#include "decls.h"

/* FUN_000b6580 @ 0xb6580 (2448 bytes) */
int FUN_000b6580(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  void *pvVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  short *psVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  
  bVar1 = param_2 == 0;
  iVar11 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (bVar1) {
    iVar6 = FUN_0004bbf0();
    if (iVar6 == 0) goto LAB_000b66b8;
    iVar6 = *(int *)(param_1 + 0x1e5c);
    if ((*(int *)(((unsigned char *)0x000036c0) + iVar6) == 0) ||
       (*(int *)(((unsigned char *)0x00001488) + param_1) != *(int *)(((unsigned char *)0x000036c0) + iVar6))) {
      if (*(char *)(param_1 + 0x1868) == '\0') {
        (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,0);
      }
      FUN_0004ac90(param_1);
      iVar6 = *(int *)(param_1 + 0x1e5c);
      if (*(int *)(((unsigned char *)0x000036c0) + iVar6) == 0) {
        *(undefined4 *)(((unsigned char *)0x00001488) + param_1) = 0;
      }
      else {
        *(int *)(((unsigned char *)0x00001488) + param_1) = *(int *)(((unsigned char *)0x000036c0) + iVar6);
      }
      ((unsigned char *)0x000010eb)[iVar6] = 0;
      *(undefined4 *)(((unsigned char *)0x00001300) + *(int *)(param_1 + 0x1e5c)) = 0;
      **(undefined4 **)(param_1 + 0x1e5c) = 0;
      iVar6 = *(int *)(param_1 + 0x1e5c);
    }
    *(undefined4 *)(((unsigned char *)0x000010e4) + iVar6) = 0xffffffff;
    if (*(int *)(param_1 + 0x23e0) == 0) {
      return;
    }
    iVar6 = *(int *)(param_1 + 0x1e5c);
    if (((unsigned char *)0x000036c4)[iVar6] != '\0') {
      ((unsigned char *)0x000010eb)[iVar6] = 0;
      *(undefined4 *)(((unsigned char *)0x0000152c) + *(int *)(param_1 + 0x1e5c)) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1c) = 0;
      return;
    }
    bVar1 = false;
  }
  else {
    iVar6 = *(int *)(param_1 + 0x1e5c);
  }
  ((unsigned char *)0x000036c4)[iVar6] = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1c) = 0;
LAB_000b66b8:
  *(undefined4 *)(((unsigned char *)0x000010e4) + *(int *)(param_1 + 0x1e5c)) = 0xffffffff;
  puVar7 = (undefined1 *)(**(code **)(param_1 + 0xc))(((unsigned char *)0x00003880));
  iVar6 = *(int *)(param_1 + 0x1e5c);
  if (*(int *)(((unsigned char *)0x000036c0) + iVar6) != 0) {
    pvVar8 = *(void **)(*(int *)(((unsigned char *)0x000036c0) + iVar6) + 0xc);
    if (pvVar8 != (void *)0x0) {
      _free(pvVar8);
      *(undefined4 *)(*(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c)) + 0xc) = 0;
      iVar6 = *(int *)(param_1 + 0x1e5c);
    }
    _free(*(void **)(((unsigned char *)0x000036c0) + iVar6));
    iVar6 = *(int *)(param_1 + 0x1e5c);
  }
  *(undefined1 **)(((unsigned char *)0x000036c0) + iVar6) = puVar7;
  puVar14 = (uint *)(puVar7 + 4);
  **(undefined4 **)(param_1 + 0x1e5c) = 0;
  *puVar7 = 0;
  uVar4 = *(uint *)(param_1 + 0x18a4);
  *(undefined4 *)(puVar7 + 4) = 0;
  *(uint *)(puVar7 + 0x1668) = uVar4 & 0x3fffc0 | *(uint *)(puVar7 + 0x1668) & 0xffc0003f;
  *(undefined4 *)(puVar7 + 0xc) = 0;
  *(undefined4 *)(puVar7 + 8) = 0;
  pvVar8 = (void *)(**(code **)(param_1 + 0xc))(0x200);
  if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
    _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*(int *)(puVar7 + 4) << 2);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
  }
  *(void **)(puVar7 + 0xc) = pvVar8;
  *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
  *(undefined4 *)(*(int *)(puVar7 + 4) * 4 + (int)pvVar8) = 1;
  iVar6 = *(int *)(puVar7 + 4);
  *(uint *)(puVar7 + 4) = iVar6 + 1U;
  if (*(uint *)(puVar7 + 8) <= iVar6 + 1U) {
    pvVar8 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
    if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*(int *)(puVar7 + 4) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
    }
    *(void **)(puVar7 + 0xc) = pvVar8;
    *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
  }
  iVar6 = 0;
  *(undefined4 *)(*puVar14 * 4 + *(int *)(puVar7 + 0xc)) = 0x10200;
  iVar16 = 0x14;
  *puVar14 = *puVar14 + 1;
  do {
    iVar5 = iVar6 + *(int *)(param_1 + 0x1e5c);
    iVar6 = iVar6 + 1;
    ((unsigned char *)0x00002ddc)[iVar5] = 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  uVar4 = (uint)*(byte *)(param_1 + 0x2b);
  if ((uint)(byte)((unsigned char *)0x000013b2)[param_1] < (uint)*(byte *)(param_1 + 0x2b)) {
    uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  }
  FUN_000d5900(param_1,puVar7);
  FUN_000d8450(param_1,puVar7,0);
  iVar6 = *(int *)(puVar7 + 4);
  if (uVar4 == 0) {
    uVar10 = 1;
    uVar12 = 0;
  }
  else {
    uVar15 = 0;
    uVar10 = 1;
    uVar12 = 0;
    psVar13 = (short *)(param_1 + 0x454);
    iVar16 = param_1;
    iVar5 = param_1;
    do {
      iVar9 = *(int *)(((unsigned char *)0x000013f8) + iVar5);
      if (iVar9 != 0) {
        if (*(short *)(iVar16 + 0x450) == -0x7a90) {
          if (*psVar13 != -0x7885) {
            FUN_000d6340(param_1,puVar7,*(undefined2 *)(iVar9 + 0x38),uVar15,iVar9,uVar10,uVar12);
            uVar10 = 0;
            uVar12 = uVar15;
          }
        }
        else {
          FUN_000d7520(param_1,puVar7,*(undefined2 *)(iVar9 + 0x38),*(short *)(iVar16 + 0x450),
                       uVar15,iVar9,uVar10,uVar12);
          uVar10 = 0;
          uVar12 = uVar15;
        }
      }
      uVar15 = uVar15 + 1;
      psVar13 = psVar13 + 0x66;
      iVar5 = iVar5 + 4;
      iVar16 = iVar16 + 0xcc;
    } while (uVar4 != uVar15);
  }
  uVar4 = *(uint *)(param_1 + 0x44);
  if ((uVar4 & 0x100000) == 0) {
    if ((((int)uVar4 < 0) &&
        (*(short *)("}J3x})+x|B;x}k" + *(int *)(*(int *)(param_1 + 4) + 0x10)) == -0x7e06)) ||
       (bVar2 = false, (uVar4 & 0x80800000) == 0x800000)) {
      bVar2 = true;
    }
  }
  else if (((uVar4 & 0x800000) == 0) ||
          (bVar2 = true, *(char *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0x6e) == '\0')) {
    bVar2 = false;
  }
  if ((bVar2) || ((uVar4 & 0x200000) != 0)) {
    FUN_000d55c0(param_1,puVar14,uVar10,uVar12);
  }
  if (iVar6 == *(int *)(puVar7 + 4)) {
    uVar4 = *puVar14;
    uVar12 = 0x170000;
    uVar15 = 0;
    do {
      if (((int)(*(uint *)(puVar7 + 0x1668) >> 6 & 0xffff) >> (uVar15 & 0x3f) & 1U) != 0) {
        uVar12 = uVar15 & 0xffff | uVar12 & 0xffff0000;
        if (*(uint *)(puVar7 + 8) <= uVar4) {
          pvVar8 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
          if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
            _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*puVar14 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
          }
          *(void **)(puVar7 + 0xc) = pvVar8;
          uVar4 = *puVar14;
          *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
        }
        *(undefined4 *)(uVar4 * 4 + *(int *)(puVar7 + 0xc)) = 0x47;
        uVar4 = *puVar14 + 1;
        *puVar14 = uVar4;
        if (*(uint *)(puVar7 + 8) <= uVar4) {
          pvVar8 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
          if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
            _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*puVar14 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
          }
          *(void **)(puVar7 + 0xc) = pvVar8;
          uVar4 = *puVar14;
          *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
        }
        *(uint *)(uVar4 * 4 + *(int *)(puVar7 + 0xc)) = uVar12;
        uVar4 = *puVar14 + 1;
        *puVar14 = uVar4;
        if (*(uint *)(puVar7 + 8) <= uVar4) {
          pvVar8 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
          if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
            _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*puVar14 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
          }
          *(void **)(puVar7 + 0xc) = pvVar8;
          uVar4 = *puVar14;
          *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
        }
        *(undefined4 *)(uVar4 * 4 + *(int *)(puVar7 + 0xc)) = 0x120000;
        uVar4 = *puVar14 + 1;
        *puVar14 = uVar4;
      }
      bVar2 = uVar15 != 3;
      uVar15 = uVar15 + 1;
    } while (bVar2);
  }
  else {
    FUN_000d5390(param_1,puVar14,0,uVar12,*(uint *)(puVar7 + 0x1668) >> 6 & 0xffff);
    uVar4 = *puVar14;
  }
  if (*(uint *)(puVar7 + 8) <= uVar4) {
    pvVar8 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
    if (*(void **)(puVar7 + 0xc) != (void *)0x0) {
      _memcpy(pvVar8,*(void **)(puVar7 + 0xc),*puVar14 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(puVar7 + 0xc));
    }
    *(void **)(puVar7 + 0xc) = pvVar8;
    uVar4 = *puVar14;
    *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
  }
  *(undefined4 *)(uVar4 * 4 + *(int *)(puVar7 + 0xc)) = 0x28;
  *puVar14 = *puVar14 + 1;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = *(undefined4 *)(puVar7 + 0xc);
  local_64 = *(undefined4 *)(puVar7 + 4);
  local_5c = 0x83;
  local_54 = 2;
  _memset((*(unsigned char *)0x00002fdc) + *(int *)(param_1 + 0x1e5c),0,0x100);
  iVar6 = 0;
  iVar16 = 0x14;
  do {
    iVar5 = iVar6 + *(int *)(param_1 + 0x1e5c);
    iVar6 = iVar6 + 1;
    ((unsigned char *)0x00002fdc)[iVar5] = 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  *(undefined4 *)(*(int *)(param_1 + 0x1e5c) + 0x1780) = 0;
  if (!bVar1) {
    *(undefined4 *)(((unsigned char *)0x0000170c) + *(int *)(param_1 + 0x1e5c)) = *(undefined4 *)(param_1 + 0x276c);
    local_5c = local_5c | 0x100;
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    sVar3 = *(short *)(((unsigned char *)0x00002e04) + iVar11);
    if (sVar3 == 0x801) {
      local_5c = local_5c | 0xc;
    }
    else if (sVar3 == 0x2601) {
      local_5c = local_5c | 4;
    }
    else if (sVar3 == 0x800) {
      local_5c = local_5c | 8;
    }
  }
  iVar11 = *(int *)(param_1 + 0x245c);
  if (iVar11 != 0) {
    local_58 = 0;
    do {
      local_58 = local_58 << 1 | 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    local_5c = local_5c | 0x400;
  }
  *(undefined4 *)(((unsigned char *)0x000010d8) + *(int *)(param_1 + 0x1e5c)) = 0xff;
  iVar11 = *(int *)(param_1 + 0x1e5c);
  FUN_000b4400(param_1,iVar11 + 0x1784,((unsigned char *)0x00001660) + iVar11,&local_68,iVar11);
  (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,0);
  if ((bVar1) && (*(int *)(param_1 + 0x23e0) != 0)) {
    *(undefined4 *)(((unsigned char *)0x0000170c) + *(int *)(param_1 + 0x1e5c)) = *(undefined4 *)(param_1 + 0x276c);
    iVar11 = *(int *)(param_1 + 0x1e5c);
    local_5c = local_5c | 0x100;
    FUN_000b4400(param_1,iVar11 + 0x1784,((unsigned char *)0x00001660) + iVar11,&local_68,iVar11);
    if (*(char *)(param_1 + 0x1868) == '\0') {
      (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,0);
    }
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    iVar11 = *(int *)(param_1 + 0x1e5c);
    *(int *)(((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + iVar11)) =
         *(int *)(((unsigned char *)0x00001744) + iVar11) - *(int *)(((unsigned char *)0x000036a0) + iVar11);
    iVar11 = *(int *)(param_1 + 0x1e5c);
    *(int *)(((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + iVar11)) =
         *(int *)(((unsigned char *)0x00001740) + iVar11) - *(int *)(((unsigned char *)0x000036a0) + iVar11);
    ((unsigned char *)0x00002ddc)[*(int *)(((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c))) +
     *(int *)(param_1 + 0x1e5c)] = 1;
    ((unsigned char *)0x00002ddc)[*(int *)(((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c))) +
     *(int *)(param_1 + 0x1e5c)] = 1;
  }
  FUN_000b5190(param_1,*(int *)(param_1 + 0x1e5c) + 0x1784,
               ((unsigned char *)0x00001660) + *(int *)(param_1 + 0x1e5c));
  *(undefined1 **)(((unsigned char *)0x00001488) + param_1) = puVar7;
  FUN_0004ac90(param_1);
  return;
}

/* FUN_000b6f20 @ 0xb6f20 (928 bytes) */
int FUN_000b6f20(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  float fVar1;
  float fVar2;
  int iVar3;
  double dVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  
  dVar12 = DOUBLE_001aa1e0;
  if (param_4 == 0) {
    return;
  }
  iVar3 = param_3 * 4;
  fVar1 = *(float *)(param_2 + 0x4c);
  iVar9 = iVar3 + param_1;
  uVar8 = *(uint *)(iVar9 + 0x1cdc);
  iVar10 = *(int *)(param_1 + 4);
  fVar2 = *(float *)(param_3 * 0xcc + param_1 + 0x470);
  dVar11 = (double)FLOAT_001aa0d4;
  *(uint *)(iVar9 + 0x1d1c) = *(uint *)(iVar9 + 0x1d1c) & 0xa0705fff | 0x20100000;
  dVar4 = DOUBLE_001aa1e8;
  uVar6 = uVar8 >> 0xd & 3;
  uVar7 = 1 << (uVar8 >> 0x15 & 7);
  dVar13 = (double)(float)((double)(fVar1 + fVar2) + dVar11);
  dVar14 = (double)((float)((double)CONCAT44(0x43300000,*(uint *)(iVar10 + 0x15c) ^ 0x80000000) -
                           dVar12) / FLOAT_001aa1b4);
  dVar12 = (double)((float)((double)CONCAT44(0x43300000,*(uint *)(iVar10 + 0x160) ^ 0x80000000) -
                           dVar12) / FLOAT_001aa1b8);
  fVar1 = (float)(dVar14 - dVar12);
  if (fVar1 < 0.0) {
    dVar12 = dVar14;
  }
  if (-fVar1 < 0.0) {
    dVar14 = dVar12;
  }
  fVar1 = (float)((double)(float)(dVar14 * dVar13) * (double)FLOAT_001aa1a8 + dVar14);
  if (uVar6 == 2) {
    dVar11 = (double)(fVar1 * FLOAT_001aa1ac);
  }
  if (param_4 != 1) {
    return;
  }
  if ((uVar8 >> 0xb & 3) == 3) {
    if (3 < uVar7) {
      uVar5 = 3;
      dVar12 = (double)(float)(dVar11 * (double)FLOAT_001aa128);
      if ((dVar12 <= (double)FLOAT_001aa158) && (uVar5 = 0, (double)FLOAT_001aa0d4 <= dVar12)) {
        if (DOUBLE_001aa1e8 <= dVar12) {
          uVar5 = (int)(dVar12 - DOUBLE_001aa1e8) + 0x80000000;
        }
        else {
          uVar5 = (uint)(dVar11 * (double)FLOAT_001aa128);
        }
      }
      if (((uVar6 == 0) && ((uVar8 >> 9 & 3) == 2)) &&
         (dVar12 = (double)FLOAT_001aa0d4, dVar13 == dVar12)) {
        uVar6 = 0;
      }
      else {
        dVar14 = (double)(fVar1 * FLOAT_001aa1bc);
        dVar12 = (double)(fVar1 * FLOAT_001aa1b0 * FLOAT_001aa0f8);
        if (DOUBLE_001aa1e8 <= dVar14) {
          uVar6 = (int)(dVar14 - DOUBLE_001aa1e8) + 0x80000000;
        }
        else {
          uVar6 = (uint)(fVar1 * FLOAT_001aa1bc);
        }
      }
      goto LAB_000b7220;
    }
    if (DOUBLE_001aa1e8 <= dVar11) {
      uVar5 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar5 = (uint)dVar11;
    }
  }
  else if (DOUBLE_001aa1e8 <= dVar11) {
    uVar5 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar5 = (uint)dVar11;
  }
  uVar6 = 0;
  dVar12 = (double)FLOAT_001aa0d4;
LAB_000b7220:
  iVar9 = iVar3 + param_1;
  *(uint *)(iVar9 + 0x1cdc) =
       (*(uint *)(&DAT_001dbf2c + uVar7 * 4) & 7) << 0x15 | *(uint *)(iVar9 + 0x1cdc) & 0xff1fffff;
  *(uint *)(iVar9 + 0x1d1c) = (uVar5 & 3) << 0xf | *(uint *)(iVar9 + 0x1d1c) & 0xfffe7fff;
  if (dVar4 <= dVar12) {
    uVar7 = (int)(dVar12 - dVar4) + 0x80000000;
  }
  else {
    uVar7 = (uint)dVar12;
  }
  *(uint *)(iVar9 + 0x1d1c) = (uVar7 & 0x3f) << 0x17 | *(uint *)(iVar9 + 0x1d1c) & 0xe07fffff;
  *(uint *)(iVar3 + param_1 + 0x1d1c) =
       (uVar6 & 7) << 0x11 | *(uint *)(iVar3 + param_1 + 0x1d1c) & 0xfff1ffff;
  return;
}

/* FUN_000b72d0 @ 0xb72d0 (11108 bytes) */
int FUN_000b72d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
  undefined1 *param_4;
  undefined1 *param_5;
  undefined1 *param_6;
  undefined1 *param_7;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  undefined1 uVar18;
  int iVar17;
  
  cVar4 = *(char *)((int)param_2 + 0xf);
  cVar5 = *(char *)((int)param_2 + 0x13);
  cVar6 = *(char *)((int)param_2 + 0x17);
  cVar7 = *(char *)((int)param_2 + 0x1b);
  switch(*param_2) {
  case 0x8782:
  case 0x8791:
  case 0x8792:
  case 0x8793:
  case 0x8794:
  case 0x8795:
switchD_000b7340_caseD_8782:
    *param_4 = 1;
    *param_5 = 1;
    *param_6 = 1;
    *param_7 = 1;
    return;
  case 0x8783:
  case 0x8789:
  case 0x878f:
  case 0x8790:
  case 0x8799:
  case 0x879c:
    iVar17 = FUN_000550e0(param_1,param_2 + 8);
    if (iVar17 != 0x87bf) goto switchD_000b7340_caseD_8782;
  case 0x879a:
  case 0x879b:
    bVar3 = cVar4 == '\0';
    if ((((bVar3) || ((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)))) &&
        (((cVar5 == '\0' || ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))) &&
         ((cVar6 == '\0' || ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))))) &&
       ((cVar7 == '\0' || ((param_2[0xd] != 0x87d5 && (param_2[0xd] != 0x87d9)))))) {
      uVar18 = 0;
    }
    else {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if (((((bVar3) || ((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)))) &&
         ((cVar5 == '\0' || ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))) &&
        ((cVar6 == '\0' || ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da)))))) &&
       ((cVar7 == '\0' || ((param_2[0xd] != 0x87d6 && (param_2[0xd] != 0x87da)))))) {
      uVar18 = 0;
    }
    else {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((((bVar3) || ((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)))) &&
        ((cVar5 == '\0' || ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))) &&
       (((cVar6 == '\0' || ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))) &&
        ((cVar7 == '\0' || ((param_2[0xd] != 0x87d7 && (param_2[0xd] != 0x87db)))))))) {
      uVar18 = 0;
    }
    else {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if ((((bVar3) || ((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)))) &&
        ((cVar5 == '\0' || ((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)))))) &&
       ((cVar6 == '\0' || ((param_2[0xc] != 0x87d8 && (param_2[0xc] != 0x87dc)))))) {
      if (cVar7 == '\0') {
LAB_000b9970:
        uVar18 = 0;
        goto LAB_000b9ef0;
      }
LAB_000b99c0:
      iVar17 = param_2[0xd];
      if (iVar17 != 0x87d8) {
LAB_000b9960:
        if (iVar17 != 0x87dc) goto LAB_000b9970;
      }
    }
    break;
  case 0x8784:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = param_2[10];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0xb] == 0x87d5)) ||
         (((param_2[0xb] == 0x87d9 || (param_2[0xc] == 0x87d5)) ||
          (bVar3 = false, param_2[0xc] == 0x87d9)))) {
        bVar3 = true;
      }
      if (((iVar17 == 0x87d6) || (iVar17 == 0x87da)) ||
         ((param_2[0xb] == 0x87d6 ||
          (((param_2[0xb] == 0x87da || (param_2[0xc] == 0x87d6)) ||
           (bVar9 = false, param_2[0xc] == 0x87da)))))) {
        bVar9 = true;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         (((param_2[0xb] == 0x87d7 || ((param_2[0xb] == 0x87db || (param_2[0xc] == 0x87d7)))) ||
          (bVar11 = false, param_2[0xc] == 0x87db)))) {
        bVar11 = true;
      }
      if (((((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) || (param_2[0xb] == 0x87d8)) ||
          ((param_2[0xb] == 0x87dc || (param_2[0xc] == 0x87d8)))) ||
         (bVar1 = false, param_2[0xc] == 0x87dc)) {
        bVar1 = true;
      }
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = param_2[0x11];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0x12] == 0x87d5)) ||
         (((param_2[0x12] == 0x87d9 || (param_2[0x13] == 0x87d5)) ||
          (bVar8 = false, param_2[0x13] == 0x87d9)))) {
        bVar8 = true;
      }
      if (((iVar17 == 0x87d6) || (iVar17 == 0x87da)) ||
         ((param_2[0x12] == 0x87d6 ||
          (((param_2[0x12] == 0x87da || (param_2[0x13] == 0x87d6)) ||
           (bVar10 = false, param_2[0x13] == 0x87da)))))) {
        bVar10 = true;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         (((param_2[0x12] == 0x87d7 || ((param_2[0x12] == 0x87db || (param_2[0x13] == 0x87d7)))) ||
          (bVar12 = false, param_2[0x13] == 0x87db)))) {
        bVar12 = true;
      }
      if (((((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) || (param_2[0x12] == 0x87d8)) ||
          ((param_2[0x12] == 0x87dc || (param_2[0x13] == 0x87d8)))) ||
         (bVar2 = false, param_2[0x13] == 0x87dc)) {
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
      bVar2 = false;
    }
    if ((bVar3) || (uVar18 = 0, bVar8)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if ((bVar9) || (uVar18 = 0, bVar10)) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((bVar11) || (uVar18 = 0, bVar12)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if (bVar1) break;
    goto LAB_000b9dfc;
  case 0x8785:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = param_2[10];
      if ((((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0xb] == 0x87d5)) ||
           ((param_2[0xb] == 0x87d9 || (param_2[0xc] == 0x87d5)))) || (param_2[0xc] == 0x87d9)) ||
         ((param_2[0xd] == 0x87d5 || (bVar3 = false, param_2[0xd] == 0x87d9)))) {
        bVar3 = true;
      }
      if ((((iVar17 == 0x87d6) || (iVar17 == 0x87da)) || (param_2[0xb] == 0x87d6)) ||
         (((param_2[0xb] == 0x87da || (param_2[0xc] == 0x87d6)) ||
          ((param_2[0xc] == 0x87da ||
           ((param_2[0xd] == 0x87d6 || (bVar9 = false, param_2[0xd] == 0x87da)))))))) {
        bVar9 = true;
      }
      if ((((iVar17 == 0x87d7) || (iVar17 == 0x87db)) || (param_2[0xb] == 0x87d7)) ||
         (((param_2[0xb] == 0x87db || (param_2[0xc] == 0x87d7)) ||
          ((param_2[0xc] == 0x87db ||
           ((param_2[0xd] == 0x87d7 || (bVar11 = false, param_2[0xd] == 0x87db)))))))) {
        bVar11 = true;
      }
      if (((((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) || (param_2[0xb] == 0x87d8)) ||
          ((param_2[0xb] == 0x87dc || (param_2[0xc] == 0x87d8)))) ||
         ((param_2[0xc] == 0x87dc ||
          ((param_2[0xd] == 0x87d8 || (bVar1 = false, param_2[0xd] == 0x87dc)))))) {
        bVar1 = true;
      }
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = param_2[0x11];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0x12] == 0x87d5)) ||
         (((param_2[0x12] == 0x87d9 || (param_2[0x13] == 0x87d5)) ||
          ((param_2[0x13] == 0x87d9 ||
           ((param_2[0x14] == 0x87d5 || (bVar8 = false, param_2[0x14] == 0x87d9)))))))) {
        bVar8 = true;
      }
      if ((((iVar17 == 0x87d6) || (iVar17 == 0x87da)) || (param_2[0x12] == 0x87d6)) ||
         (((param_2[0x12] == 0x87da || (param_2[0x13] == 0x87d6)) ||
          ((param_2[0x13] == 0x87da ||
           ((param_2[0x14] == 0x87d6 || (bVar10 = false, param_2[0x14] == 0x87da)))))))) {
        bVar10 = true;
      }
      if (((((iVar17 == 0x87d7) || (iVar17 == 0x87db)) || (param_2[0x12] == 0x87d7)) ||
          ((param_2[0x12] == 0x87db || (param_2[0x13] == 0x87d7)))) ||
         ((param_2[0x13] == 0x87db ||
          ((param_2[0x14] == 0x87d7 || (bVar12 = false, param_2[0x14] == 0x87db)))))) {
        bVar12 = true;
      }
      if ((((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) || (param_2[0x12] == 0x87d8)) ||
         (((param_2[0x12] == 0x87dc || (param_2[0x13] == 0x87d8)) ||
          ((param_2[0x13] == 0x87dc ||
           ((param_2[0x14] == 0x87d8 || (bVar2 = false, param_2[0x14] == 0x87dc)))))))) {
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
      bVar2 = false;
    }
    if ((bVar3) || (uVar18 = 0, bVar8)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if (bVar9) goto LAB_000b92a0;
LAB_000b9294:
    uVar18 = 0;
    if (bVar10) goto LAB_000b92a0;
    goto LAB_000b92a4;
  case 0x8786:
  case 0x8787:
  case 0x878a:
  case 0x878b:
  case 0x878c:
  case 0x878d:
  case 0x8796:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = FUN_000550e0(param_1,param_2 + 8);
      if (iVar17 == 0x87bf) {
        bVar3 = cVar4 == '\0';
        if (((((bVar3) || ((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)))) &&
             ((cVar5 == '\0' || ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))))) &&
            ((cVar6 == '\0' || ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))) &&
           ((cVar7 == '\0' || ((param_2[0xd] != 0x87d5 && (param_2[0xd] != 0x87d9)))))) {
          bVar9 = false;
        }
        else {
          bVar9 = true;
        }
        if ((((bVar3) || ((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)))) &&
            ((cVar5 == '\0' || ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))) &&
           (((cVar6 == '\0' || ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da)))) &&
            ((cVar7 == '\0' || ((param_2[0xd] != 0x87d6 && (param_2[0xd] != 0x87da)))))))) {
          bVar11 = false;
        }
        else {
          bVar11 = true;
        }
        if ((((bVar3) || ((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)))) &&
            ((cVar5 == '\0' || ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))) &&
           (((cVar6 == '\0' || ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))) &&
            ((cVar7 == '\0' || ((param_2[0xd] != 0x87d7 && (param_2[0xd] != 0x87db)))))))) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (((((bVar3) || ((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)))) &&
             ((cVar5 == '\0' || ((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)))))) &&
            ((cVar6 == '\0' || ((param_2[0xc] != 0x87d8 && (param_2[0xc] != 0x87dc)))))) &&
           ((cVar7 == '\0' || ((param_2[0xd] != 0x87d8 && (param_2[0xd] != 0x87dc))))))
        goto LAB_000b7dec;
        bVar3 = true;
      }
      else {
        bVar9 = true;
        bVar11 = true;
        bVar1 = true;
        bVar3 = true;
      }
    }
    else {
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
LAB_000b7dec:
      bVar3 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = FUN_000550e0(param_1,param_2 + 0xf);
      if (iVar17 == 0x87bf) {
        bVar2 = cVar4 == '\0';
        if ((((bVar2) || ((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)))) &&
            ((cVar5 == '\0' || ((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)))))) &&
           (((cVar6 == '\0' || ((param_2[0x13] != 0x87d5 && (param_2[0x13] != 0x87d9)))) &&
            ((cVar7 == '\0' || ((param_2[0x14] != 0x87d5 && (param_2[0x14] != 0x87d9)))))))) {
          bVar8 = false;
        }
        else {
          bVar8 = true;
        }
        if ((((bVar2) || ((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)))) &&
            ((cVar5 == '\0' || ((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)))))) &&
           (((cVar6 == '\0' || ((param_2[0x13] != 0x87d6 && (param_2[0x13] != 0x87da)))) &&
            ((cVar7 == '\0' || ((param_2[0x14] != 0x87d6 && (param_2[0x14] != 0x87da)))))))) {
          bVar10 = false;
        }
        else {
          bVar10 = true;
        }
        if (((((bVar2) || ((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)))) &&
             ((cVar5 == '\0' || ((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)))))) &&
            ((cVar6 == '\0' || ((param_2[0x13] != 0x87d7 && (param_2[0x13] != 0x87db)))))) &&
           ((cVar7 == '\0' || ((param_2[0x14] != 0x87d7 && (param_2[0x14] != 0x87db)))))) {
          bVar12 = false;
        }
        else {
          bVar12 = true;
        }
        if ((((bVar2) || ((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)))) &&
            ((cVar5 == '\0' || ((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)))))) &&
           (((cVar6 == '\0' || ((param_2[0x13] != 0x87d8 && (param_2[0x13] != 0x87dc)))) &&
            ((cVar7 == '\0' || ((param_2[0x14] != 0x87d8 && (param_2[0x14] != 0x87dc))))))))
        goto LAB_000b812c;
        bVar2 = true;
      }
      else {
        bVar8 = true;
        bVar10 = true;
        bVar12 = true;
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
LAB_000b812c:
      bVar2 = false;
    }
    if ((bVar9) || (uVar18 = 0, bVar8)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if ((bVar11) || (uVar18 = 0, bVar10)) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((bVar1) || (uVar18 = 0, bVar12)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    goto joined_r0x000b9df8;
  case 0x8788:
  case 0x878e:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = FUN_000550e0(param_1,param_2 + 8);
      if (iVar17 == 0x87bf) {
        bVar1 = cVar4 == '\0';
        if (((((bVar1) || ((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)))) &&
             ((cVar5 == '\0' || ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))))) &&
            ((cVar6 == '\0' || ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))) &&
           ((cVar7 == '\0' || ((param_2[0xd] != 0x87d5 && (param_2[0xd] != 0x87d9)))))) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
        if ((((bVar1) || ((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)))) &&
            ((cVar5 == '\0' || ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))) &&
           (((cVar6 == '\0' || ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da)))) &&
            ((cVar7 == '\0' || ((param_2[0xd] != 0x87d6 && (param_2[0xd] != 0x87da)))))))) {
          bVar9 = false;
        }
        else {
          bVar9 = true;
        }
        if ((((bVar1) || ((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)))) &&
            ((cVar5 == '\0' || ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))) &&
           (((cVar6 == '\0' || ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))) &&
            ((cVar7 == '\0' || ((param_2[0xd] != 0x87d7 && (param_2[0xd] != 0x87db)))))))) {
          bVar11 = false;
        }
        else {
          bVar11 = true;
        }
        if (((((bVar1) || ((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)))) &&
             ((cVar5 == '\0' || ((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)))))) &&
            ((cVar6 == '\0' || ((param_2[0xc] != 0x87d8 && (param_2[0xc] != 0x87dc)))))) &&
           ((cVar7 == '\0' || ((param_2[0xd] != 0x87d8 && (param_2[0xd] != 0x87dc))))))
        goto LAB_000b84cc;
        bVar8 = true;
      }
      else {
        bVar3 = true;
        bVar9 = true;
        bVar11 = true;
        bVar8 = true;
      }
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
LAB_000b84cc:
      bVar8 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      iVar17 = FUN_000550e0(param_1,param_2 + 0xf);
      if (iVar17 == 0x87bf) {
        bVar1 = cVar4 == '\0';
        if ((((bVar1) || ((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)))) &&
            ((cVar5 == '\0' || ((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)))))) &&
           (((cVar6 == '\0' || ((param_2[0x13] != 0x87d5 && (param_2[0x13] != 0x87d9)))) &&
            ((cVar7 == '\0' || ((param_2[0x14] != 0x87d5 && (param_2[0x14] != 0x87d9)))))))) {
          bVar10 = false;
        }
        else {
          bVar10 = true;
        }
        if (((((bVar1) || ((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)))) &&
             ((cVar5 == '\0' || ((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)))))) &&
            ((cVar6 == '\0' || ((param_2[0x13] != 0x87d6 && (param_2[0x13] != 0x87da)))))) &&
           ((cVar7 == '\0' || ((param_2[0x14] != 0x87d6 && (param_2[0x14] != 0x87da)))))) {
          bVar12 = false;
        }
        else {
          bVar12 = true;
        }
        if (((((bVar1) || ((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)))) &&
             ((cVar5 == '\0' || ((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)))))) &&
            ((cVar6 == '\0' || ((param_2[0x13] != 0x87d7 && (param_2[0x13] != 0x87db)))))) &&
           ((cVar7 == '\0' || ((param_2[0x14] != 0x87d7 && (param_2[0x14] != 0x87db)))))) {
          bVar16 = false;
        }
        else {
          bVar16 = true;
        }
        if ((((bVar1) || ((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)))) &&
            ((cVar5 == '\0' || ((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)))))) &&
           (((cVar6 == '\0' || ((param_2[0x13] != 0x87d8 && (param_2[0x13] != 0x87dc)))) &&
            ((cVar7 == '\0' || ((param_2[0x14] != 0x87d8 && (param_2[0x14] != 0x87dc))))))))
        goto LAB_000b880c;
        bVar1 = true;
      }
      else {
        bVar10 = true;
        bVar12 = true;
        bVar16 = true;
        bVar1 = true;
      }
    }
    else {
      bVar10 = false;
      bVar12 = false;
      bVar16 = false;
LAB_000b880c:
      bVar1 = false;
    }
    if ((param_2[0x16] == 2) && (param_3 == param_2[0x17])) {
      iVar17 = FUN_000550e0(param_1,param_2 + 0x16);
      if (iVar17 == 0x87bf) {
        bVar2 = cVar4 == '\0';
        if ((((bVar2) || ((param_2[0x18] != 0x87d5 && (param_2[0x18] != 0x87d9)))) &&
            ((cVar5 == '\0' || ((param_2[0x19] != 0x87d5 && (param_2[0x19] != 0x87d9)))))) &&
           (((cVar6 == '\0' || ((param_2[0x1a] != 0x87d5 && (param_2[0x1a] != 0x87d9)))) &&
            ((cVar7 == '\0' || ((param_2[0x1b] != 0x87d5 && (param_2[0x1b] != 0x87d9)))))))) {
          bVar13 = false;
        }
        else {
          bVar13 = true;
        }
        if (((((bVar2) || ((param_2[0x18] != 0x87d6 && (param_2[0x18] != 0x87da)))) &&
             ((cVar5 == '\0' || ((param_2[0x19] != 0x87d6 && (param_2[0x19] != 0x87da)))))) &&
            ((cVar6 == '\0' || ((param_2[0x1a] != 0x87d6 && (param_2[0x1a] != 0x87da)))))) &&
           ((cVar7 == '\0' || ((param_2[0x1b] != 0x87d6 && (param_2[0x1b] != 0x87da)))))) {
          bVar14 = false;
        }
        else {
          bVar14 = true;
        }
        if ((((bVar2) || ((param_2[0x18] != 0x87d7 && (param_2[0x18] != 0x87db)))) &&
            ((cVar5 == '\0' || ((param_2[0x19] != 0x87d7 && (param_2[0x19] != 0x87db)))))) &&
           (((cVar6 == '\0' || ((param_2[0x1a] != 0x87d7 && (param_2[0x1a] != 0x87db)))) &&
            ((cVar7 == '\0' || ((param_2[0x1b] != 0x87d7 && (param_2[0x1b] != 0x87db)))))))) {
          bVar15 = false;
        }
        else {
          bVar15 = true;
        }
        if ((((bVar2) || ((param_2[0x18] != 0x87d8 && (param_2[0x18] != 0x87dc)))) &&
            ((cVar5 == '\0' || ((param_2[0x19] != 0x87d8 && (param_2[0x19] != 0x87dc)))))) &&
           (((cVar6 == '\0' || ((param_2[0x1a] != 0x87d8 && (param_2[0x1a] != 0x87dc)))) &&
            ((cVar7 == '\0' || ((param_2[0x1b] != 0x87d8 && (param_2[0x1b] != 0x87dc))))))))
        goto LAB_000b8b4c;
        bVar2 = true;
      }
      else {
        bVar13 = true;
        bVar14 = true;
        bVar15 = true;
        bVar2 = true;
      }
    }
    else {
      bVar13 = false;
      bVar14 = false;
      bVar15 = false;
LAB_000b8b4c:
      bVar2 = false;
    }
    if (((bVar3) || (bVar10)) || (uVar18 = 0, bVar13)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if (((bVar9) || (bVar12)) || (uVar18 = 0, bVar14)) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if (((bVar11) || (bVar16)) || (uVar18 = 0, bVar15)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if (bVar8) break;
    goto joined_r0x000b8bc8;
  case 0x8797:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      bVar1 = cVar4 == '\0';
      if ((((bVar1) ||
           ((((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)) && (param_2[0xc] != 0x87d5)) &&
            (param_2[0xc] != 0x87d9)))) &&
          ((cVar5 == '\0' ||
           (((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)) &&
            ((param_2[0xc] != 0x87d5 && (param_2[0xc] != 0x87d9)))))))) &&
         ((cVar6 == '\0' ||
          (((param_2[10] != 0x87d5 && (param_2[10] != 0x87d9)) &&
           ((param_2[0xb] != 0x87d5 && (param_2[0xb] != 0x87d9)))))))) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (((bVar1) ||
          ((((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)) && (param_2[0xc] != 0x87d6)) &&
           (param_2[0xc] != 0x87da)))) &&
         (((cVar5 == '\0' ||
           (((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)) &&
            ((param_2[0xc] != 0x87d6 && (param_2[0xc] != 0x87da)))))) &&
          ((cVar6 == '\0' ||
           (((param_2[10] != 0x87d6 && (param_2[10] != 0x87da)) &&
            ((param_2[0xb] != 0x87d6 && (param_2[0xb] != 0x87da)))))))))) {
        bVar9 = false;
      }
      else {
        bVar9 = true;
      }
      if ((((bVar1) ||
           ((((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)) && (param_2[0xc] != 0x87d7)) &&
            (param_2[0xc] != 0x87db)))) &&
          ((cVar5 == '\0' ||
           (((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)) &&
            ((param_2[0xc] != 0x87d7 && (param_2[0xc] != 0x87db)))))))) &&
         ((cVar6 == '\0' ||
          (((param_2[10] != 0x87d7 && (param_2[10] != 0x87db)) &&
           ((param_2[0xb] != 0x87d7 && (param_2[0xb] != 0x87db)))))))) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
      }
      if (((bVar1) ||
          ((((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)) && (param_2[0xc] != 0x87d8)) &&
           (param_2[0xc] != 0x87dc)))) &&
         (((cVar5 == '\0' ||
           (((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)) &&
            ((param_2[0xc] != 0x87d8 && (param_2[0xc] != 0x87dc)))))) &&
          ((cVar6 == '\0' ||
           (((param_2[10] != 0x87d8 && (param_2[10] != 0x87dc)) &&
            ((param_2[0xb] != 0x87d8 && (param_2[0xb] != 0x87dc)))))))))) goto LAB_000b8f1c;
      bVar1 = true;
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
LAB_000b8f1c:
      bVar1 = false;
    }
    if ((param_2[0xf] == 2) && (param_3 == param_2[0x10])) {
      bVar2 = cVar4 == '\0';
      if ((((bVar2) ||
           ((((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)) && (param_2[0x13] != 0x87d5))
            && (param_2[0x13] != 0x87d9)))) &&
          ((cVar5 == '\0' ||
           (((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)) &&
            ((param_2[0x13] != 0x87d5 && (param_2[0x13] != 0x87d9)))))))) &&
         ((cVar6 == '\0' ||
          (((param_2[0x11] != 0x87d5 && (param_2[0x11] != 0x87d9)) &&
           ((param_2[0x12] != 0x87d5 && (param_2[0x12] != 0x87d9)))))))) {
        bVar8 = false;
      }
      else {
        bVar8 = true;
      }
      if ((((bVar2) ||
           ((((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)) && (param_2[0x13] != 0x87d6))
            && (param_2[0x13] != 0x87da)))) &&
          ((cVar5 == '\0' ||
           (((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)) &&
            ((param_2[0x13] != 0x87d6 && (param_2[0x13] != 0x87da)))))))) &&
         ((cVar6 == '\0' ||
          (((param_2[0x11] != 0x87d6 && (param_2[0x11] != 0x87da)) &&
           ((param_2[0x12] != 0x87d6 && (param_2[0x12] != 0x87da)))))))) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      if (((bVar2) ||
          ((((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)) && (param_2[0x13] != 0x87d7)) &&
           (param_2[0x13] != 0x87db)))) &&
         (((cVar5 == '\0' ||
           (((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)) &&
            ((param_2[0x13] != 0x87d7 && (param_2[0x13] != 0x87db)))))) &&
          ((cVar6 == '\0' ||
           (((param_2[0x11] != 0x87d7 && (param_2[0x11] != 0x87db)) &&
            ((param_2[0x12] != 0x87d7 && (param_2[0x12] != 0x87db)))))))))) {
        bVar12 = false;
      }
      else {
        bVar12 = true;
      }
      if ((((bVar2) ||
           ((((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)) && (param_2[0x13] != 0x87d8))
            && (param_2[0x13] != 0x87dc)))) &&
          ((cVar5 == '\0' ||
           (((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)) &&
            ((param_2[0x13] != 0x87d8 && (param_2[0x13] != 0x87dc)))))))) &&
         ((cVar6 == '\0' ||
          (((param_2[0x11] != 0x87d8 && (param_2[0x11] != 0x87dc)) &&
           ((param_2[0x12] != 0x87d8 && (param_2[0x12] != 0x87dc)))))))) goto LAB_000b926c;
      bVar2 = true;
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
LAB_000b926c:
      bVar2 = false;
    }
    if ((bVar3) || (uVar18 = 0, bVar8)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if (!bVar9) goto LAB_000b9294;
LAB_000b92a0:
    uVar18 = 1;
LAB_000b92a4:
    *param_5 = uVar18;
    if ((bVar11) || (uVar18 = 0, bVar12)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
joined_r0x000b8bc8:
    if (!bVar1) {
LAB_000b9dfc:
      uVar18 = 0;
      if (!bVar2) goto LAB_000b9ef0;
    }
    break;
  case 0x8798:
    if ((((((param_2[0x11] == 0x87d5) || (param_2[0x11] == 0x87d9)) || (param_2[0x12] == 0x87d5)) ||
         ((param_2[0x12] == 0x87d9 || (param_2[0x13] == 0x87d5)))) || (param_2[0x13] == 0x87d9)) ||
       ((param_2[0x14] == 0x87d5 || (uVar18 = 0, param_2[0x14] == 0x87d9)))) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if ((((param_2[0x11] == 0x87d6) || (param_2[0x11] == 0x87da)) || (param_2[0x12] == 0x87d6)) ||
       (((param_2[0x12] == 0x87da || (param_2[0x13] == 0x87d6)) ||
        ((param_2[0x13] == 0x87da ||
         ((param_2[0x14] == 0x87d6 || (uVar18 = 0, param_2[0x14] == 0x87da)))))))) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((((param_2[0x11] == 0x87d7) || (param_2[0x11] == 0x87db)) || (param_2[0x12] == 0x87d7)) ||
       (((param_2[0x12] == 0x87db || (param_2[0x13] == 0x87d7)) ||
        ((param_2[0x13] == 0x87db ||
         ((param_2[0x14] == 0x87d7 || (uVar18 = 0, param_2[0x14] == 0x87db)))))))) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if (((((param_2[0x11] != 0x87d8) && (param_2[0x11] != 0x87dc)) && (param_2[0x12] != 0x87d8)) &&
        ((param_2[0x12] != 0x87dc && (param_2[0x13] != 0x87d8)))) && (param_2[0x13] != 0x87dc)) {
      iVar17 = param_2[0x14];
joined_r0x000b9b40:
      if ((iVar17 != 0x87d8) && (uVar18 = 0, iVar17 != 0x87dc)) goto LAB_000b9ef0;
    }
    break;
  case 0x879d:
    iVar17 = FUN_000550e0(param_1,param_2 + 8);
    if (iVar17 != 0x87bf) goto switchD_000b7340_caseD_8782;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) {
      iVar17 = param_2[10];
joined_r0x000b97e0:
      if ((iVar17 != 0x87d5) && (iVar17 != 0x87d9)) goto LAB_000b9790;
      uVar18 = 1;
    }
    else {
      if (iVar17 == 1) {
        iVar17 = param_2[0xb];
        goto joined_r0x000b97e0;
      }
      if (iVar17 == 2) {
        iVar17 = param_2[0xc];
        goto joined_r0x000b97e0;
      }
      if (iVar17 == 3) {
        iVar17 = param_2[0xd];
        goto joined_r0x000b97e0;
      }
LAB_000b9790:
      uVar18 = 0;
    }
    *param_4 = uVar18;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) {
      iVar17 = param_2[10];
joined_r0x000b9880:
      if ((iVar17 != 0x87d6) && (iVar17 != 0x87da)) goto LAB_000b9830;
      uVar18 = 1;
    }
    else {
      if (iVar17 == 1) {
        iVar17 = param_2[0xb];
        goto joined_r0x000b9880;
      }
      if (iVar17 == 2) {
        iVar17 = param_2[0xc];
        goto joined_r0x000b9880;
      }
      if (iVar17 == 3) {
        iVar17 = param_2[0xd];
        goto joined_r0x000b9880;
      }
LAB_000b9830:
      uVar18 = 0;
    }
    *param_5 = uVar18;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) {
      iVar17 = param_2[10];
joined_r0x000b9920:
      if ((iVar17 != 0x87d7) && (iVar17 != 0x87db)) goto LAB_000b98d0;
      uVar18 = 1;
    }
    else {
      if (iVar17 == 1) {
        iVar17 = param_2[0xb];
        goto joined_r0x000b9920;
      }
      if (iVar17 == 2) {
        iVar17 = param_2[0xc];
        goto joined_r0x000b9920;
      }
      if (iVar17 == 3) {
        iVar17 = param_2[0xd];
        goto joined_r0x000b9920;
      }
LAB_000b98d0:
      uVar18 = 0;
    }
    *param_6 = uVar18;
    iVar17 = param_2[0x10];
    if (iVar17 == 0) {
      iVar17 = param_2[10];
joined_r0x000b9990:
      if (iVar17 == 0x87d8) break;
      goto LAB_000b9960;
    }
    if (iVar17 == 1) {
      iVar17 = param_2[0xb];
      goto joined_r0x000b9990;
    }
    if (iVar17 == 2) {
      iVar17 = param_2[0xc];
      goto joined_r0x000b9990;
    }
    if (iVar17 == 3) goto LAB_000b99c0;
    goto LAB_000b9970;
  case 0x879e:
    if (((((param_2[10] == 0x87d5) || (param_2[10] == 0x87d9)) || (param_2[0xb] == 0x87d5)) ||
        ((param_2[0xb] == 0x87d9 || (param_2[0xd] == 0x87d5)))) ||
       (uVar18 = 0, param_2[0xd] == 0x87d9)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if (((param_2[10] == 0x87d6) || (param_2[10] == 0x87da)) ||
       ((param_2[0xb] == 0x87d6 ||
        (((param_2[0xb] == 0x87da || (param_2[0xd] == 0x87d6)) ||
         (uVar18 = 0, param_2[0xd] == 0x87da)))))) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if (((param_2[10] == 0x87d7) || (param_2[10] == 0x87db)) ||
       (((param_2[0xb] == 0x87d7 || ((param_2[0xb] == 0x87db || (param_2[0xd] == 0x87d7)))) ||
        (uVar18 = 0, param_2[0xd] == 0x87db)))) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if ((((param_2[10] != 0x87d8) && (param_2[10] != 0x87dc)) && (param_2[0xb] != 0x87d8)) &&
       (param_2[0xb] != 0x87dc)) {
      iVar17 = param_2[0xd];
      goto joined_r0x000b9b40;
    }
    break;
  case 0x879f:
    if ((param_2[8] == 2) && (param_3 == param_2[9])) {
      iVar17 = param_2[0xb];
      if ((((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) || (param_2[0xc] == 0x87d5)) ||
         (bVar9 = false, param_2[0xc] == 0x87d9)) {
        bVar9 = true;
      }
      if (((iVar17 == 0x87d6) || (iVar17 == 0x87da)) ||
         ((param_2[0xc] == 0x87d6 || (bVar11 = false, param_2[0xc] == 0x87da)))) {
        bVar11 = true;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         ((param_2[0xc] == 0x87d7 || (bVar1 = false, param_2[0xc] == 0x87db)))) {
        bVar1 = true;
      }
      if ((((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) || (param_2[0xc] == 0x87d8)) ||
         (bVar3 = false, param_2[0xc] == 0x87dc)) {
        bVar3 = true;
      }
    }
    else {
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
      bVar3 = false;
    }
    if ((param_2[0xf] == 2) && (param_2[0x10] == param_3)) {
      iVar17 = param_2[0x12];
      if (((iVar17 == 0x87d5) || (iVar17 == 0x87d9)) ||
         ((param_2[0x14] == 0x87d5 || (bVar8 = false, param_2[0x14] == 0x87d9)))) {
        bVar8 = true;
      }
      if ((((iVar17 == 0x87d6) || (iVar17 == 0x87da)) || (param_2[0x14] == 0x87d6)) ||
         (bVar10 = false, param_2[0x14] == 0x87da)) {
        bVar10 = true;
      }
      if (((iVar17 == 0x87d7) || (iVar17 == 0x87db)) ||
         ((param_2[0x14] == 0x87d7 || (bVar12 = false, param_2[0x14] == 0x87db)))) {
        bVar12 = true;
      }
      if (((iVar17 == 0x87d8) || (iVar17 == 0x87dc)) ||
         ((param_2[0x14] == 0x87d8 || (bVar2 = false, param_2[0x14] == 0x87dc)))) {
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
      bVar2 = false;
    }
    if ((bVar9) || (uVar18 = 0, bVar8)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if ((bVar11) || (uVar18 = 0, bVar10)) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((bVar1) || (uVar18 = 0, bVar12)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
joined_r0x000b9df8:
    if (bVar3) break;
    goto LAB_000b9dfc;
  case 0x87a0:
  case 0x87a1:
  case 0x87a2:
    if ((param_2[10] == 0x87d5) || (uVar18 = 0, param_2[10] == 0x87d9)) {
      uVar18 = 1;
    }
    *param_4 = uVar18;
    if ((param_2[10] == 0x87d6) || (uVar18 = 0, param_2[10] == 0x87da)) {
      uVar18 = 1;
    }
    *param_5 = uVar18;
    if ((param_2[10] == 0x87d7) || (uVar18 = 0, param_2[10] == 0x87db)) {
      uVar18 = 1;
    }
    *param_6 = uVar18;
    if ((param_2[10] == 0x87d8) || (uVar18 = 0, param_2[10] == 0x87dc)) {
      uVar18 = 1;
    }
    *param_7 = uVar18;
    return;
  default:
    uVar18 = 0;
    *param_4 = 0;
    *param_5 = 0;
    *param_6 = 0;
    goto LAB_000b9ef0;
  }
  uVar18 = 1;
LAB_000b9ef0:
  *param_7 = uVar18;
  return;
}

/* FUN_000b9f10 @ 0xb9f10 (11376 bytes) */
int FUN_000b9f10(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  void *pvVar9;
  int iVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  int iVar14;
  byte bVar16;
  undefined4 *puVar15;
  uint uVar17;
  undefined4 *puVar18;
  int iVar19;
  undefined4 uVar20;
  int *piVar21;
  undefined4 uVar22;
  int iVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  int iVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  int iVar32;
  uint uVar33;
  uint uVar34;
  int iVar35;
  int iVar36;
  uint uVar37;
  undefined4 *puVar38;
  undefined4 *puVar39;
  int iStack00000018;
  char local_68;
  char local_67;
  char local_66;
  char local_65 [25];
  
  iVar32 = param_2 + 0x1c;
  uVar17 = *(uint *)(param_2 + 0x14);
  uVar8 = uVar17;
  iStack00000018 = param_1;
  if (uVar17 != 0) {
    iVar36 = uVar17 * 0x74;
    uVar33 = 0;
    do {
      iVar10 = *(int *)(param_2 + 0x18);
      uVar37 = uVar17 - uVar33;
      iVar14 = iVar36 + iVar10;
      cVar2 = *(char *)(iVar14 + -0x61);
      cVar3 = *(char *)(iVar14 + -0x5d);
      cVar4 = *(char *)(iVar14 + -0x59);
      bVar1 = *(char *)(iVar14 + -0x65) == '\0';
      if ((((bVar1) && (cVar2 == '\0')) && (cVar3 == '\0')) && (cVar4 == '\0')) {
LAB_000ba610:
        iVar10 = iVar36;
        if (uVar37 < uVar8) {
          do {
            uVar37 = uVar37 + 1;
            pvVar9 = (void *)(iVar10 + *(int *)(param_2 + 0x18));
            _memcpy((void *)((int)pvVar9 + -0x74),pvVar9,0x74);
            uVar8 = *(uint *)(param_2 + 0x14);
            iVar10 = iVar10 + 0x74;
          } while (uVar37 < uVar8);
        }
        uVar8 = uVar8 - 1;
        *(uint *)(param_2 + 0x14) = uVar8;
      }
      else {
        iVar19 = *(int *)(iVar14 + -0x70);
        if (iVar19 == 1) {
          if (uVar37 < uVar8) {
            iVar10 = uVar8 - uVar37;
            piVar21 = (int *)(iVar14 + 4);
            bVar13 = 0;
            bVar16 = 0;
            bVar12 = 0;
            bVar11 = 0;
            do {
              if ((*piVar21 == 1) && (piVar21[1] == *(int *)(iVar14 + -0x6c))) {
                bVar16 = bVar16 | *(byte *)((int)piVar21 + 0xb);
                bVar13 = bVar13 | *(byte *)((int)piVar21 + 0xf);
                bVar12 = bVar12 | *(byte *)((int)piVar21 + 0x13);
                bVar11 = bVar11 | *(byte *)((int)piVar21 + 0x17);
              }
              piVar21 = piVar21 + 0x1d;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          }
          else {
            bVar16 = 0;
            bVar13 = 0;
            bVar12 = 0;
            bVar11 = 0;
          }
          if ((((bVar1) || (bVar16 != 0)) && ((cVar2 == '\0' || (bVar13 != 0)))) &&
             (((cVar3 == '\0' || (bVar12 != 0)) && ((cVar4 == '\0' || (bVar11 != 0))))))
          goto LAB_000ba610;
        }
        else {
          if (*(int *)(iVar14 + -0x74) == 0x87a2) {
            if (uVar37 < uVar8) {
              iVar10 = uVar8 - uVar37;
              pcVar7 = (char *)(iVar14 + 0x38);
              bVar5 = true;
              bVar13 = 0;
              bVar12 = 0;
              bVar11 = 0;
              bVar16 = 0;
              do {
                if (((*pcVar7 != '\0') || (pcVar7[0x1c] != '\0')) || (pcVar7[0x38] != '\0')) {
                  bVar5 = false;
                }
                if ((*(int *)(pcVar7 + -0x34) == 2) &&
                   (*(int *)(pcVar7 + -0x30) == *(int *)(iVar14 + -0x6c))) {
                  bVar13 = bVar13 | pcVar7[-0x29];
                  bVar12 = bVar12 | pcVar7[-0x25];
                  bVar11 = bVar11 | pcVar7[-0x21];
                  bVar16 = bVar16 | pcVar7[-0x1d];
                }
                pcVar7 = pcVar7 + 0x74;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
            }
            else {
              bVar5 = true;
              bVar13 = 0;
              bVar12 = 0;
              bVar11 = 0;
              bVar16 = 0;
            }
            if (((((((bVar1) || (bVar13 != 0)) && ((cVar2 == '\0' || (bVar12 != 0)))) &&
                  ((cVar3 == '\0' || (bVar11 != 0)))) && ((cVar4 == '\0' || (bVar16 != 0)))) &&
                (bVar5)) || (uVar8 <= uVar37)) goto LAB_000ba610;
            iVar10 = uVar8 - uVar37;
            pcVar7 = (char *)(iVar14 + 0x38);
            bVar5 = true;
            do {
              if (((*pcVar7 != '\0') || (pcVar7[0x1c] != '\0')) || (pcVar7[0x38] != '\0')) {
                bVar5 = false;
              }
              pcVar7 = pcVar7 + 0x74;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          }
          else {
            if (*(char *)(param_2 + 0x7b) == '\0') {
              if (iVar19 == 2) {
                iVar19 = *(int *)(iVar14 + -0x6c);
                iVar23 = *(int *)(param_2 + 0x20);
                goto LAB_000ba1a0;
              }
            }
            else if (iVar19 == 2) {
              iVar19 = *(int *)(iVar14 + -0x6c);
              iVar23 = *(int *)(param_2 + 0x20);
              if (*(int *)(iVar19 * 0x54 + iVar23 + 0x28) == 0x87c4) goto LAB_000ba664;
LAB_000ba1a0:
              if (*(int *)(iVar19 * 0x54 + iVar23 + 0x24) == 0x87c0) goto LAB_000ba664;
            }
            if (uVar37 < uVar8) {
              bVar11 = 0;
              bVar12 = 0;
              bVar13 = 0;
              bVar16 = 0;
              bVar5 = true;
              iVar19 = iVar36;
              uVar34 = uVar37;
              while( true ) {
                iVar10 = iVar19 + iVar10;
                if ((((*(int *)(iVar10 + 0x20) == 2) &&
                     (iVar23 = *(int *)(iVar14 + -0x6c), *(int *)(iVar10 + 0x24) == iVar23)) ||
                    ((*(int *)(iVar10 + 0x3c) == 2 &&
                     (iVar23 = *(int *)(iVar14 + -0x6c), *(int *)(iVar10 + 0x40) == iVar23)))) ||
                   ((*(int *)(iVar10 + 0x58) == 2 &&
                    (iVar23 = *(int *)(iVar14 + -0x6c), *(int *)(iVar10 + 0x5c) == iVar23)))) {
                  ((int (*)())FUN_000b72d0)(iVar32,iVar10,iVar23,&local_68,&local_67,&local_66,local_65);
                  if (((((bVar1) || ((local_68 == '\0' || (bVar16 != 0)))) &&
                       ((cVar2 == '\0' || ((local_67 == '\0' || (bVar13 != 0)))))) &&
                      ((cVar3 == '\0' || ((local_66 == '\0' || (bVar12 != 0)))))) &&
                     ((cVar4 == '\0' || ((local_65[0] == '\0' || (bVar11 != 0)))))) {
                    uVar8 = *(uint *)(param_2 + 0x14);
                  }
                  else {
                    uVar8 = *(uint *)(param_2 + 0x14);
                    bVar5 = false;
                  }
                }
                if ((*(int *)(iVar10 + 4) == 2) &&
                   (*(int *)(iVar10 + 8) == *(int *)(iVar14 + -0x6c))) {
                  bVar11 = bVar11 | *(byte *)(iVar10 + 0x1b);
                  bVar16 = bVar16 | *(byte *)(iVar10 + 0xf);
                  bVar13 = bVar13 | *(byte *)(iVar10 + 0x13);
                  bVar12 = bVar12 | *(byte *)(iVar10 + 0x17);
                }
                uVar34 = uVar34 + 1;
                iVar19 = iVar19 + 0x74;
                if (uVar8 <= uVar34) break;
                iVar10 = *(int *)(param_2 + 0x18);
              }
            }
            else {
              bVar5 = true;
              bVar16 = 0;
              bVar13 = 0;
              bVar12 = 0;
              bVar11 = 0;
            }
            if (((((bVar1) || (bVar16 != 0)) && ((cVar2 == '\0' || (bVar13 != 0)))) &&
                ((((cVar3 == '\0' || (bVar12 != 0)) && ((cVar4 == '\0' || (bVar11 != 0)))) &&
                 (bVar5)))) || (uVar8 <= uVar37)) goto LAB_000ba610;
            bVar5 = true;
            bVar12 = 0;
            bVar13 = 0;
            bVar16 = 0;
            bVar11 = 0;
            iVar10 = iVar36;
            uVar34 = uVar37;
            do {
              iVar19 = iVar10 + *(int *)(param_2 + 0x18);
              if ((((*(int *)(iVar19 + 0x20) == 2) &&
                   (iVar23 = *(int *)(iVar14 + -0x6c), *(int *)(iVar19 + 0x24) == iVar23)) ||
                  ((*(int *)(iVar19 + 0x3c) == 2 &&
                   (iVar23 = *(int *)(iVar14 + -0x6c), *(int *)(iVar19 + 0x40) == iVar23)))) ||
                 ((*(int *)(iVar19 + 0x58) == 2 &&
                  (iVar23 = *(int *)(iVar14 + -0x6c), *(int *)(iVar19 + 0x5c) == iVar23)))) {
                ((int (*)())FUN_000b72d0)(iVar32,iVar19,iVar23,&local_68,&local_67,&local_66,local_65);
                if ((((bVar1) || ((local_68 == '\0' || (bVar12 != 0)))) &&
                    (((cVar2 == '\0' || ((local_67 == '\0' || (bVar13 != 0)))) &&
                     ((cVar3 == '\0' || ((local_66 == '\0' || (bVar16 != 0)))))))) &&
                   ((cVar4 == '\0' || ((local_65[0] == '\0' || (bVar11 != 0)))))) {
                  uVar8 = *(uint *)(param_2 + 0x14);
                }
                else {
                  uVar8 = *(uint *)(param_2 + 0x14);
                  bVar5 = false;
                }
              }
              if ((*(int *)(iVar19 + 4) == 2) && (*(int *)(iVar19 + 8) == *(int *)(iVar14 + -0x6c)))
              {
                bVar11 = bVar11 | *(byte *)(iVar19 + 0x1b);
                bVar12 = bVar12 | *(byte *)(iVar19 + 0xf);
                bVar13 = bVar13 | *(byte *)(iVar19 + 0x13);
                bVar16 = bVar16 | *(byte *)(iVar19 + 0x17);
              }
              uVar34 = uVar34 + 1;
              iVar10 = iVar10 + 0x74;
            } while (uVar34 < uVar8);
          }
          if (bVar5) goto LAB_000ba610;
        }
      }
LAB_000ba664:
      uVar33 = uVar33 + 1;
      iVar36 = iVar36 + -0x74;
    } while (uVar17 != uVar33);
  }
  if (uVar8 != 0) {
    uVar17 = 0;
    do {
      iVar10 = uVar17 * 0x74;
      iVar36 = *(int *)(param_2 + 0x18);
      puVar39 = (undefined4 *)(iVar10 + iVar36);
      if ((((*(int *)(iVar10 + iVar36) == 0x8786) && (puVar39[1] == 2)) &&
          ((puVar39[3] != 0 && ((puVar39[4] != 0 && (puVar39[5] != 0)))))) &&
         ((puVar39[6] != 0 && (uVar37 = uVar17 + 1, uVar33 = uVar37, uVar37 < uVar8)))) {
        do {
          iVar14 = uVar33 * 0x74;
          puVar38 = (undefined4 *)(iVar36 + iVar14);
          if (*(int *)(iVar36 + iVar14) == 0x8787) {
            iVar19 = puVar38[8];
            if ((iVar19 != 2) || (iVar23 = puVar39[2], puVar38[9] != iVar23)) {
              if ((puVar38[0xf] != 2) || (iVar23 = puVar39[2], puVar38[0x10] != iVar23))
              goto LAB_000ba7ec;
              iVar35 = 2;
              if (iVar19 == 2) goto LAB_000ba7dc;
            }
            else {
              iVar35 = puVar38[0xf];
              if (iVar35 == 2) {
LAB_000ba7dc:
                if (puVar38[9] == puVar38[0x10]) goto LAB_000ba7ec;
              }
            }
            bVar1 = true;
            if (uVar37 < uVar33) {
              iVar6 = uVar33 - uVar37;
              piVar21 = (int *)(iVar36 + uVar37 * 0x74 + 0x20);
              do {
                if ((((*piVar21 == 2) && (piVar21[1] == iVar23)) ||
                    ((piVar21[7] == 2 && (piVar21[8] == iVar23)))) ||
                   ((((piVar21[0xe] == 2 && (piVar21[0xf] == iVar23)) ||
                     ((iVar27 = piVar21[-7], iVar27 == 2 && (piVar21[-6] == iVar23)))) ||
                    (((iVar27 == puVar39[8] && (piVar21[-6] == puVar39[9])) ||
                     ((iVar27 == puVar39[0xf] && (piVar21[-6] == puVar39[0x10])))))))) {
                  bVar1 = false;
                }
                piVar21 = piVar21 + 0x1d;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
              if (bVar1) goto LAB_000ba8a8;
LAB_000ba754:
              bVar1 = true;
              iVar6 = uVar33 - uVar37;
              piVar21 = (int *)(uVar37 * 0x74 + iVar36 + 0x20);
              if ((uVar33 < uVar17 + 2) || (uVar33 == 0)) {
                iVar6 = 1;
              }
              do {
                if ((((((*piVar21 == 2) && (piVar21[1] == iVar23)) ||
                      ((piVar21[7] == 2 && (piVar21[8] == iVar23)))) ||
                     ((piVar21[0xe] == 2 && (piVar21[0xf] == iVar23)))) ||
                    (((*piVar21 == 2 && (piVar21[1] == puVar38[2])) ||
                     ((((piVar21[7] == 2 && (piVar21[8] == puVar38[2])) ||
                       ((piVar21[0xe] == 2 && (piVar21[0xf] == puVar38[2])))) ||
                      ((iVar27 = piVar21[-7], iVar19 == iVar27 && (piVar21[-6] == puVar38[9]))))))))
                   || (((iVar27 == iVar35 && (piVar21[-6] == puVar38[0x10])) ||
                       ((iVar27 == puVar38[1] && (piVar21[-6] == puVar38[2])))))) {
                  bVar1 = false;
                }
                piVar21 = piVar21 + 0x1d;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
              if (bVar1) {
LAB_000bc018:
                bVar1 = true;
                uVar34 = uVar33 + 1;
                if (uVar34 < uVar8) {
                  iVar6 = uVar8 - uVar34;
                  piVar21 = (int *)(iVar36 + uVar34 * 0x74 + 0x20);
                  do {
                    if ((((*piVar21 == 2) && (piVar21[1] == iVar23)) ||
                        ((piVar21[7] == 2 && (piVar21[8] == iVar23)))) ||
                       ((piVar21[0xe] == 2 && (piVar21[0xf] == iVar23)))) {
                      bVar1 = false;
                    }
                    piVar21 = piVar21 + 0x1d;
                    iVar6 = iVar6 + -1;
                  } while (iVar6 != 0);
                  if (!bVar1) goto LAB_000bd6dc;
                }
                iVar36 = puVar38[9];
                *puVar39 = 0x8788;
                if (iVar36 == iVar23) {
                  uVar22 = puVar38[0x10];
                  uVar26 = puVar38[0x11];
                  uVar20 = puVar38[0x12];
                  uVar28 = puVar38[0x13];
                  uVar24 = puVar38[0x14];
                  uVar31 = puVar38[0x15];
                  puVar39[0x16] = iVar35;
                  puVar39[0x17] = uVar22;
                  puVar39[0x18] = uVar26;
                  puVar39[0x19] = uVar20;
                  puVar39[0x1a] = uVar28;
                  puVar39[0x1b] = uVar24;
                  puVar39[0x1c] = uVar31;
                }
                else {
                  uVar22 = puVar38[10];
                  uVar26 = puVar38[0xb];
                  uVar30 = puVar38[0xc];
                  uVar29 = puVar38[0xd];
                  uVar25 = puVar38[0xe];
                  uVar28 = puVar38[0x11];
                  uVar24 = puVar38[0x12];
                  uVar20 = puVar38[0x13];
                  uVar31 = puVar38[0x14];
                  puVar39[0x16] = iVar19;
                  puVar39[0x17] = iVar36;
                  puVar39[0x18] = uVar22;
                  puVar39[0x19] = uVar26;
                  puVar39[0x1a] = uVar30;
                  puVar39[0x1b] = uVar29;
                  puVar39[0x1c] = uVar25;
                  puVar38[10] = uVar28;
                  puVar38[0xb] = uVar24;
                  puVar38[0xc] = uVar20;
                  puVar38[0xd] = uVar31;
                }
                uVar22 = puVar38[2];
                puVar15 = puVar38 + 0x11;
                uVar26 = puVar38[3];
                uVar31 = puVar38[4];
                puVar39[1] = puVar38[1];
                puVar39[2] = uVar22;
                puVar39[3] = uVar26;
                puVar39[4] = uVar31;
                uVar26 = puVar38[7];
                uVar22 = puVar38[5];
                puVar39[6] = puVar38[6];
                puVar39[7] = uVar26;
                puVar39[5] = uVar22;
                uVar22 = puVar38[10];
                switch(uVar22) {
                case 0x87d9:
                  uVar22 = 0x87d5;
                  break;
                case 0x87da:
                  uVar22 = 0x87d6;
                  break;
                case 0x87db:
                  uVar22 = 0x87d7;
                  break;
                case 0x87dc:
                  uVar22 = 0x87d8;
                  break;
                case 0x87df:
                  uVar22 = 0x87de;
                }
                uVar26 = puVar38[0xb];
                *puVar15 = uVar22;
                switch(uVar26) {
                case 0x87d9:
                  uVar26 = 0x87d5;
                  break;
                case 0x87da:
                  uVar26 = 0x87d6;
                  break;
                case 0x87db:
                  uVar26 = 0x87d7;
                  break;
                case 0x87dc:
                  uVar26 = 0x87d8;
                  break;
                case 0x87df:
                  uVar26 = 0x87de;
                }
                uVar22 = puVar38[0xc];
                puVar38[0x12] = uVar26;
                switch(uVar22) {
                case 0x87d9:
                  uVar22 = 0x87d5;
                  break;
                case 0x87da:
                  uVar22 = 0x87d6;
                  break;
                case 0x87db:
                  uVar22 = 0x87d7;
                  break;
                case 0x87dc:
                  uVar22 = 0x87d8;
                  break;
                case 0x87df:
                  uVar22 = 0x87de;
                }
                uVar26 = puVar38[0xd];
                puVar38[0x13] = uVar22;
                switch(uVar26) {
                case 0x87d9:
                  uVar26 = 0x87d5;
                  break;
                case 0x87da:
                  uVar26 = 0x87d6;
                  break;
                case 0x87db:
                  uVar26 = 0x87d7;
                  break;
                case 0x87dc:
                  uVar26 = 0x87d8;
                  break;
                case 0x87df:
                  uVar26 = 0x87de;
                }
                uVar22 = puVar38[10];
                puVar38[0x14] = uVar26;
                puVar18 = puVar39 + 10;
                switch(uVar22) {
                case 0x87d5:
                  uVar22 = *puVar18;
                  break;
                case 0x87d6:
                  uVar22 = puVar39[0xb];
                  break;
                case 0x87d7:
                  uVar22 = puVar39[0xc];
                  break;
                case 0x87d8:
                  uVar22 = puVar39[0xd];
                  break;
                case 0x87d9:
                  uVar22 = *puVar18;
                  switch(uVar22) {
                  case 0x87d5:
switchD_000bc544_caseD_87d5:
                    uVar22 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bc544_caseD_87d6:
                    uVar22 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bc544_caseD_87d7:
                    uVar22 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bc544_caseD_87d8:
                    uVar22 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bc544_caseD_87d9:
                    uVar22 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bc544_caseD_87da:
                    uVar22 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bc544_caseD_87db:
                    uVar22 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bc544_caseD_87dc:
                    uVar22 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bc544_caseD_87de:
                    uVar22 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bc544_caseD_87df:
                    uVar22 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar22 = puVar39[0xb];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bc544_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc544_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc544_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc544_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc544_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc544_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc544_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc544_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc544_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc544_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar22 = puVar39[0xc];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bc544_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc544_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc544_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc544_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc544_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc544_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc544_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc544_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc544_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc544_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar22 = puVar39[0xd];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bc544_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc544_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc544_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc544_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc544_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc544_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc544_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc544_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc544_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc544_caseD_87df;
                  }
                }
                uVar26 = puVar38[0xb];
                puVar38[10] = uVar22;
                switch(uVar26) {
                case 0x87d5:
                  uVar26 = *puVar18;
                  break;
                case 0x87d6:
                  uVar26 = puVar39[0xb];
                  break;
                case 0x87d7:
                  uVar26 = puVar39[0xc];
                  break;
                case 0x87d8:
                  uVar26 = puVar39[0xd];
                  break;
                case 0x87d9:
                  uVar26 = *puVar18;
                  switch(uVar26) {
                  case 0x87d5:
switchD_000bc79c_caseD_87d5:
                    uVar26 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bc79c_caseD_87d6:
                    uVar26 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bc79c_caseD_87d7:
                    uVar26 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bc79c_caseD_87d8:
                    uVar26 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bc79c_caseD_87d9:
                    uVar26 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bc79c_caseD_87da:
                    uVar26 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bc79c_caseD_87db:
                    uVar26 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bc79c_caseD_87dc:
                    uVar26 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bc79c_caseD_87de:
                    uVar26 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bc79c_caseD_87df:
                    uVar26 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar26 = puVar39[0xb];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bc79c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc79c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc79c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc79c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc79c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc79c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc79c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc79c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc79c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc79c_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar26 = puVar39[0xc];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bc79c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc79c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc79c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc79c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc79c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc79c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc79c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc79c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc79c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc79c_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar26 = puVar39[0xd];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bc79c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc79c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc79c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc79c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc79c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc79c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc79c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc79c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc79c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc79c_caseD_87df;
                  }
                }
                uVar22 = puVar38[0xc];
                puVar38[0xb] = uVar26;
                switch(uVar22) {
                case 0x87d5:
                  uVar22 = *puVar18;
                  break;
                case 0x87d6:
                  uVar22 = puVar39[0xb];
                  break;
                case 0x87d7:
                  uVar22 = puVar39[0xc];
                  break;
                case 0x87d8:
                  uVar22 = puVar39[0xd];
                  break;
                case 0x87d9:
                  uVar22 = *puVar18;
                  switch(uVar22) {
                  case 0x87d5:
switchD_000bc9f4_caseD_87d5:
                    uVar22 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bc9f4_caseD_87d6:
                    uVar22 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bc9f4_caseD_87d7:
                    uVar22 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bc9f4_caseD_87d8:
                    uVar22 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bc9f4_caseD_87d9:
                    uVar22 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bc9f4_caseD_87da:
                    uVar22 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bc9f4_caseD_87db:
                    uVar22 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bc9f4_caseD_87dc:
                    uVar22 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bc9f4_caseD_87de:
                    uVar22 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bc9f4_caseD_87df:
                    uVar22 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar22 = puVar39[0xb];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bc9f4_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc9f4_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc9f4_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc9f4_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc9f4_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc9f4_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc9f4_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc9f4_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc9f4_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc9f4_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar22 = puVar39[0xc];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bc9f4_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc9f4_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc9f4_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc9f4_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc9f4_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc9f4_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc9f4_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc9f4_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc9f4_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc9f4_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar22 = puVar39[0xd];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bc9f4_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc9f4_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc9f4_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc9f4_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc9f4_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc9f4_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc9f4_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc9f4_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc9f4_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc9f4_caseD_87df;
                  }
                }
                uVar26 = puVar38[0xd];
                puVar38[0xc] = uVar22;
                switch(uVar26) {
                case 0x87d5:
                  uVar26 = *puVar18;
                  break;
                case 0x87d6:
                  uVar26 = puVar39[0xb];
                  break;
                case 0x87d7:
                  uVar26 = puVar39[0xc];
                  break;
                case 0x87d8:
                  uVar26 = puVar39[0xd];
                  break;
                case 0x87d9:
                  uVar26 = *puVar18;
                  switch(uVar26) {
                  case 0x87d5:
switchD_000bcc4c_caseD_87d5:
                    uVar26 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bcc4c_caseD_87d6:
                    uVar26 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bcc4c_caseD_87d7:
                    uVar26 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bcc4c_caseD_87d8:
                    uVar26 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bcc4c_caseD_87d9:
                    uVar26 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bcc4c_caseD_87da:
                    uVar26 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bcc4c_caseD_87db:
                    uVar26 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bcc4c_caseD_87dc:
                    uVar26 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bcc4c_caseD_87de:
                    uVar26 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bcc4c_caseD_87df:
                    uVar26 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar26 = puVar39[0xb];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bcc4c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcc4c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcc4c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcc4c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcc4c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcc4c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcc4c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcc4c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcc4c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcc4c_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar26 = puVar39[0xc];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bcc4c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcc4c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcc4c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcc4c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcc4c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcc4c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcc4c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcc4c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcc4c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcc4c_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar26 = puVar39[0xd];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bcc4c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcc4c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcc4c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcc4c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcc4c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcc4c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcc4c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcc4c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcc4c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcc4c_caseD_87df;
                  }
                }
                uVar22 = *puVar15;
                puVar38[0xd] = uVar26;
                puVar18 = puVar39 + 0x11;
                switch(uVar22) {
                case 0x87d5:
                  uVar22 = *puVar18;
                  break;
                case 0x87d6:
                  uVar22 = puVar39[0x12];
                  break;
                case 0x87d7:
                  uVar22 = puVar39[0x13];
                  break;
                case 0x87d8:
                  uVar22 = puVar39[0x14];
                  break;
                case 0x87d9:
                  uVar22 = *puVar18;
                  switch(uVar22) {
                  case 0x87d5:
switchD_000bcea8_caseD_87d5:
                    uVar22 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bcea8_caseD_87d6:
                    uVar22 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bcea8_caseD_87d7:
                    uVar22 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bcea8_caseD_87d8:
                    uVar22 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bcea8_caseD_87d9:
                    uVar22 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bcea8_caseD_87da:
                    uVar22 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bcea8_caseD_87db:
                    uVar22 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bcea8_caseD_87dc:
                    uVar22 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bcea8_caseD_87de:
                    uVar22 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bcea8_caseD_87df:
                    uVar22 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar22 = puVar39[0x12];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bcea8_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcea8_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcea8_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcea8_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcea8_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcea8_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcea8_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcea8_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcea8_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcea8_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar22 = puVar39[0x13];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bcea8_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcea8_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcea8_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcea8_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcea8_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcea8_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcea8_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcea8_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcea8_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcea8_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar22 = puVar39[0x14];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bcea8_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcea8_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcea8_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcea8_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcea8_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcea8_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcea8_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcea8_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcea8_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcea8_caseD_87df;
                  }
                }
                uVar26 = puVar38[0x12];
                *puVar15 = uVar22;
                switch(uVar26) {
                case 0x87d5:
                  uVar26 = *puVar18;
                  break;
                case 0x87d6:
                  uVar26 = puVar39[0x12];
                  break;
                case 0x87d7:
                  uVar26 = puVar39[0x13];
                  break;
                case 0x87d8:
                  uVar26 = puVar39[0x14];
                  break;
                case 0x87d9:
                  uVar26 = *puVar18;
                  switch(uVar26) {
                  case 0x87d5:
switchD_000bd100_caseD_87d5:
                    uVar26 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bd100_caseD_87d6:
                    uVar26 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bd100_caseD_87d7:
                    uVar26 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bd100_caseD_87d8:
                    uVar26 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bd100_caseD_87d9:
                    uVar26 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bd100_caseD_87da:
                    uVar26 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bd100_caseD_87db:
                    uVar26 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bd100_caseD_87dc:
                    uVar26 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bd100_caseD_87de:
                    uVar26 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bd100_caseD_87df:
                    uVar26 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar26 = puVar39[0x12];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bd100_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd100_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd100_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd100_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd100_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd100_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd100_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd100_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd100_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd100_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar26 = puVar39[0x13];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bd100_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd100_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd100_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd100_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd100_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd100_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd100_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd100_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd100_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd100_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar26 = puVar39[0x14];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bd100_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd100_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd100_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd100_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd100_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd100_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd100_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd100_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd100_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd100_caseD_87df;
                  }
                }
                uVar22 = puVar38[0x13];
                puVar38[0x12] = uVar26;
                switch(uVar22) {
                case 0x87d5:
                  uVar22 = *puVar18;
                  break;
                case 0x87d6:
                  uVar22 = puVar39[0x12];
                  break;
                case 0x87d7:
                  uVar22 = puVar39[0x13];
                  break;
                case 0x87d8:
                  uVar22 = puVar39[0x14];
                  break;
                case 0x87d9:
                  uVar22 = *puVar18;
                  switch(uVar22) {
                  case 0x87d5:
switchD_000bd358_caseD_87d5:
                    uVar22 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bd358_caseD_87d6:
                    uVar22 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bd358_caseD_87d7:
                    uVar22 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bd358_caseD_87d8:
                    uVar22 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bd358_caseD_87d9:
                    uVar22 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bd358_caseD_87da:
                    uVar22 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bd358_caseD_87db:
                    uVar22 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bd358_caseD_87dc:
                    uVar22 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bd358_caseD_87de:
                    uVar22 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bd358_caseD_87df:
                    uVar22 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar22 = puVar39[0x12];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bd358_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd358_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd358_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd358_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd358_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd358_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd358_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd358_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd358_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd358_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar22 = puVar39[0x13];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bd358_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd358_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd358_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd358_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd358_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd358_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd358_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd358_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd358_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd358_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar22 = puVar39[0x14];
                  switch(uVar22) {
                  case 0x87d5:
                    goto switchD_000bd358_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd358_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd358_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd358_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd358_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd358_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd358_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd358_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd358_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd358_caseD_87df;
                  }
                }
                uVar26 = puVar38[0x14];
                puVar38[0x13] = uVar22;
                switch(uVar26) {
                case 0x87d5:
                  uVar26 = *puVar18;
                  break;
                case 0x87d6:
                  uVar26 = puVar39[0x12];
                  break;
                case 0x87d7:
                  uVar26 = puVar39[0x13];
                  break;
                case 0x87d8:
                  uVar26 = puVar39[0x14];
                  break;
                case 0x87d9:
                  uVar26 = *puVar18;
                  switch(uVar26) {
                  case 0x87d5:
switchD_000bd5b0_caseD_87d5:
                    uVar26 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bd5b0_caseD_87d6:
                    uVar26 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bd5b0_caseD_87d7:
                    uVar26 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bd5b0_caseD_87d8:
                    uVar26 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bd5b0_caseD_87d9:
                    uVar26 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bd5b0_caseD_87da:
                    uVar26 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bd5b0_caseD_87db:
                    uVar26 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bd5b0_caseD_87dc:
                    uVar26 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bd5b0_caseD_87de:
                    uVar26 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bd5b0_caseD_87df:
                    uVar26 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar26 = puVar39[0x12];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bd5b0_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd5b0_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd5b0_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd5b0_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd5b0_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd5b0_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd5b0_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd5b0_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd5b0_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd5b0_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar26 = puVar39[0x13];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bd5b0_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd5b0_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd5b0_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd5b0_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd5b0_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd5b0_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd5b0_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd5b0_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd5b0_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd5b0_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar26 = puVar39[0x14];
                  switch(uVar26) {
                  case 0x87d5:
                    goto switchD_000bd5b0_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd5b0_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd5b0_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd5b0_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd5b0_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd5b0_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd5b0_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd5b0_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd5b0_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd5b0_caseD_87df;
                  }
                }
                puVar38[0x14] = uVar26;
                uVar31 = puVar38[0x14];
                uVar22 = puVar38[10];
                uVar26 = puVar38[0xb];
                uVar24 = puVar38[0xc];
                uVar30 = puVar38[0xd];
                uVar28 = puVar38[0x11];
                uVar20 = puVar38[0x13];
                puVar39[0x12] = puVar38[0x12];
                puVar39[0x14] = uVar31;
                puVar39[10] = uVar22;
                puVar39[0xb] = uVar26;
                puVar39[0xc] = uVar24;
                puVar39[0xd] = uVar30;
                puVar39[0x11] = uVar28;
                puVar39[0x13] = uVar20;
                uVar8 = *(int *)(param_2 + 0x14) - 1;
                *(uint *)(param_2 + 0x14) = uVar8;
                uVar34 = uVar33;
                if (uVar33 < uVar8) {
                  do {
                    uVar34 = uVar34 + 1;
                    pvVar9 = (void *)(iVar14 + *(int *)(param_2 + 0x18));
                    iVar14 = iVar14 + 0x74;
                    _memcpy(pvVar9,(void *)((int)pvVar9 + 0x74),0x74);
                    uVar8 = *(uint *)(param_2 + 0x14);
                  } while (uVar34 < uVar8);
                }
              }
LAB_000bd6dc:
              uVar33 = uVar33 + 1;
              bVar1 = true;
            }
            else {
LAB_000ba8a8:
              bVar1 = true;
              uVar34 = uVar33 + 1;
              if (uVar34 < uVar8) {
                iVar6 = uVar8 - uVar34;
                piVar21 = (int *)(iVar36 + uVar34 * 0x74 + 0x20);
                do {
                  if (((*piVar21 == 2) && (piVar21[1] == iVar23)) ||
                     (((piVar21[7] == 2 && (piVar21[8] == iVar23)) ||
                      ((piVar21[0xe] == 2 && (piVar21[0xf] == iVar23)))))) {
                    bVar1 = false;
                  }
                  piVar21 = piVar21 + 0x1d;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
                if (!bVar1) {
                  if (uVar37 < uVar33) goto LAB_000ba754;
                  goto LAB_000bc018;
                }
              }
              *puVar38 = 0x8788;
              if (puVar38[9] == iVar23) {
                uVar22 = puVar38[10];
                puVar38[0x16] = iVar35;
                puVar38[0x17] = puVar38[0x10];
                puVar38[0x18] = puVar38[0x11];
                puVar38[0x19] = puVar38[0x12];
                puVar38[0x1a] = puVar38[0x13];
                puVar38[0x1b] = puVar38[0x14];
                puVar38[0x1c] = puVar38[0x15];
              }
              else {
                puVar38[0x18] = puVar38[10];
                uVar22 = puVar38[0x11];
                puVar38[0x16] = iVar19;
                puVar38[0x17] = puVar38[9];
                puVar38[0x19] = puVar38[0xb];
                puVar38[0x1a] = puVar38[0xc];
                puVar38[0x1b] = puVar38[0xd];
                puVar38[0x1c] = puVar38[0xe];
                puVar38[0xb] = puVar38[0x12];
                puVar38[0xc] = puVar38[0x13];
                puVar38[0xd] = puVar38[0x14];
                puVar38[10] = uVar22;
              }
              puVar15 = puVar38 + 0x11;
              switch(uVar22) {
              case 0x87d9:
                uVar22 = 0x87d5;
                break;
              case 0x87da:
                uVar22 = 0x87d6;
                break;
              case 0x87db:
                uVar22 = 0x87d7;
                break;
              case 0x87dc:
                uVar22 = 0x87d8;
                break;
              case 0x87df:
                uVar22 = 0x87de;
              }
              uVar26 = puVar38[0xb];
              *puVar15 = uVar22;
              switch(uVar26) {
              case 0x87d9:
                uVar26 = 0x87d5;
                break;
              case 0x87da:
                uVar26 = 0x87d6;
                break;
              case 0x87db:
                uVar26 = 0x87d7;
                break;
              case 0x87dc:
                uVar26 = 0x87d8;
                break;
              case 0x87df:
                uVar26 = 0x87de;
              }
              uVar22 = puVar38[0xc];
              puVar38[0x12] = uVar26;
              switch(uVar22) {
              case 0x87d9:
                uVar22 = 0x87d5;
                break;
              case 0x87da:
                uVar22 = 0x87d6;
                break;
              case 0x87db:
                uVar22 = 0x87d7;
                break;
              case 0x87dc:
                uVar22 = 0x87d8;
                break;
              case 0x87df:
                uVar22 = 0x87de;
              }
              uVar26 = puVar38[0xd];
              puVar38[0x13] = uVar22;
              switch(uVar26) {
              case 0x87d9:
                uVar26 = 0x87d5;
                break;
              case 0x87da:
                uVar26 = 0x87d6;
                break;
              case 0x87db:
                uVar26 = 0x87d7;
                break;
              case 0x87dc:
                uVar26 = 0x87d8;
                break;
              case 0x87df:
                uVar26 = 0x87de;
              }
              puVar38[0x14] = uVar26;
              puVar18 = puVar39 + 10;
              puVar38[9] = puVar39[9];
              uVar22 = puVar38[10];
              switch(uVar22) {
              case 0x87d5:
                uVar22 = *puVar18;
                break;
              case 0x87d6:
                uVar22 = puVar39[0xb];
                break;
              case 0x87d7:
                uVar22 = puVar39[0xc];
                break;
              case 0x87d8:
                uVar22 = puVar39[0xd];
                break;
              case 0x87d9:
                uVar22 = *puVar18;
                switch(uVar22) {
                case 0x87d5:
switchD_000badac_caseD_87d5:
                  uVar22 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000badac_caseD_87d6:
                  uVar22 = 0x87da;
                  break;
                case 0x87d7:
switchD_000badac_caseD_87d7:
                  uVar22 = 0x87db;
                  break;
                case 0x87d8:
switchD_000badac_caseD_87d8:
                  uVar22 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000badac_caseD_87d9:
                  uVar22 = 0x87d5;
                  break;
                case 0x87da:
switchD_000badac_caseD_87da:
                  uVar22 = 0x87d6;
                  break;
                case 0x87db:
switchD_000badac_caseD_87db:
                  uVar22 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000badac_caseD_87dc:
                  uVar22 = 0x87d8;
                  break;
                case 0x87de:
switchD_000badac_caseD_87de:
                  uVar22 = 0x87df;
                  break;
                case 0x87df:
switchD_000badac_caseD_87df:
                  uVar22 = 0x87de;
                }
                break;
              case 0x87da:
                uVar22 = puVar39[0xb];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000badac_caseD_87d5;
                case 0x87d6:
                  goto switchD_000badac_caseD_87d6;
                case 0x87d7:
                  goto switchD_000badac_caseD_87d7;
                case 0x87d8:
                  goto switchD_000badac_caseD_87d8;
                case 0x87d9:
                  goto switchD_000badac_caseD_87d9;
                case 0x87da:
                  goto switchD_000badac_caseD_87da;
                case 0x87db:
                  goto switchD_000badac_caseD_87db;
                case 0x87dc:
                  goto switchD_000badac_caseD_87dc;
                case 0x87de:
                  goto switchD_000badac_caseD_87de;
                case 0x87df:
                  goto switchD_000badac_caseD_87df;
                }
                break;
              case 0x87db:
                uVar22 = puVar39[0xc];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000badac_caseD_87d5;
                case 0x87d6:
                  goto switchD_000badac_caseD_87d6;
                case 0x87d7:
                  goto switchD_000badac_caseD_87d7;
                case 0x87d8:
                  goto switchD_000badac_caseD_87d8;
                case 0x87d9:
                  goto switchD_000badac_caseD_87d9;
                case 0x87da:
                  goto switchD_000badac_caseD_87da;
                case 0x87db:
                  goto switchD_000badac_caseD_87db;
                case 0x87dc:
                  goto switchD_000badac_caseD_87dc;
                case 0x87de:
                  goto switchD_000badac_caseD_87de;
                case 0x87df:
                  goto switchD_000badac_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar22 = puVar39[0xd];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000badac_caseD_87d5;
                case 0x87d6:
                  goto switchD_000badac_caseD_87d6;
                case 0x87d7:
                  goto switchD_000badac_caseD_87d7;
                case 0x87d8:
                  goto switchD_000badac_caseD_87d8;
                case 0x87d9:
                  goto switchD_000badac_caseD_87d9;
                case 0x87da:
                  goto switchD_000badac_caseD_87da;
                case 0x87db:
                  goto switchD_000badac_caseD_87db;
                case 0x87dc:
                  goto switchD_000badac_caseD_87dc;
                case 0x87de:
                  goto switchD_000badac_caseD_87de;
                case 0x87df:
                  goto switchD_000badac_caseD_87df;
                }
              }
              uVar26 = puVar38[0xb];
              puVar38[10] = uVar22;
              switch(uVar26) {
              case 0x87d5:
                uVar26 = *puVar18;
                break;
              case 0x87d6:
                uVar26 = puVar39[0xb];
                break;
              case 0x87d7:
                uVar26 = puVar39[0xc];
                break;
              case 0x87d8:
                uVar26 = puVar39[0xd];
                break;
              case 0x87d9:
                uVar26 = *puVar18;
                switch(uVar26) {
                case 0x87d5:
switchD_000bb004_caseD_87d5:
                  uVar26 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb004_caseD_87d6:
                  uVar26 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb004_caseD_87d7:
                  uVar26 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb004_caseD_87d8:
                  uVar26 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb004_caseD_87d9:
                  uVar26 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb004_caseD_87da:
                  uVar26 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb004_caseD_87db:
                  uVar26 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb004_caseD_87dc:
                  uVar26 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb004_caseD_87de:
                  uVar26 = 0x87df;
                  break;
                case 0x87df:
switchD_000bb004_caseD_87df:
                  uVar26 = 0x87de;
                }
                break;
              case 0x87da:
                uVar26 = puVar39[0xb];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bb004_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb004_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb004_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb004_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb004_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb004_caseD_87da;
                case 0x87db:
                  goto switchD_000bb004_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb004_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb004_caseD_87de;
                case 0x87df:
                  goto switchD_000bb004_caseD_87df;
                }
                break;
              case 0x87db:
                uVar26 = puVar39[0xc];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bb004_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb004_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb004_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb004_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb004_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb004_caseD_87da;
                case 0x87db:
                  goto switchD_000bb004_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb004_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb004_caseD_87de;
                case 0x87df:
                  goto switchD_000bb004_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar26 = puVar39[0xd];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bb004_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb004_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb004_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb004_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb004_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb004_caseD_87da;
                case 0x87db:
                  goto switchD_000bb004_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb004_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb004_caseD_87de;
                case 0x87df:
                  goto switchD_000bb004_caseD_87df;
                }
              }
              uVar22 = puVar38[0xc];
              puVar38[0xb] = uVar26;
              switch(uVar22) {
              case 0x87d5:
                uVar22 = *puVar18;
                break;
              case 0x87d6:
                uVar22 = puVar39[0xb];
                break;
              case 0x87d7:
                uVar22 = puVar39[0xc];
                break;
              case 0x87d8:
                uVar22 = puVar39[0xd];
                break;
              case 0x87d9:
                uVar22 = *puVar18;
                switch(uVar22) {
                case 0x87d5:
switchD_000bb25c_caseD_87d5:
                  uVar22 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb25c_caseD_87d6:
                  uVar22 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb25c_caseD_87d7:
                  uVar22 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb25c_caseD_87d8:
                  uVar22 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb25c_caseD_87d9:
                  uVar22 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb25c_caseD_87da:
                  uVar22 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb25c_caseD_87db:
                  uVar22 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb25c_caseD_87dc:
                  uVar22 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb25c_caseD_87de:
                  uVar22 = 0x87df;
                  break;
                case 0x87df:
switchD_000bb25c_caseD_87df:
                  uVar22 = 0x87de;
                }
                break;
              case 0x87da:
                uVar22 = puVar39[0xb];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000bb25c_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb25c_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb25c_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb25c_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb25c_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb25c_caseD_87da;
                case 0x87db:
                  goto switchD_000bb25c_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb25c_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb25c_caseD_87de;
                case 0x87df:
                  goto switchD_000bb25c_caseD_87df;
                }
                break;
              case 0x87db:
                uVar22 = puVar39[0xc];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000bb25c_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb25c_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb25c_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb25c_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb25c_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb25c_caseD_87da;
                case 0x87db:
                  goto switchD_000bb25c_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb25c_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb25c_caseD_87de;
                case 0x87df:
                  goto switchD_000bb25c_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar22 = puVar39[0xd];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000bb25c_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb25c_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb25c_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb25c_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb25c_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb25c_caseD_87da;
                case 0x87db:
                  goto switchD_000bb25c_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb25c_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb25c_caseD_87de;
                case 0x87df:
                  goto switchD_000bb25c_caseD_87df;
                }
              }
              uVar26 = puVar38[0xd];
              puVar38[0xc] = uVar22;
              switch(uVar26) {
              case 0x87d5:
                uVar26 = *puVar18;
                break;
              case 0x87d6:
                uVar26 = puVar39[0xb];
                break;
              case 0x87d7:
                uVar26 = puVar39[0xc];
                break;
              case 0x87d8:
                uVar26 = puVar39[0xd];
                break;
              case 0x87d9:
                uVar26 = *puVar18;
                switch(uVar26) {
                case 0x87d5:
switchD_000bb4b4_caseD_87d5:
                  uVar26 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb4b4_caseD_87d6:
                  uVar26 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb4b4_caseD_87d7:
                  uVar26 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb4b4_caseD_87d8:
                  uVar26 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb4b4_caseD_87d9:
                  uVar26 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb4b4_caseD_87da:
                  uVar26 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb4b4_caseD_87db:
                  uVar26 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb4b4_caseD_87dc:
                  uVar26 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb4b4_caseD_87de:
                  uVar26 = 0x87df;
                  break;
                case 0x87df:
switchD_000bb4b4_caseD_87df:
                  uVar26 = 0x87de;
                }
                break;
              case 0x87da:
                uVar26 = puVar39[0xb];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bb4b4_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb4b4_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb4b4_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb4b4_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb4b4_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb4b4_caseD_87da;
                case 0x87db:
                  goto switchD_000bb4b4_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb4b4_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb4b4_caseD_87de;
                case 0x87df:
                  goto switchD_000bb4b4_caseD_87df;
                }
                break;
              case 0x87db:
                uVar26 = puVar39[0xc];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bb4b4_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb4b4_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb4b4_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb4b4_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb4b4_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb4b4_caseD_87da;
                case 0x87db:
                  goto switchD_000bb4b4_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb4b4_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb4b4_caseD_87de;
                case 0x87df:
                  goto switchD_000bb4b4_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar26 = puVar39[0xd];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bb4b4_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb4b4_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb4b4_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb4b4_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb4b4_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb4b4_caseD_87da;
                case 0x87db:
                  goto switchD_000bb4b4_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb4b4_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb4b4_caseD_87de;
                case 0x87df:
                  goto switchD_000bb4b4_caseD_87df;
                }
              }
              puVar38[0xd] = uVar26;
              puVar18 = puVar39 + 0x11;
              puVar38[0x10] = puVar39[0x10];
              uVar22 = *puVar15;
              switch(uVar22) {
              case 0x87d5:
                uVar22 = *puVar18;
                break;
              case 0x87d6:
                uVar22 = puVar39[0x12];
                break;
              case 0x87d7:
                uVar22 = puVar39[0x13];
                break;
              case 0x87d8:
                uVar22 = puVar39[0x14];
                break;
              case 0x87d9:
                uVar22 = *puVar18;
                switch(uVar22) {
                case 0x87d5:
switchD_000bb718_caseD_87d5:
                  uVar22 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb718_caseD_87d6:
                  uVar22 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb718_caseD_87d7:
                  uVar22 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb718_caseD_87d8:
                  uVar22 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb718_caseD_87d9:
                  uVar22 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb718_caseD_87da:
                  uVar22 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb718_caseD_87db:
                  uVar22 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb718_caseD_87dc:
                  uVar22 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb718_caseD_87de:
                  uVar22 = 0x87df;
                  break;
                case 0x87df:
switchD_000bb718_caseD_87df:
                  uVar22 = 0x87de;
                }
                break;
              case 0x87da:
                uVar22 = puVar39[0x12];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000bb718_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb718_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb718_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb718_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb718_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb718_caseD_87da;
                case 0x87db:
                  goto switchD_000bb718_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb718_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb718_caseD_87de;
                case 0x87df:
                  goto switchD_000bb718_caseD_87df;
                }
                break;
              case 0x87db:
                uVar22 = puVar39[0x13];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000bb718_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb718_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb718_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb718_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb718_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb718_caseD_87da;
                case 0x87db:
                  goto switchD_000bb718_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb718_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb718_caseD_87de;
                case 0x87df:
                  goto switchD_000bb718_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar22 = puVar39[0x14];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000bb718_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb718_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb718_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb718_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb718_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb718_caseD_87da;
                case 0x87db:
                  goto switchD_000bb718_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb718_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb718_caseD_87de;
                case 0x87df:
                  goto switchD_000bb718_caseD_87df;
                }
              }
              uVar26 = puVar38[0x12];
              *puVar15 = uVar22;
              switch(uVar26) {
              case 0x87d5:
                uVar26 = *puVar18;
                break;
              case 0x87d6:
                uVar26 = puVar39[0x12];
                break;
              case 0x87d7:
                uVar26 = puVar39[0x13];
                break;
              case 0x87d8:
                uVar26 = puVar39[0x14];
                break;
              case 0x87d9:
                uVar26 = *puVar18;
                switch(uVar26) {
                case 0x87d5:
switchD_000bb970_caseD_87d5:
                  uVar26 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb970_caseD_87d6:
                  uVar26 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb970_caseD_87d7:
                  uVar26 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb970_caseD_87d8:
                  uVar26 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb970_caseD_87d9:
                  uVar26 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb970_caseD_87da:
                  uVar26 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb970_caseD_87db:
                  uVar26 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb970_caseD_87dc:
                  uVar26 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb970_caseD_87de:
                  uVar26 = 0x87df;
                  break;
                case 0x87df:
switchD_000bb970_caseD_87df:
                  uVar26 = 0x87de;
                }
                break;
              case 0x87da:
                uVar26 = puVar39[0x12];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bb970_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb970_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb970_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb970_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb970_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb970_caseD_87da;
                case 0x87db:
                  goto switchD_000bb970_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb970_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb970_caseD_87de;
                case 0x87df:
                  goto switchD_000bb970_caseD_87df;
                }
                break;
              case 0x87db:
                uVar26 = puVar39[0x13];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bb970_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb970_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb970_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb970_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb970_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb970_caseD_87da;
                case 0x87db:
                  goto switchD_000bb970_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb970_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb970_caseD_87de;
                case 0x87df:
                  goto switchD_000bb970_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar26 = puVar39[0x14];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bb970_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb970_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb970_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb970_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb970_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb970_caseD_87da;
                case 0x87db:
                  goto switchD_000bb970_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb970_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb970_caseD_87de;
                case 0x87df:
                  goto switchD_000bb970_caseD_87df;
                }
              }
              uVar22 = puVar38[0x13];
              puVar38[0x12] = uVar26;
              switch(uVar22) {
              case 0x87d5:
                uVar22 = *puVar18;
                break;
              case 0x87d6:
                uVar22 = puVar39[0x12];
                break;
              case 0x87d7:
                uVar22 = puVar39[0x13];
                break;
              case 0x87d8:
                uVar22 = puVar39[0x14];
                break;
              case 0x87d9:
                uVar22 = *puVar18;
                switch(uVar22) {
                case 0x87d5:
switchD_000bbbc8_caseD_87d5:
                  uVar22 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bbbc8_caseD_87d6:
                  uVar22 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bbbc8_caseD_87d7:
                  uVar22 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bbbc8_caseD_87d8:
                  uVar22 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bbbc8_caseD_87d9:
                  uVar22 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bbbc8_caseD_87da:
                  uVar22 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bbbc8_caseD_87db:
                  uVar22 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bbbc8_caseD_87dc:
                  uVar22 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bbbc8_caseD_87de:
                  uVar22 = 0x87df;
                  break;
                case 0x87df:
switchD_000bbbc8_caseD_87df:
                  uVar22 = 0x87de;
                }
                break;
              case 0x87da:
                uVar22 = puVar39[0x12];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000bbbc8_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbbc8_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbbc8_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbbc8_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbbc8_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbbc8_caseD_87da;
                case 0x87db:
                  goto switchD_000bbbc8_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbbc8_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbbc8_caseD_87de;
                case 0x87df:
                  goto switchD_000bbbc8_caseD_87df;
                }
                break;
              case 0x87db:
                uVar22 = puVar39[0x13];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000bbbc8_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbbc8_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbbc8_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbbc8_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbbc8_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbbc8_caseD_87da;
                case 0x87db:
                  goto switchD_000bbbc8_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbbc8_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbbc8_caseD_87de;
                case 0x87df:
                  goto switchD_000bbbc8_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar22 = puVar39[0x14];
                switch(uVar22) {
                case 0x87d5:
                  goto switchD_000bbbc8_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbbc8_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbbc8_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbbc8_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbbc8_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbbc8_caseD_87da;
                case 0x87db:
                  goto switchD_000bbbc8_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbbc8_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbbc8_caseD_87de;
                case 0x87df:
                  goto switchD_000bbbc8_caseD_87df;
                }
              }
              uVar26 = puVar38[0x14];
              puVar38[0x13] = uVar22;
              switch(uVar26) {
              case 0x87d5:
                uVar26 = *puVar18;
                break;
              case 0x87d6:
                uVar26 = puVar39[0x12];
                break;
              case 0x87d7:
                uVar26 = puVar39[0x13];
                break;
              case 0x87d8:
                uVar26 = puVar39[0x14];
                break;
              case 0x87d9:
                uVar26 = *puVar18;
                switch(uVar26) {
                case 0x87d5:
switchD_000bbe20_caseD_87d5:
                  uVar26 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bbe20_caseD_87d6:
                  uVar26 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bbe20_caseD_87d7:
                  uVar26 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bbe20_caseD_87d8:
                  uVar26 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bbe20_caseD_87d9:
                  uVar26 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bbe20_caseD_87da:
                  uVar26 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bbe20_caseD_87db:
                  uVar26 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bbe20_caseD_87dc:
                  uVar26 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bbe20_caseD_87de:
                  uVar26 = 0x87df;
                  break;
                case 0x87df:
switchD_000bbe20_caseD_87df:
                  uVar26 = 0x87de;
                }
                break;
              case 0x87da:
                uVar26 = puVar39[0x12];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bbe20_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbe20_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbe20_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbe20_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbe20_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbe20_caseD_87da;
                case 0x87db:
                  goto switchD_000bbe20_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbe20_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbe20_caseD_87de;
                case 0x87df:
                  goto switchD_000bbe20_caseD_87df;
                }
                break;
              case 0x87db:
                uVar26 = puVar39[0x13];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bbe20_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbe20_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbe20_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbe20_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbe20_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbe20_caseD_87da;
                case 0x87db:
                  goto switchD_000bbe20_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbe20_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbe20_caseD_87de;
                case 0x87df:
                  goto switchD_000bbe20_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar26 = puVar39[0x14];
                switch(uVar26) {
                case 0x87d5:
                  goto switchD_000bbe20_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbe20_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbe20_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbe20_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbe20_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbe20_caseD_87da;
                case 0x87db:
                  goto switchD_000bbe20_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbe20_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbe20_caseD_87de;
                case 0x87df:
                  goto switchD_000bbe20_caseD_87df;
                }
              }
              puVar38[0x14] = uVar26;
              uVar8 = *(int *)(param_2 + 0x14) - 1;
              *(uint *)(param_2 + 0x14) = uVar8;
              iVar36 = iVar10;
              uVar34 = uVar17;
              if (uVar17 < uVar8) {
                do {
                  uVar33 = uVar34;
                  uVar34 = uVar33 + 1;
                  pvVar9 = (void *)(iVar36 + *(int *)(param_2 + 0x18));
                  _memcpy(pvVar9,(void *)((int)pvVar9 + 0x74),0x74);
                  uVar8 = *(uint *)(param_2 + 0x14);
                  iVar36 = iVar36 + 0x74;
                } while (uVar34 < uVar8);
                uVar33 = uVar33 + 2;
                bVar1 = true;
              }
              else {
                bVar1 = true;
                uVar33 = uVar37;
              }
            }
          }
          else {
LAB_000ba7ec:
            bVar1 = false;
            uVar33 = uVar33 + 1;
          }
          if ((uVar8 <= uVar33) || (bVar1)) break;
          iVar36 = *(int *)(param_2 + 0x18);
        } while( true );
      }
      uVar17 = uVar17 + 1;
    } while (uVar17 < uVar8);
    if (uVar8 != 0) {
      uVar17 = 0;
      do {
        iVar36 = *(int *)(param_2 + 0x18);
        iVar10 = iVar36 + uVar17 * 0x74;
        if (((*(int *)(iVar36 + uVar17 * 0x74) == 0x8798) && (*(int *)(iVar10 + 4) == 2)) &&
           (*(int *)(iVar10 + 0x20) == 2)) {
          iVar14 = *(int *)(param_2 + 0x20) + *(int *)(iVar10 + 0x24) * 0x54;
          if ((*(char *)(iVar14 + 0x44) != '\0') && (*(int *)(iVar14 + 0x48) == 0xba6)) {
            uVar33 = uVar17 + 1;
            if (uVar33 < uVar8) {
              iVar14 = uVar8 - uVar33;
              bVar1 = true;
              uVar37 = 0;
              piVar21 = (int *)(uVar33 * 0x74 + iVar36 + 0x3c);
              do {
                if ((*piVar21 == 2) && (piVar21[1] == *(int *)(iVar10 + 8))) {
                  if ((((piVar21[-0xf] == 0x8798) && (piVar21[-7] == 2)) &&
                      (iVar19 = *(int *)(param_2 + 0x20) + piVar21[-6] * 0x54,
                      *(char *)(iVar19 + 0x44) != '\0')) &&
                     ((*(int *)(iVar19 + 0x48) == 0xba7 && (uVar37 == 0)))) {
                    bVar5 = false;
                    uVar37 = uVar33;
                  }
                  else {
LAB_000bd88c:
                    bVar1 = false;
                    bVar5 = true;
                  }
                }
                else {
                  if (((piVar21[-7] == 2) && (piVar21[-6] == *(int *)(iVar10 + 8))) ||
                     ((piVar21[7] == 2 && (piVar21[8] == *(int *)(iVar10 + 8))))) goto LAB_000bd88c;
                  if ((piVar21[-0xe] != 2) || (bVar5 = true, piVar21[-0xd] != *(int *)(iVar10 + 8)))
                  {
                    bVar5 = false;
                  }
                }
                uVar33 = uVar33 + 1;
                iVar14 = iVar14 + -1;
              } while ((iVar14 != 0) && (piVar21 = piVar21 + 0x1d, !bVar5));
              if (!bVar1) goto LAB_000bd970;
              iVar14 = uVar37 * 0x74;
            }
            else {
              uVar37 = 0;
              iVar14 = 0;
            }
            iVar19 = *(int *)(param_2 + 0x2c);
            if (iVar19 == 0) {
              iVar19 = FUN_00054dd0(iStack00000018,iVar32,
                                    *(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + iStack00000018) + 0x18)
                                   );
              iVar36 = *(int *)(param_2 + 0x18);
              *(int *)(param_2 + 0x2c) = iVar19;
            }
            iVar14 = iVar14 + iVar36;
            *(int *)(iVar10 + 0x24) = iVar19;
            uVar22 = *(undefined4 *)(iVar14 + 8);
            uVar31 = *(undefined4 *)(iVar14 + 0xc);
            uVar26 = *(undefined4 *)(iVar14 + 0x10);
            *(undefined4 *)(iVar10 + 4) = *(undefined4 *)(iVar14 + 4);
            *(undefined4 *)(iVar10 + 8) = uVar22;
            *(undefined4 *)(iVar10 + 0xc) = uVar31;
            *(undefined4 *)(iVar10 + 0x10) = uVar26;
            uVar22 = *(undefined4 *)(iVar14 + 0x14);
            uVar26 = *(undefined4 *)(iVar14 + 0x18);
            *(undefined4 *)(iVar10 + 0x1c) = *(undefined4 *)(iVar14 + 0x1c);
            *(undefined4 *)(iVar10 + 0x14) = uVar22;
            *(undefined4 *)(iVar10 + 0x18) = uVar26;
            uVar8 = *(int *)(param_2 + 0x14) - 1;
            *(uint *)(param_2 + 0x14) = uVar8;
            if (uVar37 < uVar8) {
              iVar36 = uVar37 * 0x74;
              do {
                uVar37 = uVar37 + 1;
                pvVar9 = (void *)(iVar36 + *(int *)(param_2 + 0x18));
                iVar36 = iVar36 + 0x74;
                _memcpy(pvVar9,(void *)((int)pvVar9 + 0x74),0x74);
                uVar8 = *(uint *)(param_2 + 0x14);
              } while (uVar37 < uVar8);
            }
          }
        }
LAB_000bd970:
        uVar17 = uVar17 + 1;
      } while (uVar17 < uVar8);
    }
  }
  return;
}

/* FUN_000bd9a0 @ 0xbd9a0 (160 bytes) */
int FUN_000bd9a0(param_1)
  int param_1;
{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
    *puVar3 = 0x860;
    *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_1 + 0x1b78);
    iVar2 = *(int *)(FUN_00002748 + param_1 + 4);
    pcVar1 = *(code **)(param_1 + 0x275c);
    *(int *)(FUN_00002748 + param_1 + 4) = iVar2 + 8;
    (*pcVar1)(param_1,iVar2 + 8);
    FUN_0009be00(param_1);
    FUN_0009cc30(param_1);
  }
  FUN_0004d620(param_1);
  return;
}

/* FUN_000bda40 @ 0xbda40 (1016 bytes) */
int FUN_000bda40(param_1)
  int param_1;
{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  
  uVar14 = *(uint *)(param_1 + 0x44);
  if (((((uVar14 & 0x2000) == 0) || ((*(byte *)(param_1 + 0x2e) & 1) != 0)) ||
      ((*(uint *)(param_1 + 0x38) & 0x8000) != 0)) || (*(short *)(param_1 + 0x42) != 0)) {
    bVar1 = ((unsigned char *)0x000013b0)[param_1];
    iVar16 = param_1 + 0x44;
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xf07fffff;
    *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xfdffffff;
    uVar24 = (uint)*(byte *)(param_1 + 0x2b);
    if ((uint)bVar1 < (uint)*(byte *)(param_1 + 0x2b)) {
      uVar24 = (uint)bVar1;
    }
    if ((uVar14 & 0x20000) == 0) {
      *(undefined1 *)(param_1 + 0x1878) = 0;
      uVar21 = 0;
    }
    else {
      if ((uVar14 & 0x2000) == 0) {
        bVar1 = ((unsigned char *)0x00001135)[param_1];
      }
      else {
        bVar1 = ((unsigned char *)0x000011d3)[param_1];
      }
      uVar21 = (uint)bVar1;
      *(byte *)(param_1 + 0x1878) = bVar1;
    }
    iVar18 = 0;
    if (uVar24 != 0) {
      uVar9 = 0;
      iVar8 = param_1;
      iVar22 = param_1;
      iVar23 = param_1;
      while( true ) {
        uVar6 = *(uint *)(iVar16 + 4) & 0x1e0;
        if ((uVar14 & 0x20000) == 0) {
          uVar14 = *(uint *)(iVar16 + 4) & 0x1f;
        }
        else {
          uVar14 = uVar21 & 1 << (uVar9 & 0x3f);
        }
        iVar10 = param_1 + 0x450 + uVar9 * 0xcc;
        if ((int)-uVar14 < 0) {
          iVar15 = uVar9 * 2 + param_1;
          bVar5 = *(char *)(iVar23 + 0x2784) == '\0';
          *(uint *)(iVar8 + 0x150) = (uint)bVar5;
          uVar7 = (ushort)bVar5 << 0xe;
          uVar2 = *(ushort *)(iVar15 + 0x187c);
          *(ushort *)(iVar15 + 0x187c) = uVar2 & 0xbfff | uVar7;
          if (uVar6 == 0) {
            *(ushort *)(iVar15 + 0x187c) = uVar2 & 0x8003 | uVar7;
            uVar14 = *(uint *)(param_1 + 0x8c);
          }
          else {
            uVar19 = uVar6 >> 7 & 1;
            sVar3 = *(short *)(iVar10 + 0x60);
            uVar14 = uVar6 >> 5 & 1;
            uVar20 = uVar6 >> 6 & 1;
            if ((uVar19 == 0) || (uVar17 = 1, 1 < (ushort)(*(short *)(iVar10 + 0x84) + 0x7aefU))) {
              uVar17 = 0;
            }
            uVar12 = 0;
            if (uVar14 != 0) {
              uVar12 = *(uint *)(&DAT_001dbf70 +
                                (*(ushort *)(iVar22 + 0x48c) >> 2 & 4 |
                                *(ushort *)(iVar22 + 0x48c) & 3) * 4);
            }
            if (uVar20 != 0) {
              uVar12 = uVar12 | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(iVar22 + 0x4b0) >> 2 & 4 |
                                        *(ushort *)(iVar22 + 0x4b0) & 3) * 4) << 3;
            }
            if (uVar19 != 0) {
              uVar12 = uVar12 | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(iVar22 + 0x4d4) >> 2 & 4 |
                                        *(ushort *)(iVar22 + 0x4d4) & 3) * 4) << 6;
            }
            if (uVar6 >> 8 != 0) {
              uVar12 = uVar12 | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(iVar22 + 0x4f8) >> 2 & 4 |
                                        *(ushort *)(iVar22 + 0x4f8) & 3) * 4) << 9;
            }
            iVar15 = uVar9 * 2 + param_1;
            uVar17 = (((ushort)(*(short *)(iVar10 + 0x3c) + 0x7aefU) < 2 || sVar3 == -0x7aee) ||
                     sVar3 == -0x7aef) | uVar17;
            uVar4 = (uint)(*(short *)(iVar10 + 0x3c) == 0x2402 || sVar3 == 0x2402);
            uVar13 = uVar17 | uVar4;
            *(ushort *)(iVar15 + 0x187c) =
                 *(ushort *)(iVar15 + 0x187c) & 0xc003 | (ushort)(uVar12 << 2) & 0x3ffc;
            uVar11 = *(uint *)(param_1 + 0x8c);
            uVar17 = (uVar17 | uVar11 >> 0x1b & 1) << 0x1b;
            *(uint *)(param_1 + 0x1874) =
                 (uVar13 | *(uint *)(param_1 + 0x1874) >> 0x19 & 1) << 0x19 |
                 *(uint *)(param_1 + 0x1874) & 0xfdffffff;
            uVar12 = (uVar4 | (uVar11 & 0xf7ffffff) >> 0x1a & 1) << 0x1a;
            *(uint *)(param_1 + 0x8c) = uVar12 | uVar17 | uVar11 & 0xf3ffffff;
            uVar14 = ((uVar11 & 0x2000000) >> 0x19 |
                     uVar13 | *(short *)(iVar10 + 0x3c) == 0x2400 & uVar14 |
                              *(short *)(iVar10 + 0x60) == 0x2400 & uVar20 |
                              *(short *)(iVar10 + 0x84) == 0x2400 & uVar19 |
                              (uint)(*(short *)(iVar10 + 0xa8) == 0x2400) & uVar6 >> 8) << 0x19 |
                     uVar12 | uVar17 | uVar11 & 0xf1ffffff;
            *(uint *)(param_1 + 0x8c) = uVar14;
          }
          *(uint *)(param_1 + 0x8c) = uVar14 | 0x800000;
          iVar10 = iVar18 * 4;
          iVar18 = iVar18 + 1;
          *(uint *)(param_1 + 0x8c) =
               (uint)(0 < (int)uVar9) << 0x18 | uVar14 & 0xfeffffff | 0x800000;
          *(uint *)(iVar10 + param_1 + 0x98) = uVar9;
        }
        else {
          *(undefined4 *)(iVar8 + 0x150) = 0;
          iVar10 = uVar9 * 2 + param_1;
          *(ushort *)(iVar10 + 0x187c) = *(ushort *)(iVar10 + 0x187c) & 0x8003;
        }
        uVar9 = uVar9 + 1;
        iVar16 = iVar16 + 4;
        iVar8 = iVar8 + 4;
        iVar22 = iVar22 + 0xcc;
        iVar23 = iVar23 + 1;
        uVar24 = uVar24 - 1;
        if (uVar24 == 0) break;
        uVar14 = *(uint *)(param_1 + 0x44);
      }
    }
    *(int *)(param_1 + 0x94) = iVar18;
  }
  return;
}

/* FUN_000bde70 @ 0xbde70 (1504 bytes) */
int FUN_000bde70(param_1, param_2, param_3, param_4)
  uint *param_1;
  uint *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  uint *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  int *piVar16;
  uint uVar17;
  uint uVar18;
  
  if (((param_4 == (undefined4 *)0x0) || (param_4[0xd] != -0x54520ff3)) ||
     (param_3 == (undefined4 *)0x0)) {
    uVar8 = 0x80000005;
  }
  else {
    iVar14 = -(*param_2 & 7);
    uVar18 = iVar14 + 3;
    uVar17 = (*param_1 & 0xf) + 1;
    if (uVar18 < 4) {
      uVar13 = uVar18;
      uVar6 = uVar18;
      if ((*param_2 >> 3 & 1) != 0) goto LAB_000bdeec;
      while( true ) {
        uVar17 = uVar17 + (param_2[uVar6 + 2] >> 6 & 0x3f) + 1;
        uVar13 = uVar6 + 1;
        if (3 < uVar6 + 1) break;
LAB_000bdeec:
        uVar17 = uVar17 + (param_2[uVar13 + 2] >> 0x11 & 0x1f) + 1;
        uVar6 = uVar13;
      }
    }
    piVar16 = (int *)*param_3;
    if (piVar16 == (int *)0x0) {
      piVar16 = (int *)(*(code *)*param_4)(uVar17 * 0x48 + 0x48);
      *piVar16 = 0;
      piVar16[1] = uVar17 + 1;
      *param_3 = piVar16;
    }
    else if ((*piVar16 != 0) || ((uint)piVar16[1] <= uVar17)) {
      return 0x80000006;
    }
    *(undefined2 *)(piVar16 + 5) = 0;
    piVar16[2] = 0;
    *(byte *)((int)piVar16 + 0xd) = (byte)(*param_1 >> 5) & 7;
    uVar13 = 0;
    puVar15 = param_1;
    piVar12 = piVar16;
    do {
      uVar4 = uVar13;
      piVar12[0x12] = 1;
      uVar13 = uVar4 + 1;
      *(byte *)(piVar12 + 0x14) = (byte)puVar15[1] & 0xf;
      *(byte *)((int)piVar12 + 0x51) = (byte)(puVar15[1] >> 4) & 1;
      *(byte *)((int)piVar12 + 0x52) = (byte)(puVar15[1] >> 0xc) & 0xf;
      *(byte *)((int)piVar12 + 0x53) = (byte)*(undefined2 *)(puVar15 + 1) & 3;
      *(byte *)(piVar12 + 0x15) = (byte)(puVar15[1] >> 0x19) & 1;
      *(byte *)((int)piVar12 + 0x55) = (byte)(puVar15[1] >> 0x1b);
      *(ushort *)((int)piVar12 + 0x4e) = (ushort)(puVar15[1] >> 0x12) & 0x7f;
      puVar15 = puVar15 + 1;
      uVar6 = *puVar15;
      *(undefined1 *)((int)piVar12 + 0x57) = 0;
      *(undefined1 *)((int)piVar12 + 0x56) = 0;
      *(ushort *)(piVar12 + 0x13) = (ushort)(uVar6 >> 5) & 0x7f;
      piVar12 = piVar12 + 0x12;
    } while (uVar13 <= (*param_1 & 0xf));
    iVar9 = uVar4 + 2;
    uVar13 = *param_2 >> 3 & 1;
    if (uVar18 < 4) {
      puVar15 = param_2 + iVar14 + 5;
      do {
        uVar4 = *puVar15;
        puVar15 = puVar15 + 1;
        uVar6 = uVar4 & 0x3f;
        uVar10 = uVar4 >> 0xc & 0x1f;
        if ((uVar13 != 0) && (uVar13 = uVar10 + (uVar4 >> 0x11 & 0x1f), uVar10 <= uVar13)) {
          iVar14 = uVar10 << 2;
          piVar12 = piVar16 + iVar9 * 0x12;
          uVar11 = uVar10;
          do {
            *piVar12 = 2;
            bVar3 = uVar11 == uVar10;
            uVar11 = uVar11 + 1;
            iVar9 = iVar9 + 1;
            *(byte *)((int)piVar12 + 0x19) = (byte)(*(uint *)(iVar14 + param_2[7]) >> 0xb) & 0xf;
            uVar5 = *(uint *)(iVar14 + param_2[7]);
            *(bool *)(piVar12 + 8) = bVar3;
            *(undefined1 *)((int)piVar12 + 0x1f) = 0;
            *(byte *)((int)piVar12 + 0x1a) = (byte)(uVar5 >> 0xf) & 7;
            *(ushort *)((int)piVar12 + 0xe) = (ushort)*(undefined4 *)(iVar14 + param_2[7]) & 0x1f;
            puVar1 = (uint *)(iVar14 + param_2[7]);
            iVar14 = iVar14 + 4;
            *(ushort *)(piVar12 + 3) = (ushort)(*puVar1 >> 6) & 0x1f;
            piVar12 = piVar12 + 0x12;
          } while (uVar11 <= uVar13);
        }
        uVar13 = uVar6 + (uVar4 >> 6 & 0x3f);
        if (uVar6 <= uVar13) {
          iVar14 = uVar6 << 2;
          piVar12 = piVar16 + iVar9 * 0x12;
          do {
            *piVar12 = 3;
            *(byte *)(piVar12 + 5) = (byte)(*(uint *)(param_2[8] + iVar14) >> 0x17) & 7;
            *(byte *)((int)piVar12 + 0x15) =
                 (byte)((uint)*(undefined4 *)(param_2[8] + iVar14) >> 0x1a) & 7;
            *(byte *)((int)piVar12 + 0x16) =
                 (byte)((uint)*(undefined4 *)(param_2[8] + iVar14) >> 0x1d) & 3;
            uVar4 = *(uint *)(param_2[8] + iVar14) & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)piVar12 + 0xe) = uVar7;
            uVar4 = *(uint *)(param_2[8] + iVar14) >> 6 & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)(piVar12 + 4) = uVar7;
            uVar4 = *(uint *)(param_2[8] + iVar14) >> 0xc & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)piVar12 + 0x12) = uVar7;
            *(ushort *)(piVar12 + 3) =
                 (ushort)((uint)*(undefined4 *)(param_2[8] + iVar14) >> 0x12) & 0x1f;
            *(byte *)(piVar12 + 8) = (byte)(*(uint *)(param_2[9] + iVar14) >> 0x17) & 1;
            *(byte *)((int)piVar12 + 0x21) = *(byte *)(param_2[9] + iVar14) & 1;
            *(byte *)((int)piVar12 + 0x22) =
                 (byte)((uint)*(undefined4 *)(param_2[9] + iVar14) >> 0x19) & 3;
            *(byte *)((int)piVar12 + 0x23) =
                 (byte)((uint)*(undefined4 *)(param_2[9] + iVar14) >> 0x1b) & 1;
            uVar4 = *(uint *)(param_2[9] + iVar14) & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)piVar12 + 0x1a) = uVar7;
            uVar4 = *(uint *)(param_2[9] + iVar14) >> 6 & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)(piVar12 + 7) = uVar7;
            uVar4 = *(uint *)(param_2[9] + iVar14) >> 0xc & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)piVar12 + 0x1e) = uVar7;
            uVar6 = uVar6 + 1;
            iVar9 = iVar9 + 1;
            *(ushort *)(piVar12 + 6) =
                 (ushort)((uint)*(undefined4 *)(param_2[9] + iVar14) >> 0x12) & 0x1f;
            *(byte *)((int)piVar12 + 0x2a) = (byte)*(undefined4 *)(param_2[0xb] + iVar14) & 0x1f;
            *(byte *)((int)piVar12 + 0x2d) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 5) & 3;
            *(byte *)((int)piVar12 + 0x2b) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 7) & 0x1f;
            *(byte *)((int)piVar12 + 0x2e) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 0xc) & 3;
            *(byte *)(piVar12 + 0xb) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 0xe) & 0x1f;
            *(byte *)((int)piVar12 + 0x2f) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 0x13) & 3;
            *(byte *)(piVar12 + 0xc) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 0x15) & 3;
            *(byte *)((int)piVar12 + 0x31) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 0x17) & 0xf;
            *(byte *)((int)piVar12 + 0x32) =
                 (byte)((uint)*(undefined4 *)(param_2[0xb] + iVar14) >> 0x1b) & 7;
            *(byte *)((int)piVar12 + 0x33) =
                 (byte)((uint)*(undefined4 *)(param_2[0xb] + iVar14) >> 0x1e) & 1;
            *(byte *)(piVar12 + 0xd) = (byte)((uint)*(undefined4 *)(param_2[0xb] + iVar14) >> 0x1f);
            *(byte *)((int)piVar12 + 0x39) = (byte)*(undefined4 *)(iVar14 + param_2[0xc]) & 0x1f;
            *(byte *)(piVar12 + 0xf) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 5) & 3;
            *(byte *)((int)piVar12 + 0x3a) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 7) & 0x1f;
            *(byte *)((int)piVar12 + 0x3d) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 0xc) & 3;
            *(byte *)((int)piVar12 + 0x3b) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 0xe) & 0x1f;
            *(byte *)((int)piVar12 + 0x3e) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 0x13) & 3;
            *(byte *)((int)piVar12 + 0x3f) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 0x15) & 3;
            *(byte *)(piVar12 + 0x10) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 0x17) & 0xf;
            *(byte *)((int)piVar12 + 0x41) =
                 (byte)((uint)*(undefined4 *)(iVar14 + param_2[0xc]) >> 0x1b) & 7;
            puVar2 = (undefined4 *)(iVar14 + param_2[0xc]);
            iVar14 = iVar14 + 4;
            *(byte *)((int)piVar12 + 0x42) = (byte)((uint)*puVar2 >> 0x1e) & 1;
            piVar12 = piVar12 + 0x12;
          } while (uVar6 <= uVar13);
        }
        bVar3 = uVar18 != 3;
        uVar13 = 1;
        uVar18 = uVar18 + 1;
      } while (bVar3);
    }
    uVar8 = 0;
    piVar16[2] = uVar17;
  }
  return uVar8;
}

/* FUN_000bf400 @ 0xbf400 (1260 bytes) */
int FUN_000bf400(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  char cVar10;
  uint uVar7;
  int iVar8;
  int *piVar9;
  undefined *puVar11;
  undefined *puVar12;
  undefined *puVar13;
  uint uVar14;
  uint *puVar15;
  undefined *puVar16;
  undefined1 *puVar17;
  undefined *puVar18;
  uint uVar19;
  byte bVar20;
  
  if (param_2 <= (*(byte *)(param_1 + 0xf) & 0xf)) {
    return;
  }
  puVar12 = *(undefined **)(param_1 + 8);
  if ((*(int *)(param_1 + 0x48) == 1) && (puVar12 != (undefined *)0x0)) {
    piVar9 = (int *)(param_1 + 0x90);
    puVar11 = (undefined *)0x1;
    do {
      puVar11 = puVar11 + 1;
      if (*piVar9 != 1) goto LAB_000bf474;
      piVar9 = piVar9 + 0x12;
    } while (puVar11 <= puVar12);
LAB_000bf44c:
    bVar20 = 0;
    uVar19 = 0;
    bVar3 = true;
  }
  else {
    puVar11 = (undefined *)0x1;
LAB_000bf474:
    if (puVar12 < puVar11) goto LAB_000bf44c;
    bVar20 = 0;
    bVar3 = true;
    puVar15 = (uint *)(param_1 + (int)puVar11 * 0x48);
    uVar7 = 0;
    uVar14 = 0;
    bVar1 = false;
    uVar19 = 0;
    puVar16 = puVar11;
    do {
      uVar4 = *puVar15;
      if (uVar4 < 5) {
        if (uVar4 < 3) {
          if ((uVar4 == 2) &&
             (bVar20 = bVar20 | *(byte *)(puVar15 + 1) | *(byte *)((int)puVar15 + 0x1b),
             *(char *)((int)puVar15 + 0x1a) != '\0')) {
            uVar19 = uVar19 | -(puVar15[7] & 0xffff00) >> 0x1f;
          }
        }
        else {
          bVar20 = bVar20 | *(byte *)(puVar15 + 1);
        }
      }
      else if ((uVar4 == 5) && (bVar20 = bVar20 | *(byte *)(puVar15 + 1), bVar3)) {
        if ((*(char *)((int)puVar15 + 0xe) != '\0') || (*(char *)((int)puVar15 + 0x11) != '\0')) {
          bVar1 = true;
        }
        uVar4 = puVar15[4] & 0xff00ff00;
        if ((uVar4 != 0) &&
           ((*(ushort *)(puVar15 + 3) < uVar14 || (*(char *)((int)puVar15 + 0x19) != '\0')))) {
          bVar1 = true;
        }
        cVar5 = *(char *)(puVar15 + 5);
        cVar6 = *(char *)((int)puVar15 + 0x15);
        cVar10 = cVar5;
        if ((uVar4 != 0) && (cVar10 = cVar6, uVar4 == 0x100ff00)) {
          cVar5 = cVar6;
        }
        cVar6 = cVar10;
        if ((cVar5 == '\x01') || (cVar6 = cVar5, cVar5 != '\0')) {
          if (cVar6 == '\x02') goto LAB_000bf5b4;
          if (cVar6 == '\x01') {
            uVar7 = uVar7 - *(byte *)((int)puVar15 + 0x13);
          }
        }
        else if (cVar10 == '\x02') {
LAB_000bf5b4:
          uVar7 = uVar7 + 1;
        }
        bVar3 = !bVar1;
        if (4 < uVar7) {
          bVar1 = true;
          bVar3 = false;
        }
      }
      puVar16 = puVar16 + 1;
      uVar14 = uVar14 + 1;
      puVar15 = puVar15 + 0x12;
    } while (puVar16 <= puVar12);
    if (uVar14 != 0) goto LAB_000bf45c;
  }
  uVar14 = 1;
LAB_000bf45c:
  if ((*(short *)(param_1 + 0x20) == 0) && (*(short *)(param_1 + 0x12) == 0)) {
    *(short *)(param_1 + 0x12) = (short)uVar14 + -1;
  }
  if (!bVar3) {
    *(undefined2 *)(param_1 + 0x28) = 1;
  }
  if ((*(short *)(param_1 + 0x28) != 0) && (*(short *)(param_1 + 0x22) == 0)) {
    *(undefined2 *)(param_1 + 0x22) = 1;
  }
  if (puVar11 <= puVar12) {
    bVar1 = bVar20 != 0;
    puVar15 = (uint *)(param_1 + (int)puVar11 * 0x48);
    uVar14 = 0;
    puVar17 = (undefined1 *)((int)puVar15 + -3);
    puVar16 = ((unsigned char *)0x000186a0);
    puVar18 = puVar11;
    do {
      uVar7 = *puVar15;
      puVar13 = puVar16;
      if (uVar7 < 5) {
        if (uVar7 < 3) {
          if (uVar7 == 2) {
            if (uVar19 == 0) {
              *(undefined1 *)((int)puVar15 + 0x1d) = 7;
              *(undefined1 *)((int)puVar15 + 0x1e) = 1;
              puVar15[5] = puVar15[5] & 0xffff | 0x1b1b0000;
            }
            bVar2 = *(byte *)((int)puVar15 + 0x1f);
            if (bVar2 != 0) {
              if ((bVar2 & 2) != 0) {
                puVar15[5] = puVar15[5] >> 2 & 0x300000 | puVar15[5] & 0xffcfffff;
              }
              if ((bVar2 & 4) != 0) {
                puVar15[5] = puVar15[5] >> 4 & 0xc0000 | puVar15[5] & 0xfff3ffff;
              }
              if ((bVar2 & 8) != 0) {
                puVar15[5] = puVar15[5] >> 6 & 0x30000 | puVar15[5] & 0xfffcffff;
              }
            }
            puVar13 = puVar18;
            if (((!bVar1) && (*(char *)(puVar15 + 8) != '\0')) && (puVar16 != ((unsigned char *)0x000186a0))) {
              iVar8 = param_1 + (int)puVar16 * 0x48;
              *(undefined1 *)(iVar8 + 4) = 1;
              *(undefined1 *)(iVar8 + 0x1b) = 1;
              *(undefined1 *)(puVar15 + 1) = 1;
            }
          }
        }
        else {
          if (((*(char *)((int)puVar15 + 0x15) == '\0') && ((puVar15[8] & 0xff00ff) == 0)) &&
             (uVar14 != *(ushort *)(param_1 + 0x12))) {
            *puVar15 = 4;
          }
          if ((bVar1) || (puVar16 == ((unsigned char *)0x000186a0))) {
LAB_000bf860:
            puVar13 = ((unsigned char *)0x000186a0);
          }
          else {
            iVar8 = param_1 + (int)puVar16 * 0x48;
            *(undefined1 *)(iVar8 + 4) = 1;
            *(undefined1 *)(iVar8 + 0x1b) = 1;
            *(undefined1 *)(puVar15 + 1) = 1;
            puVar13 = ((unsigned char *)0x000186a0);
          }
        }
      }
      else if (uVar7 == 5) {
        if ((!bVar1) && (puVar16 != ((unsigned char *)0x000186a0))) {
          iVar8 = param_1 + (int)puVar16 * 0x48;
          *(undefined1 *)(iVar8 + 4) = 1;
          *(undefined1 *)(iVar8 + 0x1b) = 1;
          *(undefined1 *)(puVar15 + 1) = 1;
        }
        if ((((byte)(*(byte *)((int)puVar15 + 0x12) & 0xf0) ==
              (byte)(*(byte *)((int)puVar15 + 0x12) << 4)) || (uVar14 == 0)) ||
           (1 < *(int *)(puVar17 + -0x45) - 3U)) goto LAB_000bf860;
        *puVar17 = 1;
        puVar13 = ((unsigned char *)0x000186a0);
      }
      puVar18 = puVar18 + 1;
      uVar14 = uVar14 + 1;
      puVar15 = puVar15 + 0x12;
      puVar17 = puVar17 + 0x48;
      puVar16 = puVar13;
    } while (puVar18 <= puVar12);
    if (((uVar14 != 0) &&
        (*(int *)(param_1 + (int)(puVar11 + *(ushort *)(param_1 + 0x12)) * 0x48) == 3)) &&
       (bVar20 == 0)) {
      *(undefined1 *)(param_1 + (int)(puVar11 + *(ushort *)(param_1 + 0x12)) * 0x48 + 4) = 1;
    }
  }
  if (((uVar19 != 0) || (bVar20 != 0)) || (*(short *)(param_1 + 0x20) != 0)) {
    param_2 = param_2 | param_2 << 4;
  }
  *(char *)(param_1 + 0xf) = (char)param_2;
  return;
}

/* FUN_000bf910 @ 0xbf910 (796 bytes) */
int FUN_000bf910(param_1, param_2, param_3, param_4)
  uint *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x80) != 0) {
    *param_1 = uVar1 & 0xffffff7f;
    return;
  }
  switch(uVar1) {
  case 0:
    *param_1 = 0;
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 2;
    return;
  case 1:
    *param_1 = 0;
    *param_2 = 0;
    *param_3 = 0;
    *param_4 = 0;
    return;
  case 2:
    uVar2 = 1;
    break;
  case 3:
    uVar2 = 2;
    break;
  case 4:
    *param_1 = 1;
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 2;
    return;
  case 5:
    uVar2 = 0;
    goto LAB_000bfac8;
  case 6:
    *param_1 = 1;
    *param_2 = 1;
    *param_3 = 1;
    *param_4 = 1;
    return;
  case 7:
    uVar2 = 2;
    goto LAB_000bfac8;
  case 8:
    *param_1 = 2;
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 2;
    return;
  case 9:
    uVar2 = 0;
    goto LAB_000bfae4;
  case 10:
    uVar2 = 1;
    goto LAB_000bfae4;
  case 0xb:
    *param_1 = 2;
    *param_2 = 2;
    *param_3 = 2;
    *param_4 = 2;
    return;
  case 0xc:
    uVar2 = 3;
    break;
  case 0xd:
    uVar2 = 3;
LAB_000bfac8:
    *param_1 = 1;
    *param_2 = uVar2;
    *param_3 = uVar2;
    *param_4 = uVar2;
    return;
  case 0xe:
    uVar2 = 3;
LAB_000bfae4:
    *param_1 = 2;
    *param_2 = uVar2;
    *param_3 = uVar2;
    *param_4 = uVar2;
    return;
  case 0xf:
    *param_1 = 3;
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 2;
    return;
  case 0x10:
    uVar2 = 0;
    goto LAB_000bfb34;
  case 0x11:
    uVar2 = 1;
    goto LAB_000bfb34;
  case 0x12:
    uVar2 = 2;
LAB_000bfb34:
    *param_1 = 3;
    *param_2 = uVar2;
    *param_3 = uVar2;
    *param_4 = uVar2;
    return;
  case 0x13:
    *param_1 = 3;
    *param_2 = 3;
    *param_3 = 3;
    *param_4 = 3;
    return;
  case 0x14:
    uVar2 = 4;
    break;
  case 0x15:
    uVar2 = 6;
    break;
  case 0x16:
    uVar2 = 5;
    break;
  case 0x17:
    *param_1 = 0;
    *param_2 = 1;
    *param_3 = 2;
    *param_4 = 0;
    return;
  case 0x18:
    *param_1 = 1;
    *param_2 = 1;
    *param_3 = 2;
    *param_4 = 0;
    return;
  case 0x19:
    *param_1 = 2;
    *param_2 = 1;
    *param_3 = 2;
    *param_4 = 0;
    return;
  case 0x1a:
    *param_1 = 0;
    *param_2 = 2;
    *param_3 = 0;
    *param_4 = 1;
    return;
  case 0x1b:
    *param_1 = 1;
    *param_2 = 2;
    *param_3 = 0;
    *param_4 = 1;
    return;
  case 0x1c:
    *param_1 = 2;
    *param_2 = 2;
    *param_3 = 0;
    *param_4 = 1;
    return;
  case 0x1d:
    *param_1 = 0;
    *param_2 = 3;
    *param_3 = 2;
    *param_4 = 1;
    return;
  case 0x1e:
    *param_1 = 1;
    *param_2 = 3;
    *param_3 = 2;
    *param_4 = 1;
    return;
  case 0x1f:
    *param_1 = 2;
    *param_2 = 3;
    *param_3 = 2;
    *param_4 = 1;
    return;
  default:
    return;
  }
  *param_1 = 0;
  *param_2 = uVar2;
  *param_3 = uVar2;
  *param_4 = uVar2;
  return;
}

/* FUN_000bfcc0 @ 0xbfcc0 (440 bytes) */
int FUN_000bfcc0(param_1, param_2)
  uint *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x80) == 0) {
    switch(uVar1) {
    case 0:
      *param_1 = 0;
      *param_2 = 0;
      return;
    case 1:
      *param_1 = 0;
      *param_2 = 1;
      return;
    case 2:
      *param_1 = 0;
      *param_2 = 2;
      return;
    case 3:
      *param_1 = 1;
      *param_2 = 0;
      return;
    case 4:
      *param_1 = 1;
      *param_2 = 1;
      return;
    case 5:
      *param_1 = 1;
      *param_2 = 2;
      return;
    case 6:
      *param_1 = 2;
      *param_2 = 0;
      return;
    case 7:
      *param_1 = 2;
      *param_2 = 1;
      return;
    case 8:
      *param_1 = 2;
      *param_2 = 2;
      return;
    case 9:
      *param_1 = 0;
      *param_2 = 3;
      return;
    case 10:
      *param_1 = 1;
      *param_2 = 3;
      return;
    case 0xb:
      *param_1 = 2;
      *param_2 = 3;
      return;
    case 0xc:
      *param_1 = 3;
      *param_2 = 0;
      return;
    case 0xd:
      *param_1 = 3;
      *param_2 = 1;
      return;
    case 0xe:
      *param_1 = 3;
      *param_2 = 2;
      return;
    case 0xf:
      *param_1 = 3;
      *param_2 = 3;
      return;
    case 0x10:
      *param_1 = 0;
      *param_2 = 4;
      return;
    case 0x11:
      *param_1 = 0;
      *param_2 = 6;
      return;
    case 0x12:
      *param_1 = 0;
      *param_2 = 5;
      return;
    default:
      return;
    }
  }
  *param_1 = uVar1 & 0xffffff7f;
  return;
}

/* FUN_000bfed0 @ 0xbfed0 (2464 bytes) */
int FUN_000bfed0(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  uint *param_3;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  ushort uVar17;
  ushort uVar18;
  ushort uVar19;
  ushort uVar20;
  ushort uVar21;
  ushort uVar22;
  ushort uVar23;
  ushort uVar24;
  bool bVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  int *piVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  int *piVar45;
  int *piVar46;
  uint uVar47;
  uint uVar48;
  int iVar49;
  uint uVar50;
  uint uVar51;
  int *piVar52;
  int iVar53;
  uint uVar54;
  uint uVar55;
  int iVar56;
  int iVar57;
  byte bVar58;
  uint uVar59;
  uint *puVar60;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint *local_68;
  uint *local_64;
  uint *local_60;
  
  ((int (*)())FUN_000c5e60)();
  if (0x10 < *(ushort *)(param_1 + 0x18)) {
    return 0x80000014;
  }
  if (0x200 < (uint)*(ushort *)(param_1 + 0x1a) + (uint)*(ushort *)(param_1 + 0x1c) +
              (uint)*(ushort *)(param_1 + 0x20)) {
    return 0x80000018;
  }
  if (0x7f < *(ushort *)(param_1 + 0x22)) {
    return 0x80000012;
  }
  if (0xff < *(ushort *)(param_1 + 0x24)) {
    return 0x80000013;
  }
  ((int (*)())FUN_000bf400)(param_1,1);
  uVar55 = *(uint *)(param_1 + 8);
  if ((*(int *)(param_1 + 0x48) == 1) && (uVar55 != 0)) {
    piVar46 = (int *)(param_1 + 0x90);
    uVar59 = 1;
    piVar39 = piVar46;
    uVar43 = 0;
    piVar52 = (int *)(param_1 + 0x48);
    do {
      piVar45 = piVar39;
      uVar48 = uVar43;
      if ((piVar52[2] & 0xff00ffU) != 0) {
        uVar48 = uVar43 + 1;
        param_2[uVar43 + 1] = 0;
        bVar58 = *(byte *)(piVar52 + 2);
        param_2[uVar43 + 1] = bVar58 & 0xf;
        uVar40 = (*(byte *)((int)piVar52 + 9) & 1) << 4 | bVar58 & 0xf;
        param_2[uVar43 + 1] = uVar40;
        uVar40 = (*(byte *)((int)piVar52 + 10) & 0xf) << 0xc | uVar40;
        param_2[uVar43 + 1] = uVar40;
        uVar40 = (*(byte *)((int)piVar52 + 0xb) & 3) << 0x10 | uVar40;
        param_2[uVar43 + 1] = uVar40;
        uVar40 = (*(byte *)(piVar52 + 3) & 1) << 0x19 | uVar40;
        param_2[uVar43 + 1] = uVar40;
        uVar40 = (*(ushort *)(piVar52 + 1) & 0x7f) << 5 | uVar40;
        param_2[uVar43 + 1] = uVar40;
        param_2[uVar43 + 1] = (*(ushort *)((int)piVar52 + 6) & 0x7f) << 0x12 | uVar40;
      }
      uVar59 = uVar59 + 1;
      if (*piVar46 != 1) break;
      piVar46 = piVar46 + 0x12;
      piVar39 = piVar45 + 0x12;
      uVar43 = uVar48;
      piVar52 = piVar45;
    } while (uVar59 <= uVar55);
    uVar43 = uVar48 & 0xff;
    if (uVar48 == 0) goto LAB_000c004c;
  }
  else {
    uVar59 = 1;
LAB_000c004c:
    uVar43 = 1;
    param_2[1] = 0;
  }
  uVar43 = uVar43 - 1 & 0xf;
  *param_2 = uVar43;
  *param_2 = (*(byte *)(param_1 + 0xd) & 7) << 5 | uVar43;
  if (uVar55 < uVar59) {
    iVar56 = 0;
    bVar58 = 0;
    iVar53 = 0;
    iVar49 = 1;
  }
  else {
    local_68 = &local_6c;
    local_60 = &local_70;
    bVar58 = 0;
    puVar60 = (uint *)(uVar59 * 0x48 + param_1);
    local_64 = &local_74;
    bVar25 = true;
    iVar49 = 0;
    iVar56 = 0;
    do {
      iVar57 = iVar56;
      uVar43 = *puVar60;
      uVar48 = 0;
      if (uVar43 < 5) {
        if (uVar43 < 3) {
          if (uVar43 == 2) {
            uVar24 = *(ushort *)((int)puVar60 + 0xe);
            uVar17 = *(ushort *)(puVar60 + 3);
            bVar25 = true;
            uVar43 = puVar60[5];
            bVar1 = *(byte *)((int)puVar60 + 6);
            bVar2 = *(byte *)((int)puVar60 + 7);
            bVar3 = *(byte *)(puVar60 + 2);
            bVar4 = *(byte *)((int)puVar60 + 9);
            bVar5 = *(byte *)((int)puVar60 + 0xb);
            bVar6 = *(byte *)((int)puVar60 + 0x1d);
            bVar7 = *(byte *)((int)puVar60 + 0x1e);
            uVar18 = *(ushort *)(puVar60 + 4);
            uVar19 = *(ushort *)((int)puVar60 + 0x12);
            bVar8 = *(byte *)(puVar60 + 1);
            bVar9 = *(byte *)((int)puVar60 + 5);
            *(uint *)(iVar49 + param_3[4] + 4) =
                 (*(byte *)((int)puVar60 + 0x1b) & 1) << 0x19 |
                 (*(byte *)(puVar60 + 7) & 1) << 0x1a |
                 (*(byte *)(puVar60 + 6) & 1) << 0x1b |
                 (*(byte *)((int)puVar60 + 0x1a) & 7) << 0x16 |
                 (*(byte *)((int)puVar60 + 0x19) & 0xf) << 0x10;
            *(uint *)(iVar49 + param_3[4] + 8) =
                 (uVar43 & 0x3000000) << 6 |
                 (uVar43 & 0xc000000) << 2 |
                 uVar43 >> 2 & 0xc000000 |
                 uVar43 >> 6 & 0x3000000 |
                 uVar43 >> 2 & 0xc000 |
                 uVar43 >> 6 & 0x3000 |
                 uVar43 >> 10 & 0xc00 |
                 uVar43 >> 0xe & 0x300 |
                 (uVar17 & 0x4000) << 9 |
                 (uVar17 & 0x7f) << 0x10 | uVar24 >> 7 & 0x80 | uVar24 & 0x7f;
            uVar48 = (bVar7 & 1) << 0xe |
                     (bVar6 & 7) << 0xb |
                     (bVar5 & 1) << 10 |
                     (bVar4 & 1) << 7 |
                     (bVar3 & 1) << 0x16 |
                     (bVar2 & 7) << 0x19 |
                     (bVar1 & 1) << 6 | (bVar9 & 7) << 3 | (bVar8 & 1) << 2 | 3;
            *(uint *)(iVar49 + param_3[4] + 0xc) =
                 uVar43 << 0x1e |
                 (uVar43 & 0xc) << 0x1a |
                 (uVar43 & 0x30) << 0x16 |
                 (uVar43 & 0xc0) << 0x12 |
                 (uVar43 & 0x300) << 6 |
                 (uVar43 & 0xc00) << 2 |
                 uVar43 >> 2 & 0xc00 |
                 uVar43 >> 6 & 0x300 |
                 (uVar19 & 0x4000) << 9 |
                 (uVar19 & 0x7f) << 0x10 | uVar18 >> 7 & 0x80 | uVar18 & 0x7f;
            *(undefined4 *)(iVar49 + param_3[4] + 0x10) = 0;
            *(undefined4 *)(iVar49 + param_3[4] + 0x14) = 0;
          }
        }
        else {
          uVar24 = *(ushort *)((int)puVar60 + 0xe);
          uVar40 = 0xffffff80;
          uVar48 = (*(byte *)(puVar60 + 0x11) & 3) << 0x17 |
                   (*(byte *)((int)puVar60 + 0x43) & 1) << 0x15 |
                   (*(byte *)(puVar60 + 0xd) & 1) << 9 |
                   (*(byte *)((int)puVar60 + 0x42) & 1) << 0x14 |
                   (*(byte *)((int)puVar60 + 0x33) & 1) << 0x13 |
                   (*(byte *)((int)puVar60 + 0x21) & 1) << 0x12 |
                   (*(byte *)((int)puVar60 + 0x15) & 7) << 0xf |
                   (*(byte *)(puVar60 + 8) & 1) << 0xe |
                   (*(byte *)(puVar60 + 5) & 7) << 0xb |
                   (*(byte *)((int)puVar60 + 10) & 1) << 8 |
                   (*(byte *)((int)puVar60 + 9) & 1) << 7 |
                   (*(byte *)(puVar60 + 2) & 1) << 0x16 |
                   (*(byte *)((int)puVar60 + 7) & 7) << 0x19 |
                   (*(byte *)((int)puVar60 + 6) & 1) << 6 |
                   (*(byte *)((int)puVar60 + 5) & 7) << 3 |
                   (*(byte *)(puVar60 + 1) & 1) << 2 | (uint)(uVar43 == 3);
          if ((uVar24 & 0x2000) == 0) {
            uVar40 = 0;
          }
          uVar17 = *(ushort *)(puVar60 + 4);
          uVar43 = 0xffffff80;
          if ((uVar17 & 0x2000) == 0) {
            uVar43 = 0;
          }
          uVar18 = *(ushort *)((int)puVar60 + 0x12);
          uVar47 = 0xffffff80;
          if ((uVar18 & 0x2000) == 0) {
            uVar47 = 0;
          }
          uVar19 = *(ushort *)((int)puVar60 + 0x1a);
          bVar1 = *(byte *)(puVar60 + 0xc);
          uVar50 = 0xffffff80;
          if ((uVar19 & 0x2000) == 0) {
            uVar50 = 0;
          }
          uVar20 = *(ushort *)(puVar60 + 7);
          uVar54 = 0xffffff80;
          if ((uVar20 & 0x2000) == 0) {
            uVar54 = 0;
          }
          uVar21 = *(ushort *)((int)puVar60 + 0x1e);
          uVar51 = 0xffffff80;
          if ((uVar21 & 0x2000) == 0) {
            uVar51 = 0;
          }
          local_6c = (uint)*(byte *)((int)puVar60 + 0x2a);
          bVar2 = *(byte *)((int)puVar60 + 0x3f);
          uVar41 = puVar60[9];
          local_70 = uVar41 >> 0x17 & 7;
          local_78 = uVar41 >> 0x1d;
          local_74 = uVar41 >> 0x1a & 7;
          ((int (*)())FUN_000bf910)(local_68,&local_78,local_64,local_60);
          uVar41 = local_6c & 3;
          uVar26 = local_78 & 7;
          uVar27 = local_74 & 7;
          uVar44 = puVar60[9];
          uVar28 = local_70 & 7;
          local_6c = uVar44 >> 7 & 7;
          local_74 = uVar44 >> 0xd & 7;
          local_78 = uVar44 >> 10 & 7;
          local_70 = (uint)*(byte *)((int)puVar60 + 0x2b);
          ((int (*)())FUN_000bf910)(local_60,local_64,&local_78,local_68);
          bVar3 = *(byte *)((int)puVar60 + 0x2d);
          bVar4 = *(byte *)((int)puVar60 + 0x2e);
          bVar5 = *(byte *)((int)puVar60 + 0x32);
          bVar6 = *(byte *)((int)puVar60 + 0x16);
          bVar7 = *(byte *)((int)puVar60 + 0x45);
          uVar44 = local_70 & 3;
          uVar29 = local_74 & 7;
          uVar30 = local_78 & 7;
          uVar31 = local_6c & 7;
          local_78 = (uint)*(byte *)((int)puVar60 + 0x36);
          local_6c = (uint)*(byte *)((int)puVar60 + 0x39);
          ((int (*)())FUN_000bfcc0)(local_68,&local_78);
          uVar32 = local_6c & 3;
          uVar33 = local_78 & 7;
          local_6c = (uint)*(byte *)((int)puVar60 + 0x37);
          local_78 = (uint)*(byte *)((int)puVar60 + 0x3a);
          ((int (*)())FUN_000bfcc0)(&local_78,local_68);
          bVar8 = *(byte *)(puVar60 + 0xf);
          bVar9 = *(byte *)((int)puVar60 + 0x3d);
          uVar22 = *(ushort *)(puVar60 + 3);
          bVar10 = *(byte *)((int)puVar60 + 0x41);
          bVar11 = *(byte *)((int)puVar60 + 0x22);
          uVar23 = *(ushort *)(puVar60 + 6);
          uVar34 = local_78 & 3;
          bVar12 = *(byte *)((int)puVar60 + 0x23);
          bVar13 = *(byte *)(puVar60 + 0x10);
          uVar35 = local_6c & 7;
          bVar14 = *(byte *)((int)puVar60 + 0x31);
          uVar42 = puVar60[10];
          local_78 = uVar42 >> 0x1d;
          local_70 = uVar42 >> 0x17 & 7;
          local_74 = uVar42 >> 0x1a & 7;
          local_6c = (uint)*(byte *)(puVar60 + 0xb);
          ((int (*)())FUN_000bf910)(local_68,&local_78,local_64,local_60);
          uVar42 = local_6c & 3;
          uVar36 = local_78 & 7;
          uVar37 = local_74 & 7;
          local_78 = (uint)*(byte *)(puVar60 + 0xe);
          uVar38 = local_70 & 7;
          local_70 = (uint)*(byte *)((int)puVar60 + 0x3b);
          ((int (*)())FUN_000bfcc0)(local_60,&local_78);
          bVar25 = false;
          bVar15 = *(byte *)((int)puVar60 + 0x2f);
          bVar16 = *(byte *)((int)puVar60 + 0x3e);
          *(uint *)(iVar49 + param_3[4] + 4) =
               (uint)bVar1 << 0x1e |
               (uVar18 & 0x4000) << 0xf |
               (uVar18 & 0x8000) << 0xd |
               (uVar47 & 0xff | uVar18 & 0x7f) << 0x14 |
               (uVar17 & 0x4000) << 5 |
               (uVar17 & 0x8000) << 3 |
               (uVar43 & 0xff | uVar17 & 0x7f) << 10 |
               uVar24 >> 5 & 0x200 | uVar24 >> 7 & 0x100 | uVar40 & 0xff | uVar24 & 0x7f;
          *(uint *)(iVar49 + param_3[4] + 8) =
               (uint)bVar2 << 0x1e |
               (uVar21 & 0x4000) << 0xf |
               (uVar21 & 0x8000) << 0xd |
               (uVar51 & 0xff | uVar21 & 0x7f) << 0x14 |
               (uVar20 & 0x4000) << 5 |
               (uVar20 & 0x8000) << 3 |
               (uVar54 & 0xff | uVar20 & 0x7f) << 10 |
               uVar19 >> 5 & 0x200 | uVar19 >> 7 & 0x100 | uVar50 & 0xff | uVar19 & 0x7f;
          *(uint *)(iVar49 + param_3[4] + 0xc) =
               (uint)bVar7 << 0x1f |
               (bVar6 & 3) << 0x1d |
               (bVar5 & 7) << 0x1a |
               (bVar4 & 3) << 0x18 |
               (bVar3 & 3) << 0xb |
               uVar31 << 0x15 |
               uVar30 << 0x12 |
               uVar29 << 0xf | uVar44 << 0xd | uVar28 << 8 | uVar27 << 5 | uVar26 << 2 | uVar41;
          *(uint *)(iVar49 + param_3[4] + 0x10) =
               uVar23 >> 3 & 0x800 |
               (uVar23 & 0x7f) << 4 |
               bVar13 & 0xf |
               (uint)bVar12 << 0x1f |
               (bVar11 & 3) << 0x1d |
               (bVar10 & 7) << 0x1a |
               (bVar9 & 3) << 0x18 |
               (bVar8 & 3) << 0x11 | uVar35 << 0x15 | uVar34 << 0x13 | uVar33 << 0xe | uVar32 << 0xc
          ;
          *(uint *)(iVar49 + param_3[4] + 0x14) =
               (uint)bVar16 << 0x1e |
               (bVar15 & 3) << 0x17 |
               (local_78 & 7) << 0x1b |
               (local_70 & 3) << 0x19 |
               uVar38 << 0x14 |
               uVar37 << 0x11 |
               uVar36 << 0xe |
               uVar42 << 0xc | uVar22 >> 3 & 0x800 | (uVar22 & 0x7f) << 4 | bVar14 & 0xf;
          if (*puVar60 == 3) {
            bVar58 = bVar58 | *(byte *)((int)puVar60 + 0x23);
          }
        }
      }
      else if (uVar43 == 5) {
        bVar1 = *(byte *)((int)puVar60 + 0xe);
        bVar2 = *(byte *)((int)puVar60 + 0xf);
        bVar25 = false;
        bVar3 = *(byte *)(puVar60 + 4);
        bVar4 = *(byte *)((int)puVar60 + 0x11);
        bVar5 = *(byte *)((int)puVar60 + 0x12);
        bVar6 = *(byte *)((int)puVar60 + 0x13);
        bVar7 = *(byte *)(puVar60 + 1);
        bVar8 = *(byte *)((int)puVar60 + 5);
        bVar9 = *(byte *)((int)puVar60 + 6);
        bVar10 = *(byte *)((int)puVar60 + 0xb);
        bVar11 = *(byte *)((int)puVar60 + 0x17);
        uVar24 = *(ushort *)(puVar60 + 3);
        bVar12 = *(byte *)((int)puVar60 + 0x19);
        bVar13 = *(byte *)((int)puVar60 + 0x16);
        bVar14 = *(byte *)(puVar60 + 5);
        bVar15 = *(byte *)(puVar60 + 6);
        bVar16 = *(byte *)((int)puVar60 + 0x15);
        *(undefined4 *)(param_3[4] + iVar49 + 4) = 0;
        uVar48 = (bVar10 & 1) << 10 | (bVar9 & 1) << 6 | (bVar8 & 7) << 3 | (bVar7 & 1) << 2 | 2;
        *(uint *)(param_3[4] + iVar49 + 8) =
             (bVar13 & 1) << 0x1c |
             (bVar16 & 3) << 0x1a |
             (bVar14 & 3) << 0x18 |
             (bVar6 & 0x1f) << 0x10 |
             (uint)bVar5 << 8 | (bVar4 & 3) << 6 | (bVar3 & 1) << 5 | (bVar2 & 1) << 4 | bVar1 & 7;
        *(uint *)(param_3[4] + iVar49 + 0xc) =
             (uint)bVar12 << 0x1f | (uVar24 & 0x1ff) << 0x10 | (bVar15 & 0x1f) << 8 | bVar11 & 0x1f;
        *(undefined4 *)(param_3[4] + iVar49 + 0x10) = 0;
        *(undefined4 *)(param_3[4] + iVar49 + 0x14) = 0;
      }
      uVar59 = uVar59 + 1;
      iVar56 = iVar57 + 1;
      puVar60 = puVar60 + 0x12;
      *(uint *)(param_3[4] + iVar49) = uVar48;
      iVar49 = iVar49 + 0x18;
    } while (uVar59 <= uVar55);
    iVar49 = iVar56;
    if (!bVar25) goto LAB_000c07dc;
    iVar53 = iVar56 * 0x18;
    iVar49 = iVar57 + 2;
  }
  *(undefined4 *)(param_3[4] + iVar53) = 0;
  *(undefined4 *)(iVar53 + param_3[4] + 4) = 0;
  *(undefined4 *)(iVar53 + param_3[4] + 8) = 0;
  *(undefined4 *)(iVar53 + param_3[4] + 0xc) = 0;
  *(undefined4 *)(iVar53 + param_3[4] + 0x10) = 0;
  *(undefined4 *)(iVar53 + param_3[4] + 0x14) = 0;
  *(uint *)(iVar53 + param_3[4]) = *(uint *)(iVar53 + param_3[4]) & 0xfffffffc | 1;
  *(uint *)(iVar53 + param_3[4]) = *(uint *)(iVar53 + param_3[4]) | 4;
  if ((iVar56 != 0) && ((uint)*(ushort *)(param_1 + 0x12) == iVar56 - 1U)) {
    *(short *)(param_1 + 0x12) = (short)iVar56;
  }
LAB_000c07dc:
  param_3[2] = 0;
  param_3[3] = (iVar49 + -1) * 0x10000 & 0x1ff0000;
  uVar55 = *(ushort *)(param_1 + 0x10) & 0x1ff;
  param_3[2] = uVar55;
  uVar24 = *(ushort *)(param_1 + 0x12);
  param_3[1] = 0;
  param_3[2] = (uVar24 & 0x1ff) << 0x10 | uVar55;
  uVar24 = *(ushort *)(param_1 + 0x28);
  *param_3 = 0;
  param_3[1] = (uint)uVar24 << 0x1f;
  uVar24 = *(ushort *)(param_1 + 0x22);
  param_3[5] = (uint)(bVar58 != 0);
  *param_3 = uVar24 & 0x7f;
  return 0;
}

/* FUN_000c3d60 @ 0xc3d60 (232 bytes) */
int FUN_000c3d60(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  if ((int)(param_4 - 0x20) < 0) {
    param_2 = (param_2 << 1) << (0x1f - param_4 & 0x3f) | param_3 >> (param_4 & 0x3f);
  }
  else {
    param_2 = param_2 >> (param_4 - 0x20 & 0x3f);
  }
  if ((param_2 & 1) != 0) {
    if (((param_5 & 1) == 0) || (*(float *)(param_1 + param_4 * 0x10) == FLOAT_001aa108)) {
      if (((param_5 & 2) == 0) || (*(float *)(param_4 * 0x10 + param_1 + 4) == FLOAT_001aa108)) {
        if (((param_5 & 4) == 0) || (*(float *)(param_4 * 0x10 + param_1 + 8) == FLOAT_001aa108)) {
          if (((param_5 & 8) == 0) || (*(float *)(param_4 * 0x10 + param_1 + 0xc) == FLOAT_001aa108)
             ) {
            if ((param_5 & 0xfffffff0) == 0) {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_000c5e60 @ 0xc5e60 (1524 bytes) */
int FUN_000c5e60(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  ushort *puVar10;
  ushort uVar11;
  uint uVar12;
  ushort *puVar13;
  byte *pbVar14;
  ushort *puVar15;
  char *pcVar16;
  ushort *puVar17;
  ushort *puVar18;
  ushort *puVar19;
  ushort *puVar20;
  ushort *puVar21;
  ushort *puVar22;
  char *pcVar23;
  ushort *puVar24;
  ushort *puVar25;
  ushort *puVar26;
  char *pcVar27;
  char *pcVar28;
  uint uVar29;
  int iVar30;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  uint local_5c;
  uint local_58;
  
  local_7c = (uint)*(ushort *)(param_1 + 5);
  if (local_7c != 0) {
    return;
  }
  local_58 = param_1[2];
  local_98 = local_7c;
  local_94 = local_7c;
  local_90 = local_7c;
  local_8c = local_7c;
  local_88 = local_7c;
  local_84 = local_7c;
  local_80 = local_7c;
  if (local_58 == 0) {
    local_5c = local_58;
    local_74 = local_58;
    local_6c = local_58;
    local_78 = local_58;
    local_70 = 1;
    local_60 = 0;
    local_68 = local_58;
    local_64 = local_58;
    uVar11 = 0;
  }
  else {
    puVar21 = (ushort *)((int)param_1 + 0x62);
    uVar29 = 0;
    local_64 = 0;
    local_70 = 1;
    local_68 = 0;
    local_78 = 0;
    local_6c = 0;
    local_5c = 0;
    local_74 = 0;
    local_60 = 0;
    pcVar23 = (char *)(param_1 + 0x1a);
    puVar24 = (ushort *)((int)param_1 + 0x5a);
    puVar4 = (ushort *)(param_1 + 0x16);
    puVar5 = (ushort *)((int)param_1 + 0x56);
    puVar15 = (ushort *)(param_1 + 0x15);
    pcVar16 = (char *)(param_1 + 0x1f);
    puVar17 = (ushort *)((int)param_1 + 0x66);
    puVar18 = (ushort *)(param_1 + 0x19);
    puVar13 = (ushort *)(param_1 + 0x18);
    pcVar27 = (char *)(param_1 + 0x17);
    pbVar14 = (byte *)((int)param_1 + 0x61);
    puVar10 = (ushort *)(param_1 + 0x13);
    pcVar7 = (char *)((int)param_1 + 0x51);
    puVar6 = (ushort *)((int)param_1 + 0x4e);
    pcVar9 = (char *)((int)param_1 + 0x53);
    uVar12 = 1;
    uVar11 = 0;
    puVar19 = puVar5;
    puVar20 = puVar4;
    puVar22 = puVar21;
    puVar25 = puVar24;
    puVar26 = puVar15;
    pcVar28 = pcVar23;
    puVar3 = param_1;
    do {
      puVar3 = puVar3 + 0x12;
      switch(*puVar3) {
      case 1:
        if ((*pcVar9 != '\0') && (uVar11 < *puVar6)) {
          uVar11 = *puVar6;
        }
        if ((*pcVar7 != '\0') && (uVar11 < *puVar10)) {
          uVar11 = *puVar10;
        }
        uVar29 = uVar29 + 1 & 0xffff;
        break;
      case 2:
        if (local_70 == 0) {
          if (*pcVar28 != '\0') {
            local_5c = local_5c + 1 & 0xffff;
            local_78 = local_78 + 1 & 0xffff;
          }
        }
        else {
          local_5c = local_5c + 1 & 0xffff;
        }
        if (*(byte *)puVar21 < 8) {
          uVar1 = 1 << ((int)(char)*(byte *)puVar21 & 0x3fU);
          if ((uVar1 & 0xba) == 0) {
            if ((uVar1 & 4) == 0) {
              if ((uVar1 & 0x40) != 0) {
                uVar2 = *puVar20;
                if (*puVar20 <= uVar11) {
                  uVar2 = uVar11;
                }
                uVar11 = *puVar24;
                if (*puVar24 <= uVar2) {
                  uVar11 = uVar2;
                }
                goto LAB_000c60a8;
              }
            }
            else if (uVar11 < *puVar19) {
              uVar11 = *puVar19;
            }
          }
          else {
LAB_000c60a8:
            if (uVar11 < *puVar19) {
              uVar11 = *puVar19;
            }
            if (uVar11 < *puVar15) {
              uVar11 = *puVar15;
            }
            if (*pbVar14 < 0x10) {
              iVar8 = (uint)*pbVar14 * 2;
              *(short *)((int)&local_98 + iVar8) = *(short *)((int)&local_98 + iVar8) + 1;
            }
          }
        }
        local_70 = 0;
        local_64 = local_64 + 1 & 0xffff;
        break;
      case 3:
      case 4:
        if (local_5c == 0) {
          local_5c = 1;
        }
        if ((*pcVar27 != '\0') && (uVar11 < *puVar26)) {
          uVar11 = *puVar26;
        }
        uVar2 = *puVar5;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        uVar2 = *puVar4;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        uVar2 = *puVar25;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        if ((*pcVar23 != '\0') && (uVar11 < *puVar13)) {
          uVar11 = *puVar13;
        }
        uVar2 = *puVar22;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        uVar2 = *puVar18;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        uVar2 = *puVar17;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        if (*pcVar16 != '\0') {
          local_74 = local_74 + 1 & 0xffff;
        }
        local_70 = 1;
        local_68 = local_68 + 1 & 0xffff;
        break;
      case 5:
        local_6c = local_6c + 1 & 0xffff;
      }
      uVar12 = uVar12 + 1;
      pcVar16 = pcVar16 + 0x48;
      puVar17 = puVar17 + 0x24;
      puVar18 = puVar18 + 0x24;
      puVar22 = puVar22 + 0x24;
      puVar13 = puVar13 + 0x24;
      pcVar23 = pcVar23 + 0x48;
      puVar25 = puVar25 + 0x24;
      puVar4 = puVar4 + 0x24;
      puVar5 = puVar5 + 0x24;
      puVar26 = puVar26 + 0x24;
      pcVar27 = pcVar27 + 0x48;
      pbVar14 = pbVar14 + 0x48;
      puVar15 = puVar15 + 0x24;
      puVar19 = puVar19 + 0x24;
      puVar24 = puVar24 + 0x24;
      puVar20 = puVar20 + 0x24;
      puVar21 = puVar21 + 0x24;
      pcVar28 = pcVar28 + 0x48;
      puVar10 = puVar10 + 0x24;
      pcVar7 = pcVar7 + 0x48;
      puVar6 = puVar6 + 0x24;
      pcVar9 = pcVar9 + 0x48;
    } while (uVar12 <= local_58);
    if (uVar29 != 0) goto LAB_000c6350;
  }
  uVar29 = 1;
LAB_000c6350:
  if (local_5c == 0) {
    local_5c = 1;
    local_68 = 1;
  }
  if (local_70 == 0) {
    local_68 = local_68 + 1 & 0xffff;
  }
  uVar12 = (local_68 + local_78 & 0xffff) + local_74 & 0xffff;
  if (uVar12 < local_64) {
    uVar12 = local_64;
  }
  if (uVar12 < local_6c) {
    uVar12 = local_6c;
  }
  if (uVar12 < uVar29) {
    uVar12 = uVar29;
  }
  *(ushort *)((int)param_1 + 0x22) = uVar11;
  *(short *)((int)param_1 + 0x26) = (short)uVar12;
  *(short *)((int)param_1 + 0x1e) = (short)(local_68 + local_78);
  *(short *)(param_1 + 6) = (short)uVar29;
  *(short *)((int)param_1 + 0x16) = (short)local_5c;
  *(undefined2 *)(param_1 + 10) = 0;
  *(short *)(param_1 + 8) = (short)local_6c;
  iVar8 = 0;
  iVar30 = 0x10;
  *(short *)(param_1 + 7) = (short)local_68;
  *(short *)((int)param_1 + 0x1a) = (short)local_64;
  *(undefined2 *)(param_1 + 9) = (*(unsigned short *)((unsigned char *)&(local_60) + 2));
  puVar3 = param_1;
  do {
    uVar11 = *(ushort *)((int)&local_98 + iVar8);
    if (0xff < uVar11) {
      uVar11 = 0xff;
      *(undefined2 *)((int)&local_98 + iVar8) = 0xff;
    }
    *(char *)((int)puVar3 + 0x2a) = (char)uVar11;
    iVar8 = iVar8 + 2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    iVar30 = iVar30 + -1;
  } while (iVar30 != 0);
  *(undefined2 *)(param_1 + 5) = 1;
  return;
}

/* FUN_000c6e90 @ 0xc6e90 (88 bytes) */
int FUN_000c6e90(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  char *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  size_t sVar1;
  char acStack_118 [264];
  
  _strcpy(acStack_118,param_2);
  sVar1 = _strlen(acStack_118);
  FUN_001a3428(acStack_118 + sVar1,0x100 - sVar1,param_3,param_4);
  return;
}

/* FUN_000c6ff0 @ 0xc6ff0 (464 bytes) */
int FUN_000c6ff0(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_54;
  undefined4 *local_50;
  undefined1 *local_4c;
  undefined1 *local_48;
  undefined1 *local_44;
  code *local_40;
  undefined1 *local_3c;
  undefined1 *local_38;
  undefined1 *local_34;
  undefined1 *local_30;
  
  _memset(&local_7c,0,0x54);
  local_78 = *(undefined4 *)(param_1 + 0x23d8);
  local_80 = 0;
  local_88 = 0;
  if (param_2 == 0) {
    local_7c = 0x2c;
  }
  else {
    puVar1 = *(undefined **)(param_1 + 0x23d4);
    if (((puVar1 + -0x7240 < &MACH_HEADER.ncmds) || (puVar1 + -0x7100 < &MACH_HEADER.ncmds)) ||
       (((((puVar1 != (undefined *)0x71c0 &&
           ((((puVar1 != (undefined *)0x71c2 && (puVar1 != (undefined *)0x71c6)) &&
             (puVar1 != (undefined *)0x71ce)) &&
            ((puVar1 != (undefined *)0x71d2 && (puVar1 != (undefined *)0x71de)))))) &&
          (puVar1 != (undefined *)0x71c4)) &&
         (((puVar1 != (undefined *)0x71c5 && (puVar1 != (undefined *)0x7140)) &&
          ((puVar1 != (undefined *)0x7142 &&
           (((puVar1 != ((unsigned char *)0x00007146) && (puVar1 != ((unsigned char *)0x0000714e))) &&
            (puVar1 != (undefined *)0x7152)))))))) &&
        (((puVar1 != (undefined *)0x715e && (puVar1 != ((unsigned char *)0x00007144))) &&
         ((puVar1 != ((unsigned char *)0x00007145) && ((puVar1 != ((unsigned char *)0x00007148) && (puVar1 != ((unsigned char *)0x00007149))))))))))
       ) {
      local_7c = 0x3c;
    }
    else {
      local_7c = 0x3e;
    }
  }
  local_4c = ((unsigned char *)0x000c6e40);
  local_48 = ((unsigned char *)0x000c6e50);
  local_54 = 2;
  local_44 = ((unsigned char *)0x000c6e80);
  local_40 = FUN_000c6e90;
  local_84 = 0x7b;
  local_3c = ((unsigned char *)0x000c6ef0);
  local_38 = ((unsigned char *)0x000c6f60);
  local_34 = ((unsigned char *)0x000c6f90);
  local_30 = ((unsigned char *)0x000c6fc0);
  local_50 = (undefined4 *)(param_1 + 0x186c);
  uVar2 = ((int (*)())FUN_000cd05c)(&local_7c,&local_88,0x10001);
  *(undefined4 *)(param_1 + 0x186c) = uVar2;
  *(undefined4 *)(param_1 + 0x1870) = local_84;
  return;
}

/* FUN_000c71e0 @ 0xc71e0 (76 bytes) */
int FUN_000c71e0(param_1)
  void *param_1;
{
  if (param_1 != (void *)0x0) {
    ((int (*)())FUN_000c71e0)(*(undefined4 *)((int)param_1 + 0x24));
    _free(param_1);
    return;
  }
  return;
}

/* FUN_000c7240 @ 0xc7240 (44 bytes) */
int FUN_000c7240(param_1)
  int param_1;
{
  undefined1 uVar1;
  
  uVar1 = 2;
  if ((param_1 != 2) && (uVar1 = 3, param_1 != 3)) {
    uVar1 = param_1 == 1;
  }
  return uVar1;
}

/* FUN_000c7270 @ 0xc7270 (24 bytes) */
int FUN_000c7270(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  param_1 = param_2 * 4 + param_1;
  *(undefined4 *)(((unsigned char *)0x00002278) + param_1) = 1;
  *(undefined4 *)(param_1 + 0x2238) = param_3;
  return;
}

/* FUN_000c7290 @ 0xc7290 (88 bytes) */
int FUN_000c7290(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = ((int)param_2 >> 5) + (uint)((int)param_2 < 0 && (param_2 & 0x1f) != 0);
  iVar3 = param_2 * 0x10 + param_1;
  param_1 = iVar2 * 4 + param_1;
  *(undefined4 *)(iVar3 + 0x1a8) = *param_3;
  uVar4 = *(uint *)(param_1 + 0x188);
  *(undefined4 *)(iVar3 + 0x1ac) = param_3[1];
  *(undefined4 *)(iVar3 + 0x1b0) = param_3[2];
  uVar1 = param_3[3];
  *(uint *)(param_1 + 0x188) = 1 << (param_2 + iVar2 * -0x20 & 0x3f) | uVar4;
  *(undefined4 *)(iVar3 + 0x1b4) = uVar1;
  return;
}

/* FUN_000c72f0 @ 0xc72f0 (88 bytes) */
int FUN_000c72f0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = ((int)param_2 >> 5) + (uint)((int)param_2 < 0 && (param_2 & 0x1f) != 0);
  iVar4 = param_2 * 0x10 + param_1;
  *(undefined4 *)(((unsigned char *)0x000011c8) + iVar4) = *param_3;
  param_1 = iVar1 * 4 + param_1;
  uVar3 = *(uint *)(((unsigned char *)0x000011a8) + param_1);
  *(undefined4 *)((int)((unsigned char *)0x000011cc) + iVar4) = param_3[1];
  *(undefined4 *)((*(unsigned char *)0x000011d0) + iVar4) = param_3[2];
  uVar2 = param_3[3];
  *(uint *)(((unsigned char *)0x000011a8) + param_1) = 1 << (param_2 + iVar1 * -0x20 & 0x3f) | uVar3;
  *(undefined4 *)(((unsigned char *)0x000011d4) + iVar4) = uVar2;
  return;
}

/* FUN_000c7350 @ 0xc7350 (72 bytes) */
int FUN_000c7350(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 8;
  do {
    uVar1 = 1 << (uVar2 & 0x3f);
    if ((uVar1 & *(uint *)(param_1 + 8)) == 0) {
      *(uint *)(param_1 + 8) = uVar1 | *(uint *)(param_1 + 8);
      return uVar2;
    }
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0x11;
}

/* FUN_000c73a0 @ 0xc73a0 (20 bytes) */
int FUN_000c73a0(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
  return;
}

/* FUN_000c73c0 @ 0xc73c0 (144 bytes) */
int FUN_000c73c0(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = 0;
  iVar6 = 8;
  iVar1 = param_1;
  do {
    uVar4 = *(uint *)(iVar1 + 0xc);
    if (uVar4 != 0) {
      uVar2 = 0;
      if ((uVar4 & 1) == 0) {
        do {
          uVar2 = uVar2 + 1;
          uVar5 = 1 << (uVar2 & 0x3f);
        } while ((uVar4 & uVar5) == 0);
        uVar5 = ~uVar5;
      }
      else {
        uVar5 = 0xfffffffe;
      }
      param_1 = iVar3 * 4 + param_1;
      *(uint *)(param_1 + 0xc) = uVar5 & *(uint *)(param_1 + 0xc);
      return uVar2 + iVar3 * 0x20;
    }
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return -1;
}

/* FUN_000c7460 @ 0xc7460 (468 bytes) */
int FUN_000c7460(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  uint *param_3;
  uint param_4;
  undefined4 *param_5;
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  
  if ((1 << (param_4 & 0x3f) & *(uint *)(param_1 + 0x70)) == 0) {
    return param_5;
  }
  *param_5 = 0x51;
  uVar2 = *(uint *)(param_1 + 0x184);
  param_5[2] = 0x40;
  param_5[1] = uVar2 & 0xffff | 0x440000;
  param_5[3] = (*(ushort *)param_2 & 0x3f) << 0x10 | (uint)(ushort)*param_2 | 0x400000;
  if ((*param_2 & 0x400000) == 0) {
    puVar4 = ((unsigned char *)0x00005555);
    goto LAB_000c7584;
  }
  uVar3 = 1;
  uVar2 = *param_3 >> 0x15 & 7;
  if (uVar2 != 1) {
    if (uVar2 < 2) {
      uVar3 = 5;
      if (uVar2 != 0) {
LAB_000c7520:
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 2;
      if (uVar2 != 2) {
        if (uVar2 != 3) goto LAB_000c7520;
        uVar3 = 3;
      }
    }
  }
  puVar4 = (undefined *)(uVar3 << 0xc | uVar3 << 8 | uVar3 << 4 | uVar3);
LAB_000c7584:
  param_5[4] = puVar4;
  param_5[5] = 0x49;
  uVar2 = *(uint *)(param_1 + 0x184);
  param_5[7] = 0x110;
  param_5[6] = uVar2 & 0xffff | 0x440000;
  uVar2 = *(uint *)(param_1 + 0x184);
  param_5[9] = ((unsigned char *)0x00003333);
  param_5[8] = uVar2 & 0xffff | 0x440000;
  uVar1 = *(ushort *)param_2;
  uVar2 = *param_2;
  param_5[0xb] = ((unsigned char *)0x00002222);
  param_5[10] = (uint)(ushort)uVar2 | (uVar1 & 0x3f) << 0x10 | 0x400000;
  return param_5 + 0xc;
}

/* FUN_000c7650 @ 0xc7650 (680 bytes) */
int FUN_000c7650(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  uint *param_3;
  uint *param_4;
  uint param_5;
  int param_6;
  uint *param_7;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  uint *puVar5;
  uint uVar6;
  
  if ((1 << (param_5 & 0x3f) & *(uint *)(param_1 + 0x70)) != 0) {
    *param_7 = 0x5b;
    iVar2 = param_5 * 4;
    uVar6 = *(uint *)(param_1 + 0x180);
    param_7[2] = 0x10;
    param_7[1] = uVar6 & 0xffff | 0x440000;
    puVar4 = (undefined *)0xd;
    uVar6 = *(uint *)(param_1 + 0x184);
    param_7[4] = (uint)((unsigned char *)0x00002222);
    param_7[3] = uVar6 & 0xffff | 0x440000;
    uVar1 = *(ushort *)param_3;
    uVar6 = *param_3;
    param_7[6] = (uint)((unsigned char *)0x00002222);
    param_7[5] = (uint)(ushort)uVar6 | (uVar1 & 0x3f) << 0x10 | 0x400000;
    switch(*(undefined4 *)(iVar2 + param_1 + 0x138)) {
    case 0x200:
    case 0x202:
    case 0x207:
      puVar4 = (undefined *)0x1000d;
      break;
    case 0x201:
      puVar4 = (undefined *)0x5000d;
      break;
    case 0x203:
      puVar4 = ((unsigned char *)0x0004000d);
      break;
    case 0x204:
      puVar4 = (undefined *)0x3000d;
      break;
    case 0x205:
      puVar4 = (undefined *)0xd;
      break;
    case 0x206:
      puVar4 = (undefined *)0x2000d;
    }
    param_7[7] = (uint)puVar4;
    if (param_6 == 0) {
      uVar6 = *param_3;
    }
    else {
      uVar6 = *param_3 | 0x400000;
      *param_3 = uVar6;
    }
    param_7[8] = uVar6;
    puVar5 = param_7 + 9;
    if (param_6 != 0) {
      puVar5 = param_7 + 10;
      param_7[9] = *param_4;
    }
    *puVar5 = *(uint *)(param_1 + 0x180) & 0xffff | 0x440000;
    iVar3 = *(int *)(iVar2 + param_1 + 0x138);
    if ((iVar3 == 0x200) || (iVar3 != 0x207)) {
      puVar4 = ((unsigned char *)0x00002222);
    }
    else {
      puVar4 = ((unsigned char *)0x00004444);
    }
    puVar5[1] = (uint)puVar4;
    param_7 = puVar5 + 6;
    uVar6 = *param_3;
    puVar5[3] = (uint)((unsigned char *)0x00005555);
    puVar5[2] = (ushort)uVar6 | 0x440000;
    uVar6 = *(uint *)(iVar2 + param_1 + 0xb8);
    puVar5[5] = (uint)((unsigned char *)0x00002222);
    puVar5[4] = uVar6 & 0xffff | 0x410000;
  }
  return param_7;
}

/* FUN_000c7930 @ 0xc7930 (2004 bytes) */
int FUN_000c7930(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint in_r9;
  int iVar5;
  
  if (*(int *)(((unsigned char *)0x000022fc) + param_2) != 0) {
    iVar5 = 4;
    iVar2 = param_2;
    do {
      if (*(int *)(((unsigned char *)0x000021f0) + iVar2) != 0) {
        *param_1 = 0x47;
        uVar1 = *(uint *)(((unsigned char *)0x000021e0) + iVar2);
        param_1[2] = 0x115;
        param_1[1] = uVar1 & 0xffff | 0x440000;
        in_r9 = *(uint *)(((unsigned char *)0x000021e0) + iVar2) & 0xffff | 0x40000;
        param_1[3] = in_r9;
        param_1 = param_1 + 4;
      }
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar2 = *(int *)(((unsigned char *)0x000022fc) + param_2);
    if (iVar2 == 2) {
      *param_1 = 0x49;
      uVar1 = *(uint *)(((unsigned char *)0x00002300) + param_2);
      param_1[2] = 1;
      param_1[1] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(((unsigned char *)0x00002304) + param_2);
      param_1[4] = ((unsigned char *)0x00002222);
      param_1[3] = uVar1 & 0xffff | in_r9 & 0xffc00000 | 0x10000 | 0x400000;
      uVar4 = 0;
      param_1[5] = *(uint *)(param_2 + 0x68) & 0xffff | 0x510000;
      if (*(int *)(((unsigned char *)0x0000230c) + param_2) == 0) {
        uVar4 = 0x100000;
      }
      param_1[6] = uVar4;
      param_1[7] = 0x2d;
      uVar1 = *(uint *)(((unsigned char *)0x00002300) + param_2);
      param_1[9] = 0x101;
      param_1[8] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(((unsigned char *)0x00002300) + param_2);
      param_1[0xb] = 0x8888;
      param_1[10] = uVar1 & 0xffff | 0x440000;
      param_1 = param_1 + 0xc;
    }
    else if (iVar2 == 3) {
      *param_1 = 0x49;
      uVar1 = *(uint *)(((unsigned char *)0x00002300) + param_2);
      param_1[2] = 1;
      param_1[1] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(((unsigned char *)0x00002304) + param_2);
      param_1[4] = ((unsigned char *)0x00003333);
      param_1[3] = uVar1 & 0xffff | in_r9 & 0xffc00000 | 0x10000 | 0x400000;
      uVar4 = 0;
      param_1[5] = *(uint *)(param_2 + 0x68) & 0xffff | 0x510000;
      if (*(int *)(((unsigned char *)0x0000230c) + param_2) == 0) {
        uVar4 = 0x100000;
      }
      param_1[6] = uVar4;
      param_1[7] = 0x49;
      param_1[8] = *(uint *)(((unsigned char *)0x00002300) + param_2) & 0xffff | 0x40000;
      uVar1 = *(uint *)(((unsigned char *)0x00002300) + param_2);
      param_1[0xb] = 0x2d;
      uVar1 = uVar1 & 0xffff | 0x40000;
      param_1[10] = uVar1;
      param_1[9] = uVar1;
      uVar1 = *(uint *)(((unsigned char *)0x00002300) + param_2);
      param_1[0xd] = 0x101;
      param_1[0xc] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(((unsigned char *)0x00002300) + param_2);
      param_1[0xf] = 0x8888;
      param_1[0xe] = uVar1 & 0xffff | 0x440000;
      param_1 = param_1 + 0x10;
    }
    else if (iVar2 == 1) {
      *param_1 = 0x40;
      uVar1 = *(uint *)(((unsigned char *)0x00002300) + param_2);
      param_1[2] = 0x101;
      uVar4 = 0;
      param_1[1] = uVar1 & 0xffff | 0x440000;
      param_1[3] = *(uint *)(param_2 + 0x68) & 0xffff | 0x510000;
      if (*(int *)(((unsigned char *)0x0000230c) + param_2) == 0) {
        uVar4 = 0x100000;
      }
      param_1[4] = uVar4;
      uVar1 = *(uint *)(((unsigned char *)0x00002304) + param_2);
      param_1[6] = 0;
      param_1[5] = uVar1 & 0xffff | 0x410000;
      uVar1 = *(uint *)(((unsigned char *)0x00002304) + param_2);
      param_1[8] = ((unsigned char *)0x00001111);
      param_1[7] = uVar1 & 0xffff | 0x410000;
      param_1 = param_1 + 9;
    }
    iVar5 = 4;
    iVar2 = param_2;
    do {
      if (*(int *)(((unsigned char *)0x000021f0) + iVar2) != 0) {
        *param_1 = 0x3f;
        uVar1 = *(uint *)(((unsigned char *)0x000021e0) + param_2);
        param_1[2] = 0x15;
        param_1[1] = uVar1 & 0xffff | 0x440000;
        uVar1 = *(uint *)(((unsigned char *)0x00002300) + param_2);
        param_1[4] = 0;
        param_1[3] = uVar1 & 0xffff | 0x440000;
        param_1[5] = *(uint *)(((unsigned char *)0x000021e0) + param_2) & 0xffff | 0x40000;
        param_1[6] = *(uint *)(((unsigned char *)0x00002308) + param_2) & 0xffff | 0x10000;
        param_1 = param_1 + 7;
      }
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (*(int *)(((unsigned char *)0x000021d0) + param_2) != 0) {
    iVar5 = 4;
    iVar2 = param_2;
    do {
      if (*(int *)(((unsigned char *)0x000021f0) + iVar2) != 0) {
        *param_1 = 0x49;
        uVar1 = *(uint *)(((unsigned char *)0x000021e0) + iVar2);
        param_1[2] = 0x40;
        param_1[1] = uVar1 & 0xffff | 0x440000;
        param_1[3] = *(uint *)(((unsigned char *)0x000021e0) + iVar2) & 0xffff | 0x40000;
        uVar1 = *(uint *)(((unsigned char *)0x000021dc) + param_2);
        param_1[5] = 0;
        param_1[4] = uVar1 & 0xffff | 0x440000;
        param_1 = param_1 + 6;
      }
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  uVar1 = 0;
  iVar5 = 4;
  iVar2 = param_2;
  do {
    if (*(int *)(((unsigned char *)0x000021f0) + iVar2) != 0) {
      *param_1 = 0x47;
      param_1[1] = uVar1 & 0xffff | 0x170000;
      param_1[2] = *(uint *)(((unsigned char *)0x000021e0) + iVar2) & 0xffff | 0x40000;
      param_1 = param_1 + 3;
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (((*(int *)(((unsigned char *)0x0000220c) + param_2) != 0) && (*(int *)(((unsigned char *)0x00002204) + param_2) != 0)) &&
     (*(int *)(param_2 + 0x2234) == 0)) {
    if (*(int *)(((unsigned char *)0x00002210) + param_2) == 0xffff) {
      *param_1 = 0x47;
      param_1[1] = 0x530000;
      param_1[2] = 0x40;
    }
    else {
      *param_1 = 0x47;
      uVar1 = *(uint *)(((unsigned char *)0x00002210) + param_2);
      param_1[2] = 1;
      param_1[1] = uVar1 & 0xffff | 0x510000;
    }
    uVar1 = *(uint *)(((unsigned char *)0x00002208) + param_2);
    param_1[4] = 0;
    param_1[3] = uVar1 & 0xffff | 0x440000;
    param_1 = param_1 + 5;
  }
  if (((*(int *)(((unsigned char *)0x00002218) + param_2) != 0) || (*(int *)(((unsigned char *)0x00002220) + param_2) != 0)) ||
     (puVar3 = param_1, *(int *)(param_2 + 0x2234) == 0)) {
    if ((*(int *)(((unsigned char *)0x00002214) + param_2) == 0) && (*(int *)(((unsigned char *)0x0000221c) + param_2) != 0)) {
      *param_1 = 0x47;
      param_1[2] = 0x10000;
      param_1[1] = 0x120000;
      param_1 = param_1 + 3;
    }
    puVar3 = param_1;
    if (*(int *)(param_2 + 0x2234) == 0) {
      *param_1 = 0x47;
      param_1[1] = 0xe0000;
      param_1[2] = *(uint *)(((unsigned char *)0x00002200) + param_2) & 0xffff | 0x40000;
      puVar3 = param_1 + 3;
      if (*(int *)(((unsigned char *)0x00002310) + param_2) != 0) {
        param_1[3] = 0x47;
        param_1[4] = *(uint *)(((unsigned char *)0x00002314) + param_2) & 0xffff | 0x110000;
        param_1[5] = *(uint *)(((unsigned char *)0x00002200) + param_2) & 0xffff | 0x40000;
        puVar3 = param_1 + 6;
      }
    }
  }
  return puVar3;
}

/* FUN_000c8110 @ 0xc8110 (1252 bytes) */
int FUN_000c8110(param_1, param_2)
  uint *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  
  uVar4 = ((int (*)())FUN_000c73a0)(param_2);
  *(undefined4 *)(((unsigned char *)0x000021e0) + param_2) = uVar4;
  uVar4 = ((int (*)())FUN_000c73a0)(param_2);
  *(undefined4 *)(((unsigned char *)0x000021e4) + param_2) = uVar4;
  uVar4 = ((int (*)())FUN_000c73a0)(param_2);
  *(undefined4 *)(((unsigned char *)0x000021e8) + param_2) = uVar4;
  uVar4 = ((int (*)())FUN_000c73a0)(param_2);
  *(undefined4 *)(((unsigned char *)0x000021ec) + param_2) = uVar4;
  if (*(int *)(((unsigned char *)0x00002324) + param_2) != 0) {
    uVar4 = ((int (*)())FUN_000c73a0)(param_2);
    *(undefined4 *)(((unsigned char *)0x00002328) + param_2) = uVar4;
  }
  uVar4 = ((int (*)())FUN_000c73a0)(param_2);
  *(undefined4 *)(((unsigned char *)0x00002200) + param_2) = uVar4;
  uVar4 = ((int (*)())FUN_000c73a0)(param_2);
  iVar2 = *(int *)(param_2 + 100);
  *(undefined4 *)(((unsigned char *)0x00002208) + param_2) = uVar4;
  if (iVar2 != 0) {
    uVar4 = ((int (*)())FUN_000c7350)(param_2);
    *(undefined4 *)(param_2 + 0x68) = uVar4;
  }
  if (*(int *)(((unsigned char *)0x000022fc) + param_2) != 0) {
    uVar4 = ((int (*)())FUN_000c73a0)(param_2);
    *(undefined4 *)(((unsigned char *)0x00002300) + param_2) = uVar4;
    uVar4 = ((int (*)())FUN_000c73c0)(param_2);
    *(undefined4 *)(((unsigned char *)0x00002304) + param_2) = uVar4;
    uVar4 = ((int (*)())FUN_000c73c0)(param_2);
    *(undefined4 *)(((unsigned char *)0x00002308) + param_2) = uVar4;
    *param_1 = 0x1ff0016;
    param_1[1] = *(uint *)(param_2 + 0x68) & 0xffff | 0x110000;
    param_1 = param_1 + 2;
  }
  if (*(int *)(((unsigned char *)0x000021d0) + param_2) != 0) {
    uVar4 = ((int (*)())FUN_000c73a0)(param_2);
    *(undefined4 *)(((unsigned char *)0x000021dc) + param_2) = uVar4;
    *param_1 = 0x1ff0016;
    param_1[1] = *(uint *)(((unsigned char *)0x000021d4) + param_2) & 0xffff | 0x110000;
    param_1[2] = *(int *)(((unsigned char *)0x000021d4) + param_2) << 0x10 | 0xb000019;
    param_1 = param_1 + 3;
  }
  if (*(int *)(param_2 + 0x4c) != 0) {
    uVar4 = ((int (*)())FUN_000c73a0)(param_2);
    *(undefined4 *)(param_2 + 0x54) = uVar4;
    uVar4 = ((int (*)())FUN_000c73c0)(param_2);
    *(undefined4 *)(param_2 + 0x58) = uVar4;
    uVar4 = ((int (*)())FUN_000c73c0)(param_2);
    *(undefined4 *)(param_2 + 0x5c) = uVar4;
    uVar4 = ((int (*)())FUN_000c7350)(param_2);
    *(undefined4 *)(param_2 + 0x60) = uVar4;
    *param_1 = 0x1ff0016;
    uVar7 = *(uint *)(param_2 + 0x60);
    param_1[2] = 0x51;
    param_1[1] = uVar7 & 0xffff | 0x110000;
    uVar7 = *(uint *)(param_2 + 0x54);
    param_1[4] = 0x40;
    param_1[3] = uVar7 & 0xffff | 0x440000;
    uVar4 = *(undefined4 *)(param_2 + 0x60);
    param_1[6] = 0x49;
    local_58 = CONCAT22(0x11,(short)uVar4);
    param_1[5] = local_58;
    uVar7 = *(uint *)(param_2 + 0x54);
    param_1[8] = 0x15;
    param_1[7] = uVar7 & 0xffff | 0x440000;
    uVar4 = *(undefined4 *)(param_2 + 0x54);
    param_1[10] = (uint)((unsigned char *)0x00003333);
    local_58 = CONCAT22(4,(short)uVar4);
    param_1[9] = local_58 | 0x400000;
    uVar4 = *(undefined4 *)(param_2 + 0x60);
    param_1[0xc] = 0x40;
    local_54 = CONCAT22(0x11,(short)uVar4);
    param_1[0xb] = local_54;
    uVar7 = *(uint *)(param_2 + 0x54);
    param_1[0xe] = 0x15;
    param_1[0xd] = uVar7 & 0xffff | 0x440000;
    local_58 = CONCAT22(4,(short)*(undefined4 *)(param_2 + 0x54));
    param_1[0xf] = local_58;
    local_54 = CONCAT22(1,(short)*(undefined4 *)(param_2 + 0x58));
    param_1[0x10] = local_54;
    local_50 = CONCAT22(1,(short)*(undefined4 *)(param_2 + 0x5c));
    param_1[0x11] = local_50;
    param_1 = param_1 + 0x12;
  }
  if (*(int *)(param_2 + 0x2234) != 0) {
    uVar3 = *(uint *)(param_2 + 0x70);
    uVar7 = *(uint *)(param_2 + 0x74);
    uVar8 = 0;
    uVar9 = 0;
    iVar2 = param_2;
    do {
      uVar10 = 1 << (uVar9 & 0x3f);
      if (((uVar3 | uVar7) & uVar10) != 0) {
        uVar4 = ((int (*)())FUN_000c73c0)(param_2);
        *(undefined4 *)(iVar2 + 0xb8) = uVar4;
        if (uVar8 == 0) {
          uVar8 = 1;
        }
      }
      if ((uVar10 & *(uint *)(param_2 + 0x74)) != 0) {
        uVar4 = ((int (*)())FUN_000c73a0)(param_2);
        *(undefined4 *)(param_2 + 0x184) = uVar4;
        if (uVar8 < 2) {
          uVar8 = 2;
        }
      }
      bVar1 = uVar9 != 0xf;
      iVar2 = iVar2 + 4;
      uVar9 = uVar9 + 1;
    } while (bVar1);
    if (uVar8 != 0) {
      uVar7 = 0;
      iVar2 = param_2;
      do {
        uVar7 = uVar7 + 1;
        uVar4 = ((int (*)())FUN_000c73a0)(param_2);
        *(undefined4 *)(iVar2 + 0x17c) = uVar4;
        iVar2 = iVar2 + 4;
      } while (uVar7 != uVar8);
    }
  }
  if (*(int *)(((unsigned char *)0x000021d0) + param_2) != 0) {
    *param_1 = (*(uint *)(((unsigned char *)0x000021d4) + param_2) & 0x3fff) << 0x10 | 0x5d;
    param_1[1] = *(uint *)(((unsigned char *)0x000021dc) + param_2) & 0xffff | 0x40000;
    local_58 = CONCAT22(0x11,(short)*(undefined4 *)(((unsigned char *)0x000021d8) + param_2));
    param_1[2] = local_58;
    param_1 = param_1 + 3;
  }
  iVar6 = 0;
  iVar11 = 0x10;
  iVar2 = param_2;
  do {
    *(int *)(((unsigned char *)0x0000232c) + iVar2) = iVar6;
    iVar6 = iVar6 + 1;
    iVar2 = iVar2 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  uVar3 = *(uint *)(param_2 + 8);
  puVar5 = (uint *)(((unsigned char *)0x0000232c) + param_2);
  uVar7 = 0;
  iVar2 = 0x10;
  do {
    if ((1 << (uVar7 & 0x3f) & uVar3) == 0) {
      *puVar5 = uVar7;
      puVar5 = puVar5 + 1;
    }
    uVar7 = uVar7 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return param_1;
}

/* FUN_000c8600 @ 0xc8600 (316 bytes) */
int FUN_000c8600(param_1, param_2, param_3, param_4, param_5)
  uint param_1;
  int param_2;
  int *param_3;
  uint param_4;
  int param_5;
{
  int iVar1;
  
  if ((int)param_1 < *param_3) {
    iVar1 = param_3[1];
  }
  else {
    iVar1 = param_3[1];
    if (iVar1 < (int)param_1) goto LAB_000c8650;
    *param_3 = param_1 + 1;
  }
  if (((int)param_1 <= iVar1) && (*param_3 <= (int)param_1)) {
    param_3[1] = param_1 - 1;
  }
LAB_000c8650:
  if (param_2 == 0x17) {
    param_3[param_1 + 0x87c] = 1;
    if (((((param_4 & 3) != 1) && ((param_4 & 0xc) != 4)) && ((param_4 & 0x30) != 0x10)) &&
       (((param_4 & 0xc0) != 0x40 && (param_5 != 0)))) {
      return;
    }
    param_3[0x889] = 1;
    return;
  }
  if (param_2 == 0x18) {
    param_3[0x88a] = 1;
    param_3[0x889] = 1;
    return;
  }
  if (param_2 == 0x12) {
    param_3[param_1 + 0x885] = 1;
    return;
  }
  if (param_2 == 0x13) {
    param_3[param_1 + 0x887] = 1;
    return;
  }
  if (param_2 != 0x10) {
    if (param_2 != 0x11) {
      return;
    }
    if (param_3[0x8c7] < (int)param_1) {
      param_3[0x8c7] = param_1;
    }
    param_3[2] = 1 << (param_1 & 0x3f) | param_3[2];
    return;
  }
  param_3[0x883] = 1;
  return;
}

/* FUN_000c8760 @ 0xc8760 (104 bytes) */
int FUN_000c8760(param_1, param_2, param_3)
  uint *param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x3f0000) == 0x160000) {
    *param_1 = uVar1 & 0xffc0ffff | 0x40000;
    *(short *)((int)param_1 + 2) = (short)*(undefined4 *)(param_3 + 0x54);
    uVar1 = *param_1;
  }
  if ((uVar1 & 0x3f0000) != 0xf0000) {
    return;
  }
  *(short *)((int)param_1 + 2) =
       (short)*(undefined4 *)(((unsigned char *)0x0000232c) + (uint)(ushort)*param_1 * 4 + param_3);
  return;
}

/* FUN_000c87d0 @ 0xc87d0 (296 bytes) */
int FUN_000c87d0(param_1, param_2, param_3)
  uint *param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = *param_1;
  uVar4 = (uint)(ushort)*param_1;
  uVar3 = uVar1 >> 0x10 & 0x3f;
  iVar2 = (int)uVar4 >> 5;
  if (uVar3 != 1) {
    if (uVar3 == 2) {
      if ((uVar1 & 0x1800000) == 0) {
        iVar2 = iVar2 * 4 + param_3;
        *(uint *)(iVar2 + 0x2c) =
             (-2 << (uVar4 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar4 & 0x1f)) & *(uint *)(iVar2 + 0x2c)
        ;
        uVar1 = *param_1;
        goto LAB_000c88e4;
      }
      iVar5 = 8;
      iVar2 = param_3;
      do {
        *(undefined4 *)(iVar2 + 0x2c) = 0;
        iVar2 = iVar2 + 4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    else {
      if (uVar3 == 3) {
        if (uVar4 != 0) {
          *(undefined4 *)(((unsigned char *)0x000021c8) + param_3) = 5;
          uVar1 = *param_1;
        }
        goto LAB_000c88e4;
      }
      if (uVar3 != 0x15) goto LAB_000c88e4;
      *(undefined4 *)(((unsigned char *)0x000021c8) + param_3) = 5;
    }
  }
  else {
    if ((uVar1 & 0x1800000) == 0) {
      iVar5 = iVar2 * 4 + param_3;
      *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & ~(1 << (uVar4 + iVar2 * -0x20 & 0x3f));
      uVar1 = *param_1;
      goto LAB_000c88e4;
    }
    iVar5 = 8;
    iVar2 = param_3;
    do {
      *(undefined4 *)(iVar2 + 0xc) = 0;
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  uVar1 = *param_1;
LAB_000c88e4:
  if ((uVar1 & 0x1800000) == 0) {
    return;
  }
  if (uVar3 == 1) {
    *(undefined4 *)(FUN_0000222c + param_3 + 4) = 1;
    return;
  }
  *(undefined4 *)(((unsigned char *)0x000021c8) + param_3) = 4;
  return;
}

/* FUN_000c8910 @ 0xc8910 (400 bytes) */
int FUN_000c8910(param_1, param_2, param_3, param_4)
  uint *param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34 [6];
  
  puVar4 = param_1 + 1;
  uVar3 = *param_1;
  if (param_2 != 0) {
    uVar5 = param_1[1];
    puVar4 = param_1 + 2;
    uVar1 = param_4;
    if ((uVar5 & 0x400000) != 0) {
      uVar1 = param_1[2];
      puVar4 = param_1 + 3;
    }
    ((int (*)())FUN_000c8600)(uVar5 & 0xffff,uVar5 >> 0x10 & 0x3f,param_4,uVar1,uVar5 >> 0x16 & 1);
    if (((uVar3 & 0xffff) == 0x48) && ((uVar5 & 0xffff) != 0)) {
      *(undefined4 *)(((unsigned char *)0x000021c8) + param_4) = 5;
    }
    if ((uVar5 & 0x1800000) != 0) {
      puVar4 = puVar4 + 1;
      *(undefined4 *)(((unsigned char *)0x000021c8) + param_4) = 4;
    }
  }
  if (0 < param_3) {
    local_48 = *puVar4;
    puVar2 = puVar4 + 1;
    if ((local_48 & 0x400000) != 0) {
      local_3c = puVar4[1];
      puVar2 = puVar4 + 2;
    }
    puVar4 = puVar2;
    if ((local_48 & 0x1800000) != 0) {
      puVar4 = puVar4 + 1;
    }
    ((int (*)())FUN_000c87d0)(&local_48,&local_3c,param_4);
  }
  if (1 < param_3) {
    local_44 = *puVar4;
    puVar2 = puVar4 + 1;
    if ((local_44 & 0x400000) != 0) {
      local_38 = puVar4[1];
      puVar2 = puVar4 + 2;
    }
    puVar4 = puVar2;
    if ((local_44 & 0x1800000) != 0) {
      puVar4 = puVar4 + 1;
    }
    ((int (*)())FUN_000c87d0)(&local_44,&local_38,param_4);
  }
  puVar2 = puVar4;
  if (2 < param_3) {
    local_40 = *puVar4;
    puVar2 = puVar4 + 1;
    if ((local_40 & 0x400000) != 0) {
      local_34[0] = puVar4[1];
      puVar2 = puVar4 + 2;
    }
    if ((local_40 & 0x1800000) != 0) {
      puVar2 = puVar2 + 1;
    }
    ((int (*)())FUN_000c87d0)(&local_40,local_34,param_4);
  }
  return puVar2;
}

/* FUN_000c8aa0 @ 0xc8aa0 (780 bytes) */
int FUN_000c8aa0(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uint uVar8;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44 [8];
  
  puVar6 = (undefined4 *)*param_2;
  puVar5 = (undefined4 *)*param_1;
  puVar4 = puVar5 + 1;
  puVar7 = puVar6 + 1;
  *puVar5 = *puVar6;
  if (param_3 != 0) {
    uVar8 = puVar6[1];
    puVar7 = puVar6 + 2;
    uVar2 = uVar8 & 0x3f0000;
    if (uVar2 == 0x170000) {
      iVar3 = (uVar8 & 0xffff) * 4 + param_5;
      *(undefined4 *)(((unsigned char *)0x000021f0) + iVar3) = 1;
      uVar8 = *(uint *)(((unsigned char *)0x000021e0) + iVar3) & 0xffff | uVar8 & 0xffc00000 | 0x40000;
    }
    else if (uVar2 == 0x100000) {
      uVar8 = *(uint *)(((unsigned char *)0x00002208) + param_5) & 0xffff | uVar8 & 0xffc00000 | 0x40000;
    }
    else if (uVar2 == 0xe0000) {
      if (*(int *)(param_5 + 0x2234) == 0) {
        uVar8 = *(uint *)(((unsigned char *)0x00002200) + param_5) & 0xffff | uVar8 & 0xffc00000 | 0x40000;
      }
    }
    else if (uVar2 == 0xd0000) {
      if ((*(int *)(param_5 + 0x2234) == 0) && (*(int *)(((unsigned char *)0x00002324) + param_5) != 0)) {
        uVar8 = *(uint *)(((unsigned char *)0x00002328) + param_5) & 0xffff | uVar8 & 0xffc00000 | 0x40000;
      }
    }
    else if (uVar2 == 0xf0000) {
      uVar8 = *(uint *)(((unsigned char *)0x0000232c) + (uVar8 & 0xffff) * 4 + param_5) & 0xffff |
              uVar8 & 0xffff0000;
    }
    *(uint *)(((unsigned char *)0x00002318) + param_5) = uVar8;
    *puVar4 = uVar8;
    puVar4 = puVar5 + 2;
    if ((uVar8 & 0x400000) != 0) {
      uVar2 = *puVar7;
      puVar4 = puVar5 + 3;
      puVar7 = puVar6 + 3;
      puVar5[2] = uVar2;
    }
  }
  if (0 < param_4) {
    local_58 = *puVar7;
    puVar1 = puVar7 + 1;
    if ((local_58 & 0x400000) != 0) {
      local_4c = puVar7[1];
      puVar1 = puVar7 + 2;
    }
    puVar7 = puVar1;
    ((int (*)())FUN_000c8760)(&local_58,&local_4c,param_5);
    *puVar4 = local_58;
    puVar1 = puVar4 + 1;
    if ((local_58 & 0x400000) != 0) {
      puVar4[1] = local_4c;
      puVar1 = puVar4 + 2;
    }
    puVar4 = puVar1;
    if ((local_58 & 0x1800000) != 0) {
      uVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
    }
  }
  if (1 < param_4) {
    local_54 = *puVar7;
    puVar1 = puVar7 + 1;
    if ((local_54 & 0x400000) != 0) {
      local_48 = puVar7[1];
      puVar1 = puVar7 + 2;
    }
    puVar7 = puVar1;
    ((int (*)())FUN_000c8760)(&local_54,&local_48,param_5);
    *puVar4 = local_54;
    puVar1 = puVar4 + 1;
    if ((local_54 & 0x400000) != 0) {
      puVar4[1] = local_48;
      puVar1 = puVar4 + 2;
    }
    puVar4 = puVar1;
    if ((local_54 & 0x1800000) != 0) {
      uVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
    }
  }
  if (2 < param_4) {
    local_50 = *puVar7;
    puVar1 = puVar7 + 1;
    if ((local_50 & 0x400000) != 0) {
      local_44[0] = puVar7[1];
      puVar1 = puVar7 + 2;
    }
    puVar7 = puVar1;
    ((int (*)())FUN_000c8760)(&local_50,local_44,param_5);
    *puVar4 = local_50;
    puVar1 = puVar4 + 1;
    if ((local_50 & 0x400000) != 0) {
      puVar4[1] = local_44[0];
      puVar1 = puVar4 + 2;
    }
    puVar4 = puVar1;
    if ((local_50 & 0x1800000) != 0) {
      uVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
    }
  }
  *param_1 = puVar4;
  *param_2 = puVar7;
  return puVar7;
}

/* FUN_000c8de0 @ 0xc8de0 (76 bytes) */
int FUN_000c8de0(param_1, param_2)
  undefined4 *param_1;
  void *param_2;
{
  undefined4 uVar1;
  void *pvVar2;
  
  pvVar2 = _malloc(0x28);
  uVar1 = *param_1;
  *param_1 = pvVar2;
  *(undefined4 *)((int)pvVar2 + 0x24) = uVar1;
  _memcpy(pvVar2,param_2,0x24);
  return;
}

/* FUN_000c8e30 @ 0xc8e30 (28 bytes) */
void FUN_000c8e30(double param_1,double param_2,double param_3,double param_4,int param_5,
                 int param_6)

{
  param_5 = param_6 * 0x10 + param_5;
  *(float *)(param_5 + 0x98) = (float)param_4;
  *(float *)(param_5 + 0x8c) = (float)param_1;
  *(float *)(param_5 + 0x90) = (float)param_2;
  *(float *)(param_5 + 0x94) = (float)param_3;
  return;
}

/* FUN_000c8e50 @ 0xc8e50 (7396 bytes) */
int FUN_000c8e50(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  undefined4 *param_3;
{
  bool bVar1;
  byte *pbVar2;
  bool bVar3;
  bool bVar4;
  byte *pbVar5;
  uint uVar6;
  void *pvVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  char *pcVar12;
  undefined4 *puVar13;
  void *pvVar14;
  uint *puVar15;
  void *pvVar16;
  undefined4 *puVar17;
  uint uVar18;
  uint *puVar19;
  uint *puVar20;
  uint uVar21;
  uint uVar22;
  undefined4 *puVar23;
  char cVar25;
  undefined4 uVar24;
  undefined4 *puVar26;
  undefined4 *puVar27;
  undefined4 uVar28;
  uint unaff_r14;
  uint unaff_r15;
  uint *puVar29;
  uint unaff_r20;
  uint unaff_r21;
  uint uVar30;
  uint *puVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  int iVar35;
  int iVar36;
  uint uVar37;
  undefined1 *puVar38;
  int iVar39;
  uint *local_2bb8;
  uint *local_2bb4;
  uint local_2bb0;
  uint local_2bac [2];
  uint local_2ba4;
  uint local_2ba0 [2];
  uint local_2b98;
  uint local_2b94;
  uint local_2b8c [3];
  undefined1 auStack_2b80 [12];
  uint local_2b74;
  uint local_2b70;
  uint local_2b68;
  uint local_2b64;
  uint local_2b60;
  uint local_2b5c;
  undefined4 local_2b58 [4];
  undefined4 local_2b48;
  undefined4 local_2b44;
  undefined4 local_2b40;
  undefined4 local_2b3c;
  undefined4 local_2b38 [4];
  undefined4 local_2b28;
  undefined4 local_2b24;
  undefined4 local_2b20;
  undefined4 local_2b1c;
  undefined1 auStack_2b18 [76];
  uint *local_2acc;
  int local_2ac8;
  undefined4 local_2ac0 [8];
  undefined4 local_2aa0 [16];
  void *local_2a60;
  undefined1 auStack_2a5c [72];
  undefined4 local_2a14;
  undefined4 local_2a10;
  uint local_2a08;
  uint local_2a04;
  void *local_29fc;
  void *local_29f8;
  undefined4 local_2958;
  undefined1 uStack_2954;
  char local_2953 [3];
  byte abStack_2950 [764];
  int local_2654;
  char local_2650 [576];
  undefined4 local_2410;
  undefined4 *local_240c;
  int *local_2408;
  int local_2400;
  undefined4 local_23fc;
  uint local_23ec;
  undefined4 local_23e8;
  undefined4 local_23e4;
  uint local_23e0;
  undefined4 local_23dc [4];
  undefined4 local_23cc;
  undefined4 local_23c8;
  undefined4 local_23c4;
  undefined4 local_23c0;
  undefined4 local_23bc [4];
  undefined4 local_23ac;
  undefined4 local_23a8;
  undefined4 local_23a4;
  undefined4 local_23a0;
  int local_239c;
  undefined4 local_2398;
  undefined4 local_2384;
  uint local_2378;
  uint local_2374;
  int aiStack_22f0 [32];
  uint local_2270;
  uint local_2260 [6];
  undefined1 auStack_2248 [8];
  float local_2240 [1024];
  uint local_1240 [8];
  int aiStack_1220 [1024];
  int local_220;
  int local_218;
  int local_1f8 [5];
  uint local_1e4;
  int local_1dc;
  uint local_1d8;
  int local_1d4;
  int local_1d0;
  int local_1cc;
  int local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  int local_1b4;
  undefined4 local_1b0 [16];
  undefined4 local_170 [16];
  uint auStack_130 [17];
  int local_ec;
  uint local_d8;
  uint local_d4;
  undefined4 local_cc;
  int local_c8;
  uint local_c4;
  undefined4 local_7c;
  longlong local_78;
  uint *local_70;
  uint *local_6c;
  uint *local_60;
  
  iVar39 = 8;
  iVar9 = 0;
  do {
    *(undefined4 *)((int)local_2b38 + iVar9) = 0xffffffff;
    *(undefined4 *)((int)local_2b58 + iVar9) = 0xffffffff;
    iVar9 = iVar9 + 4;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
  pvVar14 = _malloc(0x400);
  uVar21 = *(uint *)(param_1 + 0x44);
  local_218 = 0;
  if ((uVar21 & 0x2000) == 0) {
    local_1e4 = uVar21 >> 0x18 & 1;
    local_1d8 = 0xffff;
  }
  else {
    local_1e4 = uVar21 >> 0xb & 1;
    if (local_1e4 == 0) {
      local_1d8 = 0xffff;
    }
    else {
      local_1d8 = (uint)(byte)((unsigned char *)0x000011d1)[param_1];
    }
  }
  puVar31 = (uint *)*param_2;
  local_d8 = uVar21 >> 10 & 1;
  iVar39 = 8;
  local_23e4 = 0xffff;
  local_d4 = (uint)(byte)((unsigned char *)0x000011d2)[param_1];
  local_c4 = (uint)(param_2[6] == 0);
  local_23c0 = local_2b1c;
  iVar9 = param_2[1];
  local_23c4 = local_2b20;
  local_23c8 = local_2b24;
  local_1b4 = 0;
  local_ec = 0;
  local_cc = 0;
  local_7c = 0;
  local_23cc = local_2b28;
  local_23dc[3] = local_2b38[3];
  local_23e8 = 0;
  local_239c = 0;
  local_2384 = 0;
  local_23dc[2] = local_2b38[2];
  local_23dc[1] = local_2b38[1];
  local_23dc[0] = local_2b38[0];
  local_23a0 = local_2b3c;
  local_2270 = 0;
  local_1b8 = 0;
  local_23e0 = 0;
  local_220 = 0;
  local_1f8[0] = 0;
  local_23a8 = local_2b44;
  local_23a4 = local_2b40;
  local_1f8[1] = 0;
  local_1f8[2] = 0;
  local_1f8[3] = 0;
  local_1d4 = 0;
  local_23bc[3] = local_2b58[3];
  local_23ac = local_2b48;
  local_1d0 = 0;
  local_1cc = 0;
  local_1c8 = 0;
  local_1dc = 0;
  local_23bc[1] = local_2b58[1];
  local_1c4 = 0;
  local_1c0 = 0;
  local_1bc = 0;
  local_23bc[2] = local_2b58[2];
  puVar29 = local_2260;
  local_6c = puVar29;
  local_23bc[0] = local_2b58[0];
  do {
    *puVar29 = 0;
    puVar29[0x408] = 0;
    puVar29 = puVar29 + 1;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
  puVar13 = local_1b0;
  iVar39 = 0x10;
  do {
    *puVar13 = 0;
    puVar13[0x10] = 0;
    puVar13 = puVar13 + 1;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
  iVar36 = 0;
  iVar39 = 0;
  uVar21 = 0;
  puVar29 = puVar31;
switchD_000c90cc_caseD_15:
  local_2bb4 = puVar29 + 2;
  puVar15 = local_2bb4;
switchD_000c90cc_caseD_18:
  puVar29 = puVar15;
  if (puVar29 < puVar31 + iVar9) goto code_r0x000c90a4;
  if (local_220 != 0) {
    puVar29 = (uint *)0x0;
    uVar18 = 0;
    goto LAB_000ca6bc;
  }
  iVar36 = (iVar36 + iVar9) * 4;
  local_2398 = local_23e8;
  if (local_239c != 0) {
    iVar36 = iVar36 + 0x48;
  }
  uVar18 = iVar36 + iVar39 * 4;
  bVar4 = local_218 != 0;
  if (bVar4) {
    uVar18 = uVar18 + 0x14;
  }
  uVar33 = uVar18;
  if ((local_1f8[0] != 0) && (uVar33 = uVar18 + 0xc, bVar4)) {
    uVar33 = uVar18 + 0x24;
  }
  uVar18 = uVar33;
  if ((local_1f8[1] != 0) && (uVar18 = uVar33 + 0xc, bVar4)) {
    uVar18 = uVar33 + 0x24;
  }
  uVar33 = uVar18;
  if ((local_1f8[2] != 0) && (uVar33 = uVar18 + 0xc, bVar4)) {
    uVar33 = uVar18 + 0x24;
  }
  uVar22 = uVar33;
  if ((local_1f8[3] != 0) && (uVar22 = uVar33 + 0xc, bVar4)) {
    uVar22 = uVar33 + 0x24;
  }
  if (((local_1dc != 0) && (local_1e4 != 0)) && (local_1b4 == 0)) {
    uVar22 = uVar22 + 0x14;
  }
  if (local_ec == 1) {
    uVar22 = uVar22 + 0x24;
  }
  else if (local_ec == 2) {
    uVar22 = uVar22 + 0x30;
  }
  else if (local_ec == 3) {
    uVar22 = uVar22 + 0x40;
  }
  else if (local_ec == 0) goto LAB_000c99d4;
  uVar22 = uVar22 + 8;
  piVar10 = local_1f8;
  iVar39 = 4;
  do {
    if (*piVar10 != 0) {
      uVar22 = uVar22 + 0x2c;
    }
    piVar10 = piVar10 + 1;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
LAB_000c99d4:
  if (((local_1d0 != 0) || (local_1c8 != 0)) || (uVar18 = uVar22, local_1b4 == 0)) {
    if ((local_1d4 == 0) && (local_1cc != 0)) {
      uVar22 = uVar22 + 0xc;
    }
    uVar18 = uVar22;
    if ((local_1b4 == 0) && (uVar18 = uVar22 + 0xc, local_d8 != 0)) {
      uVar18 = uVar22 + 0x18;
    }
  }
  bVar4 = true;
  puVar29 = _malloc(uVar18 + 0x10);
  *puVar29 = *puVar31;
  local_2bb4 = puVar31 + 2;
  puVar29[1] = puVar31[1];
  puVar20 = local_2bb4;
  puVar15 = puVar29 + 2;
  goto switchD_000c9ab8_caseD_18;
code_r0x000c90a4:
  uVar18 = *puVar29;
  puVar15 = puVar29;
  switch(uVar18 & 0xffff) {
  default:
    goto switchD_000c90cc_caseD_0;
  case 1:
  case 2:
  case 4:
  case 5:
  case 0xb:
  case 0xe:
  case 0x12:
  case 0x1e:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
  case 0x33:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x47:
  case 0x48:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x50:
  case 0x51:
  case 0x54:
  case 0x55:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5c:
  case 0x62:
  case 99:
    uVar8 = 1;
    break;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    uVar8 = 1;
    goto LAB_000c9340;
  case 6:
  case 0x10:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_2bb4 = puVar29 + 1;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    uVar8 = 0;
LAB_000c9340:
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,uVar8,2,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 8:
  case 0x32:
    local_2bb4 = puVar29 + 2;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 9:
  case 0x1d:
    local_2bb4 = puVar29 + 3;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,1,3,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0xf:
    local_2bb4 = puVar29 + *(ushort *)((int)puVar29 + 6) + 2;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x14:
    local_2bb4 = puVar29 + 3;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x15:
    goto switchD_000c90cc_caseD_15;
  case 0x16:
    local_2bb4 = puVar29 + 1;
    uVar33 = puVar29[1];
    uVar18 = uVar33 & 0x3f0000;
    ((int (*)())FUN_000c8600)(uVar33 & 0xffff,uVar33 >> 0x10 & 0x3f,&local_23e8,0,0);
    if (uVar18 == 0x160000) {
      local_239c = 1;
    }
    else if (uVar18 == 0x110000) {
      local_23e0 = 1 << (uVar33 & 0x3f) | local_23e0;
    }
    else if (uVar18 == 0xf0000) {
      uVar21 = uVar21 | 1 << (uVar33 & 0x3f);
    }
    else if (uVar18 == 0x100000) {
      local_2384 = 1;
    }
    goto LAB_000c9564;
  case 0x18:
    goto switchD_000c90cc_caseD_18;
  case 0x19:
    uVar22 = uVar18 >> 0x1b & 3;
    uVar33 = uVar18 >> 0x10 & 0xff;
    if ((uVar22 == 2) || ((uVar22 == 0 && (auStack_130[uVar33] == 2)))) {
      local_2270 = 1 << (uVar18 >> 0x10 & 0x3f) | local_2270;
    }
    ((int (*)())FUN_000c7270)(&local_23e8,uVar33,uVar18 >> 0x18 & 7);
    local_2bb4 = local_2bb4 + 1;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x1a:
    local_2bb4 = puVar29 + 1;
    if ((int)uVar18 < 0) {
      local_2bb4 = puVar29 + 2;
    }
LAB_000c9564:
    local_2bb4 = local_2bb4 + 1;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x1c:
    local_2bb4 = puVar29 + 1;
    uVar33 = puVar29[1];
    uVar18 = uVar33 >> 0x10 & 0x3f;
    if (uVar18 == 1) {
      local_2b68 = puVar29[2];
      local_2b64 = puVar29[3];
      local_2b60 = puVar29[4];
      local_2bb4 = puVar29 + 6;
      local_2b5c = puVar29[5];
      ((int (*)())FUN_000c7290)(&local_23e8,uVar33 & 0xffff,&local_2b68);
      puVar15 = local_2bb4;
    }
    else {
      puVar15 = local_2bb4;
      if (uVar18 == 2) {
        local_2b68 = puVar29[2];
        local_2b64 = puVar29[3];
        local_2b60 = puVar29[4];
        local_2bb4 = puVar29 + 6;
        local_2b5c = puVar29[5];
        ((int (*)())FUN_000c72f0)(&local_23e8,uVar33 & 0xffff,&local_2b68);
        puVar15 = local_2bb4;
      }
    }
    goto switchD_000c90cc_caseD_18;
  case 0x24:
    iVar36 = iVar36 + 5;
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,1,2,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x35:
    local_2bb4 = puVar29 + 2;
    local_2b8c[0] = puVar29[1];
    ((int (*)())FUN_000c87d0)(local_2b8c,auStack_2b80,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x37:
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,0,1,&local_23e8);
    local_1bc = 1;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x3e:
    uVar8 = 0;
    break;
  case 0x5d:
    local_2bb4 = puVar29 + 2;
    local_c8 = local_c8 + 1;
    uVar18 = puVar29[1];
    uVar33 = *puVar29;
    if ((((uVar33 & 0xc000000) == 0x4000000) ||
        (((uVar33 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2374) != 0)))) &&
       (local_2378 << (*(byte *)((int)puVar29 + 1) & 0x3f) != 0)) {
      iVar39 = iVar39 + 0x1b;
      local_2374 = 1 << (*(byte *)((int)puVar29 + 1) & 0x3f) | local_2374;
      uVar33 = *puVar29;
    }
    if ((int)uVar33 < 0) {
      local_2bb4 = puVar29 + 3;
      uVar33 = *puVar29;
    }
    if ((uVar33 & 0x40000000) != 0) {
      local_2bb4 = local_2bb4 + 1;
    }
    if ((uVar18 & 0x400000) != 0) {
      unaff_r21 = *local_2bb4;
      local_2bb4 = local_2bb4 + 1;
    }
    ((int (*)())FUN_000c8600)(uVar18 & 0xffff,uVar18 >> 0x10 & 0x3f,&local_23e8,unaff_r21,uVar18 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2378) != 0) {
      iVar39 = iVar39 + 4;
    }
    local_2b74 = *local_2bb4;
    puVar29 = local_2bb4 + 1;
    if ((local_2b74 & 0x400000) != 0) {
      local_2bb0 = local_2bb4[1];
      puVar29 = local_2bb4 + 2;
    }
    local_2bb4 = puVar29;
    ((int (*)())FUN_000c87d0)(&local_2b74,&local_2bb0,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x5e:
    local_2bb4 = puVar29 + 2;
    local_c8 = local_c8 + 1;
    uVar18 = puVar29[1];
    uVar33 = *puVar29;
    if ((((uVar33 & 0xc000000) == 0x4000000) ||
        (((uVar33 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2374) != 0)))) &&
       (local_2378 << (*(byte *)((int)puVar29 + 1) & 0x3f) != 0)) {
      iVar39 = iVar39 + 0x1b;
      local_2374 = 1 << (*(byte *)((int)puVar29 + 1) & 0x3f) | local_2374;
      uVar33 = *puVar29;
    }
    if ((int)uVar33 < 0) {
      local_2bb4 = puVar29 + 3;
      uVar33 = *puVar29;
    }
    if ((uVar33 & 0x40000000) != 0) {
      local_2bb4 = local_2bb4 + 1;
    }
    if ((uVar18 & 0x400000) != 0) {
      unaff_r20 = *local_2bb4;
      local_2bb4 = local_2bb4 + 1;
    }
    ((int (*)())FUN_000c8600)(uVar18 & 0xffff,uVar18 >> 0x10 & 0x3f,&local_23e8,unaff_r20,uVar18 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2378) != 0) {
      iVar39 = iVar39 + 4;
    }
    local_2bb0 = *local_2bb4;
    puVar29 = local_2bb4 + 1;
    if ((local_2bb0 & 0x400000) != 0) {
      local_2ba4 = local_2bb4[1];
      puVar29 = local_2bb4 + 2;
    }
    local_2bac[0] = *puVar29;
    local_2bb4 = puVar29 + 1;
    if ((local_2bac[0] & 0x400000) != 0) {
      local_2ba0[0] = puVar29[1];
      local_2bb4 = puVar29 + 2;
    }
    ((int (*)())FUN_000c87d0)(&local_2bb0,&local_2ba4,&local_23e8);
    ((int (*)())FUN_000c87d0)(local_2bac,local_2ba0,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  }
  local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,uVar8,1,&local_23e8);
  puVar15 = local_2bb4;
  goto switchD_000c90cc_caseD_18;
switchD_000c9ab8_caseD_18:
  local_2bb8 = puVar15;
  puVar19 = puVar20;
  if (puVar31 + iVar9 <= puVar19) {
    uVar18 = uVar18 >> 2;
    local_23e0 = uVar21 | local_23e0;
LAB_000ca6bc:
    if (local_220 != 0) {
      return local_220;
    }
    param_3[0x1587] = 0;
    iVar9 = 0;
    param_3[0x1589] = 0;
    param_3[0x1502] = 0;
    puVar13 = param_3 + 0x1000;
    puVar38 = auStack_2248;
    puVar17 = param_3 + 0x1004;
    puVar31 = local_6c;
    do {
      puVar26 = puVar17 + 1;
      puVar27 = (undefined4 *)(puVar38 + 8);
      puVar23 = puVar13 + 1;
      iVar39 = 0x20;
      uVar21 = 0;
      do {
        if ((1 << (uVar21 & 0x3f) & *puVar31) == 0) {
          *(undefined1 *)puVar26 = 0;
        }
        else {
          *puVar23 = *puVar27;
          puVar23[1] = puVar27[1];
          puVar23[2] = puVar27[2];
          uVar8 = puVar27[3];
          *(undefined1 *)(puVar23 + 4) = 1;
          puVar23[3] = uVar8;
          if ((uint)param_3[0x1502] < iVar9 + uVar21) {
            param_3[0x1502] = iVar9 + uVar21;
          }
        }
        uVar21 = uVar21 + 1;
        puVar26 = puVar26 + 5;
        puVar27 = puVar27 + 4;
        puVar23 = puVar23 + 5;
        iVar39 = iVar39 + -1;
      } while (iVar39 != 0);
      bVar4 = iVar9 != 0xe0;
      puVar17 = puVar17 + 0xa0;
      puVar38 = puVar38 + 0x200;
      puVar13 = puVar13 + 0xa0;
      puVar31 = puVar31 + 1;
      iVar9 = iVar9 + 0x20;
    } while (bVar4);
    if ((int)param_3[0x1587] < (int)param_3[0x1502]) {
      param_3[0x1587] = param_3[0x1502];
    }
    _memset(auStack_2b18,0,0xbc);
    _memset(auStack_2a5c,0,0x674);
    pvVar16 = (void *)(**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x1870));
    local_2ac8 = uVar18 << 2;
    puVar17 = local_23dc;
    puVar13 = local_2ac0;
    iVar9 = 8;
    local_2a60 = pvVar16;
    do {
      uVar8 = *puVar17;
      uVar11 = puVar17[8];
      puVar17 = puVar17 + 1;
      *puVar13 = uVar8;
      puVar13[8] = uVar11;
      puVar13 = puVar13 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    local_2410 = 0x400;
    local_2acc = puVar29;
    local_240c = _malloc(0x40000);
    local_2408 = _malloc(0x40000);
    local_2a10 = 0x40;
    local_29f8 = _malloc(0x900);
    local_2a14 = 0x40;
    local_29fc = _malloc(0x900);
    cVar25 = '\0';
    pcVar12 = local_2953;
    iVar9 = 0x40;
    do {
      *pcVar12 = cVar25;
      pcVar12 = pcVar12 + 0xc;
      cVar25 = cVar25 + '\x01';
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    iVar9 = *(int *)(param_1 + 0x186c);
    if (iVar9 == 0) {
      ((int (*)())FUN_000c6ff0)(param_1,1);
      iVar9 = *(int *)(param_1 + 0x186c);
    }
    iVar9 = ((int (*)())FUN_000cd1b0)(iVar9,auStack_2b18,auStack_2a5c);
    if (iVar9 != 0) {
      return 2;
    }
    param_3[0x1000] = local_2400;
    if (local_2400 != 0) {
      puVar13 = local_240c;
      puVar17 = param_3;
      if (local_2400 == 0) {
        local_2400 = 1;
      }
      do {
        uVar8 = *puVar13;
        uVar11 = puVar13[1];
        uVar24 = puVar13[2];
        uVar28 = puVar13[3];
        puVar13 = puVar13 + 4;
        *puVar17 = uVar8;
        puVar17[1] = uVar11;
        puVar17[2] = uVar24;
        puVar17[3] = uVar28;
        puVar17 = puVar17 + 4;
        local_2400 = local_2400 + -1;
      } while (local_2400 != 0);
    }
    uVar21 = param_3[0x1502];
    if (uVar21 < local_23ec) {
      param_3[0x1502] = local_23ec;
      param_3[0x1501] = local_23ec + 1;
      uVar21 = local_23ec;
    }
    else {
      param_3[0x1501] = uVar21 + 1;
    }
    if (0xff < uVar21) {
      param_3[0x1502] = 0xff;
    }
    if (0x100 < (uint)param_3[0x1501]) {
      param_3[0x1501] = 0x100;
    }
    if (local_2a04 == 0) goto LAB_000caa4c;
    uVar18 = 0;
    iVar9 = 0;
    uVar21 = local_2a04;
    do {
      iVar39 = iVar9 + (int)local_29f8;
      if (*(int *)(iVar39 + 8) == 0x16) {
        uVar33 = *(uint *)(iVar39 + 0x10);
        iVar35 = *(int *)(iVar9 + (int)local_29f8);
        iVar36 = ((int)uVar33 >> 5) + (uint)((int)uVar33 < 0 && (uVar33 & 0x1f) != 0);
        if ((1 << (uVar33 + iVar36 * -0x20 & 0x3f) & local_2260[iVar36]) == 0) goto LAB_000caa2c;
        iVar36 = ((int (*)())FUN_000c7240)(*(undefined4 *)(iVar39 + 4));
        iVar39 = ((int (*)())FUN_000c7240)(*(undefined4 *)(iVar39 + 0xc));
        local_78 = (longlong)(int)local_2240[uVar33 * 4 + iVar39];
        aiStack_1220[iVar35 * 4 + iVar36] = (int)local_2240[uVar33 * 4 + iVar39];
      }
      else if (*(int *)(iVar39 + 8) == 0x18) {
LAB_000caa2c:
        ((int (*)())FUN_000c8de0)(param_3 + 0x1589,iVar39);
        uVar21 = local_2a04;
      }
      uVar18 = uVar18 + 1;
      iVar9 = iVar9 + 0x24;
      if (uVar21 <= uVar18) {
LAB_000caa4c:
        if (local_2a08 != 0) {
          uVar18 = 0;
          iVar9 = 0;
          uVar21 = local_2a08;
          do {
            pvVar7 = local_29fc;
            if (*(int *)((int)local_29fc + iVar9 + 8) == 1) {
              uVar33 = *(uint *)(iVar9 + (int)local_29fc);
              iVar39 = ((int (*)())FUN_000c7240)(*(undefined4 *)((int)local_29fc + iVar9 + 4));
              uVar8 = *(undefined4 *)((int)pvVar7 + iVar9 + 0x14);
              *(undefined1 *)(param_3 + (int)(((unsigned char *)0x00001005) + uVar33 * 5)) = 1;
              param_3[(int)(((unsigned char *)0x00001001) + uVar33 * 5 + iVar39)] = uVar8;
              uVar21 = local_2a08;
              if ((uint)param_3[0x1502] < uVar33) {
                param_3[0x1502] = uVar33;
              }
            }
            uVar18 = uVar18 + 1;
            iVar9 = iVar9 + 0x24;
          } while (uVar18 < uVar21);
        }
        uVar21 = 0;
        *(undefined1 *)(param_3 + 0x1507) = 0;
        param_3[0x1506] = 0;
        param_3[0x151d] = 0;
        param_3[0x151e] = 0;
        param_3[0x1503] = local_2958;
        param_3[0x1504] = local_2654;
        param_3[0x1505] = local_23fc;
        param_3[0x1588] = 0;
        if (local_2654 == 0) {
          uVar21 = param_3[0x151d];
        }
        else {
          pcVar12 = local_2650;
          if (local_2654 == 0) {
            local_2654 = 1;
          }
          do {
            cVar25 = *pcVar12;
            if (cVar25 == '\x01') {
              uVar21 = uVar21 | 0x10000;
              param_3[0x151d] = uVar21;
            }
            else if (cVar25 == '\0') {
              uVar21 = uVar21 | 1;
              *(undefined1 *)(param_3 + 0x1507) = 1;
              param_3[0x151d] = uVar21;
            }
            else if (cVar25 == '\x02') {
              cVar25 = pcVar12[1];
              if (cVar25 == '\x01') {
                uVar21 = uVar21 | 4;
                param_3[0x151d] = uVar21;
              }
              else if (cVar25 == '\0') {
                uVar21 = uVar21 | 2;
                param_3[0x151d] = uVar21;
              }
              else if (cVar25 == '\x02') {
                uVar21 = uVar21 | 8;
                param_3[0x151d] = uVar21;
              }
              else if (cVar25 == '\x03') {
                uVar21 = uVar21 | 0x10;
                param_3[0x151d] = uVar21;
              }
            }
            else if (cVar25 == '\x05') {
              param_3[0x151e] = 4 << ((uint)(byte)pcVar12[1] * 3 & 0x3f) | param_3[0x151e];
              param_3[0x1588] = 4 << ((uint)(byte)pcVar12[1] * 3 & 0x3f) | param_3[0x1588];
            }
            pcVar12 = pcVar12 + 0xc;
            local_2654 = local_2654 + -1;
          } while (local_2654 != 0);
        }
        if ((uVar21 & 0x18) != 0) {
          param_3[0x151d] = uVar21 | 0x1c;
        }
        puVar13 = param_3 + 0x1571;
        iVar9 = 0x16;
        do {
          *puVar13 = 0x16;
          puVar13 = puVar13 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        uVar21 = param_3[0x1503];
        if (uVar21 != 0) {
          puVar38 = &uStack_2954;
          uVar18 = uVar21;
          if (uVar21 == 0) {
            uVar18 = 1;
          }
          do {
            pbVar2 = puVar38 + 1;
            pbVar5 = puVar38 + (int)(abStack_2950 + -(int)&uStack_2954);
            puVar38 = puVar38 + 0xc;
            param_3[(int)(((unsigned char *)0x00001571) + *pbVar2)] = (uint)*pbVar5;
            uVar18 = uVar18 - 1;
          } while (uVar18 != 0);
        }
        if (uVar21 < 2) {
          if (uVar21 == 0) {
            param_3[0x1571] = 0;
            param_3[0x1572] = 1;
          }
          else if (param_3[0x1571] == 0) {
            param_3[0x1572] = 1;
          }
          else {
            param_3[0x1572] = 0;
          }
        }
        iVar9 = *local_2408;
        param_3[0x1520] = 0;
        param_3[0x151f] = (uint)(iVar9 != 0);
        if (((iVar9 != 0) != 0) && (iVar9 = *local_2408, 0 < iVar9)) {
          puVar13 = param_3 + 0x1531;
          uVar21 = 0;
          do {
            puVar13[0x20] = 0;
            *puVar13 = 0;
            puVar13[0x10] = 0;
            if (local_2408[uVar21 * 7 + 3] == 0x3e) {
              param_3[0x1520] = 2 << ((uVar21 & 0x1f) << 1) | param_3[0x1520];
              *(char *)((int)param_3 + uVar21 * 4 + 0x5547) =
                   (char)aiStack_1220[local_2408[uVar21 * 7 + 4] * 4 + 1];
              *(char *)((int)param_3 + uVar21 * 4 + 0x5546) =
                   (char)aiStack_1220[local_2408[uVar21 * 7 + 4] * 4 + 2];
              *(short *)((int)param_3 + uVar21 * 4 + 0x54c6) = (short)local_2408[uVar21 * 7 + 5];
              *(short *)(param_3 + (int)(((unsigned char *)0x00001531) + uVar21)) =
                   (short)aiStack_1220[local_2408[uVar21 * 7 + 4] * 4];
              *(short *)((int)param_3 + uVar21 * 4 + 0x5506) = (short)local_2408[uVar21 * 7 + 7];
              *(short *)(param_3 + (int)(((unsigned char *)0x00001541) + uVar21)) =
                   (short)local_2408[uVar21 * 7 + 5] + 1;
              param_3[(int)(((unsigned char *)0x00001561) + local_2408[uVar21 * 7 + 4])] = uVar21;
            }
            uVar21 = uVar21 + 1;
            puVar13 = puVar13 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        if (local_240c != (undefined4 *)0x0) {
          _free(local_240c);
        }
        if (pvVar14 != (void *)0x0) {
          _free(pvVar14);
        }
        if (local_2408 != (int *)0x0) {
          _free(local_2408);
        }
        if (puVar29 != (uint *)0x0) {
          _free(puVar29);
        }
        if (pvVar16 != (void *)0x0) {
          _free(pvVar16);
        }
        if (local_29f8 != (void *)0x0) {
          _free(local_29f8);
        }
        if (local_29fc != (void *)0x0) {
          _free(local_29fc);
        }
        return 0;
      }
    } while( true );
  }
  uVar33 = *puVar19;
  puVar20 = puVar19;
  puVar15 = local_2bb8;
  switch(uVar33 & 0xffff) {
  default:
    goto switchD_000c90cc_caseD_0;
  case 1:
  case 2:
  case 4:
  case 5:
  case 0xb:
  case 0xe:
  case 0x12:
  case 0x1e:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
  case 0x33:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3c:
  case 0x3d:
  case 0x47:
  case 0x48:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x50:
  case 0x51:
  case 0x54:
  case 0x55:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5c:
  case 0x62:
  case 99:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *)((int (*)())FUN_000c8110)(local_2bb8,&local_23e8);
    }
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,1,&local_23e8);
    puVar20 = local_2bb4;
    puVar15 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *)((int (*)())FUN_000c8110)(local_2bb8,&local_23e8);
    }
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,2,&local_23e8);
    puVar20 = local_2bb4;
    puVar15 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_2bb4 = puVar19 + 1;
    *local_2bb8 = uVar33;
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,0,2,&local_23e8);
    puVar20 = local_2bb4;
    puVar15 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *local_2bb8 = uVar33;
    local_2bb4 = puVar19 + 2;
    local_2bb8[1] = puVar19[1];
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 2;
    goto switchD_000c9ab8_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *local_2bb8 = uVar33;
    local_2bb8[1] = puVar19[1];
    local_2bb4 = puVar19 + 3;
    local_2bb8[2] = puVar19[2];
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 3;
    goto switchD_000c9ab8_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *)((int (*)())FUN_000c8110)(local_2bb8,&local_23e8);
    }
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,3,&local_23e8);
    puVar20 = local_2bb4;
    puVar15 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 0xf:
    local_2bb4 = puVar19 + 2;
    *local_2bb8 = uVar33;
    local_2bb8[1] = puVar19[1];
    puVar15 = local_2bb8 + 2;
    for (uVar33 = (uint)*(ushort *)((int)puVar19 + 6); puVar20 = local_2bb4, uVar33 != 0;
        uVar33 = uVar33 - 1) {
      uVar22 = *local_2bb4;
      local_2bb4 = local_2bb4 + 1;
      *puVar15 = uVar22;
      puVar15 = puVar15 + 1;
    }
  case 0x18:
    goto switchD_000c9ab8_caseD_18;
  case 0x19:
    local_2bb4 = puVar19 + 1;
    if ((uVar33 & 0x18000000) == 0) {
      uVar22 = *(uint *)((int)auStack_130 + (uVar33 >> 0xe & 0x3fc));
      if (uVar22 != 2) {
        uVar22 = 1;
      }
      uVar33 = (uVar22 & 3) << 0x1b | uVar33 & 0xe7ffffff;
    }
    *local_2bb8 = uVar33;
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1a:
    local_2bb4 = puVar19 + 1;
    *local_2bb8 = uVar33;
    puVar15 = local_2bb8 + 1;
    if ((int)uVar33 < 0) {
      uVar33 = *local_2bb4;
      local_2bb4 = puVar19 + 2;
      local_2bb8[1] = uVar33;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    uVar33 = *local_2bb4;
    local_2bb4 = local_2bb4 + 1;
    *local_2bb8 = uVar33;
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1c:
    local_2bb4 = puVar19 + 1;
    *local_2bb8 = uVar33;
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 1;
    if ((puVar19[1] >> 0x10 & 0x3f) - 1 < 2) {
      local_2bb8[1] = puVar19[1];
      local_2bb8[2] = puVar19[2];
      local_2bb8[3] = puVar19[3];
      local_2bb8[4] = puVar19[4];
      local_2bb4 = puVar19 + 6;
      local_2bb8[5] = puVar19[5];
      puVar20 = local_2bb4;
      puVar15 = local_2bb8 + 6;
    }
    goto switchD_000c9ab8_caseD_18;
  case 0x28:
    local_2bb4 = puVar19 + 1;
    puVar15 = (uint *)((int (*)())FUN_000c7930)(local_2bb8,&local_23e8);
    *puVar15 = uVar33;
    puVar20 = local_2bb4;
    puVar15 = puVar15 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x35:
    *local_2bb8 = uVar33;
    local_2bb4 = puVar19 + 2;
    local_2b8c[0] = puVar19[1];
    local_2bb8 = local_2bb8 + 1;
    ((int (*)())FUN_000c8760)(local_2b8c,auStack_2b80,&local_23e8);
    *local_2bb8 = local_2b8c[0];
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x37:
  case 0x3e:
    uVar8 = 0;
    break;
  case 0x3b:
    uVar8 = 1;
    break;
  case 0x5d:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *)((int (*)())FUN_000c8110)(local_2bb8,&local_23e8);
      puVar19 = local_2bb4;
    }
    uVar32 = *puVar19;
    puVar15 = puVar19 + 1;
    uVar33 = uVar32 >> 0x10;
    uVar22 = uVar33 & 0xff;
    bVar3 = (uVar32 & 0x80000000) != 0;
    if (bVar3) {
      puVar15 = puVar19 + 2;
      uVar30 = puVar19[1];
    }
    else {
      uVar30 = 0;
    }
    bVar1 = (uVar32 >> 0x1e & 1) != 0;
    if (bVar1) {
      uVar37 = *puVar15;
      puVar15 = puVar15 + 1;
    }
    else {
      uVar37 = 0;
    }
    local_2ba4 = *puVar15;
    puVar20 = puVar15 + 1;
    if ((local_2ba4 & 0x400000) != 0) {
      puVar20 = puVar15 + 2;
      unaff_r15 = puVar15[1];
    }
    local_2b74 = *puVar20;
    local_2bb4 = puVar20 + 1;
    if ((local_2b74 & 0x400000) != 0) {
      local_2b98 = puVar20[1];
      local_2bb4 = puVar20 + 2;
    }
    uVar6 = uVar32 & 0xc000000;
    if (uVar6 == 0x4000000) {
LAB_000ca0e4:
      if (local_2378 << (uVar33 & 0x3f) == 0) {
        local_70 = &local_2b74;
        uVar8 = 0;
        uVar34 = 1 << (uVar33 & 0x3f);
        puVar15 = &local_2b98;
      }
      else {
        local_60 = &local_2b98;
        local_70 = &local_2b74;
        local_2bb8 = (uint *)((int (*)())FUN_000c7460)(&local_23e8,local_70,local_60,uVar22,local_2bb8);
        puVar15 = local_60;
        if ((local_2ba4 & 0x400000) == 0) {
          uVar8 = 0;
          uVar34 = 1 << (uVar33 & 0x3f);
        }
        else {
          local_2ba4 = local_2ba4 & 0xffbfffff;
          uVar8 = 1;
          uVar34 = 1 << (uVar33 & 0x3f);
          local_2bb0 = unaff_r15;
        }
      }
    }
    else if (uVar6 == 0x8000000) {
      uVar34 = 1 << (uVar33 & 0x3f);
      if ((uVar34 & local_2374) != 0) goto LAB_000ca0e4;
      local_70 = &local_2b74;
      uVar8 = 0;
      puVar15 = &local_2b98;
    }
    else {
      uVar8 = 0;
      uVar34 = 1 << (uVar33 & 0x3f);
      local_70 = &local_2b74;
      puVar15 = &local_2b98;
    }
    ((int (*)())FUN_000c8760)(local_70,puVar15,&local_23e8);
    *local_2bb8 = uVar32;
    puVar15 = local_2bb8 + 1;
    if (bVar3) {
      local_2bb8[1] = uVar30;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    if (bVar1) {
      *local_2bb8 = uVar37;
      local_2bb8 = local_2bb8 + 1;
    }
    *local_2bb8 = local_2ba4;
    puVar15 = local_2bb8 + 1;
    if ((local_2ba4 & 0x400000) != 0) {
      local_2bb8[1] = unaff_r15;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    *local_2bb8 = local_2b74;
    puVar15 = local_2bb8 + 1;
    if ((local_2b74 & 0x400000) != 0) {
      local_2bb8[1] = local_2b98;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    if (((uVar6 == 0x4000000) || ((uVar6 == 0x8000000 && ((uVar34 & local_2374) != 0)))) &&
       (local_2378 << (uVar33 & 0x3f) != 0)) {
      local_2bb8 = (uint *)((int (*)())FUN_000c7650)(&local_23e8,local_70,&local_2ba4,&local_2bb0,uVar22,uVar8,
                                        local_2bb8);
    }
    uVar34 = uVar34 & local_2378;
    uVar33 = unaff_r15;
    goto joined_r0x000ca538;
  case 0x5e:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *)((int (*)())FUN_000c8110)(local_2bb8,&local_23e8);
      puVar19 = local_2bb4;
    }
    uVar32 = *puVar19;
    puVar15 = puVar19 + 1;
    uVar33 = uVar32 >> 0x10;
    uVar22 = uVar33 & 0xff;
    bVar3 = (uVar32 & 0x80000000) != 0;
    if (bVar3) {
      puVar15 = puVar19 + 2;
      uVar30 = puVar19[1];
    }
    else {
      uVar30 = 0;
    }
    bVar1 = (uVar32 & 0x40000000) != 0;
    if (bVar1) {
      uVar37 = *puVar15;
      puVar15 = puVar15 + 1;
    }
    else {
      uVar37 = 0;
    }
    local_2ba4 = *puVar15;
    puVar20 = puVar15 + 1;
    if ((local_2ba4 & 0x400000) != 0) {
      puVar20 = puVar15 + 2;
      unaff_r14 = puVar15[1];
    }
    local_2b98 = *puVar20;
    puVar15 = puVar20 + 1;
    if ((local_2b98 & 0x400000) != 0) {
      local_2b74 = puVar20[1];
      puVar15 = puVar20 + 2;
    }
    local_2b94 = *puVar15;
    local_2bb4 = puVar15 + 1;
    if ((local_2b94 & 0x400000) != 0) {
      local_2b70 = puVar15[1];
      local_2bb4 = puVar15 + 2;
    }
    uVar6 = uVar32 & 0xc000000;
    if (uVar6 == 0x4000000) {
LAB_000ca3b8:
      if ((local_2378 << (uVar33 & 0x3f) == 0) ||
         (local_2bb8 = (uint *)((int (*)())FUN_000c7460)(&local_23e8,&local_2b98,&local_2b74,uVar22,local_2bb8),
         (local_2ba4 & 0x400000) == 0)) {
LAB_000ca3ec:
        uVar8 = 0;
        uVar34 = 1 << (uVar33 & 0x3f);
      }
      else {
        local_2ba4 = local_2ba4 & 0xffbfffff;
        uVar8 = 1;
        uVar34 = 1 << (uVar33 & 0x3f);
        local_2bb0 = unaff_r14;
      }
    }
    else {
      if (uVar6 != 0x8000000) goto LAB_000ca3ec;
      uVar8 = 0;
      uVar34 = 1 << (uVar33 & 0x3f);
      if ((uVar34 & local_2374) != 0) goto LAB_000ca3b8;
    }
    *local_2bb8 = uVar32;
    puVar15 = local_2bb8 + 1;
    if (bVar3) {
      local_2bb8[1] = uVar30;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    if (bVar1) {
      *local_2bb8 = uVar37;
      local_2bb8 = local_2bb8 + 1;
    }
    *local_2bb8 = local_2ba4;
    puVar15 = local_2bb8 + 1;
    if ((local_2ba4 & 0x400000) != 0) {
      local_2bb8[1] = unaff_r14;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    *local_2bb8 = local_2b98;
    puVar15 = local_2bb8 + 1;
    if ((local_2b98 & 0x400000) != 0) {
      local_2bb8[1] = local_2b74;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    *local_2bb8 = local_2b94;
    puVar15 = local_2bb8 + 1;
    if ((local_2b94 & 0x400000) != 0) {
      local_2bb8[1] = local_2b70;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    if (((uVar6 == 0x4000000) || ((uVar6 == 0x8000000 && ((uVar34 & local_2374) != 0)))) &&
       (local_2378 << (uVar33 & 0x3f) != 0)) {
      local_2bb8 = (uint *)((int (*)())FUN_000c7650)(&local_23e8,&local_2b98,&local_2ba4,&local_2bb0,uVar22,uVar8
                                        ,local_2bb8);
    }
    uVar34 = uVar34 & local_2378;
    uVar33 = unaff_r14;
joined_r0x000ca538:
    puVar20 = local_2bb4;
    puVar15 = local_2bb8;
    if (uVar34 != 0) {
      *local_2bb8 = 0x47;
      uVar32 = local_2ba4;
      if ((local_2ba4 & 0x400000) == 0) {
        uVar32 = local_2ba4 | 0x400000;
        uVar33 = 0x55;
      }
      if (aiStack_22f0[uVar22] == 0x1906) {
        if ((uVar33 & 3) == 1) {
          uVar33 = uVar33 & 0xfffffffc | 2;
        }
        if ((uVar33 & 0xc) == 4) {
          uVar33 = uVar33 & 0xfffffff3 | 8;
        }
        if ((uVar33 & 0x30) == 0x10) {
          uVar33 = uVar33 & 0xffffffcf | 0x20;
        }
      }
      else if ((aiStack_22f0[uVar22] == 0x1909) && ((uVar33 & 0xc0) == 0x40)) {
        uVar33 = uVar33 & 0xffffff3f | 0xc0;
      }
      local_2bb8[1] = uVar32;
      local_2bb8[2] = uVar33;
      local_2bb8[3] = uVar32 & 0x3fffff;
      puVar15 = local_2bb8 + 4;
    }
    goto switchD_000c9ab8_caseD_18;
  }
  local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,uVar8,1,&local_23e8);
  puVar20 = local_2bb4;
  puVar15 = local_2bb8;
  goto switchD_000c9ab8_caseD_18;
switchD_000c90cc_caseD_0:
                    
  _exit(0);
}

/* FUN_000cae90 @ 0xcae90 (7760 bytes) */
int FUN_000cae90(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  bool bVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  uint uVar8;
  float fVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  void *pvVar14;
  uint *puVar15;
  void *pvVar16;
  uint uVar17;
  uint *puVar18;
  uint *puVar19;
  int iVar20;
  uint uVar21;
  byte *pbVar22;
  int iVar23;
  uint uVar24;
  int *piVar25;
  undefined4 uVar26;
  int iVar27;
  char *pcVar28;
  int *piVar29;
  undefined4 uVar30;
  uint unaff_r14;
  uint unaff_r15;
  uint *puVar31;
  uint unaff_r19;
  undefined1 *puVar32;
  uint unaff_r20;
  uint uVar33;
  undefined1 *puVar34;
  uint uVar35;
  uint *puVar36;
  uint uVar37;
  float *pfVar38;
  uint uVar39;
  int iVar40;
  undefined4 *puVar41;
  int iVar42;
  uint *local_c1f8;
  uint *local_c1f4;
  uint local_c1f0;
  uint local_c1ec [2];
  uint local_c1e4;
  uint local_c1e0 [2];
  uint local_c1d8;
  uint local_c1d4;
  uint local_c1cc;
  uint local_c1c8;
  uint local_c1c0 [3];
  undefined1 auStack_c1b4 [12];
  uint local_c1a8;
  uint local_c1a4;
  uint local_c1a0;
  uint local_c19c;
  uint local_c198 [4];
  undefined4 local_c188 [4];
  undefined4 local_c178;
  undefined4 local_c174;
  undefined4 local_c170;
  undefined4 local_c16c;
  uint local_c168 [4];
  undefined4 local_c158;
  undefined4 local_c154;
  undefined4 local_c150;
  undefined4 local_c14c;
  undefined1 auStack_c148 [72];
  uint *local_c100;
  uint *local_c0fc;
  int local_c0f8;
  uint local_c0f0 [8];
  uint local_c0d0 [16];
  void *local_c090;
  undefined4 local_c08c;
  undefined4 local_c088;
  uint local_c084;
  uint local_c080 [4];
  undefined4 local_c070;
  undefined4 local_c06c;
  undefined4 local_c068;
  undefined4 local_c064;
  uint local_c060 [4];
  undefined4 local_c050;
  undefined4 local_c04c;
  undefined4 local_c048;
  undefined4 local_c044;
  int local_c040;
  undefined4 local_c03c;
  int local_c034;
  int local_c030;
  uint local_c02c;
  int local_c028;
  int local_c024;
  int local_c020;
  uint local_c01c;
  uint local_c018;
  undefined4 local_bfd4;
  uint local_bf94 [16];
  uint local_bf54 [16];
  uint local_bf14;
  uint local_bf04 [6];
  undefined1 auStack_beec [4104];
  uint local_aee4 [6];
  undefined1 auStack_aecc [4104];
  int local_9ec4;
  int local_9ebc;
  int local_9eb8;
  undefined4 local_9eb4;
  int local_9e9c [5];
  int local_9e88;
  int local_9e80;
  int local_9e78;
  int local_9e74;
  int local_9e70;
  int local_9e6c;
  undefined4 local_9e68;
  int local_9e64;
  int local_9e60;
  undefined4 local_9e5c;
  int local_9e58;
  int local_9e54 [16];
  int local_9e14 [16];
  uint local_9dd4 [17];
  int local_9d90;
  int local_9d88;
  int local_9d84;
  undefined4 local_9d80;
  int local_9d7c;
  undefined4 local_9d70;
  int local_9d6c;
  undefined4 local_9d20;
  undefined1 auStack_9d1c [72];
  undefined4 local_9cd4;
  uint local_9cc8;
  void *local_9cbc;
  uint local_9c84 [27];
  int local_9c18;
  char local_9c14 [1348];
  undefined1 auStack_96d0 [37816];
  int iStack_318;
  undefined4 *local_88;
  uint *local_84;
  int *local_80;
  uint *local_70;
  
  iVar42 = 8;
  iVar11 = 0;
  do {
    *(undefined4 *)((int)local_c168 + iVar11) = 0xffffffff;
    *(undefined4 *)((int)local_c188 + iVar11) = 0;
    iVar11 = iVar11 + 4;
    iVar42 = iVar42 + -1;
  } while (iVar42 != 0);
  bVar3 = param_1 == 0;
  local_c168[0] = local_c168[0] & 0xffff0000;
  pvVar14 = _malloc(0x400);
  local_9d20 = 0;
  local_c018 = 0;
  local_9d70 = 0;
  local_9d6c = 0;
  if (bVar3) {
    local_c01c = 0;
  }
  else {
    uVar21 = 0;
    iVar42 = 0x10;
    local_c018 = 0;
    local_c01c = 0;
    puVar31 = local_bf94;
    iVar11 = param_1;
    do {
      iVar23 = *(int *)(((unsigned char *)0x000013f8) + iVar11);
      if ((iVar23 != 0) && (*(short *)(iVar23 + 0x38) == 0x1902)) {
        uVar17 = 1 << (uVar21 & 0x3f);
        local_c01c = uVar17 | local_c01c;
        *puVar31 = (uint)*(ushort *)(iVar23 + 0x58);
        puVar31[0x10] = (uint)*(ushort *)(iVar23 + 0x5c);
        if (*(short *)(iVar23 + 0x5a) != 0) {
          local_c018 = uVar17 | local_c018;
        }
      }
      uVar21 = uVar21 + 1;
      iVar11 = iVar11 + 4;
      puVar31 = puVar31 + 1;
      iVar42 = iVar42 + -1;
    } while (iVar42 != 0);
  }
  if (*(char *)(param_3 + 0x46) == '\0') {
    local_9ebc = 0;
  }
  else {
    local_9eb8 = param_3[0x2b];
    local_9ebc = 1;
    if (bVar3) {
      local_9eb4 = 0;
    }
    else {
      local_9eb4 = *(undefined4 *)(param_1 + 0x276c);
    }
  }
  iVar11 = 0;
  puVar31 = local_9dd4;
  iVar42 = 0x10;
  do {
    *puVar31 = 0;
    if ((!bVar3) && (*(int *)(((unsigned char *)0x000013f8) + iVar11 * 4 + *param_2) != 0)) {
      *puVar31 = (uint)*(byte *)(*(int *)(((unsigned char *)0x000013f8) + iVar11 * 4 + *param_2) + 0x30);
    }
    iVar11 = iVar11 + 1;
    puVar31 = puVar31 + 1;
    iVar42 = iVar42 + -1;
  } while (iVar42 != 0);
  local_9e58 = 1;
  local_9e88 = 0;
  local_9d90 = param_3[0x45];
  if ((bVar3) || (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(param_1 + 4) + 0x10)) != -0x7baf)) {
    local_9d80 = 0;
  }
  else {
    local_9d80 = 1;
  }
  puVar36 = (uint *)*param_4;
  local_c08c = 0;
  local_c028 = 0;
  local_c088 = 0xffff;
  local_c064 = local_c14c;
  local_c068 = local_c150;
  local_c06c = local_c154;
  local_c070 = local_c158;
  local_c080[3] = local_c168[3];
  local_c080[2] = local_c168[2];
  local_c080[1] = local_c168[1];
  local_c080[0] = local_c168[0];
  local_c044 = local_c16c;
  local_c048 = local_c170;
  iVar11 = param_4[1];
  local_c04c = local_c174;
  local_c050 = local_c178;
  local_c040 = 0;
  local_c060[3] = local_c188[3];
  local_c060[2] = local_c188[2];
  local_c084 = 0;
  local_9e5c = 0;
  local_bf14 = 0;
  local_9ec4 = 0;
  local_9e9c[0] = 0;
  local_9e9c[1] = 0;
  local_9e9c[2] = 0;
  local_9e9c[3] = 0;
  local_9e78 = 0;
  local_9e74 = 0;
  local_9e70 = 0;
  local_9e6c = 0;
  local_9e80 = 0;
  local_9e68 = 0;
  local_9e64 = 0;
  local_9e60 = 0;
  local_c060[1] = local_c188[1];
  local_c060[0] = local_c188[0];
  puVar31 = local_bf04;
  iVar42 = 8;
  do {
    *puVar31 = 0;
    puVar31[0x408] = 0;
    puVar31 = puVar31 + 1;
    iVar42 = iVar42 + -1;
  } while (iVar42 != 0);
  local_80 = local_9e54;
  iVar42 = 0x10;
  piVar12 = local_80;
  do {
    *piVar12 = 0;
    piVar12[0x10] = 0;
    piVar12 = piVar12 + 1;
    iVar42 = iVar42 + -1;
  } while (iVar42 != 0);
  iVar42 = 0;
  iVar23 = 0;
  uVar21 = 0;
  puVar31 = puVar36;
switchD_000cb23c_caseD_15:
  local_c1f8 = puVar31 + 2;
  puVar15 = local_c1f8;
switchD_000cb23c_caseD_18:
  puVar31 = puVar15;
  if (puVar31 < puVar36 + iVar11) goto code_r0x000cb214;
  if (local_9ec4 != 0) {
    puVar31 = (uint *)0x0;
    uVar17 = 0;
    goto LAB_000cc88c;
  }
  iVar42 = (iVar11 + iVar42) * 4;
  local_c03c = local_c08c;
  if (local_c040 != 0) {
    iVar42 = iVar42 + 0x48;
  }
  uVar17 = iVar42 + iVar23 * 4;
  bVar5 = local_9ebc != 0;
  if (bVar5) {
    uVar17 = uVar17 + 0x14;
  }
  uVar10 = uVar17;
  if ((local_9e9c[0] != 0) && (uVar10 = uVar17 + 0xc, bVar5)) {
    uVar10 = uVar17 + 0x24;
  }
  uVar17 = uVar10;
  if ((local_9e9c[1] != 0) && (uVar17 = uVar10 + 0xc, bVar5)) {
    uVar17 = uVar10 + 0x24;
  }
  uVar10 = uVar17;
  if ((local_9e9c[2] != 0) && (uVar10 = uVar17 + 0xc, bVar5)) {
    uVar10 = uVar17 + 0x24;
  }
  uVar24 = uVar10;
  if ((local_9e9c[3] != 0) && (uVar24 = uVar10 + 0xc, bVar5)) {
    uVar24 = uVar10 + 0x24;
  }
  if (((local_9e80 != 0) && (local_9e88 != 0)) && (local_9e58 == 0)) {
    uVar24 = uVar24 + 0x14;
  }
  if (local_9d90 == 1) {
    uVar24 = uVar24 + 0x24;
  }
  else if (local_9d90 == 2) {
    uVar24 = uVar24 + 0x30;
  }
  else if (local_9d90 == 3) {
    uVar24 = uVar24 + 0x40;
  }
  else if (local_9d90 == 0) goto LAB_000cbb64;
  uVar24 = uVar24 + 8;
  piVar12 = local_9e9c;
  iVar42 = 4;
  do {
    if (*piVar12 != 0) {
      uVar24 = uVar24 + 0x2c;
    }
    piVar12 = piVar12 + 1;
    iVar42 = iVar42 + -1;
  } while (iVar42 != 0);
LAB_000cbb64:
  if (((local_9e74 != 0) || (local_9e6c != 0)) || (uVar17 = uVar24, local_9e58 == 0)) {
    if ((local_9e78 == 0) && (local_9e70 != 0)) {
      uVar24 = uVar24 + 0xc;
    }
    uVar17 = uVar24;
    if ((local_9e58 == 0) && (uVar17 = uVar24 + 0xc, local_9d7c != 0)) {
      uVar17 = uVar24 + 0x18;
    }
  }
  bVar5 = true;
  puVar31 = _malloc(uVar17 + 0x10);
  *puVar31 = *puVar36;
  local_c1f8 = puVar36 + 2;
  puVar31[1] = puVar36[1];
  puVar19 = local_c1f8;
  puVar15 = puVar31 + 2;
  goto switchD_000cbc48_caseD_18;
code_r0x000cb214:
  uVar17 = *puVar31;
  puVar15 = puVar31;
  switch(uVar17 & 0xffff) {
  default:
    goto switchD_000cb23c_caseD_0;
  case 1:
  case 2:
  case 4:
  case 5:
  case 0xb:
  case 0xe:
  case 0x12:
  case 0x1e:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
  case 0x33:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x47:
  case 0x48:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x50:
  case 0x51:
  case 0x54:
  case 0x55:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5c:
  case 0x62:
  case 99:
    uVar26 = 1;
    break;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    uVar26 = 1;
    goto LAB_000cb4b0;
  case 6:
  case 0x10:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_c1f8 = puVar31 + 1;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    uVar26 = 0;
LAB_000cb4b0:
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar31,uVar26,2,&local_c08c);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 8:
  case 0x32:
    local_c1f8 = puVar31 + 2;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 9:
  case 0x1d:
    local_c1f8 = puVar31 + 3;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar31,1,3,&local_c08c);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0xf:
    local_c1f8 = puVar31 + *(ushort *)((int)puVar31 + 6) + 2;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x14:
    local_c1f8 = puVar31 + 3;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x15:
    goto switchD_000cb23c_caseD_15;
  case 0x16:
    local_c1f8 = puVar31 + 1;
    uVar10 = puVar31[1];
    uVar17 = uVar10 & 0x3f0000;
    ((int (*)())FUN_000c8600)(uVar10 & 0xffff,uVar10 >> 0x10 & 0x3f,&local_c08c,0,0);
    if (uVar17 == 0x160000) {
      local_c040 = 1;
    }
    else if (uVar17 == 0x110000) {
      local_c084 = 1 << (uVar10 & 0x3f) | local_c084;
    }
    else if (uVar17 == 0xf0000) {
      uVar21 = uVar21 | 1 << (uVar10 & 0x3f);
    }
    else if (uVar17 == 0x100000) {
      local_c028 = 1;
    }
    goto LAB_000cb6d4;
  case 0x18:
    goto switchD_000cb23c_caseD_18;
  case 0x19:
    uVar24 = uVar17 >> 0x1b & 3;
    uVar10 = uVar17 >> 0x10 & 0xff;
    if ((uVar24 == 2) || ((uVar24 == 0 && (local_9dd4[uVar10] == 2)))) {
      local_bf14 = 1 << (uVar17 >> 0x10 & 0x3f) | local_bf14;
    }
    ((int (*)())FUN_000c7270)(&local_c08c,uVar10,uVar17 >> 0x18 & 7);
    local_c1f8 = local_c1f8 + 1;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x1a:
    local_c1f8 = puVar31 + 1;
    if ((int)uVar17 < 0) {
      local_c1f8 = puVar31 + 2;
    }
LAB_000cb6d4:
    local_c1f8 = local_c1f8 + 1;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x1c:
    local_c1f8 = puVar31 + 1;
    uVar10 = puVar31[1];
    uVar17 = uVar10 >> 0x10 & 0x3f;
    if (uVar17 == 1) {
      local_c1a8 = puVar31[2];
      local_c1a4 = puVar31[3];
      local_c1a0 = puVar31[4];
      local_c1f8 = puVar31 + 6;
      local_c19c = puVar31[5];
      ((int (*)())FUN_000c7290)(&local_c08c,uVar10 & 0xffff,&local_c1a8);
      puVar15 = local_c1f8;
    }
    else {
      puVar15 = local_c1f8;
      if (uVar17 == 2) {
        local_c1a8 = puVar31[2];
        local_c1a4 = puVar31[3];
        local_c1a0 = puVar31[4];
        local_c1f8 = puVar31 + 6;
        local_c19c = puVar31[5];
        ((int (*)())FUN_000c72f0)(&local_c08c,uVar10 & 0xffff,&local_c1a8);
        puVar15 = local_c1f8;
      }
    }
    goto switchD_000cb23c_caseD_18;
  case 0x24:
    iVar42 = iVar42 + 5;
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar31,1,2,&local_c08c);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x35:
    local_c1f8 = puVar31 + 2;
    local_c1c0[0] = puVar31[1];
    ((int (*)())FUN_000c87d0)(local_c1c0,auStack_c1b4,&local_c08c);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x37:
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar31,0,1,&local_c08c);
    local_9e60 = 1;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x3e:
    uVar26 = 0;
    break;
  case 0x5d:
    local_c1f8 = puVar31 + 2;
    local_9d6c = local_9d6c + 1;
    uVar17 = puVar31[1];
    uVar10 = *puVar31;
    if ((((uVar10 & 0xc000000) == 0x4000000) ||
        (((uVar10 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_c018) != 0)))) &&
       (local_c01c << (*(byte *)((int)puVar31 + 1) & 0x3f) != 0)) {
      iVar23 = iVar23 + 0x1b;
      local_c018 = 1 << (*(byte *)((int)puVar31 + 1) & 0x3f) | local_c018;
      uVar10 = *puVar31;
    }
    if ((int)uVar10 < 0) {
      local_c1f8 = puVar31 + 3;
      uVar10 = *puVar31;
    }
    if ((uVar10 & 0x40000000) != 0) {
      local_c1f8 = local_c1f8 + 1;
    }
    if ((uVar17 & 0x400000) != 0) {
      unaff_r20 = *local_c1f8;
      local_c1f8 = local_c1f8 + 1;
    }
    local_88 = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar17 & 0xffff,uVar17 >> 0x10 & 0x3f,local_88,unaff_r20,uVar17 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_c01c) != 0) {
      iVar23 = iVar23 + 4;
    }
    local_c1e4 = *local_c1f8;
    puVar31 = local_c1f8 + 1;
    if ((local_c1e4 & 0x400000) != 0) {
      local_c1f0 = local_c1f8[1];
      puVar31 = local_c1f8 + 2;
    }
    local_c1f8 = puVar31;
    ((int (*)())FUN_000c87d0)(&local_c1e4,&local_c1f0,local_88);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x5e:
    local_c1f8 = puVar31 + 2;
    local_9d6c = local_9d6c + 1;
    uVar17 = puVar31[1];
    uVar10 = *puVar31;
    if ((((uVar10 & 0xc000000) == 0x4000000) ||
        (((uVar10 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_c018) != 0)))) &&
       (local_c01c << (*(byte *)((int)puVar31 + 1) & 0x3f) != 0)) {
      iVar23 = iVar23 + 0x1b;
      local_c018 = 1 << (*(byte *)((int)puVar31 + 1) & 0x3f) | local_c018;
      uVar10 = *puVar31;
    }
    if ((int)uVar10 < 0) {
      local_c1f8 = puVar31 + 3;
      uVar10 = *puVar31;
    }
    if ((uVar10 & 0x40000000) != 0) {
      local_c1f8 = local_c1f8 + 1;
    }
    if ((uVar17 & 0x400000) != 0) {
      unaff_r19 = *local_c1f8;
      local_c1f8 = local_c1f8 + 1;
    }
    local_88 = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar17 & 0xffff,uVar17 >> 0x10 & 0x3f,local_88,unaff_r19,uVar17 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_c01c) != 0) {
      iVar23 = iVar23 + 4;
    }
    local_c1f0 = *local_c1f8;
    puVar31 = local_c1f8 + 1;
    if ((local_c1f0 & 0x400000) != 0) {
      local_c1e4 = local_c1f8[1];
      puVar31 = local_c1f8 + 2;
    }
    local_c1ec[0] = *puVar31;
    local_c1f8 = puVar31 + 1;
    if ((local_c1ec[0] & 0x400000) != 0) {
      local_c1e0[0] = puVar31[1];
      local_c1f8 = puVar31 + 2;
    }
    ((int (*)())FUN_000c87d0)(&local_c1f0,&local_c1e4,local_88);
    ((int (*)())FUN_000c87d0)(local_c1ec,local_c1e0,local_88);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  }
  local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar31,uVar26,1,&local_c08c);
  puVar15 = local_c1f8;
  goto switchD_000cb23c_caseD_18;
switchD_000cbc48_caseD_18:
  local_c1f4 = puVar15;
  puVar18 = puVar19;
  if (puVar36 + iVar11 <= puVar18) {
    uVar17 = uVar17 >> 2;
    local_c084 = uVar21 | local_c084;
LAB_000cc88c:
    if (local_9ec4 != 0) {
      _free(puVar31);
      return local_9ec4;
    }
    if ((local_c040 == 0) || (local_c02c == 0x11)) {
      *(undefined1 *)(param_2 + 0x7a6) = 0;
      *(undefined1 *)((int)param_2 + 0x1e2f) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x7a6) = 1;
      *(undefined1 *)((int)param_2 + 0x1e2f) = 1;
      param_2[0x7a4] = local_c02c + 2;
      param_3[0x2e] = local_c034 + param_2[0x7c7];
      param_3[0x2f] = local_c030 + param_2[0x7c7];
    }
    if ((local_c028 == 0) || (local_c024 == 0x11)) {
      *(undefined1 *)((int)param_2 + 0x1e2e) = 0;
    }
    else {
      param_2[0x7a3] = local_c024 + 2;
      *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
    }
    if (local_9d90 == 0) {
      *(undefined1 *)(param_2 + 0x7a8) = 0;
    }
    else {
      param_2[0x7a3] = local_c020;
      param_3[0x38] = local_9d88 + param_2[0x7c7];
      param_3[0x39] = local_9d84 + param_2[0x7c7];
      *(undefined1 *)(param_2 + 0x7a8) = 1;
    }
    if (local_9e64 == 0) {
      *(undefined1 *)((int)param_2 + 0x1efd) = 0;
    }
    else {
      *(undefined1 *)((int)param_2 + 0x1efd) = 1;
    }
    if (local_9e60 == 0) {
      *(undefined1 *)(param_2 + 0x7c1) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x7c1) = 1;
    }
    iVar11 = 8;
    uVar21 = 0;
    piVar25 = param_3 + 0x2c;
    piVar12 = param_3;
    do {
      if ((1 << (uVar21 & 0x3f) & local_c084) == 0) {
        *(undefined1 *)(piVar12 + 0x2c) = 0;
      }
      else if ((local_c040 == 0) || (local_c02c != uVar21)) {
        *(undefined1 *)(piVar12 + 0x2c) = 1;
      }
      else {
        *(undefined1 *)piVar25 = 0;
      }
      uVar21 = uVar21 + 1;
      piVar25 = (int *)((int)piVar25 + 1);
      piVar12 = (int *)((int)piVar12 + 1);
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    param_2[0x7a9] = 0;
    param_3[0x36] = 0;
    uVar21 = 0;
    iVar11 = 0x10;
    *(undefined4 *)(((unsigned char *)0x000010e0) + *param_3) = local_bfd4;
    piVar12 = local_80;
    piVar25 = param_2;
    piVar29 = param_2;
    do {
      uVar10 = 1 << (uVar21 & 0x3f);
      if ((uVar10 & local_bf14) == 0) {
        *(undefined1 *)(piVar29 + 0x582) = 0;
      }
      else {
        *(undefined1 *)(piVar29 + 0x582) = 1;
      }
      if ((uVar10 & local_c01c) == 0) {
        *(undefined1 *)(piVar29 + 0x586) = 0;
      }
      else {
        *(undefined1 *)(piVar29 + 0x586) = 1;
        param_2[0x7a9] = 1;
        piVar25[0x7aa] = piVar12[-0x860] + param_2[0x7c7];
      }
      uVar21 = uVar21 + 1;
      piVar25[0x572] = *piVar12;
      piVar25 = piVar25 + 1;
      piVar2 = piVar12 + 0x10;
      piVar12 = piVar12 + 1;
      *(char *)(piVar29 + 0x56e) = (char)*piVar2;
      fVar9 = FLOAT_001aa0e8;
      piVar29 = (int *)((int)piVar29 + 1);
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    iVar11 = 0;
    piVar12 = param_2;
    piVar25 = param_2;
    do {
      if (((!bVar3) && (*(char *)(piVar25 + 0x586) != '\0')) &&
         (iVar42 = *(int *)(((unsigned char *)0x000013f8) + iVar11 * 4 + *param_2), iVar42 != 0)) {
        ((void (*)())FUN_000c8e30)((double)(fVar9 / *(float *)(iVar42 + 0x44)),
                     (double)(fVar9 / *(float *)(iVar42 + 0x48)),(double)*(float *)(iVar42 + 0x50),
                     (double)FLOAT_001aa0e8,*param_3,
                     (param_3[0x36] - param_2[0x7c7]) + piVar12[0x7aa]);
      }
      bVar5 = iVar11 != 0xf;
      piVar12 = piVar12 + 1;
      piVar25 = (int *)((int)piVar25 + 1);
      iVar11 = iVar11 + 1;
    } while (bVar5);
    local_88 = &local_c08c;
    iVar11 = 0;
    puVar36 = local_aee4;
    puVar34 = auStack_beec;
    puVar32 = auStack_aecc;
    do {
      puVar41 = (undefined4 *)(puVar32 + 8);
      pfVar38 = (float *)(puVar34 + 8);
      uVar21 = 0;
      iVar42 = iVar11 << 2;
      do {
        uVar10 = 1 << (uVar21 & 0x3f);
        if ((uVar10 & puVar36[-0x408]) != 0) {
          ((void (*)())FUN_000c8e30)((double)*pfVar38,(double)pfVar38[1],(double)pfVar38[2],(double)pfVar38[3],
                       *param_3,iVar11 + uVar21);
        }
        if ((uVar10 & *puVar36) != 0) {
          uVar30 = puVar41[1];
          uVar26 = *puVar41;
          iVar23 = iVar42 + *param_3;
          ((unsigned char *)0x000036c9)[iVar23] = (char)puVar41[2];
          ((unsigned char *)0x000036cb)[iVar23] = (char)uVar26;
          ((unsigned char *)0x000036ca)[iVar23] = (char)uVar30;
        }
        bVar3 = uVar21 != 0x1f;
        iVar42 = iVar42 + 4;
        puVar41 = puVar41 + 4;
        pfVar38 = pfVar38 + 4;
        uVar21 = uVar21 + 1;
      } while (bVar3);
      bVar3 = iVar11 != 0xe0;
      puVar32 = puVar32 + 0x200;
      puVar34 = puVar34 + 0x200;
      puVar36 = puVar36 + 1;
      iVar11 = iVar11 + 0x20;
    } while (bVar3);
    *(uint *)(((unsigned char *)0x00003748) + *param_3) = local_aee4[0];
    _memset(auStack_c148,0,0xbc);
    _memset(auStack_9d1c,0,0x9c88);
    pvVar16 = _malloc(param_5[1]);
    if (pvVar16 == (void *)0x0) {
      return -1;
    }
    _memset(pvVar16,0,param_5[1]);
    local_c0f8 = uVar17 << 2;
    puVar15 = local_c080;
    puVar36 = local_c0f0;
    iVar11 = 8;
    local_c090 = pvVar16;
    do {
      uVar21 = *puVar15;
      uVar17 = puVar15[8];
      puVar15 = puVar15 + 1;
      *puVar36 = uVar21;
      puVar36[8] = uVar17;
      puVar36 = puVar36 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    local_c100 = local_c198;
    local_9cd4 = 0x40;
    local_c198[0] = local_c198[0] & 0x403fffff | 0x62000000;
    local_c0fc = puVar31;
    local_9cbc = _malloc(0x900);
    iVar11 = ((int (*)())FUN_000cd1b0)(*param_5,auStack_c148,auStack_9d1c);
    if (iVar11 != 0) {
      return 2;
    }
    iVar11 = 0;
    puVar32 = auStack_96d0;
    do {
      _memcpy((void *)(param_3[3] + iVar11),puVar32,0x48);
      iVar42 = iVar11 + param_3[3];
      if ((*(int *)(iVar11 + param_3[3]) == 1) && (*(char *)(iVar42 + 8) == '\x0f')) {
        *(char *)(iVar42 + 8) = (char)local_c024;
      }
      iVar11 = iVar11 + 0x48;
      puVar32 = puVar32 + 0x48;
    } while (iVar11 != 0x9360);
    iVar23 = 0;
    iVar11 = 0;
    iVar42 = 0;
    iVar40 = 0x1a20;
    piVar12 = param_2 + 0x594;
    do {
      uVar21 = *(uint *)((int)local_9c84 + iVar11) | *(uint *)((int)local_88 + iVar11 + 0x188);
      *(uint *)(((unsigned char *)0x000010b8) + iVar23 * 4 + *param_3) = uVar21;
      if (uVar21 != 0) {
        iVar20 = param_2[0x7c7];
        pbVar22 = (byte *)(piVar12 + 2);
        piVar25 = (int *)((int)param_2 + iVar40);
        iVar27 = iVar42;
        do {
          bVar7 = (byte)uVar21;
          uVar21 = uVar21 >> 1;
          iVar13 = iVar27 + iVar20;
          *pbVar22 = bVar7 & 1;
          iVar27 = iVar27 + 1;
          pbVar22 = pbVar22 + 1;
          *piVar25 = iVar13;
          piVar25 = piVar25 + 1;
        } while (uVar21 != 0);
      }
      bVar3 = iVar23 != 7;
      iVar11 = iVar11 + 4;
      iVar42 = iVar42 + 0x20;
      piVar12 = piVar12 + 8;
      iVar40 = iVar40 + 0x80;
      iVar23 = iVar23 + 1;
    } while (bVar3);
    if (*(int *)(((unsigned char *)0x000010b8) + *param_3) == 0) {
      *(undefined4 *)(((unsigned char *)0x000010d8) + *param_3) = 0;
    }
    for (; iStack_318 != 0; iStack_318 = iStack_318 + -1) {
    }
    if (local_9cc8 != 0) {
      uVar17 = 0;
      uVar21 = local_9cc8;
      do {
        piVar12 = (int *)(uVar17 * 0x24 + (int)local_9cbc);
        switch(piVar12[2]) {
        case 1:
          iVar11 = piVar12[1];
          iVar42 = *param_3;
          iVar23 = *piVar12;
          if (iVar11 == 1) {
            piVar25 = (int *)(iVar23 * 0x10 + iVar42 + 0x90);
          }
          else if (iVar11 == 0) {
            piVar25 = (int *)(iVar23 * 0x10 + iVar42 + 0x8c);
          }
          else if (iVar11 == 2) {
            piVar25 = (int *)(iVar23 * 0x10 + iVar42 + 0x94);
          }
          else {
            piVar25 = (int *)0x0;
            if (iVar11 == 3) {
              piVar25 = (int *)(iVar23 * 0x10 + iVar42 + 0x98);
            }
          }
          *piVar25 = piVar12[5];
          uVar21 = local_9cc8;
          break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
          ((int (*)())FUN_000c8de0)(param_3 + 0x48);
          uVar21 = local_9cc8;
        }
        uVar17 = uVar17 + 1;
      } while (uVar17 < uVar21);
    }
    if (local_9c18 != 0) {
      iVar11 = 0;
      pcVar28 = local_9c14;
      if (local_9c18 == 0) {
        local_9c18 = 1;
      }
      do {
        cVar6 = *pcVar28;
        pcVar28 = pcVar28 + 0xc;
        if (cVar6 != '\x02') {
          iVar11 = iVar11 + 1;
        }
        if (cVar6 == '\x04') {
          *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
          param_2[0x7a3] = local_c024 + 2;
        }
        local_9c18 = local_9c18 + -1;
      } while (local_9c18 != 0);
      iVar42 = 1;
      if (8 < iVar11) goto LAB_000ccf90;
    }
    iVar42 = 0;
LAB_000ccf90:
    iVar11 = 0;
    iVar23 = 0x10;
    do {
      iVar40 = iVar11 * 0x10;
      iVar11 = iVar11 + 1;
      *(undefined4 *)(iVar40 + param_3[1] + 0x108) = 0;
      *(undefined4 *)(iVar40 + param_3[1] + 0x10c) = 1;
      *(undefined4 *)(iVar40 + param_3[1] + 0x110) = 2;
      *(undefined4 *)(iVar40 + param_3[1] + 0x114) = 3;
      iVar23 = iVar23 + -1;
    } while (iVar23 != 0);
    _free(local_9cbc);
    _free(pvVar16);
    if (pvVar14 != (void *)0x0) {
      _free(pvVar14);
    }
    if (puVar31 != (uint *)0x0) {
      _free(puVar31);
    }
    return iVar42;
  }
  uVar10 = *puVar18;
  puVar19 = puVar18;
  puVar15 = local_c1f4;
  switch(uVar10 & 0xffff) {
  default:
    goto switchD_000cb23c_caseD_0;
  case 1:
  case 2:
  case 4:
  case 5:
  case 0xb:
  case 0xe:
  case 0x12:
  case 0x1e:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
  case 0x33:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3c:
  case 0x3d:
  case 0x47:
  case 0x48:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x50:
  case 0x51:
  case 0x54:
  case 0x55:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5c:
  case 0x62:
  case 99:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *)((int (*)())FUN_000c8110)(local_c1f4,local_88);
    }
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,1,local_88);
    puVar19 = local_c1f8;
    puVar15 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *)((int (*)())FUN_000c8110)(local_c1f4,local_88);
    }
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,2,local_88);
    puVar19 = local_c1f8;
    puVar15 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_c1f8 = puVar18 + 1;
    *local_c1f4 = uVar10;
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,0,2,&local_c08c);
    puVar19 = local_c1f8;
    puVar15 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *local_c1f4 = uVar10;
    local_c1f8 = puVar18 + 2;
    local_c1f4[1] = puVar18[1];
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 2;
    goto switchD_000cbc48_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *local_c1f4 = uVar10;
    local_c1f4[1] = puVar18[1];
    local_c1f8 = puVar18 + 3;
    local_c1f4[2] = puVar18[2];
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 3;
    goto switchD_000cbc48_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *)((int (*)())FUN_000c8110)(local_c1f4,local_88);
    }
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,3,local_88);
    puVar19 = local_c1f8;
    puVar15 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 0xf:
    local_c1f8 = puVar18 + 2;
    *local_c1f4 = uVar10;
    local_c1f4[1] = puVar18[1];
    puVar15 = local_c1f4 + 2;
    for (uVar10 = (uint)*(ushort *)((int)puVar18 + 6); puVar19 = local_c1f8, uVar10 != 0;
        uVar10 = uVar10 - 1) {
      uVar24 = *local_c1f8;
      local_c1f8 = local_c1f8 + 1;
      *puVar15 = uVar24;
      puVar15 = puVar15 + 1;
    }
  case 0x18:
    goto switchD_000cbc48_caseD_18;
  case 0x19:
    local_c1f8 = puVar18 + 1;
    if ((uVar10 & 0x18000000) == 0) {
      uVar24 = *(uint *)((int)local_9dd4 + (uVar10 >> 0xe & 0x3fc));
      if (uVar24 != 2) {
        uVar24 = 1;
      }
      uVar10 = (uVar24 & 3) << 0x1b | uVar10 & 0xe7ffffff;
    }
    *local_c1f4 = uVar10;
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1a:
    local_c1f8 = puVar18 + 1;
    *local_c1f4 = uVar10;
    puVar15 = local_c1f4 + 1;
    if ((int)uVar10 < 0) {
      uVar10 = *local_c1f8;
      local_c1f8 = puVar18 + 2;
      local_c1f4[1] = uVar10;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    uVar10 = *local_c1f8;
    local_c1f8 = local_c1f8 + 1;
    *local_c1f4 = uVar10;
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1c:
    local_c1f8 = puVar18 + 1;
    *local_c1f4 = uVar10;
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 1;
    if ((puVar18[1] >> 0x10 & 0x3f) - 1 < 2) {
      local_c1f4[1] = puVar18[1];
      local_c1f4[2] = puVar18[2];
      local_c1f4[3] = puVar18[3];
      local_c1f4[4] = puVar18[4];
      local_c1f8 = puVar18 + 6;
      local_c1f4[5] = puVar18[5];
      puVar19 = local_c1f8;
      puVar15 = local_c1f4 + 6;
    }
    goto switchD_000cbc48_caseD_18;
  case 0x28:
    local_c1f8 = puVar18 + 1;
    puVar15 = (uint *)((int (*)())FUN_000c7930)(local_c1f4,&local_c08c);
    *puVar15 = uVar10;
    puVar19 = local_c1f8;
    puVar15 = puVar15 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x35:
    *local_c1f4 = uVar10;
    local_c1f8 = puVar18 + 2;
    local_c1c0[0] = puVar18[1];
    local_c1f4 = local_c1f4 + 1;
    ((int (*)())FUN_000c8760)(local_c1c0,auStack_c1b4,&local_c08c);
    *local_c1f4 = local_c1c0[0];
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x37:
  case 0x3e:
    uVar26 = 0;
    break;
  case 0x3b:
    uVar26 = 1;
    break;
  case 0x5d:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *)((int (*)())FUN_000c8110)(local_c1f4,local_88);
      puVar18 = local_c1f8;
    }
    uVar37 = *puVar18;
    puVar15 = puVar18 + 1;
    uVar10 = uVar37 >> 0x10;
    uVar24 = uVar10 & 0xff;
    bVar4 = (uVar37 & 0x80000000) != 0;
    if (bVar4) {
      puVar15 = puVar18 + 2;
      uVar33 = puVar18[1];
    }
    else {
      uVar33 = 0;
    }
    bVar1 = (uVar37 >> 0x1e & 1) != 0;
    if (bVar1) {
      uVar35 = *puVar15;
      puVar15 = puVar15 + 1;
    }
    else {
      uVar35 = 0;
    }
    local_c1f0 = *puVar15;
    puVar19 = puVar15 + 1;
    if ((local_c1f0 & 0x400000) != 0) {
      puVar19 = puVar15 + 2;
      unaff_r15 = puVar15[1];
    }
    local_c1cc = *puVar19;
    local_c1f8 = puVar19 + 1;
    if ((local_c1cc & 0x400000) != 0) {
      local_c1d8 = puVar19[1];
      local_c1f8 = puVar19 + 2;
    }
    uVar8 = uVar37 & 0xc000000;
    if (uVar8 == 0x4000000) {
LAB_000cc2a4:
      if (local_c01c << (uVar10 & 0x3f) == 0) {
        local_84 = &local_c1cc;
        uVar26 = 0;
        uVar39 = 1 << (uVar10 & 0x3f);
        puVar15 = &local_c1d8;
      }
      else {
        local_84 = &local_c1cc;
        local_70 = &local_c1d8;
        local_c1f4 = (uint *)((int (*)())FUN_000c7460)(local_88,local_84,local_70,uVar24,local_c1f4);
        puVar15 = local_70;
        if ((local_c1f0 & 0x400000) == 0) {
          uVar26 = 0;
          uVar39 = 1 << (uVar10 & 0x3f);
        }
        else {
          local_c1f0 = local_c1f0 & 0xffbfffff;
          uVar26 = 1;
          uVar39 = 1 << (uVar10 & 0x3f);
          local_c1e4 = unaff_r15;
        }
      }
    }
    else if (uVar8 == 0x8000000) {
      uVar39 = 1 << (uVar10 & 0x3f);
      if ((uVar39 & local_c018) != 0) goto LAB_000cc2a4;
      local_84 = &local_c1cc;
      uVar26 = 0;
      puVar15 = &local_c1d8;
    }
    else {
      uVar26 = 0;
      uVar39 = 1 << (uVar10 & 0x3f);
      local_84 = &local_c1cc;
      puVar15 = &local_c1d8;
    }
    ((int (*)())FUN_000c8760)(local_84,puVar15,local_88);
    *local_c1f4 = uVar37;
    puVar15 = local_c1f4 + 1;
    if (bVar4) {
      local_c1f4[1] = uVar33;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    if (bVar1) {
      *local_c1f4 = uVar35;
      local_c1f4 = local_c1f4 + 1;
    }
    *local_c1f4 = local_c1f0;
    puVar15 = local_c1f4 + 1;
    if ((local_c1f0 & 0x400000) != 0) {
      local_c1f4[1] = unaff_r15;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    *local_c1f4 = local_c1cc;
    puVar15 = local_c1f4 + 1;
    if ((local_c1cc & 0x400000) != 0) {
      local_c1f4[1] = local_c1d8;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    if (((uVar8 == 0x4000000) || ((uVar8 == 0x8000000 && ((uVar39 & local_c018) != 0)))) &&
       (local_c01c << (uVar10 & 0x3f) != 0)) {
      local_c1f4 = (uint *)((int (*)())FUN_000c7650)(local_88,local_84,&local_c1f0,&local_c1e4,uVar24,uVar26,
                                        local_c1f4);
    }
    uVar39 = uVar39 & local_c01c;
    uVar10 = unaff_r15;
    goto joined_r0x000cc708;
  case 0x5e:
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *)((int (*)())FUN_000c8110)(local_c1f4,&local_c08c);
      puVar18 = local_c1f8;
    }
    uVar37 = *puVar18;
    puVar15 = puVar18 + 1;
    uVar10 = uVar37 >> 0x10;
    uVar24 = uVar10 & 0xff;
    bVar4 = (uVar37 & 0x80000000) != 0;
    if (bVar4) {
      puVar15 = puVar18 + 2;
      uVar33 = puVar18[1];
    }
    else {
      uVar33 = 0;
    }
    bVar1 = (uVar37 & 0x40000000) != 0;
    if (bVar1) {
      uVar35 = *puVar15;
      puVar15 = puVar15 + 1;
    }
    else {
      uVar35 = 0;
    }
    local_c1f0 = *puVar15;
    puVar19 = puVar15 + 1;
    if ((local_c1f0 & 0x400000) != 0) {
      puVar19 = puVar15 + 2;
      unaff_r14 = puVar15[1];
    }
    local_c1d8 = *puVar19;
    puVar15 = puVar19 + 1;
    if ((local_c1d8 & 0x400000) != 0) {
      local_c1cc = puVar19[1];
      puVar15 = puVar19 + 2;
    }
    local_c1d4 = *puVar15;
    local_c1f8 = puVar15 + 1;
    if ((local_c1d4 & 0x400000) != 0) {
      local_c1c8 = puVar15[1];
      local_c1f8 = puVar15 + 2;
    }
    uVar8 = uVar37 & 0xc000000;
    if (uVar8 == 0x4000000) {
LAB_000cc588:
      if ((local_c01c << (uVar10 & 0x3f) == 0) ||
         (local_c1f4 = (uint *)((int (*)())FUN_000c7460)(&local_c08c,&local_c1d8,&local_c1cc,uVar24,local_c1f4),
         (local_c1f0 & 0x400000) == 0)) {
LAB_000cc5bc:
        uVar26 = 0;
        uVar39 = 1 << (uVar10 & 0x3f);
      }
      else {
        local_c1f0 = local_c1f0 & 0xffbfffff;
        uVar26 = 1;
        uVar39 = 1 << (uVar10 & 0x3f);
        local_c1e4 = unaff_r14;
      }
    }
    else {
      if (uVar8 != 0x8000000) goto LAB_000cc5bc;
      uVar26 = 0;
      uVar39 = 1 << (uVar10 & 0x3f);
      if ((uVar39 & local_c018) != 0) goto LAB_000cc588;
    }
    *local_c1f4 = uVar37;
    puVar15 = local_c1f4 + 1;
    if (bVar4) {
      local_c1f4[1] = uVar33;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    if (bVar1) {
      *local_c1f4 = uVar35;
      local_c1f4 = local_c1f4 + 1;
    }
    *local_c1f4 = local_c1f0;
    puVar15 = local_c1f4 + 1;
    if ((local_c1f0 & 0x400000) != 0) {
      local_c1f4[1] = unaff_r14;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    *local_c1f4 = local_c1d8;
    puVar15 = local_c1f4 + 1;
    if ((local_c1d8 & 0x400000) != 0) {
      local_c1f4[1] = local_c1cc;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    *local_c1f4 = local_c1d4;
    puVar15 = local_c1f4 + 1;
    if ((local_c1d4 & 0x400000) != 0) {
      local_c1f4[1] = local_c1c8;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    if (((uVar8 == 0x4000000) || ((uVar8 == 0x8000000 && ((uVar39 & local_c018) != 0)))) &&
       (local_c01c << (uVar10 & 0x3f) != 0)) {
      local_c1f4 = (uint *)((int (*)())FUN_000c7650)(&local_c08c,&local_c1d8,&local_c1f0,&local_c1e4,uVar24,
                                        uVar26,local_c1f4);
    }
    uVar39 = uVar39 & local_c01c;
    uVar10 = unaff_r14;
joined_r0x000cc708:
    puVar19 = local_c1f8;
    puVar15 = local_c1f4;
    if (uVar39 != 0) {
      *local_c1f4 = 0x47;
      uVar37 = local_c1f0;
      if ((local_c1f0 & 0x400000) == 0) {
        uVar37 = local_c1f0 | 0x400000;
        uVar10 = 0x55;
      }
      if (local_bf94[uVar24] == 0x1906) {
        if ((uVar10 & 3) == 1) {
          uVar10 = uVar10 & 0xfffffffc | 2;
        }
        if ((uVar10 & 0xc) == 4) {
          uVar10 = uVar10 & 0xfffffff3 | 8;
        }
        if ((uVar10 & 0x30) == 0x10) {
          uVar10 = uVar10 & 0xffffffcf | 0x20;
        }
      }
      else if ((local_bf94[uVar24] == 0x1909) && ((uVar10 & 0xc0) == 0x40)) {
        uVar10 = uVar10 & 0xffffff3f | 0xc0;
      }
      local_c1f4[1] = uVar37;
      local_c1f4[2] = uVar10;
      local_c1f4[3] = uVar37 & 0x3fffff;
      puVar15 = local_c1f4 + 4;
    }
    goto switchD_000cbc48_caseD_18;
  }
  local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,uVar26,1,&local_c08c);
  puVar19 = local_c1f8;
  puVar15 = local_c1f4;
  goto switchD_000cbc48_caseD_18;
switchD_000cb23c_caseD_0:
                    
  _exit(0);
}

/* FUN_000cd05c @ 0xcd05c (244 bytes) */
int FUN_000cd05c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  if ((((((param_1 == 0) || (*(code **)(param_1 + 0x30) == (code *)0x0)) ||
        (*(int *)(param_1 + 0x34) == 0)) ||
       ((*(int *)(param_1 + 0x38) == 0 || (*(int *)(param_1 + 0x40) == 0)))) ||
      ((*(int *)(param_1 + 0x44) == 0 ||
       ((*(int *)(param_1 + 0x48) == 0 || (*(int *)(param_1 + 0x4c) == 0)))))) ||
     ((param_2 == 0 ||
      (iVar1 = (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0x2c),0x44), iVar1 == 0)))) {
    iVar1 = 0;
  }
  else {
    FUN_000da0c0(iVar1,param_1);
    iVar2 = FUN_000da420(iVar1);
    if (iVar2 != 0) {
      FUN_000da458(iVar1,1);
      (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0x2c),iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

/* FUN_000cd1b0 @ 0xcd1b0 (20 bytes) */
int FUN_000cd1b0(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_000da394();
    return uVar1;
  }
  return 3;
}

/* FUN_000cd1ec @ 0xcd1ec (40 bytes) */
int FUN_000cd1ec()
{
  undefined4 in_r6;
  undefined4 uStack00000024;
  
  uStack00000024 = in_r6;
  ((int (*)())FUN_000cd388)();
  return;
}

/* FUN_000cd214 @ 0xcd214 (40 bytes) */
int FUN_000cd214(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uStack00000020;
  
  uStack00000020 = param_3;
  ((int (*)())FUN_000cd404)(param_1,param_2,&STACKARG(0x20));
  return;
}

/* FUN_000cd23c @ 0xcd23c (40 bytes) */
int FUN_000cd23c()
{
  undefined4 in_r7;
  undefined4 uStack00000028;
  
  uStack00000028 = in_r7;
  ((int (*)())FUN_000cdba4)();
  return;
}

/* FUN_000cd264 @ 0xcd264 (40 bytes) */
int FUN_000cd264(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uStack00000020;
  
  uStack00000020 = param_3;
  ((int (*)())FUN_000cdbe4)(param_1,param_2,&STACKARG(0x20));
  return;
}

/* FUN_000cd290 @ 0xcd290 (88 bytes) */
int FUN_000cd290(param_1)
  undefined4 param_1;
{
  switch(param_1) {
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x39:
    return 1;
  case 0x1d:
  case 0x38:
  case 0x3a:
  case 0x3b:
    return 2;
  default:
    return 0;
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    return 3;
  }
}

/* FUN_000cd388 @ 0xcd388 (28 bytes) */
int FUN_000cd388(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  if (param_4 == 0) {
    return;
  }
  if (param_2 == 0) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  FUN_000e06d8();
  return;
}

/* FUN_000cd3a4 @ 0xcd3a4 (96 bytes) */
int FUN_000cd3a4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  (*(code *)*param_2)(param_1,"",param_3,&STACKARG(0x24));
  return;
}

/* FUN_000cd404 @ 0xcd404 (1952 bytes) */
int FUN_000cd404(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_238 [128];
  undefined1 auStack_1b8 [128];
  undefined1 auStack_138 [128];
  undefined1 auStack_b8 [144];
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"; ------------- SC_SRCSHADER Dump ------------------\r\n");
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntVSConst = %d\r\n",param_2[3]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntPSConst = %d\r\n",param_2[4]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntGSConst = %d\r\n",param_2[5]);
  if (((param_2[3] != 0) && (*param_2 != 0)) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer VS Constants"), param_2[3] != 0)
     ) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10 + *param_2;
      uVar4 = uVar5 + 1;
      ((int (*)())FUN_000cd3a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar5,
                   *(undefined4 *)(uVar5 * 0x10 + *param_2),*(undefined4 *)(iVar3 + 4),
                   *(undefined4 *)(iVar3 + 8));
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[3]);
  }
  if ((param_2[4] != 0) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer PS Constants"), param_2[4] != 0)
     ) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10 + param_2[1];
      uVar4 = uVar5 + 1;
      ((int (*)())FUN_000cd3a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar5,
                   *(undefined4 *)(uVar5 * 0x10 + param_2[1]),*(undefined4 *)(iVar3 + 4),
                   *(undefined4 *)(iVar3 + 8));
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[4]);
  }
  if ((param_2[5] != 0) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer GS Constants"), param_2[5] != 0)
     ) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10 + param_2[2];
      uVar4 = uVar5 + 1;
      ((int (*)())FUN_000cd3a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar5,
                   *(undefined4 *)(uVar5 * 0x10 + param_2[2]),*(undefined4 *)(iVar3 + 4),
                   *(undefined4 *)(iVar3 + 8));
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[5]);
  }
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolVSConst = %d\r\n",param_2[9]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolPSConst = %d\r\n",param_2[10]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolGSConst = %d\r\n",param_2[0xb]);
  if (param_2[9] == 0) goto LAB_000cd7d0;
  if (param_2[6] != 0) {
    ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool VS Constants");
    if (param_2[9] == 0) goto LAB_000cd7d0;
    uVar5 = 0;
    do {
      if (*(int *)(uVar5 * 4 + param_2[6]) == 0) {
        pcVar2 = "FALSE";
      }
      else {
        pcVar2 = "TRUE";
      }
      ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar5,pcVar2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)param_2[9]);
    if (param_2[9] == 0) goto LAB_000cd7d0;
  }
  if (param_2[7] != 0) {
    ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool PS Constants");
    if (param_2[10] != 0) {
      uVar5 = 0;
      do {
        if (*(int *)(uVar5 * 4 + param_2[7]) == 0) {
          pcVar2 = "FALSE";
        }
        else {
          pcVar2 = "TRUE";
        }
        ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar5,pcVar2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)param_2[10]);
    }
    if (param_2[9] == 0) goto LAB_000cd7d0;
  }
  if ((param_2[8] != 0) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool GS Constants"), param_2[0xb] != 0))
  {
    uVar5 = 0;
    do {
      if (*(int *)(uVar5 * 4 + param_2[8]) == 0) {
        pcVar2 = "FALSE";
      }
      else {
        pcVar2 = "TRUE";
      }
      ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar5,pcVar2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)param_2[0xb]);
  }
LAB_000cd7d0:
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatVSConst = %d\r\n",param_2[0xf]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatPSConst = %d\r\n",param_2[0x10]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatGSConst = %d\r\n",param_2[0x11]);
  if (((param_2[0xf] != 0) && (param_2[0xc] != 0)) &&
     (uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float VS Constants"),
     param_2[0xf] != 0)) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xc] + iVar3),uVar1,10,auStack_238);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xc] + iVar3 + 4),uVar1,10,auStack_1b8);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xc] + iVar3 + 8),uVar1,10,auStack_138);
      ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xc] + iVar3 + 0xc),uVar1,10,auStack_b8);
      uVar4 = uVar5 + 1;
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar5,
                           auStack_238,auStack_1b8,auStack_138,auStack_b8);
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[0xf]);
  }
  if (((param_2[0x10] != 0) && (param_2[0xd] != 0)) &&
     (uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float PS Constants"),
     param_2[0x10] != 0)) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xd] + iVar3),uVar1,10,auStack_238);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xd] + iVar3 + 4),uVar1,10,auStack_1b8);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xd] + iVar3 + 8),uVar1,10,auStack_138);
      ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xd] + iVar3 + 0xc),uVar1,10,auStack_b8);
      uVar4 = uVar5 + 1;
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar5,
                           auStack_238,auStack_1b8,auStack_138,auStack_b8);
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[0x10]);
  }
  if (((param_2[0x11] != 0) && (param_2[0xe] != 0)) &&
     (uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float GS Constants"),
     param_2[0x11] != 0)) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xe] + iVar3),uVar1,10,auStack_238);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xe] + iVar3 + 4),uVar1,10,auStack_1b8);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xe] + iVar3 + 8),uVar1,10,auStack_138);
      ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xe] + iVar3 + 0xc),uVar1,10,auStack_b8);
      uVar4 = uVar5 + 1;
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar5,
                           auStack_238,auStack_1b8,auStack_138,auStack_b8);
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[0x11]);
  }
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"u32Copts = 0x%08X",param_2[0x15]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"fConstantsAvailable = %d",param_2[0x16],param_2[0x17],param_2[0x18],
               param_2[0x19],param_2[0x1a]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"iConstantsAvailable = %d",param_2[0x1e],param_2[0x1f],param_2[0x20],
               param_2[0x21],param_2[0x22]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"bConstantsAvailable = %d",param_2[0x26],param_2[0x27],param_2[0x28],
               param_2[0x29],param_2[0x2a]);
  return;
}

/* FUN_000cdba4 @ 0xcdba4 (64 bytes) */
int FUN_000cdba4(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  if (param_2 == 0) {
    return;
  }
  if (param_5 == 0) {
    return;
  }
  if (2 < *(int *)(param_2 + 0xfc) - 1U) {
    return;
  }
  if (*(int *)(param_2 + 0xf8) == 0) {
    FUN_000d035c();
    return;
  }
  if (*(int *)(param_2 + 0xf8) != 1) {
    return;
  }
  FUN_000d4e8c();
  return;
}

/* FUN_000cdbe4 @ 0xcdbe4 (60 bytes) */
int FUN_000cdbe4(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  if (param_2 == 0) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  if (2 < *(int *)(param_2 + 0xfc) - 1U) {
    return;
  }
  if (*(int *)(param_2 + 0xf8) == 0) {
    FUN_000d0304();
    return;
  }
  if (*(int *)(param_2 + 0xf8) != 1) {
    return;
  }
  FUN_000d4e64();
  return;
}

/* FUN_000cdc3c @ 0xcdc3c (996 bytes) */
char * FUN_000cdc3c(double param_1,int param_2,int *param_3,char *param_4)

{
  double dVar1;
  double dVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  uint local_98;
  
  pcVar6 = _ecvt(param_1,param_2,param_3,param_3);
  if ((1 - (int)param_3 < 1) && (-1 < (int)param_3)) {
    *param_4 = '0';
    param_4[1] = '.';
    uVar9 = 2;
    if (*pcVar6 != '\0') {
      iVar7 = 0;
      pcVar8 = pcVar6;
      do {
        if (iVar7 == -1) {
          param_4[uVar9] = '.';
          uVar9 = uVar9 + 1;
        }
        iVar7 = iVar7 + 1;
        param_4[uVar9] = *pcVar8;
        uVar9 = uVar9 + 1;
        pcVar8 = pcVar6 + iVar7;
      } while (pcVar6[iVar7] != '\0');
    }
    param_4[uVar9] = '\0';
    cVar5 = *param_4;
    uVar11 = uVar9;
    if (cVar5 != '\0') {
      iVar7 = 0;
      do {
        if (cVar5 != '0') {
          if (cVar5 == '.') {
            uVar11 = uVar9;
            if (iVar7 + 2U < uVar9) {
              uVar11 = iVar7 + 2U;
            }
          }
          else {
            uVar11 = iVar7 + 1;
          }
        }
        iVar7 = iVar7 + 1;
        cVar5 = param_4[iVar7];
      } while (cVar5 != '\0');
    }
    param_4[uVar11] = '\0';
  }
  else {
    *param_4 = *pcVar6;
    param_4[1] = '.';
    iVar7 = 2;
    cVar5 = pcVar6[1];
    if (cVar5 != '\0') {
      pcVar8 = param_4 + 2;
      iVar3 = 1;
      do {
        *pcVar8 = cVar5;
        iVar3 = iVar3 + 1;
        cVar5 = pcVar6[iVar3];
        iVar7 = iVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar5 != '\0');
    }
    param_4[iVar7] = 'e';
    param_4[iVar7 + 1] = '-';
    local_98 = 1;
    dVar12 = (double)_log((double)(float)(4503601774854145.0 - DOUBLE_001aa1e0));
    dVar13 = (double)_log(DOUBLE_001aa238);
    dVar2 = DOUBLE_001aa1e8;
    dVar1 = DOUBLE_001aa1e0;
    dVar12 = dVar12 / dVar13;
    if (DOUBLE_001aa1e8 <= dVar12) {
      uVar9 = (int)(dVar12 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar9 = (uint)dVar12;
    }
    uVar10 = 0;
    pcVar6 = param_4 + iVar7 + 2;
    uVar11 = uVar9;
    do {
      dVar14 = (double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - dVar1;
      dVar13 = (double)_pow(DOUBLE_001aa238,dVar14);
      dVar12 = DOUBLE_001aa238;
      if (dVar2 <= dVar13) {
        uVar4 = (int)(dVar13 - dVar2) + 0x80000000;
      }
      else {
        uVar4 = (uint)dVar13;
      }
      cVar5 = (char)(local_98 / uVar4);
      *pcVar6 = cVar5 + '0';
      dVar12 = (double)_pow(dVar12,dVar14);
      if (DOUBLE_001aa1e8 <= dVar12) {
        iVar3 = (int)(dVar12 - DOUBLE_001aa1e8) + -0x80000000;
      }
      else {
        iVar3 = (int)dVar12;
      }
      uVar10 = uVar10 + 1;
      pcVar6 = pcVar6 + 1;
      uVar11 = uVar11 - 1;
      local_98 = local_98 - cVar5 * iVar3;
    } while (uVar10 <= uVar9);
    param_4[uVar10 + iVar7 + 2] = '\0';
  }
  return param_4;
}

/* FUN_000ce038 @ 0xce038 (24 bytes) */
int FUN_000ce038(param_1)
  undefined4 *param_1;
{
  param_1[3] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

/* FUN_000ce050 @ 0xce050 (248 bytes) */
int FUN_000ce050(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  char cVar1;
  char *pcVar2;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_a4 [152];
  
  if (*(int *)(param_1 + 8) != 0) {
    uStack00000020 = param_3;
    uStack00000024 = param_4;
    uStack00000028 = param_5;
    uStack0000002c = param_6;
    uStack00000030 = param_7;
    uStack00000034 = param_8;
    FUN_001a34d4(acStack_a4,param_2,&STACKARG(0x20));
    pcVar2 = _strchr(acStack_a4,0x3f);
    if (pcVar2 != (char *)0x0) {
      for (; (((cVar1 = *pcVar2, cVar1 == '?' || (cVar1 == ' ')) || (cVar1 == ',')) ||
             (cVar1 == '\t')); pcVar2 = pcVar2 + -1) {
      }
      pcVar2[1] = '\0';
    }
    FUN_001a32d0(acStack_a4,"%s\n",acStack_a4);
    (*(code *)**(undefined4 **)(param_1 + 8))
              (*(undefined4 *)(param_1 + 0xc),"",acStack_a4,&STACKARG(0x20));
  }
  return;
}

/* FUN_000ce148 @ 0xce148 (836 bytes) */
int FUN_000ce148(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
{
  bool bVar1;
  uint uVar2;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char acStack_48 [32];
  
  uVar4 = *param_2;
  uVar2 = uVar4 & 0x1e000000;
  uVar6 = uVar4 & 0xf;
  *param_3 = '\0';
  if (uVar2 == 0x1e000000) {
    uVar5 = 0;
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '-';
    (param_3 + sVar3)[1] = '\0';
  }
  else {
    uVar5 = -uVar2 >> 0x1f;
  }
  if (uVar6 == 1) {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = 'v';
    (param_3 + sVar3)[1] = '\0';
  }
  else if (uVar6 == 0) {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = 'r';
    (param_3 + sVar3)[1] = '\0';
  }
  else if (uVar6 == 2) {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = 'c';
    (param_3 + sVar3)[1] = '\0';
  }
  else if (uVar6 == 3) {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = 't';
    (param_3 + sVar3)[1] = '\0';
  }
  else {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '?';
    (param_3 + sVar3)[1] = '\0';
  }
  FUN_001a32d0(acStack_48,"%d",uVar4 >> 5 & 0xff);
  if ((uVar4 & 0x80000010) == 0) {
    _strcat(param_3,acStack_48);
  }
  else {
    if ((uVar4 & 0x80000010) == 0x10) {
      sVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar3,"[a0",4);
    }
    else {
      sVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar3,"[i0",4);
    }
    switch(uVar4 >> 0x1d & 3) {
    case 0:
      _strcat(param_3,".x");
      break;
    case 1:
      _strcat(param_3,".y");
      break;
    case 2:
      _strcat(param_3,".z");
      break;
    case 3:
      _strcat(param_3,".w");
      break;
    default:
      _strcat(param_3,".?");
    }
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '+';
    (param_3 + sVar3)[1] = '\0';
    _strcat(param_3,acStack_48);
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = ']';
    (param_3 + sVar3)[1] = '\0';
  }
  if (((uVar4 & 0x1ffe000) != 0xd10000) || (uVar5 != 0)) {
    uVar6 = 0;
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '.';
    (param_3 + sVar3)[1] = '\0';
    uVar7 = 0xd;
    do {
      if (((uVar2 & 0x2000000 << (uVar6 & 0x3f)) != 0) && (uVar5 != 0)) {
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = '-';
        (param_3 + sVar3)[1] = '\0';
      }
      switch((uVar4 & 0x1ffe000 & 7 << (uVar7 & 0x3f)) >> (uVar7 & 0x3f)) {
      case 0:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = 'x';
        (param_3 + sVar3)[1] = '\0';
        break;
      case 1:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = 'y';
        (param_3 + sVar3)[1] = '\0';
        break;
      case 2:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = 'z';
        (param_3 + sVar3)[1] = '\0';
        break;
      case 3:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = 'w';
        (param_3 + sVar3)[1] = '\0';
        break;
      case 4:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = '0';
        (param_3 + sVar3)[1] = '\0';
        break;
      case 5:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = '1';
        (param_3 + sVar3)[1] = '\0';
        break;
      default:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = '?';
        (param_3 + sVar3)[1] = '\0';
      }
      bVar1 = uVar6 != 3;
      uVar7 = uVar7 + 3;
      uVar6 = uVar6 + 1;
    } while (bVar1);
  }
  return param_2 + 1;
}

/* FUN_000ce4e4 @ 0xce4e4 (48 bytes) */
int FUN_000ce4e4(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  if ((*param_2 & 1) == 0) {
    return;
  }
  ((int (*)())FUN_000ce050)(param_1,";    v%d = dx v%d",*(undefined1 *)(param_2 + 1),
               *(undefined1 *)((int)param_2 + 1));
  return;
}

/* FUN_000ce514 @ 0xce514 (864 bytes) */
int FUN_000ce514(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  bool bVar1;
  byte bVar2;
  char *acVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  int iVar12;
  char local_218 [12];
  uint local_20c [5];
  char local_1f8 [4];
  char local_1f4;
  char acStack_1f3 [3];
  char local_1f0;
  char acStack_1ef [3];
  char local_1ec;
  undefined1 auStack_1b8 [128];
  undefined1 auStack_138 [64];
  undefined1 auStack_f8 [64];
  undefined1 auStack_b8 [64];
  undefined1 auStack_78 [76];
  
  if ((*param_2 & 1) != 0) {
    acVar3 = acStack_1ef;
    switch(*(undefined1 *)param_2) {
    case 0:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_pos_001a62cc) + 0));
      (*(unsigned short *)((unsigned char *)&(acStack_1f3) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_pos_001a62cc) + 5));
      local_1f4 = s_IL_pos_001a62cc[4];
      break;
    case 1:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 4));
      local_1f0 = (*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 8));
      local_1ec = s_IL_pointsize_001a62d4[0xc];
      break;
    case 2:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_color_001a62e4) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_color_001a62e4) + 4));
      local_1f0 = s_IL_color_001a62e4[8];
      local_1f0 = CONCAT13(local_1f0,acVar3);
      break;
    case 3:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 4));
      local_1f0 = (*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 8));
      local_1ec = s_IL_backcolor_001a62f0[0xc];
      break;
    case 4:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_fog_001a6300) + 0));
      (*(unsigned short *)((unsigned char *)&(acStack_1f3) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_fog_001a6300) + 5));
      local_1f4 = s_IL_fog_001a6300[4];
      break;
    case 5:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 4));
      (*(unsigned short *)((unsigned char *)&(acStack_1ef) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_generic_001a6308) + 9));
      local_1f0 = s_IL_generic_001a6308[8];
      break;
    default:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 4));
      (*(unsigned short *)((unsigned char *)&(acStack_1ef) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_unknown_001a6314) + 9));
      local_1f0 = s_IL_unknown_001a6314[8];
    }
    FUN_001a32d0(local_218 + 4,"%d",*(undefined1 *)((int)param_2 + 1));
    builtin_strncpy(local_218,"xyzw",4);
    uVar11 = *param_2 >> 4;
    iVar4 = 0;
    bVar1 = false;
    uVar9 = 0;
    pcVar8 = local_218;
    iVar12 = 4;
    puVar6 = param_2;
    do {
      if ((uVar11 & 0xf & 1 << (uVar9 & 0x3f)) != 0) {
        bVar2 = *(byte *)(puVar6 + 1);
        *(uint *)(pcVar8 + 0x10) = (uint)bVar2;
        if ((iVar4 != 0) && ((uint)bVar2 != *(uint *)(pcVar8 + 0xc))) {
          bVar1 = true;
        }
        iVar4 = iVar4 + 1;
        pcVar8 = pcVar8 + 4;
      }
      uVar9 = uVar9 + 1;
      puVar6 = (uint *)((int)puVar6 + 1);
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    if (bVar1) {
      uVar11 = 0;
      puVar10 = auStack_138;
      puVar6 = param_2;
      do {
        if ((*param_2 >> 4 & 0xf & 1 << (uVar11 & 0x3f)) == 0) {
          auStack_138[uVar11 * 0x40] = 0;
        }
        else {
          FUN_001a32d0(puVar10,"o%d.%c ",*(undefined1 *)(puVar6 + 1),
                       (int)local_218[*(byte *)(puVar6 + 2)]);
        }
        bVar1 = uVar11 != 3;
        puVar10 = puVar10 + 0x40;
        puVar6 = (uint *)((int)puVar6 + 1);
        uVar11 = uVar11 + 1;
      } while (bVar1);
      FUN_001a32d0(auStack_1b8,"%s%s%s%s",auStack_138,auStack_f8,auStack_b8,auStack_78);
    }
    else {
      iVar4 = 0x5f;
      if ((uVar11 & 1) != 0) {
        iVar4 = (int)local_218[*(byte *)(param_2 + 2)];
      }
      iVar12 = 0x5f;
      if ((uVar11 & 2) != 0) {
        iVar12 = (int)local_218[*(byte *)((int)param_2 + 9)];
      }
      iVar5 = 0x5f;
      if ((uVar11 & 4) != 0) {
        iVar5 = (int)local_218[*(byte *)((int)param_2 + 10)];
      }
      iVar7 = 0x5f;
      if ((uVar11 & 8) != 0) {
        iVar7 = (int)local_218[*(byte *)((int)param_2 + 0xb)];
      }
      FUN_001a32d0(auStack_1b8,"o%d.%c%c%c%c",*(undefined1 *)(param_2 + 1),iVar4,iVar12,iVar5,iVar7)
      ;
    }
    ((int (*)())FUN_000ce050)(param_1,";    %s = %s%s",auStack_1b8,local_1f8,local_218 + 4);
  }
  return;
}

/* FUN_000ce88c @ 0xce88c (480 bytes) */
int FUN_000ce88c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  ((int (*)())FUN_000ce050)(param_1,"");
  ((int (*)())FUN_000ce050)(param_1,";*****************************************");
  ((int (*)())FUN_000ce050)(param_1,";                 VS Data");
  ((int (*)())FUN_000ce050)(param_1,";*****************************************");
  ((int (*)())FUN_000ce050)(param_1,"; Input Semantic Mappings");
  if (*(int *)(param_2 + 0x104) == 0) {
    ((int (*)())FUN_000ce050)(param_1,";    No input mappings");
  }
  else {
    iVar3 = 0;
    iVar2 = param_2 + 0x108;
    do {
      ((int (*)())FUN_000ce4e4)(param_1,iVar2,iVar3);
      bVar1 = iVar3 != 0x3f;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (bVar1);
  }
  ((int (*)())FUN_000ce050)(param_1,"");
  ((int (*)())FUN_000ce050)(param_1,"; Output Semantic Mappings");
  if (*(int *)(param_2 + 0x408) == 0) {
    ((int (*)())FUN_000ce050)(param_1,";    No output mappings");
  }
  else {
    iVar3 = 0;
    iVar2 = param_2 + 0x40c;
    do {
      ((int (*)())FUN_000ce514)(param_1,iVar2,iVar3);
      bVar1 = iVar3 != 0x2f;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (bVar1);
  }
  ((int (*)())FUN_000ce050)(param_1,"");
  ((int (*)())FUN_000ce050)(param_1,"; Num Insts = %d",*(undefined4 *)(param_2 + 0x65c));
  ((int (*)())FUN_000ce050)(param_1,"; Max Temp = %d",*(int *)(param_2 + 0x660) + -1);
  ((int (*)())FUN_000ce050)(param_1,"; Max AltTemp = %d",*(int *)(param_2 + 0x664) + -1);
  ((int (*)())FUN_000ce050)(param_1,"; Max Constants = %d",*(int *)(param_2 + 0x670) + -1);
  ((int (*)())FUN_000ce050)(param_1,"; Last Pos Inst = %d",*(undefined4 *)(param_2 + 0x668));
  ((int (*)())FUN_000ce050)(param_1,"; Last Src Inst = %d",*(undefined4 *)(param_2 + 0x66c));
  if (*(int *)(param_2 + 0x658) != 0) {
    ((int (*)())FUN_000ce050)(param_1,"; Shader uses relative addressing");
  }
  return 1;
}

/* FUN_000cea6c @ 0xcea6c (660 bytes) */
int FUN_000cea6c(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
{
  undefined2 uVar1;
  uint uVar2;
  size_t sVar3;
  uint uVar4;
  char acStack_38 [28];
  
  uVar1 = (*(unsigned short *)((unsigned char *)&(s_ox_001a64a8) + 1));
  uVar4 = *param_2;
  switch(uVar4 >> 8 & 0xf) {
  case 0:
    param_3[0] = 'r';
    param_3[1] = '\0';
    break;
  case 1:
    param_3[0] = 'a';
    param_3[1] = '\0';
    break;
  case 2:
    param_3[0] = 'o';
    param_3[1] = '\0';
    break;
  case 3:
    *param_3 = s_ox_001a64a8[0];
    *(undefined2 *)(param_3 + 1) = uVar1;
    break;
  case 4:
    param_3[0] = 't';
    param_3[1] = '\0';
    break;
  case 5:
    param_3[0] = 'v';
    param_3[1] = '\0';
    break;
  default:
    param_3[0] = '?';
    param_3[1] = '\0';
  }
  FUN_001a32d0(acStack_38,"%d",uVar4 >> 0xd & 0x7f);
  if ((uVar4 & 0x80001000) == 0) {
    _strcat(param_3,acStack_38);
  }
  else {
    if ((uVar4 & 0x80001000) == 0x80000000) {
      sVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar3,"[a0",4);
    }
    else {
      sVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar3,"[i0",4);
    }
    switch(uVar4 >> 0x1d & 3) {
    case 0:
      _strcat(param_3,".x");
      break;
    case 1:
      _strcat(param_3,".y");
      break;
    case 2:
      _strcat(param_3,".z");
      break;
    case 3:
      _strcat(param_3,".w");
      break;
    default:
      _strcat(param_3,".?");
    }
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '+';
    (param_3 + sVar3)[1] = '\0';
    _strcat(param_3,acStack_38);
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = ']';
    (param_3 + sVar3)[1] = '\0';
  }
  if ((uVar4 & 0x40) == 0) {
    uVar2 = uVar4 & 0x1000000;
  }
  else {
    uVar2 = uVar4 & 0x2000000;
  }
  if (uVar2 != 0) {
    _strcat(param_3,"_sat");
  }
  if ((uVar4 & 0xf00000) != 0xf00000) {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '.';
    (param_3 + sVar3)[1] = '\0';
    if ((uVar4 & 0x100000) != 0) {
      sVar3 = _strlen(param_3);
      (param_3 + sVar3)[0] = 'x';
      (param_3 + sVar3)[1] = '\0';
    }
    if ((uVar4 & 0x200000) != 0) {
      sVar3 = _strlen(param_3);
      (param_3 + sVar3)[0] = 'y';
      (param_3 + sVar3)[1] = '\0';
    }
    if ((uVar4 & 0x400000) != 0) {
      sVar3 = _strlen(param_3);
      (param_3 + sVar3)[0] = 'z';
      (param_3 + sVar3)[1] = '\0';
    }
    if ((uVar4 & 0x800000) != 0) {
      sVar3 = _strlen(param_3);
      (param_3 + sVar3)[0] = 'w';
      (param_3 + sVar3)[1] = '\0';
    }
  }
  return param_2 + 1;
}

/* FUN_000ced58 @ 0xced58 (1288 bytes) */
int FUN_000ced58(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
  char *param_4;
  char *param_5;
{
  bool bVar1;
  undefined4 uVar2;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char acStack_48 [5];
  char acStack_43 [23];
  
  uVar2 = (*(unsigned int *)((unsigned char *)&(s_Du_001a64b4) + 4));
  uVar7 = *param_2;
  uVar4 = param_2[-3];
  uVar5 = uVar7 & 0x18000000;
  uVar6 = uVar7 & 0xf;
  *(undefined4 *)param_3 = (*(unsigned int *)((unsigned char *)&(s_Du_001a64b4) + 0));
  *(undefined4 *)(param_3 + 4) = uVar2;
  switch(uVar7 >> 0x15 & 0xf | (uVar7 & 4) << 2 | 0x40) {
  case 0x40:
    _strcat(param_3,"NOPme     ");
    break;
  case 0x41:
    _strcat(param_3,"EXPP      ");
    break;
  case 0x42:
    _strcat(param_3,"LOGP      ");
    break;
  case 0x43:
    _strcat(param_3,"EXPPE     ");
    break;
  case 0x44:
    _strcat(param_3,"LIT       ");
    break;
  case 0x45:
    _strcat(param_3,"POW       ");
    break;
  case 0x46:
    _strcat(param_3,"RCP       ");
    break;
  case 0x47:
    _strcat(param_3,"RCPFF     ");
    break;
  case 0x48:
    _strcat(param_3,"RSQ       ");
    break;
  case 0x49:
    _strcat(param_3,"RSQFF     ");
    break;
  case 0x4a:
    _strcat(param_3,"MULme     ");
    break;
  case 0x4b:
    _strcat(param_3,"EXP       ");
    break;
  case 0x4c:
    _strcat(param_3,"LOG       ");
    break;
  case 0x4d:
    _strcat(param_3,"POWB      ");
    break;
  case 0x4e:
    _strcat(param_3,"POWB1     ");
    break;
  case 0x4f:
    _strcat(param_3,"POW01     ");
    break;
  case 0x50:
    _strcat(param_3,"SIN       ");
    break;
  case 0x51:
    _strcat(param_3,"COS       ");
    break;
  case 0x52:
    _strcat(param_3,"LOGIE3    ");
    break;
  case 0x53:
    _strcat(param_3,"RCPIE3    ");
    break;
  case 0x54:
    _strcat(param_3,"RSQIE3    ");
    break;
  case 0x55:
    _strcat(param_3,"Prd_EQ    ");
    break;
  case 0x56:
    _strcat(param_3,"Prd_GT    ");
    break;
  case 0x57:
    _strcat(param_3,"Prd_GTE   ");
    break;
  case 0x58:
    _strcat(param_3,"Prd_NEQ   ");
    break;
  case 0x59:
    _strcat(param_3,"Prd_CLR   ");
    break;
  case 0x5a:
    _strcat(param_3,"Prd_INV   ");
    break;
  case 0x5b:
    _strcat(param_3,"Prd_POP   ");
    break;
  case 0x5c:
    _strcat(param_3,"Prd_RSTOR ");
    break;
  default:
    _strcat(param_3,"ERROR     ");
  }
  param_4[0] = 't';
  param_4[1] = '\0';
  FUN_001a32d0(acStack_48,"%d",uVar7 >> 0x13 & 3);
  if ((uVar4 & 0x2000000) != 0) {
    _strcat(param_4,"_sat");
  }
  _strcat(param_4,acStack_48);
  sVar3 = _strlen(param_4);
  (param_4 + sVar3)[0] = '.';
  (param_4 + sVar3)[1] = '\0';
  if (uVar5 == 0) {
    sVar3 = _strlen(param_4);
    (param_4 + sVar3)[0] = 'x';
    (param_4 + sVar3)[1] = '\0';
  }
  else if (uVar5 == 0x8000000) {
    sVar3 = _strlen(param_4);
    (param_4 + sVar3)[0] = 'y';
    (param_4 + sVar3)[1] = '\0';
  }
  else if (uVar5 == 0x10000000) {
    sVar3 = _strlen(param_4);
    (param_4 + sVar3)[0] = 'z';
    (param_4 + sVar3)[1] = '\0';
  }
  else if (uVar5 == 0x18000000) {
    sVar3 = _strlen(param_4);
    (param_4 + sVar3)[0] = 'w';
    (param_4 + sVar3)[1] = '\0';
  }
  sVar3 = _strlen(param_4);
  (param_4 + sVar3)[0] = ',';
  (param_4 + sVar3)[1] = '\0';
  if (uVar6 == 1) {
    param_5[0] = 'v';
    param_5[1] = '\0';
  }
  else if (uVar6 == 0) {
    param_5[0] = 'r';
    param_5[1] = '\0';
  }
  else if (uVar6 == 2) {
    param_5[0] = 'c';
    param_5[1] = '\0';
  }
  else if (uVar6 == 3) {
    param_5[0] = 't';
    param_5[1] = '\0';
  }
  else {
    param_5[0] = '?';
    param_5[1] = '\0';
  }
  FUN_001a32d0(acStack_43,"%d",uVar7 >> 5 & 0xff);
  _strcat(param_5,acStack_43);
  uVar5 = uVar7 & 0x6000000;
  if (((uVar7 & 0x7e000) != 0x10000) || (uVar5 != 0)) {
    uVar6 = 0;
    sVar3 = _strlen(param_5);
    (param_5 + sVar3)[0] = '.';
    (param_5 + sVar3)[1] = '\0';
    uVar4 = 0xd;
    do {
      if (((uVar5 & 0x2000000 << (uVar6 & 0x3f)) != 0) && (uVar5 != 0)) {
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = '-';
        (param_5 + sVar3)[1] = '\0';
      }
      switch((uVar7 & 0x7e000 & 7 << (uVar4 & 0x3f)) >> (uVar4 & 0x3f)) {
      case 0:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = 'x';
        (param_5 + sVar3)[1] = '\0';
        break;
      case 1:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = 'y';
        (param_5 + sVar3)[1] = '\0';
        break;
      case 2:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = 'z';
        (param_5 + sVar3)[1] = '\0';
        break;
      case 3:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = 'w';
        (param_5 + sVar3)[1] = '\0';
        break;
      case 4:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = '0';
        (param_5 + sVar3)[1] = '\0';
        break;
      case 5:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = '1';
        (param_5 + sVar3)[1] = '\0';
        break;
      default:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = '?';
        (param_5 + sVar3)[1] = '\0';
      }
      bVar1 = uVar6 != 1;
      uVar4 = uVar4 + 3;
      uVar6 = uVar6 + 1;
    } while (bVar1);
  }
  return param_2 + 1;
}

/* FUN_000cf2ec @ 0xcf2ec (1952 bytes) */
int FUN_000cf2ec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  uint uVar1;
  undefined4 local_18;
  
  uVar1 = *param_2;
  *param_4 = 0;
  if ((uVar1 & 0x10000000) != 0) {
    *param_4 = 1;
  }
  if ((uVar1 & 0x4000000) == 0) {
    builtin_strncpy(param_3,"   ",4);
  }
  else if ((uVar1 & 0x8000000) == 0) {
    builtin_strncpy(param_3,"!p ",4);
  }
  else {
    builtin_strncpy(param_3," p ",4);
  }
  switch(uVar1 & 0xff) {
  case 0:
    _strcat(param_3,"NOPve     ");
    local_18 = 0;
    *param_5 = 0;
    break;
  case 1:
    _strcat(param_3,"DP4       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 2:
    _strcat(param_3,"MULve     ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 3:
    _strcat(param_3,"ADD       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 4:
    _strcat(param_3,"MAD       ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 5:
    _strcat(param_3,"DST       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 6:
    _strcat(param_3,"FRC       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 7:
    _strcat(param_3,"MAX       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 8:
    _strcat(param_3,"MIN       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 9:
    _strcat(param_3,"SGE       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 10:
    _strcat(param_3,"SLT       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0xb:
    _strcat(param_3,"M2xADD    ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0xc:
    _strcat(param_3,"MULCLAMP  ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0xd:
    _strcat(param_3,"F2F_FLR   ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0xe:
    _strcat(param_3,"F2F_RND   ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0xf:
    _strcat(param_3,"PrdEQ_PSH ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x10:
    _strcat(param_3,"PrdGT_PSH");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x11:
    _strcat(param_3,"PrdGTE_PSH");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x12:
    _strcat(param_3,"PrdNEQ_PSH");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x13:
    _strcat(param_3,"CND_WR_EQ ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x14:
    _strcat(param_3,"CND_WR_GT");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x15:
    _strcat(param_3,"CND_WR_GTE");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x16:
    _strcat(param_3,"CND_WR_NEQ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x17:
    _strcat(param_3,"CND_MUX_EQ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x18:
    _strcat(param_3,"CND_MUX_GT");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x19:
    _strcat(param_3,"CND_MUX_GTE");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x1a:
    _strcat(param_3,"SGT       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x1b:
    _strcat(param_3,"SEQ       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x1c:
    _strcat(param_3,"SNE       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  default:
    _strcat(param_3,"ERROR     ");
    local_18 = 1;
    break;
  case 0x40:
    _strcat(param_3,"NOPme     ");
    local_18 = 0;
    *param_5 = 0;
    break;
  case 0x41:
    _strcat(param_3,"EXPP      ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x42:
    _strcat(param_3,"LOGP      ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x43:
    _strcat(param_3,"EXPPE     ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x44:
    _strcat(param_3,"LIT       ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x45:
    _strcat(param_3,"POW       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x46:
    _strcat(param_3,"RCP       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x47:
    _strcat(param_3,"RCPFF     ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x48:
    _strcat(param_3,"RSQ       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x49:
    _strcat(param_3,"RSQFF     ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x4a:
    _strcat(param_3,"MULme     ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x4b:
    _strcat(param_3,"EXP       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x4c:
    _strcat(param_3,"LOG       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x4d:
    _strcat(param_3,"POWB      ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x4e:
    _strcat(param_3,"POWB1     ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x4f:
    _strcat(param_3,"POW01     ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x50:
    _strcat(param_3,"SIN       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x51:
    _strcat(param_3,"COS       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x55:
    _strcat(param_3,"Prd_EQ    ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x58:
    _strcat(param_3,"Prd_NEQ   ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x59:
    _strcat(param_3,"Prd_CLR   ");
    local_18 = 0;
    *param_5 = 0;
    break;
  case 0x5a:
    _strcat(param_3,"Prd_INV   ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x5b:
    _strcat(param_3,"Prd_POP   ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x5c:
    _strcat(param_3,"Prd_RSTOR ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x80:
    _strcat(param_3,"MADmac    ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x81:
    _strcat(param_3,"M2xADDmac ");
    local_18 = 0;
    *param_5 = 2;
  }
  return local_18;
}

/* FUN_000cfc94 @ 0xcfc94 (144 bytes) */
int FUN_000cfc94(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if (param_2 == 0x3e) {
    return "loop   ";
  }
  if (param_2 < 0x3f) {
    if (param_2 == 0x35) {
      return "ifnz  ";
    }
    if (param_2 < 0x36) {
      if (param_2 == 8) {
        return "call   ";
      }
      if (param_2 == 9) {
        return "callnz ";
      }
    }
  }
  else if (param_2 == 0x53) {
    return "ret    ";
  }
  return "unknown";
}

/* FUN_000cfd24 @ 0xcfd24 (524 bytes) */
int FUN_000cfd24(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  undefined4 uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar8 = param_2[2];
  if (uVar8 == 0x35) {
    iVar7 = param_2[3];
    if (*param_2 == 0) {
      pcVar2 = "!=";
    }
    else {
      pcVar2 = "==";
    }
    iVar4 = param_2[6];
    pcVar3 = "          CF- IF  B%d %s 0, if = %d, else = %d, endif = %d";
    pcVar5 = (char *)(param_2[4] + 1);
    iVar6 = param_2[5] + 1;
LAB_000cfef0:
    ((int (*)())FUN_000ce050)(param_1,pcVar3,iVar7,pcVar2,pcVar5,iVar6,iVar4);
    return;
  }
  if (uVar8 < 0x36) {
    if (uVar8 == 0x27) {
      return;
    }
    if (uVar8 < 0x28) {
      if (uVar8 == 8) {
        iVar6 = param_2[6];
        iVar4 = param_2[4];
        iVar7 = param_2[5];
        pcVar2 = "          CF- CALL at %d, subroutine from %d to %d";
        goto LAB_000cfe3c;
      }
      if (uVar8 == 9) {
        iVar7 = param_2[4];
        pcVar2 = (char *)param_2[3];
        if (*param_2 == 0) {
          pcVar5 = "!=";
        }
        else {
          pcVar5 = "==";
        }
        iVar4 = param_2[6];
        iVar6 = param_2[5];
        pcVar3 = "          CF- CALL at %d if B%d %s 0, subroutine from %d to %d";
        goto LAB_000cfef0;
      }
    }
    else if (uVar8 == 0x29) {
      return;
    }
  }
  else {
    if (uVar8 == 0x3e) {
      if (param_2[1] == 0) {
        iVar6 = param_2[6];
        iVar4 = param_2[3];
        pcVar2 = "          CF- Loop I%d first in loop = %d last in loop = %d";
        iVar7 = param_2[4] + 1;
      }
      else {
        iVar6 = param_2[6];
        iVar4 = param_2[3];
        pcVar2 = "          CF- Rep  I%d first in loop = %d last in loop = %d";
        iVar7 = param_2[4] + 1;
      }
      goto LAB_000cfe3c;
    }
    if (uVar8 == 0x53) {
      return;
    }
  }
  iVar7 = *param_2;
  uVar1 = ((int (*)())FUN_000cfc94)(param_1,uVar8);
  ((int (*)())FUN_000ce050)(param_1,"\nNot = %d, op=%s(%d), reg =%d",iVar7,uVar1,uVar8,param_2[3]);
  iVar7 = param_2[4];
  ((int (*)())FUN_000ce050)(param_1," ifinst = %d begInst= %d callinst = %d",iVar7,iVar7,iVar7);
  ((int (*)())FUN_000ce050)(param_1," else=%d, labelinst=%d",param_2[5],param_2[5]);
  iVar4 = param_2[6];
  pcVar2 = " endif= %d , endinst = %d, retinst = %d";
  iVar7 = iVar4;
  iVar6 = iVar4;
LAB_000cfe3c:
  ((int (*)())FUN_000ce050)(param_1,pcVar2,iVar4,iVar7,iVar6);
  return;
}

