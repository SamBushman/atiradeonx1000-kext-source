#include "decls.h"

/* FUN_000a4980 @ 0xa4980 (4768 bytes) */
int FUN_000a4980(param_1)
  int param_1;
{
  char cVar1;
  undefined1 *puVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  ushort uVar8;
  ushort uVar9;
  bool bVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  char cVar14;
  undefined1 uVar15;
  uint uVar16;
  uint *puVar17;
  int iVar18;
  undefined2 uVar20;
  int iVar19;
  int iVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  uint uVar24;
  undefined1 *puVar25;
  undefined4 uVar26;
  uint uVar27;
  int iVar28;
  char cVar29;
  char cVar30;
  uint uVar31;
  void *pvVar32;
  void *pvVar33;
  uint uVar34;
  undefined4 uVar35;
  void *pvVar36;
  int iVar37;
  char *pcVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  uint uVar42;
  int iVar43;
  double dVar44;
  double dVar45;
  double dVar46;
  undefined8 uVar47;
  int local_118 [4];
  longlong local_108;
  undefined4 local_100;
  uint uStack_fc[0];
  longlong local_f8;
  undefined4 local_f0;
  uint uStack_ec;
  undefined4 local_e8;
  uint uStack_e4;
  undefined4 local_e0;
  uint uStack_dc;
  longlong local_d8;
  undefined4 local_d0;
  uint uStack_cc;
  undefined4 local_c8;
  uint uStack_c4;
  undefined4 local_c0;
  uint uStack_bc;
  longlong local_b8[0];
  undefined4 local_b0;
  uint uStack_ac;
  longlong local_a8;
  undefined4 local_a0;
  uint uStack_9c;
  undefined4 local_98;
  uint uStack_94;
  undefined4 local_90;
  uint uStack_8c;
  
  iVar21 = FUN_001a3258();
  if ((*(uint *)(iVar21 + 0x44) & 0x60020000) != 0x40000000) {
    iVar39 = *(int *)(iVar21 + 4);
    if ((((unsigned char *)0x00002e2d)[*(int *)(iVar39 + 0x10)] != '\0') &&
       ((*(uint *)(iVar21 + 0x44) & 0x20000) == 0)) {
      iVar21 = FUN_0001a010(iVar39,*(undefined4 *)(((unsigned char *)0x000026a0) + iVar39));
      if (iVar21 == 0) goto LAB_000a4a50;
      iVar39 = *(int *)(param_1 + 4);
    }
    iVar21 = *(int *)(iVar39 + 0x10);
    if ((((((unsigned char *)0x00002e2c)[iVar21] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
        (*(short *)(((unsigned char *)0x00002e28) + iVar21) == -1)) &&
       (((((unsigned char *)0x00003178)[iVar21] == '\0' || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
        ((*(short *)(((unsigned char *)0x00003170) + iVar21) != 0x1b02 &&
         (*(short *)(((unsigned char *)0x00003172) + iVar21) != 0x1b02)))))) {
      if (*(int *)(param_1 + 0x2768) == 0) {
        return 0;
      }
      FUN_000a4550(param_1);
      return 0;
    }
  }
LAB_000a4a50:
  uVar24 = *(uint *)(param_1 + 0x276c);
  if (-1 < (int)uVar24) {
    uVar16 = *(uint *)(param_1 + 0x38) & 0x10310e |
             (int)(uint)*(ushort *)(param_1 + 0x34) >> (uVar24 & 0x3f) & 1U;
  }
  else {
    uVar16 = 1;
  }
  if (uVar16 == 0 && *(int *)(param_1 + 0x2458) == 0) {
    return 0;
  }
  uVar27 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  uVar16 = uVar27 - 1;
  if (-1 < (int)uVar16) {
    puVar17 = (uint *)(uVar16 * 4 + param_1 + 0x48);
    do {
      if ((((*puVar17 & 0x1f) == 0) || (puVar17[0x4ec] == 0)) &&
         ((uVar31 = *(uint *)(param_1 + 0x44), (uVar31 & 0x2000) == 0 ||
          (((((int)(uint)(byte)((unsigned char *)0x000011d3)[param_1] >> (uVar16 & 0x3f) & 1U) == 0 &&
            (((uVar31 & 0x800) == 0 || ((byte)((unsigned char *)0x000011d1)[param_1] != uVar16)))) &&
           (((uVar31 & 0x400) == 0 || ((byte)((unsigned char *)0x000011d2)[param_1] != uVar16)))))))) break;
      uVar16 = uVar16 - 1;
      puVar17 = puVar17 + -1;
      uVar27 = uVar27 - 1;
    } while (uVar27 != 0);
  }
  if (-1 < (int)uVar24) {
    uVar24 = 1 << (uVar24 & 0x3f);
  }
  else {
    uVar24 = 0;
  }
  if (-1 < (int)uVar16) {
    uVar24 = uVar24 | 1 << (uVar16 & 0x3f);
  }
  if (uVar24 != 0) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
    *(ushort *)(param_1 + 0x32) = (ushort)uVar24 | *(ushort *)(param_1 + 0x32);
    *(ushort *)(param_1 + 0x34) = (ushort)uVar24 | *(ushort *)(param_1 + 0x34);
  }
  *(uint *)(param_1 + 0x276c) = uVar16;
  if ((int)uVar16 < 0) goto LAB_000a52dc;
  iVar21 = *(int *)(param_1 + 4);
  cVar1 = *(char *)(param_1 + 0x245b);
  iVar37 = *(int *)(iVar21 + 0x10);
  bVar10 = (*(uint *)(param_1 + 0x44) & 0x60020000) == 0x40000000;
  iVar21 = FUN_0001a010(iVar21,*(undefined4 *)(((unsigned char *)0x000026a0) + iVar21));
  iVar39 = FUN_000a36b0(param_1,iVar21 == 0);
  iVar40 = *(int *)(param_1 + 4);
  sVar5 = *(short *)(((unsigned char *)0x00002e0e) + iVar37);
  if ((((unsigned char *)0x00002e2d)[*(int *)(iVar40 + 0x10)] == '\0') ||
     ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) {
LAB_000a4c38:
    cVar14 = '\0';
  }
  else {
    iVar40 = FUN_0001a010(iVar40,*(undefined4 *)(((unsigned char *)0x000026a0) + iVar40));
    if (iVar40 != 0) {
      iVar40 = *(int *)(param_1 + 4);
      goto LAB_000a4c38;
    }
    iVar40 = *(int *)(param_1 + 4);
    cVar14 = '\x01';
  }
  if (((((unsigned char *)0x00002e2c)[*(int *)(iVar40 + 0x10)] == '\0') ||
      ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     (cVar29 = '\x01', *(short *)(((unsigned char *)0x00002e28) + *(int *)(iVar40 + 0x10)) == -1)) {
    cVar29 = '\0';
  }
  iVar40 = FUN_000a4770(param_1);
  fVar3 = *(float *)(((unsigned char *)0x00002e20) + iVar37);
  fVar4 = *(float *)(((unsigned char *)0x000013e8) + param_1);
  sVar6 = *(short *)(((unsigned char *)0x00002e10) + iVar37);
  fVar11 = fVar4;
  if ((fVar4 < fVar3) &&
     (fVar11 = *(float *)(((unsigned char *)0x000013ec) + param_1), fVar3 < *(float *)(((unsigned char *)0x000013ec) + param_1))) {
    local_100 = 0x43300000;
    uStack_fc[0] = (uint)((fVar3 - fVar4) / *(float *)(((unsigned char *)0x000013f0) + param_1) + FLOAT_001aa10c);
    local_108 = (longlong)(int)uStack_fc[0];
    uStack_fc[0] = uStack_fc[0] ^ 0x80000000;
    fVar11 = *(float *)(((unsigned char *)0x000013f0) + param_1) *
             (float)((double)CONCAT44(0x43300000,uStack_fc[0]) - DOUBLE_001aa1e0) + fVar4;
  }
  iVar41 = *(int *)(param_1 + 4);
  sVar7 = *(short *)(((unsigned char *)0x00002e28) + iVar37);
  iVar18 = *(int *)(iVar41 + 0x10);
  if (((((unsigned char *)0x00003178)[iVar18] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     ((*(short *)(((unsigned char *)0x00003170) + iVar18) != 0x1b02 &&
      (*(short *)(((unsigned char *)0x00003172) + iVar18) != 0x1b02)))) {
    cVar30 = '\0';
  }
  else {
    cVar30 = '\x01';
  }
  uVar8 = *(ushort *)(((unsigned char *)0x00003172) + iVar37);
  uVar9 = *(ushort *)(((unsigned char *)0x00003170) + iVar37);
  if (cVar1 != '\0') {
    cVar29 = '\x01';
    cVar30 = '\x01';
  }
  pcVar38 = *(char **)(param_1 + 0x2764);
  if (pcVar38 != (char *)0x0) {
    do {
      if ((((bool)*pcVar38 == bVar10) &&
          (((!bVar10 ||
            ((((bool)pcVar38[1] == (iVar21 == 0) && (iVar39 == *(int *)(pcVar38 + 4))) &&
             ((sVar5 == 0x1102) == (bool)pcVar38[8])))) &&
           ((pcVar38[0x14] == cVar14 && (pcVar38[0x15] == cVar29)))))) &&
         (((cVar14 == '\0' && (cVar29 == '\0')) ||
          ((((iVar40 == *(int *)(pcVar38 + 0x18) && ((sVar6 == 0x1102) == (bool)pcVar38[0x1c])) &&
            ((cVar14 == '\0' ||
             ((FLOAT_001aa108 <= *(float *)(pcVar38 + 0x20) ||
              (fVar11 == *(float *)(pcVar38 + 0x20))))))) &&
           ((cVar29 == '\0' || (*(short *)(pcVar38 + 0x28) == sVar7)))))))) {
        if ((uint)uVar9 == *(uint *)(pcVar38 + 0xb4)) {
          uVar24 = *(uint *)(pcVar38 + 0xb8);
          if (uVar8 != uVar24) goto LAB_000a4e54;
        }
        else {
          uVar24 = *(uint *)(pcVar38 + 0xb8);
LAB_000a4e54:
          if ((uVar9 != uVar24) || ((uint)uVar8 != *(uint *)(pcVar38 + 0xb4))) goto LAB_000a4e90;
        }
        if ((pcVar38[0x2a] == cVar30) &&
           ((cVar30 == '\0' ||
            (iVar18 = _memcmp(pcVar38 + 0x2c,((unsigned char *)0x000030e8) + iVar37,0x80), iVar18 == 0))))
        goto LAB_000a5b9c;
      }
LAB_000a4e90:
      pcVar38 = *(char **)(pcVar38 + 0x138);
    } while (pcVar38 != (char *)0x0);
  }
  if (*(int *)(param_1 + 0x2778) == 0x100) {
    FUN_000a43f0(param_1);
    iVar41 = *(int *)(param_1 + 4);
  }
  iVar21 = *(int *)(iVar41 + 0x10);
  cVar1 = *(char *)(param_1 + 0x245b);
  pcVar38 = (char *)(**(code **)(param_1 + 0x10))(1,0x13c);
  if (pcVar38 == (char *)0x0) goto LAB_000a52dc;
  *pcVar38 = (*(uint *)(param_1 + 0x44) & 0x60020000) == 0x40000000;
  iVar39 = FUN_0001a010(*(int *)(param_1 + 4),*(undefined4 *)(((unsigned char *)0x000026a0) + *(int *)(param_1 + 4))
                       );
  pcVar38[1] = iVar39 == 0;
  pcVar38[8] = *(short *)(((unsigned char *)0x00002e0e) + iVar21) == 0x1102;
  iVar39 = *(int *)(param_1 + 4);
  if ((((unsigned char *)0x00002e2d)[*(int *)(iVar39 + 0x10)] == '\0') ||
     ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) {
LAB_000a4f50:
    cVar14 = '\0';
  }
  else {
    iVar39 = FUN_0001a010(iVar39,*(undefined4 *)(((unsigned char *)0x000026a0) + iVar39));
    cVar14 = '\x01';
    if (iVar39 != 0) goto LAB_000a4f50;
  }
  pcVar38[0x14] = cVar14;
  pcVar38[0x1c] = *(short *)(((unsigned char *)0x00002e10) + iVar21) == 0x1102;
  fVar3 = *(float *)(((unsigned char *)0x00002e20) + iVar21);
  fVar4 = *(float *)(((unsigned char *)0x000013e8) + param_1);
  fVar11 = fVar4;
  if ((fVar4 < fVar3) &&
     (fVar11 = *(float *)(((unsigned char *)0x000013ec) + param_1), fVar3 < *(float *)(((unsigned char *)0x000013ec) + param_1))) {
    local_f0 = 0x43300000;
    uStack_ec = (uint)((fVar3 - fVar4) / *(float *)(((unsigned char *)0x000013f0) + param_1) + FLOAT_001aa10c);
    local_f8 = (longlong)(int)uStack_ec;
    uStack_ec = uStack_ec ^ 0x80000000;
    fVar11 = *(float *)(((unsigned char *)0x000013f0) + param_1) *
             (float)((double)CONCAT44(0x43300000,uStack_ec) - DOUBLE_001aa1e0) + fVar4;
  }
  *(float *)(pcVar38 + 0x20) = fVar11;
  iVar39 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((((unsigned char *)0x00002e2c)[iVar39] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     (cVar14 = '\x01', *(short *)(((unsigned char *)0x00002e28) + iVar39) == -1)) {
    cVar14 = '\0';
  }
  pcVar38[0x15] = cVar14;
  iVar39 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((((unsigned char *)0x00003178)[iVar39] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     ((*(short *)(((unsigned char *)0x00003170) + iVar39) != 0x1b02 &&
      (*(short *)(((unsigned char *)0x00003172) + iVar39) != 0x1b02)))) {
    cVar14 = '\0';
  }
  else {
    cVar14 = '\x01';
  }
  pcVar38[0x2a] = cVar14;
  *(uint *)(pcVar38 + 0xb4) = (uint)*(ushort *)(((unsigned char *)0x00003170) + iVar21);
  *(uint *)(pcVar38 + 0xb8) = (uint)*(ushort *)(((unsigned char *)0x00003172) + iVar21);
  if (cVar1 != '\0') {
    pcVar38[0x2a] = '\x01';
    pcVar38[0x15] = '\x01';
  }
  if (*pcVar38 == '\0') {
    if ((*(int *)(pcVar38 + 0xb4) == 0x1b00) || (*(int *)(pcVar38 + 0xb8) == 0x1b00))
    goto LAB_000a5108;
    iVar39 = 0;
    uVar24 = 0;
  }
  else {
    iVar37 = FUN_000a36b0(param_1,pcVar38[1]);
    iVar39 = iVar37 << 2;
    *(int *)(pcVar38 + 4) = iVar37;
    if (iVar39 < 1) {
LAB_000a5108:
      iVar39 = 0;
      uVar24 = 1;
    }
    else {
      uVar24 = 1;
    }
  }
  iVar37 = iVar39;
  iVar40 = iVar39;
  if ((*(uint *)(pcVar38 + 0x14) & 0xffff0000) == 0) {
    if ((*(int *)(pcVar38 + 0xb4) == 0x1b01) || (*(int *)(pcVar38 + 0xb8) == 0x1b01))
    goto LAB_000a5188;
  }
  else {
    uVar20 = 0xffff;
    if (((unsigned char *)0x00002e2c)[iVar21] != '\0') {
      uVar20 = *(undefined2 *)(((unsigned char *)0x00002e28) + iVar21);
    }
    *(undefined2 *)(pcVar38 + 0x28) = uVar20;
    iVar18 = FUN_000a4770(param_1);
    *(int *)(pcVar38 + 0x18) = iVar18;
    if (iVar39 < iVar18 << 2) {
      iVar37 = iVar18 << 2;
    }
    if (iVar39 < 0x10) {
      iVar40 = 0x10;
    }
LAB_000a5188:
    uVar24 = uVar24 + 1;
    iVar39 = iVar37;
  }
  if (pcVar38[0x2a] != '\0') {
    (**(code **)(((unsigned char *)0x00001344) + param_1))(pcVar38 + 0x2c,((unsigned char *)0x000030e8) + iVar21,0x80);
    *(undefined4 *)(pcVar38 + 0xac) = *(undefined4 *)(param_1 + 0x2770);
    *(undefined4 *)(pcVar38 + 0xb0) = *(undefined4 *)(param_1 + 0x2774);
    if (iVar39 < 0x20) {
      iVar39 = 0x20;
    }
    if (iVar40 < 0x20) {
      iVar40 = 0x20;
    }
    uVar24 = uVar24 + 1;
  }
  uVar22 = FUN_000a3610(param_1,iVar39);
  uVar23 = FUN_000a3610(param_1,iVar40);
  uVar16 = uVar24;
  if (1 < uVar24) {
    uVar16 = 4;
  }
  uVar35 = *(undefined4 *)(param_1 + 4);
  if (uVar24 < 2) {
    uVar26 = 3;
  }
  else {
    uVar26 = 1;
  }
  iVar21 = FUN_00030c50(param_1,uVar22,uVar23,uVar16,0x1909,1,((unsigned char *)0x00001401),uVar26);
  iVar39 = 0;
  if (iVar21 != 0) {
    FUN_0002ddf0(uVar35,iVar21);
    iVar37 = *(int *)(iVar21 + 0x30);
    iVar39 = iVar21 + 0x3c;
    *(undefined1 *)(iVar21 + 0x39) = 0xff;
    *(undefined2 *)(iVar21 + 0x74) = *(undefined2 *)(iVar37 + 0xb0);
    *(undefined2 *)(iVar21 + 0x7c) = *(undefined2 *)(iVar37 + 0xac);
    *(uint *)(iVar21 + 0xc0) = (uint)*(ushort *)(iVar37 + 0xae) * (uint)*(ushort *)(iVar37 + 0xac);
    uVar22 = *(undefined4 *)(iVar37 + 0xb4);
    *(undefined2 *)(iVar21 + 0xa2) = 0x2600;
    *(uint *)(iVar21 + 0x50) = *(uint *)(iVar21 + 0x50) & 0xfffe01ff | 0x8a00;
    *(uint *)(iVar21 + 0x54) = *(uint *)(iVar21 + 0x54) & 0xfffffffc | 1;
    *(undefined2 *)(iVar21 + 0xa0) = 0x2600;
    *(undefined4 *)(iVar21 + 0xbc) = uVar22;
  }
  *(int *)(pcVar38 + 0xbc) = iVar39;
  if (iVar39 != 0) {
    pvVar36 = *(void **)(iVar39 + 0x80);
    if (*pcVar38 == '\0') {
      if (1 < uVar24) {
        _memset(pvVar36,0xff,*(size_t *)(iVar39 + 0x84));
      }
    }
    else {
      uVar31 = (uint)*(ushort *)(iVar39 + 0x3c);
      uVar34 = (uint)*(ushort *)(iVar39 + 0x3a);
      local_e8 = 0x43300000;
      uVar16 = *(int *)(pcVar38 + 4) * 2;
      uVar27 = *(int *)(pcVar38 + 4) << 2;
      uStack_e4 = uVar16 ^ 0x80000000;
      bVar10 = pcVar38[1] == '\0';
      dVar46 = (double)(float)((double)CONCAT44(0x43300000,uStack_e4) - DOUBLE_001aa1e0);
      if (bVar10) {
        iVar21 = 0;
        fVar3 = FLOAT_001aa0d4;
      }
      else {
        uVar47 = (**(code **)(param_1 + 0xc))(uVar16);
        iVar21 = (int)((ulonglong)uVar47 >> 0x20);
        bVar10 = iVar21 == 0;
        fVar3 = FLOAT_001aa0d4;
        if (!bVar10) {
          if ((*(uint *)(param_1 + 0xe8) & 1) == 0) {
            dVar44 = (double)*(float *)(param_1 + 0xe0);
            if (pcVar38[8] != '\0') goto LAB_000a53ac;
            ((void (*)())FUN_000a3a60)(dVar44,param_1,(int)uVar47,uVar27,iVar21,local_118);
          }
          else {
            dVar44 = (double)*(float *)(param_1 + 0x104);
LAB_000a53ac:
            ((void (*)())FUN_000a3790)(dVar44,param_1,(int)uVar47,uVar27,iVar21,local_118);
          }
          local_e0 = 0x43300000;
          uStack_dc = uVar16 - local_118[0] ^ 0x80000000;
          fVar3 = (float)((double)CONCAT44(0x43300000,uStack_dc) - DOUBLE_001aa1e0) - FLOAT_001aa10c
          ;
          fVar3 = fVar3 * fVar3;
        }
      }
      fVar4 = (float)((double)FLOAT_001aa10c - dVar46);
      if (bVar10) {
        if (uVar31 != 0) {
          uVar16 = 0;
          fVar3 = fVar4;
          do {
            if (uVar34 != 0) {
              iVar21 = 0;
              uVar42 = uVar34;
              fVar11 = fVar4;
              do {
                uVar15 = 0xff;
                if ((float)(dVar46 * dVar46) <= fVar11 * fVar11 + fVar3 * fVar3) {
                  uVar15 = 0;
                }
                *(undefined1 *)((int)pvVar36 + iVar21) = uVar15;
                iVar21 = iVar21 + 1;
                fVar11 = fVar11 + FLOAT_001aa0e8;
                uVar42 = uVar42 - 1;
              } while (uVar42 != 0);
            }
            uVar16 = uVar16 + 1;
            pvVar36 = (void *)((int)pvVar36 + uVar34);
            fVar3 = fVar3 + FLOAT_001aa0e8;
          } while (uVar31 != uVar16);
        }
      }
      else {
        if (uVar31 != 0) {
          uVar16 = 0;
          fVar11 = fVar4;
          do {
            if (uVar34 != 0) {
              uVar42 = 0;
              fVar12 = fVar4;
              do {
                fVar13 = fVar12 * fVar12 + fVar11 * fVar11;
                if (fVar3 <= fVar13) {
                  if ((float)(dVar46 * dVar46) <= fVar13) {
                    *(undefined1 *)((int)pvVar36 + uVar42) = 0;
                  }
                  else {
                    dVar44 = (double)_sqrtf();
                    iVar39 = (int)((float)(dVar46 - dVar44) + FLOAT_001aa10c);
                    local_d8 = (longlong)iVar39;
                    *(undefined1 *)((int)pvVar36 + uVar42) = *(undefined1 *)(iVar21 + iVar39);
                  }
                }
                else {
                  *(undefined1 *)((int)pvVar36 + uVar42) = 0xff;
                }
                uVar42 = uVar42 + 1;
                fVar12 = fVar12 + FLOAT_001aa0e8;
              } while (uVar34 != uVar42);
            }
            uVar16 = uVar16 + 1;
            pvVar36 = (void *)((int)pvVar36 + uVar34);
            fVar11 = fVar11 + FLOAT_001aa0e8;
          } while (uVar31 != uVar16);
        }
        (**(code **)(param_1 + 0x18))(iVar21);
      }
      dVar46 = DOUBLE_001aa1e0;
      uStack_cc = uVar27 ^ 0x80000000;
      uStack_c4 = uVar34 ^ 0x80000000;
      local_d0 = 0x43300000;
      uStack_bc = uVar31 ^ 0x80000000;
      local_c8 = 0x43300000;
      fVar3 = (float)((double)CONCAT44(0x43300000,uStack_cc) - DOUBLE_001aa1e0);
      *(float *)(pcVar38 + 0xc) =
           fVar3 / (float)((double)CONCAT44(0x43300000,uStack_c4) - DOUBLE_001aa1e0);
      local_c0 = 0x43300000;
      *(float *)(pcVar38 + 0x10) = fVar3 / (float)((double)CONCAT44(0x43300000,uStack_bc) - dVar46);
    }
    iVar21 = *(int *)(pcVar38 + 0xbc);
    pvVar36 = *(void **)(iVar21 + 0x80);
    if (1 < uVar24) {
      pvVar36 = (void *)((int)pvVar36 + *(int *)(iVar21 + 0x84));
    }
    if ((*(uint *)(pcVar38 + 0x14) & 0xffff0000) == 0) {
      if (1 < uVar24) {
        _memset(pvVar36,0xff,*(size_t *)(iVar21 + 0x84));
        goto LAB_000a58ec;
      }
    }
    else {
      uVar27 = (uint)*(ushort *)(iVar21 + 0x3a);
      iVar37 = *(int *)(pcVar38 + 0x18);
      iVar40 = (int)(uint)*(ushort *)(iVar21 + 0x3c) >> 4;
      iVar39 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      uVar16 = iVar37 * 4;
      pvVar33 = (void *)((int)pvVar36 + uVar27 * (*(ushort *)(iVar21 + 0x3c) - 1));
      if (pcVar38[0x14] == '\0') {
        _memset(pvVar33,0xff,uVar27);
        pcVar38[0x24] = '?';
        pcVar38[0x25] = -0x80;
        pcVar38[0x26] = '\0';
        pcVar38[0x27] = '\0';
      }
      else {
        if (pcVar38[0x1c] == '\0') {
          dVar44 = (double)*(float *)(((unsigned char *)0x00002e20) + iVar39);
          dVar45 = (double)*(float *)(((unsigned char *)0x000013e8) + param_1);
          dVar46 = dVar45;
          if ((dVar45 < dVar44) &&
             (dVar46 = (double)*(float *)(((unsigned char *)0x000013ec) + param_1),
             dVar44 < (double)*(float *)(((unsigned char *)0x000013ec) + param_1))) {
            local_a0 = 0x43300000;
            uStack_9c = (uint)((float)((double)(float)(dVar44 - dVar45) /
                                      (double)*(float *)(((unsigned char *)0x000013f0) + param_1)) + FLOAT_001aa10c)
            ;
            local_a8 = (longlong)(int)uStack_9c;
            uStack_9c = uStack_9c ^ 0x80000000;
            dVar46 = (double)(float)((double)*(float *)(((unsigned char *)0x000013f0) + param_1) *
                                     (double)(float)((double)CONCAT44(0x43300000,uStack_9c) -
                                                    DOUBLE_001aa1e0) + dVar45);
          }
          ((void (*)())FUN_000a3a60)(dVar46,param_1);
        }
        else {
          dVar44 = (double)*(float *)(((unsigned char *)0x00002e20) + iVar39);
          dVar45 = (double)*(float *)(((unsigned char *)0x000013e8) + param_1);
          dVar46 = dVar45;
          if ((dVar45 < dVar44) &&
             (dVar46 = (double)*(float *)(((unsigned char *)0x000013ec) + param_1),
             dVar44 < (double)*(float *)(((unsigned char *)0x000013ec) + param_1))) {
            local_b0 = 0x43300000;
            uStack_ac = (uint)((float)((double)(float)(dVar44 - dVar45) /
                                      (double)*(float *)(((unsigned char *)0x000013f0) + param_1)) + FLOAT_001aa10c)
            ;
            local_b8[0] = (longlong)(int)uStack_ac;
            uStack_ac = uStack_ac ^ 0x80000000;
            dVar46 = (double)(float)((double)*(float *)(((unsigned char *)0x000013f0) + param_1) *
                                     (double)(float)((double)CONCAT44(0x43300000,uStack_ac) -
                                                    DOUBLE_001aa1e0) + dVar45);
          }
          ((void (*)())FUN_000a3790)(dVar46,param_1);
        }
        if (0 < local_118[0]) {
          iVar21 = 0;
          puVar25 = (undefined1 *)((int)pvVar33 + uVar16);
          do {
            puVar2 = (undefined1 *)(iVar21 + (int)pvVar33);
            iVar21 = iVar21 + 1;
            puVar25 = puVar25 + -1;
            *puVar25 = *puVar2;
          } while (iVar21 < local_118[0]);
        }
        _memset((void *)((int)pvVar33 + local_118[0]),0xff,uVar16 + local_118[0] * -2);
        _memset((undefined1 *)((int)pvVar33 + uVar16),0,uVar27 + iVar37 * -4);
        uStack_94 = uVar16 ^ 0x80000000;
        uStack_8c = uVar27 ^ 0x80000000;
        local_90 = 0x43300000;
        local_98 = 0x43300000;
        *(float *)(pcVar38 + 0x24) =
             (float)((double)CONCAT44(0x43300000,uStack_94) - DOUBLE_001aa1e0) /
             (float)((double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_001aa1e0);
      }
      iVar21 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      if (((((unsigned char *)0x00002e2c)[iVar21] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
         (uVar16 = (uint)*(ushort *)(((unsigned char *)0x00002e28) + iVar21), uVar16 == 0xffff)) {
        uVar16 = 0xffff;
      }
      iVar21 = 0;
      do {
        if ((uVar16 & 1) == 0) {
          pvVar32 = (void *)((int)pvVar36 + uVar27 * iVar40);
          _memset(pvVar36,0,uVar27 * iVar40);
        }
        else {
          iVar39 = iVar40;
          if (iVar21 == 0xf) {
            iVar39 = iVar40 + -1;
          }
          pvVar32 = pvVar36;
          if (0 < iVar39) {
            iVar37 = 0;
            do {
              iVar37 = iVar37 + 1;
              pvVar32 = (void *)((int)pvVar36 + uVar27);
              (**(code **)(((unsigned char *)0x00001344) + param_1))(pvVar36,pvVar33,uVar27);
              pvVar36 = pvVar32;
            } while (iVar39 != iVar37);
          }
        }
        bVar10 = iVar21 != 0xf;
        uVar16 = uVar16 >> 1;
        iVar21 = iVar21 + 1;
        pvVar36 = pvVar32;
      } while (bVar10);
LAB_000a58ec:
      iVar21 = *(int *)(pcVar38 + 0xbc);
    }
    pvVar36 = *(void **)(iVar21 + 0x80);
    if (1 < uVar24) {
      pvVar36 = (void *)((int)pvVar36 + *(int *)(iVar21 + 0x84) * 2);
    }
    if (pcVar38[0x2a] == '\0') {
      if (1 < uVar24) {
        _memset(pvVar36,0xff,*(size_t *)(iVar21 + 0x84));
        goto LAB_000a59f4;
      }
    }
    else {
      uVar27 = (uint)*(ushort *)(iVar21 + 0x3a);
      iVar37 = 0x20;
      uVar24 = *(uint *)(pcVar38 + 0xac);
      uVar16 = *(uint *)(pcVar38 + 0xb0);
      iVar21 = (int)(uint)*(ushort *)(iVar21 + 0x3c) >> 5;
      iVar39 = (int)uVar27 >> 5;
      do {
        iVar40 = 0;
        iVar18 = 0;
        do {
          uVar15 = 0xff;
          if ((1 << (uVar24 & 0x3f) & *(uint *)(pcVar38 + (0x1f - uVar16) * 4 + 0x2c)) == 0) {
            uVar15 = 0;
          }
          iVar41 = iVar18 + (int)pvVar36;
          if (iVar21 != 0) {
            iVar28 = 0;
            do {
              if (iVar39 != 0) {
                iVar19 = 0;
                iVar43 = iVar39;
                do {
                  *(undefined1 *)(iVar41 + iVar19) = uVar15;
                  iVar19 = iVar19 + 1;
                  iVar43 = iVar43 + -1;
                } while (iVar43 != 0);
              }
              iVar28 = iVar28 + 1;
              iVar41 = iVar41 + uVar27;
            } while (iVar21 != iVar28);
          }
          bVar10 = iVar40 != 0x1f;
          iVar18 = iVar18 + iVar39;
          iVar40 = iVar40 + 1;
          uVar24 = uVar24 + 1 & 0x1f;
        } while (bVar10);
        iVar37 = iVar37 + -1;
        pvVar36 = (void *)((int)pvVar36 + uVar27 * iVar21);
        uVar16 = uVar16 + 1 & 0x1f;
      } while (iVar37 != 0);
LAB_000a59f4:
      iVar21 = *(int *)(pcVar38 + 0xbc);
    }
    iVar21 = FUN_000341a0(param_1,*(undefined4 *)(iVar21 + 0x7c),*(undefined4 *)(param_1 + 0x276c));
    if (iVar21 != 0) {
      uVar24 = (uint)*(byte *)(*(int *)(pcVar38 + 0xbc) + 0x31);
      pcVar38[0xf8] = '\0';
      pcVar38[0xf9] = '\0';
      pcVar38[0xfa] = '\0';
      pcVar38[0xfb] = '\0';
      pcVar38[0xd0] = '\0';
      pcVar38[0xd1] = '\0';
      pcVar38[0xd2] = '\0';
      pcVar38[0xd3] = '\0';
      iVar21 = 1 - ((int)-(uVar24 ^ 2) >> 0x1f);
      if ((*pcVar38 == '\0') && (uVar24 != 3)) {
        pcVar38[0xe8] = '\0';
        pcVar38[0xe9] = '\0';
        pcVar38[0xea] = '\0';
        pcVar38[0xeb] = '\0';
        pcVar38[0xc0] = '\0';
        pcVar38[0xc1] = '\0';
        pcVar38[0xc2] = '\0';
        pcVar38[0xc3] = '\0';
      }
      else {
        pcVar38[0xc0] = '\0';
        pcVar38[0xc1] = '\0';
        pcVar38[0xc2] = '\0';
        pcVar38[0xc3] = '\x02';
        pcVar38[0xe8] = '\0';
        pcVar38[0xe9] = '\0';
        pcVar38[0xea] = '\0';
        pcVar38[0xeb] = '\x01';
        if ((*(int *)(pcVar38 + 0xb4) == 0x1b00) || (*(int *)(pcVar38 + 0xb8) == 0x1b00)) {
          *(uint *)(pcVar38 + 0xd0) = uVar24;
          *(int *)(pcVar38 + 0xf8) = iVar21;
        }
      }
      if (((*(uint *)(pcVar38 + 0x14) & 0xffff0000) == 0) && (uVar24 != 3)) {
        pcVar38[0xec] = '\0';
        pcVar38[0xed] = '\0';
        pcVar38[0xee] = '\0';
        pcVar38[0xef] = '\0';
        pcVar38[0xc4] = '\0';
        pcVar38[0xc5] = '\0';
        pcVar38[0xc6] = '\0';
        pcVar38[199] = '\0';
      }
      else {
        *(uint *)(pcVar38 + 0xc4) = uVar24;
        *(int *)(pcVar38 + 0xec) = iVar21;
        if ((*(int *)(pcVar38 + 0xb4) == 0x1b01) || (*(int *)(pcVar38 + 0xb8) == 0x1b01)) {
          *(uint *)(pcVar38 + 0xd0) = uVar24;
          *(int *)(pcVar38 + 0xf8) = iVar21;
        }
      }
      if ((pcVar38[0x2a] != 0) || (uVar24 == 3)) {
        *(uint *)(pcVar38 + 0xd0) = uVar24;
        *(int *)(pcVar38 + 0xf8) = iVar21;
      }
      uVar16 = (uint)((*(uint *)(pcVar38 + 0x14) & 0xffff0000) != 0) * 0x10 |
               *(uint *)(pcVar38 + 0x114) & 0xffffffef;
      uVar23 = *(undefined4 *)(pcVar38 + 0xf8);
      uVar24 = -(uint)(byte)pcVar38[0x2a] >> 0x1b & 0x10 | *(uint *)(pcVar38 + 0x120) & 0xffffffef;
      uVar22 = *(undefined4 *)(pcVar38 + 0xd0);
      *(undefined4 *)(pcVar38 + 0xcc) = *(undefined4 *)(pcVar38 + 0xc4);
      *(undefined4 *)(pcVar38 + 200) = *(undefined4 *)(pcVar38 + 0xc4);
      *(undefined4 *)(pcVar38 + 0xf4) = *(undefined4 *)(pcVar38 + 0xec);
      *(undefined4 *)(pcVar38 + 0xf0) = *(undefined4 *)(pcVar38 + 0xec);
      *(undefined4 *)(pcVar38 + 0x10c) = uVar23;
      *(uint *)(pcVar38 + 0x11c) = uVar16;
      *(uint *)(pcVar38 + 0x134) = uVar24;
      *(uint *)(pcVar38 + 0x120) = uVar24;
      *(uint *)(pcVar38 + 0x124) = uVar24;
      *(uint *)(pcVar38 + 0x128) = uVar24;
      *(uint *)(pcVar38 + 300) = uVar24;
      *(uint *)(pcVar38 + 0x130) = uVar24;
      *(undefined4 *)(pcVar38 + 0xe4) = uVar22;
      *(undefined4 *)(pcVar38 + 0xd4) = uVar22;
      *(undefined4 *)(pcVar38 + 0xfc) = uVar23;
      *(undefined4 *)(pcVar38 + 0xd8) = uVar22;
      *(undefined4 *)(pcVar38 + 0x100) = uVar23;
      *(undefined4 *)(pcVar38 + 0xdc) = uVar22;
      *(undefined4 *)(pcVar38 + 0x104) = uVar23;
      *(undefined4 *)(pcVar38 + 0xe0) = uVar22;
      *(undefined4 *)(pcVar38 + 0x108) = uVar23;
      *(uint *)(pcVar38 + 0x114) = uVar16;
      *(uint *)(pcVar38 + 0x118) = uVar16;
      *(uint *)(pcVar38 + 0x110) = *(uint *)(pcVar38 + 0x110) & 0xffffffef;
      *(undefined4 *)(pcVar38 + 0x138) = *(undefined4 *)(param_1 + 0x2764);
      *(undefined4 *)(param_1 + 0x2764) = pcVar38;
      *(int *)(param_1 + 0x2778) = *(int *)(param_1 + 0x2778) + 1;
LAB_000a5b9c:
      *(char **)(param_1 + 0x2768) = pcVar38;
      FUN_000a46d0(param_1);
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(ushort *)(param_1 + 0x34) =
           (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x34);
      *(undefined4 *)(param_1 + 0x277c) = 0xffffffff;
      return 0;
    }
  }
  _free(pcVar38);
LAB_000a52dc:
  FUN_000a4550(param_1);
  return 1;
}

/* FUN_000a5c40 @ 0xa5c40 (624 bytes) */
int FUN_000a5c40(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  double dVar8;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  dVar8 = (double)(*(float *)(((unsigned char *)0x00002da8) + iVar4) * FLOAT_001aa0f0);
  if (DOUBLE_001aa1e8 <= dVar8) {
    uVar6 = (int)(dVar8 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar6 = (uint)(*(float *)(((unsigned char *)0x00002da8) + iVar4) * FLOAT_001aa0f0);
  }
  dVar8 = (double)(*(float *)(((unsigned char *)0x00002dac) + iVar4) * FLOAT_001aa0f0);
  if (DOUBLE_001aa1e8 <= dVar8) {
    iVar1 = (int)(dVar8 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar1 = (int)(*(float *)(((unsigned char *)0x00002dac) + iVar4) * FLOAT_001aa0f0);
  }
  dVar8 = (double)(*(float *)(((unsigned char *)0x00002da0) + iVar4) * FLOAT_001aa0f0);
  if (DOUBLE_001aa1e8 <= dVar8) {
    iVar2 = (int)(dVar8 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar2 = (int)(*(float *)(((unsigned char *)0x00002da0) + iVar4) * FLOAT_001aa0f0);
  }
  dVar8 = (double)(*(float *)(((unsigned char *)0x00002da4) + iVar4) * FLOAT_001aa0f0);
  if (DOUBLE_001aa1e8 <= dVar8) {
    iVar4 = (int)(dVar8 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar4 = (int)(*(float *)(((unsigned char *)0x00002da4) + iVar4) * FLOAT_001aa0f0);
  }
  *(uint *)(param_1 + 0x1a94) = uVar6 | iVar1 << 0x18 | iVar2 << 0x10 | iVar4 << 8;
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xd);
  iVar4 = *(int *)(param_1 + 4);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
  puVar5 = *(uint **)(iVar4 + 0x1d8);
  *puVar5 = (int)puVar3 - (int)puVar5 >> 2 | *puVar5;
  *(undefined4 **)(iVar4 + 0x1d8) = puVar3;
  *puVar3 = 0x4000000;
  puVar3[3] = ((unsigned char *)0x00001393);
  puVar3[4] = 10;
  puVar3[5] = ((unsigned char *)0x00001385);
  uVar7 = *(undefined4 *)(param_1 + 0x1a94);
  puVar3[7] = 0xc0023800;
  puVar3[0xb] = ((unsigned char *)0x00001380);
  puVar3[0xc] = 0;
  puVar3[8] = 0;
  puVar3[9] = 0;
  puVar3[10] = 0;
  puVar3[6] = uVar7;
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3 + 0xd;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar3 + 0xd);
  return;
}

/* FUN_000a5ec0 @ 0xa5ec0 (620 bytes) */
int FUN_000a5ec0(param_1)
  int param_1;
{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  
  uVar4 = *(uint *)(param_1 + 0x1a4c);
  iVar6 = *(int *)(param_1 + 0x1a60);
  *(uint *)(param_1 + 0x1a4c) = uVar4 & 0xfffeffff;
  *(undefined4 *)(param_1 + 0x1a60) = 0;
  iVar10 = *(int *)(*(int *)(param_1 + 4) + 0x2a50);
  if (iVar10 == 1) {
    uVar7 = *(uint *)(param_1 + 0x44);
    if ((uVar7 & 0x10000000) == 0) {
      *(undefined4 *)(param_1 + 0x1a68) = 0x66666666;
      *(undefined4 *)(param_1 + 0x1a6c) = 0x6666666;
      *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
      goto LAB_000a6110;
    }
  }
  else {
    uVar7 = *(uint *)(param_1 + 0x44);
  }
  iVar10 = iVar10 >> 1;
  iVar2 = (iVar10 + -1) * 4;
  uVar3 = *(uint *)(&DAT_001aa7e8 + iVar2);
  *(uint *)(param_1 + 0x2354) = *(uint *)(param_1 + 0x2354) & 0xfffffffe;
  uVar4 = (uint)(iVar10 == 3) << 0x11 | uVar4 & 0xfffcffff;
  *(undefined4 *)(param_1 + 0x1a6c) = *(undefined4 *)(&DAT_001aa7d0 + iVar2);
  *(uint *)(param_1 + 0x1a4c) = uVar4;
  uVar5 = *(undefined4 *)(&DAT_001aa7dc + iVar2);
  *(uint *)(param_1 + 0x1a60) = (uVar3 & 3) << 1 | 1;
  *(undefined4 *)(param_1 + 0x1a68) = uVar5;
  if ((uVar7 & 0x10000000) == 0) {
    cVar9 = '\0';
    uVar3 = 0;
    fVar1 = FLOAT_001aa0e8;
  }
  else {
    fVar1 = *(float *)(param_1 + 0x438);
    cVar9 = *(char *)(param_1 + 0x43c);
    uVar3 = uVar7 >> 0x19 & 1;
    *(uint *)(param_1 + 0x1a4c) = uVar7 >> 0xb & 0x10000 | uVar4;
  }
  uVar4 = *(uint *)(*(int *)(param_1 + 4) + 0x2a50);
  if (uVar3 == 0) {
    uVar4 = (1 << (uVar4 & 0x3f)) - 1;
    uVar4 = uVar4 | uVar4 * 0x40000 | uVar4 * 0x1000 | uVar4 * 0x40;
  }
  else {
    uVar8 = 0;
    uVar7 = (uint)(fVar1 * FLOAT_001aa104 *
                   (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_001aa1e0) +
                  FLOAT_001aa10c);
    uVar3 = uVar7 & 3;
    uVar7 = (int)uVar7 >> 2;
    if (cVar9 != '\0') {
      uVar8 = (1 << (uVar4 & 0x3f)) - 1;
    }
    uVar4 = uVar8 ^ (1 << (uVar7 + (uVar3 != 0) & 0x3f)) - 1U |
            (uVar8 ^ (1 << (uVar7 & 0x3f)) - 1U) << 0x12 |
            (uVar8 ^ (1 << (uVar7 + (1 < uVar3) & 0x3f)) - 1U) << 0xc |
            (uVar8 ^ (1 << (uVar7 + (2 < uVar3) & 0x3f)) - 1U) << 6;
  }
  *(uint *)(param_1 + 0x1b60) = uVar4;
LAB_000a6110:
  uVar4 = *(uint *)(param_1 + 0x1930);
  *(uint *)(param_1 + 0x1930) = uVar4 | 0x80200;
  if (iVar6 != *(int *)(param_1 + 0x1a60)) {
    *(uint *)(param_1 + 0x1930) = uVar4 | 0x2080340;
  }
  return;
}

/* FUN_000a6140 @ 0xa6140 (896 bytes) */
int FUN_000a6140(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  FUN_00086a80(param_1,param_3);
  *(undefined4 *)(param_1 + 0x1ba0) = 3;
  *(undefined4 *)(param_1 + 0x1b9c) = 3;
  *(undefined4 *)(param_1 + 0x1b84) = 0;
  *(undefined4 *)(param_1 + 0x1b50) = 0;
  *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
  *(undefined4 *)(((unsigned char *)0x00001b30) + param_1) = 0;
  *(undefined4 *)(param_1 + 0x1b74) = 0x1c000;
  *(undefined4 *)(param_1 + 0x248c) = 8;
  if ((param_2 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x1a50) = 0;
    *(undefined4 *)(param_1 + 0x1ab8) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x1ab8) = 0;
  }
  if ((param_2 & 0x1000) != 0) {
    *(undefined4 *)(param_1 + 0x1aec) = 0;
  }
  **(undefined4 **)(param_1 + 0x2440) = 0;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xfffffff0 | 3;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffff0f;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffe0ff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffdfff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffbfff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffff7fff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xfff0ffff | 0x30000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xff0fffff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xe0ffffff | 0x1000000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) | 0x20000000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xbfffffff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0x7fffffff;
  **(undefined4 **)(param_1 + 0x2444) = 0;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffff8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffffffc7 | 8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffe3f | 0x80;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffff1ff | 0x600;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffff0fff | 0xf000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfff8ffff;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffc7ffff | 0x80000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfe3fffff | 0x800000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xf1ffffff | 0x6000000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffff | 0xf0000000;
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x20);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar1;
  puVar3 = puVar1 + 0x1a;
  *puVar1 = 0x887;
  uVar2 = *(undefined4 *)(param_1 + 0x1b74);
  puVar1[2] = 0x82c;
  puVar1[1] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1b84);
  puVar1[4] = ((unsigned char *)0x000010ae);
  puVar1[3] = uVar2;
  uVar2 = *(undefined4 *)(((unsigned char *)0x00001b30) + param_1);
  puVar1[6] = ((unsigned char *)0x00001002);
  puVar1[5] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1b50);
  puVar1[8] = 0x824;
  puVar1[7] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1b9c);
  puVar1[10] = 0x825;
  puVar1[9] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar1[0xc] = 0x82d;
  puVar1[0xb] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x248c);
  puVar1[0xe] = 0x854;
  puVar1[0xd] = uVar2;
  uVar2 = **(undefined4 **)(param_1 + 0x2440);
  puVar1[0x10] = 0x878;
  puVar1[0xf] = uVar2;
  uVar2 = **(undefined4 **)(param_1 + 0x2444);
  puVar1[0x12] = ((unsigned char *)0x000012f0);
  puVar1[0x11] = uVar2;
  puVar1[0x13] = *(undefined4 *)(param_1 + 0x1aec);
  puVar1[0x14] = ((unsigned char *)0x000012f6);
  uVar2 = *(undefined4 *)(param_1 + 0x1a50);
  puVar1[0x16] = ((unsigned char *)0x000010fa);
  puVar1[0x15] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1b60);
  puVar1[0x18] = ((unsigned char *)0x000013c5);
  puVar1[0x17] = uVar2;
  puVar1[0x19] = *(undefined4 *)(param_1 + 0x1ab8);
  if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
    puVar1[0x1a] = ((unsigned char *)0x000013c5);
    puVar3 = puVar1 + 0x1c;
    puVar1[0x1b] = *(undefined4 *)(param_1 + 0x1ab8);
  }
  *puVar3 = ((unsigned char *)0x00001048);
  uVar2 = *(undefined4 *)(param_1 + 0x1bc0);
  puVar3[2] = ((unsigned char *)0x00001047);
  puVar3[1] = uVar2;
  puVar3[3] = *(undefined4 *)(param_1 + 0x1bb0);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3 + 4;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar3 + 4);
  return;
}

/* FUN_000a6500 @ 0xa6500 (828 bytes) */
int FUN_000a6500(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar12 = *(int *)(param_1 + 4);
  iVar11 = *(int *)(iVar12 + 0x10);
  uVar3 = FUN_0004e990();
  uVar9 = *(uint *)(iVar12 + 0x154) & 0x30000;
  if ((uVar9 == 0x20000) || (uVar9 == 0x30000)) {
    iVar10 = 0x18;
  }
  else {
    if (uVar9 == 0x10000) {
      iVar10 = 0x10;
      *(uint *)(param_1 + 0x1ae4) = uVar3 | uVar3 << 0x10;
      goto LAB_000a6564;
    }
    iVar10 = 0;
  }
  *(uint *)(param_1 + 0x1ae4) = uVar3 << 8;
LAB_000a6564:
  *(uint *)(param_1 + 0x1ae4) = *(uint *)(param_1 + 0x1ae4) | *(uint *)(((unsigned char *)0x00002db4) + iVar11);
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x1a);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
  puVar7 = puVar4 + 0xc;
  puVar1 = *(uint **)(iVar12 + 0x1d8);
  *puVar1 = (int)puVar4 - (int)puVar1 >> 2 | *puVar1;
  *(undefined4 **)(iVar12 + 0x1d8) = puVar4;
  puVar4[8] = 0xc0023200;
  puVar4[0xb] = 0;
  *puVar4 = 0x5000000;
  puVar4[6] = ((unsigned char *)0x000013c6);
  puVar4[1] = param_2;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = 0;
  puVar4[5] = 0;
  puVar4[9] = 0;
  puVar4[10] = 0;
  puVar4[7] = 3;
  if (param_2 != 0) {
    if (*(char *)(param_1 + 0x2451) == '\0') {
      uVar3 = uVar3 >> (iVar10 - 8U & 0x3f);
      uVar9 = uVar3 | uVar3 << 0x18 | uVar3 << 0x10 | uVar3 << 8;
    }
    else {
      uVar9 = 0xffffffff;
      if ((uVar3 < 0xffffff) && (uVar9 = 0, uVar3 != 0)) {
        uVar9 = iVar10 - 1;
        uVar5 = *(uint *)(param_1 + 0x1ab0) >> 0xc & 7;
        uVar2 = (1 << uVar5) - 1;
        if ((*(uint *)(param_1 + 0x1ab0) & 0x8000) == 0) {
          uVar6 = 0;
          for (; (1 << (uVar9 & 0x3f) & uVar3 * uVar2) != 0; uVar9 = uVar9 - 1) {
            uVar6 = uVar6 + 1;
          }
        }
        else {
          uVar6 = 0;
          for (; (uVar3 * uVar2 & 1 << (uVar9 & 0x3f)) == 0; uVar9 = uVar9 - 1) {
            uVar6 = uVar6 + 1;
          }
        }
        uVar3 = uVar3 * uVar2;
        if (uVar6 < uVar2) {
          uVar3 = uVar3 * 2;
          uVar2 = uVar6;
        }
        uVar9 = (uVar3 & ~((1 << (uVar2 & 0x3f)) + -1 << (iVar10 - uVar2 & 0x3f))) >>
                ((uVar5 + (iVar10 - uVar2)) - 8 & 0x3f) | uVar2 << (8 - uVar5 & 0x3f);
        uVar3 = uVar9 & 0xff;
        uVar9 = uVar3 | uVar3 << 8 | uVar3 << 0x10 | uVar9 << 0x18;
      }
    }
    uVar3 = *(uint *)(param_1 + 0x1ab8);
    puVar8 = puVar4 + 0xe;
    *puVar7 = ((unsigned char *)0x000013c5);
    uVar3 = uVar3 | 1;
    puVar4[0xd] = uVar3;
    if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
      puVar4[0xf] = uVar3;
      puVar4[0xe] = ((unsigned char *)0x000013c5);
      puVar8 = puVar4 + 0x10;
    }
    puVar7 = puVar8 + 6;
    puVar4[2] = (int)puVar8 - (int)puVar4 >> 2;
    *puVar8 = 0xc0023700;
    puVar8[2] = 0;
    puVar8[3] = uVar9;
    puVar8[1] = 0;
    puVar8[4] = ((unsigned char *)0x000013c5);
    puVar8[5] = *(undefined4 *)(param_1 + 0x1ab8);
    if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
      puVar8[6] = ((unsigned char *)0x000013c5);
      puVar7 = puVar8 + 8;
      puVar8[7] = *(undefined4 *)(param_1 + 0x1ab8);
    }
  }
  puVar4[3] = (int)puVar7 + (4 - (int)puVar4) >> 2;
  *puVar7 = ((unsigned char *)0x000013ca);
  puVar7[1] = *(undefined4 *)(param_1 + 0x1ae4);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar7 + 2;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar7 + 2);
  return;
}

/* FUN_000a6860 @ 0xa6860 (1096 bytes) */
int FUN_000a6860(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  float fVar7;
  float fVar11;
  float fVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  uint uVar16;
  undefined4 uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  double dVar21;
  ulonglong uVar22;
  undefined1 auStack_128 [144];
  undefined4 local_98;
  uint uStack_94;
  undefined4 local_90;
  uint uStack_8c;
  undefined4 local_88[0];
  uint uStack_84;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  longlong local_70;
  longlong local_68;
  undefined4 local_60;
  undefined4 uStack_5c[0];
  longlong local_58;
  longlong local_50;
  float fVar8;
  float fVar9;
  float fVar10;
  
  uVar17 = 0x43300000;
  uVar22 = FUN_001a3260();
  iVar20 = (int)(uVar22 >> 0x20);
  uVar13 = *(int *)(((unsigned char *)0x00001358) + iVar20) - *(int *)(((unsigned char *)0x000013d8) + iVar20);
  uVar14 = *(int *)(((unsigned char *)0x00001360) + iVar20) - *(int *)(((unsigned char *)0x000013d8) + iVar20);
  uVar16 = *(int *)(((unsigned char *)0x0000135c) + iVar20) - *(int *)(((unsigned char *)0x000013dc) + iVar20);
  uVar18 = *(int *)(((unsigned char *)0x00001364) + iVar20) - *(int *)(((unsigned char *)0x000013dc) + iVar20);
  uStack_94 = uVar13 ^ 0x80000000;
  uStack_8c = uVar14 ^ 0x80000000;
  uStack_84 = uVar16 ^ 0x80000000;
  uStack_7c = uVar18 ^ 0x80000000;
  dVar21 = *(double *)(((unsigned char *)0x00002d88) + *(int *)(*(int *)(iVar20 + 4) + 0x10));
  fVar1 = (float)((double)(CONCAT44(uVar17,uVar13) ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar2 = (float)((double)(CONCAT44(uVar17,uVar14) ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar3 = (float)((double)(CONCAT44(uVar17,uVar18) ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar4 = (float)((double)(CONCAT44(uVar17,uVar16) ^ 0x80000000) - DOUBLE_001aa1e0);
  if (((uVar22 & 0x400) == 0) || (iVar19 = 1, ((unsigned char *)0x00001491)[iVar20] == '\0')) {
    iVar19 = 0;
  }
  if (((uVar22 & 0x100) == 0) || (iVar20 = 1, ((unsigned char *)0x00001490)[param_1] == '\0')) {
    iVar20 = 0;
  }
  local_98 = uVar17;
  local_90 = uVar17;
  local_88[0] = uVar17;
  local_80 = uVar17;
  FUN_00086ba0(param_1,0,iVar20,iVar19,auStack_128);
  if ((iVar20 == 0) && (iVar19 != 0)) {
    uVar17 = 0x25;
    if (*(char *)(param_1 + 0x2802) != '\0') {
      uVar17 = 0x23;
    }
    puVar15 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,uVar17);
    cVar6 = *(char *)(param_1 + 0x2802);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar15;
    if (cVar6 == '\0') {
      *puVar15 = 0x5c8;
      puVar15[1] = 0x10000000;
      puVar15 = puVar15 + 2;
      *(undefined1 *)(param_1 + 0x2802) = 1;
    }
    puVar15 = (undefined4 *)FUN_00083c90(param_1,puVar15);
    uStack_74 = *(undefined4 *)(param_1 + 8);
    local_78 = 0x43300000;
    *(undefined4 **)(param_1 + 0x2794) = puVar15;
    fVar10 = FLOAT_001aa194;
    fVar9 = FLOAT_001aa190;
    fVar8 = FLOAT_001aa18c;
    fVar7 = FLOAT_001aa188;
    fVar12 = (fVar4 + fVar3) * FLOAT_001aa10c;
    fVar11 = (fVar1 + fVar2) * FLOAT_001aa10c;
    fVar5 = (float)((double)CONCAT44(0x43300000,uStack_74) - DOUBLE_001aa250);
    uVar13 = (uint)(*(float *)(param_1 + 0x2818) * FLOAT_001aa10c * fVar5 * (fVar3 - fVar4));
    local_70 = (longlong)(int)uVar13;
    iVar20 = (int)(fVar5 * *(float *)(param_1 + 0x2814) * FLOAT_001aa10c * (fVar2 - fVar1));
    local_68 = (longlong)iVar20;
    puVar15[2] = 0x82c;
    *puVar15 = ((unsigned char *)0x00001087);
    puVar15[1] = iVar20 << 0x10 | uVar13 & 0xffff;
  }
  else {
    uVar17 = 0x25;
    if (*(char *)(param_1 + 0x2802) != '\0') {
      uVar17 = 0x23;
    }
    puVar15 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,uVar17);
    cVar6 = *(char *)(param_1 + 0x2802);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar15;
    if (cVar6 == '\0') {
      *puVar15 = 0x5c8;
      puVar15[1] = 0x10000000;
      puVar15 = puVar15 + 2;
      *(undefined1 *)(param_1 + 0x2802) = 1;
    }
    puVar15 = (undefined4 *)FUN_00083c90(param_1,puVar15);
    uStack_5c[0] = *(undefined4 *)(param_1 + 8);
    local_60 = 0x43300000;
    *(undefined4 **)(param_1 + 0x2794) = puVar15;
    fVar10 = FLOAT_001aa194;
    fVar9 = FLOAT_001aa190;
    fVar8 = FLOAT_001aa18c;
    fVar7 = FLOAT_001aa188;
    fVar12 = (fVar4 + fVar3) * FLOAT_001aa10c;
    fVar11 = (fVar1 + fVar2) * FLOAT_001aa10c;
    fVar5 = (float)((double)CONCAT44(0x43300000,uStack_5c[0]) - DOUBLE_001aa250);
    uVar13 = (uint)(*(float *)(param_1 + 0x2818) * FLOAT_001aa10c * fVar5 * (fVar3 - fVar4));
    local_58 = (longlong)(int)uVar13;
    iVar20 = (int)(fVar5 * *(float *)(param_1 + 0x2814) * FLOAT_001aa10c * (fVar2 - fVar1));
    local_50 = (longlong)iVar20;
    puVar15[2] = 0x82c;
    *puVar15 = ((unsigned char *)0x00001087);
    puVar15[1] = iVar20 << 0x10 | uVar13 & 0xffff;
  }
  uVar17 = *(undefined4 *)(param_1 + 0x1b84);
  puVar15[4] = 0xc0083500;
  puVar15[5] = 0x10031;
  puVar15[6] = fVar11;
  puVar15[7] = fVar12;
  puVar15[8] = (float)dVar21;
  puVar15[10] = fVar7;
  puVar15[0xb] = fVar8;
  puVar15[3] = uVar17;
  puVar15[0xc] = fVar9;
  puVar15[0xd] = fVar10;
  puVar15[0xe] = ((unsigned char *)0x00001087);
  puVar15[9] = 0x3f800000;
  puVar15[0xf] = *(undefined4 *)(param_1 + 0x1ccc);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar15 + 0x10;
  (**(code **)(param_1 + 0x275c))(param_1,puVar15 + 0x10);
  FUN_0009d3b0(param_1);
  FUN_000872e0(param_1,auStack_128);
  return;
}

/* FUN_000a6cb0 @ 0xa6cb0 (656 bytes) */
int FUN_000a6cb0(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  code *pcVar2;
  uint *puVar3;
  undefined4 *puVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  
  iVar6 = *(int *)(param_1 + 4);
  cVar5 = ((unsigned char *)0x00003190)[*(int *)(iVar6 + 0x10)];
  if (cVar5 != '\0') {
    if ((((*(int *)(param_1 + 0x440) == 0) && (*(int *)(param_1 + 0x444) == 0)) &&
        (*(int *)(iVar6 + 0x160) == *(int *)(param_1 + 0x44c))) &&
       (*(int *)(iVar6 + 0x15c) == *(int *)(param_1 + 0x448))) {
      cVar5 = '\0';
    }
  }
  uVar7 = *(uint *)(iVar6 + 0x154);
  iVar10 = iVar6 + 0x30;
  if (*(int *)(iVar6 + 0x150) != 0) {
    iVar10 = *(int *)(iVar6 + 0x150);
  }
  if ((uVar7 & 0x40) == 0) {
    bVar1 = (param_2 >> 8 & 1) == 0;
LAB_000a6d70:
    if ((uVar7 & 0x80) == 0) {
      uVar8 = param_2 >> 10 & 1;
LAB_000a6db0:
      if (cVar5 == '\0') {
        if (bVar1) {
          uVar9 = 0;
        }
        else if (((*(char *)(param_1 + 0x247c) == '\0') || ((uVar7 & 0x40) == 0)) ||
                (((uVar7 & 0x30000) == 0x10000 && ((uVar7 & 0x1000) != 0)))) {
          uVar9 = 0;
          *(undefined1 *)(iVar10 + 0xc5) = 1;
        }
        else {
          uVar9 = 1;
          *(undefined1 *)(iVar10 + 0xc5) = 0;
          *(undefined1 *)(iVar10 + 0xc4) = 1;
        }
        iVar6 = (**(code **)(param_1 + 0x2758))(param_1,3000);
        pcVar2 = *(code **)(param_1 + 0x275c);
        *(int *)(FUN_00002748 + param_1 + 4) = iVar6;
        (*pcVar2)(param_1,iVar6);
        iVar10 = *(int *)(FUN_00002748 + param_1 + 4);
        ((int (*)())FUN_000a6500)(param_1,uVar9);
        *(int *)(iVar6 + 0x10) = *(int *)(FUN_00002748 + param_1 + 4) - iVar10 >> 2;
        ((int (*)())FUN_000a6860)(param_1,param_2);
        *(int *)(iVar6 + 0x14) = *(int *)(param_1 + 0x2794) - iVar10 >> 2;
        goto LAB_000a6ebc;
      }
    }
    else {
      uVar8 = param_2 >> 10 & 1;
      if ((uVar8 != 0) || ((*(uint *)(param_1 + 0x8c) & 0x20000000) == 0)) goto LAB_000a6db0;
    }
    if (!bVar1) {
      *(undefined1 *)(iVar10 + 0xc5) = 1;
    }
  }
  else {
    bVar1 = (param_2 >> 8 & 1) == 0;
    if (!bVar1) goto LAB_000a6d70;
  }
  uVar8 = param_2 >> 10 & 1;
  ((int (*)())FUN_000a6860)(param_1,param_2);
LAB_000a6ebc:
  if (uVar8 != 0) {
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x20000000;
  }
  iVar6 = *(int *)(param_1 + 4);
  FUN_0004ce30(param_1);
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,5);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
  puVar3 = *(uint **)(iVar6 + 0x1d8);
  *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(iVar6 + 0x1d8) = puVar4;
  *puVar4 = 0x2f000000;
  puVar4[1] = ((unsigned char *)0x000010e9);
  uVar9 = *(undefined4 *)(param_1 + 0x1ae0);
  puVar4[3] = ((unsigned char *)0x000013c7);
  puVar4[2] = uVar9;
  puVar4[4] = *(undefined4 *)(param_1 + 0x1ab0);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4 + 5;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar4 + 5);
  return;
}

/* FUN_000a6f70 @ 0xa6f70 (8 bytes) */
int FUN_000a6f70(param_1)
  size_t param_1;
{
  _calloc(param_1,1);
  return;
}

/* FUN_000a7050 @ 0xa7050 (2324 bytes) */
int FUN_000a7050(param_1)
  int param_1;
{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  iVar9 = param_1 + 0x240;
  *(undefined1 *)(param_1 + 0x26b) = 0;
  puVar2 = PTR_001e8a58;
  *(undefined **)(param_1 + 0x250) = PTR_001e8b14;
  *(undefined **)(param_1 + 0x254) = puVar2;
  puVar2 = PTR_001e8aa4;
  *(undefined **)(param_1 + 600) = PTR_001e8a3c;
  *(undefined **)(((unsigned char *)0x00001584) + param_1) = puVar2;
  puVar2 = PTR_LAB_001e8aa8;
  *(undefined **)(param_1 + 0x2998) = PTR_LAB_001e8ab0;
  *(undefined **)(param_1 + 0x299c) = puVar2;
  puVar2 = PTR_FUN_001e8ae0;
  *(undefined **)(((unsigned char *)0x000014c0) + param_1) = PTR_FUN_001e8acc;
  *(undefined **)(((unsigned char *)0x000014c8) + param_1) = puVar2;
  puVar2 = PTR_LAB_001e8ae8;
  *(undefined **)(((unsigned char *)0x000014d0) + param_1) = PTR_FUN_001e8abc;
  *(undefined **)(((unsigned char *)0x000014c4) + param_1) = puVar2;
  puVar2 = PTR_LAB_001e8b38;
  *(undefined **)(((unsigned char *)0x000014cc) + param_1) = PTR_FUN_001e8a2c;
  *(undefined **)(((unsigned char *)0x000014d4) + param_1) = puVar2;
  *(undefined4 *)(((unsigned char *)0x00001604) + param_1) = 0x3f800000;
  *(undefined4 *)(((unsigned char *)0x00001628) + param_1) = 0x3e000000;
  puVar3 = PTR_LAB_001e8b28;
  puVar2 = PTR_LAB_001e8a48;
  *(code **)(param_1 + 0x24c) = FUN_000a6f70;
  *(int *)(param_1 + 0x244) = param_1;
  *(undefined4 *)(((unsigned char *)0x0000162c) + param_1) = 0x42800000;
  *(undefined4 *)(((unsigned char *)0x00001608) + param_1) = 0x42800000;
  *(undefined4 *)((int)((unsigned char *)0x00001624) + param_1) = 0x80;
  *(int *)(param_1 + 0x25c) = iVar9;
  *(undefined **)(((unsigned char *)0x000014e8) + param_1) = puVar2;
  *(undefined **)(((unsigned char *)0x000014d8) + param_1) = puVar3;
  *(undefined4 *)(((unsigned char *)0x0000145c) + param_1) = 0;
  puVar2 = PTR_LAB_001e8a18;
  *(undefined **)(((unsigned char *)0x000014dc) + param_1) = PTR_FUN_001e8aa0;
  *(undefined **)(((unsigned char *)0x000014e4) + param_1) = puVar2;
  *(undefined **)(((unsigned char *)0x000014e0) + param_1) = PTR_LAB_001e8b00;
  *(undefined **)(((unsigned char *)0x000014ec) + param_1) = PTR_LAB_001e8a08;
  ((unsigned char *)0x000015f4)[param_1] = 4;
  ((unsigned char *)0x000015f5)[param_1] = 8;
  ((unsigned char *)0x000015f7)[param_1] = 0xc;
  *(undefined4 *)(((unsigned char *)0x00001630) + param_1) = 0x3e000000;
  ((unsigned char *)0x000015f3)[param_1] = 1;
  *(undefined4 *)(((unsigned char *)0x00001408) + param_1) = 0xffff;
  *(undefined2 *)(((unsigned char *)0x000015fe) + param_1) = 0x100;
  *(undefined4 *)(((unsigned char *)0x00001614) + param_1) = 0x40;
  ((unsigned char *)0x000015f8)[param_1] = ((unsigned char *)0x00002b7c)[param_1];
  *(undefined4 *)(((unsigned char *)0x00001618) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000161c) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000160c) + param_1) = 0x3e000000;
  *(undefined4 *)(((unsigned char *)0x00001610) + param_1) = 1;
  *(undefined4 *)(((unsigned char *)0x00001620) + param_1) = 1;
  *(undefined4 *)(((unsigned char *)0x000013f8) + param_1) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x00001400) + param_1) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x00001404) + param_1) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x000013fc) + param_1) = 0x20;
  uVar6 = ((int (*)())FUN_000a6f70)(0xa8);
  pcVar4 = *(code **)(param_1 + 0x24c);
  *(undefined4 *)(((unsigned char *)0x000016dc) + param_1) = 0x20;
  *(undefined4 *)(((unsigned char *)0x000013ac) + param_1) = uVar6;
  uVar6 = (*pcVar4)(0x90);
  pcVar4 = *(code **)(param_1 + 0x24c);
  *(undefined4 *)(((unsigned char *)0x00001394) + param_1) = uVar6;
  *(undefined2 *)(((unsigned char *)0x0000138a) + param_1) = 8;
  *(undefined2 *)(((unsigned char *)0x00001388) + param_1) = 6;
  ((unsigned char *)0x00001390)[param_1] = 2;
  *(undefined2 *)(((unsigned char *)0x0000138e) + param_1) = 8;
  *(undefined2 *)(((unsigned char *)0x0000138c) + param_1) = 0x10;
  uVar6 = (*pcVar4)(0x14);
  uVar8 = *(uint *)(param_1 + 0x2cc);
  *(undefined4 *)(((unsigned char *)0x0000136c) + param_1) = uVar6;
  ((unsigned char *)0x000015f0)[param_1] = 8;
  ((unsigned char *)0x000015f6)[param_1] = 0x10;
  *(undefined4 *)(param_1 + 0x2d4) = 0;
  ((unsigned char *)0x000015f2)[param_1] = 8;
  ((unsigned char *)0x000015f1)[param_1] = 0x10;
  *(undefined4 *)(param_1 + 0x29a8) = 0;
  *(undefined4 *)(param_1 + 0x29a4) = 0;
  *(undefined4 *)(param_1 + 0x29b0) = 0;
  *(undefined4 *)(param_1 + 0x29b4) = 0;
  *(undefined4 *)(param_1 + 0x29b8) = 0;
  *(undefined1 *)(param_1 + 0x262d) = 0;
  ((unsigned char *)0x00002690)[param_1] = 0;
  *(undefined4 *)(param_1 + 0x1a48) = 0;
  *(undefined4 *)(param_1 + 0x248) = 0xc;
  *(undefined4 *)(((unsigned char *)0x00001600) + param_1) = 3;
  *(undefined4 *)(param_1 + 0x1b74) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x29ac) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x29bc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1b70) = 0xffffffff;
  iVar10 = 0x10;
  *(uint *)(param_1 + 0x2cc) = uVar8 & 0xc02fffff | 0x40200000;
  *(undefined4 *)(param_1 + 0x1ef8) = 0xaaaaaaaa;
  iVar5 = iVar9;
  do {
    *(undefined4 *)(iVar5 + 0x98) = 0;
    iVar5 = iVar5 + 4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(undefined1 *)(param_1 + 0x2d0) = 0;
  *(undefined1 *)(param_1 + 0x2d1) = 0;
  uVar8 = *(uint *)(param_1 + 0x284);
  iVar5 = *(int *)(param_1 + 0x244);
  *(uint *)(param_1 + 0x1ae4) = *(uint *)(param_1 + 0x1ae4) & 0xffffffef;
  *(uint *)(param_1 + 0x2cc) = *(uint *)(param_1 + 0x2cc) & 0xfff5ffff;
  ((unsigned char *)0x000016d0)[param_1] = (byte)(*(uint *)(param_1 + 0x154) >> 6) & 1;
  *(uint *)(param_1 + 0x284) = uVar8 & 0xff8220ff;
  ((unsigned char *)0x000016d1)[param_1] = (byte)(*(uint *)(param_1 + 0x154) >> 7) & 1;
  *(undefined1 *)(iVar5 + 0xf6) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 0xf4) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 0xf5) = 1;
  *(undefined1 *)(param_1 + 0x269) = 0;
  *(undefined4 *)(((unsigned char *)0x00001634) + param_1) = 0x100;
  *(undefined4 *)(((unsigned char *)0x00002694) + param_1) = 0;
  *(undefined **)(((unsigned char *)0x00002168) + param_1) = ((unsigned char *)0x0000101d);
  *(undefined4 *)(((unsigned char *)0x00002688) + param_1) = 0x200;
  *(undefined4 *)(((unsigned char *)0x00001e20) + param_1) = 0x400;
  *(undefined4 *)(((unsigned char *)0x0000268c) + param_1) = 0x406;
  iVar5 = *(int *)(param_1 + 0x244);
  uVar8 = *(uint *)(iVar5 + 0x24) & 0x7ff00000;
  if ((((uVar8 == 0x800000) || (uVar8 == 0x100000)) || (uVar8 == 0x200000)) || (uVar8 == 0x400000))
  {
    *(undefined4 *)(((unsigned char *)0x00001e20) + param_1) = 0x600;
    *(undefined4 *)(((unsigned char *)0x00002688) + param_1) = 0x400;
    *(undefined4 *)(((unsigned char *)0x0000268c) + param_1) = 0x606;
    *(undefined4 *)(((unsigned char *)0x00001634) + param_1) = 0x400;
    *(undefined **)(((unsigned char *)0x00002168) + param_1) = ((unsigned char *)0x0000101d);
    uVar8 = *(uint *)(iVar5 + 0x24) & 0x7ff00000;
    if (uVar8 == 0x800000) {
      *(uint *)(((unsigned char *)0x00002694) + param_1) = *(uint *)(((unsigned char *)0x00002694) + param_1) | 0x80000000;
    }
    else if (uVar8 == 0x100000) {
      *(uint *)(((unsigned char *)0x00002694) + param_1) = *(uint *)(((unsigned char *)0x00002694) + param_1) | 0x40000000;
    }
    else if (uVar8 == 0x200000) {
      *(uint *)(((unsigned char *)0x00002694) + param_1) = *(uint *)(((unsigned char *)0x00002694) + param_1) | 0x8000000;
    }
    else if (uVar8 == 0x400000) {
      *(uint *)(((unsigned char *)0x00002694) + param_1) = *(uint *)(((unsigned char *)0x00002694) + param_1) | 0x2000000;
    }
  }
  ((int (*)())FUN_000b6020)(iVar9,0,0);
  *(undefined1 *)(param_1 + 0x1aa9) = 0;
  *(undefined1 *)(param_1 + 0x1aa8) = 0;
  *(undefined4 *)(param_1 + 0x1aa4) = 0;
  ((int (*)())FUN_000ab900)(iVar9);
  puVar2 = PTR_FUN_001e8b18;
  cVar1 = *(char *)(param_1 + 0x1aa8);
  *(undefined **)(((unsigned char *)0x000014f0) + param_1) = PTR_FUN_001e8a20;
  *(undefined **)(((unsigned char *)0x000014f4) + param_1) = puVar2;
  if (cVar1 == '\0') {
    *(undefined **)(((unsigned char *)0x000014f8) + param_1) = PTR_FUN_001e8a60;
  }
  else {
    *(undefined **)(((unsigned char *)0x000014f8) + param_1) = PTR_FUN_001e8af4;
  }
  puVar2 = PTR_FUN_001e8ac4;
  *(undefined **)(((unsigned char *)0x0000157c) + param_1) = PTR_FUN_001e8a44;
  *(undefined **)(((unsigned char *)0x00001580) + param_1) = puVar2;
  puVar3 = PTR_DAT_001e8aac;
  puVar2 = PTR_FUN_001e8a38;
  if (cVar1 == '\0') {
    *(undefined4 *)(((unsigned char *)0x0000151c) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x000014fc) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00001514) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00001518) + param_1) = 0;
    puVar2 = PTR_LAB_001e8b20;
    *(undefined **)(((unsigned char *)0x00001500) + param_1) = PTR_LAB_001e8a84;
    *(undefined **)(((unsigned char *)0x00001510) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8a4c;
    *(undefined **)(((unsigned char *)0x00001504) + param_1) = PTR_DAT_001e8a14;
    *(undefined **)(((unsigned char *)0x00001524) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8b30;
    *(undefined **)(((unsigned char *)0x00001520) + param_1) = PTR_FUN_001e8b0c;
    *(undefined **)(((unsigned char *)0x0000152c) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8a30;
    *(undefined **)(((unsigned char *)0x00001528) + param_1) = PTR_LAB_001e8af8;
    *(undefined **)(((unsigned char *)0x00001534) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8a5c;
    *(undefined **)(((unsigned char *)0x00001530) + param_1) = PTR_LAB_001e8a80;
    *(undefined **)(((unsigned char *)0x0000153c) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8a28;
    *(undefined **)(((unsigned char *)0x00001538) + param_1) = PTR_LAB_001e8aec;
    *(undefined **)(((unsigned char *)0x00001544) + param_1) = puVar2;
    *(undefined **)(((unsigned char *)0x00001540) + param_1) = PTR_LAB_001e8a90;
    *(undefined **)(((unsigned char *)0x00001548) + param_1) = PTR_LAB_001e8a24;
    *(undefined **)(((unsigned char *)0x0000154c) + param_1) = PTR_LAB_001e8a1c;
    puVar2 = PTR_LAB_001e8a34;
    *(undefined **)(((unsigned char *)0x00001550) + param_1) = PTR_LAB_001e8a78;
    *(undefined **)(((unsigned char *)0x00001554) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8a00;
    *(undefined **)(((unsigned char *)0x00001558) + param_1) = PTR_LAB_001e8b2c;
    *(undefined **)(((unsigned char *)0x0000155c) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8b24;
    *(undefined **)(((unsigned char *)0x00001560) + param_1) = PTR_LAB_001e8a8c;
    *(undefined **)(((unsigned char *)0x00001564) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8ad4;
    *(undefined **)(((unsigned char *)0x00001568) + param_1) = PTR_LAB_001e89f8;
    *(undefined **)(((unsigned char *)0x0000156c) + param_1) = puVar2;
  }
  else {
    *(undefined4 *)(((unsigned char *)0x00001520) + param_1) = 0;
    *(undefined **)(((unsigned char *)0x000014fc) + param_1) = puVar3;
    *(undefined **)(((unsigned char *)0x00001500) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8a50;
    *(undefined **)(((unsigned char *)0x00001510) + param_1) = PTR_LAB_001e8ad0;
    *(undefined **)(((unsigned char *)0x00001504) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8b34;
    *(undefined **)(((unsigned char *)0x00001514) + param_1) = PTR_LAB_001e8b08;
    *(undefined **)(((unsigned char *)0x00001518) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8a64;
    *(undefined **)(((unsigned char *)0x0000151c) + param_1) = PTR_FUN_001e8a70;
    *(undefined **)(((unsigned char *)0x00001528) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8ac0;
    *(undefined **)(((unsigned char *)0x00001524) + param_1) = PTR_FUN_001e8a10;
    *(undefined **)(((unsigned char *)0x00001530) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8a7c;
    *(undefined **)(((unsigned char *)0x0000152c) + param_1) = PTR_LAB_001e8a74;
    *(undefined **)(((unsigned char *)0x00001538) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8ab4;
    *(undefined **)(((unsigned char *)0x00001534) + param_1) = PTR_LAB_001e8af0;
    *(undefined **)(((unsigned char *)0x00001540) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8adc;
    *(undefined **)(((unsigned char *)0x0000153c) + param_1) = PTR_LAB_001e8a0c;
    *(undefined **)(((unsigned char *)0x00001544) + param_1) = PTR_LAB_001e8a40;
    *(undefined **)(((unsigned char *)0x00001548) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8a98;
    *(undefined **)(((unsigned char *)0x0000154c) + param_1) = PTR_LAB_001e8b10;
    *(undefined **)(((unsigned char *)0x00001550) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8a9c;
    *(undefined **)(((unsigned char *)0x00001554) + param_1) = PTR_LAB_001e8a54;
    *(undefined **)(((unsigned char *)0x00001558) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8ab8;
    *(undefined **)(((unsigned char *)0x0000155c) + param_1) = PTR_LAB_001e8b04;
    *(undefined **)(((unsigned char *)0x00001560) + param_1) = puVar2;
    puVar2 = PTR_LAB_001e8ad8;
    *(undefined **)(((unsigned char *)0x00001564) + param_1) = PTR_LAB_001e8a94;
    *(undefined **)(((unsigned char *)0x00001568) + param_1) = puVar2;
    *(undefined **)(((unsigned char *)0x0000156c) + param_1) = PTR_LAB_001e8b1c;
  }
  *(undefined1 **)(((unsigned char *)0x00001588) + param_1) = ((unsigned char *)0x000a6f90);
  FUN_0009bd60(iVar9,0x80);
  pcVar4 = *(code **)(param_1 + 0x250);
  ((unsigned char *)0x00002691)[param_1] = 0;
  *(undefined1 *)(param_1 + 0x365) = 0;
  *(undefined1 *)(param_1 + 0x36b) = 1;
  *(undefined2 *)(param_1 + 0x20ac) = 1;
  *(undefined1 *)(param_1 + 0x366) = 1;
  *(undefined1 *)(param_1 + 0x364) = 1;
  *(undefined4 *)(param_1 + 0x37c) = 1;
  ((unsigned char *)0x00002b81)[param_1] = 1;
  uVar6 = (*pcVar4)(1,((unsigned char *)0x00003754));
  *(undefined4 *)(param_1 + 0x20a0) = uVar6;
  FUN_0004ab60(iVar9);
  *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(param_1 + 0x20a0)) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x0000135c) + param_1) = 5;
  uVar6 = (**(code **)(param_1 + 0x250))(1,0x14);
  pcVar4 = *(code **)(param_1 + 0x24c);
  *(undefined2 *)(((unsigned char *)0x00001350) + param_1) = 5;
  *(undefined4 *)(((unsigned char *)0x00001358) + param_1) = uVar6;
  pvVar7 = (void *)(*pcVar4)(10);
  *(void **)(((unsigned char *)0x00001354) + param_1) = pvVar7;
  _memset(pvVar7,0xff,(uint)*(ushort *)(((unsigned char *)0x00001350) + param_1) << 1);
  pcVar4 = *(code **)(param_1 + 0x24c);
  *(undefined4 *)(((unsigned char *)0x000020b4) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x000020b8) + param_1) = 0x10;
  uVar6 = (*pcVar4)(0x40);
  *(undefined4 *)(((unsigned char *)0x000020bc) + param_1) = uVar6;
  FUN_0004f720(iVar9);
  puVar2 = PTR_LAB_001e8afc;
  *(undefined **)(((unsigned char *)0x000013e0) + param_1) = PTR_LAB_001e89c4;
  *(undefined **)(((unsigned char *)0x00001398) + param_1) = puVar2;
  puVar2 = PTR_LAB_001e89fc;
  *(undefined **)(((unsigned char *)0x0000139c) + param_1) = ((unsigned char *)0x000a6f80);
  puVar3 = PTR_DAT_001e8a6c;
  *(undefined **)(((unsigned char *)0x000014b4) + param_1) = puVar2;
  puVar2 = PTR_FUN_001e8a68;
  *(undefined **)(((unsigned char *)0x000014b8) + param_1) = puVar3;
  puVar3 = PTR_LAB_001e8a88;
  *(undefined **)(((unsigned char *)0x000014bc) + param_1) = puVar2;
  *(undefined **)(((unsigned char *)0x00001464) + param_1) = puVar3;
  FUN_000a2530(iVar9);
  FUN_000a0ef0(iVar9);
  FUN_0008f760(iVar9);
  *(undefined1 *)(param_1 + 0x26f) = 1;
  puVar2 = PTR_LAB_001e8a04;
  *(undefined **)(((unsigned char *)0x00001570) + param_1) = PTR_DAT_001e8ac8;
  *(undefined **)(((unsigned char *)0x00001574) + param_1) = puVar2;
  puVar2 = PTR_LAB_001e89f4;
  *(undefined **)(((unsigned char *)0x00001578) + param_1) = PTR_LAB_001e8ae4;
  *(undefined **)(((unsigned char *)0x00002b8c) + param_1) = puVar2;
  return;
}

/* FUN_000a7970 @ 0xa7970 (240 bytes) */
int FUN_000a7970(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = param_1 + 0x240;
  FUN_000a4490(iVar1);
  FUN_000a43f0(iVar1);
  ((int (*)())FUN_000b5fb0)(iVar1);
  FUN_0004b710(iVar1);
  FUN_0009c700(iVar1);
  if (*(int *)(((unsigned char *)0x00001358) + param_1) != 0) {
    (**(code **)(param_1 + 600))();
    *(undefined4 *)(((unsigned char *)0x00001358) + param_1) = 0;
  }
  if (*(int *)(((unsigned char *)0x00001354) + param_1) != 0) {
    (**(code **)(param_1 + 600))();
    *(undefined4 *)(((unsigned char *)0x00001354) + param_1) = 0;
  }
  if (*(int *)(((unsigned char *)0x000020bc) + param_1) != 0) {
    (**(code **)(param_1 + 600))();
    *(undefined4 *)(((unsigned char *)0x000020b8) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x000020bc) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x000020b4) + param_1) = 0;
  }
  FUN_000a0c60(iVar1);
  if (*(int *)(param_1 + 0x1aa4) != 0) {
    (**(code **)(param_1 + 600))();
    *(undefined4 *)(param_1 + 0x1aa4) = 0;
  }
  return;
}

/* FUN_000a7a60 @ 0xa7a60 (496 bytes) */
int FUN_000a7a60(param_1)
  int param_1;
{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar1 = PTR_DAT_001e88c8;
  iVar7 = param_1 + 0x240;
  ((unsigned char *)0x000015f8)[param_1] = ((unsigned char *)0x00002b7c)[param_1];
  uVar5 = *(uint *)(param_1 + 0x1ae4);
  uVar2 = *(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18);
  uVar4 = *(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x1c);
  *(uint *)(param_1 + 0x1ae4) = uVar5 & 0xffc0003f;
  piVar3 = *(int **)(*(int *)(param_1 + 0x18) + 0x1a0);
  uVar2 = uVar4 >> 0xe & 0xc000 |
          uVar4 >> 0x12 & 0x3000 | (uVar2 & 6) << 9 | (uVar2 & 0x18) << 5 | uVar2 >> 5 & 0x1f;
  if (piVar3 == (int *)0x0) {
    uVar4 = 0;
    iVar8 = 4;
    iVar6 = iVar7;
    do {
      if (*(short *)(((unsigned char *)0x00002dba) + uVar4 * 2 + *(int *)(param_1 + 0x10)) == 0) {
        *(undefined4 *)(iVar6 + 0x233c) = 0xf;
      }
      else {
        *(uint *)(iVar6 + 0x233c) = uVar2;
        *(uint *)(param_1 + 0x1ae4) =
             ((*(uint *)(param_1 + 0x1ae4) >> 6 | 1 << (uVar4 & 0x3f)) & 0xffff) << 6 |
             *(uint *)(param_1 + 0x1ae4) & 0xffc0003f;
      }
      uVar4 = uVar4 + 1;
      iVar6 = iVar6 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  else {
    uVar4 = 0;
    iVar8 = 4;
    iVar6 = iVar7;
    do {
      if (*(short *)(uVar4 * 2 + *piVar3 + 0x90) == 0) {
        *(undefined4 *)(iVar6 + 0x233c) = 0xf;
      }
      else {
        *(uint *)(iVar6 + 0x233c) = uVar2;
        *(uint *)(param_1 + 0x1ae4) =
             ((*(uint *)(param_1 + 0x1ae4) >> 6 | 1 << (uVar4 & 0x3f)) & 0xffff) << 6 |
             *(uint *)(param_1 + 0x1ae4) & 0xffc0003f;
      }
      uVar4 = uVar4 + 1;
      iVar6 = iVar6 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  uVar2 = *(uint *)(param_1 + 0x1ae4);
  if (*(int *)(((unsigned char *)0x00001448) + (uVar2 >> 6 & 0xffff) * 4 + iVar7) == 0) {
    ((int (*)())FUN_000b6020)(iVar7,0);
    uVar2 = *(uint *)(param_1 + 0x1ae4);
  }
  if ((((uVar5 >> 6 & 0xffff) != (uVar2 >> 6 & 0xffff)) && ((uVar2 & 0x3fffc0) != 0)) &&
     (((unsigned char *)0x0000430c)[*(int *)(param_1 + 0x10)] == '\0')) {
    FUN_000b6580(iVar7,0);
    (**(code **)(((unsigned char *)0x00002b8c) + param_1))(iVar7,*(undefined4 *)(param_1 + 0x209c));
  }
  *(uint *)(param_1 + 0x1b70) = *(uint *)(param_1 + 0x1b70) | 0x40;
  return;
}

/* FUN_000a7d10 @ 0xa7d10 (344 bytes) */
int FUN_000a7d10(param_1)
  int param_1;
{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  uVar6 = *(uint *)(param_1 + 0x44);
  if ((((int)uVar6 < 0) &&
      (*(short *)("}J3x})+x|B;x}k" + *(int *)(*(int *)(param_1 + 4) + 0x10)) == -0x7e06)) ||
     (iVar5 = 0, (uVar6 & 0xa10000) != 0)) {
    iVar5 = 1;
  }
  if ((uVar6 & 0x1000000) != 0) {
    iVar5 = 5;
  }
  if ((uVar6 & 0x20000) == 0) {
    bVar1 = *(byte *)(param_1 + 0x2b);
    if (bVar1 != 0) {
      uVar6 = (uint)bVar1;
      iVar3 = 0;
      iVar7 = 0;
      iVar8 = param_1;
      if ((bVar1 == 0) || (uVar6 == 0x80000000)) {
        uVar6 = 1;
      }
      do {
        if (*(int *)(((unsigned char *)0x000013f8) + iVar8) != 0) {
          iVar2 = iVar3 * 4;
          iVar3 = iVar3 + 1;
          *(int *)(iVar2 + param_1 + 0x1824) = iVar7;
        }
        iVar7 = iVar7 + 1;
        iVar8 = iVar8 + 4;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
LAB_000a7de8:
      iVar3 = iVar3 << 4;
      goto LAB_000a7df4;
    }
  }
  else {
    uVar4 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar4 != 0) {
      iVar3 = 0;
      uVar9 = 0;
      if ((uVar4 == 0) || (uVar4 == 0x80000000)) {
        uVar4 = 1;
      }
      while( true ) {
        if ((uVar6 & 0x2000) == 0) {
          uVar6 = (int)(uint)(byte)((unsigned char *)0x00001135)[param_1] >> (uVar9 & 0x3f);
        }
        else {
          uVar6 = (int)(uint)(byte)((unsigned char *)0x000011d3)[param_1] >> (uVar9 & 0x3f);
        }
        if ((uVar6 & 1) != 0) {
          iVar8 = iVar3 * 4;
          iVar3 = iVar3 + 1;
          *(uint *)(iVar8 + param_1 + 0x1824) = uVar9;
        }
        uVar9 = uVar9 + 1;
        uVar4 = uVar4 - 1;
        if (uVar4 == 0) break;
        uVar6 = *(uint *)(param_1 + 0x44);
      }
      goto LAB_000a7de8;
    }
  }
  iVar3 = 0;
LAB_000a7df4:
  *(int *)(param_1 + 0x1804) = iVar5 + iVar3;
  return;
}

/* FUN_000a7e80 @ 0xa7e80 (24 bytes) */
int FUN_000a7e80(param_1)
  int param_1;
{
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x10;
  return;
}

/* FUN_000a7ea0 @ 0xa7ea0 (48 bytes) */
int FUN_000a7ea0(param_1)
  int param_1;
{
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xefffffff;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x400;
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1018;
  return;
}

/* FUN_000a7ee0 @ 0xa7ee0 (980 bytes) */
int FUN_000a7ee0(param_1, param_2)
  int param_1;
  uint param_2;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  ushort uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  
  if (param_2 != 0) {
    uVar14 = 0;
    iVar15 = param_1 + 0x240;
    iVar13 = param_1;
    do {
      if ((param_2 & 1) != 0) {
        iVar6 = uVar14 * 4;
        uVar7 = *(uint *)(param_1 + 0x278);
        iVar11 = 1 << (uVar14 & 0x3f);
        uVar9 = *(uint *)(iVar6 + iVar15 + 0x48);
        uVar12 = (ushort)iVar11;
        uVar8 = uVar9 & 0xffffffe0 |
                *(uint *)(((unsigned char *)0x000031d4) + uVar14 * 0x7c + *(int *)(param_1 + 0x10)) & 0x1f;
        *(ushort *)(param_1 + 0x272) = uVar12 | *(ushort *)(param_1 + 0x272);
        *(uint *)(param_1 + 0x278) = uVar7 | 0x200;
        if (uVar9 != uVar8) {
          *(undefined1 *)(param_1 + 0x269) = 1;
          *(ushort *)(param_1 + 0x274) = uVar12 | *(ushort *)(param_1 + 0x274);
          iVar10 = *(int *)(param_1 + 0x10);
          if ((("}J3x})+x|B;x}k"[iVar10 + 2] != '\0') && (*(int *)(iVar13 + 0x18c) != 0)) &&
             ((**(ushort **)(*(int *)(iVar13 + 0x18c) + 0x30) & 0xf) == 0)) {
            *(uint *)(param_1 + 0x278) = uVar7 | 0x220;
            iVar10 = *(int *)(param_1 + 0x10);
          }
          if (((unsigned char *)0x00002e0a)[iVar10] != '\0') {
            *(uint *)(param_1 + 0x278) = *(uint *)(param_1 + 0x278) | 0x100;
          }
          *(uint *)(iVar6 + iVar15 + 0x48) = uVar8;
          ((unsigned char *)0x000026b5)[param_1] = 1;
        }
        iVar10 = *(int *)(iVar13 + 0x18c);
        bVar5 = (byte)iVar11;
        if (iVar10 == 0) {
          if (((unsigned char *)0x00001438)[uVar14 + iVar15] != '\0') {
            *(undefined1 *)(param_1 + 0x269) = 1;
            *(ushort *)(param_1 + 0x274) = uVar12 | *(ushort *)(param_1 + 0x274);
          }
          ((unsigned char *)0x00001438)[uVar14 + iVar15] = 0;
          *(undefined4 *)(((unsigned char *)0x000013f8) + iVar6 + iVar15) = 0;
          iVar6 = uVar14 * 8 + iVar15;
          iVar11 = uVar14 * 2 + iVar15;
          *(uint *)(iVar6 + 0x18ac) = *(uint *)(iVar6 + 0x18ac) & 0xfffffffe;
          *(ushort *)(iVar11 + 0x187c) = *(ushort *)(iVar11 + 0x187c) & 0x7fff;
          *(byte *)(param_1 + 0x260) = *(byte *)(param_1 + 0x260) & ~bVar5;
        }
        else {
          iVar11 = *(int *)(((unsigned char *)0x000013f8) + iVar6 + iVar15);
          bVar1 = *(byte *)(iVar10 + 0x6b);
          bVar2 = *(byte *)(iVar10 + 0x6a);
          bVar3 = *(byte *)(iVar10 + 0x69);
          uVar7 = *(uint *)(iVar10 + 200) >> 0x16 & 3;
          bVar4 = *(byte *)(iVar10 + 0x68);
          if ((iVar10 + 0x3c != iVar11) && (*(undefined1 *)(param_1 + 0x269) = 1, iVar11 == 0)) {
            *(ushort *)(param_1 + 0x274) = uVar12 | *(ushort *)(param_1 + 0x274);
          }
          ((unsigned char *)0x00001438)[uVar14 + iVar15] = 1;
          *(int *)(((unsigned char *)0x000013f8) + iVar6 + iVar15) = iVar10 + 0x3c;
          iVar6 = uVar14 * 8 + iVar15;
          iVar11 = uVar14 * 2 + iVar15;
          *(uint *)(iVar6 + 0x18ac) = *(uint *)(iVar6 + 0x18ac) | 1;
          *(uint *)(iVar6 + 0x18a8) =
               (uint)*(byte *)(iVar10 + 0x6c) << 0x1d | *(uint *)(iVar6 + 0x18a8) & 0x1fffffff;
          *(ushort *)(iVar11 + 0x187c) = *(ushort *)(iVar11 + 0x187c) | 0x8000;
          if (*(byte *)(param_1 + 0x26b) <= uVar14) {
            uVar8 = *(uint *)(param_1 + 0x27c);
            ((unsigned char *)0x000026b5)[param_1] = 1;
            *(char *)(param_1 + 0x26b) = (char)uVar14 + '\x01';
            *(undefined1 *)(param_1 + 0x269) = 1;
            *(uint *)(param_1 + 0x27c) = uVar8 | 0x400;
          }
          FUN_0002ebc0(param_1,uVar14);
          *(undefined4 *)(iVar10 + 0x88) = *(undefined4 *)(*(int *)(iVar10 + 0x30) + 0x38);
          *(uint *)(iVar6 + 0x18ac) =
               (bVar4 & 1) << 0x14 |
               (bVar3 & 7) << 0x15 |
               (bVar2 & 1) << 0x13 | (bVar1 & 7) << 4 | *(uint *)(iVar6 + 0x18ac) & 0xff07ff8f;
          if (*(short *)(iVar10 + 0x74) == 0x1902) {
            *(uint *)(param_1 + 0x1a48) = *(uint *)(param_1 + 0x1a48) | 0x80000000;
          }
          if ((**(ushort **)(iVar10 + 0x30) & 0xf) == 2) {
            *(uint *)(param_1 + 0x1a48) = *(uint *)(param_1 + 0x1a48) | 0x40000000;
          }
          if (*(float *)(iVar10 + 0x88) != FLOAT_001aa0d4) {
            *(uint *)(param_1 + 0x1a48) = *(uint *)(param_1 + 0x1a48) | 0x10000000;
          }
          if ((uVar14 < 8) && (uVar7 != 0)) {
            if ((*(uint *)(param_1 + 0x284) & 0x20000) != 0) goto LAB_000a81e0;
            if (((int)(uint)*(byte *)(param_1 + 0x260) >> (uVar14 & 0x3f) & 1U) == 0) {
              *(undefined1 *)(param_1 + 0x269) = 1;
              *(byte *)(param_1 + 0x260) = *(byte *)(param_1 + 0x260) | bVar5;
              *(ushort *)(param_1 + 0x274) = uVar12 | *(ushort *)(param_1 + 0x274);
            }
            *(char *)(uVar14 + iVar15 + 0x21) = (char)uVar7;
            iVar6 = uVar14 * 0xc + iVar15;
            *(uint *)(iVar6 + 0x2854) = (uint)*(ushort *)(iVar10 + 0xd0);
            *(uint *)(iVar6 + 0x2858) = (uint)*(ushort *)(iVar10 + 0xd4);
            *(uint *)(iVar6 + 0x285c) = (uint)*(ushort *)(iVar10 + 0xd2);
          }
          else {
LAB_000a81e0:
            if (((int)(uint)*(byte *)(param_1 + 0x260) >> (uVar14 & 0x3f) & 1U) != 0) {
              *(undefined1 *)(param_1 + 0x269) = 1;
              *(byte *)(param_1 + 0x260) = *(byte *)(param_1 + 0x260) & ~bVar5;
              *(ushort *)(param_1 + 0x274) = uVar12 | *(ushort *)(param_1 + 0x274);
            }
          }
          iVar6 = uVar14 * 8 + iVar15;
          *(uint *)(iVar6 + 0x18a8) = uVar7 << 2 | *(uint *)(iVar6 + 0x18a8) & 0xfffffff3;
        }
      }
      uVar14 = uVar14 + 1;
      param_2 = param_2 >> 1;
      iVar13 = iVar13 + 4;
    } while (param_2 != 0);
  }
  return;
}

/* FUN_000a82c0 @ 0xa82c0 (96 bytes) */
int FUN_000a82c0(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(((unsigned char *)0x000013f8) + param_2 * 4 + param_1 + 0x240) == 0) {
    return;
  }
  iVar2 = 5;
  piVar1 = (int *)(param_2 * 0x14 + *(int *)(param_1 + 0x18));
  while ((*piVar1 == 0 ||
         (*(int *)(((unsigned char *)0x000013f8) + param_2 * 4 + param_1 + 0x240) != *piVar1 + 0x3c))) {
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      *(undefined4 *)(((unsigned char *)0x000013f8) + param_2 * 4 + param_1 + 0x240) = 0;
      return;
    }
  }
  return;
}

/* FUN_000a8320 @ 0xa8320 (20 bytes) */
int FUN_000a8320(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(((unsigned char *)0x00001638) + param_2 * 4 + param_1) = 0;
  return;
}

/* FUN_000a8340 @ 0xa8340 (720 bytes) */
int FUN_000a8340(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  
  uVar3 = param_2 >> 0x10 & 0xff;
  if (uVar3 != 0) {
    uVar5 = 0;
    iVar6 = param_1 + 0x288;
    iVar10 = 0;
    iVar4 = 0;
    do {
      if ((uVar3 & 1) != 0) {
        iVar1 = uVar5 * 4;
        iVar9 = iVar10 + param_1 + 0x690;
        puVar8 = (uint *)(iVar6 + iVar1);
        psVar2 = (short *)(((unsigned char *)0x00003988) + iVar4 + *(int *)(param_1 + 0x10));
        if (*(char *)(psVar2 + 0x48) == '\0') {
          *(uint *)(iVar6 + iVar1) = *(uint *)(iVar6 + iVar1) & 0xffffffdf;
        }
        else {
          *(uint *)(iVar6 + iVar1) = *(uint *)(iVar6 + iVar1) | 0x20;
        }
        if (*(char *)((int)psVar2 + 0x91) == '\0') {
          uVar7 = *puVar8 & 0xffffffbf;
          *puVar8 = uVar7;
        }
        else {
          uVar7 = *puVar8 | 0x40;
          *puVar8 = uVar7;
        }
        if (*(char *)(psVar2 + 0x49) == '\0') {
          uVar7 = uVar7 & 0xffffff7f;
          *puVar8 = uVar7;
        }
        else {
          uVar7 = uVar7 | 0x80;
          *puVar8 = uVar7;
        }
        if (*(char *)((int)psVar2 + 0x93) == '\0') {
          uVar7 = uVar7 & 0xfffffeff;
          *puVar8 = uVar7;
        }
        else {
          uVar7 = uVar7 | 0x100;
          *puVar8 = uVar7;
        }
        if ((uVar7 & 0x1e0) != 0) {
          if ((uVar7 & 0x20) != 0) {
            if (*(short *)(iVar9 + 0x3c) != *psVar2) {
              *(short *)(iVar9 + 0x3c) = *psVar2;
            }
            *(undefined4 *)(iVar9 + 0x50) = *(undefined4 *)(psVar2 + 10);
            *(undefined4 *)(iVar9 + 0x54) = *(undefined4 *)(psVar2 + 0xc);
            *(undefined4 *)(iVar9 + 0x58) = *(undefined4 *)(psVar2 + 0xe);
            *(undefined4 *)(iVar9 + 0x5c) = *(undefined4 *)(psVar2 + 0x10);
            *(undefined4 *)(iVar9 + 0x40) = *(undefined4 *)(psVar2 + 2);
            *(undefined4 *)(iVar9 + 0x44) = *(undefined4 *)(psVar2 + 4);
            *(undefined4 *)(iVar9 + 0x48) = *(undefined4 *)(psVar2 + 6);
            *(undefined4 *)(iVar9 + 0x4c) = *(undefined4 *)(psVar2 + 8);
            uVar7 = *puVar8;
          }
          if ((uVar7 & 0x40) != 0) {
            if (*(short *)(iVar9 + 0x60) != psVar2[0x12]) {
              *(short *)(iVar9 + 0x60) = psVar2[0x12];
            }
            *(undefined4 *)(iVar9 + 0x74) = *(undefined4 *)(psVar2 + 0x1c);
            *(undefined4 *)(iVar9 + 0x78) = *(undefined4 *)(psVar2 + 0x1e);
            *(undefined4 *)(iVar9 + 0x7c) = *(undefined4 *)(psVar2 + 0x20);
            *(undefined4 *)(iVar9 + 0x80) = *(undefined4 *)(psVar2 + 0x22);
            *(undefined4 *)(iVar9 + 100) = *(undefined4 *)(psVar2 + 0x14);
            *(undefined4 *)(iVar9 + 0x68) = *(undefined4 *)(psVar2 + 0x16);
            *(undefined4 *)(iVar9 + 0x6c) = *(undefined4 *)(psVar2 + 0x18);
            *(undefined4 *)(iVar9 + 0x70) = *(undefined4 *)(psVar2 + 0x1a);
            uVar7 = *puVar8;
          }
          if ((uVar7 & 0x80) != 0) {
            if (*(short *)(iVar9 + 0x84) != psVar2[0x24]) {
              *(short *)(iVar9 + 0x84) = psVar2[0x24];
            }
            *(undefined4 *)(iVar9 + 0x98) = *(undefined4 *)(psVar2 + 0x2e);
            *(undefined4 *)(iVar9 + 0x9c) = *(undefined4 *)(psVar2 + 0x30);
            *(undefined4 *)(iVar9 + 0xa0) = *(undefined4 *)(psVar2 + 0x32);
            *(undefined4 *)(iVar9 + 0xa4) = *(undefined4 *)(psVar2 + 0x34);
            *(undefined4 *)(iVar9 + 0x88) = *(undefined4 *)(psVar2 + 0x26);
            *(undefined4 *)(iVar9 + 0x8c) = *(undefined4 *)(psVar2 + 0x28);
            *(undefined4 *)(iVar9 + 0x90) = *(undefined4 *)(psVar2 + 0x2a);
            *(undefined4 *)(iVar9 + 0x94) = *(undefined4 *)(psVar2 + 0x2c);
            uVar7 = *puVar8;
          }
          if ((uVar7 & 0x100) != 0) {
            if (*(short *)(iVar9 + 0xa8) != psVar2[0x36]) {
              *(short *)(iVar9 + 0xa8) = psVar2[0x36];
            }
            *(undefined4 *)(iVar9 + 0xbc) = *(undefined4 *)(psVar2 + 0x40);
            *(undefined4 *)(iVar9 + 0xc0) = *(undefined4 *)(psVar2 + 0x42);
            *(undefined4 *)(iVar9 + 0xc4) = *(undefined4 *)(psVar2 + 0x44);
            *(undefined4 *)(iVar9 + 200) = *(undefined4 *)(psVar2 + 0x46);
            *(undefined4 *)(iVar9 + 0xac) = *(undefined4 *)(psVar2 + 0x38);
            *(undefined4 *)(iVar9 + 0xb0) = *(undefined4 *)(psVar2 + 0x3a);
            *(undefined4 *)(iVar9 + 0xb4) = *(undefined4 *)(psVar2 + 0x3c);
            *(undefined4 *)(iVar9 + 0xb8) = *(undefined4 *)(psVar2 + 0x3e);
          }
        }
        *(undefined1 *)(param_1 + 0x269) = 1;
        uVar7 = *(uint *)(param_1 + 0x278);
        *(byte *)(param_1 + 0x26c) = (byte)(1 << (uVar5 & 0x3f)) | *(byte *)(param_1 + 0x26c);
        *(uint *)(param_1 + 0x278) = uVar7 | 0x8000;
        if ("}J3x})+x|B;x}k"[*(int *)(param_1 + 0x10) + 2] != '\0') {
          *(uint *)(param_1 + 0x278) = uVar7 | 0x8020;
        }
      }
      uVar3 = uVar3 >> 1;
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x94;
      iVar10 = iVar10 + 0xcc;
    } while (uVar3 != 0);
  }
  ((unsigned char *)0x000026b5)[param_1] = 1;
  return;
}

/* FUN_000a8630 @ 0xa8630 (968 bytes) */
int FUN_000a8630(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  uint uVar32;
  uint uVar33;
  int iVar34;
  int iVar35;
  undefined1 uVar36;
  undefined8 uVar37;
  
  uVar37 = FUN_001a322c();
  iVar34 = (int)((ulonglong)uVar37 >> 0x20);
  iVar35 = (int)uVar37;
  if ((param_3 & 8) != 0) {
    *(uint *)(iVar34 + 0x38) = *(uint *)(iVar34 + 0x38) | 0x80;
    *(uint *)(iVar34 + 0x40) = *(uint *)(iVar34 + 0x40) | 0x20000;
    *(undefined1 *)(iVar34 + 0x29) = 1;
  }
  if (((param_3 & 0x3f000008) != 0) && (*(int *)(((unsigned char *)0x00003e28) + iVar35) != 0)) {
    fVar1 = *(float *)(iVar35 + 0x1920);
    fVar2 = *(float *)(iVar35 + 0x192c);
    fVar3 = *(float *)(iVar35 + 0x1958);
    fVar4 = *(float *)(iVar35 + 0x195c);
    fVar5 = *(float *)(iVar35 + 0x1928);
    fVar6 = *(float *)(iVar35 + 0x1938);
    fVar7 = *(float *)(iVar35 + 0x1948);
    fVar8 = *(float *)(iVar35 + 0x193c);
    fVar9 = *(float *)(iVar35 + 0x1934);
    fVar27 = fVar5 * fVar4 - fVar2 * fVar3;
    fVar26 = fVar5 * fVar8 - fVar2 * fVar6;
    fVar30 = fVar6 * fVar4 - fVar8 * fVar3;
    fVar10 = *(float *)(iVar35 + 0x1924);
    fVar11 = *(float *)(iVar35 + 0x1944);
    fVar12 = *(float *)(iVar35 + 0x194c);
    fVar13 = *(float *)(iVar35 + 0x1954);
    fVar14 = *(float *)(iVar35 + 0x1940);
    fVar25 = fVar5 * fVar12 - fVar2 * fVar7;
    fVar18 = fVar13 * fVar26 + (fVar10 * fVar30 - fVar9 * fVar27);
    fVar29 = fVar6 * fVar12 - fVar8 * fVar7;
    fVar28 = fVar7 * fVar4 - fVar12 * fVar3;
    fVar24 = fVar1 * fVar11 - fVar10 * fVar14;
    fVar31 = -(fVar10 * fVar29 - (fVar9 * fVar25 - fVar11 * fVar26));
    fVar19 = -(fVar10 * fVar28 - (fVar11 * fVar27 - fVar13 * fVar25));
    fVar15 = *(float *)(iVar35 + 0x1950);
    fVar16 = *(float *)(iVar35 + 0x1930);
    fVar17 = fVar13 * fVar29 + (fVar9 * fVar28 - fVar11 * fVar30);
    fVar23 = fVar1 * fVar13 - fVar10 * fVar15;
    fVar20 = fVar16 * fVar13 - fVar9 * fVar15;
    fVar22 = fVar1 * fVar9 - fVar10 * fVar16;
    fVar9 = fVar16 * fVar11 - fVar9 * fVar14;
    fVar21 = fVar1 * fVar17 + fVar16 * fVar19 + fVar15 * fVar31 + fVar14 * fVar18;
    fVar10 = fVar14 * fVar13 - fVar11 * fVar15;
    if ((fVar21 < FLOAT_001aa198) || (uVar36 = 0, FLOAT_001aa19c < fVar21)) {
      uVar36 = 1;
      fVar21 = FLOAT_001aa0e8 / fVar21;
      *(float *)(((unsigned char *)0x000013a4) + iVar34) =
           (fVar22 * fVar7 + (fVar9 * fVar5 - fVar24 * fVar6)) * fVar21;
      *(float *)(((unsigned char *)0x0000136c) + iVar34) =
           fVar21 * -(fVar16 * fVar28 - (fVar14 * fVar30 - fVar15 * fVar29));
      *(float *)(((unsigned char *)0x00001370) + iVar34) =
           (fVar9 * fVar4 + (fVar10 * fVar8 - fVar20 * fVar12)) * fVar21;
      *(float *)(((unsigned char *)0x00001388) + iVar34) = fVar18 * fVar21;
      *(float *)(((unsigned char *)0x00001374) + iVar34) =
           -(fVar10 * fVar6 - (fVar20 * fVar7 - fVar9 * fVar3)) * fVar21;
      *(float *)(((unsigned char *)0x0000137c) + iVar34) =
           fVar21 * (fVar15 * fVar25 + (fVar1 * fVar28 - fVar14 * fVar27));
      *(float *)(((unsigned char *)0x00001380) + iVar34) =
           -(fVar10 * fVar2 - (fVar23 * fVar12 - fVar24 * fVar4)) * fVar21;
      *(float *)(((unsigned char *)0x0000138c) + iVar34) =
           fVar21 * -(fVar1 * fVar30 - (fVar16 * fVar27 - fVar15 * fVar26));
      *(float *)(((unsigned char *)0x00001384) + iVar34) =
           (fVar24 * fVar3 + (fVar10 * fVar5 - fVar23 * fVar7)) * fVar21;
      *(float *)(((unsigned char *)0x0000139c) + iVar34) =
           fVar21 * (fVar14 * fVar26 + (fVar1 * fVar29 - fVar16 * fVar25));
      *(float *)(((unsigned char *)0x00001390) + iVar34) =
           (fVar22 * fVar4 + (fVar20 * fVar2 - fVar23 * fVar8)) * fVar21;
      *(float *)(((unsigned char *)0x00001368) + iVar34) = fVar17 * fVar21;
      *(float *)(((unsigned char *)0x00001378) + iVar34) = fVar19 * fVar21;
      *(float *)(((unsigned char *)0x00001394) + iVar34) =
           -(fVar20 * fVar5 - (fVar23 * fVar6 - fVar22 * fVar3)) * fVar21;
      *(float *)(((unsigned char *)0x00001398) + iVar34) = fVar31 * fVar21;
      *(float *)(((unsigned char *)0x000013a0) + iVar34) =
           -(fVar9 * fVar2 - (fVar24 * fVar8 - fVar22 * fVar12)) * fVar21;
    }
    uVar32 = *(uint *)(iVar34 + 0x38);
    uVar33 = *(uint *)(iVar34 + 0x40);
    ((unsigned char *)0x000013a8)[iVar34] = uVar36;
    *(uint *)(iVar34 + 0x40) = uVar33 | 0x20000;
    *(uint *)(iVar34 + 0x38) = uVar32 | 0x20080;
    *(undefined1 *)(iVar34 + 0x29) = 1;
    *(undefined2 *)(iVar34 + 0x36) = 0x3f;
  }
  if ((param_3 & 0xf8) != 0) {
    if ((param_3 & 0x10) == 0) {
      uVar32 = *(uint *)(iVar34 + 0x40);
    }
    else {
      uVar32 = *(uint *)(iVar34 + 0x40) | 0x10000;
      *(uint *)(iVar34 + 0x40) = uVar32;
    }
    if (((unsigned char *)0x00004301)[iVar35] != '\0') {
      uVar33 = (uint)(byte)((unsigned char *)0x00004300)[iVar35];
      if ((uint)(byte)((unsigned char *)0x000013b4)[iVar34] < (uint)(byte)((unsigned char *)0x00004300)[iVar35]) {
        uVar33 = (uint)(byte)((unsigned char *)0x000013b4)[iVar34];
      }
      if (1 < uVar33) {
        if ((param_3 & 0x20) == 0) {
          iVar35 = uVar33 - 1;
          uVar33 = 1;
          do {
            uVar33 = uVar33 + 1;
            iVar35 = iVar35 + -1;
            if (iVar35 == 0) goto LAB_000a89c0;
          } while ((param_3 & 0x10 << (uVar33 & 0x3f)) == 0);
        }
        uVar32 = uVar32 | 0x10000;
        *(uint *)(iVar34 + 0x40) = uVar32;
      }
    }
LAB_000a89c0:
    *(uint *)(iVar34 + 0x40) = uVar32 | 0x30000;
    *(undefined1 *)(iVar34 + 0x29) = 1;
    *(uint *)(iVar34 + 0x38) = *(uint *)(iVar34 + 0x38) | 0x80;
  }
  FUN_001a327c();
  return;
}

/* FUN_000a8a00 @ 0xa8a00 (488 bytes) */
int FUN_000a8a00(param_1, param_2)
  int param_1;
  uint param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined *puVar11;
  uint uVar12;
  int iVar13;
  
  fVar6 = FLOAT_001aa0e8;
  uVar12 = 0;
  iVar13 = 6;
  iVar8 = *(int *)(param_1 + 0x10);
  iVar7 = param_1 + 0x618;
  puVar11 = ((unsigned char *)0x00003e20) + iVar8;
  do {
    if (((0x1000000 << (uVar12 & 0x3f) | 8U) & param_2) != 0) {
      uVar9 = 1 << (uVar12 & 0x3f);
      if ((uVar9 & *(uint *)(((unsigned char *)0x00003e28) + iVar8)) != 0) {
        fVar1 = *(float *)(puVar11 + 0x18);
        iVar5 = uVar12 * 0x10;
        fVar2 = *(float *)(puVar11 + 0xc);
        fVar3 = *(float *)(puVar11 + 0x10);
        fVar4 = *(float *)(puVar11 + 0x14);
        iVar10 = iVar5 + iVar7;
        if (fVar1 == fVar6) {
          *(float *)(iVar7 + iVar5) =
               fVar4 * *(float *)(((unsigned char *)0x000015c8) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015a8) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015b8) + param_1) + *(float *)(((unsigned char *)0x000015d8) + param_1);
          *(float *)(iVar10 + 4) =
               fVar4 * *(float *)(((unsigned char *)0x000015cc) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015ac) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015bc) + param_1) + *(float *)(((unsigned char *)0x000015dc) + param_1);
          *(float *)(iVar10 + 8) =
               fVar4 * *(float *)(((unsigned char *)0x000015d0) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015b0) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015c0) + param_1) + *(float *)(((unsigned char *)0x000015e0) + param_1);
          *(float *)(iVar10 + 0xc) =
               fVar4 * *(float *)((int)((unsigned char *)0x000015d4) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015b4) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015c4) + param_1) + *(float *)(((unsigned char *)0x000015e4) + param_1);
        }
        else {
          *(float *)(iVar7 + iVar5) =
               fVar1 * *(float *)(((unsigned char *)0x000015d8) + param_1) +
               fVar4 * *(float *)(((unsigned char *)0x000015c8) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015a8) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015b8) + param_1);
          *(float *)(iVar10 + 4) =
               fVar1 * *(float *)(((unsigned char *)0x000015dc) + param_1) +
               fVar4 * *(float *)(((unsigned char *)0x000015cc) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015ac) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015bc) + param_1);
          *(float *)(iVar10 + 8) =
               fVar1 * *(float *)(((unsigned char *)0x000015e0) + param_1) +
               fVar4 * *(float *)(((unsigned char *)0x000015d0) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015b0) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015c0) + param_1);
          *(float *)(iVar10 + 0xc) =
               fVar1 * *(float *)(((unsigned char *)0x000015e4) + param_1) +
               fVar4 * *(float *)((int)((unsigned char *)0x000015d4) + param_1) +
               fVar2 * *(float *)(((unsigned char *)0x000015b4) + param_1) +
               fVar3 * *(float *)(((unsigned char *)0x000015c4) + param_1);
        }
      }
      *(ushort *)(param_1 + 0x276) = (ushort)uVar9 | *(ushort *)(param_1 + 0x276);
    }
    uVar12 = uVar12 + 1;
    puVar11 = puVar11 + 0x10;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  *(undefined1 *)(param_1 + 0x269) = 1;
  *(uint *)(param_1 + 0x278) = *(uint *)(param_1 + 0x278) | 0x20000;
  return;
}

/* FUN_000a8c00 @ 0xa8c00 (356 bytes) */
int FUN_000a8c00(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (((unsigned char *)0x00002e2d)[param_2] != '\0') {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(undefined1 *)(param_1 + 0x2940) = 1;
    *(uint *)(param_1 + 0x1808) = *(uint *)(param_1 + 0x1808) | 0x20000000;
  }
  if (((unsigned char *)0x00002e2c)[param_2] != '\0') {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(undefined1 *)(param_1 + 0x2940) = 1;
    *(uint *)(param_1 + 0x1808) = *(uint *)(param_1 + 0x1808) | 0x20000000;
  }
  iVar3 = *(int *)(param_1 + 4);
  if ((((unsigned char *)0x00002e2d)[*(int *)(iVar3 + 0x10)] != '\0') &&
     ((*(uint *)(param_1 + 0x44) & 0x20000) == 0)) {
    iVar3 = FUN_0001a010(iVar3,*(undefined4 *)(((unsigned char *)0x000026a0) + iVar3));
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 4);
      uVar4 = 1;
      goto LAB_000a8cb4;
    }
    iVar3 = *(int *)(param_1 + 4);
  }
  uVar4 = 0;
LAB_000a8cb4:
  uVar2 = *(uint *)(param_1 + 0x1928);
  uVar1 = uVar2 >> 4 & 1 ^ uVar4;
  *(uint *)(param_1 + 0x1928) = uVar2 & 0xffffffef | uVar1 | uVar4 << 4;
  if (((((unsigned char *)0x00002e2c)[*(int *)(iVar3 + 0x10)] == '\0') ||
      ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     (uVar5 = 1, *(short *)(((unsigned char *)0x00002e28) + *(int *)(iVar3 + 0x10)) == -1)) {
    uVar5 = 0;
  }
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 6;
  *(uint *)(param_1 + 0x1928) =
       uVar2 & 0xffffffe7 | uVar1 | uVar4 << 4 | (uVar2 & 8) >> 3 ^ uVar5 | uVar5 << 3;
  return;
}

/* FUN_000a8d70 @ 0xa8d70 (168 bytes) */
int FUN_000a8d70(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  
  if (((unsigned char *)0x00003178)[param_2] != '\0') {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(undefined1 *)(param_1 + 0x2940) = 1;
    *(uint *)(param_1 + 0x1808) = *(uint *)(param_1 + 0x1808) | 0x20000000;
  }
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 4;
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((((unsigned char *)0x00003178)[iVar1] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     ((*(short *)(((unsigned char *)0x00003170) + iVar1) != 0x1b02 && (*(short *)(((unsigned char *)0x00003172) + iVar1) != 0x1b02))
     )) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  *(uint *)(param_1 + 0x1928) =
       *(uint *)(param_1 + 0x1928) & 0xfffffffb | *(uint *)(param_1 + 0x1928) >> 2 & 1 ^ uVar2 |
       uVar2 << 2;
  return;
}

/* FUN_000a8e20 @ 0xa8e20 (544 bytes) */
int FUN_000a8e20(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_3 & 0x1000) == 0) {
    uVar4 = *(uint *)(param_1 + 0x44);
    uVar2 = (uint)(byte)((unsigned char *)0x00002e0b)[param_2];
    goto LAB_000a8ee8;
  }
  if (((unsigned char *)0x00002e0a)[param_2] == '\0') {
    uVar3 = *(uint *)(param_1 + 0x44);
LAB_000a8e54:
    uVar2 = 0;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x44);
    uVar2 = 1;
    if ((uVar3 & 0x2000) != 0) goto LAB_000a8e54;
  }
  uVar1 = *(uint *)(param_1 + 0x38);
  uVar4 = uVar2 << 0x18 | uVar3 & 0xfeffffff;
  *(uint *)(param_1 + 0x44) = uVar4;
  *(uint *)(param_1 + 0x38) = uVar1 | 0x100;
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
  *(uint *)(param_1 + 0x18a4) = uVar2 | *(uint *)(param_1 + 0x18a4) & 0xfffffffe;
  *(undefined1 *)(param_1 + 0x29) = 1;
  uVar2 = (uint)(byte)((unsigned char *)0x00002e0b)[param_2];
  if ((("}J3x})+x|B;x}k"[param_2 + 2] != '\0' || ((unsigned char *)0x00002e0b)[param_2] != 0) ||
      (uVar3 & 0x200000) != 0) || (uVar3 & 0x10000) != 0) {
    *(uint *)(param_1 + 0x38) = uVar1 | 0x120;
    uVar2 = (uint)(byte)((unsigned char *)0x00002e0b)[param_2];
  }
LAB_000a8ee8:
  if ((uVar4 >> 0x17 & 1) != uVar2) {
    uVar3 = *(uint *)(param_1 + 0x38);
    *(uint *)(param_1 + 0x44) = (uVar2 & 1) << 0x17 | uVar4 & 0xff7fffff;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(uint *)(param_1 + 0x38) = uVar3 | 0x120;
    if (*(int *)(param_1 + -0x70) != 0) {
      *(uint *)(param_1 + 0x38) = uVar3 | 0x2320;
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 2;
    }
    if (((unsigned char *)0x00004304)[param_2] == '\0') {
      if ((int)*(uint *)(param_1 + 0x44) < 0) {
        uVar2 = *(uint *)(param_1 + 0x18a4);
        uVar4 = (uint)(*(short *)("}J3x})+x|B;x}k" + param_2) == -0x7e06) << 2;
        *(uint *)(param_1 + 0x18a4) = uVar4 | uVar2 & 0xfffffffb;
        *(uint *)(param_1 + 0x18a4) =
             ((byte)"}J3x})+x|B;x}k"[param_2 + 4] & 1) << 1 | uVar4 | uVar2 & 0xfffffff9;
      }
      else {
        *(uint *)(param_1 + 0x18a4) =
             *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
      }
    }
    else {
      *(uint *)(param_1 + 0x18a4) =
           (uint)((undefined1 *)(*(uint *)(param_1 + 0x44) & 0x80040) == ((unsigned char *)0x00080040)) << 1 |
           *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
    }
  }
  if ((param_3 & 0x800) != 0) {
    uVar4 = *(uint *)(param_1 + 0x38);
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(uint *)(param_1 + 0x38) = uVar4 | 0x100;
    if ("}J3x})+x|B;x}k"[param_2 + 2] != '\0') {
      *(uint *)(param_1 + 0x38) = uVar4 | 0x120;
    }
    if (*(int *)(param_1 + -0x70) == 0) {
      if (*(int *)(param_1 + -0x74) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
        *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 3;
        return;
      }
      return;
    }
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2200;
    *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 2;
    return;
  }
  return;
}

/* FUN_000a9070 @ 0xa9070 (1476 bytes) */
int FUN_000a9070(param_1, param_2)
  int param_1;
  uint param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  undefined4 *puVar18;
  undefined2 *puVar19;
  
  uVar9 = param_2 | param_2 >> 0x10;
  uVar9 = (uVar9 | uVar9 >> 8) & 0xff;
  *(ushort *)(param_1 + 0x272) = (ushort)uVar9 | *(ushort *)(param_1 + 0x272);
  if (uVar9 != 0) {
    uVar16 = 0;
    iVar17 = 0;
    iVar15 = param_1 + 0x240;
    do {
      if ((uVar9 & 1) != 0) {
        puVar18 = (undefined4 *)(((unsigned char *)0x000031c4) + uVar16 * 0x7c + *(int *)(param_1 + 0x10));
        puVar19 = (undefined2 *)(param_1 + 0x690 + uVar16 * 0xcc);
        if ((uVar16 == *(uint *)(param_1 + 0x29ac)) && (*(int *)(param_1 + 0x29a8) != 0)) {
          iVar10 = *(int *)(*(int *)(param_1 + 0x29a8) + 0xbc);
          uVar13 = 1 << (uVar16 & 0x3f);
        }
        else {
          iVar10 = *(int *)(((unsigned char *)0x000013f8) + iVar15);
          uVar13 = 1 << (uVar16 & 0x3f);
          if (iVar10 == 0) {
            *(uint *)(param_1 + 0x29f4) = ~uVar13 & *(uint *)(param_1 + 0x29f4);
            *(uint *)(param_1 + 0x29f0) = ~uVar13 & *(uint *)(param_1 + 0x29f0);
          }
        }
        if ((param_2 & uVar13) != 0) {
          iVar14 = iVar17 + param_1 + 0x1ae4;
          *puVar19 = *(undefined2 *)(puVar18 + 5);
          uVar5 = *(ushort *)(puVar18 + 5);
          *(uint *)(iVar14 + 8) =
               (((uint)uVar5 * 0x3b >> 0xd & 1 | (uint)uVar5 * 0x107 >> 10 & 2 | uVar5 >> 3 & 4) ^ 1
               ) << 1 | *(uint *)(iVar14 + 8) & 0xfffffff1;
        }
        if ((param_2 & 0x10000 << (uVar16 & 0x3f)) != 0) {
          *(undefined4 *)(puVar19 + 0x10) = puVar18[0xf];
          if (iVar10 != 0) {
            iVar10 = iVar10 + 0x4c;
          }
          FUN_00086a10(param_1 + 0x240,puVar19,iVar10);
        }
        if ((param_2 & 0x100 << (uVar16 & 0x3f)) != 0) {
          *(undefined4 *)(puVar19 + 0x16) = *puVar18;
          *(undefined4 *)(puVar19 + 0x18) = puVar18[1];
          *(undefined4 *)(puVar19 + 0x1a) = puVar18[2];
          *(undefined4 *)(puVar19 + 0x1c) = puVar18[3];
          *(undefined1 *)(param_1 + 0x269) = 1;
          *(uint *)(param_1 + 0x27c) = *(uint *)(param_1 + 0x27c) | 0x400;
        }
        if ((param_2 & 0x1000000 << (uVar16 & 0x3f)) != 0) {
          uVar13 = (uint)*(ushort *)(puVar18 + 6);
          iVar10 = param_1 + 0x1ae8;
          uVar5 = *(ushort *)((int)puVar18 + 0x1a);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[1];
          puVar11 = (uint *)(iVar10 + iVar17);
          if (uVar13 != (ushort)puVar19[2]) {
            puVar19[2] = *(ushort *)(puVar18 + 6);
            puVar11[1] = ((uVar13 * 0xb5 >> 7 & 1 | uVar13 * 0x177 >> 8 & 2 |
                           uVar13 * 0x19f >> 6 & 4 | uVar13 * 0x1bb >> 5 & 8) ^ 0xf) << 7 |
                         puVar11[1] & 0xfffff87f;
          }
          uVar7 = puVar19[3];
          uVar8 = *(ushort *)(puVar18 + 7);
          uVar13 = (uint)uVar8;
          if (uVar12 != uVar6) {
            puVar19[1] = uVar5;
            puVar11[1] = ((uVar12 * 0xc3 >> 8 & 1 | uVar12 * 0x165 >> 9 & 2 | uVar12 * 0xb >> 8 & 4
                          | uVar12 * 0xcb >> 6 & 8) ^ 10) << 0xd | puVar11[1] & 0xfffe1fff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x22);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[6];
          if (uVar13 != uVar7) {
            puVar19[3] = uVar8;
            puVar11[1] = ((uVar13 * 0x11 >> 4 & 1 | uVar13 * 0x37 >> 6 & 2 | uVar13 * 0x51 >> 7 & 4
                          | uVar13 * 0x15 >> 6 & 8) ^ 0xc) << 0x18 | puVar11[1] & 0xf0ffffff;
          }
          uVar7 = *(ushort *)(puVar18 + 10);
          uVar8 = puVar19[9];
          if (uVar12 != uVar6) {
            puVar19[6] = uVar5;
            *(uint *)(iVar10 + iVar17) =
                 ((uVar12 * 0x11 >> 4 & 1 | uVar12 * 0x37 >> 6 & 2 | uVar12 * 0x51 >> 7 & 4 |
                  uVar12 * 0x15 >> 6 & 8) ^ 0xc) << 8 | *(uint *)(iVar10 + iVar17) & 0xfffff0ff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x2e);
          uVar6 = puVar19[0xc];
          if ((uint)uVar7 != (uint)uVar8) {
            puVar19[9] = uVar7;
            *(uint *)(iVar10 + iVar17) =
                 (uVar7 & 3) << 0x14 | *(uint *)(iVar10 + iVar17) & 0xffcfffff;
          }
          uVar7 = puVar19[4];
          uVar8 = *(ushort *)((int)puVar18 + 0x1e);
          uVar13 = (uint)uVar8;
          if ((uint)uVar5 != (uint)uVar6) {
            puVar19[0xc] = uVar5;
            *(uint *)(iVar10 + iVar17) =
                 (uVar5 & 1) << 0x1a | *(uint *)(iVar10 + iVar17) & 0xfbffffff;
          }
          uVar5 = *(ushort *)(puVar18 + 9);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[7];
          if (uVar13 != uVar7) {
            puVar19[4] = uVar8;
            puVar11[1] = ((uVar13 * 0x11 >> 4 & 1 | uVar13 * 0x37 >> 6 & 2 | uVar13 * 0x51 >> 7 & 4
                          | uVar13 * 0x15 >> 6 & 8) ^ 0xc) << 0x1c | puVar11[1] & 0xfffffff;
          }
          uVar7 = puVar19[10];
          uVar8 = *(ushort *)((int)puVar18 + 0x2a);
          if (uVar12 != uVar6) {
            puVar19[7] = uVar5;
            *(uint *)(iVar10 + iVar17) =
                 ((uVar12 * 0x11 >> 4 & 1 | uVar12 * 0x37 >> 6 & 2 | uVar12 * 0x51 >> 7 & 4 |
                  uVar12 * 0x15 >> 6 & 8) ^ 0xc) << 0xc | *(uint *)(iVar10 + iVar17) & 0xffff0fff;
          }
          uVar5 = *(ushort *)(puVar18 + 0xc);
          uVar6 = puVar19[0xd];
          if ((uint)uVar8 != (uint)uVar7) {
            puVar19[10] = uVar8;
            *(uint *)(iVar10 + iVar17) =
                 (uVar8 & 3) << 0x16 | *(uint *)(iVar10 + iVar17) & 0xff3fffff;
          }
          uVar7 = puVar19[5];
          uVar8 = *(ushort *)(puVar18 + 8);
          uVar13 = (uint)uVar8;
          if ((uint)uVar5 != (uint)uVar6) {
            puVar19[0xd] = uVar5;
            *(uint *)(iVar10 + iVar17) =
                 (uVar5 & 1) << 0x1b | *(uint *)(iVar10 + iVar17) & 0xf7ffffff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x26);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[8];
          if (uVar13 != uVar7) {
            puVar19[5] = uVar8;
            *puVar11 = ((uVar13 * 0x11 >> 4 & 1 | uVar13 * 0x37 >> 6 & 2 | uVar13 * 0x51 >> 7 & 4 |
                        uVar13 * 0x15 >> 6 & 8) ^ 0xc) << 4 | *puVar11 & 0xffffff0f;
          }
          uVar7 = puVar19[0xb];
          uVar8 = *(ushort *)(puVar18 + 0xb);
          if (uVar12 != uVar6) {
            puVar19[8] = uVar5;
            *puVar11 = ((uVar12 * 0x11 >> 4 & 1 | uVar12 * 0x37 >> 6 & 2 | uVar12 * 0x51 >> 7 & 4 |
                        uVar12 * 0x15 >> 6 & 8) ^ 0xc) << 0x10 | *puVar11 & 0xfff0ffff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x32);
          uVar6 = puVar19[0xe];
          if ((uint)uVar8 != (uint)uVar7) {
            puVar19[0xb] = uVar8;
            *puVar11 = (uVar8 & 3) << 0x18 | *puVar11 & 0xfcffffff;
          }
          fVar1 = (float)puVar18[0xd];
          fVar2 = *(float *)(puVar19 + 0x12);
          if ((uint)uVar5 != (uint)uVar6) {
            puVar19[0xe] = uVar5;
            *puVar11 = (uVar5 & 1) << 0x1c | *puVar11 & 0xefffffff;
          }
          fVar3 = (float)puVar18[0xe];
          fVar4 = *(float *)(puVar19 + 0x14);
          if (fVar1 != fVar2) {
            *(float *)(puVar19 + 0x12) = fVar1;
            uVar13 = 1;
            if (FLOAT_001aa128 < fVar1) {
              uVar13 = 3 - (fVar1 <= FLOAT_001aa158);
            }
            puVar11[1] = (uVar13 & 3) << 0xb | puVar11[1] & 0xffffe7ff;
          }
          if (fVar3 != fVar4) {
            *(float *)(puVar19 + 0x14) = fVar3;
            uVar13 = 1;
            if (FLOAT_001aa128 < fVar3) {
              uVar13 = 3 - (fVar3 <= FLOAT_001aa158);
            }
            puVar11[1] = (uVar13 & 3) << 0x11 | puVar11[1] & 0xfff9ffff;
          }
        }
      }
      uVar9 = uVar9 >> 1;
      uVar16 = uVar16 + 1;
      iVar17 = iVar17 + 8;
      iVar15 = iVar15 + 4;
    } while (uVar9 != 0);
  }
  *(uint *)(param_1 + 0x278) = *(uint *)(param_1 + 0x278) | 0x200;
  return;
}

/* FUN_000a9640 @ 0xa9640 (1116 bytes) */
int FUN_000a9640(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  bool bVar8;
  float fVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  double dVar13;
  
  bVar1 = ((unsigned char *)0x000030dc)[param_2];
  uVar10 = *(uint *)(param_1 + 0x44);
  uVar12 = (bVar1 & 1) << 0x1e;
  *(uint *)(param_1 + 0x44) = uVar12 | uVar10 & 0xbfffffff;
  bVar2 = ((unsigned char *)0x000030dd)[param_2];
  *(uint *)(param_1 + 0x44) = (bVar2 & 1) << 0x1d | uVar12 | uVar10 & 0x9fffffff;
  if ((bVar2 & 1) != 0 || (bVar1 & 1) != 0) {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    *(undefined1 *)(param_1 + 0x2940) = 1;
    *(uint *)(param_1 + 0x1808) = *(uint *)(param_1 + 0x1808) | 0x20000000;
  }
  uVar11 = *(undefined4 *)(((unsigned char *)0x000013d0) + param_1);
  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(((unsigned char *)0x000030e4) + param_2);
  dVar13 = DOUBLE_001aa250;
  fVar3 = *(float *)(((unsigned char *)0x000030c0) + param_2);
  fVar4 = *(float *)(((unsigned char *)0x000013c4) + param_1);
  *(float *)(param_1 + 0xf4) = fVar3;
  fVar5 = fVar3;
  if (fVar3 - fVar4 < 0.0) {
    fVar5 = fVar4;
  }
  fVar6 = fVar4;
  if (-(fVar3 - fVar4) < 0.0) {
    fVar6 = fVar5;
  }
  *(float *)(param_1 + 0x100) = fVar6;
  if (fVar3 <= (float)((double)CONCAT44(0x43300000,uVar11) - dVar13)) {
    *(undefined4 *)(param_1 + 0x108) = uVar11;
  }
  else {
    *(int *)(param_1 + 0x108) = (int)fVar3;
  }
  uVar11 = *(undefined4 *)(((unsigned char *)0x000013d4) + param_1);
  fVar3 = *(float *)(((unsigned char *)0x000030c4) + param_2);
  *(float *)(param_1 + 0xf8) = fVar3;
  fVar5 = *(float *)(((unsigned char *)0x000013c8) + param_1);
  fVar6 = fVar5;
  if (fVar3 - fVar5 < 0.0) {
    fVar6 = fVar3;
  }
  if (-(fVar3 - fVar5) < 0.0) {
    fVar6 = fVar5;
  }
  *(float *)(param_1 + 0x104) = fVar6;
  if ((float)((double)CONCAT44(0x43300000,uVar11) - DOUBLE_001aa250) <= fVar3) {
    *(undefined4 *)(param_1 + 0x10c) = uVar11;
  }
  else {
    *(int *)(param_1 + 0x10c) = (int)fVar3;
  }
  fVar3 = *(float *)(((unsigned char *)0x000013cc) + param_1);
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(((unsigned char *)0x000030bc) + param_2);
  fVar6 = *(float *)(((unsigned char *)0x000030bc) + param_2);
  fVar7 = fVar4;
  if ((fVar4 < fVar6) && (fVar7 = fVar5, fVar6 < fVar5)) {
    fVar7 = fVar3 * (float)((double)CONCAT44(0x43300000,
                                             (int)((fVar6 - fVar4) / fVar3 + FLOAT_001aa10c) ^
                                             0x80000000) - DOUBLE_001aa1e0) + fVar4;
  }
  *(float *)(param_1 + 0xe0) = fVar7;
  fVar9 = FLOAT_001aa0e8;
  fVar6 = *(float *)(((unsigned char *)0x000030bc) + param_2);
  fVar7 = fVar4;
  if ((fVar4 < fVar6) && (fVar7 = fVar5, fVar6 < fVar5)) {
    fVar7 = fVar3 * (float)((double)CONCAT44(0x43300000,
                                             (int)((fVar6 - fVar4) / fVar3 + FLOAT_001aa10c) ^
                                             0x80000000) - DOUBLE_001aa1e0) + fVar4;
  }
  *(int *)(param_1 + 0xe4) = (int)fVar7;
  *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(((unsigned char *)0x000030c8) + param_2);
  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(((unsigned char *)0x000030cc) + param_2);
  *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(((unsigned char *)0x000030d0) + param_2);
  uVar11 = *(undefined4 *)(((unsigned char *)0x000030d4) + param_2);
  *(float *)(param_1 + 0x11c) = fVar9;
  *(undefined4 *)(param_1 + 0x118) = uVar11;
  if (((*(float *)(((unsigned char *)0x000030cc) + param_2) == fVar9) &&
      (*(float *)(((unsigned char *)0x000030d0) + param_2) == FLOAT_001aa0d4)) &&
     (*(float *)(((unsigned char *)0x000030d4) + param_2) == FLOAT_001aa0d4)) {
    uVar12 = *(uint *)(param_1 + 0xe8) & 0xfffffffe;
    *(uint *)(param_1 + 0xe8) = uVar12;
    *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xff7fffff;
    *(uint *)(param_1 + 0x1928) =
         *(uint *)(param_1 + 0x1928) & 0xfffffffd | *(uint *)(param_1 + 0x1928) >> 1 & 1;
  }
  else {
    uVar12 = *(uint *)(param_1 + 0xe8) | 1;
    *(uint *)(param_1 + 0xe8) = uVar12;
    *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) | 0x800000;
    if (*(int *)(*(int *)(param_1 + 4) + 0x1cc) == 0) {
      *(uint *)(param_1 + 0x1928) =
           *(uint *)(param_1 + 0x1928) & 0xfffffffd | (*(uint *)(param_1 + 0x1928) ^ 2) >> 1 & 1 | 2
      ;
    }
  }
  if (*(short *)(((unsigned char *)0x000030e2) + param_2) == 0x60b4) {
    uVar12 = uVar12 & 0xfffffff7;
    *(uint *)(param_1 + 0xe8) = uVar12;
  }
  else {
    uVar12 = uVar12 | 8;
    *(uint *)(param_1 + 0xe8) = uVar12;
  }
  if ((*(int *)(param_1 + 0xe4) < 2) && ((uVar12 & 1) == 0)) {
    bVar8 = false;
    uVar11 = 0;
    if (*(int *)(param_1 + 0xec) == 0) goto LAB_000a99e8;
  }
  bVar8 = true;
  uVar11 = 1;
LAB_000a99e8:
  *(undefined4 *)(param_1 + 0x1940) = uVar11;
  if (bVar8) {
    fVar3 = *(float *)(*(int *)(param_1 + 4) + 0x2a54);
    fVar4 = *(float *)(*(int *)(param_1 + 4) + 0x2a58);
    fVar3 = (fVar3 + fVar3) * *(float *)(param_2 + 0x1810);
    fVar4 = (fVar4 + fVar4) * *(float *)(param_2 + 0x1814);
    if (fVar3 == FLOAT_001aa0d4) {
      *(float *)(param_1 + 400) = FLOAT_001aa0d4;
    }
    else {
      *(float *)(param_1 + 400) = FLOAT_001aa0e8 / fVar3;
    }
    if (fVar4 == FLOAT_001aa0d4) {
      *(float *)(param_1 + 0x194) = FLOAT_001aa0d4;
    }
    else {
      *(float *)(param_1 + 0x194) = FLOAT_001aa0e8 / fVar4;
    }
    dVar13 = (double)_sqrt((double)(*(float *)(param_1 + 400) * *(float *)(param_1 + 400) +
                                   *(float *)(param_1 + 0x194) * *(float *)(param_1 + 0x194)));
    *(float *)(param_1 + 0x198) = (float)dVar13;
  }
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0xc;
  return;
}

/* FUN_000a9ac0 @ 0xa9ac0 (7656 bytes) */
int FUN_000a9ac0(param_1, param_2)
  int param_1;
  uint *param_2;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  double dVar16;
  int iVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  uint uVar21;
  code *pcVar22;
  uint uVar23;
  char cVar25;
  int iVar24;
  int iVar26;
  undefined *puVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  int iVar31;
  uint uVar32;
  char cVar33;
  int unaff_r20;
  float unaff_r21;
  int iVar34;
  uint uVar35;
  int iVar36;
  uint uVar37;
  byte bVar39;
  int iVar38;
  int iVar40;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  float local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  float local_40;
  int local_3c;
  int local_38;
  int local_34;
  
  uVar37 = *param_2;
  iVar36 = *(int *)(param_1 + 4);
  uVar35 = param_2[2];
  if ((((uVar37 & 0x20000180) != 0) || (*(int *)(iVar36 + 0x2a48) != *(int *)(iVar36 + 0x15c))) ||
     (*(int *)(iVar36 + 0x2a4c) != *(int *)(iVar36 + 0x160))) {
    FUN_00019c50(iVar36);
  }
  if (*(char *)(iVar36 + 0x2a43) != '\0') {
    uVar35 = uVar35 | 1;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x400;
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1002;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  if (((unsigned char *)0x00002b7d)[iVar36] != '\0') {
    iVar31 = *(int *)(param_1 + 4);
    uVar21 = *(uint *)(iVar31 + 0x154) >> 6 & 1;
    ((unsigned char *)0x00001490)[param_1] = (char)uVar21;
    ((unsigned char *)0x00001491)[param_1] = (byte)(*(uint *)(iVar31 + 0x154) >> 7) & 1;
    if (uVar21 != 0) {
      uVar37 = uVar37 | 0x200;
    }
    uVar35 = uVar35 | 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
    uVar37 = uVar37 | 0x4000001;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x4000;
  }
  iVar34 = *(int *)(iVar36 + 0x10);
  uVar21 = param_2[3];
  iVar31 = *(int *)(((unsigned char *)0x00003e28) + iVar34);
  if (*(int *)(iVar36 + 0x1cc) == 0) {
    *(undefined4 *)(((unsigned char *)0x000026c4) + iVar36) = 0;
    *(undefined4 *)(((unsigned char *)0x000026c0) + iVar36) = 0;
    if (uVar35 == 0 && uVar21 == 0) goto LAB_000aaa50;
    if ((uVar21 & 0x4400000) != 0) {
      iVar17 = *(int *)(param_1 + -0x74);
      uVar28 = *(uint *)(param_1 + 0x44);
      iVar31 = iVar17 + -1 + (uint)(iVar17 == 0);
      if (iVar17 - iVar31 == (uVar28 >> 0x14 & 1)) {
        if (((iVar17 != iVar31) || (uVar28 >> 0x1f == (uint)(byte)"}J3x})+x|B;x}k"[iVar34 + 2])) ||
           (((unsigned char *)0x00004304)[iVar34] != '\0')) goto LAB_000a9de4;
LAB_000a9c74:
        uVar23 = *(uint *)(param_1 + 0x1874) >> 0x17 & 1;
        *(uint *)(param_1 + 0x1928) =
             *(uint *)(param_1 + 0x1928) & 0xfffffffd |
             *(uint *)(param_1 + 0x1928) >> 1 & 1 ^ uVar23 | uVar23 << 1;
        if (((unsigned char *)0x00004304)[iVar34] == '\0') {
          *(undefined1 *)(param_1 + 0x2475) = 1;
          uVar28 = (uint)(byte)"}J3x})+x|B;x}k"[iVar34 + 2] << 0x1f | uVar28 & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar28;
        }
        else if ((int)uVar28 < 0) {
          uVar28 = uVar28 & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar28;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
        }
        pcVar22 = *(code **)(((unsigned char *)0x000012b0) + param_1);
        *(uint *)(param_1 + 0x44) = uVar28 & 0xffe7ffff;
        *(undefined1 *)(param_1 + 299) = 1;
        (*pcVar22)(param_1);
        bVar39 = ((unsigned char *)0x000013b6)[param_1];
        *(undefined1 *)(param_1 + 0x29) = 1;
        uVar23 = *(uint *)(param_1 + 0x38) | 0x58a60;
        *(uint *)(param_1 + 0x38) = uVar23;
        *(ushort *)(param_1 + 0x34) =
             (short)(1 << (bVar39 & 0x3f)) - 1U | *(ushort *)(param_1 + 0x34);
      }
      else {
        if (iVar17 == iVar31) goto LAB_000a9c74;
        uVar23 = *(uint *)(param_1 + 0x38);
        *(uint *)(param_1 + 0x44) = uVar28 | 0x180000;
        *(undefined1 *)(param_1 + 299) = 1;
        *(uint *)(param_1 + 0x1928) =
             *(uint *)(param_1 + 0x1928) & 0xfffffffd | *(uint *)(param_1 + 0x1928) >> 1 & 1;
      }
      if (((unsigned char *)0x00004304)[iVar34] == '\0') {
        if ((int)*(uint *)(param_1 + 0x44) < 0) {
          uVar29 = *(uint *)(param_1 + 0x18a4);
          uVar28 = (uint)(*(short *)("}J3x})+x|B;x}k" + iVar34) == -0x7e06) << 2;
          *(uint *)(param_1 + 0x18a4) = uVar28 | uVar29 & 0xfffffffb;
          *(uint *)(param_1 + 0x18a4) =
               ((byte)"}J3x})+x|B;x}k"[iVar34 + 4] & 1) << 1 | uVar28 | uVar29 & 0xfffffff9;
        }
        else {
          *(uint *)(param_1 + 0x18a4) =
               *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
        }
      }
      else {
        *(uint *)(param_1 + 0x18a4) =
             (uint)((undefined1 *)(*(uint *)(param_1 + 0x44) & 0x80040) == ((unsigned char *)0x00080040)) << 1 |
             *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
      }
      *(uint *)(param_1 + 0x38) = uVar23 | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 0xf;
    }
LAB_000a9de4:
    if ((uVar21 & 0x7000000) != 0) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      bVar39 = *(byte *)(param_1 + 0x2e) | 2;
      if ((uVar21 & 0x5000000) != 0) {
        uVar29 = *(uint *)(param_1 + 0x44);
        bVar39 = *(byte *)(param_1 + 0x2e) | 3;
        uVar23 = uVar29 >> 0xf & 1;
        uVar28 = uVar29 >> 0xd & 1;
        if (*(int *)(param_1 + -0x70) == 0) {
          if (uVar28 == 0) {
            if (uVar23 != 0) {
              *(uint *)(param_1 + 0x44) = uVar29 & 0xfffd7fff;
              *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
              if ((uVar29 & 0x4000) != 0) {
                *(undefined1 *)(param_1 + 0x29) = 1;
                *(uint *)(param_1 + 0x44) = uVar29 & 0xfffc3fff;
                *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
              }
            }
          }
          else {
            *(uint *)(param_1 + 0x44) = uVar29 & 0xfffddfff;
            *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
            FUN_0008d470(param_1);
          }
        }
        else if (*(char *)(param_1 + 0x279c) == '\0') {
          if (uVar23 == 0) {
            if (uVar28 != 0) {
              *(uint *)(param_1 + 0x44) = uVar29 & 0xfffddfff;
              *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
              FUN_0008d470(param_1);
              uVar29 = *(uint *)(param_1 + 0x44);
            }
            iVar31 = *(int *)(((unsigned char *)0x00001144) + param_1);
            *(uint *)(param_1 + 0x44) = uVar29 | 0x28000;
            *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) | 0x4000;
            bVar2 = *(byte *)(iVar31 + 0x6c);
            uVar28 = (bVar2 & 1) << 0xe | uVar29 & 0xffffbfff | 0x28000;
            *(uint *)(param_1 + 0x44) = uVar28;
            if ((bVar2 & 1) != 0) {
              *(undefined1 *)(param_1 + 0x29) = 1;
              *(uint *)(param_1 + 0x44) = uVar28 | 0x10000;
              *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
            }
          }
          FUN_0003e320(param_1 + -0x240,param_2,0);
        }
        else if (uVar28 == 0) {
          if (uVar23 == 0) {
            uVar28 = *(uint *)(param_1 + 0x1874);
            uVar23 = uVar29;
          }
          else {
            uVar28 = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
            *(uint *)(param_1 + 0x44) = uVar29 & 0xfffd7fff;
            *(uint *)(param_1 + 0x1874) = uVar28;
            uVar23 = uVar29 & 0xfffd7fff;
            if ((uVar29 & 0x4000) != 0) {
              *(undefined1 *)(param_1 + 0x29) = 1;
              *(uint *)(param_1 + 0x44) = uVar29 & 0xfffc3fff;
              *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
              uVar23 = uVar29 & 0xfffc3fff;
            }
          }
          *(uint *)(param_1 + 0x1874) = uVar28 | 0x4000;
          *(uint *)(param_1 + 0x44) = uVar23 | 0x22000;
          *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x80000000;
          FUN_0008d470(param_1);
        }
        *(undefined1 *)(param_1 + 0x2475) = 1;
      }
      iVar31 = *(int *)(param_1 + 4);
      if ((((unsigned char *)0x00002e2d)[*(int *)(iVar31 + 0x10)] == '\0') ||
         ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) {
LAB_000a9ffc:
        uVar28 = 0;
      }
      else {
        iVar31 = FUN_0001a010(iVar31,*(undefined4 *)(((unsigned char *)0x000026a0) + iVar31));
        if (iVar31 != 0) {
          iVar31 = *(int *)(param_1 + 4);
          goto LAB_000a9ffc;
        }
        iVar31 = *(int *)(param_1 + 4);
        uVar28 = 1;
      }
      uVar29 = *(uint *)(param_1 + 0x1928);
      uVar23 = uVar29 >> 4 & 1 ^ uVar28;
      *(uint *)(param_1 + 0x1928) = uVar29 & 0xffffffef | uVar23 | uVar28 << 4;
      if (((((unsigned char *)0x00002e2c)[*(int *)(iVar31 + 0x10)] == '\0') ||
          ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
         (uVar32 = 1, *(short *)(((unsigned char *)0x00002e28) + *(int *)(iVar31 + 0x10)) == -1)) {
        uVar32 = 0;
      }
      *(byte *)(param_1 + 0x2e) = bVar39;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
      *(uint *)(param_1 + 0x1928) =
           uVar29 & 0xffffffe7 | uVar23 | uVar28 << 4 | (uVar29 & 8) >> 3 ^ uVar32 | uVar32 << 3;
    }
    dVar16 = DOUBLE_001aa200;
    if ((uVar35 & 1) != 0) {
      bVar39 = *(byte *)(iVar36 + 0x2a5c);
      iVar31 = *(int *)(iVar36 + 0x10);
      bVar2 = *(byte *)(iVar36 + 0x2a5d);
      *(ushort *)(((unsigned char *)0x000015fc) + iVar36) = (ushort)bVar39 * (short)*(undefined4 *)(iVar36 + 0x15c);
      *(ushort *)(((unsigned char *)0x000015fa) + iVar36) = (ushort)bVar2 * (short)*(undefined4 *)(iVar36 + 0x160);
      if ((*(double *)(FUN_00001830 + iVar31) == dVar16) && (*(double *)(iVar31 + 0x1838) == dVar16)
         ) {
        *(uint *)(iVar36 + 0x2cc) = *(uint *)(iVar36 + 0x2cc) | 0x400000;
      }
      if ((bVar39 < 2) || (bVar2 < 2)) {
        ((unsigned char *)0x00002690)[iVar36] = 0;
      }
      else {
        ((unsigned char *)0x00002690)[iVar36] = 1;
      }
      *(uint *)(iVar36 + 0x278) = *(uint *)(iVar36 + 0x278) | 0x400;
      *(uint *)(iVar36 + 0x27c) = *(uint *)(iVar36 + 0x27c) | 3;
      *(undefined1 *)(iVar36 + 0x269) = 1;
    }
    if ((uVar21 & 0x200000) != 0) {
      if (((unsigned char *)0x00004301)[iVar34] != '\0') {
        uVar35 = uVar35 | 0xf0;
      }
      iVar31 = *(int *)(iVar36 + 0x10);
      if ((((unsigned char *)0x00004301)[iVar31] == '\0') ||
         (uVar28 = (uint)(byte)((unsigned char *)0x000015f4)[iVar36], uVar28 == 0)) {
        iVar17 = 0;
        cVar25 = '\0';
      }
      else {
        iVar17 = 0;
        uVar23 = 0;
        if (uVar28 == 0) {
          uVar28 = 1;
        }
        do {
          if (((1 << ((byte)((unsigned char *)0x00004300)[iVar31] & 0x3f)) - 1U & 1 << (uVar23 & 0x3f)) != 0) {
            iVar17 = iVar17 + 1;
          }
          uVar23 = uVar23 + 1;
          uVar28 = uVar28 - 1;
        } while (uVar28 != 0);
        cVar25 = (char)iVar17;
      }
      *(char *)(iVar36 + 0x2d0) = cVar25;
      if ((iVar17 == 0) || (cVar33 = '\x01', ((unsigned char *)0x00004302)[iVar31] == '\0')) {
        cVar33 = '\0';
      }
      uVar28 = *(uint *)(iVar36 + 0x278);
      *(char *)(iVar36 + 0x2d1) = cVar25 - cVar33;
      *(undefined1 *)(iVar36 + 0x269) = 1;
      *(uint *)(iVar36 + 0x278) = uVar28 | 0x800;
      if ("}J3x})+x|B;x}k"[*(int *)(iVar36 + 0x10) + 2] != '\0') {
        *(uint *)(iVar36 + 0x278) = uVar28 | 0x820;
      }
    }
    bVar1 = (int)uVar35 < 0;
    if (uVar35 != 0) {
      if ((uVar35 & 0xff0000) != 0) {
        uVar28 = uVar35 >> 0x10 & 0xff;
        if (uVar28 != 0) {
          uVar23 = 0;
          do {
            if ((uVar28 & 1) != 0) {
              bVar1 = FLOAT_001aa0e8 == (float)(*(int *)(iVar36 + 0x10) + uVar23 * 0x40 + 0x1c60);
              if (((((((local_64 == 0 && local_60 == 0) && local_5c == 0) && bVar1) &&
                    (((local_58 == 0 && local_50 == 0) && local_4c == 0) &&
                    FLOAT_001aa0e8 == local_54)) &&
                   (((local_48 == 0 && local_44 == 0) && local_3c == 0) &&
                   FLOAT_001aa0e8 == local_40)) &&
                   (((local_38 == 0 && local_34 == 0) && unaff_r20 == 0) &&
                   FLOAT_001aa0e8 == unaff_r21)) &&
                 (*(char *)(uVar23 + *(int *)(iVar36 + 0x25c) + 0x2784) != '\0')) {
                uVar32 = ~(0x10000 << (uVar23 & 0x3f));
              }
              else {
                *(bool *)(uVar23 + *(int *)(iVar36 + 0x25c) + 0x2784) =
                     (((((local_64 == 0 && local_60 == 0) && local_5c == 0) && bVar1) &&
                      (((local_58 == 0 && local_50 == 0) && local_4c == 0) &&
                      FLOAT_001aa0e8 == local_54)) &&
                     (((local_48 == 0 && local_44 == 0) && local_3c == 0) &&
                     FLOAT_001aa0e8 == local_40)) &&
                     (((local_38 == 0 && local_34 == 0) && unaff_r20 == 0) &&
                     FLOAT_001aa0e8 == unaff_r21);
                uVar29 = 1 << (uVar23 & 0x3f);
                *(undefined1 *)(iVar36 + 0x269) = 1;
                uVar32 = 0xffffffff;
                *(ushort *)(iVar36 + 0x272) = (ushort)uVar29 | *(ushort *)(iVar36 + 0x272);
                *(uint *)(iVar36 + 0x278) = *(uint *)(iVar36 + 0x278) | 0x80;
                *(uint *)(iVar36 + 0x280) = uVar29 | *(uint *)(iVar36 + 0x280);
              }
              uVar35 = uVar35 & uVar32;
            }
            uVar28 = uVar28 >> 1;
            uVar23 = uVar23 + 1;
          } while (uVar28 != 0);
          bVar1 = (int)uVar35 < 0;
          if (uVar35 == 0) goto LAB_000aa35c;
        }
        ((unsigned char *)0x000026b5)[iVar36] = 1;
      }
LAB_000aa35c:
      if (((uVar35 & 0x40000000) != 0) && ("}J3x})+x|B;x}k"[iVar34 + 2] != '\0')) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      }
      if ((uVar35 & 0x3f0000f8) != 0) {
        ((int (*)())FUN_000a8630)(param_1,iVar34,uVar35);
      }
      if (((uVar35 & 0x800000f0) != 0) &&
         (((*(char *)(iVar34 + 0x24ae) != '\0' || (bVar1)) && ("}J3x})+x|B;x}k"[iVar34 + 2] != '\0')
          ))) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      }
      if ((uVar35 & 0x3f000008) != 0) {
        ((int (*)())FUN_000a8a00)(iVar36,uVar35);
      }
    }
    if ((uVar21 & 0x1007ffff) != 0) {
      if ((uVar21 & 0x7ffff) != 0) {
        if ((((unsigned char *)0x00004304)[iVar34] == '\0') || (*(int *)(param_1 + -0x74) != 0)) {
          uVar28 = (uint)(byte)"}J3x})+x|B;x}k"[iVar34 + 2] << 0x1f |
                   *(uint *)(param_1 + 0x44) & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar28;
        }
        else {
          uVar28 = *(uint *)(param_1 + 0x44) & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar28;
        }
        if (((unsigned char *)0x00004304)[iVar34] == '\0') {
          if ((int)uVar28 < 0) {
            uVar29 = *(uint *)(param_1 + 0x18a4);
            uVar23 = (uint)(*(short *)("}J3x})+x|B;x}k" + iVar34) == -0x7e06) << 2;
            *(uint *)(param_1 + 0x18a4) = uVar23 | uVar29 & 0xfffffffb;
            uVar23 = ((byte)"}J3x})+x|B;x}k"[iVar34 + 4] & 1) << 1 | uVar23 | uVar29 & 0xfffffff9;
            *(uint *)(param_1 + 0x18a4) = uVar23;
          }
          else {
            uVar23 = uVar28 >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
            *(uint *)(param_1 + 0x18a4) = uVar23;
          }
        }
        else {
          uVar23 = (uint)((undefined1 *)(uVar28 & 0x80040) == ((unsigned char *)0x00080040)) << 1 |
                   uVar28 >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
          *(uint *)(param_1 + 0x18a4) = uVar23;
        }
        bVar1 = (uVar28 & 0x80000000) == 0;
        if (!bVar1) {
          *(undefined1 *)(param_1 + 0x2f) = 0;
        }
        if ((uVar21 & 1) != 0) {
          *(undefined4 *)(param_1 + 0x1810) = 0x1f;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x10000;
          *(uint *)(param_1 + 0x180c) = *(uint *)(param_1 + 0x180c) | 7;
          *(undefined1 *)(param_1 + 0x29) = 1;
          if (((unsigned char *)0x00004304)[iVar34] == '\0') {
            if (bVar1) {
              *(uint *)(param_1 + 0x18a4) = uVar28 >> 0x15 & 4 | uVar23 & 0xfffffff9;
            }
            else {
              uVar28 = (uint)(*(short *)("}J3x})+x|B;x}k" + iVar34) == -0x7e06) << 2;
              *(uint *)(param_1 + 0x18a4) = uVar28 | uVar23 & 0xfffffffb;
              *(uint *)(param_1 + 0x18a4) =
                   ((byte)"}J3x})+x|B;x}k"[iVar34 + 4] & 1) << 1 | uVar28 | uVar23 & 0xfffffff9;
            }
          }
          else {
            *(uint *)(param_1 + 0x18a4) =
                 (uint)((undefined1 *)(*(uint *)(param_1 + 0x44) & 0x80040) == ((unsigned char *)0x00080040)) << 1 |
                 uVar28 >> 0x15 & 4 | uVar23 & 0xfffffff9;
          }
        }
        *(undefined4 *)(param_1 + 0x88) = 0;
        fVar15 = FLOAT_001aa1a4;
        fVar14 = FLOAT_001aa1a0;
        fVar13 = FLOAT_001aa158;
        fVar12 = FLOAT_001aa114;
        fVar11 = FLOAT_001aa0e8;
        iVar40 = 8;
        uVar28 = 0;
        iVar26 = 0x2500;
        puVar27 = ((unsigned char *)0x000014b0) + param_1;
        iVar38 = 0;
        iVar31 = param_1;
        iVar17 = iVar34;
        iVar30 = param_1;
        do {
          *(uint *)(param_1 + 0x88) =
               1 << (uVar28 & 0x3f) & *(uint *)(((unsigned char *)0x00002d40) + iVar34) | *(uint *)(param_1 + 0x88);
          fVar3 = FLOAT_001aa0d4;
          if ((uVar21 & (0xc << ((uVar28 & 0x1f) << 1) | 1U)) != 0) {
            iVar24 = iVar34 + iVar26;
            *(undefined4 *)(((unsigned char *)0x000014a4) + iVar30) = *(undefined4 *)(iVar17 + 0x24f0);
            *(undefined4 *)(((unsigned char *)0x000014a8) + iVar30) = *(undefined4 *)(iVar17 + 0x24f4);
            *(undefined4 *)(((unsigned char *)0x000014ac) + iVar30) = *(undefined4 *)(iVar17 + 0x24f8);
            *(undefined4 *)(((unsigned char *)0x000014b0) + iVar30) = *(undefined4 *)(iVar17 + 0x24fc);
            fVar4 = *(float *)(iVar34 + iVar26);
            fVar19 = *(float *)(iVar24 + 8) * *(float *)(iVar24 + 8) +
                     fVar4 * fVar4 + *(float *)(iVar24 + 4) * *(float *)(iVar24 + 4);
            if (fVar3 < fVar19) {
              if (fVar19 == fVar11) {
                *(float *)(puVar27 + 4) = fVar4;
                *(undefined4 *)(puVar27 + 8) = *(undefined4 *)(iVar24 + 4);
                *(undefined4 *)(puVar27 + 0xc) = *(undefined4 *)(iVar24 + 8);
              }
              else {
                fVar20 = (float)(0x5f375a00 - ((uint)fVar19 >> 1));
                fVar3 = fVar20 * fVar19 * fVar20;
                fVar19 = fVar13 - fVar3;
                fVar3 = fVar19 * fVar20 * fVar14 * -(fVar19 * fVar3 * fVar19 - fVar15);
                *(float *)(puVar27 + 4) = fVar4 * fVar3;
                *(float *)(puVar27 + 8) = fVar3 * *(float *)(iVar24 + 4);
                *(float *)(puVar27 + 0xc) = fVar3 * *(float *)(iVar24 + 8);
              }
            }
            else {
              *(float *)(puVar27 + 0xc) = fVar3;
              *(float *)(puVar27 + 4) = fVar3;
              *(float *)(puVar27 + 8) = fVar3;
            }
            fVar3 = FLOAT_001aa0d4;
            ((unsigned char *)0x0000150c)[iVar30] = *(float *)(iVar17 + 0x250c) != fVar12;
            *(undefined4 *)(((unsigned char *)0x00001504) + iVar30) = *(undefined4 *)(iVar17 + 0x250c);
            if (*(float *)(iVar17 + 0x2510) != fVar3) {
              *(float *)(((unsigned char *)0x00001508) + iVar30) = fVar11 / *(float *)(iVar17 + 0x2510);
            }
            fVar4 = FLOAT_001aa0d4;
            if (("}J3x})+x|B;x}k"[iVar34 + 5] == '\0') && (((unsigned char *)0x0000150c)[iVar30] == '\0')) {
              if (*(float *)(((unsigned char *)0x000014b0) + iVar30) == fVar3) {
                iVar24 = param_1 + iVar38;
                fVar4 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 4);
                fVar19 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 8);
                fVar20 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 0xc);
                fVar9 = fVar4 * fVar4 + fVar19 * fVar19;
                fVar8 = fVar20 * fVar20 + fVar9;
                fVar18 = fVar3;
                fVar5 = fVar3;
                fVar6 = FLOAT_001aa0e8;
                fVar7 = fVar3;
                if (fVar3 < fVar8) {
                  if (fVar8 == FLOAT_001aa0e8) {
                    fVar3 = fVar20;
                    fVar18 = fVar4;
                    fVar5 = fVar19;
                    fVar6 = fVar20 + FLOAT_001aa0e8;
                    fVar7 = fVar9;
                  }
                  else {
                    fVar18 = (float)(0x5f375a00 - ((uint)fVar8 >> 1));
                    fVar3 = fVar18 * fVar8 * fVar18;
                    fVar5 = fVar13 - fVar3;
                    fVar18 = fVar5 * fVar18 * fVar14 * -(fVar5 * fVar3 * fVar5 - fVar15);
                    fVar5 = fVar19 * fVar18;
                    fVar3 = fVar20 * fVar18;
                    fVar18 = fVar4 * fVar18;
                    fVar6 = fVar3 + FLOAT_001aa0e8;
                    fVar7 = fVar18 * fVar18 + fVar5 * fVar5;
                  }
                }
                fVar7 = fVar6 * fVar6 + fVar7;
                *(float *)(((unsigned char *)0x000014fc) + iVar30) = fVar3;
                *(float *)(((unsigned char *)0x000014f4) + iVar30) = fVar18;
                *(float *)(((unsigned char *)0x000014f8) + iVar30) = fVar5;
                fVar3 = FLOAT_001aa0d4;
                iVar24 = param_1 + iVar38;
                if (FLOAT_001aa0d4 < fVar7) {
                  if (fVar7 == fVar11) {
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 4) = fVar18;
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 0xc) = fVar6;
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 8) = fVar5;
                  }
                  else {
                    fVar19 = (float)(0x5f375a00 - ((uint)fVar7 >> 1));
                    fVar3 = fVar19 * fVar7 * fVar19;
                    fVar4 = fVar13 - fVar3;
                    fVar3 = fVar4 * fVar19 * fVar14 * -(fVar4 * fVar3 * fVar4 - fVar15);
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 4) = fVar3 * fVar18;
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 0xc) = fVar6 * fVar3;
                    *(float *)(((unsigned char *)0x000014e0) + iVar24 + 8) = fVar3 * fVar5;
                  }
                }
                else {
                  *(float *)(((unsigned char *)0x000014e0) + iVar24 + 4) = FLOAT_001aa0d4;
                  *(float *)(((unsigned char *)0x000014e0) + iVar24 + 0xc) = fVar3;
                  *(float *)(((unsigned char *)0x000014e0) + iVar24 + 8) = fVar3;
                }
              }
            }
            else if (*(float *)(((unsigned char *)0x000014b0) + iVar30) == FLOAT_001aa0d4) {
              iVar24 = param_1 + iVar38;
              iVar10 = param_1 + iVar38;
              fVar3 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 4);
              fVar19 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 0xc);
              fVar20 = *(float *)(((unsigned char *)0x000014a0) + iVar24 + 8);
              fVar19 = fVar19 * fVar19 + fVar3 * fVar3 + fVar20 * fVar20;
              if (FLOAT_001aa0d4 < fVar19) {
                if (fVar19 == fVar11) {
                  *(float *)(((unsigned char *)0x000014f0) + iVar10 + 4) = fVar3;
                  *(undefined4 *)(((unsigned char *)0x000014f0) + iVar10 + 8) =
                       *(undefined4 *)(((unsigned char *)0x000014a0) + iVar24 + 8);
                  *(undefined4 *)(((unsigned char *)0x000014f0) + iVar10 + 0xc) =
                       *(undefined4 *)(((unsigned char *)0x000014a0) + iVar24 + 0xc);
                }
                else {
                  fVar20 = (float)(0x5f375a00 - ((uint)fVar19 >> 1));
                  fVar4 = fVar20 * fVar19 * fVar20;
                  fVar19 = fVar13 - fVar4;
                  fVar4 = fVar19 * fVar20 * fVar14 * -(fVar19 * fVar4 * fVar19 - fVar15);
                  *(float *)(((unsigned char *)0x000014f0) + iVar10 + 4) = fVar3 * fVar4;
                  *(float *)(((unsigned char *)0x000014f0) + iVar10 + 8) =
                       fVar4 * *(float *)(((unsigned char *)0x000014a0) + iVar24 + 8);
                  *(float *)(((unsigned char *)0x000014f0) + iVar10 + 0xc) =
                       fVar4 * *(float *)(((unsigned char *)0x000014a0) + iVar24 + 0xc);
                }
              }
              else {
                *(float *)(((unsigned char *)0x000014f0) + iVar10 + 4) = FLOAT_001aa0d4;
                *(float *)(((unsigned char *)0x000014f0) + iVar10 + 0xc) = fVar4;
                *(float *)(((unsigned char *)0x000014f0) + iVar10 + 8) = fVar4;
              }
            }
            bVar39 = *(byte *)(iVar31 + 0x1814);
            bVar2 = *(byte *)(iVar31 + 0x181c);
            *(undefined1 *)(param_1 + 0x29) = 1;
            *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
            *(byte *)(iVar31 + 0x1814) = bVar39 | 0x3f;
            *(byte *)(iVar31 + 0x181c) = bVar2 | 3;
          }
          uVar28 = uVar28 + 1;
          iVar38 = iVar38 + 0x6c;
          puVar27 = puVar27 + 0x6c;
          iVar26 = iVar26 + 0x80;
          iVar31 = iVar31 + 1;
          iVar30 = iVar30 + 0x6c;
          iVar17 = iVar17 + 0x80;
          iVar40 = iVar40 + -1;
        } while (iVar40 != 0);
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      }
      if ((uVar21 & 0x10000000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
    }
LAB_000aaa50:
    uVar28 = param_2[1];
    uVar23 = param_2[4];
    if (uVar23 != 0 || (uVar28 & 0xff0000) != 0) {
      if ((uVar28 & 0xff0000) != 0) {
        ((int (*)())FUN_000a8340)(iVar36,uVar28);
      }
      if (uVar23 != 0) {
        ((int (*)())FUN_000a9070)(iVar36,uVar23);
      }
    }
    if (uVar37 != 0) {
      if ((uVar37 & 1) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1010;
      }
      if ((uVar37 & 6) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1018;
      }
      if ((uVar37 & 0x200) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
      }
      if ((uVar37 & 0x10000000) != 0) {
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
      }
      if ((uVar37 & 0x8000000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
      }
      if ((uVar37 & 0x4000000) != 0) {
        iVar38 = *(int *)(((unsigned char *)0x00003180) + iVar34);
        iVar26 = *(int *)(((unsigned char *)0x00003184) + iVar34);
        iVar30 = *(int *)(((unsigned char *)0x00003188) + iVar34);
        iVar40 = *(int *)(((unsigned char *)0x0000318c) + iVar34);
        iVar17 = *(int *)(param_1 + -0xe0);
        iVar31 = *(int *)(param_1 + -0xe4);
        *(int *)(param_1 + 0x440) = iVar38;
        *(int *)(param_1 + 0x444) = iVar26;
        *(int *)(param_1 + 0x448) = iVar30;
        *(int *)(param_1 + 0x44c) = iVar40;
        if (((unsigned char *)0x00003190)[iVar34] == '\0') {
          *(undefined4 *)(((unsigned char *)0x0000135c) + param_1) = 0;
          *(int *)(((unsigned char *)0x00001360) + param_1) = iVar31;
          *(int *)(((unsigned char *)0x00001364) + param_1) = iVar17;
          *(undefined4 *)(((unsigned char *)0x00001358) + param_1) = 0;
        }
        else {
          if (*(char *)(param_1 + 0x293c) != '\0') {
            iVar26 = iVar17 - (iVar26 + iVar40);
          }
          iVar30 = iVar38 + iVar30;
          iVar40 = iVar26 + iVar40;
          if (iVar38 < 0) {
            iVar38 = 0;
          }
          if (iVar26 < 0) {
            iVar26 = 0;
          }
          if (iVar30 <= iVar31) {
            iVar31 = iVar30;
          }
          if (iVar40 <= iVar17) {
            iVar17 = iVar40;
          }
          *(int *)(((unsigned char *)0x00001358) + param_1) = iVar38;
          *(int *)(((unsigned char *)0x0000135c) + param_1) = iVar26;
          *(int *)(((unsigned char *)0x00001360) + param_1) = iVar31;
          *(int *)(((unsigned char *)0x00001364) + param_1) = iVar17;
        }
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 2;
      }
      if ((uVar37 & 0x800000) != 0) {
        iVar31 = *(int *)(*(int *)(param_1 + 4) + 0x10);
        if (((((unsigned char *)0x00003178)[iVar31] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
           ((*(short *)(((unsigned char *)0x00003170) + iVar31) != 0x1b02 &&
            (*(short *)(((unsigned char *)0x00003172) + iVar31) != 0x1b02)))) {
          uVar23 = 0;
        }
        else {
          uVar23 = 1;
        }
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x4004;
        *(uint *)(param_1 + 0x1928) =
             *(uint *)(param_1 + 0x1928) & 0xfffffffb |
             *(uint *)(param_1 + 0x1928) >> 2 & 1 ^ uVar23 | uVar23 << 2;
      }
      if ((uVar37 & 0x1c0080) != 0) {
        if ((uVar37 & 0x40080) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
        }
        if ((uVar37 & 0x80000) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
        }
        if ((uVar37 & 0x100000) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
        }
      }
      uVar23 = uVar37 & 0xe363fd78;
      if (uVar23 != 0) {
        if ((uVar37 & 0x1800) != 0) {
          ((int (*)())FUN_000a8e20)(param_1,iVar34,uVar23);
        }
        if ((uVar37 & 0x3000000) != 0) {
          ((int (*)())FUN_000a8d70)(param_1,iVar34,uVar23);
        }
        if ((uVar37 & 0x38) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if ((uVar37 & 0x100) != 0) {
          ((int (*)())FUN_000a7e80)(param_1,iVar34);
        }
        if ((uVar37 & 0x400) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
        }
        if ((uVar37 & 0x2000) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
        }
        if ((uVar37 & 0x1c000) != 0) {
          ((int (*)())FUN_000a8c00)(param_1,iVar34);
        }
        if ((uVar37 & 0x20000) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
        }
        if ((uVar37 & 0x400000) != 0) {
          ((int (*)())FUN_000a9640)(param_1,iVar34);
        }
        if ((uVar37 & 0x20000000) != 0) {
          ((int (*)())FUN_000a7ea0)(param_1,iVar34);
        }
      }
    }
    if (((unsigned char *)0x000026b5)[iVar36] != '\0') {
      FUN_000bda40(param_1);
      ((unsigned char *)0x000026b5)[iVar36] = 0;
    }
    if ((((uVar37 & 0x401800) == 0 && (uVar28 & 0xffffff) == 0) && (uVar35 & 0x3fff0008) == 0) &&
        (uVar21 & 0x5400002) == 0) {
      return;
    }
    uVar35 = *(uint *)(iVar36 + 0x2cc);
    iVar31 = *(int *)(iVar36 + 0x10);
    if (((*(uint *)(iVar36 + 0x284) & 0x80000800) != 0) ||
       (((((*(uint *)(iVar36 + 0x284) & 0x1000000) != 0 &&
          (*(short *)(((unsigned char *)0x00002e06) + iVar31) == -0x7bae)) || ((*(uint *)(iVar36 + 0x328) & 1) != 0)
         ) || ((*(int *)(((unsigned char *)0x00003e28) + iVar31) != 0 || (uVar37 = 0, (uVar35 & 0xe000000) != 0)))))
       ) {
      uVar37 = 1;
    }
    *(uint *)(iVar36 + 0x2cc) = uVar37 << 0x13 | uVar35 & 0xfff7ffff;
    if ((uVar35 >> 0x13 & 1) == uVar37) {
      return;
    }
    if (((unsigned char *)0x00004301)[iVar31] == '\0') {
      return;
    }
    uVar35 = *(uint *)(iVar36 + 0x278);
    *(undefined1 *)(iVar36 + 0x269) = 1;
    *(uint *)(iVar36 + 0x278) = uVar35 | 0x800;
    if ("}J3x})+x|B;x}k"[iVar31 + 2] == '\0') {
      return;
    }
    *(uint *)(iVar36 + 0x278) = uVar35 | 0x820;
    return;
  }
  *(uint *)(((unsigned char *)0x000026c4) + iVar36) = uVar21 & 0x1027ffff;
  if (iVar31 == 0 && (uVar35 & 0x3f000000) == 0) {
    uVar23 = 0xc0ff00f8;
    uVar28 = 0x3f00ff07;
  }
  else {
    uVar23 = 0xc0ff00f0;
    uVar28 = 0x3f00ff0f;
  }
  uVar28 = uVar35 & uVar28;
  *(uint *)(((unsigned char *)0x000026c0) + iVar36) = uVar35 & uVar23;
  if ((uVar28 & 0xff00) != 0 || (uVar21 & 0x4c00000) != 0) {
    if ((uVar21 & 0x800000) != 0) {
      iVar31 = *(int *)(iVar36 + 0x10);
      uVar35 = *(uint *)(param_1 + 0x44);
      if ((uint)(byte)((unsigned char *)0x00004305)[iVar31] != (uVar35 >> 7 & 1)) {
        uVar35 = ((byte)((unsigned char *)0x00004305)[iVar31] & 1) << 7 | uVar35 & 0xffffff7f;
        *(uint *)(param_1 + 0x44) = uVar35;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1008;
        iVar31 = *(int *)(iVar36 + 0x10);
      }
      if ((uint)(byte)((unsigned char *)0x00004306)[iVar31] != (uVar35 >> 6 & 1)) {
        *(uint *)(param_1 + 0x44) = ((byte)((unsigned char *)0x00004306)[iVar31] & 1) << 6 | uVar35 & 0xffffffbf;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      }
    }
    if ((uVar21 & 0x4400000) != 0) {
      uVar23 = *(uint *)(param_1 + 0x44);
      uVar35 = (uint)(*(int *)(param_1 + -0x74) != 0);
      if (uVar35 == (uVar23 >> 0x14 & 1)) {
        if (((uVar35 != 0) || (uVar23 >> 0x1f == (uint)(byte)"}J3x})+x|B;x}k"[iVar34 + 2])) ||
           (((unsigned char *)0x00004304)[iVar34] != '\0')) goto LAB_000ab18c;
LAB_000ab014:
        uVar35 = *(uint *)(param_1 + 0x1874) >> 0x17 & 1;
        *(uint *)(param_1 + 0x1928) =
             *(uint *)(param_1 + 0x1928) & 0xfffffffd |
             *(uint *)(param_1 + 0x1928) >> 1 & 1 ^ uVar35 | uVar35 << 1;
        if (((unsigned char *)0x00004304)[iVar34] == '\0') {
          *(undefined1 *)(param_1 + 0x2475) = 1;
          uVar23 = (uint)(byte)"}J3x})+x|B;x}k"[iVar34 + 2] << 0x1f | uVar23 & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar23;
        }
        else if ((int)uVar23 < 0) {
          uVar23 = uVar23 & 0x7fffffff;
          *(uint *)(param_1 + 0x44) = uVar23;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
        }
        pcVar22 = *(code **)(((unsigned char *)0x000012b0) + param_1);
        *(uint *)(param_1 + 0x44) = uVar23 & 0xffe7ffff;
        *(undefined1 *)(param_1 + 299) = 1;
        (*pcVar22)(param_1);
        bVar39 = ((unsigned char *)0x000013b6)[param_1];
        *(undefined1 *)(param_1 + 0x29) = 1;
        uVar35 = *(uint *)(param_1 + 0x38) | 0x58a60;
        *(uint *)(param_1 + 0x38) = uVar35;
        *(ushort *)(param_1 + 0x34) =
             (short)(1 << (bVar39 & 0x3f)) - 1U | *(ushort *)(param_1 + 0x34);
      }
      else {
        if (uVar35 == 0) goto LAB_000ab014;
        uVar35 = *(uint *)(param_1 + 0x38);
        *(uint *)(param_1 + 0x44) = uVar23 | 0x180000;
        *(undefined1 *)(param_1 + 299) = 1;
        *(uint *)(param_1 + 0x1928) =
             *(uint *)(param_1 + 0x1928) & 0xfffffffd | *(uint *)(param_1 + 0x1928) >> 1 & 1;
      }
      if (((unsigned char *)0x00004304)[iVar34] == '\0') {
        if ((int)*(uint *)(param_1 + 0x44) < 0) {
          uVar29 = *(uint *)(param_1 + 0x18a4);
          uVar23 = (uint)(*(short *)("}J3x})+x|B;x}k" + iVar34) == -0x7e06) << 2;
          *(uint *)(param_1 + 0x18a4) = uVar23 | uVar29 & 0xfffffffb;
          *(uint *)(param_1 + 0x18a4) =
               ((byte)"}J3x})+x|B;x}k"[iVar34 + 4] & 1) << 1 | uVar23 | uVar29 & 0xfffffff9;
        }
        else {
          *(uint *)(param_1 + 0x18a4) =
               *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
        }
      }
      else {
        *(uint *)(param_1 + 0x18a4) =
             (uint)((undefined1 *)(*(uint *)(param_1 + 0x44) & 0x80040) == ((unsigned char *)0x00080040)) << 1 |
             *(uint *)(param_1 + 0x44) >> 0x15 & 4 | *(uint *)(param_1 + 0x18a4) & 0xfffffff9;
      }
      *(uint *)(param_1 + 0x38) = uVar35 | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 0xf;
    }
LAB_000ab18c:
    FUN_0003b160(iVar36,param_2,0);
  }
  if ((uVar21 & 0x7000000) == 0) goto LAB_000ab460;
  *(undefined1 *)(param_1 + 0x29) = 1;
  bVar39 = *(byte *)(param_1 + 0x2e) | 2;
  if ((uVar21 & 0x5000000) != 0) {
    uVar23 = *(uint *)(param_1 + 0x44);
    bVar39 = *(byte *)(param_1 + 0x2e) | 3;
    uVar21 = uVar23 >> 0xf & 1;
    uVar35 = uVar23 >> 0xd & 1;
    if (*(int *)(param_1 + -0x70) == 0) {
      if (uVar35 == 0) {
        if (uVar21 != 0) {
          *(uint *)(param_1 + 0x44) = uVar23 & 0xfffd7fff;
          *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
          if ((uVar23 & 0x4000) != 0) {
            *(undefined1 *)(param_1 + 0x29) = 1;
            *(uint *)(param_1 + 0x44) = uVar23 & 0xfffc3fff;
            *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
          }
        }
      }
      else {
        *(uint *)(param_1 + 0x44) = uVar23 & 0xfffddfff;
        *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
        FUN_0008d470(param_1);
      }
    }
    else if (*(char *)(param_1 + 0x279c) == '\0') {
      if (uVar21 == 0) {
        if (uVar35 != 0) {
          *(uint *)(param_1 + 0x44) = uVar23 & 0xfffddfff;
          *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
          FUN_0008d470(param_1);
          uVar23 = *(uint *)(param_1 + 0x44);
        }
        iVar31 = *(int *)(((unsigned char *)0x00001144) + param_1);
        *(uint *)(param_1 + 0x44) = uVar23 | 0x28000;
        *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) | 0x4000;
        bVar2 = *(byte *)(iVar31 + 0x6c);
        uVar35 = (bVar2 & 1) << 0xe | uVar23 & 0xffffbfff | 0x28000;
        *(uint *)(param_1 + 0x44) = uVar35;
        if ((bVar2 & 1) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x44) = uVar35 | 0x10000;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
        }
      }
      FUN_0003e320(param_1 + -0x240,param_2,0);
    }
    else if (uVar35 == 0) {
      if (uVar21 == 0) {
        uVar35 = *(uint *)(param_1 + 0x1874);
        uVar21 = uVar23;
      }
      else {
        uVar35 = *(uint *)(param_1 + 0x1874) & 0xffffbfff;
        *(uint *)(param_1 + 0x44) = uVar23 & 0xfffd7fff;
        *(uint *)(param_1 + 0x1874) = uVar35;
        uVar21 = uVar23 & 0xfffd7fff;
        if ((uVar23 & 0x4000) != 0) {
          *(undefined1 *)(param_1 + 0x29) = 1;
          *(uint *)(param_1 + 0x44) = uVar23 & 0xfffc3fff;
          *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
          uVar21 = uVar23 & 0xfffc3fff;
        }
      }
      *(uint *)(param_1 + 0x1874) = uVar35 | 0x4000;
      *(uint *)(param_1 + 0x44) = uVar21 | 0x22000;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x80000000;
      FUN_0008d470(param_1);
    }
    *(undefined1 *)(param_1 + 0x2475) = 1;
  }
  iVar31 = *(int *)(param_1 + 4);
  if ((((unsigned char *)0x00002e2d)[*(int *)(iVar31 + 0x10)] == '\0') ||
     ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) {
LAB_000ab3d0:
    uVar35 = 0;
  }
  else {
    iVar31 = FUN_0001a010(iVar31,*(undefined4 *)(((unsigned char *)0x000026a0) + iVar31));
    if (iVar31 != 0) {
      iVar31 = *(int *)(param_1 + 4);
      goto LAB_000ab3d0;
    }
    iVar31 = *(int *)(param_1 + 4);
    uVar35 = 1;
  }
  uVar23 = *(uint *)(param_1 + 0x1928);
  uVar21 = uVar23 >> 4 & 1 ^ uVar35;
  *(uint *)(param_1 + 0x1928) = uVar23 & 0xffffffef | uVar21 | uVar35 << 4;
  if (((((unsigned char *)0x00002e2c)[*(int *)(iVar31 + 0x10)] == '\0') ||
      ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     (uVar29 = 1, *(short *)(((unsigned char *)0x00002e28) + *(int *)(iVar31 + 0x10)) == -1)) {
    uVar29 = 0;
  }
  *(byte *)(param_1 + 0x2e) = bVar39;
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
  *(uint *)(param_1 + 0x1928) =
       uVar23 & 0xffffffe7 | uVar21 | uVar35 << 4 | (uVar23 & 8) >> 3 ^ uVar29 | uVar29 << 3;
LAB_000ab460:
  dVar16 = DOUBLE_001aa200;
  if (uVar28 != 0) {
    if ((uVar28 & 1) != 0) {
      bVar39 = *(byte *)(iVar36 + 0x2a5c);
      iVar31 = *(int *)(iVar36 + 0x10);
      bVar2 = *(byte *)(iVar36 + 0x2a5d);
      *(ushort *)(((unsigned char *)0x000015fc) + iVar36) = (ushort)bVar39 * (short)*(undefined4 *)(iVar36 + 0x15c);
      *(ushort *)(((unsigned char *)0x000015fa) + iVar36) = (ushort)bVar2 * (short)*(undefined4 *)(iVar36 + 0x160);
      if ((*(double *)(FUN_00001830 + iVar31) == dVar16) && (*(double *)(iVar31 + 0x1838) == dVar16)
         ) {
        *(uint *)(iVar36 + 0x2cc) = *(uint *)(iVar36 + 0x2cc) | 0x400000;
      }
      if ((bVar39 < 2) || (bVar2 < 2)) {
        ((unsigned char *)0x00002690)[iVar36] = 0;
      }
      else {
        ((unsigned char *)0x00002690)[iVar36] = 1;
      }
      *(undefined1 *)(iVar36 + 0x269) = 1;
      *(uint *)(iVar36 + 0x278) = *(uint *)(iVar36 + 0x278) | 0x400;
      *(uint *)(iVar36 + 0x27c) = *(uint *)(iVar36 + 0x27c) | 3;
    }
    if ((uVar28 & 0x3f000008) != 0) {
      ((int (*)())FUN_000a8630)(param_1,iVar34,uVar28);
      ((int (*)())FUN_000a8a00)(iVar36,uVar28);
    }
  }
  uVar35 = param_2[4];
  if (uVar35 != 0 || (param_2[1] & 0xff0000) != 0) {
    if ((param_2[1] & 0xff0000) != 0) {
      ((int (*)())FUN_000a8340)(iVar36);
    }
    if (uVar35 != 0) {
      ((int (*)())FUN_000a9070)(iVar36,uVar35);
    }
  }
  if (uVar37 != 0) {
    if ((uVar37 & 1) != 0) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1010;
    }
    if ((uVar37 & 6) != 0) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x1018;
    }
    if ((uVar37 & 0x200) != 0) {
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
    }
    if ((uVar37 & 0x10000000) != 0) {
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
    }
    if ((uVar37 & 0x8000000) != 0) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
    }
    if ((uVar37 & 0x4000000) != 0) {
      iVar26 = *(int *)(((unsigned char *)0x00003180) + iVar34);
      iVar30 = *(int *)(((unsigned char *)0x00003184) + iVar34);
      iVar17 = *(int *)(((unsigned char *)0x00003188) + iVar34);
      iVar38 = *(int *)(((unsigned char *)0x0000318c) + iVar34);
      iVar31 = *(int *)(param_1 + -0xe0);
      iVar36 = *(int *)(param_1 + -0xe4);
      *(int *)(param_1 + 0x440) = iVar26;
      *(int *)(param_1 + 0x444) = iVar30;
      *(int *)(param_1 + 0x448) = iVar17;
      *(int *)(param_1 + 0x44c) = iVar38;
      if (((unsigned char *)0x00003190)[iVar34] == '\0') {
        *(undefined4 *)(((unsigned char *)0x0000135c) + param_1) = 0;
        *(int *)(((unsigned char *)0x00001360) + param_1) = iVar36;
        *(int *)(((unsigned char *)0x00001364) + param_1) = iVar31;
        *(undefined4 *)(((unsigned char *)0x00001358) + param_1) = 0;
      }
      else {
        if (*(char *)(param_1 + 0x293c) != '\0') {
          iVar30 = iVar31 - (iVar30 + iVar38);
        }
        iVar17 = iVar26 + iVar17;
        iVar38 = iVar30 + iVar38;
        if (iVar26 < 0) {
          iVar26 = 0;
        }
        if (iVar30 < 0) {
          iVar30 = 0;
        }
        if (iVar17 <= iVar36) {
          iVar36 = iVar17;
        }
        if (iVar38 <= iVar31) {
          iVar31 = iVar38;
        }
        *(int *)(((unsigned char *)0x00001358) + param_1) = iVar26;
        *(int *)(((unsigned char *)0x0000135c) + param_1) = iVar30;
        *(int *)(((unsigned char *)0x00001360) + param_1) = iVar36;
        *(int *)(((unsigned char *)0x00001364) + param_1) = iVar31;
      }
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 2;
    }
    if ((uVar37 & 0x800000) != 0) {
      iVar36 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      if (((((unsigned char *)0x00003178)[iVar36] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
         ((*(short *)(((unsigned char *)0x00003170) + iVar36) != 0x1b02 &&
          (*(short *)(((unsigned char *)0x00003172) + iVar36) != 0x1b02)))) {
        uVar35 = 0;
      }
      else {
        uVar35 = 1;
      }
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x4004;
      *(uint *)(param_1 + 0x1928) =
           *(uint *)(param_1 + 0x1928) & 0xfffffffb | *(uint *)(param_1 + 0x1928) >> 2 & 1 ^ uVar35
           | uVar35 << 2;
    }
    if ((uVar37 & 0x1c0080) != 0) {
      if ((uVar37 & 0x40080) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
      }
      if ((uVar37 & 0x80000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
      }
      if ((uVar37 & 0x100000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
      }
    }
    uVar35 = uVar37 & 0xe363fd78;
    if (uVar35 != 0) {
      if ((uVar37 & 0x1800) != 0) {
        ((int (*)())FUN_000a8e20)(param_1,iVar34,uVar35);
      }
      if ((uVar37 & 0x3000000) != 0) {
        ((int (*)())FUN_000a8d70)(param_1,iVar34,uVar35);
      }
      if ((uVar37 & 0x38) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((uVar37 & 0x100) != 0) {
        ((int (*)())FUN_000a7e80)(param_1,iVar34);
      }
      if ((uVar37 & 0x400) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
      }
      if ((uVar37 & 0x2000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
      }
      if ((uVar37 & 0x1c000) != 0) {
        ((int (*)())FUN_000a8c00)(param_1,iVar34);
      }
      if ((uVar37 & 0x20000) != 0) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 8;
      }
      if ((uVar37 & 0x400000) != 0) {
        ((int (*)())FUN_000a9640)(param_1,iVar34);
      }
      if ((uVar37 & 0x20000000) != 0) {
        ((int (*)())FUN_000a7ea0)(param_1,iVar34);
      }
    }
  }
  return;
}

/* FUN_000ab900 @ 0xab900 (60 bytes) */
int FUN_000ab900(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 0x1868) != '\0') {
    *(undefined **)((int)((unsigned char *)0x000011cc) + param_1) = PTR_FUN_001e8b40;
    return;
  }
  *(undefined **)((int)((unsigned char *)0x000011cc) + param_1) = PTR_FUN_001e8b3c;
  return;
}

/* FUN_000ab940 @ 0xab940 (96 bytes) */
int FUN_000ab940(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
  undefined1 *param_5;
  int param_6;
{
  if (param_1 == 3) {
    if (param_2 == 1) {
      param_4[1] = 0x18;
      *param_4 = 0;
    }
    else {
      *param_4 = param_6;
      param_4[1] = 0x17;
    }
    *param_5 = 1;
    return;
  }
  *param_4 = param_2;
  param_4[1] = 4;
  *param_5 = 0;
  return;
}

/* FUN_000ab9b0 @ 0xab9b0 (240 bytes) */
int FUN_000ab9b0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int in_stack_00000038;
  int *in_stack_0000003c;
  
  if (param_1 == 1) {
    in_stack_00000038 = param_2 * 0x14 + in_stack_00000038;
    iVar1 = *(int *)(in_stack_00000038 + 8);
    iVar2 = *(int *)(in_stack_00000038 + 0xc);
    if (iVar1 == 1) {
      if (iVar2 == 0) {
        *in_stack_0000003c = 0;
        in_stack_0000003c[1] = 0x12;
        return;
      }
      in_stack_0000003c[1] = 0x13;
      *in_stack_0000003c = 0;
      return;
    }
    if (iVar1 == 3) {
      in_stack_0000003c[1] = 0x10;
      *in_stack_0000003c = 0;
      return;
    }
    if (iVar1 == 4) {
      in_stack_0000003c[1] = 0x16;
      *in_stack_0000003c = 0;
      return;
    }
    *in_stack_0000003c = iVar2;
    in_stack_0000003c[1] = 0x11;
    return;
  }
  if (param_1 == 0) {
    *in_stack_0000003c = param_2;
    in_stack_0000003c[1] = 4;
    return;
  }
  if (param_1 != 2) {
    return;
  }
  *in_stack_0000003c = param_2;
  in_stack_0000003c[1] = 1;
  return;
}

/* FUN_000abab0 @ 0xabab0 (164 bytes) */
int FUN_000abab0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined1 auStack_70 [16];
  undefined1 auStack_30 [20];
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x74) + 0x84) * -0x10;
  *(BADSPACEBASE **)(auStack_70 + iVar1) = ((unsigned int)__builtin_frame_address(0));
  FUN_00024fe0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(*(int *)(param_2 + 0x74) + 0x84),
               auStack_30 + iVar1);
  (**(code **)(((unsigned char *)0x00001280) + param_1))
            (param_1,param_3,0,0,auStack_30 + iVar1,*(undefined4 *)(*(int *)(param_2 + 0x74) + 0x84)
             ,1);
  return;
}

/* FUN_000abb60 @ 0xabb60 (96 bytes) */
int FUN_000abb60(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int *)(((unsigned char *)0x0000121c) + param_1) != 0) {
    iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000121c) + param_1) + 0x74);
    if (*(char *)(iVar1 + 0x54) == '\0') {
      iVar1 = *(int *)(*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 +
                       *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 8) + 0x14);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = *(int *)(iVar1 + 0x74);
    }
    if (iVar1 != 0) {
      return *(undefined4 *)(iVar1 + 8);
    }
  }
  return 0;
}

/* FUN_000abbd0 @ 0xabbd0 (312 bytes) */
int FUN_000abbd0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = (uint *)(param_1 + 4);
  if (param_2 != 0) {
    uVar4 = *(uint *)(param_1 + 4);
    puVar3 = (uint *)(param_1 + 8);
    if ((uVar4 & 0x3f0000) == 0x180000) {
      *(undefined1 *)(*(int *)(param_4 + 0x74) + 4) = 1;
    }
    if ((uVar4 & 0x400000) != 0) {
      puVar3 = (uint *)(param_1 + 0xc);
    }
  }
  puVar2 = puVar3;
  if (0 < param_3) {
    uVar4 = *puVar3;
    puVar2 = puVar3 + 1;
    if ((uVar4 & 0x400000) != 0) {
      puVar2 = puVar3 + 2;
    }
    if ((uVar4 >> 0x10 & 0x3f) - 1 < 2) {
      iVar1 = (uVar4 & 0xffff) + 1;
      if (*(int *)(*(int *)(param_4 + 0x74) + 0x84) < iVar1) {
        *(int *)(*(int *)(param_4 + 0x74) + 0x84) = iVar1;
      }
    }
  }
  puVar3 = puVar2;
  if (1 < param_3) {
    uVar4 = *puVar2;
    puVar3 = puVar2 + 1;
    if ((uVar4 & 0x400000) != 0) {
      puVar3 = puVar2 + 2;
    }
    if ((uVar4 >> 0x10 & 0x3f) - 1 < 2) {
      iVar1 = (uVar4 & 0xffff) + 1;
      if (*(int *)(*(int *)(param_4 + 0x74) + 0x84) < iVar1) {
        *(int *)(*(int *)(param_4 + 0x74) + 0x84) = iVar1;
      }
    }
  }
  if (param_3 < 3) {
    return puVar3;
  }
  uVar4 = *puVar3;
  puVar2 = puVar3 + 2;
  if ((uVar4 & 0x400000) == 0) {
    puVar2 = puVar3 + 1;
  }
  if (1 < (uVar4 >> 0x10 & 0x3f) - 1) {
    return puVar2;
  }
  iVar1 = (uVar4 & 0xffff) + 1;
  if (iVar1 <= *(int *)(*(int *)(param_4 + 0x74) + 0x84)) {
    return puVar2;
  }
  *(int *)(*(int *)(param_4 + 0x74) + 0x84) = iVar1;
  return puVar2;
}

/* FUN_000abd10 @ 0xabd10 (1640 bytes) */
int FUN_000abd10(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  uint uVar1;
  undefined4 uVar2;
  void *pvVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  float fVar7;
  float *pfVar8;
  undefined4 uVar9;
  int iVar10;
  size_t sVar11;
  float *pfVar12;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  float fStack_44;
  undefined4 local_40;
  float fStack_3c;
  undefined4 local_38;
  float fStack_34;
  undefined4 local_30;
  float fStack_2c;
  
  iVar10 = *(int *)(param_2 + 0x74);
  sVar11 = *(int *)(iVar10 + 0x5c) - 10;
  pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(int *)(iVar10 + 0x5c) + -6);
  param_3[2] = (uint)pvVar3;
  _memcpy(pvVar3,(void *)(*(int *)(iVar10 + 0x58) + 10),sVar11);
  uVar4 = param_3[2];
  pfVar12 = (float *)(uVar4 + 8);
  uVar1 = *(int *)(iVar10 + 0x5c) - 10U >> 2;
  *param_3 = uVar1;
  param_3[1] = uVar1 + 1;
  uVar9 = *(undefined4 *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 + *(int *)(param_2 + 0x70));
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 3) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 5) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0xc) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x10) = 0;
  **(undefined1 **)(param_2 + 0x74) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 1) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 2) = 0;
  *(undefined1 *)(param_2 + 0x6c) = 1;
  while (pfVar12 < (float *)(uVar4 + sVar11)) {
    fVar7 = *pfVar12;
    switch((uint)fVar7 & 0xffff) {
    default:
      goto switchD_000abe1c_caseD_0;
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
      pfVar12 = (float *)((int (*)())FUN_000abbd0)(pfVar12,1,1,param_2);
      break;
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
      pfVar12 = (float *)((int (*)())FUN_000abbd0)(pfVar12,1,2,param_2);
      break;
    case 10:
    case 0xd:
    case 0x21:
    case 0x2f:
    case 0x3f:
    case 0x40:
    case 100:
      pfVar12 = (float *)((int (*)())FUN_000abbd0)(pfVar12,1,3,param_2);
      break;
    case 0xf:
      pfVar12 = pfVar12 + *(ushort *)((int)pfVar12 + 6) + 2;
      break;
    case 0x14:
      pfVar12 = pfVar12 + 3;
      break;
    case 0x16:
      pfVar5 = pfVar12 + 1;
      pfVar12 = pfVar12 + 2;
      uVar1 = (uint)*pfVar5 >> 0x10 & 0x3f;
      if (uVar1 == 0x11) {
        *(uint *)(*(int *)(param_2 + 0x74) + 0xc) =
             1 << ((uint)*pfVar5 & 0x3f) | *(uint *)(*(int *)(param_2 + 0x74) + 0xc);
      }
      else if (uVar1 < 0x12) {
        if (uVar1 == 0x10) {
          *(undefined1 *)(*(int *)(param_2 + 0x74) + 1) = 1;
        }
      }
      else if (uVar1 == 0x13) {
        **(undefined1 **)(param_2 + 0x74) = 1;
      }
      else if (uVar1 == 0x16) {
        *(undefined1 *)(*(int *)(param_2 + 0x74) + 2) = 1;
      }
      break;
    case 0x18:
      break;
    case 0x19:
      uVar1 = (uint)fVar7 >> 0x10 & 0xff;
      pfVar12 = pfVar12 + 1;
      *(uint *)(*(int *)(param_2 + 0x74) + 0x10) =
           1 << ((uint)fVar7 >> 0x10 & 0x3f) | *(uint *)(*(int *)(param_2 + 0x74) + 0x10);
      switch((uint)fVar7 >> 0x18 & 7) {
      case 0:
        iVar10 = uVar1 * 4;
        if (*(int *)(((unsigned char *)0x000013f8) + iVar10 + param_1) == 0) {
switchD_000ac280_caseD_4:
          *(undefined4 *)(iVar10 + *(int *)(param_2 + 0x74) + 0x14) = 1;
        }
        else {
          switch(*(undefined1 *)(*(int *)(((unsigned char *)0x000013f8) + iVar10 + param_1) + 0x30)) {
          case 0:
            *(undefined4 *)(iVar10 + *(int *)(param_2 + 0x74) + 0x14) = 4;
            break;
          case 1:
            *(undefined4 *)(iVar10 + *(int *)(param_2 + 0x74) + 0x14) = 3;
            break;
          case 2:
            *(undefined4 *)(iVar10 + *(int *)(param_2 + 0x74) + 0x14) = 5;
            break;
          case 3:
            *(undefined4 *)(iVar10 + *(int *)(param_2 + 0x74) + 0x14) = 2;
            break;
          case 4:
            goto switchD_000ac280_caseD_4;
          }
        }
        break;
      case 1:
        *(undefined4 *)(uVar1 * 4 + *(int *)(param_2 + 0x74) + 0x14) = 1;
        break;
      case 2:
        uVar2 = 5;
        if (((uint)fVar7 & 0x18000000) != 0x10000000) {
          uVar2 = 2;
        }
        *(undefined4 *)(uVar1 * 4 + *(int *)(param_2 + 0x74) + 0x14) = uVar2;
        break;
      case 3:
        *(undefined4 *)(uVar1 * 4 + *(int *)(param_2 + 0x74) + 0x14) = 3;
        break;
      case 4:
        *(undefined4 *)(uVar1 * 4 + *(int *)(param_2 + 0x74) + 0x14) = 4;
      }
      break;
    case 0x1c:
      fVar7 = pfVar12[1];
      uVar1 = (uint)fVar7 >> 0x10 & 0x3f;
      if (uVar1 == 1) {
        (**(code **)(((unsigned char *)0x00001280) + param_1))
                  (param_1,uVar9,(uint)fVar7 & 0xffff,(uint)fVar7 & 0xffff,pfVar12 + 2,1,0);
        pfVar5 = pfVar12 + 6;
      }
      else {
        pfVar5 = pfVar12 + 1;
        if (uVar1 == 2) {
          local_48 = 0x43300000;
          fStack_44 = -pfVar12[2];
          local_58 = (float)((double)CONCAT44(0x43300000,fStack_44) - DOUBLE_001aa1e0);
          local_40 = 0x43300000;
          fStack_3c = -pfVar12[3];
          local_54 = (float)((double)CONCAT44(0x43300000,fStack_3c) - DOUBLE_001aa1e0);
          local_38 = 0x43300000;
          fStack_34 = -pfVar12[4];
          local_50 = (float)((double)CONCAT44(0x43300000,fStack_34) - DOUBLE_001aa1e0);
          local_30 = 0x43300000;
          fStack_2c = -pfVar12[5];
          local_4c = (float)((double)CONCAT44(0x43300000,fStack_2c) - DOUBLE_001aa1e0);
          (**(code **)(((unsigned char *)0x00001280) + param_1))
                    (param_1,uVar9,(uint)fVar7 & 0xffff,(uint)fVar7 & 0xffff,&local_58,1,0);
          pfVar5 = pfVar12 + 6;
        }
      }
      pfVar12 = pfVar5;
      iVar10 = ((uint)fVar7 & 0xffff) + 1;
      if (*(int *)(*(int *)(param_2 + 0x74) + 0x84) < iVar10) {
        *(int *)(*(int *)(param_2 + 0x74) + 0x84) = iVar10;
      }
      break;
    case 0x37:
      pfVar12 = (float *)((int (*)())FUN_000abbd0)(pfVar12,0,1,param_2);
      *(undefined1 *)(*(int *)(param_2 + 0x74) + 3) = 1;
      break;
    case 0x4b:
      pfVar12 = pfVar12 + 1;
      break;
    case 0x5d:
      pfVar5 = pfVar12 + 1;
      if ((int)fVar7 < 0) {
        pfVar5 = pfVar12 + 2;
      }
      if (((uint)fVar7 & 0x40000000) != 0) {
        pfVar5 = pfVar5 + 1;
      }
      fVar7 = *pfVar5;
      pfVar8 = pfVar5 + 1;
      if (((uint)fVar7 & 0x3f0000) == 0x180000) {
        *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = 1;
      }
      if (((uint)fVar7 & 0x400000) != 0) {
        pfVar8 = pfVar5 + 2;
      }
      local_58 = *pfVar8;
      pfVar12 = pfVar8 + 1;
      if (((uint)local_58 & 0x400000) != 0) {
        pfVar12 = pfVar8 + 2;
      }
      if (((uint)local_58 >> 0x10 & 0x3f) - 1 < 2) {
        iVar6 = *(int *)(param_2 + 0x74);
        iVar10 = ((uint)local_58 & 0xffff) + 1;
        if (*(int *)(iVar6 + 0x84) < iVar10) {
LAB_000ac4f8:
          *(int *)(iVar6 + 0x84) = iVar10;
        }
      }
      break;
    case 0x5e:
      pfVar5 = pfVar12 + 1;
      if ((int)fVar7 < 0) {
        pfVar5 = pfVar12 + 2;
      }
      if (((uint)fVar7 & 0x40000000) != 0) {
        pfVar5 = pfVar5 + 1;
      }
      fVar7 = *pfVar5;
      pfVar12 = pfVar5 + 1;
      if (((uint)fVar7 & 0x3f0000) == 0x180000) {
        *(undefined1 *)(*(int *)(param_2 + 0x74) + 4) = 1;
      }
      if (((uint)fVar7 & 0x400000) != 0) {
        pfVar12 = pfVar5 + 2;
      }
      local_58 = *pfVar12;
      pfVar5 = pfVar12 + 1;
      if (((uint)local_58 & 0x400000) != 0) {
        pfVar5 = pfVar12 + 2;
      }
      if (((uint)local_58 >> 0x10 & 0x3f) - 1 < 2) {
        iVar10 = ((uint)local_58 & 0xffff) + 1;
        if (*(int *)(*(int *)(param_2 + 0x74) + 0x84) < iVar10) {
          *(int *)(*(int *)(param_2 + 0x74) + 0x84) = iVar10;
        }
      }
      local_54 = *pfVar5;
      pfVar12 = pfVar5 + 1;
      if (((uint)local_54 & 0x400000) != 0) {
        pfVar12 = pfVar5 + 2;
      }
      if (((uint)local_54 >> 0x10 & 0x3f) - 1 < 2) {
        iVar6 = *(int *)(param_2 + 0x74);
        iVar10 = ((uint)local_54 & 0xffff) + 1;
        if (*(int *)(iVar6 + 0x84) < iVar10) goto LAB_000ac4f8;
      }
    }
  }
switchD_000abe1c_caseD_0:
  return 1;
}

/* FUN_000ac540 @ 0xac540 (476 bytes) */
int FUN_000ac540(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  uint param_3;
  uint param_4;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0xe;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = param_4 & 0xffff | 0x170000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = param_3 & 0xffff | 0x40000;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000ac720 @ 0xac720 (7944 bytes) */
int FUN_000ac720(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint *param_3;
  int param_4;
  uint *param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  void *pvVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint *in_stack_00000038;
  char in_stack_0000003f;
  char in_stack_00000043;
  char in_stack_00000047;
  undefined4 in_stack_00000048;
  undefined4 in_stack_0000004c;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000058;
  undefined4 in_stack_0000005c;
  undefined4 in_stack_00000060;
  undefined4 in_stack_00000064;
  undefined4 in_stack_00000068;
  undefined4 in_stack_0000006c;
  undefined4 in_stack_00000070;
  undefined4 in_stack_00000074;
  undefined4 in_stack_00000078;
  undefined4 local_88[0];
  uint local_84;
  uint local_80;
  uint local_7c [9];
  int local_58;
  undefined4 local_54;
  
  uVar19 = 0;
  uVar14 = 0;
  local_58 = param_2;
  local_88[0] = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c[0] = 0;
  local_7c[1] = 0;
  local_7c[2] = 0;
  local_54 = in_stack_00000078;
  if ((param_4 - 0x21U < 0x20) && ((1 << (param_4 - 0x21U & 0x3f) & 0x8fffffffU) != 0)) {
    uVar19 = 0x100;
  }
  if (param_5[1] == 0x18) {
    uVar19 = 0x100;
  }
  uVar13 = param_6 >> 2 & 1;
  uVar2 = (param_6 >> 1 & 1) << 2;
  uVar3 = uVar13 << 4;
  uVar17 = (param_5[1] & 0x3f) << 0x10 | *param_5 & 0xffff | 0x400000;
  uVar4 = (param_6 >> 3 & 1) << 6;
  uVar20 = uVar4 | uVar3 | uVar2 | param_6 & 1 | uVar19;
  switch(param_4) {
  case 0:
  case 3:
  case 8:
  case 9:
  case 10:
  case 0xc:
  case 0x12:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x19:
  case 0x1c:
  case 0x21:
  case 0x24:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x32:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x39:
  case 0x3c:
    iVar15 = 1;
    goto LAB_000ad33c;
  case 1:
  case 4:
  case 5:
  case 6:
  case 7:
  case 0x10:
  case 0x11:
  case 0x13:
  case 0x14:
  case 0x18:
  case 0x1a:
  case 0x1b:
  case 0x20:
  case 0x22:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x30:
  case 0x31:
  case 0x33:
  case 0x34:
  case 0x38:
  case 0x3a:
  case 0x3b:
  case 0x40:
    iVar15 = 1;
    goto LAB_000ace5c;
  case 2:
  case 0xe:
  case 0xf:
  case 0x23:
  case 0x2e:
  case 0x2f:
    local_7c[6] = in_stack_00000074;
    local_7c[5] = in_stack_00000070;
    local_7c[4] = in_stack_0000006c;
    local_7c[3] = in_stack_00000068;
    local_80 = *in_stack_00000038 & 0xffff;
    local_80 = (in_stack_00000038[1] & 0x3f) << 0x10 | local_80 | 0x400000;
    if (in_stack_00000038[1] == 0x10) {
      iVar16 = 0;
      iVar15 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + iVar16 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        iVar15 = iVar15 + -1;
        *(undefined4 *)((int)local_7c + iVar16 + 0xc) = uVar5;
        iVar16 = iVar16 + 4;
      } while (iVar15 != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      local_7c[2] = 0;
      break;
    case 1:
      bVar1 = false;
      local_7c[2] = 1;
      break;
    case 2:
      bVar1 = false;
      local_7c[2] = 2;
      break;
    case 3:
      bVar1 = false;
      local_7c[2] = 3;
      break;
    case 4:
      bVar1 = false;
      local_7c[2] = 4;
      break;
    case 5:
      bVar1 = false;
      local_7c[2] = 5;
      break;
    case 6:
      bVar1 = true;
      local_7c[2] = 0;
      break;
    case 7:
      bVar1 = true;
      local_7c[2] = 1;
      break;
    case 8:
      bVar1 = true;
      local_7c[2] = 2;
      break;
    case 9:
      bVar1 = true;
      local_7c[2] = 3;
      break;
    case 10:
      bVar1 = true;
      local_7c[2] = 5;
    }
    if (bVar1) {
      local_7c[2] = local_7c[2] | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[2] = iVar15 << 4 | local_7c[2];
    if (bVar1) {
      local_7c[2] = local_7c[2] | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[2] = iVar15 << 8 | local_7c[2];
    if (bVar1) {
      local_7c[2] = local_7c[2] | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[2] = iVar15 << 0xc | local_7c[2];
    if (bVar1) {
      local_7c[2] = local_7c[2] | 0x8000;
    }
    iVar15 = 2;
    if (in_stack_00000047 != '\0') {
      local_7c[2] = (local_7c[2] & 0xfffff777 ^ 0x8000) & 0x8000 |
                    (local_7c[2] & 0xffffff77 ^ 0x800) & 0x800 |
                    (local_7c[2] & 0xfffffff7 ^ 0x80) & 0x80 |
                    (local_7c[2] ^ 8) & 8 | local_7c[2] & 0xffff7777;
    }
LAB_000ace5c:
    local_7c[6] = in_stack_00000064;
    local_7c[5] = in_stack_00000060;
    local_7c[4] = in_stack_0000005c;
    local_7c[3] = in_stack_00000058;
    local_84 = (param_8[1] & 0x3f) << 0x10 | *param_8 & 0xffff | 0x400000;
    if (param_8[1] == 0x10) {
      iVar21 = 0;
      iVar16 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + iVar21 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        iVar16 = iVar16 + -1;
        *(undefined4 *)((int)local_7c + iVar21 + 0xc) = uVar5;
        iVar21 = iVar21 + 4;
      } while (iVar16 != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      local_7c[1] = 0;
      break;
    case 1:
      bVar1 = false;
      local_7c[1] = 1;
      break;
    case 2:
      bVar1 = false;
      local_7c[1] = 2;
      break;
    case 3:
      bVar1 = false;
      local_7c[1] = 3;
      break;
    case 4:
      bVar1 = false;
      local_7c[1] = 4;
      break;
    case 5:
      bVar1 = false;
      local_7c[1] = 5;
      break;
    case 6:
      bVar1 = true;
      local_7c[1] = 0;
      break;
    case 7:
      bVar1 = true;
      local_7c[1] = 1;
      break;
    case 8:
      bVar1 = true;
      local_7c[1] = 2;
      break;
    case 9:
      bVar1 = true;
      local_7c[1] = 3;
      break;
    case 10:
      bVar1 = true;
      local_7c[1] = 5;
    }
    if (bVar1) {
      local_7c[1] = local_7c[1] | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[1] = iVar16 << 4 | local_7c[1];
    if (bVar1) {
      local_7c[1] = local_7c[1] | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[1] = iVar16 << 8 | local_7c[1];
    if (bVar1) {
      local_7c[1] = local_7c[1] | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[1] = iVar16 << 0xc | local_7c[1];
    if (bVar1) {
      local_7c[1] = local_7c[1] | 0x8000;
    }
    iVar15 = iVar15 + 1;
    if (in_stack_00000043 != '\0') {
      local_7c[1] = (local_7c[1] & 0xfffff777 ^ 0x8000) & 0x8000 |
                    (local_7c[1] & 0xffffff77 ^ 0x800) & 0x800 |
                    (local_7c[1] & 0xfffffff7 ^ 0x80) & 0x80 |
                    (local_7c[1] ^ 8) & 8 | local_7c[1] & 0xffff7777;
    }
LAB_000ad33c:
    local_7c[6] = in_stack_00000054;
    local_7c[5] = in_stack_00000050;
    local_7c[4] = in_stack_0000004c;
    local_7c[3] = in_stack_00000048;
    local_88[0] = (param_7[1] & 0x3f) << 0x10 | *param_7 & 0xffff | 0x400000;
    if (param_7[1] == 0x10) {
      iVar21 = 0;
      iVar16 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + iVar21 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        iVar16 = iVar16 + -1;
        *(undefined4 *)((int)local_7c + iVar21 + 0xc) = uVar5;
        iVar21 = iVar21 + 4;
      } while (iVar16 != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      local_7c[0] = 0;
      break;
    case 1:
      bVar1 = false;
      local_7c[0] = 1;
      break;
    case 2:
      bVar1 = false;
      local_7c[0] = 2;
      break;
    case 3:
      bVar1 = false;
      local_7c[0] = 3;
      break;
    case 4:
      bVar1 = false;
      local_7c[0] = 4;
      break;
    case 5:
      bVar1 = false;
      local_7c[0] = 5;
      break;
    case 6:
      bVar1 = true;
      local_7c[0] = 0;
      break;
    case 7:
      bVar1 = true;
      local_7c[0] = 1;
      break;
    case 8:
      bVar1 = true;
      local_7c[0] = 2;
      break;
    case 9:
      bVar1 = true;
      local_7c[0] = 3;
      break;
    case 10:
      bVar1 = true;
      local_7c[0] = 5;
    }
    if (bVar1) {
      local_7c[0] = local_7c[0] | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[0] = iVar16 << 4 | local_7c[0];
    if (bVar1) {
      local_7c[0] = local_7c[0] | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[0] = iVar16 << 8 | local_7c[0];
    if (bVar1) {
      local_7c[0] = local_7c[0] | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar16 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar16 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar16 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar16 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar16 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar16 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar16 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar16 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar16 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar16 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar16 = 5;
    }
    local_7c[0] = iVar16 << 0xc | local_7c[0];
    if (bVar1) {
      local_7c[0] = local_7c[0] | 0x8000;
    }
    if (in_stack_0000003f != '\0') {
      local_7c[0] = (local_7c[0] & 0xfffff777 ^ 0x8000) & 0x8000 |
                    (local_7c[0] & 0xffffff77 ^ 0x800) & 0x800 |
                    (local_7c[0] & 0xfffffff7 ^ 0x80) & 0x80 |
                    (local_7c[0] ^ 8) & 8 | local_7c[0] & 0xffff7777;
    }
    break;
  default:
    iVar15 = 0;
    break;
  case 0xd:
  case 0x2d:
    uVar6 = *param_7;
    uVar10 = param_7[1];
    local_7c[6] = in_stack_00000054;
    local_7c[5] = in_stack_00000050;
    local_7c[4] = in_stack_0000004c;
    local_7c[3] = in_stack_00000048;
    uVar8 = *(int *)(param_2 + 0x88) + 2;
    uVar12 = uVar8 & 0xffff;
    if (uVar10 == 0x10) {
      iVar16 = 0;
      iVar15 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + iVar16 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        iVar15 = iVar15 + -1;
        *(undefined4 *)((int)local_7c + iVar16 + 0xc) = uVar5;
        iVar16 = iVar16 + 4;
      } while (iVar15 != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      uVar7 = 0;
      break;
    case 1:
      bVar1 = false;
      uVar7 = 1;
      break;
    case 2:
      bVar1 = false;
      uVar7 = 2;
      break;
    case 3:
      bVar1 = false;
      uVar7 = 3;
      break;
    case 4:
      bVar1 = false;
      uVar7 = 4;
      break;
    case 5:
      bVar1 = false;
      uVar7 = 5;
      break;
    case 6:
      bVar1 = true;
      uVar7 = 0;
      break;
    case 7:
      bVar1 = true;
      uVar7 = 1;
      break;
    case 8:
      bVar1 = true;
      uVar7 = 2;
      break;
    case 9:
      bVar1 = true;
      uVar7 = 3;
      break;
    case 10:
      bVar1 = true;
      uVar7 = 5;
    }
    if (bVar1) {
      uVar7 = uVar7 | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    uVar7 = iVar15 << 4 | uVar7;
    if (bVar1) {
      uVar7 = uVar7 | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    uVar7 = iVar15 << 8 | uVar7;
    if (bVar1) {
      uVar7 = uVar7 | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    uVar7 = iVar15 << 0xc | uVar7;
    if (bVar1) {
      uVar7 = uVar7 | 0x8000;
    }
    if (in_stack_0000003f != '\0') {
      uVar7 = (uVar7 & 0xfffff777 ^ 0x8000) & 0x8000 |
              (uVar7 & 0xffffff77 ^ 0x800) & 0x800 |
              (uVar7 & 0xfffffff7 ^ 0x80) & 0x80 | (uVar7 ^ 8) & 8 | uVar7 & 0xffff7777;
    }
    uVar11 = *param_3;
    if (param_3[1] <= uVar11) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar11 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(uVar11 * 4 + param_3[2]) = 0x47;
    uVar11 = *param_3 + 1;
    *param_3 = uVar11;
    if (param_3[1] <= uVar11) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar11 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar11 * 4 + param_3[2]) = uVar12 | 0x40000;
    uVar11 = *param_3 + 1;
    *param_3 = uVar11;
    if (param_3[1] <= uVar11) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar11 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar11 * 4 + param_3[2]) = (uVar10 & 0x3f) << 0x10 | uVar6 & 0xffff | 0x400000;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + param_3[2]) = uVar7;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(uVar6 * 4 + param_3[2]) = 0x2000d;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + param_3[2]) = uVar12 | 0x440000;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(uVar6 * 4 + param_3[2]) = 4;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + param_3[2]) = uVar12 | 0x40000;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + param_3[2]) = uVar12 | 0x40000;
    uVar6 = *param_3 + 1;
    *param_3 = uVar6;
    if (param_3[1] <= uVar6) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar6 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + param_3[2]) = uVar12 | 0x440000;
    uVar12 = *param_3 + 1;
    *param_3 = uVar12;
    if (param_3[1] <= uVar12) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar12 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    iVar15 = 1;
    *(undefined **)(uVar12 * 4 + param_3[2]) = ((unsigned char *)0x00004444);
    local_88[0] = CONCAT22((*(unsigned short *)((unsigned char *)&(local_88[0]) + 0)),(short)uVar8);
    *param_3 = *param_3 + 1;
    local_88[0] = local_88[0] & 0xff80ffff | 0x40000;
  }
  switch(param_4) {
  case 0:
  case 0x21:
    uVar14 = 1;
    break;
  case 1:
  case 0x22:
    uVar14 = 3;
    break;
  case 2:
  case 0x23:
    uVar14 = 0x5000d;
    break;
  case 3:
  case 0x24:
    uVar14 = 0x12;
    goto LAB_000ae47c;
  case 4:
  case 0x25:
    uVar14 = 0x22;
    break;
  case 5:
  case 0x26:
    uVar14 = 0x23;
    break;
  case 6:
  case 0x27:
    uVar14 = 0x23;
    local_7c[0] = local_7c[0] & 0xffff0fff | 0x5000;
    break;
  case 7:
  case 0x28:
    uVar14 = 0x24;
    break;
  case 8:
  case 0x29:
    uVar14 = 0x2d;
    break;
  case 9:
  case 0x2a:
    uVar14 = 0x30;
    break;
  case 10:
  case 0x2b:
    uVar14 = 0x31;
    break;
  case 0xc:
  case 0x2c:
    uVar14 = 0x3c;
    break;
  case 0xd:
  case 0x2d:
    uVar14 = 0x39;
    break;
  case 0xe:
  case 0x2e:
    uVar14 = 0x3f;
    break;
  case 0xf:
  case 0x2f:
    uVar14 = 0x40;
    break;
  case 0x10:
  case 0x30:
    uVar14 = 0x41;
    break;
  case 0x11:
  case 0x31:
    uVar14 = 0x44;
    break;
  case 0x12:
  case 0x1c:
  case 0x32:
  case 0x3c:
    uVar14 = 0x47;
    break;
  case 0x13:
  case 0x33:
    uVar14 = 0x49;
    break;
  case 0x14:
  case 0x34:
    uVar14 = 0x4e;
    break;
  case 0x15:
  case 0x35:
    uVar14 = 0x51;
    break;
  case 0x16:
  case 0x36:
    uVar14 = 0x55;
    local_7c[0] = local_7c[0] & 0xffff7777 | 0x100000;
    break;
  case 0x17:
  case 0x37:
    uVar14 = 0x59;
    break;
  case 0x18:
  case 0x38:
    uVar14 = 0x20056;
    break;
  case 0x19:
  case 0x39:
    uVar14 = 0x58;
LAB_000ae47c:
    uVar12 = *param_3;
    if (param_3[1] <= uVar12) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar12 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(uVar12 * 4 + param_3[2]) = 0x4d;
    uVar12 = *param_3 + 1;
    *param_3 = uVar12;
    iVar16 = *(int *)(((unsigned char *)0x000011e0) + param_1);
    if (param_3[1] <= uVar12) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar12 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    uVar6 = local_88[0];
    *(uint *)(uVar12 * 4 + param_3[2]) = iVar16 + 1U & 0xffff | 0x40000;
    uVar12 = *param_3 + 1;
    *param_3 = uVar12;
    if (param_3[1] <= uVar12) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar12 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    uVar8 = local_7c[0];
    *(uint *)(uVar12 * 4 + param_3[2]) = uVar6;
    uVar12 = *param_3 + 1;
    *param_3 = uVar12;
    if ((local_88[0] & 0x400000) != 0) {
      if (param_3[1] <= uVar12) {
        pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
        if ((void *)param_3[2] != (void *)0x0) {
          _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
          (**(code **)(param_1 + 0x18))(param_3[2]);
        }
        param_3[2] = (uint)pvVar9;
        uVar12 = *param_3;
        param_3[1] = param_3[1] + 0x80;
      }
      *(uint *)(uVar12 * 4 + param_3[2]) = uVar8;
      *param_3 = *param_3 + 1;
    }
    local_88[0] = CONCAT22((short)(local_88[0] >> 0x10),
                        (short)*(undefined4 *)(((unsigned char *)0x000011e0) + param_1) + 1) & 0xffc0ffff | 0x40000;
    break;
  case 0x1a:
  case 0x3a:
    uVar14 = 0x50056;
    break;
  case 0x1b:
  case 0x3b:
    uVar14 = 0x5b;
    break;
  case 0x20:
  case 0x40:
    uVar14 = 0x13;
  }
  if (param_5[1] == 0x18) {
    if (iVar15 != 0) {
      iVar21 = 0;
      iVar16 = iVar15;
      do {
        if (((local_88)[iVar21] & 0x400000) != 0) {
          uVar20 = local_7c[iVar21];
          local_7c[iVar21] = uVar20 >> 8 & 7 | uVar20 >> 8 & 8 | uVar20 & 0xfffffff0;
        }
        iVar21 = iVar21 + 1;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
    }
    uVar20 = uVar13 | uVar4 | uVar3 | uVar2 | uVar19;
    bVar1 = false;
  }
  else if (param_5[1] == 0x17) {
    bVar1 = true;
    uVar17 = *(uint *)(local_58 + 0x88) & 0xffff | 0x440000;
  }
  else {
    bVar1 = false;
  }
  uVar19 = *param_3;
  if (param_3[1] <= uVar19) {
    pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
    if ((void *)param_3[2] != (void *)0x0) {
      _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
      (**(code **)(param_1 + 0x18))(param_3[2]);
    }
    param_3[2] = (uint)pvVar9;
    uVar19 = *param_3;
    param_3[1] = param_3[1] + 0x80;
  }
  *(undefined4 *)(uVar19 * 4 + param_3[2]) = uVar14;
  uVar19 = *param_3 + 1;
  *param_3 = uVar19;
  if (param_3[1] <= uVar19) {
    pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
    if ((void *)param_3[2] != (void *)0x0) {
      _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
      (**(code **)(param_1 + 0x18))(param_3[2]);
    }
    param_3[2] = (uint)pvVar9;
    uVar19 = *param_3;
    param_3[1] = param_3[1] + 0x80;
  }
  *(uint *)(uVar19 * 4 + param_3[2]) = uVar17;
  uVar19 = *param_3 + 1;
  *param_3 = uVar19;
  if ((uVar17 & 0x400000) != 0) {
    if (param_3[1] <= uVar19) {
      pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar9;
      uVar19 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar19 * 4 + param_3[2]) = uVar20;
    uVar19 = *param_3 + 1;
    *param_3 = uVar19;
  }
  if (iVar15 != 0) {
    iVar16 = 0;
    iVar21 = 0;
    puVar18 = &local_88;
    do {
      uVar14 = *(undefined4 *)(iVar21 + (int)&local_88);
      if (param_3[1] <= uVar19) {
        pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
        if ((void *)param_3[2] != (void *)0x0) {
          _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
          (**(code **)(param_1 + 0x18))(param_3[2]);
        }
        param_3[2] = (uint)pvVar9;
        uVar19 = *param_3;
        param_3[1] = param_3[1] + 0x80;
      }
      *(undefined4 *)(uVar19 * 4 + param_3[2]) = uVar14;
      uVar19 = *param_3 + 1;
      *param_3 = uVar19;
      if ((*puVar18 & 0x400000) != 0) {
        uVar14 = *(undefined4 *)((int)local_7c + iVar21);
        if (param_3[1] <= uVar19) {
          pvVar9 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
          if ((void *)param_3[2] != (void *)0x0) {
            _memcpy(pvVar9,(void *)param_3[2],*param_3 << 2);
            (**(code **)(param_1 + 0x18))(param_3[2]);
          }
          param_3[2] = (uint)pvVar9;
          uVar19 = *param_3;
          param_3[1] = param_3[1] + 0x80;
        }
        *(undefined4 *)(uVar19 * 4 + param_3[2]) = uVar14;
        uVar19 = *param_3 + 1;
        *param_3 = uVar19;
      }
      iVar16 = iVar16 + 1;
      puVar18 = puVar18 + 1;
      iVar21 = iVar21 + 4;
    } while (iVar15 != iVar16);
  }
  if (bVar1) {
    ((int (*)())FUN_000ac540)(param_1,param_3,*(undefined4 *)(local_58 + 0x88),local_54);
    return;
  }
  return;
}

/* FUN_000aec40 @ 0xaec40 (3872 bytes) */
int FUN_000aec40(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint *param_3;
  int param_4;
  uint *param_5;
  uint param_6;
  uint *param_7;
  undefined4 param_8;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  void *pvVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  undefined4 uStack00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  char in_stack_00000047;
  uint in_stack_00000048;
  int in_stack_0000004c;
  uint local_88[0];
  undefined4 local_84;
  uint local_80;
  uint local_7c [14];
  
  uVar13 = 0;
  uVar10 = param_5[1];
  local_88[0] = 0;
  local_84 = 0;
  local_7c[0] = 0;
  local_80 = 0;
  local_7c[1] = 0;
  if (uVar10 != 0x17) {
    uVar12 = (uVar10 & 0x3f) << 0x10 | *param_5 & 0xffff;
  }
  else {
    uVar12 = *(uint *)(param_2 + 0x88) & 0xffff | 0x40000;
  }
  if (param_4 - 0x3dU < 3) {
    uVar13 = 0x100;
  }
  if (uVar10 == 0x18) {
    uVar13 = 0x100;
  }
  uStack00000034 = param_8;
  if ((param_4 == 0x1f) && (in_stack_00000047 != '\0')) {
    uVar2 = *param_7;
    uVar7 = param_7[1];
    local_7c[5] = in_stack_00000040;
    local_7c[4] = in_stack_0000003c;
    local_7c[3] = in_stack_00000038;
    local_7c[2] = param_8;
    uVar5 = *(int *)(param_2 + 0x88) + 1;
    if (uVar7 == 0x10) {
      iVar11 = 0;
      iVar8 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + iVar11 + 8)) {
        default:
          uVar3 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar3 = 4;
          break;
        case 3:
        case 5:
          uVar3 = 5;
          break;
        case 6:
          uVar3 = 6;
          break;
        case 9:
        case 10:
          uVar3 = 10;
        }
        iVar8 = iVar8 + -1;
        *(undefined4 *)((int)local_7c + iVar11 + 8) = uVar3;
        iVar11 = iVar11 + 4;
      } while (iVar8 != 0);
    }
    switch(local_7c[2]) {
    default:
      bVar1 = false;
      uVar4 = 0;
      break;
    case 1:
      bVar1 = false;
      uVar4 = 1;
      break;
    case 2:
      bVar1 = false;
      uVar4 = 2;
      break;
    case 3:
      bVar1 = false;
      uVar4 = 3;
      break;
    case 4:
      bVar1 = false;
      uVar4 = 4;
      break;
    case 5:
      bVar1 = false;
      uVar4 = 5;
      break;
    case 6:
      bVar1 = true;
      uVar4 = 0;
      break;
    case 7:
      bVar1 = true;
      uVar4 = 1;
      break;
    case 8:
      bVar1 = true;
      uVar4 = 2;
      break;
    case 9:
      bVar1 = true;
      uVar4 = 3;
      break;
    case 10:
      bVar1 = true;
      uVar4 = 5;
    }
    if (bVar1) {
      uVar4 = uVar4 | 8;
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      iVar8 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar8 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar8 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar8 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar8 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar8 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar8 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar8 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar8 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar8 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar8 = 5;
    }
    uVar4 = iVar8 << 4 | uVar4;
    if (bVar1) {
      uVar4 = uVar4 | 0x80;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar8 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar8 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar8 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar8 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar8 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar8 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar8 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar8 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar8 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar8 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar8 = 5;
    }
    uVar4 = iVar8 << 8 | uVar4;
    if (bVar1) {
      uVar4 = uVar4 | 0x800;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar8 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar8 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar8 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar8 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar8 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar8 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar8 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar8 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar8 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar8 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar8 = 5;
    }
    uVar4 = iVar8 << 0xc | uVar4;
    if (bVar1) {
      uVar4 = uVar4 | 0x8000;
    }
    uVar9 = *param_3;
    if (param_3[1] <= uVar9) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar9 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(undefined4 *)(uVar9 * 4 + param_3[2]) = 0x47;
    uVar9 = *param_3 + 1;
    *param_3 = uVar9;
    if (param_3[1] <= uVar9) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar9 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar9 * 4 + param_3[2]) = uVar5 & 0xffff | 0x40000;
    uVar9 = *param_3 + 1;
    *param_3 = uVar9;
    if (param_3[1] <= uVar9) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar9 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar9 * 4 + param_3[2]) = (uVar7 & 0x3f) << 0x10 | uVar2 & 0xffff | 0x400000;
    uVar2 = *param_3 + 1;
    *param_3 = uVar2;
    if (param_3[1] <= uVar2) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar2 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar2 * 4 + param_3[2]) =
         (uVar4 & 0xfffff777 ^ 0x8000) & 0x8000 |
         (uVar4 & 0xffffff77 ^ 0x800) & 0x800 |
         (uVar4 & 0xfffffff7 ^ 0x80) & 0x80 | (uVar4 ^ 8) & 8 | uVar4 & 0xffff7777;
    local_84 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_84) + 0)),(short)uVar5);
    local_7c[0] = local_7c[0] & 0xffff8888 | 0x3210;
    uVar2 = *param_3 + 1;
    *param_3 = uVar2;
    local_84 = local_84 & 0xffc0ffff | 0x40000;
LAB_000af474:
    iVar8 = 1;
    local_88[0] = 0x5d;
    local_84 = local_84 | 0x400000;
    local_7c[0] = local_7c[0] & 0xff1fffff | 0x600000;
    goto LAB_000afabc;
  }
  local_7c[5] = in_stack_00000040;
  local_7c[4] = in_stack_0000003c;
  local_7c[3] = in_stack_00000038;
  local_7c[2] = param_8;
  local_84 = *param_7 & 0xffff;
  local_84 = (param_7[1] & 0x3f) << 0x10 | local_84 | 0x400000;
  if (param_7[1] == 0x10) {
    iVar11 = 0;
    iVar8 = 4;
    do {
      switch(*(undefined4 *)((int)local_7c + iVar11 + 8)) {
      default:
        uVar3 = 0;
        break;
      case 1:
      case 2:
      case 4:
      case 7:
      case 8:
        uVar3 = 4;
        break;
      case 3:
      case 5:
        uVar3 = 5;
        break;
      case 6:
        uVar3 = 6;
        break;
      case 9:
      case 10:
        uVar3 = 10;
      }
      iVar8 = iVar8 + -1;
      *(undefined4 *)((int)local_7c + iVar11 + 8) = uVar3;
      iVar11 = iVar11 + 4;
    } while (iVar8 != 0);
  }
  switch(local_7c[2]) {
  default:
    bVar1 = false;
    local_7c[0] = 0;
    break;
  case 1:
    bVar1 = false;
    local_7c[0] = 1;
    break;
  case 2:
    bVar1 = false;
    local_7c[0] = 2;
    break;
  case 3:
    bVar1 = false;
    local_7c[0] = 3;
    break;
  case 4:
    bVar1 = false;
    local_7c[0] = 4;
    break;
  case 5:
    bVar1 = false;
    local_7c[0] = 5;
    break;
  case 6:
    bVar1 = true;
    local_7c[0] = 0;
    break;
  case 7:
    bVar1 = true;
    local_7c[0] = 1;
    break;
  case 8:
    bVar1 = true;
    local_7c[0] = 2;
    break;
  case 9:
    bVar1 = true;
    local_7c[0] = 3;
    break;
  case 10:
    bVar1 = true;
    local_7c[0] = 5;
  }
  if (bVar1) {
    local_7c[0] = local_7c[0] | 8;
  }
  switch(local_7c[3]) {
  default:
    bVar1 = false;
    iVar8 = 0;
    break;
  case 1:
    bVar1 = false;
    iVar8 = 1;
    break;
  case 2:
    bVar1 = false;
    iVar8 = 2;
    break;
  case 3:
    bVar1 = false;
    iVar8 = 3;
    break;
  case 4:
    bVar1 = false;
    iVar8 = 4;
    break;
  case 5:
    bVar1 = false;
    iVar8 = 5;
    break;
  case 6:
    bVar1 = true;
    iVar8 = 0;
    break;
  case 7:
    bVar1 = true;
    iVar8 = 1;
    break;
  case 8:
    bVar1 = true;
    iVar8 = 2;
    break;
  case 9:
    bVar1 = true;
    iVar8 = 3;
    break;
  case 10:
    bVar1 = true;
    iVar8 = 5;
  }
  local_7c[0] = iVar8 << 4 | local_7c[0];
  if (bVar1) {
    local_7c[0] = local_7c[0] | 0x80;
  }
  switch(local_7c[4]) {
  default:
    bVar1 = false;
    iVar8 = 0;
    break;
  case 1:
    bVar1 = false;
    iVar8 = 1;
    break;
  case 2:
    bVar1 = false;
    iVar8 = 2;
    break;
  case 3:
    bVar1 = false;
    iVar8 = 3;
    break;
  case 4:
    bVar1 = false;
    iVar8 = 4;
    break;
  case 5:
    bVar1 = false;
    iVar8 = 5;
    break;
  case 6:
    bVar1 = true;
    iVar8 = 0;
    break;
  case 7:
    bVar1 = true;
    iVar8 = 1;
    break;
  case 8:
    bVar1 = true;
    iVar8 = 2;
    break;
  case 9:
    bVar1 = true;
    iVar8 = 3;
    break;
  case 10:
    bVar1 = true;
    iVar8 = 5;
  }
  local_7c[0] = iVar8 << 8 | local_7c[0];
  if (bVar1) {
    local_7c[0] = local_7c[0] | 0x800;
  }
  switch(local_7c[5]) {
  default:
    bVar1 = false;
    iVar8 = 0;
    break;
  case 1:
    bVar1 = false;
    iVar8 = 1;
    break;
  case 2:
    bVar1 = false;
    iVar8 = 2;
    break;
  case 3:
    bVar1 = false;
    iVar8 = 3;
    break;
  case 4:
    bVar1 = false;
    iVar8 = 4;
    break;
  case 5:
    bVar1 = false;
    iVar8 = 5;
    break;
  case 6:
    bVar1 = true;
    iVar8 = 0;
    break;
  case 7:
    bVar1 = true;
    iVar8 = 1;
    break;
  case 8:
    bVar1 = true;
    iVar8 = 2;
    break;
  case 9:
    bVar1 = true;
    iVar8 = 3;
    break;
  case 10:
    bVar1 = true;
    iVar8 = 5;
  }
  local_7c[0] = iVar8 << 0xc | local_7c[0];
  if (bVar1) {
    local_7c[0] = local_7c[0] | 0x8000;
  }
  if (in_stack_00000047 != '\0') {
    local_7c[0] = (local_7c[0] & 0xfffff777 ^ 0x8000) & 0x8000 |
                  (local_7c[0] & 0xffffff77 ^ 0x800) & 0x800 |
                  (local_7c[0] & 0xfffffff7 ^ 0x80) & 0x80 |
                  (local_7c[0] ^ 8) & 8 | local_7c[0] & 0xffff7777;
  }
  switch(param_4) {
  case 0xb:
    uVar2 = *param_3;
    iVar8 = 1;
    local_88[0] = 0x37;
    goto LAB_000afb10;
  default:
    uVar2 = *param_3;
    iVar8 = 0;
    goto LAB_000afb10;
  case 0x1d:
  case 0x3d:
    uVar2 = *param_3;
    iVar8 = 1;
    local_88[0] = 0x5d;
    break;
  case 0x1e:
  case 0x3e:
    iVar8 = 2;
    local_88[0] = 0x5e;
    uVar2 = *param_3;
    local_80 = local_84;
    local_7c[1] = local_7c[0];
    break;
  case 0x1f:
  case 0x3f:
    uVar2 = *param_3;
    goto LAB_000af474;
  }
LAB_000afabc:
  local_88[0] = (uint)(in_stack_0000004c - 6U < 3) << 0x1a |
             (in_stack_00000048 & 0x33ff) << 0x10 | local_88[0];
LAB_000afb10:
  if (param_3[1] <= uVar2) {
    pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
    if ((void *)param_3[2] != (void *)0x0) {
      _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
      (**(code **)(param_1 + 0x18))(param_3[2]);
    }
    param_3[2] = (uint)pvVar6;
    uVar2 = *param_3;
    param_3[1] = param_3[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_3[2]) = local_88[0];
  uVar2 = *param_3 + 1;
  *param_3 = uVar2;
  if (param_4 != 0xb) {
    if (param_3[1] <= uVar2) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar2 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar2 * 4 + param_3[2]) = uVar12 | 0x400000;
    uVar12 = *param_3 + 1;
    *param_3 = uVar12;
    if (param_3[1] <= uVar12) {
      pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
      if ((void *)param_3[2] != (void *)0x0) {
        _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
        (**(code **)(param_1 + 0x18))(param_3[2]);
      }
      param_3[2] = (uint)pvVar6;
      uVar12 = *param_3;
      param_3[1] = param_3[1] + 0x80;
    }
    *(uint *)(uVar12 * 4 + param_3[2]) =
         (param_6 >> 3 & 1) << 6 |
         (param_6 >> 2 & 1) << 4 | (param_6 >> 1 & 1) << 2 | param_6 & 1 | uVar13;
    uVar2 = *param_3 + 1;
    *param_3 = uVar2;
  }
  if (iVar8 != 0) {
    puVar15 = &local_84;
    iVar11 = 0;
    iVar14 = 0;
    do {
      uVar3 = *(undefined4 *)((int)&local_84 + iVar14);
      if (param_3[1] <= uVar2) {
        pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
        if ((void *)param_3[2] != (void *)0x0) {
          _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
          (**(code **)(param_1 + 0x18))(param_3[2]);
        }
        param_3[2] = (uint)pvVar6;
        uVar2 = *param_3;
        param_3[1] = param_3[1] + 0x80;
      }
      *(undefined4 *)(uVar2 * 4 + param_3[2]) = uVar3;
      uVar2 = *param_3 + 1;
      *param_3 = uVar2;
      if ((*puVar15 & 0x400000) != 0) {
        uVar3 = *(undefined4 *)((int)local_7c + iVar14);
        if (param_3[1] <= uVar2) {
          pvVar6 = (void *)(**(code **)(param_1 + 0xc))(param_3[1] * 4 + 0x200);
          if ((void *)param_3[2] != (void *)0x0) {
            _memcpy(pvVar6,(void *)param_3[2],*param_3 << 2);
            (**(code **)(param_1 + 0x18))(param_3[2]);
          }
          param_3[2] = (uint)pvVar6;
          uVar2 = *param_3;
          param_3[1] = param_3[1] + 0x80;
        }
        *(undefined4 *)(uVar2 * 4 + param_3[2]) = uVar3;
        uVar2 = *param_3 + 1;
        *param_3 = uVar2;
      }
      iVar11 = iVar11 + 1;
      puVar15 = puVar15 + 1;
      iVar14 = iVar14 + 4;
    } while (iVar8 != iVar11);
  }
  if (uVar10 == 0x17) {
    ((int (*)())FUN_000ac540)(param_1,param_3,*(undefined4 *)(param_2 + 0x88),*param_5);
  }
  return;
}

/* FUN_000afe40 @ 0xafe40 (5932 bytes) */
int FUN_000afe40(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  size_t sVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char *pcVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  undefined4 uVar14;
  int iVar15;
  code *pcVar16;
  uint uVar17;
  undefined4 uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  undefined4 uVar22;
  char *pcVar23;
  int iVar24;
  char local_208 [4];
  undefined1 auStack_204 [8];
  undefined1 auStack_1fc [8];
  undefined1 auStack_1f4 [8];
  uint local_1ec;
  uint local_1e8;
  void *local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  char acStack_170 [264];
  int local_68;
  undefined1 *local_64;
  char *local_60;
  uint *local_5c;
  
  iVar11 = *(int *)(((unsigned char *)0x0000121c) + param_1);
  pcVar23 = *(char **)(iVar11 + 0x74);
  if (pcVar23[0x54] == '\0') {
    iVar11 = *(int *)(*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 +
                      *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 8) + 0x14);
    pcVar23 = *(char **)(iVar11 + 0x74);
  }
  uVar12 = *(uint *)(iVar11 + 0x70);
  iVar15 = *(int *)(((unsigned char *)0x00001130) + param_1) * 4;
  pcVar10 = *(char **)(iVar15 + uVar12);
  if (pcVar10 == (char *)0x0) {
    pcVar16 = *(code **)(param_1 + 0x10);
    uVar4 = (**(code **)(((unsigned char *)0x00001284) + param_1))();
    uVar4 = (*pcVar16)(1,uVar4);
    *(undefined4 *)(iVar15 + uVar12) = uVar4;
  }
  else {
    if ((param_2 != 1) && (pcVar10[0x119] == '\0')) goto LAB_000b0028;
    *(undefined4 *)(iVar15 + uVar12) = 0;
    (**(code **)(((unsigned char *)0x00001224) + param_1))(param_1,pcVar10);
    pcVar16 = *(code **)(param_1 + 0x10);
    iVar15 = *(int *)(((unsigned char *)0x00001130) + param_1);
    uVar12 = *(uint *)(iVar11 + 0x70);
    uVar4 = (**(code **)(((unsigned char *)0x00001284) + param_1))(param_1);
    uVar4 = (*pcVar16)(1,uVar4);
    *(undefined4 *)(iVar15 * 4 + uVar12) = uVar4;
  }
  pcVar10 = *(char **)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 + *(int *)(iVar11 + 0x70));
  *pcVar10 = '\0';
  if (pcVar23[0x55] == '\0') {
    local_1e4 = (void *)0x0;
    local_1ec = 0;
    local_1e8 = 0;
    pvVar5 = (void *)(**(code **)(param_1 + 0xc))(0x200);
    if (local_1e4 != (void *)0x0) {
      _memcpy(pvVar5,local_1e4,local_1ec << 2);
      (**(code **)(param_1 + 0x18))(local_1e4);
    }
    local_1e8 = local_1e8 + 0x80;
    *(undefined4 *)((int)pvVar5 + local_1ec * 4) = 1;
    local_1ec = local_1ec + 1;
    local_1e4 = pvVar5;
    if (local_1e8 <= local_1ec) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
      if (local_1e4 != (void *)0x0) {
        _memcpy(pvVar5,local_1e4,local_1ec << 2);
        (**(code **)(param_1 + 0x18))(local_1e4);
      }
      local_1e8 = local_1e8 + 0x80;
      local_1e4 = pvVar5;
    }
    *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x10200;
    local_1ec = local_1ec + 1;
    if (local_1e8 <= local_1ec) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
      if (local_1e4 != (void *)0x0) {
        _memcpy(pvVar5,local_1e4,local_1ec << 2);
        (**(code **)(param_1 + 0x18))(local_1e4);
      }
      local_1e8 = local_1e8 + 0x80;
      local_1e4 = pvVar5;
    }
    *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x1ff0016;
    local_1ec = local_1ec + 1;
    if (local_1e8 <= local_1ec) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
      if (local_1e4 != (void *)0x0) {
        _memcpy(pvVar5,local_1e4,local_1ec << 2);
        (**(code **)(param_1 + 0x18))(local_1e4);
      }
      local_1e8 = local_1e8 + 0x80;
      local_1e4 = pvVar5;
    }
    *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x120000;
    local_1ec = local_1ec + 1;
    if (*pcVar23 != '\0') {
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x1ff0016;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x130000;
      local_1ec = local_1ec + 1;
    }
    if (pcVar23[1] != '\0') {
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x1ff0016;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x100000;
      local_1ec = local_1ec + 1;
    }
    if (pcVar23[2] != '\0') {
      uVar12 = 0x3ff0016;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x3ff0016;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x160000;
      local_1ec = local_1ec + 1;
    }
    uVar7 = local_1ec;
    if (((unsigned char *)0x000013b1)[param_1] != '\0') {
      uVar20 = 0;
      pcVar13 = pcVar23;
      do {
        uVar17 = 1 << (uVar20 & 0x3f);
        if ((uVar17 & *(uint *)(pcVar23 + 0x10)) != 0) {
          switch(*(undefined4 *)(pcVar13 + 0x14)) {
          case 0:
            uVar12 = uVar20 << 0x10 | 0x8000019;
            break;
          case 1:
          case 6:
            uVar12 = uVar20 << 0x10 | 0x9000019;
            break;
          case 2:
          case 7:
            uVar12 = uVar20 << 0x10 | 0xa000019;
            break;
          case 3:
            uVar12 = uVar20 << 0x10 | 0xb000019;
            break;
          case 4:
            uVar12 = uVar20 << 0x10 | 0xc000019;
            break;
          case 5:
          case 8:
            uVar12 = uVar20 << 0x10 | 0x12000019;
          }
          if (local_1e8 <= uVar7) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            uVar7 = local_1ec;
            local_1e4 = pvVar5;
          }
          *(uint *)(uVar7 * 4 + (int)local_1e4) = uVar12;
          uVar7 = local_1ec + 1;
          local_1ec = uVar7;
        }
        if (((int)uVar20 < (int)(uint)(byte)((unsigned char *)0x000013b0)[param_1]) &&
           ((uVar17 & *(uint *)(pcVar23 + 0xc)) != 0)) {
          if (local_1e8 <= uVar7) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            uVar7 = local_1ec;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(uVar7 * 4 + (int)local_1e4) = 0x1ff0016;
          local_1ec = local_1ec + 1;
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(uint *)(local_1ec * 4 + (int)local_1e4) = uVar20 & 0xffff | 0x110000;
          uVar7 = local_1ec + 1;
          local_1ec = uVar7;
        }
        uVar20 = uVar20 + 1;
        pcVar13 = pcVar13 + 4;
      } while ((int)uVar20 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
    }
    iVar15 = *(int *)(pcVar23 + 0x84);
    uVar12 = 0x10000;
    if (0 < iVar15) {
      iVar19 = 0;
      iVar24 = 0;
      do {
        iVar21 = iVar24 + *(int *)(pcVar23 + 0x80);
        if (*(int *)(iVar21 + 8) == 0x34) {
          uVar12 = *(uint *)(iVar21 + 4) & 0xffff | uVar12 & 0xffff0000;
          if (local_1e8 <= uVar7) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            uVar7 = local_1ec;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(uVar7 * 4 + (int)local_1e4) = 0x1c;
          local_1ec = local_1ec + 1;
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(uint *)(local_1ec * 4 + (int)local_1e4) = uVar12;
          local_1ec = local_1ec + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar21 + 0xc) * 0x10 + *(int *)(pcVar23 + 0x8c));
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = uVar4;
          local_1ec = local_1ec + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar21 + 0xc) * 0x10 + *(int *)(pcVar23 + 0x8c) + 4);
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = uVar4;
          local_1ec = local_1ec + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar21 + 0xc) * 0x10 + *(int *)(pcVar23 + 0x8c) + 8);
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = uVar4;
          local_1ec = local_1ec + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar21 + 0xc) * 0x10 + *(int *)(pcVar23 + 0x8c) + 0xc);
          if (local_1e8 <= local_1ec) {
            pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
            if (local_1e4 != (void *)0x0) {
              _memcpy(pvVar5,local_1e4,local_1ec << 2);
              (**(code **)(param_1 + 0x18))(local_1e4);
            }
            local_1e8 = local_1e8 + 0x80;
            local_1e4 = pvVar5;
          }
          *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = uVar4;
          uVar7 = local_1ec + 1;
          iVar15 = *(int *)(pcVar23 + 0x84);
          local_1ec = uVar7;
        }
        iVar19 = iVar19 + 1;
        iVar24 = iVar24 + 0x14;
      } while (iVar19 < iVar15);
    }
    if (**(int **)(pcVar23 + 100) == 0x41) {
      local_5c = &local_1ec;
LAB_000b10a0:
      if (local_1e8 <= uVar7) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        uVar7 = local_1ec;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(uVar7 * 4 + (int)local_1e4) = 0x47;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x570000;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0;
      local_1ec = local_1ec + 1;
      if (local_1e8 <= local_1ec) {
        pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
        if (local_1e4 != (void *)0x0) {
          _memcpy(pvVar5,local_1e4,local_1ec << 2);
          (**(code **)(param_1 + 0x18))(local_1e4);
        }
        local_1e8 = local_1e8 + 0x80;
        local_1e4 = pvVar5;
      }
      *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x40000;
      local_1ec = local_1ec + 1;
    }
    else {
      local_5c = &local_1ec;
      iVar15 = 0;
      local_68 = 0;
      local_64 = auStack_1f4;
      local_60 = acStack_170;
      iVar24 = 0;
      do {
        local_208[0] = '\0';
        iVar19 = iVar24 + *(int *)(pcVar23 + 100);
        uVar12 = *(uint *)(iVar24 + *(int *)(pcVar23 + 100));
        local_1e0 = *(undefined4 *)(iVar19 + 4);
        local_1dc = *(undefined4 *)(iVar19 + 8);
        uVar22 = *(undefined4 *)(iVar19 + 0xc);
        local_190 = *(undefined4 *)(iVar19 + 0x10);
        local_18c = *(undefined4 *)(iVar19 + 0x14);
        local_188 = *(undefined4 *)(iVar19 + 0x18);
        local_184 = *(undefined4 *)(iVar19 + 0x1c);
        local_180 = *(undefined4 *)(iVar19 + 0x20);
        local_17c = *(undefined4 *)(iVar19 + 0x24);
        uVar8 = *(undefined4 *)(iVar19 + 0x28);
        local_174 = *(undefined4 *)(iVar19 + 0x2c);
        local_1b0 = *(undefined4 *)(iVar19 + 0x30);
        local_1ac = *(undefined4 *)(iVar19 + 0x34);
        local_1a8 = *(undefined4 *)(iVar19 + 0x38);
        local_1a4 = *(undefined4 *)(iVar19 + 0x3c);
        (*(unsigned char *)((unsigned char *)&(local_178) + 0)) = (undefined1)((uint)uVar8 >> 0x18);
        uVar3 = (*(unsigned char *)((unsigned char *)&(local_178) + 0));
        local_1a0 = *(undefined4 *)(iVar19 + 0x40);
        local_19c = *(undefined4 *)(iVar19 + 0x44);
        uVar9 = *(undefined4 *)(iVar19 + 0x48);
        uVar18 = *(undefined4 *)(iVar19 + 0x4c);
        local_1d0 = *(undefined4 *)(iVar19 + 0x50);
        local_1cc = *(undefined4 *)(iVar19 + 0x54);
        local_1c8 = *(undefined4 *)(iVar19 + 0x58);
        local_1c4 = *(undefined4 *)(iVar19 + 0x5c);
        (*(unsigned char *)((unsigned char *)&(local_198) + 0)) = (undefined1)((uint)uVar9 >> 0x18);
        uVar2 = (*(unsigned char *)((unsigned char *)&(local_198) + 0));
        uVar4 = *(undefined4 *)(iVar19 + 0x68);
        uVar14 = *(undefined4 *)(iVar19 + 0x6c);
        local_1c0 = *(undefined4 *)(iVar19 + 0x60);
        local_1bc = *(undefined4 *)(iVar19 + 100);
        (*(unsigned char *)((unsigned char *)&(local_1b8) + 0)) = (undefined1)((uint)uVar4 >> 0x18);
        uVar1 = (*(unsigned char *)((unsigned char *)&(local_1b8) + 0));
        local_1d8 = uVar22;
        local_1b8 = uVar4;
        local_1b4 = uVar14;
        local_198 = uVar9;
        local_194 = uVar18;
        local_178 = uVar8;
        if (uVar12 < 0x20) {
          if ((0x1c < uVar12) || (uVar12 == 0xb)) goto LAB_000b0fbc;
LAB_000b0e20:
          ((int (*)())FUN_000ab940)(local_1e0,local_1dc,uVar22,auStack_204,local_208,
                       *(undefined1 *)(*(int *)(pcVar23 + 0x94) + iVar15));
          local_178 = CONCAT13(uVar3,(*(unsigned int *)((unsigned char *)&(local_178) + 1)));
          ((int (*)())FUN_000ab9b0)(local_190,local_18c,local_188,local_184,local_180,local_17c,local_178,
                       local_174);
          local_198 = CONCAT13(uVar2,(*(unsigned int *)((unsigned char *)&(local_198) + 1)));
          local_194 = uVar18;
          ((int (*)())FUN_000ab9b0)(local_1b0,local_1ac,local_1a8,local_1a4,local_1a0,local_19c,local_198,uVar18)
          ;
          local_1b8 = CONCAT13(uVar1,(*(unsigned int *)((unsigned char *)&(local_1b8) + 1)));
          local_1b4 = uVar14;
          ((int (*)())FUN_000ab9b0)(local_1d0,local_1cc,local_1c8,local_1c4,local_1c0,local_1bc,local_1b8,uVar14)
          ;
          ((int (*)())FUN_000ac720)(param_1,pcVar23,local_5c,uVar12,auStack_204,uVar22,local_64,auStack_1fc);
        }
        else {
          if (2 < uVar12 - 0x3d) goto LAB_000b0e20;
LAB_000b0fbc:
          ((int (*)())FUN_000ab940)(local_1e0,local_1dc,uVar22,auStack_1fc,local_208,0);
          local_178 = CONCAT13(uVar3,(*(unsigned int *)((unsigned char *)&(local_178) + 1)));
          ((int (*)())FUN_000ab9b0)(local_190,local_18c,local_188,local_184,local_180,local_17c,local_178,
                       local_174);
          ((int (*)())FUN_000aec40)(param_1,pcVar23,local_5c,uVar12,auStack_1fc,uVar22,auStack_204,local_188);
        }
        if (local_208[0] != '\0') {
          local_68 = 1;
        }
        iVar24 = iVar24 + 0x70;
        iVar15 = iVar15 + 1;
      } while (*(int *)(*(int *)(pcVar23 + 100) + iVar24) != 0x41);
      uVar7 = local_1ec;
      if (local_68 == 0) goto LAB_000b10a0;
    }
    if (local_1e8 <= local_1ec) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(local_1e8 * 4 + 0x200);
      if (local_1e4 != (void *)0x0) {
        _memcpy(pvVar5,local_1e4,local_1ec << 2);
        (**(code **)(param_1 + 0x18))(local_1e4);
      }
      local_1e8 = local_1e8 + 0x80;
      local_1e4 = pvVar5;
    }
    *(undefined4 *)(local_1ec * 4 + (int)local_1e4) = 0x28;
    local_1ec = local_1ec + 1;
    iVar15 = (**(code **)(((unsigned char *)0x00001288) + param_1))(param_1,iVar11,pcVar10,local_5c);
    if (iVar15 < 0) {
      iVar24 = *(int *)(((unsigned char *)0x00001130) + param_1);
      iVar19 = *(int *)(iVar11 + 0x70);
      uVar4 = *(undefined4 *)(iVar24 * 4 + iVar19);
      if (iVar15 == -1) {
        FUN_001a32d0(acStack_170,
                     "Fragment program exceeded native resources:\n  Temporaries          - %d\n  Parameters           - %d\n  Attributes           - %d\n  ALU instructions     - %d\n  Texture instructions - %d\n  Texture indirections - %d\n"
                     ,*(undefined4 *)(iVar11 + 0x68),*(undefined4 *)(iVar11 + 100),
                     *(undefined4 *)(iVar11 + 0x60),*(undefined4 *)(iVar11 + 0x54),
                     *(undefined4 *)(iVar11 + 0x58),*(undefined4 *)(iVar11 + 0x5c));
        if (*(int *)(((unsigned char *)0x00001128) + param_1) != 0) {
          (**(code **)(param_1 + 0x18))();
        }
        sVar6 = _strlen(acStack_170);
        pcVar23 = (char *)(**(code **)(param_1 + 0xc))(sVar6 + 1);
        *(char **)(((unsigned char *)0x00001128) + param_1) = pcVar23;
        _strcpy(pcVar23,acStack_170);
        iVar24 = *(int *)(((unsigned char *)0x00001130) + param_1);
        iVar19 = *(int *)(iVar11 + 0x70);
      }
      *(undefined4 *)(iVar24 * 4 + iVar19) = 0;
LAB_000b1448:
      (**(code **)(((unsigned char *)0x00001224) + param_1))(param_1,uVar4);
      return 0;
    }
  }
  else {
    iVar15 = ((int (*)())FUN_000abd10)(param_1,iVar11,acStack_170);
    if (iVar15 == 0) {
      if (*(int *)(((unsigned char *)0x00001128) + param_1) != 0) {
        (**(code **)(param_1 + 0x18))();
      }
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(0x22);
      *(void **)(((unsigned char *)0x00001128) + param_1) = pvVar5;
      _memcpy(pvVar5,"program had bad or unsupported IL",0x22);
      return 0;
    }
    iVar15 = (**(code **)(((unsigned char *)0x00001288) + param_1))(param_1,iVar11,pcVar10,acStack_170);
    if (iVar15 == -1) {
      *(undefined1 *)(iVar11 + 0x6c) = 0;
    }
    else {
      if (iVar15 == -2) {
        uVar4 = *(undefined4 *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 + *(int *)(iVar11 + 0x70));
        *(undefined4 *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 + *(int *)(iVar11 + 0x70)) = 0;
        goto LAB_000b1448;
      }
      *(undefined1 *)(iVar11 + 0x6c) = 1;
    }
  }
  pcVar10[0x119] = '\0';
LAB_000b0028:
  ((unsigned char *)0x000011d0)[param_1] = 0;
  if (pcVar23[0x55] == '\0') {
    iVar24 = *(int *)(iVar11 + 0x74);
    iVar15 = 0;
    if (0 < *(int *)(iVar24 + 0x84)) {
      do {
        iVar19 = iVar15 * 0x14 + *(int *)(iVar24 + 0x80);
        if (*(int *)(iVar19 + 8) == 0x34) {
          if (*pcVar10 == '\0') {
            (**(code **)(((unsigned char *)0x00001280) + param_1))
                      (param_1,pcVar10,iVar15,*(undefined4 *)(iVar19 + 4),
                       *(int *)(iVar19 + 0xc) * 0x10 + *(int *)(iVar24 + 0x8c),1,1);
            iVar24 = *(int *)(iVar11 + 0x74);
          }
        }
        else {
          FUN_0008ebb0(param_1,iVar19,&local_1e0);
          (**(code **)(((unsigned char *)0x00001280) + param_1))
                    (param_1,pcVar10,iVar15,*(undefined4 *)(iVar19 + 4),&local_1e0,1,1);
          iVar24 = *(int *)(iVar11 + 0x74);
        }
        iVar15 = iVar15 + 1;
      } while (iVar15 < *(int *)(iVar24 + 0x84));
    }
  }
  else {
    ((int (*)())FUN_000abab0)(param_1,iVar11,pcVar10);
  }
  if (((*(uint *)(param_1 + 0x44) & 0x2000) != 0) && (*(char *)(iVar11 + 0x6c) != '\0')) {
    (**(code **)(((unsigned char *)0x00001290) + param_1))(param_1,pcVar10);
  }
  return 1;
}

/* FUN_000b15d0 @ 0xb15d0 (180 bytes) */
int FUN_000b15d0(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = param_3;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b1690 @ 0xb1690 (476 bytes) */
int FUN_000b1690(param_1, param_2)
  int param_1;
  uint *param_2;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0xe;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x170000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x40000;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b1870 @ 0xb1870 (800 bytes) */
int FUN_000b1870(param_1, param_2)
  int param_1;
  uint *param_2;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 3;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x40000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x40000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x530000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined **)(uVar2 * 4 + param_2[2]) = ((unsigned char *)0x00004210);
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b1b90 @ 0xb1b90 (748 bytes) */
int FUN_000b1b90(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  int param_3;
  uint param_4;
  uint param_5;
{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x47;
  uVar3 = 0;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if ((param_5 & 7) == 0) {
    uVar3 = 0x15;
  }
  if ((param_5 & 1) != 0) {
    uVar3 = uVar3 & 0xfffffffc | 1;
  }
  if ((param_5 & 2) != 0) {
    uVar3 = uVar3 & 0xfffffff3 | 4;
  }
  if ((param_5 & 4) != 0) {
    uVar3 = uVar3 & 0xffffffcf | 0x10;
  }
  if ((param_5 & 8) != 0) {
    uVar3 = uVar3 | 0x40;
  }
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = param_3 + 0x76dfU & 0xffff | 0x440000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = uVar3;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = param_4 & 0xffff | 0x40000;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b1e80 @ 0xb1e80 (932 bytes) */
int FUN_000b1e80(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  uint *param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  
  uVar5 = 0;
  puVar6 = (undefined *)0x0;
  uVar4 = *param_3;
  if ((uVar4 - 0x8921 < 6) && (*(char *)(uVar4 + param_6 + -0x8921) == '\0')) {
    uVar4 = 0;
    *param_3 = 0;
LAB_000b1f80:
    uVar5 = 0x410000;
    puVar6 = ((unsigned char *)0x00004444);
  }
  else if (uVar4 < 0x8927) {
    if (uVar4 < 0x8921) {
      if (uVar4 == 1) {
        uVar5 = 0x410000;
        puVar6 = ((unsigned char *)0x00005555);
      }
      else {
        if (uVar4 == 0) goto LAB_000b1f80;
        if (uVar4 == 0x8577) {
          uVar5 = 0x120000;
        }
      }
    }
    else {
      uVar5 = uVar4 + 0x76df & 0xffff | 0x40000;
    }
  }
  else if (0x8940 < uVar4) {
    if (uVar4 < 0x8949) {
      uVar5 = uVar4 + 0x76bf & 0xffff | 0x10000;
    }
    else if (uVar4 == 0x896d) {
      uVar5 = 0x130000;
    }
  }
  uVar1 = param_3[3];
  if (uVar1 == 0) {
    uVar3 = param_3[2];
    if (uVar3 == 0) goto LAB_000b2028;
  }
  else {
    uVar3 = param_3[2];
  }
  uVar5 = uVar5 | 0x400000;
LAB_000b2028:
  if ((uVar3 & 1) != 0) {
    puVar6 = (undefined *)((uint)puVar6 | 0x40000);
  }
  if ((uVar3 & 2) != 0) {
    puVar6 = (undefined *)((uint)puVar6 | 0x10000);
  }
  if ((uVar3 & 4) != 0) {
    puVar6 = (undefined *)((uint)puVar6 | 0x8888);
  }
  if ((uVar3 & 8) != 0) {
    puVar6 = (undefined *)((uint)puVar6 | 0x20000);
  }
  if (1 < uVar4) {
    if (uVar1 == 0x1904) {
      puVar6 = (undefined *)((uint)puVar6 & 0xffff8888 | 0x1111);
    }
    else if (uVar1 < 0x1905) {
      if (uVar1 == 0) {
        puVar6 = (undefined *)((uint)puVar6 & 0xffff8888 | 0x3210);
      }
      else if (uVar1 == 0x1903) {
        puVar6 = (undefined *)((uint)puVar6 & 0xffff8888);
      }
    }
    else if (uVar1 == 0x1905) {
      puVar6 = (undefined *)((uint)puVar6 & 0xffff8888 | 0x2222);
    }
    else if (uVar1 == 0x1906) {
      puVar6 = (undefined *)((uint)puVar6 & 0xffff8888 | 0x3333);
    }
  }
  uVar4 = *param_2;
  if (param_2[1] <= uVar4) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar4 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar4 * 4 + param_2[2]) = uVar5;
  uVar4 = *param_2 + 1;
  *param_2 = uVar4;
  if ((uVar5 & 0x400000) != 0) {
    if (param_2[1] <= uVar4) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar2;
      uVar4 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(undefined **)(uVar4 * 4 + param_2[2]) = puVar6;
    *param_2 = *param_2 + 1;
  }
  return 1;
}

/* FUN_000b2260 @ 0xb2260 (692 bytes) */
int FUN_000b2260(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  uint *param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  uVar3 = *param_3;
  if (uVar3 - 0x8921 < 6) {
    *(undefined1 *)(uVar3 + param_6 + -0x8921) = 1;
    uVar3 = uVar3 + 0x76df;
  }
  uVar5 = uVar3 & 0xffff | 0x40000;
  if (param_5 != 0) {
    uVar1 = param_3[1];
    uVar4 = 0;
    if ((uVar1 & 7) == 0) {
      uVar5 = uVar3 & 0xffff | 0x440000;
      uVar4 = 0x15;
    }
    if ((uVar1 & 1) != 0) {
      uVar5 = uVar5 | 0x400000;
      uVar4 = uVar4 & 0xfffffffc | 1;
    }
    if ((uVar1 & 2) != 0) {
      uVar5 = uVar5 | 0x400000;
      uVar4 = uVar4 & 0xfffffff3 | 4;
    }
    if ((uVar1 & 4) != 0) {
      uVar5 = uVar5 | 0x400000;
      uVar4 = uVar4 & 0xffffffcf | 0x10;
    }
    if ((uVar1 & 8) == 0) goto LAB_000b2364;
  }
  uVar5 = uVar5 | 0x400000;
  uVar4 = uVar4 | 0x40;
LAB_000b2364:
  uVar3 = param_3[2];
  if (uVar3 != 0) {
    uVar5 = uVar5 | 0x400000;
    if ((uVar3 & 0x40) != 0) {
      uVar4 = uVar4 | 0x100;
    }
    switch(uVar3 & 0x3f) {
    case 1:
      uVar4 = uVar4 | 0x200;
      break;
    case 2:
      uVar4 = uVar4 | 0x400;
      break;
    case 4:
      uVar4 = uVar4 | 0x600;
      break;
    case 8:
      uVar4 = uVar4 | 0x800;
      break;
    case 0x10:
      uVar4 = uVar4 | 0xa00;
      break;
    case 0x20:
      uVar4 = uVar4 | 0xc00;
    }
  }
  uVar3 = *param_2;
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar3 * 4 + param_2[2]) = uVar5;
  uVar3 = *param_2 + 1;
  *param_2 = uVar3;
  if ((uVar5 & 0x400000) != 0) {
    if (param_2[1] <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if ((void *)param_2[2] != (void *)0x0) {
        _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = (uint)pvVar2;
      uVar3 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(uVar3 * 4 + param_2[2]) = uVar4;
    *param_2 = *param_2 + 1;
  }
  return 1;
}

/* FUN_000b25a0 @ 0xb25a0 (2216 bytes) */
int FUN_000b25a0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined *puVar8;
  int iVar9;
  
  uVar4 = (uint)*(ushort *)(param_3 + 0x14);
  iVar5 = *(int *)(param_3 + 0x10);
  if (*(ushort *)(param_3 + 0x14) != 0) {
    uVar6 = 0;
    do {
      iVar9 = (uVar6 + uVar4 * param_4) * 0xc;
      iVar2 = iVar9 + *(int *)(iVar5 + 0xc);
      if (*(char *)(iVar9 + *(int *)(iVar5 + 0xc)) != '\0') {
        uVar7 = *(uint *)(iVar2 + 4);
        puVar8 = (undefined *)0x0;
        if (*(char *)(iVar2 + 1) == '\0') {
          if ((uVar7 == 0x8976) && (uVar6 == *(int *)(iVar2 + 8) - 0x8921U)) goto LAB_000b2c0c;
          uVar4 = *param_2;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + param_2[2]) = 0x47;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar4 * 4 + param_2[2]) = uVar6 + 6 & 0xffff | 0x40000;
          *param_2 = *param_2 + 1;
          *(undefined1 *)(param_6 + uVar6) = 1;
          iVar2 = *(int *)(iVar9 + *(int *)(iVar5 + 0xc) + 8);
          if (iVar2 - 0x84c0U < 6) {
            uVar4 = iVar2 + 0x7b40U & 0xffff | 0x110000;
          }
          else {
            uVar4 = iVar2 + 0x76dfU & 0xffff | 0x40000;
          }
          uVar3 = *param_2;
          if (param_2[1] <= uVar3) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar3 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar3 * 4 + param_2[2]) = uVar4 | 0x400000;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
        }
        else {
          uVar4 = *param_2;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar4 * 4 + param_2[2]) = (uVar6 & 0x3fff) << 0x10 | 0x5d;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar4 * 4 + param_2[2]) = uVar6 + 6 & 0xffff | 0x40000;
          *param_2 = *param_2 + 1;
          iVar2 = *(int *)(iVar9 + *(int *)(iVar5 + 0xc) + 8);
          if (iVar2 - 0x84c0U < 6) {
            uVar4 = iVar2 + 0x7b40U & 0xffff | 0x110000;
          }
          else if (*(char *)(param_6 + iVar2 + -0x8921) == '\0') {
            uVar7 = 0;
            uVar4 = iVar2 + 0x76dfU & 0xffff | 0x10000;
          }
          else {
            uVar4 = iVar2 + 0x76dfU & 0xffff | 0x40000;
          }
          *(undefined1 *)(uVar6 + param_6) = 1;
          uVar3 = *param_2;
          if (param_2[1] <= uVar3) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar3 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar3 * 4 + param_2[2]) = uVar4 | 0x400000;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
        }
        if (uVar7 == 0x8977) {
          puVar8 = ((unsigned char *)0x00003310);
        }
        else if (uVar7 < 0x8978) {
          if (uVar7 == 0) {
            puVar8 = ((unsigned char *)0x00004444);
          }
          else if (uVar7 == 0x8976) {
            puVar8 = ((unsigned char *)0x00003210);
          }
        }
        else if (uVar7 == 0x8978) {
          puVar8 = (undefined *)0x602510;
        }
        else if (uVar7 == 0x8979) {
          puVar8 = (undefined *)0x603510;
        }
        if (param_2[1] <= uVar4) {
          pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar1;
          uVar4 = *param_2;
          param_2[1] = param_2[1] + 0x80;
        }
        *(undefined **)(uVar4 * 4 + param_2[2]) = puVar8;
        *param_2 = *param_2 + 1;
        uVar4 = (uint)*(ushort *)(param_3 + 0x14);
      }
LAB_000b2c0c:
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < (int)uVar4);
    if (uVar4 != 0) {
      uVar6 = 0;
      do {
        iVar2 = (uVar6 + uVar4 * param_4) * 0xc;
        iVar9 = iVar2 + *(int *)(iVar5 + 0xc);
        if ((*(char *)(iVar2 + *(int *)(iVar5 + 0xc)) != '\0') &&
           (((*(char *)(iVar9 + 1) != '\0' || (*(int *)(iVar9 + 4) != 0x8976)) ||
            (uVar6 != *(int *)(iVar9 + 8) - 0x8921U)))) {
          uVar4 = *param_2;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + param_2[2]) = 0x47;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar4 * 4 + param_2[2]) = uVar6 & 0xffff | 0x40000;
          uVar4 = *param_2 + 1;
          *param_2 = uVar4;
          if (param_2[1] <= uVar4) {
            pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
            if ((void *)param_2[2] != (void *)0x0) {
              _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
              (**(code **)(param_1 + 0x18))(param_2[2]);
            }
            param_2[2] = (uint)pvVar1;
            uVar4 = *param_2;
            param_2[1] = param_2[1] + 0x80;
          }
          *(uint *)(uVar4 * 4 + param_2[2]) = (uVar6 & 0xffff) + 6 & 0xffff | 0x40000;
          *param_2 = *param_2 + 1;
          uVar4 = (uint)*(ushort *)(param_3 + 0x14);
        }
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < (int)uVar4);
    }
  }
  return;
}

/* FUN_000b2e60 @ 0xb2e60 (636 bytes) */
int FUN_000b2e60(param_1, param_2)
  int param_1;
  uint *param_2;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x47;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x40000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x410000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar1,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar1;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined **)(uVar2 * 4 + param_2[2]) = ((unsigned char *)0x00004444);
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000b30e0 @ 0xb30e0 (1352 bytes) */
int FUN_000b30e0(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  uVar5 = *param_2;
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (param_2[1] <= uVar5) {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    uVar5 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + param_2[2]) = 0x1ff0016;
  uVar5 = *param_2 + 1;
  *param_2 = uVar5;
  if (param_2[1] <= uVar5) {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    uVar5 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + param_2[2]) = 0x120000;
  uVar5 = *param_2 + 1;
  *param_2 = uVar5;
  if (*(char *)(param_4 + 0x6c) == '\0') {
    if ((*(uint *)(param_1 + 0x44) & 0x80100000) == 0x80000000) {
      if (*(short *)("}J3x})+x|B;x}k" + iVar6) != -0x7e06) goto LAB_000b3398;
    }
    else if ((*(uint *)(param_1 + 0x44) & 0x800000) == 0) goto LAB_000b3398;
  }
  if (param_2[1] <= uVar5) {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    uVar5 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + param_2[2]) = 0x1ff0016;
  uVar5 = *param_2 + 1;
  *param_2 = uVar5;
  if (param_2[1] <= uVar5) {
    pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar3;
    uVar5 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + param_2[2]) = 0x130000;
  uVar5 = *param_2 + 1;
  *param_2 = uVar5;
LAB_000b3398:
  uVar1 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
  if (uVar1 != 0) {
    uVar7 = 0;
    do {
      if (((int)(uint)*(byte *)(param_3 + 1) >> (uVar7 & 0x3f) & 1U) != 0) {
        if (param_2[1] <= uVar5) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar3;
          uVar5 = *param_2;
          param_2[1] = param_2[1] + 0x80;
        }
        *(undefined4 *)(uVar5 * 4 + param_2[2]) = 0x1ff0016;
        uVar5 = *param_2 + 1;
        *param_2 = uVar5;
        if (param_2[1] <= uVar5) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar3;
          uVar5 = *param_2;
          param_2[1] = param_2[1] + 0x80;
        }
        *(uint *)(uVar5 * 4 + param_2[2]) = uVar7 & 0xffff | 0x110000;
        uVar5 = *param_2 + 1;
        *param_2 = uVar5;
        uVar1 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
      }
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < (int)uVar1);
  }
  uVar1 = (uint)*(ushort *)(param_3 + 0x14);
  if (*(ushort *)(param_3 + 0x14) != 0) {
    iVar8 = 0;
    iVar6 = 0;
    do {
      iVar4 = *(int *)(param_4 + 0xc);
      if (((*(char *)(iVar4 + iVar6) != '\0') && (*(char *)(iVar4 + iVar6 + 1) != '\0')) ||
         ((iVar2 = (iVar8 + uVar1) * 0xc, *(char *)(iVar4 + iVar2) != '\0' &&
          (*(char *)(iVar4 + iVar2 + 1) != '\0')))) {
        if (param_2[1] <= uVar5) {
          pvVar3 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
          if ((void *)param_2[2] != (void *)0x0) {
            _memcpy(pvVar3,(void *)param_2[2],*param_2 << 2);
            (**(code **)(param_1 + 0x18))(param_2[2]);
          }
          param_2[2] = (uint)pvVar3;
          uVar5 = *param_2;
          param_2[1] = param_2[1] + 0x80;
        }
        *(uint *)(uVar5 * 4 + param_2[2]) = iVar8 << 0x10 | 0x19;
        uVar5 = *param_2 + 1;
        *param_2 = uVar5;
        uVar1 = (uint)*(ushort *)(param_3 + 0x14);
      }
      iVar8 = iVar8 + 1;
      iVar6 = iVar6 + 0xc;
    } while (iVar8 < (int)uVar1);
  }
  return;
}

/* FUN_000b3630 @ 0xb3630 (3316 bytes) */
int FUN_000b3630(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  undefined2 uVar4;
  code *pcVar3;
  char cVar7;
  int iVar5;
  int iVar6;
  undefined4 uVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined1 *puVar18;
  code *pcVar19;
  int *piVar20;
  undefined1 *puVar21;
  int *piVar22;
  int iVar23;
  int iVar24;
  undefined1 local_74 [8];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_58;
  int local_54;
  
  local_54 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    iVar23 = *(int *)(((unsigned char *)0x00001144) + param_1);
  }
  else {
    iVar23 = *(int *)(((unsigned char *)0x00001154) + param_1) + 0x10;
  }
  puVar18 = *(undefined1 **)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 + *(int *)(iVar23 + 0x70));
  if (puVar18 != (undefined1 *)0x0) {
    uVar11 = *(uint *)(param_1 + 0x44);
    if ((uVar11 & 0x100000) == 0) {
      if ((((int)uVar11 < 0) && (*(short *)("}J3x})+x|B;x}k" + local_54) == -0x7e06)) ||
         (cVar7 = '\0', (uVar11 & 0x80800000) == 0x800000)) {
        cVar7 = '\x01';
      }
    }
    else if (((uVar11 & 0x800000) == 0) ||
            (cVar7 = '\x01', *(char *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0x6e) == '\0')) {
      cVar7 = '\0';
    }
    if (puVar18[0x118] == cVar7) {
      if (((unsigned char *)0x00001136)[param_1] != '\0') {
        *puVar18 = 0;
      }
    }
    else {
      puVar18[0x119] = 1;
    }
    if (puVar18[0x119] == '\0') goto LAB_000b42ec;
  }
  local_64 = 0;
  local_6c = 0;
  local_68 = 0;
  ((int (*)())FUN_000b15d0)(param_1,&local_6c,1);
  ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x10200);
  iVar5 = 0;
  iVar24 = 8;
  do {
    local_74[iVar5] = 0;
    iVar5 = iVar5 + 1;
    iVar24 = iVar24 + -1;
  } while (iVar24 != 0);
  if (puVar18 != (undefined1 *)0x0) {
    uVar8 = *(undefined4 *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 + *(int *)(iVar23 + 0x70));
    *(undefined4 *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 + *(int *)(iVar23 + 0x70)) = 0;
    (**(code **)(((unsigned char *)0x00001158) + param_1))(param_1,uVar8);
    pcVar3 = *(code **)(((unsigned char *)0x00001284) + param_1);
    iVar24 = *(int *)(((unsigned char *)0x0000113c) + param_1);
    pcVar19 = *(code **)(param_1 + 0x10);
    iVar5 = *(int *)(iVar23 + 0x70);
  }
  else {
    pcVar3 = *(code **)(((unsigned char *)0x00001284) + param_1);
    iVar24 = *(int *)(((unsigned char *)0x0000113c) + param_1);
    pcVar19 = *(code **)(param_1 + 0x10);
    iVar5 = *(int *)(iVar23 + 0x70);
  }
  uVar8 = (*pcVar3)(param_1);
  uVar8 = (*pcVar19)(1,uVar8);
  *(undefined4 *)(iVar24 * 4 + iVar5) = uVar8;
  puVar18 = *(undefined1 **)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 + *(int *)(iVar23 + 0x70));
  *puVar18 = 0;
  local_58 = *(int *)(iVar23 + 4);
  ((int (*)())FUN_000b30e0)(param_1,&local_6c,((unsigned char *)0x00001134) + param_1,iVar23);
  ((int (*)())FUN_000b2e60)(param_1,&local_6c);
  if (0 < local_58) {
    iVar15 = 0;
    iVar16 = 0;
    iVar24 = 0;
    iVar5 = 0;
    do {
      iVar13 = 0;
      iVar14 = 0;
      iVar17 = 0;
      ((int (*)())FUN_000b25a0)(param_1,&local_6c,((unsigned char *)0x00001134) + param_1,iVar5,local_58,local_74);
      while( true ) {
        iVar6 = *(int *)(*(int *)(iVar23 + 0x14) + iVar5 * 4);
        iVar12 = *(int *)(*(int *)(iVar23 + 0x20) + iVar5 * 4);
        if (iVar6 + iVar12 <= iVar17) break;
        if (((iVar15 < *(int *)(iVar23 + 0x18)) && (iVar13 < iVar6)) &&
           (piVar20 = (int *)(iVar15 * 0x4c + *(int *)(iVar23 + 0x10)), iVar24 == piVar20[0x11])) {
          iVar15 = iVar15 + 1;
          iVar13 = iVar13 + 1;
          iVar17 = iVar17 + 1;
          iVar24 = iVar24 + 1;
        }
        else {
          piVar20 = (int *)0x0;
        }
        if (((iVar16 < *(int *)(iVar23 + 0x24)) && (iVar14 < iVar12)) &&
           (piVar22 = (int *)(iVar16 * 0x4c + *(int *)(iVar23 + 0x1c)), iVar24 == piVar22[0x11])) {
          iVar14 = iVar14 + 1;
          iVar17 = iVar17 + 1;
          iVar16 = iVar16 + 1;
          iVar24 = iVar24 + 1;
        }
        else {
          piVar22 = (int *)0x0;
        }
        if ((piVar20 == (int *)0x0) || (piVar22 == (int *)0x0)) goto LAB_000b3a90;
        switch(*piVar22) {
        case 0x8961:
          uVar11 = 1;
          break;
        default:
          uVar11 = 0;
          break;
        case 0x8966:
        case 0x8967:
          if (*piVar22 == *piVar20) goto LAB_000b3a90;
        case 0x8963:
        case 0x8964:
        case 0x8965:
          uVar11 = 2;
          break;
        case 0x896c:
          if (*piVar20 == 0x896c) goto LAB_000b3a90;
        case 0x8968:
        case 0x8969:
        case 0x896a:
        case 0x896b:
          uVar11 = 3;
        }
        iVar6 = piVar20[1];
        if (((iVar6 != piVar22[5]) && ((iVar6 != piVar22[9] || (uVar11 < 2)))) &&
           ((iVar6 != piVar22[0xd] || (uVar11 < 3)))) {
LAB_000b3a90:
          if (piVar20 != (int *)0x0) {
            bVar1 = false;
            iVar6 = 0;
            goto LAB_000b3aa8;
          }
          bVar1 = false;
          iVar6 = 0;
          goto switchD_000b3adc_caseD_8962;
        }
        iVar6 = piVar20[1];
        bVar1 = true;
        piVar20[1] = 6;
LAB_000b3aa8:
        bVar2 = piVar22 != (int *)0x0;
        switch(*piVar20) {
        case 0x8961:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x47);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar20 + 1,0,1,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 5,0,1,local_74);
        default:
          goto switchD_000b3adc_caseD_8962;
        case 0x8963:
          uVar4 = 3;
          break;
        case 0x8964:
          uVar4 = 0x49;
          break;
        case 0x8965:
          uVar4 = 0x5b;
          break;
        case 0x8966:
          if ((bVar2) && (*piVar22 == 0x8966)) {
            piVar20[2] = piVar20[2] | 8;
          }
          uVar4 = 0x22;
          break;
        case 0x8967:
          if ((bVar2) && (*piVar22 == 0x8967)) {
            piVar20[2] = piVar20[2] | 8;
          }
          uVar4 = 0x23;
          break;
        case 0x8968:
          uVar4 = 0x40;
          goto LAB_000b3c70;
        case 0x8969:
          uVar4 = 0x3f;
LAB_000b3c70:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,uVar4);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar20 + 1,0,1,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 5,0,1,local_74);
LAB_000b3e14:
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 9,0,1,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 0xd,0,1,local_74);
          goto switchD_000b3adc_caseD_8962;
        case 0x896a:
          uVar11 = 0x3000d;
          iVar12 = 1;
          goto LAB_000b3d3c;
        case 0x896b:
          uVar11 = 0x2000d;
          iVar12 = 0;
LAB_000b3d3c:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,iVar12 << 0x16 | uVar11);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar20 + 1,0,1,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 0xd,0,1,local_74);
          goto LAB_000b3bb4;
        case 0x896c:
          if ((bVar2) && (*piVar22 == 0x896c)) {
            piVar20[2] = piVar20[2] | 8;
          }
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x21);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar20 + 1,0,1,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 5,0,1,local_74);
          goto LAB_000b3e14;
        }
        ((int (*)())FUN_000b15d0)(param_1,&local_6c,uVar4);
        ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar20 + 1,0,1,local_74);
LAB_000b3bb4:
        ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 5,0,1,local_74);
        ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar20 + 9,0,1,local_74);
switchD_000b3adc_caseD_8962:
        if (piVar22 == (int *)0x0) goto switchD_000b3e78_caseD_8962;
        switch(*piVar22) {
        case 0x8961:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x47);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar22 + 1,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 5,0,0,local_74);
          break;
        case 0x8963:
          uVar4 = 3;
          goto LAB_000b3f1c;
        case 0x8964:
          uVar4 = 0x49;
          goto LAB_000b3f1c;
        case 0x8965:
          uVar4 = 0x5b;
LAB_000b3f1c:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,uVar4);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar22 + 1,0,0,local_74);
LAB_000b4120:
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 5,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 9,0,0,local_74);
          break;
        case 0x8968:
          uVar4 = 0x40;
          goto LAB_000b3f68;
        case 0x8969:
          uVar4 = 0x3f;
LAB_000b3f68:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,uVar4);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar22 + 1,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 5,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 9,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 0xd,0,0,local_74);
          break;
        case 0x896a:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x43000d);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar22 + 1,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 0xd,0,0,local_74);
          goto LAB_000b4120;
        case 0x896b:
          ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x2000d);
          ((int (*)())FUN_000b2260)(param_1,&local_6c,piVar22 + 1,0,0,local_74);
          ((int (*)())FUN_000b1e80)(param_1,&local_6c,piVar22 + 0xd,0,0,local_74);
          goto LAB_000b4120;
        }
switchD_000b3e78_caseD_8962:
        if (bVar1) {
          ((int (*)())FUN_000b1b90)(param_1,&local_6c,iVar6,piVar20[1],piVar20[2]);
          piVar20[1] = iVar6;
        }
      }
      iVar5 = iVar5 + 1;
    } while (local_58 != iVar5);
  }
  if ((*(uint *)(param_1 + 0x44) & 0x80100000) == 0x80000000) {
    if (*(short *)("}J3x})+x|B;x}k" + local_54) == -0x7e06) goto LAB_000b420c;
LAB_000b41b8:
    puVar18[0x118] = 0;
  }
  else {
    if ((*(uint *)(param_1 + 0x44) & 0x800000) == 0) goto LAB_000b41b8;
LAB_000b420c:
    ((int (*)())FUN_000b1870)(param_1,&local_6c);
    puVar18[0x118] = 1;
  }
  ((int (*)())FUN_000b1690)(param_1,&local_6c);
  ((int (*)())FUN_000b15d0)(param_1,&local_6c,0x28);
  *(undefined4 *)(puVar18 + 0x11c) = 0;
  uVar11 = (uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1);
  if (uVar11 != 0) {
    uVar10 = 0;
    iVar5 = 0;
    puVar21 = puVar18;
    do {
      if (*(char *)(*(int *)(iVar23 + 0x28) + iVar5) != '\0') {
        *(uint *)(puVar18 + 0x11c) = 1 << (uVar10 & 0x3f) | *(uint *)(puVar18 + 0x11c);
        *(undefined4 *)(puVar21 + 0x98) = *(undefined4 *)(*(int *)(iVar23 + 0x28) + iVar5 + 4);
        *(undefined4 *)(puVar21 + 0x9c) = *(undefined4 *)(*(int *)(iVar23 + 0x28) + iVar5 + 8);
        *(undefined4 *)(puVar21 + 0xa0) = *(undefined4 *)(*(int *)(iVar23 + 0x28) + iVar5 + 0xc);
        *(undefined4 *)(puVar21 + 0xa4) = *(undefined4 *)(*(int *)(iVar23 + 0x28) + iVar5 + 0x10);
        uVar11 = (uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1);
      }
      uVar10 = uVar10 + 1;
      iVar5 = iVar5 + 0x14;
      puVar21 = puVar21 + 0x10;
    } while ((int)uVar10 < (int)uVar11);
  }
  puVar18[0x120] = 1;
  (**(code **)(((unsigned char *)0x00001288) + param_1))(param_1,0,puVar18,&local_6c);
  puVar18[0x119] = 0;
LAB_000b42ec:
  uVar11 = 0;
  iVar23 = 0;
  ((unsigned char *)0x00001136)[param_1] = 0;
  puVar21 = puVar18 + 0x98;
  do {
    if ((1 << (uVar11 & 0x3f) & *(uint *)(puVar18 + 0x11c)) == 0) {
      if (*(char *)(iVar23 + *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0xc)) != '\0') {
        pcVar3 = *(code **)(((unsigned char *)0x00001280) + param_1);
        puVar9 = (undefined1 *)(iVar23 + *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0xc) + 4);
        goto LAB_000b4370;
      }
    }
    else {
      pcVar3 = *(code **)(((unsigned char *)0x00001280) + param_1);
      puVar9 = puVar21;
LAB_000b4370:
      (*pcVar3)(param_1,puVar18,uVar11,uVar11,puVar9,1,0);
    }
    bVar1 = uVar11 == 7;
    puVar21 = puVar21 + 0x10;
    iVar23 = iVar23 + 0x14;
    uVar11 = uVar11 + 1;
    if (bVar1) {
      if ((*(uint *)(param_1 + 0x44) & 0x22000) == 0x20000) {
        (**(code **)(((unsigned char *)0x00001290) + param_1))(param_1,puVar18);
      }
      return 1;
    }
  } while( true );
}

/* FUN_000b4400 @ 0xb4400 (2136 bytes) */
int FUN_000b4400(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined1 local_38 [28];
  
  if ((((param_2 == (int *)0x0) || (param_3 == (int *)0x0)) || (param_4 == (int *)0x0)) ||
     (param_5 == 0)) {
    return 1;
  }
  *param_2 = param_1;
  param_2[0xe] = 0;
  param_2[1] = 0;
  iVar8 = 0;
  param_2[2] = 0;
  *(undefined1 *)(param_2 + 3) = 0;
  *(undefined1 *)((int)param_2 + 0xd) = 0;
  *(undefined1 *)((int)param_2 + 0xe) = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[7] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  *(undefined1 *)(param_2 + 0xd) = 0;
  param_2[8] = 0;
  param_2[6] = 0x21;
  piVar4 = param_2;
  piVar7 = param_2;
  piVar9 = param_2;
  do {
    bVar1 = iVar8 != 2;
    piVar4[0xf] = 0x21;
    piVar4[0x12] = 0;
    piVar9[0x15] = 0;
    piVar9[0x16] = 1;
    piVar9[0x17] = 2;
    piVar9[0x18] = 3;
    *(undefined1 *)(piVar4 + 0x21) = 0;
    *(undefined1 *)((int)piVar4 + 0x85) = 0;
    *(undefined1 *)((int)piVar4 + 0x86) = 0;
    *(undefined1 *)((int)piVar4 + 0x87) = 0;
    *(undefined1 *)(piVar7 + 0x24) = 0;
    *(undefined1 *)((int)piVar7 + 0x93) = 0;
    *(undefined1 *)((int)piVar7 + 0x96) = 0;
    *(undefined1 *)((int)piVar7 + 0x99) = 0;
    *(undefined1 *)(piVar7 + 0x27) = 0;
    piVar4[0x28] = 0;
    piVar9 = piVar9 + 4;
    piVar4 = piVar4 + 1;
    piVar7 = (int *)((int)piVar7 + 1);
    iVar8 = iVar8 + 1;
  } while (bVar1);
  param_2[0x2d] = 0;
  *(undefined1 *)(param_2 + 0x2b) = 0;
  param_2[0x2c] = 0;
  iVar8 = 0x10;
  piVar4 = param_2;
  piVar7 = param_2;
  do {
    *(undefined1 *)(piVar4 + 0x56e) = 0;
    piVar7[0x572] = 0;
    *(undefined1 *)(piVar4 + 0x582) = 0;
    *(undefined1 *)(piVar4 + 0x586) = 0;
    piVar7[0x7aa] = 0;
    piVar4 = (int *)((int)piVar4 + 1);
    piVar7 = piVar7 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0x30;
  piVar4 = param_2;
  piVar7 = param_2;
  do {
    *(undefined1 *)(piVar7 + 0x58a) = 0;
    piVar4[0x658] = 0;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  param_2[0x788] = 0;
  param_2[0x656] = 0;
  param_2[0x78a] = 0x100;
  iVar8 = 0;
  piVar4 = param_2;
  piVar7 = param_2;
  piVar9 = param_2;
  do {
    *(undefined1 *)(piVar7 + 0x596) = 0;
    *(undefined1 *)(piVar7 + 0x5d6) = 0;
    iVar8 = iVar8 + 1;
    piVar9[0x688] = 0;
    piVar4[0x6e] = 0;
    piVar4[0x6f] = 0;
    piVar4[0x70] = 0;
    piVar4[0x71] = 0;
    *(undefined1 *)(piVar7 + 0x2e) = 0;
    piVar9 = piVar9 + 1;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar4 = piVar4 + 5;
  } while (iVar8 < param_2[0x78a]);
  param_2[0x7a5] = 0;
  param_2[0x657] = 0;
  param_2[0x789] = 0;
  *(undefined1 *)(param_2 + 0x78b) = 0;
  iVar8 = 8;
  *(undefined1 *)((int)param_2 + 0x1e2d) = 0;
  *(undefined1 *)((int)param_2 + 0x1e2e) = 0;
  *(undefined1 *)((int)param_2 + 0x1e2f) = 0;
  *(undefined1 *)(param_2 + 0x78c) = 0;
  param_2[0x7a3] = 0;
  param_2[0x7a4] = 0;
  piVar4 = param_2;
  piVar7 = param_2;
  do {
    *(undefined1 *)((int)piVar7 + 0x1e31) = 0;
    *(undefined1 *)((int)piVar7 + 0x1e39) = 0;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar4[0x793] = 0;
    piVar4[0x79b] = 0;
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  param_2[0x7a9] = 0;
  param_2[0x791] = 0;
  param_2[0x792] = 0;
  *(undefined1 *)(param_2 + 0x7a6) = 0;
  iVar8 = 4;
  *(undefined1 *)((int)param_2 + 0x1e99) = 0;
  *(undefined1 *)((int)param_2 + 0x1e9a) = 0;
  *(undefined1 *)((int)param_2 + 0x1e9b) = 0;
  *(undefined1 *)(param_2 + 0x7a7) = 0;
  *(undefined1 *)((int)param_2 + 0x1e9d) = 0;
  *(undefined1 *)((int)param_2 + 0x1e9e) = 0;
  *(undefined1 *)((int)param_2 + 0x1e9f) = 0;
  *(undefined1 *)(param_2 + 0x7a8) = 0;
  *(undefined1 *)((int)param_2 + 0x1ea1) = 0;
  *(undefined1 *)(param_2 + 0x7ba) = 0;
  param_2[0x7bb] = 0;
  param_2[0x7bc] = 0;
  param_2[0x7bd] = 0;
  piVar4 = param_2;
  do {
    *(undefined1 *)(piVar4 + 0x7be) = 0;
    piVar4 = (int *)((int)piVar4 + 1);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(undefined1 *)(param_2 + 0x7c1) = 0;
  *(undefined1 *)(param_2 + 0x7bf) = 0;
  *(undefined1 *)((int)param_2 + 0x1efd) = 0;
  param_2[0x7c5] = 0;
  param_2[0x7c3] = 0;
  param_2[0x7c2] = 1;
  param_2[0x7c6] = 0;
  param_2[0x7c4] = 0;
  param_2[0x7c7] = 0x8000;
  *param_3 = param_5;
  param_3[1] = (int)(((unsigned char *)0x000010ec) + param_5);
  *(undefined4 *)(((unsigned char *)0x000012fc) + param_5) = 0;
  iVar10 = 0x10;
  *(undefined4 *)(((unsigned char *)0x000010e4) + *param_3) = 0xffffffff;
  iVar8 = param_5;
  do {
    *(undefined4 *)(((unsigned char *)0x000015d0) + iVar8) = 0;
    ((unsigned char *)0x00001610)[param_5] = 0;
    param_5 = param_5 + 1;
    *(undefined4 *)(((unsigned char *)0x00001620) + iVar8) = 0;
    iVar8 = iVar8 + 4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar8 = 8;
  *(undefined4 *)(((unsigned char *)0x000010e0) + *param_3) = 0;
  *(undefined4 *)(((unsigned char *)0x000015cc) + *param_3) = 0;
  ((unsigned char *)0x000010e9)[*param_3] = 0;
  ((unsigned char *)0x000010ea)[*param_3] = 0;
  param_3[0x12] = 1;
  param_3[0x1a] = 0;
  param_3[0x18] = 0;
  param_3[0x17] = 0;
  param_3[0x19] = 0;
  param_3[0x15] = 0;
  param_3[0x16] = 0;
  param_3[0x13] = 0;
  param_3[0x14] = 0;
  piVar4 = param_3;
  do {
    piVar4[0x1b] = 0;
    piVar4[0x23] = 0;
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0;
  iVar10 = 4;
  do {
    iVar2 = iVar8 * 4;
    iVar8 = iVar8 + 1;
    *(undefined4 *)(((unsigned char *)0x000010a8) + iVar2 + *param_3) = 0;
    *(undefined4 *)(((unsigned char *)0x00001098) + iVar2 + *param_3) = 0;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar8 = 8;
  piVar4 = param_3;
  do {
    *(undefined1 *)(piVar4 + 0x2c) = 0;
    piVar4 = (int *)((int)piVar4 + 1);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 4;
  param_3[0x36] = 0;
  param_3[0x3a] = 0;
  param_3[0x37] = 0x8000;
  param_3[0x2e] = 0x8000;
  param_3[0x2f] = 0x8000;
  param_3[0x30] = 0x8000;
  param_3[0x31] = 0x8000;
  param_3[0x32] = 0x8000;
  param_3[0x33] = 0x8000;
  param_3[0x34] = 0x8000;
  param_3[0x35] = 0x8000;
  param_3[0x3b] = 0;
  param_3[0x3c] = 0;
  param_3[0x3d] = 0;
  param_3[0x42] = 0;
  piVar4 = param_3;
  do {
    piVar4[0x3e] = 0;
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(undefined1 *)(param_3 + 0x44) = 0;
  *(undefined1 *)(param_3 + 0x43) = 0;
  *(undefined1 *)((int)param_3 + 0x10d) = 0;
  *(undefined1 *)((int)param_3 + 0x10e) = 0;
  *(undefined1 *)((int)param_3 + 0x10f) = 0;
  param_2[2] = *param_4;
  *(byte *)((int)param_2 + 0x1f05) = (byte)param_4[3] & 1;
  *(byte *)((int)param_2 + 0x1f06) = (byte)param_4[3] & 2;
  uVar3 = (uint)param_4[3] >> 2 & 3;
  param_3[0x45] = uVar3;
  if (uVar3 != 0) {
    *(undefined1 *)(param_2 + 0x7a8) = 1;
  }
  if ((param_4[3] & 0x100U) == 0) {
    *(undefined1 *)(param_3 + 0x46) = 0;
    param_3[1] = (int)(((unsigned char *)0x000010ec) + *param_3);
  }
  else {
    *(undefined1 *)(param_3 + 0x46) = 1;
    param_3[1] = (int)(((unsigned char *)0x00001318) + *param_3);
  }
  if ((param_4[3] & 0x400U) == 0) {
    param_3[0x47] = 0;
  }
  else {
    param_3[0x47] = param_4[4];
  }
  if ((param_4[3] & 0x200U) == 0) {
    *(undefined1 *)((int)param_3 + 0x119) = 0;
  }
  else {
    *(undefined1 *)((int)param_3 + 0x119) = 1;
  }
  iVar8 = 0;
  iVar10 = 8;
  do {
    local_38[iVar8] = 0;
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  puVar5 = (undefined4 *)((int (*)())FUN_000a6f70)(0x48000);
  param_3[3] = (int)puVar5;
  _memset(puVar5,0,0x48);
  *(undefined1 *)(puVar5 + 3) = 0;
  *(undefined1 *)((int)puVar5 + 0xd) = 0;
  *(undefined2 *)(puVar5 + 5) = 0;
  *(undefined2 *)((int)puVar5 + 0x22) = 0;
  puVar5[1] = 0x1000;
  *puVar5 = 0;
  puVar5[2] = 0;
  param_3[2] = (int)(puVar5 + 0x12);
  iVar8 = FUN_000879f0(param_1,param_2,param_3,param_3[1],puVar5 + 0x12,local_38,0,0);
  iVar10 = 0;
  param_3[2] = iVar8;
  *(undefined1 *)(param_2 + 0x7c8) = 1;
  iVar8 = 0x10;
  do {
    iVar2 = iVar10 * 0x10;
    iVar10 = iVar10 + 1;
    *(undefined4 *)(iVar2 + param_3[1] + 0x108) = 0;
    *(undefined4 *)(iVar2 + param_3[1] + 0x10c) = 1;
    *(undefined4 *)(iVar2 + param_3[1] + 0x110) = 2;
    *(undefined4 *)(iVar2 + param_3[1] + 0x114) = 3;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (param_1 == 0) {
    iVar8 = param_4[6];
  }
  else {
    if (*(int *)(param_1 + 0x186c) == 0) {
      FUN_000c6ff0(param_1,*(undefined4 *)(param_1 + 0x2454));
    }
    iVar8 = param_1 + 0x186c;
  }
  iVar8 = FUN_000cae90(param_1,param_2,param_3,param_4,iVar8);
  if (iVar8 != 0) {
    return 2;
  }
  FUN_000c5e60(param_3[3]);
  iVar8 = param_3[3];
  FUN_000c5e60(iVar8);
  if ((param_4[3] & 0x100U) == 0) {
    iVar10 = *param_3 + 4;
  }
  else {
    iVar10 = *param_3 + 0x20;
  }
  uVar6 = ((int (*)())FUN_000a6f70)(((uint)*(ushort *)(iVar8 + 0x1c) + (uint)*(ushort *)(iVar8 + 0x1a) +
                       (uint)*(ushort *)(iVar8 + 0x20)) * 0x18);
  *(undefined4 *)(iVar10 + 0x10) = uVar6;
  iVar8 = FUN_000bfed0(param_3[3],param_3[1] + 0x44,iVar10);
  if ((param_4[3] & 0x100U) == 0) {
    *(uint *)(((unsigned char *)0x000036a8) + *param_3) =
         ((*(uint *)(iVar10 + 8) >> 0x10 & 0x1ff) - (*(uint *)(iVar10 + 8) & 0x1ff)) + 1;
    *(uint *)(((unsigned char *)0x000036b0) + *param_3) = (*(uint *)(param_3[1] + 0x44) & 0xf) + 1;
  }
  else {
    *(uint *)(((unsigned char *)0x000036b4) + *param_3) =
         ((*(uint *)(iVar10 + 8) >> 0x10 & 0x1ff) - (*(uint *)(iVar10 + 8) & 0x1ff)) + 1;
    *(uint *)(((unsigned char *)0x000036bc) + *param_3) = (*(uint *)(param_3[1] + 0x44) & 0xf) + 1;
  }
  ((unsigned char *)0x000036c5)[*param_3] = 1;
  _free((void *)param_3[3]);
  if (8 < (uint)(((param_2[0x791] + param_2[0x792]) -
                 ((int)-(uint)*(byte *)((int)param_2 + 0x1e2e) >> 0x1f)) -
                ((int)-(uint)*(byte *)((int)param_2 + 0x1e2f) >> 0x1f))) {
    param_2[1] = 6;
    return 6;
  }
  if (iVar8 == 0) {
switchD_000b4be8_caseD_80000007:
    uVar6 = 0;
  }
  else {
    switch(iVar8) {
    case -0x7fffffff:
    case -0x7ffffff0:
      uVar6 = 3;
      break;
    case -0x7ffffffe:
    case -0x7fffffee:
      uVar6 = 4;
      break;
    case -0x7ffffffd:
    case -0x7fffffec:
      uVar6 = 6;
      break;
    case -0x7ffffffc:
    case -0x7fffffea:
      uVar6 = 9;
      break;
    case -0x7ffffffb:
    case -0x7fffffeb:
      uVar6 = 10;
      break;
    case -0x7ffffffa:
    case -0x7fffffef:
      uVar6 = 8;
      break;
    default:
      goto switchD_000b4be8_caseD_80000007;
    case -0x7fffffed:
      uVar6 = 5;
      break;
    case -0x7fffffe9:
      uVar6 = 0xb;
      break;
    case -0x7fffffe8:
      uVar6 = 0xc;
    }
  }
  return uVar6;
}

/* FUN_000b4f50 @ 0xb4f50 (180 bytes) */
void FUN_000b4f50(double param_1,double param_2,double param_3,double param_4,int param_5,
                 int param_6)

{
  undefined4 uVar1;
  int in_r9;
  
  if (in_r9 == 0) {
    uVar1 = ((uint (*)())FUN_0004a7d0)();
    param_5 = param_6 * 0x10 + param_5;
    *(undefined4 *)(param_5 + 0x8c) = uVar1;
    uVar1 = ((uint (*)())FUN_0004a7d0)(param_2);
    *(undefined4 *)(param_5 + 0x90) = uVar1;
    uVar1 = ((uint (*)())FUN_0004a7d0)(param_3);
    *(undefined4 *)(param_5 + 0x94) = uVar1;
    uVar1 = ((uint (*)())FUN_0004a7d0)(param_4);
    *(undefined4 *)(param_5 + 0x98) = uVar1;
  }
  else {
    param_5 = param_6 * 0x10 + param_5;
    *(float *)(param_5 + 0x98) = (float)param_4;
    *(float *)(param_5 + 0x8c) = (float)param_1;
    *(float *)(param_5 + 0x90) = (float)param_2;
    *(float *)(param_5 + 0x94) = (float)param_3;
  }
  return;
}

/* FUN_000b5010 @ 0xb5010 (132 bytes) */
int FUN_000b5010(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int param_4;
{
  if ((param_4 < 0x100) && (((unsigned char *)0x00001658)[param_4 + param_2] != '\0')) {
    if (*(char *)(param_4 + param_2 + 0x1758) == '\0') {
      ((void (*)())FUN_000b4f50)(*param_3,*(int *)(param_4 * 4 + param_2 + 0x1a20) - *(int *)(param_2 + 0x1f1c));
      *(undefined4 *)(param_1 + 0x1e64) = 0;
      ((unsigned char *)0x000010eb)[*param_3] = 0;
    }
  }
  return;
}

/* FUN_000b50a0 @ 0xb50a0 (228 bytes) */
int FUN_000b50a0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  fVar1 = FLOAT_001aa0e8;
  if (((unsigned char *)0x000013b1)[param_1] != '\0') {
    iVar3 = 0;
    iVar4 = param_1;
    iVar5 = param_2;
    iVar6 = param_2;
    do {
      if (((unsigned char *)0x00001618)[iVar6] != '\0') {
        iVar2 = *(int *)(((unsigned char *)0x000013f8) + iVar4);
        if (iVar2 != 0) {
          ((void (*)())FUN_000b4f50)((double)(fVar1 / *(float *)(iVar2 + 0x44)),
                       (double)(fVar1 / *(float *)(iVar2 + 0x48)),(double)*(float *)(iVar2 + 0x50),
                       (double)*(float *)(((unsigned char *)0x00001620) + iVar3 * 4 + *param_3),*param_3,
                       (*(int *)(iVar5 + 0x1ea8) - *(int *)(param_2 + 0x1f1c)) + param_3[0x36]);
        }
      }
      iVar3 = iVar3 + 1;
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + 4;
      iVar5 = iVar5 + 4;
    } while (iVar3 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
  }
  return;
}

/* FUN_000b5190 @ 0xb5190 (4 bytes) */
int FUN_000b5190()
{
  return;
}

/* FUN_000b51a0 @ 0xb51a0 (376 bytes) */
int FUN_000b51a0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  float fVar1;
  float fVar2;
  double dVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined8 uVar11;
  
  puVar5 = param_3;
  uVar11 = FUN_001a3260();
  dVar3 = DOUBLE_001aa240;
  iVar4 = *(int *)((int)((ulonglong)uVar11 >> 0x20) + 4);
  iVar6 = *(int *)(iVar4 + 0x10);
  if (*(char *)((int)uVar11 + 0x1e2f) != '\0') {
    fVar1 = *(float *)(iVar4 + 0x2a58);
    fVar2 = *(float *)(iVar4 + 0x2a54);
    dVar9 = (double)CONCAT44(0x43300000,*(uint *)(iVar6 + 0x1840) ^ 0x80000000) - DOUBLE_001aa1e0;
    dVar10 = (double)CONCAT44(0x43300000,*(uint *)(iVar6 + 0x1844) ^ 0x80000000) - DOUBLE_001aa1e0;
    dVar8 = (double)(fVar2 * (float)((double)CONCAT44(0x43300000,
                                                      *(uint *)(iVar6 + 0x1848) ^ 0x80000000) -
                                    DOUBLE_001aa1e0) * FLOAT_001aa10c);
    dVar7 = (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                      *(uint *)(iVar6 + 0x184c) ^ 0x80000000) -
                                    DOUBLE_001aa1e0) * FLOAT_001aa10c);
    ((void (*)())FUN_000b4f50)(dVar8,dVar7,
                 (double)(float)((*(double *)(iVar6 + 0x1838) - *(double *)(FUN_00001830 + iVar6)) *
                                DOUBLE_001aa240),(double)FLOAT_001aa0d4,*puVar5,
                 puVar5[0x2e] - *(int *)((int)uVar11 + 0x1f1c));
    ((void (*)())FUN_000b4f50)((double)(float)((double)(fVar2 * (float)dVar9) + dVar8),
                 (double)(float)((double)(fVar1 * (float)dVar10) + dVar7),
                 (double)(float)((*(double *)(iVar6 + 0x1838) + *(double *)(FUN_00001830 + iVar6)) *
                                dVar3),(double)FLOAT_001aa0d4,*param_3,
                 param_3[0x2f] - *(int *)(param_2 + 0x1f1c));
    *(undefined4 *)(param_1 + 0x1e64) = 0;
  }
  return;
}

/* FUN_000b5320 @ 0xb5320 (204 bytes) */
int FUN_000b5320(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(char *)(param_2 + 0x1ea0) != '\0') {
    ((void (*)())FUN_000b4f50)(-(double)*(float *)(((unsigned char *)0x00002dfc) + iVar1),
                 (double)(float)((double)*(float *)(((unsigned char *)0x00002dfc) + iVar1) *
                                (double)*(float *)(((unsigned char *)0x00002df8) + iVar1)),
                 (double)(float)((double)*(float *)(((unsigned char *)0x00002df0) + iVar1) / DOUBLE_001aa268),
                 (double)(float)((double)*(float *)(((unsigned char *)0x00002df0) + iVar1) / DOUBLE_001aa270),
                 *param_3,param_3[0x38] - *(int *)(param_2 + 0x1f1c));
    ((void (*)())FUN_000b4f50)((double)*(float *)(((unsigned char *)0x00002de0) + iVar1),(double)*(float *)(((unsigned char *)0x00002de4) + iVar1)
                 ,(double)*(float *)(((unsigned char *)0x00002de8) + iVar1),(double)FLOAT_001aa0d4,*param_3,
                 param_3[0x39] - *(int *)(param_2 + 0x1f1c));
    *(undefined4 *)(param_1 + 0x1e64) = 0;
  }
  return;
}

/* FUN_000b5400 @ 0xb5400 (928 bytes) */
int FUN_000b5400(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  iVar9 = *(int *)(param_2 + 0x14);
  iVar10 = *(int *)(((unsigned char *)0x00004024) + iVar9);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
  iVar11 = iVar10 * 4;
  puVar5[1] = 0;
  *puVar5 = 0x8a1;
  iVar4 = *(int *)(FUN_00002748 + param_1 + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = iVar4 + 8;
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar4 + 8);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,6);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
  *puVar5 = ((unsigned char *)0x000208b4);
  puVar5[1] = *(undefined4 *)(param_1 + 0x1b90);
  puVar5[2] = *(undefined4 *)(param_1 + 0x1b8c);
  uVar7 = *(undefined4 *)(param_1 + 0x1b94);
  puVar5[4] = 0x820;
  puVar5[3] = uVar7;
  puVar5[5] = *(undefined4 *)(param_1 + 0x1b7c);
  iVar4 = *(int *)(FUN_00002748 + param_1 + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = iVar4 + 0x18;
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar4 + 0x18);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
  *puVar5 = 0x8b7;
  puVar5[1] = *(undefined4 *)(param_1 + 0x1b98);
  iVar4 = *(int *)(FUN_00002748 + param_1 + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = iVar4 + 8;
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar4 + 8);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar11 + 3);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
  *puVar5 = 0x880;
  uVar3 = *(uint *)(((unsigned char *)0x0000548c) + iVar9);
  puVar5[2] = (iVar11 + -1) * 0x10000 | 0x8882;
  puVar5[1] = uVar3 & 0x3ff;
  _memcpy(puVar5 + 3,(void *)(iVar9 + 0x24),*(int *)(((unsigned char *)0x00004024) + iVar9) << 4);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  iVar11 = iVar10 * 0x10 + *(int *)(FUN_00002748 + param_1 + 4) + 0xc;
  *(int *)(FUN_00002748 + param_1 + 4) = iVar11;
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar11);
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x15);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
  *puVar5 = 0x82d;
  iVar9 = 8;
  uVar7 = *(undefined4 *)(param_1 + 0x1ca4);
  puVar5[2] = 0x861;
  puVar5[1] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1ca0);
  puVar5[4] = 0x824;
  puVar5[3] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1b9c);
  puVar5[6] = 0x825;
  puVar5[5] = uVar7;
  uVar7 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar5[8] = ((unsigned char *)0x000010c0);
  puVar5[7] = uVar7;
  puVar5[9] = *(undefined4 *)(param_1 + 0x1f2c);
  puVar5[10] = *(uint *)(param_1 + 0x1f28) | 0x70000;
  iVar11 = 0;
  iVar4 = param_1;
  do {
    puVar1 = (undefined4 *)(iVar4 + 0x1ee8);
    iVar4 = iVar4 + 4;
    *(undefined4 *)((int)puVar5 + iVar11 + 0x2c) = *puVar1;
    iVar9 = iVar9 + -1;
    iVar11 = iVar11 + 4;
  } while (iVar9 != 0);
  puVar5[0x13] = ((unsigned char *)0x00001047);
  puVar5[0x14] = *(undefined4 *)(param_1 + 0x1bb0);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x54;
  (*UNRECOVERED_JUMPTABLE)(param_1);
  if (*(int *)(param_1 + 0x243c) != 0) {
    uVar2 = *(int *)(param_1 + 0x243c) + 1U >> 1;
    puVar6 = (uint *)(**(code **)(param_1 + 0x2758))(param_1,uVar2 * 2 + 2);
    *(uint **)(FUN_00002748 + param_1 + 4) = puVar6;
    puVar8 = puVar6 + 1;
    uVar3 = (uVar2 - 1) * 0x10000;
    *puVar6 = uVar3 | 0x854;
    if (uVar2 != 0) {
      iVar11 = 0;
      uVar12 = uVar2;
      do {
        iVar4 = iVar11 * 4;
        iVar11 = iVar11 + 1;
        *puVar8 = *(uint *)(iVar4 + *(int *)(param_1 + 0x2440));
        puVar8 = puVar8 + 1;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
    }
    *puVar8 = uVar3 | 0x878;
    if (uVar2 != 0) {
      iVar11 = 0;
      uVar3 = uVar2;
      do {
        *(undefined4 *)((int)puVar8 + iVar11 + 4) =
             *(undefined4 *)(iVar11 + *(int *)(param_1 + 0x2444));
        iVar11 = iVar11 + 4;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
    *(uint *)(FUN_00002748 + param_1 + 4) = uVar2 * 8 + *(int *)(FUN_00002748 + param_1 + 4) + 8;
                    
                    
    (*UNRECOVERED_JUMPTABLE)(param_1);
    return;
  }
  return;
}

/* FUN_000b57a0 @ 0xb57a0 (688 bytes) */
int FUN_000b57a0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  
  if (*(int *)(param_2 + 0x14) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x569c);
  *(undefined4 **)(param_2 + 0x14) = puVar4;
  puVar4[2] = 0;
  iVar5 = 0xe;
  *puVar4 = *(undefined4 *)(param_2 + 0xc);
  puVar4[1] = *(undefined4 *)(param_2 + 4);
  puVar4[3] = *(undefined4 *)(param_1 + 0x2454);
  puVar4[4] = *(undefined4 *)(param_1 + 0x2454);
  uVar1 = *(uint *)(param_1 + 0x44);
  puVar4[8] = 1;
  puVar4[7] = 1;
  puVar4[6] = uVar1 >> 7 & 1;
  if (*(char *)(param_1 + 0x1869) != '\0') {
    puVar7 = puVar4 + 9;
    iVar5 = FUN_000c8e50(param_1,puVar4,puVar7);
    if (iVar5 == 0) {
      iVar5 = puVar4[0x150b];
      *(undefined1 *)((int)puVar4 + 0x5497) = 0;
      iVar9 = puVar4[0x1009];
      *(char *)((int)puVar4 + 0x5495) = (char)iVar5;
      uVar1 = (iVar9 + -1) * 0x100000 & 0x3ff00000U | puVar4[0x1523] & 0xc00ffc00;
      puVar4[0x1523] = uVar1;
      if (*(int *)(((unsigned char *)0x00001240) + param_2) < (int)puVar4[0x1590]) {
        *(undefined4 *)(((unsigned char *)0x00001240) + param_2) = puVar4[0x1590];
        uVar1 = puVar4[0x1523];
        iVar9 = puVar4[0x1009];
        iVar5 = puVar4[0x150b];
      }
      uVar3 = 0;
      iVar8 = iVar9;
      if (iVar9 != 0) {
        do {
          uVar3 = puVar7[iVar8 * 4 + -4] & 0xf00;
          if (((uVar3 == 0x200) || (uVar3 == 0x300)) && ((puVar7[iVar8 * 4 + -4] & 0xfe000) == 0)) {
            uVar3 = iVar8 - 1;
          }
          else {
            uVar3 = 0;
          }
        } while ((iVar8 + -1 != 0) && (iVar8 = iVar8 + -1, uVar3 == 0));
        uVar3 = uVar3 & 0xffff;
      }
      uVar6 = 0;
      puVar4[0x1523] = (uVar3 & 0x3ff) << 10 | uVar1 & 0xfff003ff;
      if (iVar9 != 0) {
        puVar7 = puVar7 + iVar9 * 4;
        do {
          if ((((puVar7[-3] & 7) == 1) || ((puVar7[-2] & 7) == 1)) || ((puVar7[-1] & 7) == 1)) {
            uVar6 = iVar9 - 1;
          }
          else {
            uVar6 = 0;
          }
          iVar9 = iVar9 + -1;
        } while ((iVar9 != 0) && (puVar7 = puVar7 + -4, uVar6 == 0));
      }
      *(int *)(((unsigned char *)0x00001038) + param_2) = iVar5;
      if (0 < iVar5) {
        pcVar10 = (char *)(puVar4 + 0x100e);
        puVar7 = puVar4 + 0x100a;
        iVar8 = 0;
        iVar9 = param_2;
        do {
          if (*pcVar10 != '\0') {
            iVar2 = *(int *)(((unsigned char *)0x00001240) + param_2);
            *(undefined4 *)(iVar9 + 0x18) = *puVar7;
            *(undefined4 *)(iVar9 + 0x1c) = puVar7[1];
            *(undefined4 *)(iVar9 + 0x20) = puVar7[2];
            *(undefined4 *)(iVar9 + 0x24) = puVar7[3];
            if (iVar2 < iVar8) {
              *(int *)(((unsigned char *)0x00001240) + param_2) = iVar8;
            }
          }
          iVar8 = iVar8 + 1;
          pcVar10 = pcVar10 + 0x14;
          puVar7 = puVar7 + 5;
          iVar9 = iVar9 + 0x10;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      iVar5 = 0;
      puVar4[0x1524] = uVar6 & 0x3ff | puVar4[0x1524] & 0xfffffc00;
      *(undefined1 *)(param_2 + 1) = 1;
    }
  }
  return iVar5;
}

/* FUN_000b5a60 @ 0xb5a60 (244 bytes) */
int FUN_000b5a60(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = *(int *)(param_2 + 0x14);
  iVar7 = *(int *)(((unsigned char *)0x00005428) + iVar6);
  if (*(int *)(((unsigned char *)0x00001240) + param_2) + 1 < *(int *)(((unsigned char *)0x00005428) + iVar6)) {
    iVar7 = *(int *)(((unsigned char *)0x00001240) + param_2) + 1;
  }
  iVar2 = iVar7 * 4;
  if (iVar2 != 0) {
    puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar2 + 5);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
    *puVar4 = 0x8a1;
    puVar4[1] = 0;
    puVar4[2] = 0x880;
    bVar1 = ((unsigned char *)0x00005497)[iVar6];
    iVar5 = *(int *)(param_1 + 0x2448);
    puVar4[4] = (iVar2 + -1) * 0x10000 | 0x8882;
    puVar4[3] = (uint)bVar1 + iVar5;
    _memcpy(puVar4 + 5,(void *)(param_2 + 0x18),iVar7 * 0x10);
    pcVar3 = *(code **)(param_1 + 0x275c);
    iVar7 = iVar7 * 0x10 + *(int *)(FUN_00002748 + param_1 + 4) + 0x14;
    *(int *)(FUN_00002748 + param_1 + 4) = iVar7;
    (*pcVar3)(param_1,iVar7);
  }
  ((unsigned char *)0x00005495)[iVar6] = (char)*(undefined4 *)(((unsigned char *)0x00001038) + param_2);
  return;
}

/* FUN_000b5ba0 @ 0xb5ba0 (36 bytes) */
int FUN_000b5ba0()
{
  ((int (*)())FUN_000b5400)();
  return 0;
}

/* FUN_000b5fb0 @ 0xb5fb0 (100 bytes) */
int FUN_000b5fb0(param_1)
  int param_1;
{
  code *pcVar1;
  int iVar2;
  
  iVar2 = param_1;
  do {
    if (*(int *)(((unsigned char *)0x00001448) + iVar2) != 0) {
      pcVar1 = *(code **)(((unsigned char *)0x00001224) + param_1);
      *(undefined4 *)(((unsigned char *)0x00001448) + iVar2) = 0;
      (*pcVar1)(param_1);
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 != param_1 + 0x10);
  return;
}

/* FUN_000b6020 @ 0xb6020 (1360 bytes) */
int FUN_000b6020(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  code *pcVar8;
  uint *puVar9;
  uint uVar10;
  
  iVar7 = param_3 * 4 + param_1;
  if (*(int *)(((unsigned char *)0x00001448) + iVar7) == 0) {
    pcVar8 = *(code **)(param_1 + 0x10);
    uVar3 = (**(code **)(((unsigned char *)0x00001284) + param_1))();
    iVar4 = (*pcVar8)(1,uVar3);
    puVar9 = (uint *)(iVar4 + 4);
    *(int *)(((unsigned char *)0x00001448) + iVar7) = iVar4;
    *(undefined4 *)(iVar4 + 4) = 0;
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *(undefined4 *)(iVar4 + 8) = 0;
    pvVar5 = (void *)(**(code **)(param_1 + 0xc))(0x200);
    if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
      _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*(int *)(iVar4 + 4) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
    }
    *(void **)(iVar4 + 0xc) = pvVar5;
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
    *(undefined4 *)(*(int *)(iVar4 + 4) * 4 + (int)pvVar5) = 1;
    uVar2 = *(int *)(iVar4 + 4) + 1;
    *(uint *)(iVar4 + 4) = uVar2;
    if (*(uint *)(iVar4 + 8) <= uVar2) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
      if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
        _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*(int *)(iVar4 + 4) << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
      }
      *(void **)(iVar4 + 0xc) = pvVar5;
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
    }
    *(undefined4 *)(*puVar9 * 4 + *(int *)(iVar4 + 0xc)) = 0x10200;
    uVar2 = *puVar9 + 1;
    *puVar9 = uVar2;
    if (*(uint *)(iVar4 + 8) <= uVar2) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
      if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
        _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
      }
      *(void **)(iVar4 + 0xc) = pvVar5;
      uVar2 = *puVar9;
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
    }
    *(undefined4 *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = 0x1ff0016;
    uVar2 = *puVar9 + 1;
    *puVar9 = uVar2;
    if (*(uint *)(iVar4 + 8) <= uVar2) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
      if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
        _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
      }
      *(void **)(iVar4 + 0xc) = pvVar5;
      uVar2 = *puVar9;
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
    }
    *(undefined4 *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = 0x120000;
    uVar2 = *puVar9 + 1;
    *puVar9 = uVar2;
    if (param_2 == 0) {
      uVar3 = 0x47;
    }
    else {
      uVar3 = 0xe;
    }
    uVar10 = 0;
    uVar6 = 0x170000;
    do {
      if ((param_3 & 1 << (uVar10 & 0x3f)) != 0) {
        uVar6 = uVar10 & 0xffff | uVar6 & 0xffff0000;
        if (*(uint *)(iVar4 + 8) <= uVar2) {
          pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
          if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
            _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
          }
          *(void **)(iVar4 + 0xc) = pvVar5;
          uVar2 = *puVar9;
          *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
        }
        *(undefined4 *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = uVar3;
        uVar2 = *puVar9 + 1;
        *puVar9 = uVar2;
        if (*(uint *)(iVar4 + 8) <= uVar2) {
          pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
          if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
            _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
          }
          *(void **)(iVar4 + 0xc) = pvVar5;
          uVar2 = *puVar9;
          *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
        }
        *(uint *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = uVar6;
        uVar2 = *puVar9 + 1;
        *puVar9 = uVar2;
        if (*(uint *)(iVar4 + 8) <= uVar2) {
          pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
          if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
            _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
          }
          *(void **)(iVar4 + 0xc) = pvVar5;
          uVar2 = *puVar9;
          *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
        }
        *(undefined4 *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = 0x120000;
        uVar2 = *puVar9 + 1;
        *puVar9 = uVar2;
      }
      bVar1 = uVar10 != 3;
      uVar10 = uVar10 + 1;
    } while (bVar1);
    if (*(uint *)(iVar4 + 8) <= uVar2) {
      pvVar5 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 8) * 4 + 0x200);
      if (*(void **)(iVar4 + 0xc) != (void *)0x0) {
        _memcpy(pvVar5,*(void **)(iVar4 + 0xc),*puVar9 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
      }
      *(void **)(iVar4 + 0xc) = pvVar5;
      uVar2 = *puVar9;
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x80;
    }
    *(undefined4 *)(uVar2 * 4 + *(int *)(iVar4 + 0xc)) = 0x28;
    *puVar9 = *puVar9 + 1;
                    
                    
    (**(code **)(((unsigned char *)0x00001288) + param_1))(param_1,0,iVar4,puVar9);
    return;
  }
  return;
}

