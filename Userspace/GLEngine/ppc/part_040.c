#include "decls.h"

/* _gleInterpolEyeAllFlatw @ 0xb9c7c (640 bytes) */
void _gleInterpolEyeAllFlatw(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
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
  uint uVar11;
  float fVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  
  fVar12 = param_2[0xb];
  fVar2 = *(float *)(param_3 + 0x2c);
  fVar3 = param_2[9];
  fVar4 = param_2[10];
  uVar13 = 0;
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_3 + 0x28);
  fVar7 = param_2[4];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar1 = (fparam_1 * (*(float *)(param_3 + 0x1c) - param_2[7]) + param_2[7]);
  param_4[8] = (fparam_1 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8]);
  param_4[0xb] = (fparam_1 * (fVar2 - fVar12) + fVar12);
  fVar2 = param_2[5];
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = param_2[6];
  fVar12 = (fparam_1 * (fVar8 - fVar7) + fVar7);
  fVar7 = *(float *)(param_3 + 0x18);
  fVar8 = -fVar1;
  param_4[9] = (fparam_1 * (fVar5 - fVar3) + fVar3);
  param_4[10] = (fparam_1 * (fVar6 - fVar4) + fVar4);
  param_4[4] = fVar12;
  fVar2 = (fparam_1 * (fVar9 - fVar2) + fVar2);
  param_4[7] = fVar1;
  fVar3 = (fparam_1 * (fVar7 - fVar10) + fVar10);
  param_4[5] = fVar2;
  param_4[6] = fVar3;
  if (fVar12 < fVar8) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar12) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar2 < fVar8) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar2) {
    uVar13 = uVar13 | 8;
  }
  if (fVar3 < fVar8) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar3) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar12 = fVar12 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar12 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar2 + *(float *)(param_1 + 0x1b84);
    fVar12 = *(float *)(param_1 + 0x1b78);
    fVar2 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar12 * fVar3 + fVar2;
  }
  uVar14 = 0;
  fVar1 = param_2[0x13];
  fVar12 = *(float *)(param_3 + 0x4c);
  param_4[0x17] =
       (fparam_1 * (*(float *)(param_3 + 0x5c) - param_2[0x17]) + param_2[0x17]);
  param_4[0x13] =
       (fparam_1 * (fVar12 - fVar1) + fVar1);
  uVar13 = *(uint *)(param_1 + 0x5150);
  do {
    uVar11 = uVar13 >> (uVar14 & 0x3f);
    if ((uVar11 & 1) == 0) {
      if (uVar11 == 0) {
        if (param_2 == param_4) {
          return;
        }
        *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
        *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
        *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
        param_4[0x12] = param_2[0x12];
        *(undefined8 *)(param_4 + 0x14) = *(undefined8 *)(param_2 + 0x14);
        fVar1 = param_2[0x16];
        param_4[0x1d] = param_2[0x1d];
        fVar12 = param_2[0x1e];
        param_4[0x16] = fVar1;
        param_4[0x1e] = fVar12;
        return;
      }
    }
    else {
      iVar15 = uVar14 * 0x10 + param_3;
      fVar1 = param_2[uVar14 * 4 + 0x23];
      fVar12 = param_2[uVar14 * 4 + 0x21];
      fVar2 = param_2[uVar14 * 4 + 0x22];
      fVar3 = *(float *)(iVar15 + 0x8c);
      fVar4 = *(float *)(iVar15 + 0x84);
      fVar5 = *(float *)(iVar15 + 0x88);
      param_4[uVar14 * 4 + 0x20] =
           (fparam_1 * (*(float *)(iVar15 + 0x80) - param_2[uVar14 * 4 + 0x20]) + param_2[uVar14 * 4 + 0x20]);
      param_4[uVar14 * 4 + 0x21] =
           (fparam_1 * (fVar4 - fVar12) + fVar12);
      param_4[uVar14 * 4 + 0x22] =
           (fparam_1 * (fVar5 - fVar2) + fVar2);
      param_4[uVar14 * 4 + 0x23] =
           (fparam_1 * (fVar3 - fVar1) + fVar1);
    }
    uVar14 = uVar14 + 1;
  } while( true );
}

/* _gleInterpolEyeAllSmooth @ 0xb9efc (892 bytes) */
void _gleInterpolEyeAllSmooth(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
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
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  float dVar27;
  
  fVar3 = param_2[0xb];
  fVar4 = *(float *)(param_3 + 0x2c);
  fVar5 = param_2[9];
  fVar6 = param_2[10];
  fVar7 = *(float *)(param_3 + 0x24);
  fVar8 = *(float *)(param_3 + 0x28);
  uVar17 = 0;
  fVar9 = param_2[4];
  fVar10 = *(float *)(param_3 + 0x10);
  fVar1 = (fparam_1 * (*(float *)(param_3 + 0x1c) - param_2[7]) + param_2[7]);
  param_4[8] = (fparam_1 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8]);
  param_4[0xb] = (fparam_1 * (fVar4 - fVar3) + fVar3);
  fVar4 = param_2[5];
  fVar11 = *(float *)(param_3 + 0x14);
  fVar12 = param_2[6];
  fVar3 = (fparam_1 * (fVar10 - fVar9) + fVar9);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = -fVar1;
  param_4[9] = (fparam_1 * (fVar7 - fVar5) + fVar5);
  param_4[10] = (fparam_1 * (fVar8 - fVar6) + fVar6);
  param_4[4] = fVar3;
  fVar4 = (fparam_1 * (fVar11 - fVar4) + fVar4);
  param_4[7] = fVar1;
  fVar5 = (fparam_1 * (fVar9 - fVar12) + fVar12);
  cVar2 = *(char *)((int)param_2 + 0x7f);
  param_4[5] = fVar4;
  param_4[6] = fVar5;
  if (fVar3 < fVar10) {
    uVar17 = 0x10;
  }
  if (fVar1 <= fVar3) {
    uVar17 = uVar17 | 0x20;
  }
  if (fVar4 < fVar10) {
    uVar17 = uVar17 | 4;
  }
  if (fVar1 <= fVar4) {
    uVar17 = uVar17 | 8;
  }
  if (fVar5 < fVar10) {
    uVar17 = uVar17 | 1;
  }
  if (fVar1 < fVar5) {
    uVar17 = uVar17 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar17 | 0x10000)));
  if (uVar17 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar3 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar4 + *(float *)(param_1 + 0x1b84);
    fVar3 = *(float *)(param_1 + 0x1b78);
    fVar4 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar5 + fVar4;
  }
  fVar1 = param_2[0x13];
  uVar18 = 0;
  fVar3 = *(float *)(param_3 + 0x4c);
  fVar4 = param_2[0xc];
  fVar5 = *(float *)(param_3 + 0x30);
  fVar6 = param_2[0xf];
  fVar7 = param_2[0xe];
  fVar8 = param_2[0xd];
  fVar9 = *(float *)(param_3 + 0x3c);
  param_4[0x17] =
       (fparam_1 * (*(float *)(param_3 + 0x5c) - param_2[0x17]) + param_2[0x17]);
  param_4[0x13] = (fparam_1 * (fVar3 - fVar1) + fVar1)
  ;
  fVar1 = *(float *)(param_3 + 0x34);
  fVar3 = *(float *)(param_3 + 0x38);
  fVar10 = param_2[0x14];
  fVar11 = *(float *)(param_3 + 0x50);
  param_4[0xc] = (fparam_1 * (fVar5 - fVar4) + fVar4);
  fVar4 = param_2[0x15];
  fVar5 = *(float *)(param_3 + 0x54);
  fVar12 = param_2[0x16];
  fVar13 = *(float *)(param_3 + 0x58);
  param_4[0xd] = (fparam_1 * (fVar1 - fVar8) + fVar8);
  param_4[0xe] = (fparam_1 * (fVar3 - fVar7) + fVar7);
  param_4[0xf] = (fparam_1 * (fVar9 - fVar6) + fVar6);
  param_4[0x14] =
       (fparam_1 * (fVar11 - fVar10) + fVar10);
  param_4[0x15] = (fparam_1 * (fVar5 - fVar4) + fVar4)
  ;
  param_4[0x16] =
       (fparam_1 * (fVar13 - fVar12) + fVar12);
  uVar16 = *(uint *)(param_1 + 0x5150);
  do {
    uVar14 = uVar16 >> (uVar18 & 0x3f);
    if ((uVar14 & 1) == 0) {
      if (uVar14 == 0) {
        fVar1 = param_2[0x10];
        fVar3 = param_2[0x11];
        fVar4 = *(float *)(param_3 + 0x40);
        fVar5 = *(float *)(param_3 + 0x44);
        param_4[0x12] =
             (fparam_1 * (*(float *)(param_3 + 0x48) - param_2[0x12]) + param_2[0x12]);
        param_4[0x10] =
             (fparam_1 * (fVar4 - fVar1) + fVar1);
        param_4[0x11] =
             (fparam_1 * (fVar5 - fVar3) + fVar3);
        if (param_2 != param_4) {
          param_4[0x1d] = param_2[0x1d];
          param_4[0x1e] = param_2[0x1e];
        }
        return;
      }
    }
    else {
      dVar27 = (double)param_2[uVar18 * 4 + 0x23];
      dVar21 = (double)param_2[uVar18 * 4 + 0x20];
      dVar23 = (double)param_2[uVar18 * 4 + 0x21];
      dVar22 = (double)param_2[uVar18 * 4 + 0x22];
      if (cVar2 == '\0') {
        dVar19 = (double)param_2[7];
        dVar27 = (double)(dVar27 * dVar19);
        dVar21 = (double)(dVar21 * dVar19);
        dVar23 = (double)(dVar23 * dVar19);
        dVar22 = (double)(dVar22 * dVar19);
      }
      iVar15 = uVar18 * 0x10 + param_3;
      dVar24 = (double)*(float *)(iVar15 + 0x8c);
      dVar25 = (double)*(float *)(iVar15 + 0x80);
      dVar19 = (double)*(float *)(iVar15 + 0x84);
      dVar26 = (double)*(float *)(iVar15 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        dVar20 = (double)*(float *)(param_3 + 0x1c);
        dVar24 = (double)(dVar24 * dVar20);
        dVar25 = (double)(dVar25 * dVar20);
        dVar19 = (double)(dVar19 * dVar20);
        dVar26 = (double)(dVar26 * dVar20);
      }
      fVar1 = (fparam_1 * (dVar25 - dVar21) + dVar21);
      fVar3 = (fparam_1 * (dVar19 - dVar23) + dVar23);
      fVar4 = (fparam_1 * (dVar26 - dVar22) + dVar22);
      fVar5 = (fparam_1 * (dVar24 - dVar27) + dVar27);
      if (uVar17 == 0) {
        fVar6 = param_4[3];
        fVar5 = fVar5 * fVar6;
        fVar1 = fVar1 * fVar6;
        fVar3 = fVar3 * fVar6;
        fVar4 = fVar4 * fVar6;
      }
      param_4[uVar18 * 4 + 0x23] = fVar5;
      param_4[uVar18 * 4 + 0x20] = fVar1;
      param_4[uVar18 * 4 + 0x21] = fVar3;
      param_4[uVar18 * 4 + 0x22] = fVar4;
    }
    uVar18 = uVar18 + 1;
  } while( true );
}

/* _gleInterpolEyeAllSmoothw @ 0xba278 (804 bytes) */
void _gleInterpolEyeAllSmoothw(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
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
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  
  fVar2 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[9];
  fVar5 = param_2[10];
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  uVar14 = 0;
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (fparam_1 * (*(float *)(param_3 + 0x1c) - param_2[7]) + param_2[7]);
  param_4[8] = (fparam_1 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8]);
  param_4[0xb] = (fparam_1 * (fVar3 - fVar2) + fVar2);
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar2 = (fparam_1 * (fVar9 - fVar8) + fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (fparam_1 * (fVar6 - fVar4) + fVar4);
  param_4[10] = (fparam_1 * (fVar7 - fVar5) + fVar5);
  param_4[4] = fVar2;
  fVar3 = (fparam_1 * (fVar10 - fVar3) + fVar3);
  param_4[7] = fVar1;
  fVar4 = (fparam_1 * (fVar8 - fVar11) + fVar11);
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar9) {
    uVar14 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar14 = uVar14 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar14 = uVar14 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar14 = uVar14 | 8;
  }
  if (fVar4 < fVar9) {
    uVar14 = uVar14 | 1;
  }
  if (fVar1 < fVar4) {
    uVar14 = uVar14 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar14 | 0x10000)));
  if (uVar14 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b78);
    fVar3 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar2 * fVar4 + fVar3;
  }
  uVar15 = 0;
  fVar1 = param_2[0x13];
  fVar2 = *(float *)(param_3 + 0x4c);
  fVar3 = param_2[0xc];
  fVar4 = *(float *)(param_3 + 0x30);
  fVar5 = param_2[0xf];
  fVar6 = param_2[0xe];
  fVar7 = param_2[0xd];
  fVar8 = *(float *)(param_3 + 0x3c);
  param_4[0x17] =
       (fparam_1 * (*(float *)(param_3 + 0x5c) - param_2[0x17]) + param_2[0x17]);
  param_4[0x13] = (fparam_1 * (fVar2 - fVar1) + fVar1)
  ;
  fVar1 = *(float *)(param_3 + 0x34);
  fVar2 = *(float *)(param_3 + 0x38);
  fVar9 = param_2[0x14];
  fVar10 = *(float *)(param_3 + 0x50);
  param_4[0xc] = (fparam_1 * (fVar4 - fVar3) + fVar3);
  fVar3 = param_2[0x15];
  fVar4 = *(float *)(param_3 + 0x54);
  fVar11 = param_2[0x16];
  fVar12 = *(float *)(param_3 + 0x58);
  param_4[0xd] = (fparam_1 * (fVar1 - fVar7) + fVar7);
  param_4[0xe] = (fparam_1 * (fVar2 - fVar6) + fVar6);
  param_4[0xf] = (fparam_1 * (fVar8 - fVar5) + fVar5);
  param_4[0x14] =
       (fparam_1 * (fVar10 - fVar9) + fVar9);
  param_4[0x15] = (fparam_1 * (fVar4 - fVar3) + fVar3)
  ;
  param_4[0x16] =
       (fparam_1 * (fVar12 - fVar11) + fVar11);
  uVar14 = *(uint *)(param_1 + 0x5150);
  do {
    uVar13 = uVar14 >> (uVar15 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        fVar1 = param_2[0x10];
        fVar2 = param_2[0x11];
        fVar3 = *(float *)(param_3 + 0x40);
        fVar4 = *(float *)(param_3 + 0x44);
        param_4[0x12] =
             (fparam_1 * (*(float *)(param_3 + 0x48) - param_2[0x12]) + param_2[0x12]);
        param_4[0x10] =
             (fparam_1 * (fVar3 - fVar1) + fVar1);
        param_4[0x11] =
             (fparam_1 * (fVar4 - fVar2) + fVar2);
        if (param_2 != param_4) {
          param_4[0x1d] = param_2[0x1d];
          param_4[0x1e] = param_2[0x1e];
        }
        return;
      }
    }
    else {
      iVar16 = uVar15 * 0x10 + param_3;
      fVar1 = param_2[uVar15 * 4 + 0x23];
      fVar2 = param_2[uVar15 * 4 + 0x21];
      fVar3 = param_2[uVar15 * 4 + 0x22];
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar5 = *(float *)(iVar16 + 0x84);
      fVar6 = *(float *)(iVar16 + 0x88);
      param_4[uVar15 * 4 + 0x20] =
           (fparam_1 * (*(float *)(iVar16 + 0x80) - param_2[uVar15 * 4 + 0x20]) + param_2[uVar15 * 4 + 0x20]);
      param_4[uVar15 * 4 + 0x21] =
           (fparam_1 * (fVar5 - fVar2) + fVar2);
      param_4[uVar15 * 4 + 0x22] =
           (fparam_1 * (fVar6 - fVar3) + fVar3);
      param_4[uVar15 * 4 + 0x23] =
           (fparam_1 * (fVar4 - fVar1) + fVar1);
    }
    uVar15 = uVar15 + 1;
  } while( true );
}

/* _gleInterpolClipNO0000 @ 0xba59c (732 bytes) */
uint _gleInterpolClipNO0000(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  
  fVar4 = *(float *)(param_3 + 0x1c);
  fVar11 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar10 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar4 + fVar10));
      fVar4 = fVar10 * (fVar4 - fVar7) + fVar7;
      fVar6 = -fVar4;
      if (FLOAT_00108e50 <= fVar4) {
        uVar12 = 0;
      }
      else {
        uVar12 = 2;
      }
    }
    else {
      uVar12 = 0;
      fVar10 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar4 - fVar10));
      fVar4 = fVar10 * (fVar4 - fVar7) + fVar7;
      fVar6 = fVar4;
    }
    bVar1 = uVar12 == 0;
    fVar7 = fVar10 * (fVar8 - fVar11) + fVar11;
    fVar5 = fVar10 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000ba7a0;
    fVar11 = -fVar4;
    if (fVar11 <= fVar5) {
      if (fVar5 < fVar4) goto LAB_000ba700;
      uVar12 = 8;
    }
    else {
      uVar12 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar11 = (fVar7 + fVar11) / ((fVar7 + fVar11) - (fVar4 + fVar8));
        fVar4 = fVar11 * (fVar4 - fVar7) + fVar7;
        fVar7 = -fVar4;
        uVar12 = (uint)(fVar4 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar12 = 0;
        fVar11 = (fVar7 - fVar11) / ((fVar7 - fVar11) - (fVar4 - fVar8));
        fVar7 = fVar11 * (fVar4 - fVar7) + fVar7;
        fVar4 = fVar7;
      }
      bVar1 = uVar12 == 0;
      fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      goto LAB_000ba7a0;
    }
    if (param_5 == 4) {
      fVar9 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar4 + fVar9));
      fVar4 = fVar9 * (fVar4 - fVar7) + fVar7;
      fVar5 = -fVar4;
      uVar12 = (uint)(fVar4 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar12 = 0;
      fVar9 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar4 - fVar9));
      fVar5 = fVar9 * (fVar4 - fVar7) + fVar7;
      fVar4 = fVar5;
    }
    bVar1 = uVar12 == 0;
    fVar7 = fVar9 * (fVar8 - fVar11) + fVar11;
    fVar6 = fVar9 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000ba7a0;
    fVar11 = -fVar4;
LAB_000ba700:
    if (fVar11 <= fVar7) {
      if (fVar7 < fVar4) goto LAB_000ba7a0;
      uVar12 = 0x20;
    }
    else {
      uVar12 = 0x10;
    }
  }
  bVar1 = uVar12 == 0;
LAB_000ba7a0:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar7;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar4;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar12 | 0x10000)));
  if (bVar1) {
    if (fVar4 != FLOAT_00108e54) {
      fVar4 = FLOAT_00108e54 / fVar4;
      fVar7 = fVar7 * fVar4;
      fVar5 = fVar5 * fVar4;
      fVar6 = fVar6 * fVar4;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar7 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar11 = *(float *)(param_1 + 0x1b88);
    fVar5 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar4;
    param_4[2] = fVar5 * fVar6 + fVar11;
  }
  if (param_2 != param_4) {
    *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
    *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
    *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
    *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
    fVar4 = param_2[0x12];
    param_4[0x1d] = param_2[0x1d];
    fVar11 = param_2[0x1e];
    param_4[0x12] = fVar4;
    param_4[0x1e] = fVar11;
  }
  return uVar12;
}

/* _gleInterpolClipNO0010 @ 0xba878 (752 bytes) */
uint _gleInterpolClipNO0010(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = param_2[4];
  fVar12 = param_2[5];
  fVar5 = param_2[6];
  fVar6 = param_2[7];
  fVar7 = *(float *)(param_3 + 0x10);
  fVar8 = *(float *)(param_3 + 0x14);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar11 = (fVar6 + fVar5) / ((fVar6 + fVar5) - (fVar10 + fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = -fVar6;
      if (FLOAT_00108e50 <= fVar6) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar11 = (fVar6 - fVar5) / ((fVar6 - fVar5) - (fVar10 - fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = fVar6;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar12 = fVar11 * (fVar8 - fVar12) + fVar12;
    if (!bVar1) goto LAB_000baa7c;
    fVar7 = -fVar6;
    if (fVar7 <= fVar12) {
      if (fVar12 < fVar6) goto LAB_000ba9dc;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar11 = (fVar6 + fVar4) / ((fVar6 + fVar4) - (fVar10 + fVar7));
        fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar4 = -fVar6;
        uVar13 = (uint)(fVar6 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar11 = (fVar6 - fVar4) / ((fVar6 - fVar4) - (fVar10 - fVar7));
        fVar4 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar6 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar12 = fVar11 * (fVar8 - fVar12) + fVar12;
      fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
      goto LAB_000baa7c;
    }
    if (param_5 == 4) {
      fVar11 = (fVar6 + fVar12) / ((fVar6 + fVar12) - (fVar10 + fVar8));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar12 = -fVar6;
      uVar13 = (uint)(fVar6 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar11 = (fVar6 - fVar12) / ((fVar6 - fVar12) - (fVar10 - fVar8));
      fVar12 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar6 = fVar12;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000baa7c;
    fVar7 = -fVar6;
LAB_000ba9dc:
    if (fVar7 <= fVar4) {
      if (fVar4 < fVar6) goto LAB_000baa7c;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000baa7c:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar12;
  param_4[6] = fVar5;
  param_4[7] = fVar6;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar6 != FLOAT_00108e54) {
      fVar6 = FLOAT_00108e54 / fVar6;
      fVar4 = fVar4 * fVar6;
      fVar12 = fVar12 * fVar6;
      fVar5 = fVar5 * fVar6;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar12 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar12 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar6;
    param_4[2] = fVar12 * fVar5 + fVar4;
  }
  param_4[0x13] = fVar11 * (*(float *)(param_3 + 0x4c) - param_2[0x13]) + param_2[0x13];
  if (param_2 != param_4) {
    *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
    *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
    *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
    *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
    fVar4 = param_2[0x12];
    param_4[0x1d] = param_2[0x1d];
    fVar12 = param_2[0x1e];
    param_4[0x12] = fVar4;
    param_4[0x1e] = fVar12;
  }
  return uVar13;
}

/* _gleInterpolClipNO0100 @ 0xbab68 (868 bytes) */
uint _gleInterpolClipNO0100(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = param_2[4];
  fVar12 = param_2[5];
  fVar5 = param_2[6];
  fVar6 = param_2[7];
  fVar7 = *(float *)(param_3 + 0x10);
  fVar8 = *(float *)(param_3 + 0x14);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar11 = (fVar6 + fVar5) / ((fVar6 + fVar5) - (fVar10 + fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = -fVar6;
      if (FLOAT_00108e50 <= fVar6) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar11 = (fVar6 - fVar5) / ((fVar6 - fVar5) - (fVar10 - fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = fVar6;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar12 = fVar11 * (fVar8 - fVar12) + fVar12;
    if (!bVar1) goto LAB_000bad6c;
    fVar7 = -fVar6;
    if (fVar7 <= fVar12) {
      if (fVar12 < fVar6) goto LAB_000baccc;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar11 = (fVar6 + fVar4) / ((fVar6 + fVar4) - (fVar10 + fVar7));
        fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar4 = -fVar6;
        uVar13 = (uint)(fVar6 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar11 = (fVar6 - fVar4) / ((fVar6 - fVar4) - (fVar10 - fVar7));
        fVar4 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar6 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar12 = fVar11 * (fVar8 - fVar12) + fVar12;
      fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
      goto LAB_000bad6c;
    }
    if (param_5 == 4) {
      fVar11 = (fVar6 + fVar12) / ((fVar6 + fVar12) - (fVar10 + fVar8));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar12 = -fVar6;
      uVar13 = (uint)(fVar6 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar11 = (fVar6 - fVar12) / ((fVar6 - fVar12) - (fVar10 - fVar8));
      fVar12 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar6 = fVar12;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bad6c;
    fVar7 = -fVar6;
LAB_000baccc:
    if (fVar7 <= fVar4) {
      if (fVar4 < fVar6) goto LAB_000bad6c;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000bad6c:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar12;
  param_4[6] = fVar5;
  param_4[7] = fVar6;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar6 != FLOAT_00108e54) {
      fVar6 = FLOAT_00108e54 / fVar6;
      fVar4 = fVar4 * fVar6;
      fVar12 = fVar12 * fVar6;
      fVar5 = fVar5 * fVar6;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar12 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar12 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar6;
    param_4[2] = fVar12 * fVar5 + fVar4;
  }
  fVar4 = *(float *)(param_3 + 0x80);
  fVar12 = *(float *)(param_3 + 0x84);
  fVar5 = *(float *)(param_3 + 0x88);
  fVar6 = *(float *)(param_3 + 0x8c);
  if (*(char *)(param_3 + 0x7f) == '\0') {
    fVar7 = *(float *)(param_3 + 0x1c);
    fVar6 = fVar6 * fVar7;
    fVar4 = fVar4 * fVar7;
    fVar12 = fVar12 * fVar7;
    fVar5 = fVar5 * fVar7;
  }
  fVar7 = fVar11 * (fVar4 - param_2[0x20]) + param_2[0x20];
  fVar12 = fVar11 * (fVar12 - param_2[0x21]) + param_2[0x21];
  fVar6 = fVar11 * (fVar6 - param_2[0x23]) + param_2[0x23];
  fVar4 = fVar11 * (fVar5 - param_2[0x22]) + param_2[0x22];
  if (bVar1) {
    fVar5 = param_4[3];
    fVar6 = fVar6 * fVar5;
    fVar7 = fVar7 * fVar5;
    fVar12 = fVar12 * fVar5;
    fVar4 = fVar4 * fVar5;
  }
  param_4[0x20] = fVar7;
  param_4[0x21] = fVar12;
  param_4[0x22] = fVar4;
  param_4[0x23] = fVar6;
  if (param_2 != param_4) {
    *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
    *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
    *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
    *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
    fVar4 = param_2[0x12];
    param_4[0x1d] = param_2[0x1d];
    fVar12 = param_2[0x1e];
    param_4[0x12] = fVar4;
    param_4[0x1e] = fVar12;
  }
  return uVar13;
}

/* _gleInterpolClipNO0100w @ 0xbaecc (812 bytes) */
uint _gleInterpolClipNO0100w(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = param_2[4];
  fVar12 = param_2[5];
  fVar5 = param_2[6];
  fVar6 = param_2[7];
  fVar7 = *(float *)(param_3 + 0x10);
  fVar8 = *(float *)(param_3 + 0x14);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar11 = (fVar6 + fVar5) / ((fVar6 + fVar5) - (fVar10 + fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = -fVar6;
      if (FLOAT_00108e50 <= fVar6) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar11 = (fVar6 - fVar5) / ((fVar6 - fVar5) - (fVar10 - fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = fVar6;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar12 = fVar11 * (fVar8 - fVar12) + fVar12;
    if (!bVar1) goto LAB_000bb0d0;
    fVar7 = -fVar6;
    if (fVar7 <= fVar12) {
      if (fVar12 < fVar6) goto LAB_000bb030;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar11 = (fVar6 + fVar4) / ((fVar6 + fVar4) - (fVar10 + fVar7));
        fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar4 = -fVar6;
        uVar13 = (uint)(fVar6 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar11 = (fVar6 - fVar4) / ((fVar6 - fVar4) - (fVar10 - fVar7));
        fVar4 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar6 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar12 = fVar11 * (fVar8 - fVar12) + fVar12;
      fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
      goto LAB_000bb0d0;
    }
    if (param_5 == 4) {
      fVar11 = (fVar6 + fVar12) / ((fVar6 + fVar12) - (fVar10 + fVar8));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar12 = -fVar6;
      uVar13 = (uint)(fVar6 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar11 = (fVar6 - fVar12) / ((fVar6 - fVar12) - (fVar10 - fVar8));
      fVar12 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar6 = fVar12;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bb0d0;
    fVar7 = -fVar6;
LAB_000bb030:
    if (fVar7 <= fVar4) {
      if (fVar4 < fVar6) goto LAB_000bb0d0;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000bb0d0:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar12;
  param_4[6] = fVar5;
  param_4[7] = fVar6;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar6 != FLOAT_00108e54) {
      fVar6 = FLOAT_00108e54 / fVar6;
      fVar4 = fVar4 * fVar6;
      fVar12 = fVar12 * fVar6;
      fVar5 = fVar5 * fVar6;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar12 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar12 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar6;
    param_4[2] = fVar12 * fVar5 + fVar4;
  }
  fVar4 = param_2[0x21];
  fVar12 = param_2[0x22];
  fVar5 = param_2[0x23];
  fVar6 = *(float *)(param_3 + 0x8c);
  fVar7 = *(float *)(param_3 + 0x84);
  fVar8 = *(float *)(param_3 + 0x88);
  param_4[0x20] = fVar11 * (*(float *)(param_3 + 0x80) - param_2[0x20]) + param_2[0x20];
  param_4[0x23] = fVar11 * (fVar6 - fVar5) + fVar5;
  param_4[0x21] = fVar11 * (fVar7 - fVar4) + fVar4;
  param_4[0x22] = fVar11 * (fVar8 - fVar12) + fVar12;
  if (param_2 != param_4) {
    *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
    *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
    *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
    *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
    fVar4 = param_2[0x12];
    param_4[0x1d] = param_2[0x1d];
    fVar12 = param_2[0x1e];
    param_4[0x12] = fVar4;
    param_4[0x1e] = fVar12;
  }
  return uVar13;
}

/* _gleInterpolClipNO0110 @ 0xbb1f8 (888 bytes) */
uint _gleInterpolClipNO0110(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  uint uVar14;
  
  fVar5 = param_2[4];
  fVar13 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar14 = 0;
      }
      else {
        uVar14 = 2;
      }
    }
    else {
      uVar14 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar14 == 0;
    fVar5 = fVar12 * (fVar8 - fVar5) + fVar5;
    fVar13 = fVar12 * (fVar9 - fVar13) + fVar13;
    if (!bVar1) goto LAB_000bb3fc;
    fVar8 = -fVar7;
    if (fVar8 <= fVar13) {
      if (fVar13 < fVar7) goto LAB_000bb35c;
      uVar14 = 8;
    }
    else {
      uVar14 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar5 = -fVar7;
        uVar14 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar14 = 0;
        fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar8));
        fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar5;
      }
      bVar1 = uVar14 == 0;
      fVar13 = fVar12 * (fVar9 - fVar13) + fVar13;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bb3fc;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar13) / ((fVar7 + fVar13) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar13 = -fVar7;
      uVar14 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar14 = 0;
      fVar12 = (fVar7 - fVar13) / ((fVar7 - fVar13) - (fVar11 - fVar9));
      fVar13 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar13;
    }
    bVar1 = uVar14 == 0;
    fVar5 = fVar12 * (fVar8 - fVar5) + fVar5;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bb3fc;
    fVar8 = -fVar7;
LAB_000bb35c:
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bb3fc;
      uVar14 = 0x20;
    }
    else {
      uVar14 = 0x10;
    }
  }
  bVar1 = uVar14 == 0;
LAB_000bb3fc:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar5;
  param_4[5] = fVar13;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar14 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar5 = fVar5 * fVar7;
      fVar13 = fVar13 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar5 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar13 + *(float *)(param_1 + 0x1b84);
    fVar5 = *(float *)(param_1 + 0x1b88);
    fVar13 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar7;
    param_4[2] = fVar13 * fVar6 + fVar5;
  }
  cVar4 = *(char *)(param_3 + 0x7f);
  param_4[0x13] = fVar12 * (*(float *)(param_3 + 0x4c) - param_2[0x13]) + param_2[0x13];
  fVar5 = *(float *)(param_3 + 0x80);
  fVar13 = *(float *)(param_3 + 0x84);
  fVar6 = *(float *)(param_3 + 0x88);
  fVar7 = *(float *)(param_3 + 0x8c);
  if (cVar4 == '\0') {
    fVar8 = *(float *)(param_3 + 0x1c);
    fVar7 = fVar7 * fVar8;
    fVar5 = fVar5 * fVar8;
    fVar13 = fVar13 * fVar8;
    fVar6 = fVar6 * fVar8;
  }
  fVar8 = fVar12 * (fVar5 - param_2[0x20]) + param_2[0x20];
  fVar13 = fVar12 * (fVar13 - param_2[0x21]) + param_2[0x21];
  fVar7 = fVar12 * (fVar7 - param_2[0x23]) + param_2[0x23];
  fVar5 = fVar12 * (fVar6 - param_2[0x22]) + param_2[0x22];
  if (bVar1) {
    fVar6 = param_4[3];
    fVar7 = fVar7 * fVar6;
    fVar8 = fVar8 * fVar6;
    fVar13 = fVar13 * fVar6;
    fVar5 = fVar5 * fVar6;
  }
  param_4[0x20] = fVar8;
  param_4[0x21] = fVar13;
  param_4[0x22] = fVar5;
  param_4[0x23] = fVar7;
  if (param_2 != param_4) {
    *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
    *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
    *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
    *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
    fVar5 = param_2[0x12];
    param_4[0x1d] = param_2[0x1d];
    fVar13 = param_2[0x1e];
    param_4[0x12] = fVar5;
    param_4[0x1e] = fVar13;
  }
  return uVar14;
}

/* _gleInterpolClipNO0110w @ 0xbb570 (832 bytes) */
uint _gleInterpolClipNO0110w(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = param_2[4];
  fVar12 = param_2[5];
  fVar5 = param_2[6];
  fVar6 = param_2[7];
  fVar7 = *(float *)(param_3 + 0x10);
  fVar8 = *(float *)(param_3 + 0x14);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar11 = (fVar6 + fVar5) / ((fVar6 + fVar5) - (fVar10 + fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = -fVar6;
      if (FLOAT_00108e50 <= fVar6) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar11 = (fVar6 - fVar5) / ((fVar6 - fVar5) - (fVar10 - fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = fVar6;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar12 = fVar11 * (fVar8 - fVar12) + fVar12;
    if (!bVar1) goto LAB_000bb774;
    fVar7 = -fVar6;
    if (fVar7 <= fVar12) {
      if (fVar12 < fVar6) goto LAB_000bb6d4;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar11 = (fVar6 + fVar4) / ((fVar6 + fVar4) - (fVar10 + fVar7));
        fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar4 = -fVar6;
        uVar13 = (uint)(fVar6 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar11 = (fVar6 - fVar4) / ((fVar6 - fVar4) - (fVar10 - fVar7));
        fVar4 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar6 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar12 = fVar11 * (fVar8 - fVar12) + fVar12;
      fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
      goto LAB_000bb774;
    }
    if (param_5 == 4) {
      fVar11 = (fVar6 + fVar12) / ((fVar6 + fVar12) - (fVar10 + fVar8));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar12 = -fVar6;
      uVar13 = (uint)(fVar6 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar11 = (fVar6 - fVar12) / ((fVar6 - fVar12) - (fVar10 - fVar8));
      fVar12 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar6 = fVar12;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bb774;
    fVar7 = -fVar6;
LAB_000bb6d4:
    if (fVar7 <= fVar4) {
      if (fVar4 < fVar6) goto LAB_000bb774;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000bb774:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar12;
  param_4[6] = fVar5;
  param_4[7] = fVar6;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar6 != FLOAT_00108e54) {
      fVar6 = FLOAT_00108e54 / fVar6;
      fVar4 = fVar4 * fVar6;
      fVar12 = fVar12 * fVar6;
      fVar5 = fVar5 * fVar6;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar12 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar12 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar6;
    param_4[2] = fVar12 * fVar5 + fVar4;
  }
  param_4[0x13] = fVar11 * (*(float *)(param_3 + 0x4c) - param_2[0x13]) + param_2[0x13];
  fVar4 = param_2[0x21];
  fVar12 = param_2[0x22];
  fVar5 = param_2[0x23];
  fVar6 = *(float *)(param_3 + 0x8c);
  fVar7 = *(float *)(param_3 + 0x84);
  fVar8 = *(float *)(param_3 + 0x88);
  param_4[0x20] = fVar11 * (*(float *)(param_3 + 0x80) - param_2[0x20]) + param_2[0x20];
  param_4[0x21] = fVar11 * (fVar7 - fVar4) + fVar4;
  param_4[0x23] = fVar11 * (fVar6 - fVar5) + fVar5;
  param_4[0x22] = fVar11 * (fVar8 - fVar12) + fVar12;
  if (param_2 != param_4) {
    *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
    *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
    *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
    *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
    fVar4 = param_2[0x12];
    param_4[0x1d] = param_2[0x1d];
    fVar12 = param_2[0x1e];
    param_4[0x12] = fVar4;
    param_4[0x1e] = fVar12;
  }
  return uVar13;
}

/* _gleInterpolClipNO0200 @ 0xbb8b0 (924 bytes) */
uint _gleInterpolClipNO0200(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  float fVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  
  fVar4 = param_2[4];
  fVar13 = param_2[5];
  fVar5 = param_2[6];
  fVar6 = param_2[7];
  fVar7 = *(float *)(param_3 + 0x10);
  fVar8 = *(float *)(param_3 + 0x14);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar11 = (fVar6 + fVar5) / ((fVar6 + fVar5) - (fVar10 + fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = -fVar6;
      if (FLOAT_00108e50 <= fVar6) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar5) / ((fVar6 - fVar5) - (fVar10 - fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = fVar6;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
    if (!bVar1) goto LAB_000bbab4;
    fVar7 = -fVar6;
    if (fVar7 <= fVar13) {
      if (fVar13 < fVar6) goto LAB_000bba14;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar11 = (fVar6 + fVar4) / ((fVar6 + fVar4) - (fVar10 + fVar7));
        fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar4 = -fVar6;
        uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar11 = (fVar6 - fVar4) / ((fVar6 - fVar4) - (fVar10 - fVar7));
        fVar4 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar6 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
      fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
      goto LAB_000bbab4;
    }
    if (param_5 == 4) {
      fVar11 = (fVar6 + fVar13) / ((fVar6 + fVar13) - (fVar10 + fVar8));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar13 = -fVar6;
      uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar13) / ((fVar6 - fVar13) - (fVar10 - fVar8));
      fVar13 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar6 = fVar13;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bbab4;
    fVar7 = -fVar6;
LAB_000bba14:
    if (fVar7 <= fVar4) {
      if (fVar4 < fVar6) goto LAB_000bbab4;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000bbab4:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar13;
  param_4[6] = fVar5;
  param_4[7] = fVar6;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar6 != FLOAT_00108e54) {
      fVar6 = FLOAT_00108e54 / fVar6;
      fVar4 = fVar4 * fVar6;
      fVar13 = fVar13 * fVar6;
      fVar5 = fVar5 * fVar6;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar13 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar13 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar6;
    param_4[2] = fVar4 * fVar5 + fVar13;
  }
  uVar14 = *(uint *)(param_1 + 0x5150);
  uVar17 = 0;
  do {
    uVar12 = uVar14 >> (uVar17 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (param_2 != param_4) {
          *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
          *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
          *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
          *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
          *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
          fVar4 = param_2[0x12];
          param_4[0x1d] = param_2[0x1d];
          fVar13 = param_2[0x1e];
          param_4[0x12] = fVar4;
          param_4[0x1e] = fVar13;
        }
        return uVar15;
      }
    }
    else {
      iVar16 = uVar17 * 0x10 + param_3;
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar13 = *(float *)(iVar16 + 0x80);
      fVar5 = *(float *)(iVar16 + 0x84);
      fVar6 = *(float *)(iVar16 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        fVar7 = *(float *)(param_3 + 0x1c);
        fVar4 = fVar4 * fVar7;
        fVar13 = fVar13 * fVar7;
        fVar5 = fVar5 * fVar7;
        fVar6 = fVar6 * fVar7;
      }
      fVar7 = fVar11 * (fVar13 - param_2[uVar17 * 4 + 0x20]) + param_2[uVar17 * 4 + 0x20];
      fVar5 = fVar11 * (fVar5 - param_2[uVar17 * 4 + 0x21]) + param_2[uVar17 * 4 + 0x21];
      fVar13 = fVar11 * (fVar6 - param_2[uVar17 * 4 + 0x22]) + param_2[uVar17 * 4 + 0x22];
      fVar4 = fVar11 * (fVar4 - param_2[uVar17 * 4 + 0x23]) + param_2[uVar17 * 4 + 0x23];
      if (bVar1) {
        fVar6 = param_4[3];
        fVar4 = fVar4 * fVar6;
        fVar7 = fVar7 * fVar6;
        fVar5 = fVar5 * fVar6;
        fVar13 = fVar13 * fVar6;
      }
      param_4[uVar17 * 4 + 0x23] = fVar4;
      param_4[uVar17 * 4 + 0x20] = fVar7;
      param_4[uVar17 * 4 + 0x21] = fVar5;
      param_4[uVar17 * 4 + 0x22] = fVar13;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolClipNO0200w @ 0xbbc4c (868 bytes) */
uint _gleInterpolClipNO0200w(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  float fVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  
  fVar4 = param_2[4];
  fVar13 = param_2[5];
  fVar5 = param_2[6];
  fVar6 = param_2[7];
  fVar7 = *(float *)(param_3 + 0x10);
  fVar8 = *(float *)(param_3 + 0x14);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar11 = (fVar6 + fVar5) / ((fVar6 + fVar5) - (fVar10 + fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = -fVar6;
      if (FLOAT_00108e50 <= fVar6) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar5) / ((fVar6 - fVar5) - (fVar10 - fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = fVar6;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
    if (!bVar1) goto LAB_000bbe50;
    fVar7 = -fVar6;
    if (fVar7 <= fVar13) {
      if (fVar13 < fVar6) goto LAB_000bbdb0;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar11 = (fVar6 + fVar4) / ((fVar6 + fVar4) - (fVar10 + fVar7));
        fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar4 = -fVar6;
        uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar11 = (fVar6 - fVar4) / ((fVar6 - fVar4) - (fVar10 - fVar7));
        fVar4 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar6 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
      fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
      goto LAB_000bbe50;
    }
    if (param_5 == 4) {
      fVar11 = (fVar6 + fVar13) / ((fVar6 + fVar13) - (fVar10 + fVar8));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar13 = -fVar6;
      uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar13) / ((fVar6 - fVar13) - (fVar10 - fVar8));
      fVar13 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar6 = fVar13;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bbe50;
    fVar7 = -fVar6;
LAB_000bbdb0:
    if (fVar7 <= fVar4) {
      if (fVar4 < fVar6) goto LAB_000bbe50;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000bbe50:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar13;
  param_4[6] = fVar5;
  param_4[7] = fVar6;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar6 != FLOAT_00108e54) {
      fVar6 = FLOAT_00108e54 / fVar6;
      fVar4 = fVar4 * fVar6;
      fVar13 = fVar13 * fVar6;
      fVar5 = fVar5 * fVar6;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar13 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar13 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar6;
    param_4[2] = fVar4 * fVar5 + fVar13;
  }
  uVar14 = *(uint *)(param_1 + 0x5150);
  uVar16 = 0;
  do {
    uVar12 = uVar14 >> (uVar16 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (param_2 != param_4) {
          *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
          *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
          *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
          *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
          *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
          fVar4 = param_2[0x12];
          param_4[0x1d] = param_2[0x1d];
          fVar13 = param_2[0x1e];
          param_4[0x12] = fVar4;
          param_4[0x1e] = fVar13;
        }
        return uVar15;
      }
    }
    else {
      iVar17 = uVar16 * 0x10 + param_3;
      fVar4 = param_2[uVar16 * 4 + 0x23];
      fVar13 = param_2[uVar16 * 4 + 0x21];
      fVar5 = param_2[uVar16 * 4 + 0x22];
      fVar6 = *(float *)(iVar17 + 0x8c);
      fVar7 = *(float *)(iVar17 + 0x84);
      fVar8 = *(float *)(iVar17 + 0x88);
      param_4[uVar16 * 4 + 0x20] =
           fVar11 * (*(float *)(iVar17 + 0x80) - param_2[uVar16 * 4 + 0x20]) +
           param_2[uVar16 * 4 + 0x20];
      param_4[uVar16 * 4 + 0x21] = fVar11 * (fVar7 - fVar13) + fVar13;
      param_4[uVar16 * 4 + 0x22] = fVar11 * (fVar8 - fVar5) + fVar5;
      param_4[uVar16 * 4 + 0x23] = fVar11 * (fVar6 - fVar4) + fVar4;
    }
    uVar16 = uVar16 + 1;
  } while( true );
}

/* _gleInterpolClipNO0210 @ 0xbbfb0 (944 bytes) */
uint _gleInterpolClipNO0210(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  float fVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  
  fVar4 = param_2[4];
  fVar13 = param_2[5];
  fVar5 = param_2[6];
  fVar6 = param_2[7];
  fVar7 = *(float *)(param_3 + 0x10);
  fVar8 = *(float *)(param_3 + 0x14);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar11 = (fVar6 + fVar5) / ((fVar6 + fVar5) - (fVar10 + fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = -fVar6;
      if (FLOAT_00108e50 <= fVar6) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar5) / ((fVar6 - fVar5) - (fVar10 - fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = fVar6;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
    if (!bVar1) goto LAB_000bc1b4;
    fVar7 = -fVar6;
    if (fVar7 <= fVar13) {
      if (fVar13 < fVar6) goto LAB_000bc114;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar11 = (fVar6 + fVar4) / ((fVar6 + fVar4) - (fVar10 + fVar7));
        fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar4 = -fVar6;
        uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar11 = (fVar6 - fVar4) / ((fVar6 - fVar4) - (fVar10 - fVar7));
        fVar4 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar6 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
      fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
      goto LAB_000bc1b4;
    }
    if (param_5 == 4) {
      fVar11 = (fVar6 + fVar13) / ((fVar6 + fVar13) - (fVar10 + fVar8));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar13 = -fVar6;
      uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar13) / ((fVar6 - fVar13) - (fVar10 - fVar8));
      fVar13 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar6 = fVar13;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bc1b4;
    fVar7 = -fVar6;
LAB_000bc114:
    if (fVar7 <= fVar4) {
      if (fVar4 < fVar6) goto LAB_000bc1b4;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000bc1b4:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar13;
  param_4[6] = fVar5;
  param_4[7] = fVar6;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar6 != FLOAT_00108e54) {
      fVar6 = FLOAT_00108e54 / fVar6;
      fVar4 = fVar4 * fVar6;
      fVar13 = fVar13 * fVar6;
      fVar5 = fVar5 * fVar6;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar13 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar13 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar6;
    param_4[2] = fVar4 * fVar5 + fVar13;
  }
  uVar17 = 0;
  param_4[0x13] = fVar11 * (*(float *)(param_3 + 0x4c) - param_2[0x13]) + param_2[0x13];
  uVar14 = *(uint *)(param_1 + 0x5150);
  do {
    uVar12 = uVar14 >> (uVar17 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (param_2 != param_4) {
          *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
          *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
          *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
          *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
          *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
          fVar4 = param_2[0x12];
          param_4[0x1d] = param_2[0x1d];
          fVar13 = param_2[0x1e];
          param_4[0x12] = fVar4;
          param_4[0x1e] = fVar13;
        }
        return uVar15;
      }
    }
    else {
      iVar16 = uVar17 * 0x10 + param_3;
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar13 = *(float *)(iVar16 + 0x80);
      fVar5 = *(float *)(iVar16 + 0x84);
      fVar6 = *(float *)(iVar16 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        fVar7 = *(float *)(param_3 + 0x1c);
        fVar4 = fVar4 * fVar7;
        fVar13 = fVar13 * fVar7;
        fVar5 = fVar5 * fVar7;
        fVar6 = fVar6 * fVar7;
      }
      fVar7 = fVar11 * (fVar13 - param_2[uVar17 * 4 + 0x20]) + param_2[uVar17 * 4 + 0x20];
      fVar5 = fVar11 * (fVar5 - param_2[uVar17 * 4 + 0x21]) + param_2[uVar17 * 4 + 0x21];
      fVar13 = fVar11 * (fVar6 - param_2[uVar17 * 4 + 0x22]) + param_2[uVar17 * 4 + 0x22];
      fVar4 = fVar11 * (fVar4 - param_2[uVar17 * 4 + 0x23]) + param_2[uVar17 * 4 + 0x23];
      if (bVar1) {
        fVar6 = param_4[3];
        fVar4 = fVar4 * fVar6;
        fVar7 = fVar7 * fVar6;
        fVar5 = fVar5 * fVar6;
        fVar13 = fVar13 * fVar6;
      }
      param_4[uVar17 * 4 + 0x23] = fVar4;
      param_4[uVar17 * 4 + 0x20] = fVar7;
      param_4[uVar17 * 4 + 0x21] = fVar5;
      param_4[uVar17 * 4 + 0x22] = fVar13;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolClipNO0210w @ 0xbc360 (888 bytes) */
uint _gleInterpolClipNO0210w(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  float fVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  
  fVar4 = param_2[4];
  fVar13 = param_2[5];
  fVar5 = param_2[6];
  fVar6 = param_2[7];
  fVar7 = *(float *)(param_3 + 0x10);
  fVar8 = *(float *)(param_3 + 0x14);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar11 = (fVar6 + fVar5) / ((fVar6 + fVar5) - (fVar10 + fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = -fVar6;
      if (FLOAT_00108e50 <= fVar6) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar5) / ((fVar6 - fVar5) - (fVar10 - fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = fVar6;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
    if (!bVar1) goto LAB_000bc564;
    fVar7 = -fVar6;
    if (fVar7 <= fVar13) {
      if (fVar13 < fVar6) goto LAB_000bc4c4;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar11 = (fVar6 + fVar4) / ((fVar6 + fVar4) - (fVar10 + fVar7));
        fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar4 = -fVar6;
        uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar11 = (fVar6 - fVar4) / ((fVar6 - fVar4) - (fVar10 - fVar7));
        fVar4 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar6 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
      fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
      goto LAB_000bc564;
    }
    if (param_5 == 4) {
      fVar11 = (fVar6 + fVar13) / ((fVar6 + fVar13) - (fVar10 + fVar8));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar13 = -fVar6;
      uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar13) / ((fVar6 - fVar13) - (fVar10 - fVar8));
      fVar13 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar6 = fVar13;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bc564;
    fVar7 = -fVar6;
LAB_000bc4c4:
    if (fVar7 <= fVar4) {
      if (fVar4 < fVar6) goto LAB_000bc564;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000bc564:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar13;
  param_4[6] = fVar5;
  param_4[7] = fVar6;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar6 != FLOAT_00108e54) {
      fVar6 = FLOAT_00108e54 / fVar6;
      fVar4 = fVar4 * fVar6;
      fVar13 = fVar13 * fVar6;
      fVar5 = fVar5 * fVar6;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar13 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar13 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar6;
    param_4[2] = fVar4 * fVar5 + fVar13;
  }
  uVar16 = 0;
  param_4[0x13] = fVar11 * (*(float *)(param_3 + 0x4c) - param_2[0x13]) + param_2[0x13];
  uVar14 = *(uint *)(param_1 + 0x5150);
  do {
    uVar12 = uVar14 >> (uVar16 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (param_2 != param_4) {
          *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
          *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
          *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
          *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
          *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
          fVar4 = param_2[0x12];
          param_4[0x1d] = param_2[0x1d];
          fVar13 = param_2[0x1e];
          param_4[0x12] = fVar4;
          param_4[0x1e] = fVar13;
        }
        return uVar15;
      }
    }
    else {
      iVar17 = uVar16 * 0x10 + param_3;
      fVar4 = param_2[uVar16 * 4 + 0x23];
      fVar13 = param_2[uVar16 * 4 + 0x21];
      fVar5 = param_2[uVar16 * 4 + 0x22];
      fVar6 = *(float *)(iVar17 + 0x8c);
      fVar7 = *(float *)(iVar17 + 0x84);
      fVar8 = *(float *)(iVar17 + 0x88);
      param_4[uVar16 * 4 + 0x20] =
           fVar11 * (*(float *)(iVar17 + 0x80) - param_2[uVar16 * 4 + 0x20]) +
           param_2[uVar16 * 4 + 0x20];
      param_4[uVar16 * 4 + 0x21] = fVar11 * (fVar7 - fVar13) + fVar13;
      param_4[uVar16 * 4 + 0x22] = fVar11 * (fVar8 - fVar5) + fVar5;
      param_4[uVar16 * 4 + 0x23] = fVar11 * (fVar6 - fVar4) + fVar4;
    }
    uVar16 = uVar16 + 1;
  } while( true );
}

/* _gleInterpolClipNO1000 @ 0xbc6d8 (740 bytes) */
uint _gleInterpolClipNO1000(int param_1,int param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = *(float *)(param_2 + 0x10);
  fVar5 = *(float *)(param_2 + 0x14);
  fVar6 = *(float *)(param_2 + 0x18);
  fVar7 = *(float *)(param_2 + 0x1c);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bc8dc;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bc83c;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bc8dc;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bc8dc;
    fVar8 = -fVar7;
LAB_000bc83c:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bc8dc;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000bc8dc:
  bVar2 = *(byte *)(param_2 + 0x7c);
  bVar3 = *(byte *)(param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar5 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar7;
    param_4[2] = fVar5 * fVar6 + fVar4;
  }
  fVar4 = *(float *)(param_2 + 0x3c);
  fVar5 = *(float *)(param_2 + 0x34);
  fVar6 = *(float *)(param_2 + 0x38);
  fVar7 = *(float *)(param_3 + 0x3c);
  fVar8 = *(float *)(param_3 + 0x34);
  fVar9 = *(float *)(param_3 + 0x38);
  param_4[0xc] = fVar12 * (*(float *)(param_3 + 0x30) - *(float *)(param_2 + 0x30)) +
                 *(float *)(param_2 + 0x30);
  param_4[0xf] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0xd] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0xe] = fVar12 * (fVar9 - fVar6) + fVar6;
  return uVar13;
}

/* _gleInterpolClipNO1001 @ 0xbc9bc (824 bytes) */
uint _gleInterpolClipNO1001(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bcbc0;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bcb20;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bcbc0;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bcbc0;
    fVar8 = -fVar7;
LAB_000bcb20:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bcbc0;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000bcbc0:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar5 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar7;
    param_4[2] = fVar5 * fVar6 + fVar4;
  }
  fVar4 = param_2[0x11];
  fVar5 = param_2[0x12];
  fVar6 = *(float *)(param_3 + 0x44);
  fVar7 = *(float *)(param_3 + 0x48);
  param_4[0x10] = fVar12 * (*(float *)(param_3 + 0x40) - param_2[0x10]) + param_2[0x10];
  param_4[0x11] = fVar12 * (fVar6 - fVar4) + fVar4;
  param_4[0x12] = fVar12 * (fVar7 - fVar5) + fVar5;
  if (param_2 != param_4) {
    param_4[0x1d] = param_2[0x1d];
    param_4[0x1e] = param_2[0x1e];
  }
  fVar4 = param_2[0xb];
  fVar5 = param_2[9];
  fVar6 = param_2[10];
  fVar7 = *(float *)(param_3 + 0x2c);
  fVar8 = *(float *)(param_3 + 0x24);
  fVar9 = *(float *)(param_3 + 0x28);
  param_4[8] = fVar12 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
  param_4[0xb] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[9] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[10] = fVar12 * (fVar9 - fVar6) + fVar6;
  return uVar13;
}

/* _gleInterpolClipNO1010 @ 0xbccf4 (760 bytes) */
uint _gleInterpolClipNO1010(int param_1,int param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = *(float *)(param_2 + 0x10);
  fVar5 = *(float *)(param_2 + 0x14);
  fVar6 = *(float *)(param_2 + 0x18);
  fVar7 = *(float *)(param_2 + 0x1c);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bcef8;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bce58;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bcef8;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bcef8;
    fVar8 = -fVar7;
LAB_000bce58:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bcef8;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000bcef8:
  bVar2 = *(byte *)(param_2 + 0x7c);
  bVar3 = *(byte *)(param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar5 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar7;
    param_4[2] = fVar5 * fVar6 + fVar4;
  }
  fVar4 = *(float *)(param_2 + 0x3c);
  fVar5 = *(float *)(param_2 + 0x30);
  fVar6 = *(float *)(param_2 + 0x34);
  fVar7 = *(float *)(param_3 + 0x3c);
  fVar8 = *(float *)(param_3 + 0x30);
  fVar9 = *(float *)(param_2 + 0x38);
  fVar10 = *(float *)(param_3 + 0x34);
  param_4[0x13] =
       fVar12 * (*(float *)(param_3 + 0x4c) - *(float *)(param_2 + 0x4c)) +
       *(float *)(param_2 + 0x4c);
  fVar11 = *(float *)(param_3 + 0x38);
  param_4[0xc] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0xf] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0xd] = fVar12 * (fVar10 - fVar6) + fVar6;
  param_4[0xe] = fVar12 * (fVar11 - fVar9) + fVar9;
  return uVar13;
}

/* _gleInterpolClipNO1011 @ 0xbcfec (844 bytes) */
uint _gleInterpolClipNO1011(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bd1f0;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bd150;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bd1f0;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bd1f0;
    fVar8 = -fVar7;
LAB_000bd150:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bd1f0;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000bd1f0:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar5 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar7;
    param_4[2] = fVar5 * fVar6 + fVar4;
  }
  fVar4 = param_2[0x10];
  fVar5 = param_2[0x11];
  fVar6 = *(float *)(param_3 + 0x40);
  fVar7 = *(float *)(param_3 + 0x44);
  fVar8 = param_2[0x12];
  param_4[0x13] = fVar12 * (*(float *)(param_3 + 0x4c) - param_2[0x13]) + param_2[0x13];
  fVar9 = *(float *)(param_3 + 0x48);
  param_4[0x10] = fVar12 * (fVar6 - fVar4) + fVar4;
  param_4[0x11] = fVar12 * (fVar7 - fVar5) + fVar5;
  param_4[0x12] = fVar12 * (fVar9 - fVar8) + fVar8;
  if (param_2 != param_4) {
    param_4[0x1d] = param_2[0x1d];
    param_4[0x1e] = param_2[0x1e];
  }
  fVar4 = param_2[0xb];
  fVar5 = param_2[9];
  fVar6 = param_2[10];
  fVar7 = *(float *)(param_3 + 0x2c);
  fVar8 = *(float *)(param_3 + 0x24);
  fVar9 = *(float *)(param_3 + 0x28);
  param_4[8] = fVar12 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
  param_4[0xb] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[9] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[10] = fVar12 * (fVar9 - fVar6) + fVar6;
  return uVar13;
}

/* _gleInterpolClipNO1100 @ 0xbd338 (876 bytes) */
uint _gleInterpolClipNO1100(int param_1,int param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  uint uVar14;
  
  fVar5 = *(float *)(param_2 + 0x10);
  fVar6 = *(float *)(param_2 + 0x14);
  fVar7 = *(float *)(param_2 + 0x18);
  fVar8 = *(float *)(param_2 + 0x1c);
  fVar9 = *(float *)(param_3 + 0x10);
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = *(float *)(param_3 + 0x18);
  fVar12 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar13 = (fVar8 + fVar7) / ((fVar8 + fVar7) - (fVar12 + fVar11));
      fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar7 = -fVar8;
      if (FLOAT_00108e50 <= fVar8) {
        uVar14 = 0;
      }
      else {
        uVar14 = 2;
      }
    }
    else {
      uVar14 = 0;
      fVar13 = (fVar8 - fVar7) / ((fVar8 - fVar7) - (fVar12 - fVar11));
      fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar7 = fVar8;
    }
    bVar1 = uVar14 == 0;
    fVar5 = fVar13 * (fVar9 - fVar5) + fVar5;
    fVar6 = fVar13 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bd53c;
    fVar9 = -fVar8;
    if (fVar9 <= fVar6) {
      if (fVar6 < fVar8) goto LAB_000bd49c;
      uVar14 = 8;
    }
    else {
      uVar14 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar13 = (fVar8 + fVar5) / ((fVar8 + fVar5) - (fVar12 + fVar9));
        fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
        fVar5 = -fVar8;
        uVar14 = (uint)(fVar8 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar14 = 0;
        fVar13 = (fVar8 - fVar5) / ((fVar8 - fVar5) - (fVar12 - fVar9));
        fVar5 = fVar13 * (fVar12 - fVar8) + fVar8;
        fVar8 = fVar5;
      }
      bVar1 = uVar14 == 0;
      fVar6 = fVar13 * (fVar10 - fVar6) + fVar6;
      fVar7 = fVar13 * (fVar11 - fVar7) + fVar7;
      goto LAB_000bd53c;
    }
    if (param_5 == 4) {
      fVar13 = (fVar8 + fVar6) / ((fVar8 + fVar6) - (fVar12 + fVar10));
      fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar6 = -fVar8;
      uVar14 = (uint)(fVar8 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar14 = 0;
      fVar13 = (fVar8 - fVar6) / ((fVar8 - fVar6) - (fVar12 - fVar10));
      fVar6 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar8 = fVar6;
    }
    bVar1 = uVar14 == 0;
    fVar5 = fVar13 * (fVar9 - fVar5) + fVar5;
    fVar7 = fVar13 * (fVar11 - fVar7) + fVar7;
    if (!bVar1) goto LAB_000bd53c;
    fVar9 = -fVar8;
LAB_000bd49c:
    if (fVar9 <= fVar5) {
      if (fVar5 < fVar8) goto LAB_000bd53c;
      uVar14 = 0x20;
    }
    else {
      uVar14 = 0x10;
    }
  }
  bVar1 = uVar14 == 0;
LAB_000bd53c:
  bVar2 = *(byte *)(param_2 + 0x7c);
  bVar3 = *(byte *)(param_2 + 0x7e);
  param_4[4] = fVar5;
  param_4[5] = fVar6;
  param_4[6] = fVar7;
  param_4[7] = fVar8;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar14 | 0x10000)));
  if (bVar1) {
    if (fVar8 != FLOAT_00108e54) {
      fVar8 = FLOAT_00108e54 / fVar8;
      fVar5 = fVar5 * fVar8;
      fVar6 = fVar6 * fVar8;
      fVar7 = fVar7 * fVar8;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar5 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar6 + *(float *)(param_1 + 0x1b84);
    fVar5 = *(float *)(param_1 + 0x1b88);
    fVar6 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar8;
    param_4[2] = fVar6 * fVar7 + fVar5;
  }
  fVar5 = *(float *)(param_2 + 0x34);
  fVar6 = *(float *)(param_2 + 0x38);
  fVar7 = *(float *)(param_2 + 0x3c);
  fVar8 = *(float *)(param_3 + 0x34);
  fVar9 = *(float *)(param_3 + 0x38);
  fVar10 = *(float *)(param_3 + 0x3c);
  cVar4 = *(char *)(param_3 + 0x7f);
  param_4[0xc] = fVar13 * (*(float *)(param_3 + 0x30) - *(float *)(param_2 + 0x30)) +
                 *(float *)(param_2 + 0x30);
  param_4[0xe] = fVar13 * (fVar9 - fVar6) + fVar6;
  param_4[0xd] = fVar13 * (fVar8 - fVar5) + fVar5;
  param_4[0xf] = fVar13 * (fVar10 - fVar7) + fVar7;
  fVar5 = *(float *)(param_3 + 0x80);
  fVar6 = *(float *)(param_3 + 0x84);
  fVar7 = *(float *)(param_3 + 0x88);
  fVar8 = *(float *)(param_3 + 0x8c);
  if (cVar4 == '\0') {
    fVar9 = *(float *)(param_3 + 0x1c);
    fVar8 = fVar8 * fVar9;
    fVar5 = fVar5 * fVar9;
    fVar6 = fVar6 * fVar9;
    fVar7 = fVar7 * fVar9;
  }
  fVar9 = fVar13 * (fVar5 - *(float *)(param_2 + 0x80)) + *(float *)(param_2 + 0x80);
  fVar6 = fVar13 * (fVar6 - *(float *)(param_2 + 0x84)) + *(float *)(param_2 + 0x84);
  fVar8 = fVar13 * (fVar8 - *(float *)(param_2 + 0x8c)) + *(float *)(param_2 + 0x8c);
  fVar5 = fVar13 * (fVar7 - *(float *)(param_2 + 0x88)) + *(float *)(param_2 + 0x88);
  if (bVar1) {
    fVar7 = param_4[3];
    fVar8 = fVar8 * fVar7;
    fVar9 = fVar9 * fVar7;
    fVar6 = fVar6 * fVar7;
    fVar5 = fVar5 * fVar7;
  }
  param_4[0x23] = fVar8;
  param_4[0x20] = fVar9;
  param_4[0x21] = fVar6;
  param_4[0x22] = fVar5;
  return uVar14;
}

/* _gleInterpolClipNO1100w @ 0xbd6a4 (820 bytes) */
uint _gleInterpolClipNO1100w(int param_1,int param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = *(float *)(param_2 + 0x10);
  fVar5 = *(float *)(param_2 + 0x14);
  fVar6 = *(float *)(param_2 + 0x18);
  fVar7 = *(float *)(param_2 + 0x1c);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bd8a8;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bd808;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bd8a8;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bd8a8;
    fVar8 = -fVar7;
LAB_000bd808:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bd8a8;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000bd8a8:
  bVar2 = *(byte *)(param_2 + 0x7c);
  bVar3 = *(byte *)(param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar5 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar7;
    param_4[2] = fVar5 * fVar6 + fVar4;
  }
  fVar4 = *(float *)(param_2 + 0x34);
  fVar5 = *(float *)(param_2 + 0x38);
  fVar6 = *(float *)(param_2 + 0x3c);
  fVar7 = *(float *)(param_3 + 0x34);
  fVar8 = *(float *)(param_3 + 0x38);
  fVar9 = *(float *)(param_3 + 0x3c);
  param_4[0xc] = fVar12 * (*(float *)(param_3 + 0x30) - *(float *)(param_2 + 0x30)) +
                 *(float *)(param_2 + 0x30);
  param_4[0xd] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0xe] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0xf] = fVar12 * (fVar9 - fVar6) + fVar6;
  fVar4 = *(float *)(param_2 + 0x8c);
  fVar5 = *(float *)(param_2 + 0x84);
  fVar6 = *(float *)(param_2 + 0x88);
  fVar7 = *(float *)(param_3 + 0x8c);
  fVar8 = *(float *)(param_3 + 0x84);
  fVar9 = *(float *)(param_3 + 0x88);
  param_4[0x20] =
       fVar12 * (*(float *)(param_3 + 0x80) - *(float *)(param_2 + 0x80)) +
       *(float *)(param_2 + 0x80);
  param_4[0x21] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0x23] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0x22] = fVar12 * (fVar9 - fVar6) + fVar6;
  return uVar13;
}

/* _gleInterpolClipNO1101 @ 0xbd9d8 (960 bytes) */
uint _gleInterpolClipNO1101(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bdbdc;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bdb3c;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bdbdc;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bdbdc;
    fVar8 = -fVar7;
LAB_000bdb3c:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bdbdc;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000bdbdc:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar5 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar7;
    param_4[2] = fVar5 * fVar6 + fVar4;
  }
  fVar4 = *(float *)(param_3 + 0x80);
  fVar5 = *(float *)(param_3 + 0x84);
  fVar6 = *(float *)(param_3 + 0x88);
  fVar7 = *(float *)(param_3 + 0x8c);
  if (*(char *)(param_3 + 0x7f) == '\0') {
    fVar8 = *(float *)(param_3 + 0x1c);
    fVar7 = fVar7 * fVar8;
    fVar4 = fVar4 * fVar8;
    fVar5 = fVar5 * fVar8;
    fVar6 = fVar6 * fVar8;
  }
  fVar9 = fVar12 * (fVar4 - param_2[0x20]) + param_2[0x20];
  fVar8 = fVar12 * (fVar5 - param_2[0x21]) + param_2[0x21];
  fVar5 = fVar12 * (fVar6 - param_2[0x22]) + param_2[0x22];
  fVar4 = fVar12 * (fVar7 - param_2[0x23]) + param_2[0x23];
  if (bVar1) {
    fVar6 = param_4[3];
    fVar4 = fVar4 * fVar6;
    fVar9 = fVar9 * fVar6;
    fVar8 = fVar8 * fVar6;
    fVar5 = fVar5 * fVar6;
  }
  param_4[0x20] = fVar9;
  param_4[0x21] = fVar8;
  param_4[0x22] = fVar5;
  param_4[0x23] = fVar4;
  fVar4 = param_2[0x11];
  fVar5 = param_2[0x12];
  fVar6 = *(float *)(param_3 + 0x44);
  fVar7 = *(float *)(param_3 + 0x48);
  param_4[0x10] = fVar12 * (*(float *)(param_3 + 0x40) - param_2[0x10]) + param_2[0x10];
  param_4[0x11] = fVar12 * (fVar6 - fVar4) + fVar4;
  param_4[0x12] = fVar12 * (fVar7 - fVar5) + fVar5;
  if (param_2 != param_4) {
    param_4[0x1d] = param_2[0x1d];
    param_4[0x1e] = param_2[0x1e];
  }
  fVar4 = param_2[0xb];
  fVar5 = param_2[9];
  fVar6 = param_2[10];
  fVar7 = *(float *)(param_3 + 0x2c);
  fVar8 = *(float *)(param_3 + 0x24);
  fVar9 = *(float *)(param_3 + 0x28);
  param_4[8] = fVar12 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
  param_4[9] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0xb] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[10] = fVar12 * (fVar9 - fVar6) + fVar6;
  return uVar13;
}

/* _gleInterpolClipNO1101w @ 0xbdd98 (904 bytes) */
uint _gleInterpolClipNO1101w(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bdf9c;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bdefc;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bdf9c;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bdf9c;
    fVar8 = -fVar7;
LAB_000bdefc:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bdf9c;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000bdf9c:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar5 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar7;
    param_4[2] = fVar5 * fVar6 + fVar4;
  }
  fVar4 = param_2[0x21];
  fVar5 = param_2[0x22];
  fVar6 = param_2[0x23];
  fVar7 = *(float *)(param_3 + 0x84);
  fVar8 = *(float *)(param_3 + 0x88);
  fVar9 = *(float *)(param_3 + 0x8c);
  param_4[0x20] = fVar12 * (*(float *)(param_3 + 0x80) - param_2[0x20]) + param_2[0x20];
  param_4[0x21] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0x22] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0x23] = fVar12 * (fVar9 - fVar6) + fVar6;
  fVar4 = param_2[0x11];
  fVar5 = param_2[0x12];
  fVar6 = *(float *)(param_3 + 0x44);
  fVar7 = *(float *)(param_3 + 0x48);
  param_4[0x10] = fVar12 * (*(float *)(param_3 + 0x40) - param_2[0x10]) + param_2[0x10];
  param_4[0x11] = fVar12 * (fVar6 - fVar4) + fVar4;
  param_4[0x12] = fVar12 * (fVar7 - fVar5) + fVar5;
  if (param_2 != param_4) {
    param_4[0x1d] = param_2[0x1d];
    param_4[0x1e] = param_2[0x1e];
  }
  fVar4 = param_2[0xb];
  fVar5 = param_2[9];
  fVar6 = param_2[10];
  fVar7 = *(float *)(param_3 + 0x2c);
  fVar8 = *(float *)(param_3 + 0x24);
  fVar9 = *(float *)(param_3 + 0x28);
  param_4[8] = fVar12 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
  param_4[0xb] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[9] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[10] = fVar12 * (fVar9 - fVar6) + fVar6;
  return uVar13;
}

/* _gleInterpolClipNO1110 @ 0xbe120 (896 bytes) */
uint _gleInterpolClipNO1110(int param_1,int param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  uint uVar14;
  
  fVar5 = *(float *)(param_2 + 0x10);
  fVar6 = *(float *)(param_2 + 0x14);
  fVar7 = *(float *)(param_2 + 0x18);
  fVar8 = *(float *)(param_2 + 0x1c);
  fVar9 = *(float *)(param_3 + 0x10);
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = *(float *)(param_3 + 0x18);
  fVar12 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar13 = (fVar8 + fVar7) / ((fVar8 + fVar7) - (fVar12 + fVar11));
      fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar7 = -fVar8;
      if (FLOAT_00108e50 <= fVar8) {
        uVar14 = 0;
      }
      else {
        uVar14 = 2;
      }
    }
    else {
      uVar14 = 0;
      fVar13 = (fVar8 - fVar7) / ((fVar8 - fVar7) - (fVar12 - fVar11));
      fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar7 = fVar8;
    }
    bVar1 = uVar14 == 0;
    fVar5 = fVar13 * (fVar9 - fVar5) + fVar5;
    fVar6 = fVar13 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000be324;
    fVar9 = -fVar8;
    if (fVar9 <= fVar6) {
      if (fVar6 < fVar8) goto LAB_000be284;
      uVar14 = 8;
    }
    else {
      uVar14 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar13 = (fVar8 + fVar5) / ((fVar8 + fVar5) - (fVar12 + fVar9));
        fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
        fVar5 = -fVar8;
        uVar14 = (uint)(fVar8 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar14 = 0;
        fVar13 = (fVar8 - fVar5) / ((fVar8 - fVar5) - (fVar12 - fVar9));
        fVar5 = fVar13 * (fVar12 - fVar8) + fVar8;
        fVar8 = fVar5;
      }
      bVar1 = uVar14 == 0;
      fVar6 = fVar13 * (fVar10 - fVar6) + fVar6;
      fVar7 = fVar13 * (fVar11 - fVar7) + fVar7;
      goto LAB_000be324;
    }
    if (param_5 == 4) {
      fVar13 = (fVar8 + fVar6) / ((fVar8 + fVar6) - (fVar12 + fVar10));
      fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar6 = -fVar8;
      uVar14 = (uint)(fVar8 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar14 = 0;
      fVar13 = (fVar8 - fVar6) / ((fVar8 - fVar6) - (fVar12 - fVar10));
      fVar6 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar8 = fVar6;
    }
    bVar1 = uVar14 == 0;
    fVar5 = fVar13 * (fVar9 - fVar5) + fVar5;
    fVar7 = fVar13 * (fVar11 - fVar7) + fVar7;
    if (!bVar1) goto LAB_000be324;
    fVar9 = -fVar8;
LAB_000be284:
    if (fVar9 <= fVar5) {
      if (fVar5 < fVar8) goto LAB_000be324;
      uVar14 = 0x20;
    }
    else {
      uVar14 = 0x10;
    }
  }
  bVar1 = uVar14 == 0;
LAB_000be324:
  bVar2 = *(byte *)(param_2 + 0x7c);
  bVar3 = *(byte *)(param_2 + 0x7e);
  param_4[4] = fVar5;
  param_4[5] = fVar6;
  param_4[6] = fVar7;
  param_4[7] = fVar8;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar14 | 0x10000)));
  if (bVar1) {
    if (fVar8 != FLOAT_00108e54) {
      fVar8 = FLOAT_00108e54 / fVar8;
      fVar5 = fVar5 * fVar8;
      fVar6 = fVar6 * fVar8;
      fVar7 = fVar7 * fVar8;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar5 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar6 + *(float *)(param_1 + 0x1b84);
    fVar5 = *(float *)(param_1 + 0x1b88);
    fVar6 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar8;
    param_4[2] = fVar6 * fVar7 + fVar5;
  }
  fVar5 = *(float *)(param_2 + 0x30);
  fVar6 = *(float *)(param_2 + 0x34);
  fVar7 = *(float *)(param_2 + 0x3c);
  fVar8 = *(float *)(param_3 + 0x30);
  fVar9 = *(float *)(param_3 + 0x34);
  fVar10 = *(float *)(param_2 + 0x38);
  fVar11 = *(float *)(param_3 + 0x3c);
  param_4[0x13] =
       fVar13 * (*(float *)(param_3 + 0x4c) - *(float *)(param_2 + 0x4c)) +
       *(float *)(param_2 + 0x4c);
  fVar12 = *(float *)(param_3 + 0x38);
  cVar4 = *(char *)(param_3 + 0x7f);
  param_4[0xc] = fVar13 * (fVar8 - fVar5) + fVar5;
  param_4[0xd] = fVar13 * (fVar9 - fVar6) + fVar6;
  param_4[0xf] = fVar13 * (fVar11 - fVar7) + fVar7;
  param_4[0xe] = fVar13 * (fVar12 - fVar10) + fVar10;
  fVar5 = *(float *)(param_3 + 0x80);
  fVar6 = *(float *)(param_3 + 0x84);
  fVar7 = *(float *)(param_3 + 0x88);
  fVar8 = *(float *)(param_3 + 0x8c);
  if (cVar4 == '\0') {
    fVar9 = *(float *)(param_3 + 0x1c);
    fVar8 = fVar8 * fVar9;
    fVar5 = fVar5 * fVar9;
    fVar6 = fVar6 * fVar9;
    fVar7 = fVar7 * fVar9;
  }
  fVar9 = fVar13 * (fVar5 - *(float *)(param_2 + 0x80)) + *(float *)(param_2 + 0x80);
  fVar6 = fVar13 * (fVar6 - *(float *)(param_2 + 0x84)) + *(float *)(param_2 + 0x84);
  fVar8 = fVar13 * (fVar8 - *(float *)(param_2 + 0x8c)) + *(float *)(param_2 + 0x8c);
  fVar5 = fVar13 * (fVar7 - *(float *)(param_2 + 0x88)) + *(float *)(param_2 + 0x88);
  if (bVar1) {
    fVar7 = param_4[3];
    fVar8 = fVar8 * fVar7;
    fVar9 = fVar9 * fVar7;
    fVar6 = fVar6 * fVar7;
    fVar5 = fVar5 * fVar7;
  }
  param_4[0x23] = fVar8;
  param_4[0x20] = fVar9;
  param_4[0x21] = fVar6;
  param_4[0x22] = fVar5;
  return uVar14;
}

/* _gleInterpolClipNO1110w @ 0xbe4a0 (840 bytes) */
uint _gleInterpolClipNO1110w(int param_1,int param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = *(float *)(param_2 + 0x10);
  fVar5 = *(float *)(param_2 + 0x14);
  fVar6 = *(float *)(param_2 + 0x18);
  fVar7 = *(float *)(param_2 + 0x1c);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000be6a4;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000be604;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000be6a4;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000be6a4;
    fVar8 = -fVar7;
LAB_000be604:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000be6a4;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000be6a4:
  bVar2 = *(byte *)(param_2 + 0x7c);
  bVar3 = *(byte *)(param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar5 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar7;
    param_4[2] = fVar5 * fVar6 + fVar4;
  }
  fVar4 = *(float *)(param_2 + 0x30);
  fVar5 = *(float *)(param_2 + 0x34);
  fVar6 = *(float *)(param_2 + 0x3c);
  fVar7 = *(float *)(param_3 + 0x30);
  fVar8 = *(float *)(param_3 + 0x34);
  fVar9 = *(float *)(param_2 + 0x38);
  fVar10 = *(float *)(param_3 + 0x3c);
  param_4[0x13] =
       fVar12 * (*(float *)(param_3 + 0x4c) - *(float *)(param_2 + 0x4c)) +
       *(float *)(param_2 + 0x4c);
  fVar11 = *(float *)(param_3 + 0x38);
  param_4[0xc] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0xd] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0xf] = fVar12 * (fVar10 - fVar6) + fVar6;
  param_4[0xe] = fVar12 * (fVar11 - fVar9) + fVar9;
  fVar4 = *(float *)(param_2 + 0x8c);
  fVar5 = *(float *)(param_2 + 0x84);
  fVar6 = *(float *)(param_2 + 0x88);
  fVar7 = *(float *)(param_3 + 0x8c);
  fVar8 = *(float *)(param_3 + 0x84);
  fVar9 = *(float *)(param_3 + 0x88);
  param_4[0x20] =
       fVar12 * (*(float *)(param_3 + 0x80) - *(float *)(param_2 + 0x80)) +
       *(float *)(param_2 + 0x80);
  param_4[0x21] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0x23] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0x22] = fVar12 * (fVar9 - fVar6) + fVar6;
  return uVar13;
}

/* _gleInterpolClipNO1111 @ 0xbe7e8 (980 bytes) */
uint _gleInterpolClipNO1111(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  uint uVar14;
  
  fVar5 = param_2[4];
  fVar6 = param_2[5];
  fVar7 = param_2[6];
  fVar8 = param_2[7];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = *(float *)(param_3 + 0x18);
  fVar12 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar13 = (fVar8 + fVar7) / ((fVar8 + fVar7) - (fVar12 + fVar11));
      fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar7 = -fVar8;
      if (FLOAT_00108e50 <= fVar8) {
        uVar14 = 0;
      }
      else {
        uVar14 = 2;
      }
    }
    else {
      uVar14 = 0;
      fVar13 = (fVar8 - fVar7) / ((fVar8 - fVar7) - (fVar12 - fVar11));
      fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar7 = fVar8;
    }
    bVar1 = uVar14 == 0;
    fVar5 = fVar13 * (fVar9 - fVar5) + fVar5;
    fVar6 = fVar13 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000be9ec;
    fVar9 = -fVar8;
    if (fVar9 <= fVar6) {
      if (fVar6 < fVar8) goto LAB_000be94c;
      uVar14 = 8;
    }
    else {
      uVar14 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar13 = (fVar8 + fVar5) / ((fVar8 + fVar5) - (fVar12 + fVar9));
        fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
        fVar5 = -fVar8;
        uVar14 = (uint)(fVar8 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar14 = 0;
        fVar13 = (fVar8 - fVar5) / ((fVar8 - fVar5) - (fVar12 - fVar9));
        fVar5 = fVar13 * (fVar12 - fVar8) + fVar8;
        fVar8 = fVar5;
      }
      bVar1 = uVar14 == 0;
      fVar6 = fVar13 * (fVar10 - fVar6) + fVar6;
      fVar7 = fVar13 * (fVar11 - fVar7) + fVar7;
      goto LAB_000be9ec;
    }
    if (param_5 == 4) {
      fVar13 = (fVar8 + fVar6) / ((fVar8 + fVar6) - (fVar12 + fVar10));
      fVar8 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar6 = -fVar8;
      uVar14 = (uint)(fVar8 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar14 = 0;
      fVar13 = (fVar8 - fVar6) / ((fVar8 - fVar6) - (fVar12 - fVar10));
      fVar6 = fVar13 * (fVar12 - fVar8) + fVar8;
      fVar8 = fVar6;
    }
    bVar1 = uVar14 == 0;
    fVar5 = fVar13 * (fVar9 - fVar5) + fVar5;
    fVar7 = fVar13 * (fVar11 - fVar7) + fVar7;
    if (!bVar1) goto LAB_000be9ec;
    fVar9 = -fVar8;
LAB_000be94c:
    if (fVar9 <= fVar5) {
      if (fVar5 < fVar8) goto LAB_000be9ec;
      uVar14 = 0x20;
    }
    else {
      uVar14 = 0x10;
    }
  }
  bVar1 = uVar14 == 0;
LAB_000be9ec:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar5;
  param_4[5] = fVar6;
  param_4[6] = fVar7;
  param_4[7] = fVar8;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar14 | 0x10000)));
  if (bVar1) {
    if (fVar8 != FLOAT_00108e54) {
      fVar8 = FLOAT_00108e54 / fVar8;
      fVar5 = fVar5 * fVar8;
      fVar6 = fVar6 * fVar8;
      fVar7 = fVar7 * fVar8;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar5 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar6 + *(float *)(param_1 + 0x1b84);
    fVar5 = *(float *)(param_1 + 0x1b88);
    fVar6 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar8;
    param_4[2] = fVar6 * fVar7 + fVar5;
  }
  cVar4 = *(char *)(param_3 + 0x7f);
  param_4[0x13] = fVar13 * (*(float *)(param_3 + 0x4c) - param_2[0x13]) + param_2[0x13];
  fVar5 = *(float *)(param_3 + 0x80);
  fVar6 = *(float *)(param_3 + 0x84);
  fVar7 = *(float *)(param_3 + 0x88);
  fVar8 = *(float *)(param_3 + 0x8c);
  if (cVar4 == '\0') {
    fVar9 = *(float *)(param_3 + 0x1c);
    fVar8 = fVar8 * fVar9;
    fVar5 = fVar5 * fVar9;
    fVar6 = fVar6 * fVar9;
    fVar7 = fVar7 * fVar9;
  }
  fVar10 = fVar13 * (fVar5 - param_2[0x20]) + param_2[0x20];
  fVar9 = fVar13 * (fVar6 - param_2[0x21]) + param_2[0x21];
  fVar6 = fVar13 * (fVar7 - param_2[0x22]) + param_2[0x22];
  fVar5 = fVar13 * (fVar8 - param_2[0x23]) + param_2[0x23];
  if (bVar1) {
    fVar7 = param_4[3];
    fVar5 = fVar5 * fVar7;
    fVar10 = fVar10 * fVar7;
    fVar9 = fVar9 * fVar7;
    fVar6 = fVar6 * fVar7;
  }
  param_4[0x20] = fVar10;
  param_4[0x21] = fVar9;
  param_4[0x22] = fVar6;
  param_4[0x23] = fVar5;
  fVar5 = param_2[0x11];
  fVar6 = param_2[0x12];
  fVar7 = *(float *)(param_3 + 0x44);
  fVar8 = *(float *)(param_3 + 0x48);
  param_4[0x10] = fVar13 * (*(float *)(param_3 + 0x40) - param_2[0x10]) + param_2[0x10];
  param_4[0x11] = fVar13 * (fVar7 - fVar5) + fVar5;
  param_4[0x12] = fVar13 * (fVar8 - fVar6) + fVar6;
  if (param_2 != param_4) {
    param_4[0x1d] = param_2[0x1d];
    param_4[0x1e] = param_2[0x1e];
  }
  fVar5 = param_2[0xb];
  fVar6 = param_2[9];
  fVar7 = param_2[10];
  fVar8 = *(float *)(param_3 + 0x2c);
  fVar9 = *(float *)(param_3 + 0x24);
  fVar10 = *(float *)(param_3 + 0x28);
  param_4[8] = fVar13 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
  param_4[9] = fVar13 * (fVar9 - fVar6) + fVar6;
  param_4[0xb] = fVar13 * (fVar8 - fVar5) + fVar5;
  param_4[10] = fVar13 * (fVar10 - fVar7) + fVar7;
  return uVar14;
}

/* _gleInterpolClipNO1111w @ 0xbebbc (924 bytes) */
uint _gleInterpolClipNO1111w(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  
  fVar4 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar13 = 0;
      }
      else {
        uVar13 = 2;
      }
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bedc0;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bed20;
      uVar13 = 8;
    }
    else {
      uVar13 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar13 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar13 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bedc0;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar13 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar13 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar13 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bedc0;
    fVar8 = -fVar7;
LAB_000bed20:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bedc0;
      uVar13 = 0x20;
    }
    else {
      uVar13 = 0x10;
    }
  }
  bVar1 = uVar13 == 0;
LAB_000bedc0:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar13 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b88);
    fVar5 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar7;
    param_4[2] = fVar5 * fVar6 + fVar4;
  }
  param_4[0x13] = fVar12 * (*(float *)(param_3 + 0x4c) - param_2[0x13]) + param_2[0x13];
  fVar4 = param_2[0x21];
  fVar5 = param_2[0x22];
  fVar6 = param_2[0x23];
  fVar7 = *(float *)(param_3 + 0x84);
  fVar8 = *(float *)(param_3 + 0x88);
  fVar9 = *(float *)(param_3 + 0x8c);
  param_4[0x20] = fVar12 * (*(float *)(param_3 + 0x80) - param_2[0x20]) + param_2[0x20];
  param_4[0x21] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0x22] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0x23] = fVar12 * (fVar9 - fVar6) + fVar6;
  fVar4 = param_2[0x11];
  fVar5 = param_2[0x12];
  fVar6 = *(float *)(param_3 + 0x44);
  fVar7 = *(float *)(param_3 + 0x48);
  param_4[0x10] = fVar12 * (*(float *)(param_3 + 0x40) - param_2[0x10]) + param_2[0x10];
  param_4[0x11] = fVar12 * (fVar6 - fVar4) + fVar4;
  param_4[0x12] = fVar12 * (fVar7 - fVar5) + fVar5;
  if (param_2 != param_4) {
    param_4[0x1d] = param_2[0x1d];
    param_4[0x1e] = param_2[0x1e];
  }
  fVar4 = param_2[0xb];
  fVar5 = param_2[9];
  fVar6 = param_2[10];
  fVar7 = *(float *)(param_3 + 0x2c);
  fVar8 = *(float *)(param_3 + 0x24);
  fVar9 = *(float *)(param_3 + 0x28);
  param_4[8] = fVar12 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
  param_4[0xb] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[9] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[10] = fVar12 * (fVar9 - fVar6) + fVar6;
  return uVar13;
}

/* _gleInterpolClipNO1200 @ 0xbef58 (932 bytes) */
uint _gleInterpolClipNO1200(int param_1,int param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  
  fVar4 = *(float *)(param_2 + 0x10);
  fVar5 = *(float *)(param_2 + 0x14);
  fVar6 = *(float *)(param_2 + 0x18);
  fVar7 = *(float *)(param_2 + 0x1c);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar16 = 0;
      }
      else {
        uVar16 = 2;
      }
    }
    else {
      uVar16 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar16 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bf15c;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bf0bc;
      uVar16 = 8;
    }
    else {
      uVar16 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar16 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar16 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar16 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bf15c;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar16 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar16 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar16 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bf15c;
    fVar8 = -fVar7;
LAB_000bf0bc:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bf15c;
      uVar16 = 0x20;
    }
    else {
      uVar16 = 0x10;
    }
  }
  bVar1 = uVar16 == 0;
LAB_000bf15c:
  bVar2 = *(byte *)(param_2 + 0x7c);
  bVar3 = *(byte *)(param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar16 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar5 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar7;
    param_4[2] = fVar4 * fVar6 + fVar5;
  }
  uVar18 = 0;
  fVar4 = *(float *)(param_2 + 0x34);
  fVar5 = *(float *)(param_2 + 0x38);
  fVar6 = *(float *)(param_2 + 0x3c);
  fVar7 = *(float *)(param_3 + 0x34);
  fVar8 = *(float *)(param_3 + 0x38);
  fVar9 = *(float *)(param_3 + 0x3c);
  param_4[0xc] = fVar12 * (*(float *)(param_3 + 0x30) - *(float *)(param_2 + 0x30)) +
                 *(float *)(param_2 + 0x30);
  param_4[0xd] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0xe] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0xf] = fVar12 * (fVar9 - fVar6) + fVar6;
  uVar15 = *(uint *)(param_1 + 0x5150);
  do {
    uVar13 = uVar15 >> (uVar18 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        return uVar16;
      }
    }
    else {
      iVar14 = uVar18 * 0x10 + param_2;
      iVar17 = uVar18 * 0x10 + param_3;
      fVar4 = *(float *)(iVar17 + 0x8c);
      fVar5 = *(float *)(iVar17 + 0x80);
      fVar6 = *(float *)(iVar17 + 0x84);
      fVar7 = *(float *)(iVar17 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        fVar8 = *(float *)(param_3 + 0x1c);
        fVar4 = fVar4 * fVar8;
        fVar5 = fVar5 * fVar8;
        fVar6 = fVar6 * fVar8;
        fVar7 = fVar7 * fVar8;
      }
      fVar8 = fVar12 * (fVar5 - *(float *)(iVar14 + 0x80)) + *(float *)(iVar14 + 0x80);
      fVar6 = fVar12 * (fVar6 - *(float *)(iVar14 + 0x84)) + *(float *)(iVar14 + 0x84);
      fVar5 = fVar12 * (fVar7 - *(float *)(iVar14 + 0x88)) + *(float *)(iVar14 + 0x88);
      fVar4 = fVar12 * (fVar4 - *(float *)(iVar14 + 0x8c)) + *(float *)(iVar14 + 0x8c);
      if (bVar1) {
        fVar7 = param_4[3];
        fVar4 = fVar4 * fVar7;
        fVar8 = fVar8 * fVar7;
        fVar6 = fVar6 * fVar7;
        fVar5 = fVar5 * fVar7;
      }
      param_4[uVar18 * 4 + 0x23] = fVar4;
      param_4[uVar18 * 4 + 0x20] = fVar8;
      param_4[uVar18 * 4 + 0x21] = fVar6;
      param_4[uVar18 * 4 + 0x22] = fVar5;
    }
    uVar18 = uVar18 + 1;
  } while( true );
}

/* _gleInterpolClipNO1200w @ 0xbf2fc (876 bytes) */
uint _gleInterpolClipNO1200w(int param_1,int param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  
  fVar4 = *(float *)(param_2 + 0x10);
  fVar5 = *(float *)(param_2 + 0x14);
  fVar6 = *(float *)(param_2 + 0x18);
  fVar7 = *(float *)(param_2 + 0x1c);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bf500;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bf460;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bf500;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bf500;
    fVar8 = -fVar7;
LAB_000bf460:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bf500;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000bf500:
  bVar2 = *(byte *)(param_2 + 0x7c);
  bVar3 = *(byte *)(param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar5 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar7;
    param_4[2] = fVar4 * fVar6 + fVar5;
  }
  uVar17 = 0;
  fVar4 = *(float *)(param_2 + 0x34);
  fVar5 = *(float *)(param_2 + 0x38);
  fVar6 = *(float *)(param_2 + 0x3c);
  fVar7 = *(float *)(param_3 + 0x34);
  fVar8 = *(float *)(param_3 + 0x38);
  fVar9 = *(float *)(param_3 + 0x3c);
  param_4[0xc] = fVar12 * (*(float *)(param_3 + 0x30) - *(float *)(param_2 + 0x30)) +
                 *(float *)(param_2 + 0x30);
  param_4[0xd] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0xe] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0xf] = fVar12 * (fVar9 - fVar6) + fVar6;
  uVar14 = *(uint *)(param_1 + 0x5150);
  do {
    uVar13 = uVar14 >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        return uVar15;
      }
    }
    else {
      iVar16 = uVar17 * 0x10 + param_2;
      iVar18 = uVar17 * 0x10 + param_3;
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar5 = *(float *)(iVar16 + 0x84);
      fVar6 = *(float *)(iVar16 + 0x88);
      fVar7 = *(float *)(iVar18 + 0x8c);
      fVar8 = *(float *)(iVar18 + 0x84);
      fVar9 = *(float *)(iVar18 + 0x88);
      param_4[uVar17 * 4 + 0x20] =
           fVar12 * (*(float *)(iVar18 + 0x80) - *(float *)(iVar16 + 0x80)) +
           *(float *)(iVar16 + 0x80);
      param_4[uVar17 * 4 + 0x21] = fVar12 * (fVar8 - fVar5) + fVar5;
      param_4[uVar17 * 4 + 0x22] = fVar12 * (fVar9 - fVar6) + fVar6;
      param_4[uVar17 * 4 + 0x23] = fVar12 * (fVar7 - fVar4) + fVar4;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolClipNO1201 @ 0xbf668 (1016 bytes) */
uint _gleInterpolClipNO1201(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  
  fVar4 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bf86c;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bf7cc;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bf86c;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bf86c;
    fVar8 = -fVar7;
LAB_000bf7cc:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bf86c;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000bf86c:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar5 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar7;
    param_4[2] = fVar4 * fVar6 + fVar5;
  }
  uVar14 = *(uint *)(param_1 + 0x5150);
  uVar17 = 0;
  do {
    uVar13 = uVar14 >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        fVar4 = param_2[0x11];
        fVar5 = param_2[0x12];
        fVar6 = *(float *)(param_3 + 0x44);
        fVar7 = *(float *)(param_3 + 0x48);
        param_4[0x10] = fVar12 * (*(float *)(param_3 + 0x40) - param_2[0x10]) + param_2[0x10];
        param_4[0x11] = fVar12 * (fVar6 - fVar4) + fVar4;
        param_4[0x12] = fVar12 * (fVar7 - fVar5) + fVar5;
        if (param_2 != param_4) {
          param_4[0x1d] = param_2[0x1d];
          param_4[0x1e] = param_2[0x1e];
        }
        fVar4 = param_2[0xb];
        fVar5 = param_2[9];
        fVar6 = param_2[10];
        fVar7 = *(float *)(param_3 + 0x2c);
        fVar8 = *(float *)(param_3 + 0x24);
        fVar9 = *(float *)(param_3 + 0x28);
        param_4[8] = fVar12 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
        param_4[9] = fVar12 * (fVar8 - fVar5) + fVar5;
        param_4[0xb] = fVar12 * (fVar7 - fVar4) + fVar4;
        param_4[10] = fVar12 * (fVar9 - fVar6) + fVar6;
        return uVar15;
      }
    }
    else {
      iVar16 = uVar17 * 0x10 + param_3;
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar5 = *(float *)(iVar16 + 0x80);
      fVar6 = *(float *)(iVar16 + 0x84);
      fVar7 = *(float *)(iVar16 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        fVar8 = *(float *)(param_3 + 0x1c);
        fVar4 = fVar4 * fVar8;
        fVar5 = fVar5 * fVar8;
        fVar6 = fVar6 * fVar8;
        fVar7 = fVar7 * fVar8;
      }
      fVar8 = fVar12 * (fVar5 - param_2[uVar17 * 4 + 0x20]) + param_2[uVar17 * 4 + 0x20];
      fVar6 = fVar12 * (fVar6 - param_2[uVar17 * 4 + 0x21]) + param_2[uVar17 * 4 + 0x21];
      fVar5 = fVar12 * (fVar7 - param_2[uVar17 * 4 + 0x22]) + param_2[uVar17 * 4 + 0x22];
      fVar4 = fVar12 * (fVar4 - param_2[uVar17 * 4 + 0x23]) + param_2[uVar17 * 4 + 0x23];
      if (bVar1) {
        fVar7 = param_4[3];
        fVar4 = fVar4 * fVar7;
        fVar8 = fVar8 * fVar7;
        fVar6 = fVar6 * fVar7;
        fVar5 = fVar5 * fVar7;
      }
      param_4[uVar17 * 4 + 0x23] = fVar4;
      param_4[uVar17 * 4 + 0x20] = fVar8;
      param_4[uVar17 * 4 + 0x21] = fVar6;
      param_4[uVar17 * 4 + 0x22] = fVar5;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolClipNO1201w @ 0xbfa60 (960 bytes) */
uint _gleInterpolClipNO1201w(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  
  fVar4 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000bfc64;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bfbc4;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000bfc64;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000bfc64;
    fVar8 = -fVar7;
LAB_000bfbc4:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000bfc64;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000bfc64:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar5 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar7;
    param_4[2] = fVar4 * fVar6 + fVar5;
  }
  uVar14 = *(uint *)(param_1 + 0x5150);
  uVar16 = 0;
  do {
    uVar13 = uVar14 >> (uVar16 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        fVar4 = param_2[0x11];
        fVar5 = param_2[0x12];
        fVar6 = *(float *)(param_3 + 0x44);
        fVar7 = *(float *)(param_3 + 0x48);
        param_4[0x10] = fVar12 * (*(float *)(param_3 + 0x40) - param_2[0x10]) + param_2[0x10];
        param_4[0x11] = fVar12 * (fVar6 - fVar4) + fVar4;
        param_4[0x12] = fVar12 * (fVar7 - fVar5) + fVar5;
        if (param_2 != param_4) {
          param_4[0x1d] = param_2[0x1d];
          param_4[0x1e] = param_2[0x1e];
        }
        fVar4 = param_2[0xb];
        fVar5 = param_2[9];
        fVar6 = param_2[10];
        fVar7 = *(float *)(param_3 + 0x2c);
        fVar8 = *(float *)(param_3 + 0x24);
        fVar9 = *(float *)(param_3 + 0x28);
        param_4[8] = fVar12 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
        param_4[0xb] = fVar12 * (fVar7 - fVar4) + fVar4;
        param_4[9] = fVar12 * (fVar8 - fVar5) + fVar5;
        param_4[10] = fVar12 * (fVar9 - fVar6) + fVar6;
        return uVar15;
      }
    }
    else {
      iVar17 = uVar16 * 0x10 + param_3;
      fVar4 = param_2[uVar16 * 4 + 0x23];
      fVar5 = param_2[uVar16 * 4 + 0x21];
      fVar6 = param_2[uVar16 * 4 + 0x22];
      fVar7 = *(float *)(iVar17 + 0x8c);
      fVar8 = *(float *)(iVar17 + 0x84);
      fVar9 = *(float *)(iVar17 + 0x88);
      param_4[uVar16 * 4 + 0x20] =
           fVar12 * (*(float *)(iVar17 + 0x80) - param_2[uVar16 * 4 + 0x20]) +
           param_2[uVar16 * 4 + 0x20];
      param_4[uVar16 * 4 + 0x21] = fVar12 * (fVar8 - fVar5) + fVar5;
      param_4[uVar16 * 4 + 0x22] = fVar12 * (fVar9 - fVar6) + fVar6;
      param_4[uVar16 * 4 + 0x23] = fVar12 * (fVar7 - fVar4) + fVar4;
    }
    uVar16 = uVar16 + 1;
  } while( true );
}

/* _gleInterpolClipNO1210 @ 0xbfe20 (952 bytes) */
uint _gleInterpolClipNO1210(int param_1,int param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  
  fVar4 = *(float *)(param_2 + 0x10);
  fVar5 = *(float *)(param_2 + 0x14);
  fVar6 = *(float *)(param_2 + 0x18);
  fVar7 = *(float *)(param_2 + 0x1c);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar16 = 0;
      }
      else {
        uVar16 = 2;
      }
    }
    else {
      uVar16 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar16 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000c0024;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000bff84;
      uVar16 = 8;
    }
    else {
      uVar16 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar16 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar16 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar16 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000c0024;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar16 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar16 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar16 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000c0024;
    fVar8 = -fVar7;
LAB_000bff84:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000c0024;
      uVar16 = 0x20;
    }
    else {
      uVar16 = 0x10;
    }
  }
  bVar1 = uVar16 == 0;
LAB_000c0024:
  bVar2 = *(byte *)(param_2 + 0x7c);
  bVar3 = *(byte *)(param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar16 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar5 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar7;
    param_4[2] = fVar4 * fVar6 + fVar5;
  }
  uVar18 = 0;
  fVar4 = *(float *)(param_2 + 0x30);
  fVar5 = *(float *)(param_2 + 0x34);
  fVar6 = *(float *)(param_2 + 0x3c);
  fVar7 = *(float *)(param_3 + 0x30);
  fVar8 = *(float *)(param_3 + 0x34);
  fVar9 = *(float *)(param_2 + 0x38);
  fVar10 = *(float *)(param_3 + 0x3c);
  param_4[0x13] =
       fVar12 * (*(float *)(param_3 + 0x4c) - *(float *)(param_2 + 0x4c)) +
       *(float *)(param_2 + 0x4c);
  fVar11 = *(float *)(param_3 + 0x38);
  param_4[0xc] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0xd] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0xf] = fVar12 * (fVar10 - fVar6) + fVar6;
  param_4[0xe] = fVar12 * (fVar11 - fVar9) + fVar9;
  uVar15 = *(uint *)(param_1 + 0x5150);
  do {
    uVar13 = uVar15 >> (uVar18 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        return uVar16;
      }
    }
    else {
      iVar14 = uVar18 * 0x10 + param_2;
      iVar17 = uVar18 * 0x10 + param_3;
      fVar4 = *(float *)(iVar17 + 0x8c);
      fVar5 = *(float *)(iVar17 + 0x80);
      fVar6 = *(float *)(iVar17 + 0x84);
      fVar7 = *(float *)(iVar17 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        fVar8 = *(float *)(param_3 + 0x1c);
        fVar4 = fVar4 * fVar8;
        fVar5 = fVar5 * fVar8;
        fVar6 = fVar6 * fVar8;
        fVar7 = fVar7 * fVar8;
      }
      fVar8 = fVar12 * (fVar5 - *(float *)(iVar14 + 0x80)) + *(float *)(iVar14 + 0x80);
      fVar6 = fVar12 * (fVar6 - *(float *)(iVar14 + 0x84)) + *(float *)(iVar14 + 0x84);
      fVar5 = fVar12 * (fVar7 - *(float *)(iVar14 + 0x88)) + *(float *)(iVar14 + 0x88);
      fVar4 = fVar12 * (fVar4 - *(float *)(iVar14 + 0x8c)) + *(float *)(iVar14 + 0x8c);
      if (bVar1) {
        fVar7 = param_4[3];
        fVar4 = fVar4 * fVar7;
        fVar8 = fVar8 * fVar7;
        fVar6 = fVar6 * fVar7;
        fVar5 = fVar5 * fVar7;
      }
      param_4[uVar18 * 4 + 0x23] = fVar4;
      param_4[uVar18 * 4 + 0x20] = fVar8;
      param_4[uVar18 * 4 + 0x21] = fVar6;
      param_4[uVar18 * 4 + 0x22] = fVar5;
    }
    uVar18 = uVar18 + 1;
  } while( true );
}

/* _gleInterpolClipNO1210w @ 0xc01d8 (896 bytes) */
uint _gleInterpolClipNO1210w(int param_1,int param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  
  fVar4 = *(float *)(param_2 + 0x10);
  fVar5 = *(float *)(param_2 + 0x14);
  fVar6 = *(float *)(param_2 + 0x18);
  fVar7 = *(float *)(param_2 + 0x1c);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000c03dc;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000c033c;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000c03dc;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000c03dc;
    fVar8 = -fVar7;
LAB_000c033c:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000c03dc;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000c03dc:
  bVar2 = *(byte *)(param_2 + 0x7c);
  bVar3 = *(byte *)(param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar5 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar7;
    param_4[2] = fVar4 * fVar6 + fVar5;
  }
  uVar17 = 0;
  fVar4 = *(float *)(param_2 + 0x30);
  fVar5 = *(float *)(param_2 + 0x34);
  fVar6 = *(float *)(param_2 + 0x3c);
  fVar7 = *(float *)(param_3 + 0x30);
  fVar8 = *(float *)(param_3 + 0x34);
  fVar9 = *(float *)(param_2 + 0x38);
  fVar10 = *(float *)(param_3 + 0x3c);
  param_4[0x13] =
       fVar12 * (*(float *)(param_3 + 0x4c) - *(float *)(param_2 + 0x4c)) +
       *(float *)(param_2 + 0x4c);
  fVar11 = *(float *)(param_3 + 0x38);
  param_4[0xc] = fVar12 * (fVar7 - fVar4) + fVar4;
  param_4[0xd] = fVar12 * (fVar8 - fVar5) + fVar5;
  param_4[0xf] = fVar12 * (fVar10 - fVar6) + fVar6;
  param_4[0xe] = fVar12 * (fVar11 - fVar9) + fVar9;
  uVar14 = *(uint *)(param_1 + 0x5150);
  do {
    uVar13 = uVar14 >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        return uVar15;
      }
    }
    else {
      iVar16 = uVar17 * 0x10 + param_2;
      iVar18 = uVar17 * 0x10 + param_3;
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar5 = *(float *)(iVar16 + 0x84);
      fVar6 = *(float *)(iVar16 + 0x88);
      fVar7 = *(float *)(iVar18 + 0x8c);
      fVar8 = *(float *)(iVar18 + 0x84);
      fVar9 = *(float *)(iVar18 + 0x88);
      param_4[uVar17 * 4 + 0x20] =
           fVar12 * (*(float *)(iVar18 + 0x80) - *(float *)(iVar16 + 0x80)) +
           *(float *)(iVar16 + 0x80);
      param_4[uVar17 * 4 + 0x21] = fVar12 * (fVar8 - fVar5) + fVar5;
      param_4[uVar17 * 4 + 0x22] = fVar12 * (fVar9 - fVar6) + fVar6;
      param_4[uVar17 * 4 + 0x23] = fVar12 * (fVar7 - fVar4) + fVar4;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolClipNO1211 @ 0xc0558 (1036 bytes) */
uint _gleInterpolClipNO1211(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  
  fVar4 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000c075c;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000c06bc;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000c075c;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000c075c;
    fVar8 = -fVar7;
LAB_000c06bc:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000c075c;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000c075c:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar5 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar7;
    param_4[2] = fVar4 * fVar6 + fVar5;
  }
  uVar17 = 0;
  param_4[0x13] = fVar12 * (*(float *)(param_3 + 0x4c) - param_2[0x13]) + param_2[0x13];
  uVar14 = *(uint *)(param_1 + 0x5150);
  do {
    uVar13 = uVar14 >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        fVar4 = param_2[0x11];
        fVar5 = param_2[0x12];
        fVar6 = *(float *)(param_3 + 0x44);
        fVar7 = *(float *)(param_3 + 0x48);
        param_4[0x10] = fVar12 * (*(float *)(param_3 + 0x40) - param_2[0x10]) + param_2[0x10];
        param_4[0x11] = fVar12 * (fVar6 - fVar4) + fVar4;
        param_4[0x12] = fVar12 * (fVar7 - fVar5) + fVar5;
        if (param_2 != param_4) {
          param_4[0x1d] = param_2[0x1d];
          param_4[0x1e] = param_2[0x1e];
        }
        fVar4 = param_2[0xb];
        fVar5 = param_2[9];
        fVar6 = param_2[10];
        fVar7 = *(float *)(param_3 + 0x2c);
        fVar8 = *(float *)(param_3 + 0x24);
        fVar9 = *(float *)(param_3 + 0x28);
        param_4[8] = fVar12 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
        param_4[0xb] = fVar12 * (fVar7 - fVar4) + fVar4;
        param_4[9] = fVar12 * (fVar8 - fVar5) + fVar5;
        param_4[10] = fVar12 * (fVar9 - fVar6) + fVar6;
        return uVar15;
      }
    }
    else {
      iVar16 = uVar17 * 0x10 + param_3;
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar5 = *(float *)(iVar16 + 0x80);
      fVar6 = *(float *)(iVar16 + 0x84);
      fVar7 = *(float *)(iVar16 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        fVar8 = *(float *)(param_3 + 0x1c);
        fVar4 = fVar4 * fVar8;
        fVar5 = fVar5 * fVar8;
        fVar6 = fVar6 * fVar8;
        fVar7 = fVar7 * fVar8;
      }
      fVar8 = fVar12 * (fVar5 - param_2[uVar17 * 4 + 0x20]) + param_2[uVar17 * 4 + 0x20];
      fVar6 = fVar12 * (fVar6 - param_2[uVar17 * 4 + 0x21]) + param_2[uVar17 * 4 + 0x21];
      fVar5 = fVar12 * (fVar7 - param_2[uVar17 * 4 + 0x22]) + param_2[uVar17 * 4 + 0x22];
      fVar4 = fVar12 * (fVar4 - param_2[uVar17 * 4 + 0x23]) + param_2[uVar17 * 4 + 0x23];
      if (bVar1) {
        fVar7 = param_4[3];
        fVar4 = fVar4 * fVar7;
        fVar8 = fVar8 * fVar7;
        fVar6 = fVar6 * fVar7;
        fVar5 = fVar5 * fVar7;
      }
      param_4[uVar17 * 4 + 0x23] = fVar4;
      param_4[uVar17 * 4 + 0x20] = fVar8;
      param_4[uVar17 * 4 + 0x21] = fVar6;
      param_4[uVar17 * 4 + 0x22] = fVar5;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolClipNO1211w @ 0xc0964 (980 bytes) */
uint _gleInterpolClipNO1211w(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  
  fVar4 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar12 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000c0b68;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000c0ac8;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar12 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar12 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar12 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar5 = fVar12 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
      goto LAB_000c0b68;
    }
    if (param_5 == 4) {
      fVar12 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar15 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar12 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar12 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar12 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar12 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000c0b68;
    fVar8 = -fVar7;
LAB_000c0ac8:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000c0b68;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000c0b68:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar5 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar7;
    param_4[2] = fVar4 * fVar6 + fVar5;
  }
  uVar16 = 0;
  param_4[0x13] = fVar12 * (*(float *)(param_3 + 0x4c) - param_2[0x13]) + param_2[0x13];
  uVar14 = *(uint *)(param_1 + 0x5150);
  do {
    uVar13 = uVar14 >> (uVar16 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        fVar4 = param_2[0x11];
        fVar5 = param_2[0x12];
        fVar6 = *(float *)(param_3 + 0x44);
        fVar7 = *(float *)(param_3 + 0x48);
        param_4[0x10] = fVar12 * (*(float *)(param_3 + 0x40) - param_2[0x10]) + param_2[0x10];
        param_4[0x11] = fVar12 * (fVar6 - fVar4) + fVar4;
        param_4[0x12] = fVar12 * (fVar7 - fVar5) + fVar5;
        if (param_2 != param_4) {
          param_4[0x1d] = param_2[0x1d];
          param_4[0x1e] = param_2[0x1e];
        }
        fVar4 = param_2[0xb];
        fVar5 = param_2[9];
        fVar6 = param_2[10];
        fVar7 = *(float *)(param_3 + 0x2c);
        fVar8 = *(float *)(param_3 + 0x24);
        fVar9 = *(float *)(param_3 + 0x28);
        param_4[8] = fVar12 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
        param_4[0xb] = fVar12 * (fVar7 - fVar4) + fVar4;
        param_4[9] = fVar12 * (fVar8 - fVar5) + fVar5;
        param_4[10] = fVar12 * (fVar9 - fVar6) + fVar6;
        return uVar15;
      }
    }
    else {
      iVar17 = uVar16 * 0x10 + param_3;
      fVar4 = param_2[uVar16 * 4 + 0x23];
      fVar5 = param_2[uVar16 * 4 + 0x21];
      fVar6 = param_2[uVar16 * 4 + 0x22];
      fVar7 = *(float *)(iVar17 + 0x8c);
      fVar8 = *(float *)(iVar17 + 0x84);
      fVar9 = *(float *)(iVar17 + 0x88);
      param_4[uVar16 * 4 + 0x20] =
           fVar12 * (*(float *)(iVar17 + 0x80) - param_2[uVar16 * 4 + 0x20]) +
           param_2[uVar16 * 4 + 0x20];
      param_4[uVar16 * 4 + 0x21] = fVar12 * (fVar8 - fVar5) + fVar5;
      param_4[uVar16 * 4 + 0x22] = fVar12 * (fVar9 - fVar6) + fVar6;
      param_4[uVar16 * 4 + 0x23] = fVar12 * (fVar7 - fVar4) + fVar4;
    }
    uVar16 = uVar16 + 1;
  } while( true );
}

/* _gleInterpolClipAllFlat @ 0xc0d38 (980 bytes) */
uint _gleInterpolClipAllFlat(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  float fVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  
  fVar4 = param_2[4];
  fVar13 = param_2[5];
  fVar5 = param_2[6];
  fVar6 = param_2[7];
  fVar7 = *(float *)(param_3 + 0x10);
  fVar8 = *(float *)(param_3 + 0x14);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar11 = (fVar6 + fVar5) / ((fVar6 + fVar5) - (fVar10 + fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = -fVar6;
      if (FLOAT_00108e50 <= fVar6) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar5) / ((fVar6 - fVar5) - (fVar10 - fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = fVar6;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
    if (!bVar1) goto LAB_000c0f3c;
    fVar7 = -fVar6;
    if (fVar7 <= fVar13) {
      if (fVar13 < fVar6) goto LAB_000c0e9c;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar11 = (fVar6 + fVar4) / ((fVar6 + fVar4) - (fVar10 + fVar7));
        fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar4 = -fVar6;
        uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar11 = (fVar6 - fVar4) / ((fVar6 - fVar4) - (fVar10 - fVar7));
        fVar4 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar6 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
      fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
      goto LAB_000c0f3c;
    }
    if (param_5 == 4) {
      fVar11 = (fVar6 + fVar13) / ((fVar6 + fVar13) - (fVar10 + fVar8));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar13 = -fVar6;
      uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar13) / ((fVar6 - fVar13) - (fVar10 - fVar8));
      fVar13 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar6 = fVar13;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000c0f3c;
    fVar7 = -fVar6;
LAB_000c0e9c:
    if (fVar7 <= fVar4) {
      if (fVar4 < fVar6) goto LAB_000c0f3c;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000c0f3c:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar13;
  param_4[6] = fVar5;
  param_4[7] = fVar6;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar6 != FLOAT_00108e54) {
      fVar6 = FLOAT_00108e54 / fVar6;
      fVar4 = fVar4 * fVar6;
      fVar13 = fVar13 * fVar6;
      fVar5 = fVar5 * fVar6;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar13 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar13 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar6;
    param_4[2] = fVar4 * fVar5 + fVar13;
  }
  uVar17 = 0;
  fVar4 = param_2[0x13];
  fVar13 = *(float *)(param_3 + 0x4c);
  param_4[0x17] = fVar11 * (*(float *)(param_3 + 0x5c) - param_2[0x17]) + param_2[0x17];
  param_4[0x13] = fVar11 * (fVar13 - fVar4) + fVar4;
  uVar14 = *(uint *)(param_1 + 0x5150);
  do {
    uVar12 = uVar14 >> (uVar17 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (param_2 != param_4) {
          *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
          *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
          *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
          *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
          *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
          param_4[0x12] = param_2[0x12];
          *(undefined8 *)(param_4 + 0x14) = *(undefined8 *)(param_2 + 0x14);
          fVar4 = param_2[0x16];
          param_4[0x1d] = param_2[0x1d];
          fVar13 = param_2[0x1e];
          param_4[0x16] = fVar4;
          param_4[0x1e] = fVar13;
        }
        return uVar15;
      }
    }
    else {
      iVar16 = uVar17 * 0x10 + param_3;
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar13 = *(float *)(iVar16 + 0x80);
      fVar5 = *(float *)(iVar16 + 0x84);
      fVar6 = *(float *)(iVar16 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        fVar7 = *(float *)(param_3 + 0x1c);
        fVar4 = fVar4 * fVar7;
        fVar13 = fVar13 * fVar7;
        fVar5 = fVar5 * fVar7;
        fVar6 = fVar6 * fVar7;
      }
      fVar7 = fVar11 * (fVar13 - param_2[uVar17 * 4 + 0x20]) + param_2[uVar17 * 4 + 0x20];
      fVar5 = fVar11 * (fVar5 - param_2[uVar17 * 4 + 0x21]) + param_2[uVar17 * 4 + 0x21];
      fVar13 = fVar11 * (fVar6 - param_2[uVar17 * 4 + 0x22]) + param_2[uVar17 * 4 + 0x22];
      fVar4 = fVar11 * (fVar4 - param_2[uVar17 * 4 + 0x23]) + param_2[uVar17 * 4 + 0x23];
      if (bVar1) {
        fVar6 = param_4[3];
        fVar4 = fVar4 * fVar6;
        fVar7 = fVar7 * fVar6;
        fVar5 = fVar5 * fVar6;
        fVar13 = fVar13 * fVar6;
      }
      param_4[uVar17 * 4 + 0x23] = fVar4;
      param_4[uVar17 * 4 + 0x20] = fVar7;
      param_4[uVar17 * 4 + 0x21] = fVar5;
      param_4[uVar17 * 4 + 0x22] = fVar13;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolClipAllFlatw @ 0xc110c (924 bytes) */
uint _gleInterpolClipAllFlatw(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  float fVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  
  fVar4 = param_2[4];
  fVar13 = param_2[5];
  fVar5 = param_2[6];
  fVar6 = param_2[7];
  fVar7 = *(float *)(param_3 + 0x10);
  fVar8 = *(float *)(param_3 + 0x14);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar11 = (fVar6 + fVar5) / ((fVar6 + fVar5) - (fVar10 + fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = -fVar6;
      if (FLOAT_00108e50 <= fVar6) {
        uVar15 = 0;
      }
      else {
        uVar15 = 2;
      }
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar5) / ((fVar6 - fVar5) - (fVar10 - fVar9));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar5 = fVar6;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
    if (!bVar1) goto LAB_000c1310;
    fVar7 = -fVar6;
    if (fVar7 <= fVar13) {
      if (fVar13 < fVar6) goto LAB_000c1270;
      uVar15 = 8;
    }
    else {
      uVar15 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar11 = (fVar6 + fVar4) / ((fVar6 + fVar4) - (fVar10 + fVar7));
        fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar4 = -fVar6;
        uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar15 = 0;
        fVar11 = (fVar6 - fVar4) / ((fVar6 - fVar4) - (fVar10 - fVar7));
        fVar4 = fVar11 * (fVar10 - fVar6) + fVar6;
        fVar6 = fVar4;
      }
      bVar1 = uVar15 == 0;
      fVar13 = fVar11 * (fVar8 - fVar13) + fVar13;
      fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
      goto LAB_000c1310;
    }
    if (param_5 == 4) {
      fVar11 = (fVar6 + fVar13) / ((fVar6 + fVar13) - (fVar10 + fVar8));
      fVar6 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar13 = -fVar6;
      uVar15 = (uint)(fVar6 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar15 = 0;
      fVar11 = (fVar6 - fVar13) / ((fVar6 - fVar13) - (fVar10 - fVar8));
      fVar13 = fVar11 * (fVar10 - fVar6) + fVar6;
      fVar6 = fVar13;
    }
    bVar1 = uVar15 == 0;
    fVar4 = fVar11 * (fVar7 - fVar4) + fVar4;
    fVar5 = fVar11 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000c1310;
    fVar7 = -fVar6;
LAB_000c1270:
    if (fVar7 <= fVar4) {
      if (fVar4 < fVar6) goto LAB_000c1310;
      uVar15 = 0x20;
    }
    else {
      uVar15 = 0x10;
    }
  }
  bVar1 = uVar15 == 0;
LAB_000c1310:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar13;
  param_4[6] = fVar5;
  param_4[7] = fVar6;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar15 | 0x10000)));
  if (bVar1) {
    if (fVar6 != FLOAT_00108e54) {
      fVar6 = FLOAT_00108e54 / fVar6;
      fVar4 = fVar4 * fVar6;
      fVar13 = fVar13 * fVar6;
      fVar5 = fVar5 * fVar6;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar13 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar13 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar6;
    param_4[2] = fVar4 * fVar5 + fVar13;
  }
  uVar16 = 0;
  fVar4 = param_2[0x13];
  fVar13 = *(float *)(param_3 + 0x4c);
  param_4[0x17] = fVar11 * (*(float *)(param_3 + 0x5c) - param_2[0x17]) + param_2[0x17];
  param_4[0x13] = fVar11 * (fVar13 - fVar4) + fVar4;
  uVar14 = *(uint *)(param_1 + 0x5150);
  do {
    uVar12 = uVar14 >> (uVar16 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (param_2 != param_4) {
          *(undefined8 *)(param_4 + 8) = *(undefined8 *)(param_2 + 8);
          *(undefined8 *)(param_4 + 10) = *(undefined8 *)(param_2 + 10);
          *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
          *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
          *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
          param_4[0x12] = param_2[0x12];
          *(undefined8 *)(param_4 + 0x14) = *(undefined8 *)(param_2 + 0x14);
          fVar4 = param_2[0x16];
          param_4[0x1d] = param_2[0x1d];
          fVar13 = param_2[0x1e];
          param_4[0x16] = fVar4;
          param_4[0x1e] = fVar13;
        }
        return uVar15;
      }
    }
    else {
      iVar17 = uVar16 * 0x10 + param_3;
      fVar4 = param_2[uVar16 * 4 + 0x23];
      fVar13 = param_2[uVar16 * 4 + 0x21];
      fVar5 = param_2[uVar16 * 4 + 0x22];
      fVar6 = *(float *)(iVar17 + 0x8c);
      fVar7 = *(float *)(iVar17 + 0x84);
      fVar8 = *(float *)(iVar17 + 0x88);
      param_4[uVar16 * 4 + 0x20] =
           fVar11 * (*(float *)(iVar17 + 0x80) - param_2[uVar16 * 4 + 0x20]) +
           param_2[uVar16 * 4 + 0x20];
      param_4[uVar16 * 4 + 0x21] = fVar11 * (fVar7 - fVar13) + fVar13;
      param_4[uVar16 * 4 + 0x22] = fVar11 * (fVar8 - fVar5) + fVar5;
      param_4[uVar16 * 4 + 0x23] = fVar11 * (fVar6 - fVar4) + fVar4;
    }
    uVar16 = uVar16 + 1;
  } while( true );
}

/* _gleInterpolClipAllSmooth @ 0xc14a8 (1196 bytes) */
uint _gleInterpolClipAllSmooth(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
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
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  
  fVar4 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar16 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar16 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar19 = 0;
      }
      else {
        uVar19 = 2;
      }
    }
    else {
      uVar19 = 0;
      fVar16 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar16 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar19 == 0;
    fVar4 = fVar16 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar16 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000c16ac;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000c160c;
      uVar19 = 8;
    }
    else {
      uVar19 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar16 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar16 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar19 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar19 = 0;
        fVar16 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar16 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar19 == 0;
      fVar5 = fVar16 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar16 * (fVar10 - fVar6) + fVar6;
      goto LAB_000c16ac;
    }
    if (param_5 == 4) {
      fVar16 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar16 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar19 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar19 = 0;
      fVar16 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar16 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar19 == 0;
    fVar4 = fVar16 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar16 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000c16ac;
    fVar8 = -fVar7;
LAB_000c160c:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000c16ac;
      uVar19 = 0x20;
    }
    else {
      uVar19 = 0x10;
    }
  }
  bVar1 = uVar19 == 0;
LAB_000c16ac:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar19 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar5 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar7;
    param_4[2] = fVar4 * fVar6 + fVar5;
  }
  uVar21 = 0;
  fVar4 = param_2[0x13];
  fVar5 = *(float *)(param_3 + 0x4c);
  fVar6 = param_2[0xc];
  fVar7 = *(float *)(param_3 + 0x30);
  fVar8 = param_2[0xf];
  fVar9 = param_2[0xe];
  fVar10 = param_2[0xd];
  fVar11 = *(float *)(param_3 + 0x3c);
  param_4[0x17] = fVar16 * (*(float *)(param_3 + 0x5c) - param_2[0x17]) + param_2[0x17];
  param_4[0x13] = fVar16 * (fVar5 - fVar4) + fVar4;
  fVar4 = *(float *)(param_3 + 0x34);
  fVar5 = *(float *)(param_3 + 0x38);
  fVar12 = param_2[0x14];
  fVar13 = *(float *)(param_3 + 0x50);
  param_4[0xc] = fVar16 * (fVar7 - fVar6) + fVar6;
  fVar6 = param_2[0x15];
  fVar7 = *(float *)(param_3 + 0x54);
  fVar14 = param_2[0x16];
  fVar15 = *(float *)(param_3 + 0x58);
  param_4[0xd] = fVar16 * (fVar4 - fVar10) + fVar10;
  param_4[0xe] = fVar16 * (fVar5 - fVar9) + fVar9;
  param_4[0xf] = fVar16 * (fVar11 - fVar8) + fVar8;
  param_4[0x14] = fVar16 * (fVar13 - fVar12) + fVar12;
  param_4[0x15] = fVar16 * (fVar7 - fVar6) + fVar6;
  param_4[0x16] = fVar16 * (fVar15 - fVar14) + fVar14;
  uVar18 = *(uint *)(param_1 + 0x5150);
  do {
    uVar17 = uVar18 >> (uVar21 & 0x3f);
    if ((uVar17 & 1) == 0) {
      if (uVar17 == 0) {
        fVar4 = param_2[0x11];
        fVar5 = param_2[0x12];
        fVar6 = *(float *)(param_3 + 0x44);
        fVar7 = *(float *)(param_3 + 0x48);
        param_4[0x10] = fVar16 * (*(float *)(param_3 + 0x40) - param_2[0x10]) + param_2[0x10];
        param_4[0x11] = fVar16 * (fVar6 - fVar4) + fVar4;
        param_4[0x12] = fVar16 * (fVar7 - fVar5) + fVar5;
        if (param_2 != param_4) {
          param_4[0x1d] = param_2[0x1d];
          param_4[0x1e] = param_2[0x1e];
        }
        fVar4 = param_2[0xb];
        fVar5 = param_2[9];
        fVar6 = param_2[10];
        fVar7 = *(float *)(param_3 + 0x2c);
        fVar8 = *(float *)(param_3 + 0x24);
        fVar9 = *(float *)(param_3 + 0x28);
        param_4[8] = fVar16 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
        param_4[0xb] = fVar16 * (fVar7 - fVar4) + fVar4;
        param_4[9] = fVar16 * (fVar8 - fVar5) + fVar5;
        param_4[10] = fVar16 * (fVar9 - fVar6) + fVar6;
        return uVar19;
      }
    }
    else {
      iVar20 = uVar21 * 0x10 + param_3;
      fVar4 = *(float *)(iVar20 + 0x8c);
      fVar5 = *(float *)(iVar20 + 0x80);
      fVar6 = *(float *)(iVar20 + 0x84);
      fVar7 = *(float *)(iVar20 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        fVar8 = *(float *)(param_3 + 0x1c);
        fVar4 = fVar4 * fVar8;
        fVar5 = fVar5 * fVar8;
        fVar6 = fVar6 * fVar8;
        fVar7 = fVar7 * fVar8;
      }
      fVar8 = fVar16 * (fVar5 - param_2[uVar21 * 4 + 0x20]) + param_2[uVar21 * 4 + 0x20];
      fVar6 = fVar16 * (fVar6 - param_2[uVar21 * 4 + 0x21]) + param_2[uVar21 * 4 + 0x21];
      fVar5 = fVar16 * (fVar7 - param_2[uVar21 * 4 + 0x22]) + param_2[uVar21 * 4 + 0x22];
      fVar4 = fVar16 * (fVar4 - param_2[uVar21 * 4 + 0x23]) + param_2[uVar21 * 4 + 0x23];
      if (bVar1) {
        fVar7 = param_4[3];
        fVar4 = fVar4 * fVar7;
        fVar8 = fVar8 * fVar7;
        fVar6 = fVar6 * fVar7;
        fVar5 = fVar5 * fVar7;
      }
      param_4[uVar21 * 4 + 0x23] = fVar4;
      param_4[uVar21 * 4 + 0x20] = fVar8;
      param_4[uVar21 * 4 + 0x21] = fVar6;
      param_4[uVar21 * 4 + 0x22] = fVar5;
    }
    uVar21 = uVar21 + 1;
  } while( true );
}

/* _gleInterpolClipAllSmoothw @ 0xc1954 (1140 bytes) */
uint _gleInterpolClipAllSmoothw(int param_1,float *param_2,int param_3,float *param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
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
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  
  fVar4 = param_2[4];
  fVar5 = param_2[5];
  fVar6 = param_2[6];
  fVar7 = param_2[7];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = *(float *)(param_3 + 0x18);
  fVar11 = *(float *)(param_3 + 0x1c);
  if (param_5 < 3) {
    if (param_5 == 1) {
      fVar16 = (fVar7 + fVar6) / ((fVar7 + fVar6) - (fVar11 + fVar10));
      fVar7 = fVar16 * (fVar11 - fVar7) + fVar7;
      fVar6 = -fVar7;
      if (FLOAT_00108e50 <= fVar7) {
        uVar19 = 0;
      }
      else {
        uVar19 = 2;
      }
    }
    else {
      uVar19 = 0;
      fVar16 = (fVar7 - fVar6) / ((fVar7 - fVar6) - (fVar11 - fVar10));
      fVar7 = fVar16 * (fVar11 - fVar7) + fVar7;
      fVar6 = fVar7;
    }
    bVar1 = uVar19 == 0;
    fVar4 = fVar16 * (fVar8 - fVar4) + fVar4;
    fVar5 = fVar16 * (fVar9 - fVar5) + fVar5;
    if (!bVar1) goto LAB_000c1b58;
    fVar8 = -fVar7;
    if (fVar8 <= fVar5) {
      if (fVar5 < fVar7) goto LAB_000c1ab8;
      uVar19 = 8;
    }
    else {
      uVar19 = 4;
    }
  }
  else {
    if (8 < param_5) {
      if (param_5 == 0x10) {
        fVar16 = (fVar7 + fVar4) / ((fVar7 + fVar4) - (fVar11 + fVar8));
        fVar7 = fVar16 * (fVar11 - fVar7) + fVar7;
        fVar4 = -fVar7;
        uVar19 = (uint)(fVar7 <= FLOAT_00108e50) << 5;
      }
      else {
        uVar19 = 0;
        fVar16 = (fVar7 - fVar4) / ((fVar7 - fVar4) - (fVar11 - fVar8));
        fVar4 = fVar16 * (fVar11 - fVar7) + fVar7;
        fVar7 = fVar4;
      }
      bVar1 = uVar19 == 0;
      fVar5 = fVar16 * (fVar9 - fVar5) + fVar5;
      fVar6 = fVar16 * (fVar10 - fVar6) + fVar6;
      goto LAB_000c1b58;
    }
    if (param_5 == 4) {
      fVar16 = (fVar7 + fVar5) / ((fVar7 + fVar5) - (fVar11 + fVar9));
      fVar7 = fVar16 * (fVar11 - fVar7) + fVar7;
      fVar5 = -fVar7;
      uVar19 = (uint)(fVar7 <= FLOAT_00108e50) << 3;
    }
    else {
      uVar19 = 0;
      fVar16 = (fVar7 - fVar5) / ((fVar7 - fVar5) - (fVar11 - fVar9));
      fVar5 = fVar16 * (fVar11 - fVar7) + fVar7;
      fVar7 = fVar5;
    }
    bVar1 = uVar19 == 0;
    fVar4 = fVar16 * (fVar8 - fVar4) + fVar4;
    fVar6 = fVar16 * (fVar10 - fVar6) + fVar6;
    if (!bVar1) goto LAB_000c1b58;
    fVar8 = -fVar7;
LAB_000c1ab8:
    if (fVar8 <= fVar4) {
      if (fVar4 < fVar7) goto LAB_000c1b58;
      uVar19 = 0x20;
    }
    else {
      uVar19 = 0x10;
    }
  }
  bVar1 = uVar19 == 0;
LAB_000c1b58:
  bVar2 = *(byte *)(param_2 + 0x1f);
  bVar3 = *(byte *)((int)param_2 + 0x7e);
  param_4[4] = fVar4;
  param_4[5] = fVar5;
  param_4[6] = fVar6;
  param_4[7] = fVar7;
  param_4[0x1f] = GH_U2F((unsigned int)(((uint)bVar2 << 0x18 | (uint)bVar3 << 8 | uVar19 | 0x10000)));
  if (bVar1) {
    if (fVar7 != FLOAT_00108e54) {
      fVar7 = FLOAT_00108e54 / fVar7;
      fVar4 = fVar4 * fVar7;
      fVar5 = fVar5 * fVar7;
      fVar6 = fVar6 * fVar7;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar4 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar5 + *(float *)(param_1 + 0x1b84);
    fVar4 = *(float *)(param_1 + 0x1b78);
    fVar5 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar7;
    param_4[2] = fVar4 * fVar6 + fVar5;
  }
  uVar20 = 0;
  fVar4 = param_2[0x13];
  fVar5 = *(float *)(param_3 + 0x4c);
  fVar6 = param_2[0xc];
  fVar7 = *(float *)(param_3 + 0x30);
  fVar8 = param_2[0xf];
  fVar9 = param_2[0xe];
  fVar10 = param_2[0xd];
  fVar11 = *(float *)(param_3 + 0x3c);
  param_4[0x17] = fVar16 * (*(float *)(param_3 + 0x5c) - param_2[0x17]) + param_2[0x17];
  param_4[0x13] = fVar16 * (fVar5 - fVar4) + fVar4;
  fVar4 = *(float *)(param_3 + 0x34);
  fVar5 = *(float *)(param_3 + 0x38);
  fVar12 = param_2[0x14];
  fVar13 = *(float *)(param_3 + 0x50);
  param_4[0xc] = fVar16 * (fVar7 - fVar6) + fVar6;
  fVar6 = param_2[0x15];
  fVar7 = *(float *)(param_3 + 0x54);
  fVar14 = param_2[0x16];
  fVar15 = *(float *)(param_3 + 0x58);
  param_4[0xd] = fVar16 * (fVar4 - fVar10) + fVar10;
  param_4[0xe] = fVar16 * (fVar5 - fVar9) + fVar9;
  param_4[0xf] = fVar16 * (fVar11 - fVar8) + fVar8;
  param_4[0x14] = fVar16 * (fVar13 - fVar12) + fVar12;
  param_4[0x15] = fVar16 * (fVar7 - fVar6) + fVar6;
  param_4[0x16] = fVar16 * (fVar15 - fVar14) + fVar14;
  uVar18 = *(uint *)(param_1 + 0x5150);
  do {
    uVar17 = uVar18 >> (uVar20 & 0x3f);
    if ((uVar17 & 1) == 0) {
      if (uVar17 == 0) {
        fVar4 = param_2[0x11];
        fVar5 = param_2[0x12];
        fVar6 = *(float *)(param_3 + 0x44);
        fVar7 = *(float *)(param_3 + 0x48);
        param_4[0x10] = fVar16 * (*(float *)(param_3 + 0x40) - param_2[0x10]) + param_2[0x10];
        param_4[0x11] = fVar16 * (fVar6 - fVar4) + fVar4;
        param_4[0x12] = fVar16 * (fVar7 - fVar5) + fVar5;
        if (param_2 != param_4) {
          param_4[0x1d] = param_2[0x1d];
          param_4[0x1e] = param_2[0x1e];
        }
        fVar4 = param_2[0xb];
        fVar5 = param_2[9];
        fVar6 = param_2[10];
        fVar7 = *(float *)(param_3 + 0x2c);
        fVar8 = *(float *)(param_3 + 0x24);
        fVar9 = *(float *)(param_3 + 0x28);
        param_4[8] = fVar16 * (*(float *)(param_3 + 0x20) - param_2[8]) + param_2[8];
        param_4[0xb] = fVar16 * (fVar7 - fVar4) + fVar4;
        param_4[9] = fVar16 * (fVar8 - fVar5) + fVar5;
        param_4[10] = fVar16 * (fVar9 - fVar6) + fVar6;
        return uVar19;
      }
    }
    else {
      iVar21 = uVar20 * 0x10 + param_3;
      fVar4 = param_2[uVar20 * 4 + 0x23];
      fVar5 = param_2[uVar20 * 4 + 0x21];
      fVar6 = param_2[uVar20 * 4 + 0x22];
      fVar7 = *(float *)(iVar21 + 0x8c);
      fVar8 = *(float *)(iVar21 + 0x84);
      fVar9 = *(float *)(iVar21 + 0x88);
      param_4[uVar20 * 4 + 0x20] =
           fVar16 * (*(float *)(iVar21 + 0x80) - param_2[uVar20 * 4 + 0x20]) +
           param_2[uVar20 * 4 + 0x20];
      param_4[uVar20 * 4 + 0x21] = fVar16 * (fVar8 - fVar5) + fVar5;
      param_4[uVar20 * 4 + 0x22] = fVar16 * (fVar9 - fVar6) + fVar6;
      param_4[uVar20 * 4 + 0x23] = fVar16 * (fVar7 - fVar4) + fVar4;
    }
    uVar20 = uVar20 + 1;
  } while( true );
}

/* _gleSelectArrayInterpFunc @ 0xc1dc8 (544 bytes) */
int _gleSelectArrayInterpFunc(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined **ppuVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = 0;
  if ((*(int *)(param_1 + 0x4e1c) != 0x1c00) ||
     ((*(uint *)(*(int *)(param_1 + 0x468c) + 0x94) & 4) != 0)) {
    uVar6 = 0x18;
  }
  uVar7 = uVar6;
  if ((((*(int *)(param_1 + 0x34f4) == 0x1d01) &&
       (uVar7 = uVar6 + 0xc, *(char *)(param_1 + 0x30aa) != '\0')) &&
      (*(char *)(param_1 + 0x4664) == '\0')) && (*(int *)(param_1 + 0x5434) == 0)) {
    uVar7 = uVar6 + 0xd;
  }
  uVar6 = _gleTexEnableBits(param_1);
  *(uint *)(param_1 + 0x5150) = uVar6;
  if (((uVar6 != 0) || (uVar8 = uVar7, *(int *)(param_1 + 0x4e1c) == 0x1c01)) &&
     ((uVar8 = uVar7 + 4, (uVar6 & 0xfffffffe) != 0 && (*(int *)(param_1 + 0x4e1c) == 0x1c00)))) {
    uVar8 = uVar7 + 8;
  }
  if ((*(char *)(param_1 + 0x316a) != '\0') && (*(int *)(param_1 + 0x4e1c) == 0x1c00)) {
    uVar8 = uVar8 + 2;
  }
  if ((*(short *)(0x3170 + param_1 + 4) == 0x1102) ||
     ((*(char *)(param_1 + 0x4fea) != '\0' &&
      (((*(char *)(param_1 + 0x30aa) == '\0' || (*(char *)(param_1 + 0x4664) != '\0')) ||
       (*(int *)(param_1 + 0x5434) != 0)))))) {
    uVar8 = uVar8 / 0xc;
    puVar1 = PTR__gleInterpolClipAllSmoothw_00110678;
    puVar2 = PTR__gleInterpolClipAllFlatw_0011067c;
    puVar3 = PTR__gleInterpolClipAllSmooth_00110680;
    puVar4 = PTR__gleInterpolClipAllFlat_00110684;
    if (param_2 == 0) {
      puVar1 = PTR__gleInterpolEyeAllSmoothw_00110688;
      puVar2 = PTR__gleInterpolEyeAllFlatw_0011068c;
      puVar3 = PTR__gleInterpolEyeAllSmooth_00110690;
      puVar4 = PTR__gleInterpolEyeAllFlat_00110694;
    }
    if (uVar8 == 1) {
      return puVar3;
    }
    if (uVar8 < 2) {
      if (uVar8 == 0) {
        return puVar4;
      }
    }
    else {
      if (uVar8 == 2) {
        return puVar2;
      }
      if (uVar8 == 3) {
        return puVar1;
      }
    }
  }
  if (param_2 == 0) {
    ppuVar5 = &_eye_interp_funcs;
  }
  else {
    ppuVar5 = &_clip_interp_funcs;
  }
  return ppuVar5[uVar8];
}

/* _gleSetEyeInterpFunc @ 0xc1fe8 (104 bytes) */
void _gleSetEyeInterpFunc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1)
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE =
       (code *)_gleBuildInterpolateFunc(param_1,0,param_3,param_4,param_5,param_6,param_7,param_8);
  *(code **)(param_1 + 0x49c8) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*((int (*)(int,int,int,int,double))UNRECOVERED_JUMPTABLE))(param_1, param_2, param_3, param_4, fparam_1);
  return;
}

/* _gleShrinkFuncCache @ 0xc2054 (68 bytes) */
void _gleShrinkFuncCache(param_1, param_2)
  int param_1;
  int param_2;
{
  if (0 < param_2) {
    do {
      ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(param_1 + 4));
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

/* _gleDeleteFuncCacheElem @ 0xc2098 (24 bytes) */
void _gleDeleteFuncCacheElem(param_1)
  int *param_1;
{
  int *piVar1;
  
  piVar1 = (int *)param_1[1];
  *piVar1 = *param_1;
  *(int **)(*param_1 + 4) = piVar1;
  _gleDCBFree(param_1);
  return;
}

/* _gleRTCAddAChunk_c20b0 @ 0xc20b0 (48 bytes) */
int _gleRTCAddAChunk_c20b0(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return iVar2;
}

/* _gleBuildInterpFunc @ 0xc20e0 (876 bytes) */
int _gleBuildInterpFunc(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  
  uVar2 = *(uint *)(param_1 + 0x498c);
  cVar7 = (*(uint *)(*(int *)(param_1 + 0x468c) + 0x94) & 3) == 1;
  if (0x20 < *(ushort *)(param_1 + 0x4990)) {
    cVar7 = cVar7 << 1;
  }
  iVar3 = _gleCreateFuncCacheElem(*(undefined4 *)(param_1 + 0x49b8),0x130);
  if (iVar3 == 0) {
    return PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar3 + 8) = param_2;
  if (*(short *)(param_1 + 0x49c2) == *(short *)(param_1 + 0x49c0)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar3 + 4));
  }
  else {
    *(short *)(param_1 + 0x49c2) = *(short *)(param_1 + 0x49c2) + 1;
  }
  bVar1 = (uVar2 >> 0xf & 1) == 0;
  if (bVar1) {
    puVar4 = &_gleVAPrologRTC;
  }
  else {
    puVar4 = &_gleVASwapPrologRTC;
  }
  iVar5 = ((int (*)())_gleRTCAddAChunk_c20b0)(puVar4,iVar3 + 0x20);
  iVar5 = iVar3 + 0x20 + iVar5 * 4;
  if ((param_2 & 0x10) == 0) {
    if ((param_2 & 8) == 0) {
      if ((param_2 & 4) == 0) {
        puVar4 = &_gleVASetOffsetsGr;
      }
      else {
        puVar4 = &_gleVASetOffsetsFogGr;
      }
    }
    else if ((param_2 & 4) == 0) {
      puVar4 = &_gleVASetOffsetsTex;
    }
    else {
      puVar4 = &_gleVASetOffsetsFogTex;
    }
  }
  else if ((param_2 & 4) == 0) {
    puVar4 = &_gleVASetOffsetsTex2;
  }
  else {
    puVar4 = &_gleVASetOffsetsFogTex2;
  }
  iVar6 = ((int (*)())_gleRTCAddAChunk_c20b0)(puVar4,iVar5);
  iVar5 = iVar5 + iVar6 * 4;
  if (bVar1) {
    puVar4 = &_gleVALoadVertices;
  }
  else {
    puVar4 = &_gleVASwapLoadVertices;
  }
  iVar6 = ((int (*)())_gleRTCAddAChunk_c20b0)(puVar4,iVar5);
  iVar5 = iVar5 + iVar6 * 4;
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0) {
    puVar4 = &_gleVAInterpVertex;
  }
  else {
    puVar4 = &_gleVAInterpVertexAV;
  }
  iVar6 = ((int (*)())_gleRTCAddAChunk_c20b0)(puVar4,iVar5);
  iVar5 = iVar5 + iVar6 * 4;
  if (bVar1) {
    puVar4 = &_gleVAStoreVertex;
  }
  else {
    puVar4 = &_gleVASwapStoreVertex;
  }
  iVar6 = ((int (*)())_gleRTCAddAChunk_c20b0)(puVar4,iVar5);
  iVar5 = iVar5 + iVar6 * 4;
  if ((param_2 & 2) != 0) {
    iVar6 = ((int (*)())_gleRTCAddAChunk_c20b0)(&_gleVAInterpColor,iVar5);
    iVar5 = iVar5 + iVar6 * 4;
  }
  if ((param_2 & 4) == 0) {
    puVar4 = &_gleVANoFog;
  }
  else if (bVar1) {
    puVar4 = &_gleVAInterpFog;
  }
  else {
    puVar4 = &_gleVASwapInterpFog;
  }
  iVar6 = ((int (*)())_gleRTCAddAChunk_c20b0)(puVar4,iVar5);
  iVar5 = iVar5 + iVar6 * 4;
  if ((param_2 & 8) != 0) {
    if (bVar1) {
      puVar4 = &_gleVAInterpTexCoord0;
    }
    else {
      puVar4 = &_gleVASwapInterpTexCoord0;
    }
    iVar6 = ((int (*)())_gleRTCAddAChunk_c20b0)(puVar4,iVar5);
    iVar5 = iVar5 + iVar6 * 4;
  }
  if ((param_2 & 0x10) != 0) {
    if (bVar1) {
      puVar4 = &_gleVAInterpTexCoord1;
    }
    else {
      puVar4 = &_gleVASwapInterpTexCoord1;
    }
    iVar6 = ((int (*)())_gleRTCAddAChunk_c20b0)(puVar4,iVar5);
    iVar5 = iVar5 + iVar6 * 4;
  }
  if (cVar7 == '\x01') {
    puVar4 = &_gleVASingleFlushDataRTC;
  }
  else {
    if (cVar7 != '\x02') goto LAB_000c23b8;
    puVar4 = &_gleVADoubleFlushDataRTC;
  }
  iVar6 = ((int (*)())_gleRTCAddAChunk_c20b0)(puVar4,iVar5);
  iVar5 = iVar5 + iVar6 * 4;
LAB_000c23b8:
  if (bVar1) {
    puVar4 = &_gleVAEpilogRTC;
  }
  else {
    puVar4 = &_gleVASwapEpilogRTC;
  }
  iVar6 = ((int (*)())_gleRTCAddAChunk_c20b0)(puVar4,iVar5);
  iVar5 = ((iVar5 + iVar6 * 4) - iVar3) + -0x20 >> 2;
  if (iVar5 < 0x131) {
    iVar3 = _gleShrinkFuncCacheElem(iVar3,iVar5);
    puVar4 = PTR__glePushInstructions_00112054;
    *(int *)(param_1 + 0x49b8) = iVar3;
    (**(code **)puVar4)(iVar5,(undefined *)(iVar3 + 0x20));
    return (undefined *)(iVar3 + 0x20);
  }
                    
  _exit(1);
}

/* _gleRTCBuildABranch_c244c @ 0xc244c (12 bytes) */
int _gleRTCBuildABranch_c244c(param_1, param_2)
  uint param_1;
  uint param_2;
{
  return (param_2 & 0x3fff) << 2 | param_1 & 0xffff0003;
}

/* _gleRTCAddAChunk_c2458 @ 0xc2458 (48 bytes) */
int _gleRTCAddAChunk_c2458(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return iVar2;
}

/* _gleBuildCompileFuncTCLNO @ 0xc2488 (1528 bytes) */
int _gleBuildCompileFuncTCLNO(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 *puVar14;
  
  bVar2 = false;
  iVar6 = -(param_2 >> 0x12 & 0x21);
  uVar13 = *(uint *)(param_1 + 0x498c) >> 0xf & 1;
  uVar3 = (uint)((*(uint *)(*(int *)(param_1 + 0x468c) + 0x94) & 3) == 1) *
          ((int)(*(ushort *)(param_1 + 0x4990) + 0x1f) >> 5) & 0xff;
  iVar7 = _gleCreateFuncCacheElem(*(undefined4 *)(param_1 + 0x49b4),0x180);
  if (iVar7 == 0) {
    return PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar7 + 8) = param_2;
  if (*(short *)(param_1 + 0x49be) == *(short *)(param_1 + 0x49bc)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar7 + 4));
  }
  else {
    *(short *)(param_1 + 0x49be) = *(short *)(param_1 + 0x49be) + 1;
  }
  bVar1 = uVar3 == 1;
  iVar8 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAPrologNoTransRTC,iVar7 + 0x20);
  iVar8 = iVar7 + 0x20 + iVar8 * 4;
  if (bVar1) {
    puVar11 = &_gleVASingleFlushSetupRTC;
LAB_000c2584:
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar11,iVar8);
    iVar8 = iVar8 + iVar9 * 4;
  }
  else if (uVar3 == 2) {
    puVar11 = &_gleVADoubleFlushSetupRTC;
    goto LAB_000c2584;
  }
  if ((param_2 >> 0x10 & 0x21) == 0x21) {
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)((&_vertex_load_array)[param_2 >> 0xc & 0xf],iVar8);
    iVar9 = iVar8 + iVar9 * 4;
    if (iVar6 < 0) {
      iVar10 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreVertXYZWRTC,iVar9);
      iVar9 = iVar9 + iVar10 * 4;
      if (uVar13 != 0) {
        puVar11 = &_gleVASwapStoreVertXYZWRTC;
        goto LAB_000c2674;
      }
    }
    else {
      iVar10 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreVertXYZRTC,iVar9);
      iVar9 = iVar9 + iVar10 * 4;
      if (uVar13 != 0) {
        puVar11 = &_gleVASwapStoreVertXYZRTC;
        goto LAB_000c2674;
      }
    }
  }
  else {
    bVar2 = true;
    iVar9 = iVar8;
    if (iVar6 < 0) {
      if (uVar13 == 0) {
        puVar11 = &_gleVACopyVertXYZWRTC;
      }
      else {
        puVar11 = &_gleVASwapCopyVertXYZWRTC;
      }
    }
    else if (uVar13 == 0) {
      puVar11 = &_gleVACopyVertXYZRTC;
    }
    else {
      puVar11 = &_gleVASwapCopyVertXYZRTC;
    }
LAB_000c2674:
    iVar10 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar11,iVar9);
    iVar9 = iVar9 + iVar10 * 4;
  }
  bVar5 = uVar13 == 0;
  bVar4 = -1 < iVar6;
  uVar13 = param_2 >> 0x11 & 0x21;
  if (uVar13 == 0x20) {
    bVar2 = true;
    if (bVar4) {
      puVar11 = &_gleVAColorFuncCopy12;
    }
    else {
      puVar11 = &_gleVAColorFuncCopy16;
    }
LAB_000c2734:
    iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar11,iVar9);
    iVar9 = iVar9 + iVar6 * 4;
  }
  else if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      puVar11 = &_gleVAColorFuncCurrent;
LAB_000c26ec:
      iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar11,iVar9);
      iVar9 = iVar9 + iVar6 * 4;
      if (bVar4) {
        if (bVar5) {
          puVar11 = &_gleVAStoreColor12;
        }
        else {
          puVar11 = &_gleVASwapColor12;
        }
      }
      else if (bVar5) {
        puVar11 = &_gleVAStoreColor16;
      }
      else {
        puVar11 = &_gleVASwapColor16;
      }
      goto LAB_000c2734;
    }
  }
  else if (uVar13 == 0x21) {
    puVar11 = *(undefined **)((int)&_color_func_array + (param_2 >> 6 & 0x3c));
    goto LAB_000c26ec;
  }
  uVar13 = param_2 >> 0x13 & 0x21;
  if (uVar13 == 0x20) {
    bVar2 = true;
    if (bVar4) {
      puVar11 = &_gleVATex0FuncCopyST16;
    }
    else {
      puVar11 = &_gleVATex0FuncCopySTQ20;
    }
    goto LAB_000c280c;
  }
  if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      puVar11 = &_gleVATex0LoadCurrent;
LAB_000c27ac:
      iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar11,iVar9);
      iVar9 = iVar9 + iVar6 * 4;
      if (bVar4) {
        iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex0ST16,iVar9);
        iVar9 = iVar9 + iVar6 * 4;
        if (!bVar5) {
          puVar11 = &_gleVASwapTex0ST16;
          goto LAB_000c280c;
        }
      }
      else {
        iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex0STQ20,iVar9);
        iVar9 = iVar9 + iVar6 * 4;
        if (!bVar5) {
          puVar11 = &_gleVASwapTex0STQ20;
LAB_000c280c:
          iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar11,iVar9);
          iVar9 = iVar9 + iVar6 * 4;
        }
      }
    }
  }
  else if (uVar13 == 0x21) {
    puVar11 = *(undefined **)((int)&_tex0_func_array + (param_2 >> 2 & 0x3c));
    goto LAB_000c27ac;
  }
  uVar13 = param_2 >> 0x14 & 0x21;
  if (uVar13 == 0x20) {
    bVar2 = true;
    if (bVar4) {
      puVar11 = &_gleVATex1FuncCopyST24;
    }
    else {
      puVar11 = &_gleVATex1FuncCopySTQ32;
    }
LAB_000c291c:
    iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar11,iVar9);
    iVar9 = iVar9 + iVar6 * 4;
  }
  else if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVATex1LoadCurrent,iVar9);
      iVar9 = iVar9 + iVar6 * 4;
      if (!bVar4) goto LAB_000c28d0;
LAB_000c28f8:
      iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex1ST24,iVar9);
      iVar9 = iVar9 + iVar6 * 4;
      if (!bVar5) {
        puVar11 = &_gleVASwapTex1ST24;
        goto LAB_000c291c;
      }
    }
  }
  else if (uVar13 == 0x21) {
    iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)((&_tex1_func_array)[param_2 & 0xf],iVar9);
    iVar9 = iVar9 + iVar6 * 4;
    if (bVar4) goto LAB_000c28f8;
    iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(*(undefined4 *)((int)&_tex1_tcl_array + (param_2 & 0xc)),iVar9);
    iVar9 = iVar9 + iVar6 * 4;
LAB_000c28d0:
    iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex1STQ32,iVar9);
    iVar9 = iVar9 + iVar6 * 4;
    if (!bVar5) {
      puVar11 = &_gleVASwapTex1STQ32;
      goto LAB_000c291c;
    }
  }
  if (bVar1) {
    puVar11 = &_gleVASingleFlushDataRTC;
LAB_000c2950:
    iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar11,iVar9);
    iVar9 = iVar9 + iVar6 * 4;
  }
  else if (uVar3 == 2) {
    puVar11 = &_gleVADoubleFlushDataRTC;
    goto LAB_000c2950;
  }
  if (bVar2) {
    iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAIncOldDataRTC,iVar9);
    iVar9 = iVar9 + iVar6 * 4;
  }
  iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAEndLoopRTC,iVar9);
  iVar9 = iVar9 + iVar6 * 4;
  puVar14 = (undefined4 *)(iVar9 + -4);
  if (bVar1) {
    puVar11 = &_gleVASingleFlushDataRTC;
  }
  else {
    if (uVar3 != 2) goto LAB_000c29e8;
    puVar11 = &_gleVADoubleCompleteDataRTC;
  }
  iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar11,iVar9);
  iVar9 = iVar9 + iVar6 * 4;
  iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)("}`!.|",iVar9);
  iVar9 = iVar9 + iVar6 * 4;
LAB_000c29e8:
  iVar6 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAEpilogNoTransRTC,iVar9);
  uVar12 = ((int (*)())_gleRTCBuildABranch_c244c)(*puVar14,iVar8 - (int)puVar14 >> 2);
  *puVar14 = uVar12;
  iVar6 = ((iVar9 + iVar6 * 4) - iVar7) + -0x20 >> 2;
  if (iVar6 < 0x181) {
    iVar7 = _gleShrinkFuncCacheElem(iVar7,iVar6);
    puVar11 = PTR__glePushInstructions_00112054;
    *(int *)(param_1 + 0x49b4) = iVar7;
    (**(code **)puVar11)(iVar6,(undefined *)(iVar7 + 0x20));
    return (undefined *)(iVar7 + 0x20);
  }
                    
  _exit(1);
}

/* _gleBuildCompileFuncNO @ 0xc2a80 (1512 bytes) */
int _gleBuildCompileFuncNO(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  char cVar11;
  uint uVar12;
  undefined4 *puVar13;
  
  bVar3 = false;
  uVar12 = *(uint *)(param_1 + 0x498c) >> 0xf & 1;
  cVar11 = (*(uint *)(*(int *)(param_1 + 0x468c) + 0x94) & 3) == 1;
  if (0x20 < *(ushort *)(param_1 + 0x4990)) {
    cVar11 = cVar11 << 1;
  }
  iVar5 = _gleCreateFuncCacheElem(*(undefined4 *)(param_1 + 0x49b4),0x180);
  if (iVar5 == 0) {
    return PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar5 + 8) = param_2;
  if (*(short *)(param_1 + 0x49be) == *(short *)(param_1 + 0x49bc)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar5 + 4));
  }
  else {
    *(short *)(param_1 + 0x49be) = *(short *)(param_1 + 0x49be) + 1;
  }
  uVar2 = param_2 >> 0x10;
  if ((uVar2 & 0x21) == 0x21) {
    puVar6 = &_gleVAPrologRTC;
  }
  else {
    puVar6 = &_gleVAPrologNoTransRTC;
  }
  bVar1 = cVar11 == '\x01';
  iVar7 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar5 + 0x20);
  iVar7 = iVar5 + 0x20 + iVar7 * 4;
  if (bVar1) {
    puVar6 = &_gleVASingleFlushSetupRTC;
LAB_000c2b8c:
    iVar8 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar7);
    iVar7 = iVar7 + iVar8 * 4;
  }
  else if (cVar11 == '\x02') {
    puVar6 = &_gleVADoubleFlushSetupRTC;
    goto LAB_000c2b8c;
  }
  if ((uVar2 & 0x21) == 0x21) {
    iVar8 = ((int (*)())_gleRTCAddAChunk_c2458)(*(undefined4 *)((int)&_vertex_func_array + (param_2 >> 10 & 0x3c)),iVar7);
    iVar8 = iVar7 + iVar8 * 4;
    if ((param_2 & 0x10000000) == 0) {
      puVar6 = &_gleVALoadClipVertRTC;
    }
    else {
      puVar6 = &_gleVALoadVertRTC;
    }
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar8);
    iVar8 = iVar8 + iVar9 * 4;
    if (uVar12 != 0) {
      puVar6 = &_gleVASwapStoreVertXYZWRTC;
      goto LAB_000c2c2c;
    }
  }
  else {
    bVar3 = true;
    iVar8 = iVar7;
    if (uVar12 == 0) {
      puVar6 = &_gleVACopyVertXYZWRTC;
    }
    else {
      puVar6 = &_gleVASwapCopyVertXYZWRTC;
    }
LAB_000c2c2c:
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar8);
    iVar8 = iVar8 + iVar9 * 4;
  }
  bVar4 = uVar12 == 0;
  uVar12 = param_2 >> 0x11 & 0x21;
  if (uVar12 == 0x20) {
    puVar6 = &_gleVAColorFuncCopy16;
    bVar3 = true;
LAB_000c2cc4:
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar8);
    iVar8 = iVar8 + iVar9 * 4;
  }
  else if (uVar12 < 0x21) {
    if (uVar12 == 1) {
      puVar6 = &_gleVAColorFuncCurrent;
LAB_000c2c98:
      iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar8);
      iVar8 = iVar8 + iVar9 * 4;
      if (bVar4) {
        puVar6 = &_gleVAStoreColor16;
      }
      else {
        puVar6 = &_gleVASwapColor16;
      }
      goto LAB_000c2cc4;
    }
  }
  else if (uVar12 == 0x21) {
    puVar6 = *(undefined **)((int)&_color_func_array + (param_2 >> 6 & 0x3c));
    goto LAB_000c2c98;
  }
  uVar12 = param_2 >> 0x13 & 0x21;
  if (uVar12 == 0x20) {
    puVar6 = &_gleVATex0FuncCopyST;
    bVar3 = true;
LAB_000c2e14:
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar8);
    iVar8 = iVar8 + iVar9 * 4;
  }
  else if (uVar12 < 0x21) {
    if (uVar12 == 1) {
      iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVATex0LoadCurrent,iVar8);
      iVar8 = iVar8 + iVar9 * 4;
      iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVATexWDivideSTQ,iVar8);
      iVar8 = iVar8 + iVar9 * 4;
      iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex0STQ,iVar8);
      iVar8 = iVar8 + iVar9 * 4;
      if (!bVar4) {
        iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVASwapTex0ST,iVar8);
        iVar8 = iVar8 + iVar9 * 4;
LAB_000c2e08:
        puVar6 = &_gleVASwapTex0Q;
        goto LAB_000c2e14;
      }
    }
  }
  else if (uVar12 == 0x21) {
    uVar12 = param_2 >> 4 & 0xf;
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)((&_tex0_func_array)[uVar12],iVar8);
    iVar8 = iVar8 + iVar9 * 4;
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(*(undefined4 *)((int)&_tex0_divide_array + (param_2 >> 4 & 0xc)),iVar8);
    iVar8 = iVar8 + iVar9 * 4;
    if (uVar12 < 0xc) {
      puVar6 = &_gleVAStoreTex0ST;
    }
    else {
      puVar6 = &_gleVAStoreTex0STQ;
    }
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar8);
    iVar8 = iVar8 + iVar9 * 4;
    if (!bVar4) {
      iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVASwapTex0ST,iVar8);
      iVar8 = iVar8 + iVar9 * 4;
      if (uVar12 >= 0xc) goto LAB_000c2e08;
    }
  }
  uVar12 = param_2 >> 0x14 & 0x21;
  if (uVar12 == 0x20) {
    puVar6 = &_gleVATex1FuncCopySTQ;
    bVar3 = true;
LAB_000c2ef0:
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar8);
    iVar8 = iVar8 + iVar9 * 4;
  }
  else if (uVar12 < 0x21) {
    if (uVar12 == 1) {
      iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVATex1LoadCurrent,iVar8);
      puVar6 = &_gleVATexWDivideSTQ;
LAB_000c2eb8:
      iVar8 = iVar8 + iVar9 * 4;
      iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar8);
      iVar8 = iVar8 + iVar9 * 4;
      iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAStoreTex1STQ,iVar8);
      iVar8 = iVar8 + iVar9 * 4;
      if (!bVar4) {
        puVar6 = &_gleVASwapTex1STQ;
        goto LAB_000c2ef0;
      }
    }
  }
  else if (uVar12 == 0x21) {
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)((&_tex1_func_array)[param_2 & 0xf],iVar8);
    puVar6 = *(undefined **)((int)&_tex1_divide_array + (param_2 & 0xc));
    goto LAB_000c2eb8;
  }
  if (bVar1) {
    puVar6 = &_gleVASingleFlushDataRTC;
LAB_000c2f20:
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar8);
    iVar8 = iVar8 + iVar9 * 4;
  }
  else if (cVar11 == '\x02') {
    puVar6 = &_gleVADoubleFlushDataRTC;
    goto LAB_000c2f20;
  }
  if (bVar3) {
    iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAIncOldDataRTC,iVar8);
    iVar8 = iVar8 + iVar9 * 4;
  }
  iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(&_gleVAEndLoopRTC,iVar8);
  iVar8 = iVar8 + iVar9 * 4;
  puVar13 = (undefined4 *)(iVar8 + -4);
  if (bVar1) {
    puVar6 = &_gleVASingleFlushDataRTC;
  }
  else {
    if (cVar11 != '\x02') goto LAB_000c2fb8;
    puVar6 = &_gleVADoubleCompleteDataRTC;
  }
  iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar8);
  iVar8 = iVar8 + iVar9 * 4;
  iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)("}`!.|",iVar8);
  iVar8 = iVar8 + iVar9 * 4;
LAB_000c2fb8:
  if ((uVar2 & 0x21) == 0x21) {
    puVar6 = &_gleVAEpilogRTC;
  }
  else {
    puVar6 = &_gleVAEpilogNoTransRTC;
  }
  iVar9 = ((int (*)())_gleRTCAddAChunk_c2458)(puVar6,iVar8);
  uVar10 = ((int (*)())_gleRTCBuildABranch_c244c)(*puVar13,iVar7 - (int)puVar13 >> 2);
  *puVar13 = uVar10;
  iVar7 = ((iVar8 + iVar9 * 4) - iVar5) + -0x20 >> 2;
  if (iVar7 < 0x181) {
    iVar5 = _gleShrinkFuncCacheElem(iVar5,iVar7);
    puVar6 = PTR__glePushInstructions_00112054;
    *(int *)(param_1 + 0x49b4) = iVar5;
    (**(code **)puVar6)(iVar7,(undefined *)(iVar5 + 0x20));
    return (undefined *)(iVar5 + 0x20);
  }
                    
  _exit(1);
}

/* _gleRTCBuildABranch_c3068 @ 0xc3068 (12 bytes) */
int _gleRTCBuildABranch_c3068(param_1, param_2)
  uint param_1;
  uint param_2;
{
  return (param_2 & 0x3fff) << 2 | param_1 & 0xffff0003;
}

/* _gleRTCAddAChunk_c3074 @ 0xc3074 (48 bytes) */
int _gleRTCAddAChunk_c3074(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return iVar2;
}

/* _gleBuildCompileFuncTCLAV @ 0xc30a4 (1992 bytes) */
int _gleBuildCompileFuncTCLAV(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  undefined **ppuVar6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  
  bVar4 = false;
  uVar14 = *(uint *)(*(int *)(param_1 + 0x468c) + 0x94);
  iVar7 = (uint)*(ushort *)(param_1 + 0x4990) * 2;
  uVar13 = *(uint *)(param_1 + 0x498c);
  uVar5 = iVar7 + 0x1fU >> 5;
  if ((*(uint *)PTR__gle_processor_0011204c & 0x40) != 0) {
    uVar5 = iVar7 + 0x7fU >> 7;
  }
  uVar5 = (uint)((uVar14 & 3) == 1) * (uVar5 & 0xff);
  bVar1 = -1 < (int)-(param_2 >> 0x12 & 0x21);
  bVar3 = false;
  if ((!bVar1) && ((uVar14 & 8) != 0)) {
    bVar3 = true;
  }
  iVar7 = _gleCreateFuncCacheElem(*(undefined4 *)(param_1 + 0x49b4),0x310);
  if (iVar7 == 0) {
    return PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar7 + 8) = param_2;
  if (*(short *)(param_1 + 0x49be) == *(short *)(param_1 + 0x49bc)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar7 + 4));
  }
  else {
    *(short *)(param_1 + 0x49be) = *(short *)(param_1 + 0x49be) + 1;
  }
  if ((*(uint *)PTR__gle_processor_0011204c & 0x40) == 0) {
    puVar8 = &_gleVAPrologNoTransAVRTC;
  }
  else {
    puVar8 = &_gleVAPrologNoTransAVRTC_128;
  }
  bVar2 = (uVar13 >> 0xf & 1) == 0;
  iVar9 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,iVar7 + 0x20);
  iVar9 = iVar7 + 0x20 + iVar9 * 4;
  if (!bVar2) {
    iVar10 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVALoadSwapVectAVRTC,iVar9);
    iVar9 = iVar9 + iVar10 * 4;
  }
  iVar10 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAStartLoopAVRTC,iVar9);
  iVar10 = iVar9 + iVar10 * 4;
  if ((param_2 >> 0x10 & 0x21) == 0x21) {
    uVar13 = param_2 >> 0xc & 0xf;
    iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)((&_vertex_load_array_av)[uVar13],iVar10);
    iVar10 = iVar10 + iVar11 * 4;
    if (bVar1) {
      if (uVar13 < 4) {
        puVar8 = &_gleVAVertFillZAV;
        goto LAB_000c3264;
      }
    }
    else {
      puVar8 = *(undefined **)((int)&_vertex_fill_array_av + (param_2 >> 0xc & 0xc));
LAB_000c3264:
      iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,iVar10);
      iVar10 = iVar10 + iVar11 * 4;
    }
    if ((*(uint *)PTR__gle_processor_0011204c & 0x40) == 0) {
      puVar8 = &_gleVAIncVertAVRTC;
    }
    else {
      puVar8 = &_gleVAIncVertAVRTC_128;
    }
    iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,iVar10);
    iVar10 = iVar10 + iVar11 * 4;
    if (!bVar2) {
      puVar8 = &_gleVASwapVertAVRTC;
      goto LAB_000c32cc;
    }
  }
  else {
    puVar8 = &_gleVALoadOldVertAVRTC;
    bVar4 = true;
LAB_000c32cc:
    iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,iVar10);
    iVar10 = iVar10 + iVar11 * 4;
  }
  if (bVar1) {
    puVar8 = &_gleVAStoreVertXYZAVRTC;
  }
  else {
    puVar8 = &_gleVAStoreVertXYZWAVRTC;
  }
  iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,iVar10);
  uVar13 = param_2 >> 0x11 & 0x21;
  iVar10 = iVar10 + iVar11 * 4;
  if (uVar13 == 0x20) {
    bVar4 = true;
    if (bVar1) {
      iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAColorLoadCopyInt12AV,iVar10);
      iVar10 = iVar10 + iVar11 * 4;
      puVar8 = &_gleVAStoreColorInt12AV;
    }
    else {
      iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAColorLoadCopyInt16AV,iVar10);
      iVar10 = iVar10 + iVar11 * 4;
      puVar8 = &_gleVAStoreColorInt16AV;
    }
LAB_000c342c:
    iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,iVar10);
    iVar10 = iVar10 + iVar11 * 4;
  }
  else if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAColorLoadCurrentAV,iVar10);
      iVar10 = iVar10 + iVar11 * 4;
      if (bVar2) {
        if (bVar1) {
          puVar8 = &_gleVAStoreColor12AV;
        }
        else {
          puVar8 = &_gleVAStoreColor16AV;
        }
      }
      else if (bVar1) {
        puVar8 = &_gleVASwapStoreColor12AV;
      }
      else {
        puVar8 = &_gleVASwapStoreColor16AV;
      }
      goto LAB_000c342c;
    }
  }
  else if (uVar13 == 0x21) {
    uVar13 = param_2 >> 6 & 0x3c;
    iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(*(undefined4 *)((int)&_color_func_array_av + uVar13),iVar10);
    iVar10 = iVar10 + iVar11 * 4;
    if (bVar2) {
      if (bVar1) {
        ppuVar6 = &_color_func_store_12av;
      }
      else {
        ppuVar6 = &_color_func_store_16av;
      }
    }
    else if (bVar1) {
      ppuVar6 = &_color_func_swap_store_12av;
    }
    else {
      ppuVar6 = &_color_func_swap_store_16av;
    }
    puVar8 = *(undefined **)(uVar13 + (int)ppuVar6);
    goto LAB_000c342c;
  }
  uVar13 = param_2 >> 0x13 & 0x21;
  if (uVar13 == 0x20) {
    bVar4 = true;
    if (bVar3) {
      puVar8 = &_gleVATex0FuncCopySTRQ20AV;
    }
    else if (bVar1) {
      puVar8 = &_gleVATex0FuncCopyST16AV;
    }
    else {
      puVar8 = &_gleVATex0FuncCopySTQ20AV;
    }
LAB_000c3584:
    iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,iVar10);
    iVar10 = iVar10 + iVar11 * 4;
  }
  else if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATex0LoadCurrentAV,iVar10);
      iVar10 = iVar10 + iVar11 * 4;
      if (!bVar2) {
        iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,iVar10);
        iVar10 = iVar10 + iVar11 * 4;
      }
      if (bVar3) goto LAB_000c3560;
LAB_000c356c:
      if (bVar1) {
        puVar8 = &_gleVAStoreTex0ST16AV;
      }
      else {
        puVar8 = &_gleVAStoreTex0STQ20AV;
      }
      goto LAB_000c3584;
    }
  }
  else if (uVar13 == 0x21) {
    uVar13 = param_2 >> 4 & 0xf;
    iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)((&_tex0_func_array_av)[uVar13],iVar10);
    iVar10 = iVar10 + iVar11 * 4;
    if (!bVar3) {
      if (!bVar1) goto LAB_000c34ac;
    }
    else {
      if (uVar13 < 8) {
        puVar8 = &_gleVATexSetRTo0AndQTo1AV;
      }
      else {
LAB_000c34ac:
        if (0xb < uVar13) goto LAB_000c34cc;
        puVar8 = &_gleVATexSetQTo1AV;
      }
      iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,iVar10);
      iVar10 = iVar10 + iVar11 * 4;
    }
LAB_000c34cc:
    if (!bVar2) {
      iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,iVar10);
      iVar10 = iVar10 + iVar11 * 4;
    }
    if (!bVar3) goto LAB_000c356c;
LAB_000c3560:
    puVar8 = &_gleVAStoreTex0STRQ20AV;
    goto LAB_000c3584;
  }
  uVar13 = param_2 >> 0x14 & 0x21;
  if (uVar13 == 0x20) {
    bVar4 = true;
    if (bVar3) {
      puVar8 = &_gleVATex1FuncCopySTRQ36AV;
    }
    else if (bVar1) {
      puVar8 = &_gleVATex1FuncCopyST24AV;
    }
    else {
      puVar8 = &_gleVATex1FuncCopySTQ32AV;
    }
LAB_000c36dc:
    iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,iVar10);
    iVar10 = iVar10 + iVar11 * 4;
  }
  else if (uVar13 < 0x21) {
    if (uVar13 == 1) {
      iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATex1FuncCurrentAV,iVar10);
      iVar10 = iVar10 + iVar11 * 4;
      if (!bVar2) {
        iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,iVar10);
        iVar10 = iVar10 + iVar11 * 4;
      }
      if (bVar3) goto LAB_000c36b8;
LAB_000c36c4:
      if (bVar1) {
        puVar8 = &_gleVAStoreTex1ST24AV;
      }
      else {
        puVar8 = &_gleVAStoreTex1STQ32AV;
      }
      goto LAB_000c36dc;
    }
  }
  else if (uVar13 == 0x21) {
    uVar13 = param_2 & 0xf;
    iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)((&_tex1_func_array_av)[uVar13],iVar10);
    iVar10 = iVar10 + iVar11 * 4;
    if (!bVar3) {
      if (!bVar1) goto LAB_000c3604;
    }
    else {
      if (uVar13 < 8) {
        puVar8 = &_gleVATexSetRTo0AndQTo1AV;
      }
      else {
LAB_000c3604:
        if (0xb < uVar13) goto LAB_000c3624;
        puVar8 = &_gleVATexSetQTo1AV;
      }
      iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,iVar10);
      iVar10 = iVar10 + iVar11 * 4;
    }
LAB_000c3624:
    if (!bVar2) {
      iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,iVar10);
      iVar10 = iVar10 + iVar11 * 4;
    }
    if (!bVar3) goto LAB_000c36c4;
LAB_000c36b8:
    puVar8 = &_gleVAStoreTex1STRQ36AV;
    goto LAB_000c36dc;
  }
  iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAIncDataAVRTC,iVar10);
  iVar10 = iVar10 + iVar11 * 4;
  if (uVar5 == 2) {
    puVar8 = &_gleVADoubleFlushDataAVRTC;
  }
  else if (uVar5 < 3) {
    if (uVar5 != 1) goto LAB_000c3774;
    if ((*(uint *)PTR__gle_processor_0011204c & 0x40) == 0) {
      puVar8 = &_gleVASingleFlushDataAVRTC;
    }
    else {
      puVar8 = &_gleVASingleFlushDataAVRTC_128;
    }
  }
  else {
    if (uVar5 != 3) goto LAB_000c3774;
    puVar8 = &_gleVATripleFlushDataAVRTC;
  }
  iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar8,iVar10);
  iVar10 = iVar10 + iVar11 * 4;
LAB_000c3774:
  if (bVar4) {
    iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAIncOldDataAVRTC,iVar10);
    iVar10 = iVar10 + iVar11 * 4;
  }
  iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAEndLoopAVRTC,iVar10);
  iVar10 = iVar10 + iVar11 * 4;
  puVar15 = (undefined4 *)(iVar10 + -4);
  if (uVar5 - 1 < 3) {
    iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVACompleteFlushDataRTC,iVar10);
    iVar10 = iVar10 + iVar11 * 4;
  }
  iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAEpilogNoTransAVRTC,iVar10);
  uVar12 = ((int (*)())_gleRTCBuildABranch_c3068)(*puVar15,iVar9 - (int)puVar15 >> 2);
  *puVar15 = uVar12;
  iVar9 = ((iVar10 + iVar11 * 4) - iVar7) + -0x20 >> 2;
  if (iVar9 < 0x311) {
    iVar7 = _gleShrinkFuncCacheElem(iVar7,iVar9);
    puVar8 = PTR__glePushInstructions_00112054;
    *(int *)(param_1 + 0x49b4) = iVar7;
    (**(code **)puVar8)(iVar9,(undefined *)(iVar7 + 0x20));
    return (undefined *)(iVar7 + 0x20);
  }
                    
  _exit(1);
}

/* _gleBuildCompileFuncAV @ 0xc386c (2036 bytes) */
int _gleBuildCompileFuncAV(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined **ppuVar8;
  int iVar9;
  undefined *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  
  bVar4 = false;
  iVar7 = (uint)((*(uint *)(*(int *)(param_1 + 0x468c) + 0x94) & 3) == 1) *
          ((uint)*(ushort *)(param_1 + 0x4990) * 2 + 0x1f >> 5 & 0xff);
  uVar5 = *(uint *)(param_1 + 0x498c);
  iVar9 = _gleCreateFuncCacheElem(*(undefined4 *)(param_1 + 0x49b4),0x310);
  if (iVar9 == 0) {
    return PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar9 + 8) = param_2;
  if (*(short *)(param_1 + 0x49be) == *(short *)(param_1 + 0x49bc)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar9 + 4));
  }
  else {
    *(short *)(param_1 + 0x49be) = *(short *)(param_1 + 0x49be) + 1;
  }
  uVar2 = param_2 >> 0x10;
  if ((uVar2 & 0x21) == 0x21) {
    puVar10 = &_gleVAPrologAVRTC;
  }
  else {
    puVar10 = &_gleVAPrologNoTransAVRTC;
  }
  uVar3 = param_2 >> 0x12;
  iVar11 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar9 + 0x20);
  uVar6 = uVar3 & 0x21;
  iVar11 = iVar9 + 0x20 + iVar11 * 4;
  if (((uVar6 != 0x20) && (0x20 < uVar6)) && (uVar6 == 0x21)) {
    uVar6 = param_2 >> 0x18 & 0xc;
    if (uVar6 == 8) {
      puVar10 = &_gleVAFogExpInitAVRTC;
LAB_000c39bc:
      iVar12 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar11);
      iVar11 = iVar11 + iVar12 * 4;
    }
    else if (uVar6 < 9) {
      if (uVar6 == 4) {
        puVar10 = &_gleVAFogLinearInitAVRTC;
        goto LAB_000c39bc;
      }
    }
    else if (uVar6 == 0xc) {
      puVar10 = &_gleVAFogExp2InitAVRTC;
      goto LAB_000c39bc;
    }
    iVar12 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAFogAllInitAVRTC,iVar11);
    iVar11 = iVar11 + iVar12 * 4;
  }
  bVar1 = (uVar5 >> 0xf & 1) == 0;
  if (!bVar1) {
    iVar12 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVALoadSwapVectAVRTC,iVar11);
    iVar11 = iVar11 + iVar12 * 4;
  }
  iVar12 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAStartLoopAVRTC,iVar11);
  iVar12 = iVar11 + iVar12 * 4;
  if (((uVar2 & 0x21) == 0x21) || ((uVar3 & 0x21) == 0x21)) {
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(*(undefined4 *)((int)&_vertex_load_array_av + (param_2 >> 10 & 0x3c)),iVar12
                       );
    iVar12 = iVar12 + iVar13 * 4;
  }
  if ((uVar3 & 0x21) == 0x20) {
    puVar10 = &_gleVAFogFuncCopyAV;
LAB_000c3b0c:
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar12);
    iVar12 = iVar12 + iVar13 * 4;
  }
  else if ((uVar3 & 0x21) == 0x21) {
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(*(undefined4 *)((int)&_vertex_fill_array_av + (param_2 >> 0xc & 0xc)),iVar12
                       );
    uVar5 = param_2 >> 0x18 & 0xc;
    iVar12 = iVar12 + iVar13 * 4;
    if (uVar5 == 8) {
      puVar10 = &_gleVAFogExpCalcAVRTC;
LAB_000c3ad8:
      iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar12);
      iVar12 = iVar12 + iVar13 * 4;
    }
    else if (uVar5 < 9) {
      if (uVar5 == 4) {
        puVar10 = &_gleVAFogLinearCalcAVRTC;
        goto LAB_000c3ad8;
      }
    }
    else if (uVar5 == 0xc) {
      puVar10 = &_gleVAFogExp2CalcAVRTC;
      goto LAB_000c3ad8;
    }
    if (bVar1) {
      puVar10 = &_gleVAFogStoreAV;
    }
    else {
      puVar10 = &_gleVAFogSwapAV;
    }
    goto LAB_000c3b0c;
  }
  if ((uVar2 & 0x21) == 0x21) {
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(*(undefined4 *)((int)&_vertex_func_array_av + (param_2 >> 0xc & 0xc)),iVar12
                       );
    iVar12 = iVar12 + iVar13 * 4;
    if ((param_2 & 0x10000000) == 0) {
      puVar10 = &_gleVALoadClipVertAVRTC;
    }
    else {
      puVar10 = &_gleVALoadVertAVRTC;
    }
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar12);
    iVar12 = iVar12 + iVar13 * 4;
    if (!bVar1) {
      puVar10 = &_gleVASwapVertAVRTC;
      goto LAB_000c3bb8;
    }
  }
  else {
    bVar4 = true;
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVALoadOldVertAVRTC,iVar12);
    iVar12 = iVar12 + iVar13 * 4;
    if (bVar1) {
      puVar10 = &_gleVASplatOOWAVRTC;
    }
    else {
      puVar10 = &_gleVASplatSwapOOWAVRTC;
    }
LAB_000c3bb8:
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar12);
    iVar12 = iVar12 + iVar13 * 4;
  }
  iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAStoreVertXYZWAVRTC,iVar12);
  uVar5 = param_2 >> 0x11 & 0x21;
  iVar12 = iVar12 + iVar13 * 4;
  if (uVar5 == 0x20) {
    bVar4 = true;
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAColorLoadCopyInt16AV,iVar12);
    iVar12 = iVar12 + iVar13 * 4;
    puVar10 = &_gleVAStoreColorInt16AV;
LAB_000c3cac:
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar12);
    iVar12 = iVar12 + iVar13 * 4;
  }
  else if (uVar5 < 0x21) {
    if (uVar5 == 1) {
      iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAColorLoadCurrentAV,iVar12);
      iVar12 = iVar12 + iVar13 * 4;
      if (bVar1) {
        puVar10 = &_gleVAStoreColor16AV;
      }
      else {
        puVar10 = &_gleVASwapStoreColor16AV;
      }
      goto LAB_000c3cac;
    }
  }
  else if (uVar5 == 0x21) {
    uVar5 = param_2 >> 6 & 0x3c;
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(*(undefined4 *)((int)&_color_func_array_av + uVar5),iVar12);
    iVar12 = iVar12 + iVar13 * 4;
    if (bVar1) {
      ppuVar8 = &_color_func_store_16av;
    }
    else {
      ppuVar8 = &_color_func_swap_store_16av;
    }
    puVar10 = *(undefined **)(uVar5 + (int)ppuVar8);
    goto LAB_000c3cac;
  }
  uVar5 = param_2 >> 0x13 & 0x21;
  if (uVar5 == 0x20) {
    bVar4 = true;
    if ((uVar3 & 0x21) == 0) {
      puVar10 = &_gleVATex0FuncCopyST20AV;
    }
    else {
      puVar10 = &_gleVATex0FuncCopyST24AV;
    }
LAB_000c3df0:
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar12);
    iVar12 = iVar12 + iVar13 * 4;
  }
  else if (uVar5 < 0x21) {
    if (uVar5 == 1) {
      iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATex0LoadCurrentAV,iVar12);
      iVar12 = iVar12 + iVar13 * 4;
      iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATexWDivideAV,iVar12);
      iVar12 = iVar12 + iVar13 * 4;
      if (!bVar1) {
        iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,iVar12);
        iVar12 = iVar12 + iVar13 * 4;
      }
LAB_000c3dd4:
      if ((uVar3 & 0x21) == 0) {
        puVar10 = &_gleVAStoreTex0AndQW20AV;
      }
      else {
        puVar10 = &_gleVAStoreTex0AndQW24AV;
      }
      goto LAB_000c3df0;
    }
  }
  else if (uVar5 == 0x21) {
    uVar5 = param_2 >> 4 & 0xf;
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)((&_tex0_func_array_av)[uVar5],iVar12);
    iVar12 = iVar12 + iVar13 * 4;
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATexWDivideAV,iVar12);
    iVar12 = iVar12 + iVar13 * 4;
    if (!bVar1) {
      iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,iVar12);
      iVar12 = iVar12 + iVar13 * 4;
    }
    if (0xb < uVar5) goto LAB_000c3dd4;
    if ((uVar3 & 0x21) == 0) {
      puVar10 = &_gleVAStoreTex0ST20AV;
    }
    else {
      puVar10 = &_gleVAStoreTex0ST24AV;
    }
    goto LAB_000c3df0;
  }
  uVar5 = param_2 >> 0x14 & 0x21;
  if (uVar5 == 0x20) {
    bVar4 = true;
    if ((uVar3 & 0x21) == 0) {
      puVar10 = &_gleVATex1FuncCopySTQ28AV;
    }
    else {
      puVar10 = &_gleVATex1FuncCopySTQ32AV;
    }
LAB_000c3ef0:
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar12);
    iVar12 = iVar12 + iVar13 * 4;
  }
  else if (uVar5 < 0x21) {
    if (uVar5 == 1) {
      puVar10 = &_gleVATex1FuncCurrentAV;
LAB_000c3e90:
      iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar12);
      iVar12 = iVar12 + iVar13 * 4;
LAB_000c3ea0:
      iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVATexWDivideAV,iVar12);
      iVar12 = iVar12 + iVar13 * 4;
      if (!bVar1) {
        iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVASwapTexAV,iVar12);
        iVar12 = iVar12 + iVar13 * 4;
      }
      if ((uVar3 & 0x21) == 0) {
        puVar10 = &_gleVAStoreTex1STQ28AV;
      }
      else {
        puVar10 = &_gleVAStoreTex1STQ32AV;
      }
      goto LAB_000c3ef0;
    }
  }
  else if (uVar5 == 0x21) {
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)((&_tex1_func_array_av)[param_2 & 0xf],iVar12);
    iVar12 = iVar12 + iVar13 * 4;
    if ((param_2 & 0xf) < 0xc) {
      puVar10 = &_gleVATexSetQTo1AV;
      goto LAB_000c3e90;
    }
    goto LAB_000c3ea0;
  }
  iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAIncDataAVRTC,iVar12);
  iVar12 = iVar12 + iVar13 * 4;
  if (iVar7 == 2) {
    puVar10 = &_gleVADoubleFlushDataAVRTC;
  }
  else {
    if (iVar7 != 3) goto LAB_000c3f50;
    puVar10 = &_gleVATripleFlushDataAVRTC;
  }
  iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar12);
  iVar12 = iVar12 + iVar13 * 4;
LAB_000c3f50:
  if (bVar4) {
    iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAIncOldDataAVRTC,iVar12);
    iVar12 = iVar12 + iVar13 * 4;
  }
  iVar13 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVAEndLoopAVRTC,iVar12);
  iVar12 = iVar12 + iVar13 * 4;
  puVar15 = (undefined4 *)(iVar12 + -4);
  if (iVar7 - 2U < 2) {
    iVar7 = ((int (*)())_gleRTCAddAChunk_c3074)(&_gleVACompleteFlushDataRTC,iVar12);
    iVar12 = iVar12 + iVar7 * 4;
  }
  if ((uVar2 & 0x21) == 0x21) {
    puVar10 = &_gleVAEpilogAVRTC;
  }
  else {
    puVar10 = &_gleVAEpilogNoTransAVRTC;
  }
  iVar7 = ((int (*)())_gleRTCAddAChunk_c3074)(puVar10,iVar12);
  uVar14 = ((int (*)())_gleRTCBuildABranch_c3068)(*puVar15,iVar11 - (int)puVar15 >> 2);
  *puVar15 = uVar14;
  iVar7 = ((iVar12 + iVar7 * 4) - iVar9) + -0x20 >> 2;
  if (iVar7 < 0x311) {
    iVar9 = _gleShrinkFuncCacheElem(iVar9,iVar7);
    puVar10 = PTR__glePushInstructions_00112054;
    *(int *)(param_1 + 0x49b4) = iVar9;
    (**(code **)puVar10)(iVar7,(undefined *)(iVar9 + 0x20));
    return (undefined *)(iVar9 + 0x20);
  }
                    
  _exit(1);
}

/* _gleEmitTransformInstructions @ 0xc4060 (1100 bytes) */
int _gleEmitTransformInstructions(param_1, param_2, param_3, param_4, param_5, param_6)
  uint *param_1;
  uint param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  uVar4 = param_5 * 0x200000 + 0x600000;
  iVar15 = 3;
  piVar11 = (int *)(param_3 + 0x3c);
  iVar13 = param_5 + 3;
  iVar12 = param_3 + 0xc;
  do {
    uVar1 = iVar15 << 1;
    iVar14 = -1;
    uVar6 = 0xc0;
    iVar10 = 3;
    uVar7 = 6;
    do {
      uVar2 = param_2 << (uVar1 & 0x3e) & uVar6;
      uVar5 = uVar2 >> (uVar7 & 0x3f);
      if (uVar5 - 1 < 2) {
        iVar14 = param_4 + iVar10;
        param_2 = param_2 | uVar6 >> (uVar1 & 0x3e);
        break;
      }
      if (((iVar10 == 3) && (param_6 != 0)) && (uVar2 == 0)) {
        uVar5 = 2;
        param_2 = param_2 | uVar6 >> (uVar1 & 0x3e);
        iVar14 = *piVar11;
        break;
      }
      iVar10 = iVar10 + -1;
      uVar6 = uVar6 << 8;
      uVar7 = uVar7 + 8;
    } while (-1 < iVar10);
    if (iVar10 == -1) {
      uVar6 = 0xc0;
      iVar10 = 3;
      do {
        if ((param_2 << (uVar1 & 0x3e) & uVar6) == 0) {
          param_2 = param_2 | uVar6 >> (uVar1 & 0x3e);
          *param_1 = uVar4 | (param_4 + iVar10) * 0x10000 |
                     *(int *)((iVar10 * 4 + iVar15) * 4 + param_3) << 6 | 0xec000032;
          param_1 = param_1 + 1;
          break;
        }
        iVar10 = iVar10 + -1;
        uVar6 = uVar6 << 8;
      } while (-1 < iVar10);
    }
    if (-1 < iVar14) {
      uVar6 = 0xc0;
      iVar10 = 3;
      uVar2 = param_4 * 0x10000 + 0x30000;
      uVar7 = param_4 * 0x800 + 0x1800;
      uVar9 = 6;
      do {
        uVar8 = (param_2 << (uVar1 & 0x3e) & uVar6) >> (uVar9 & 0x3f);
        if (uVar8 - 1 < 2) {
          param_2 = param_2 | uVar6 >> (uVar1 & 0x3e);
          if (uVar5 == 2) {
            uVar7 = uVar4 | iVar14 << 0x10 | uVar7;
            if (uVar8 == 2) {
              uVar7 = uVar4 | (param_4 + iVar10) * 0x10000 | iVar14 << 0xb | 0xec00002a;
            }
            else {
LAB_000c42a8:
              uVar7 = uVar7 | 0xec000028;
            }
            *param_1 = uVar7;
          }
          else {
            if (uVar8 == 2) {
              uVar7 = uVar4 | (param_4 + iVar10) * 0x10000 | iVar14 << 0xb;
              goto LAB_000c42a8;
            }
            *param_1 = uVar4 | uVar2 | iVar14 << 0xb | 0xec00002a;
            param_1 = param_1 + 1;
            *param_1 = uVar4 | iVar13 << 0xb | 0xfc000050;
          }
          param_1 = param_1 + 1;
          break;
        }
        iVar10 = iVar10 + -1;
        uVar6 = uVar6 << 8;
        uVar9 = uVar9 + 8;
        uVar7 = uVar7 - 0x800;
        uVar2 = uVar2 - 0x10000;
      } while (-1 < iVar10);
      if (iVar10 == -1) {
        uVar6 = 0xc0;
        iVar10 = 3;
        piVar3 = (int *)(iVar12 + 0x30);
        uVar7 = param_4 * 0x10000 + 0x30000;
        do {
          if ((param_2 << (uVar1 & 0x3e) & uVar6) == 0) {
            param_2 = param_2 | uVar6 >> (uVar1 & 0x3e);
            if (uVar5 == 2) {
              uVar1 = uVar4 | (param_4 + iVar10) * 0x10000 | iVar14 << 0xb |
                      *(int *)((iVar10 * 4 + iVar15) * 4 + param_3) << 6 | 0xec00003a;
            }
            else {
              uVar1 = uVar4 | uVar7 | iVar14 << 0xb | *piVar3 << 6 | 0xec000038;
            }
            *param_1 = uVar1;
            param_1 = param_1 + 1;
            break;
          }
          iVar10 = iVar10 + -1;
          uVar6 = uVar6 << 8;
          uVar7 = uVar7 - 0x10000;
          piVar3 = piVar3 + -4;
        } while (-1 < iVar10);
        if (iVar10 == -1) {
          if (uVar5 == 2) {
            uVar1 = uVar4 | iVar14 << 0xb | 0xfc000090;
          }
          else {
            uVar1 = uVar4 | iVar14 << 0xb | 0xfc000050;
          }
          *param_1 = uVar1;
          param_1 = param_1 + 1;
        }
      }
    }
    iVar15 = iVar15 + -1;
    iVar12 = iVar12 + -4;
    iVar13 = iVar13 + -1;
    uVar4 = uVar4 - 0x200000;
    piVar11 = piVar11 + -1;
    if (iVar15 < 0) {
      iVar12 = 0;
      do {
        iVar10 = 3;
        iVar15 = param_5 + 3;
        iVar13 = param_3 + 0xc;
        do {
          uVar2 = param_4 * 0x800 + 0x1800;
          uVar5 = iVar15 << 0x15 | iVar15 << 0x10;
          uVar1 = 0xc0;
          iVar14 = 3;
          uVar4 = iVar10 << 1;
          uVar7 = 6;
          uVar6 = uVar2;
          do {
            uVar9 = (param_2 << (uVar4 & 0x3e) & uVar1) >> (uVar7 & 0x3f);
            if (uVar9 - 1 < 2) {
              param_2 = param_2 | uVar1 >> (uVar4 & 0x3e);
              if (uVar9 == 2) {
                uVar1 = uVar5 | uVar6 | 0xec00002a;
              }
              else {
                uVar1 = uVar5 | uVar2 | 0xec000028;
              }
              *param_1 = uVar1;
              param_1 = param_1 + 1;
              break;
            }
            iVar14 = iVar14 + -1;
            uVar1 = uVar1 << 8;
            uVar7 = uVar7 + 8;
            uVar6 = uVar6 - 0x800;
            uVar2 = uVar2 - 0x800;
          } while (-1 < iVar14);
          if (iVar14 == -1) {
            uVar1 = 0xc0;
            iVar14 = 3;
            piVar11 = (int *)(iVar13 + 0x30);
            uVar6 = param_4 * 0x10000 + 0x30000;
            do {
              if ((param_2 << (uVar4 & 0x3e) & uVar1) == 0) {
                param_2 = param_2 | uVar1 >> (uVar4 & 0x3e);
                *param_1 = iVar15 << 0x15 | uVar6 | iVar15 << 0xb | *piVar11 << 6 | 0xec00003a;
                param_1 = param_1 + 1;
                break;
              }
              iVar14 = iVar14 + -1;
              uVar1 = uVar1 << 8;
              uVar6 = uVar6 - 0x10000;
              piVar11 = piVar11 + -4;
            } while (-1 < iVar14);
          }
          iVar10 = iVar10 + -1;
          iVar13 = iVar13 + -4;
          iVar15 = iVar15 + -1;
        } while (-1 < iVar10);
        iVar12 = iVar12 + 1;
        if (2 < iVar12) {
          return param_1;
        }
      } while( true );
    }
  } while( true );
}

/* _gleRTCBuildABranch_c44ac @ 0xc44ac (12 bytes) */
int _gleRTCBuildABranch_c44ac(param_1, param_2)
  uint param_1;
  uint param_2;
{
  return (param_2 & 0x3fff) << 2 | param_1 & 0xffff0003;
}

/* _gleRTCAddAChunk_c44b8 @ 0xc44b8 (48 bytes) */
int _gleRTCAddAChunk_c44b8(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return iVar2;
}

/* _gleSetModelviewFuncAll @ 0xc44e8 (100 bytes) */
void _gleSetModelviewFuncAll(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)(*_gleBuildModelviewTransformFunc)(param_1,0,param_3);
  *(code **)(param_1 + 0x5064) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3);
  return;
}

/* _gleSetModelviewFuncW1 @ 0xc454c (100 bytes) */
void _gleSetModelviewFuncW1(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)(*_gleBuildModelviewTransformFunc)(param_1,1,param_3);
  *(code **)(param_1 + 0x5064) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3);
  return;
}

/* _gleSetModelviewFuncZ0W1 @ 0xc45b0 (100 bytes) */
void _gleSetModelviewFuncZ0W1(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)(*_gleBuildModelviewTransformFunc)(param_1,3,param_3);
  *(code **)(param_1 + 0x5064) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3);
  return;
}

/* _gleTransformModelviewBlend @ 0xc4614 (76 bytes) */
void _gleTransformModelviewBlend(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 + param_3 * 0x100;
  if (uVar1 <= param_2) {
    return;
  }
  uVar1 = (uVar1 - param_2) + 0xff >> 8;
  do {
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_2 + 0xf0);
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_2 + 0xf4);
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_2 + 0xf8);
    *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(param_2 + 0xfc);
    param_2 = param_2 + 0x100;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}

/* FUN_000c4664 @ 0xc4664 (1236 bytes) */
int FUN_000c4664(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  
  if (*(char *)(param_1 + 0x4661) != '\0') {
    return (int *)PTR__gleTransformModelviewBlend_001109f8;
  }
  uVar2 = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(param_1,param_1 + 0x1cc0);
  *(uint *)(param_1 + 0x5090) = uVar2;
  uVar11 = uVar2;
  if (((param_2 & 2) != 0) && (uVar11 = uVar2 | 0xff00, (uVar2 & 0xc0c000c) == 0xc0c000c)) {
    uVar11 = uVar2 & 0xffff00ff | 0xfb00;
  }
  uVar2 = param_2 | *(ushort *)(param_1 + 0x4fe8);
  if (*(short *)(0x3170 + param_1 + 4) == 0x1102) {
    uVar2 = uVar2 | 0x20;
  }
  if ((*(byte *)(param_1 + 0x50b4) & 1) == 0) {
    if ((uVar2 & 0x10) == 0) {
      uVar11 = uVar11 & 0xc0c0c0c | 0xb3e3f3f2;
    }
    else {
      uVar11 = 0xbfeffbfe;
    }
  }
  uVar1 = uVar11;
  if ((uVar11 != 0xbfeffbfe) && (uVar1 = 0x3fcff3fc, (uVar11 & 0x3fcff3fc) != 0x3fcff3fc)) {
    uVar1 = 0;
  }
  piVar12 = *(int **)(param_1 + 0x5094);
  piVar13 = piVar12;
  do {
    if (uVar1 == piVar13[2] && uVar2 == piVar13[3]) {
      if (piVar13 != piVar12) {
        _gleMoveFuncCacheElem(piVar12,piVar13);
        *(int **)(param_1 + 0x5094) = piVar13;
      }
      return piVar13 + 8;
    }
    piVar13 = (int *)*piVar13;
  } while (piVar13 != piVar12);
  iVar3 = _gleCreateFuncCacheElem(piVar13,0x70);
  if (iVar3 == 0) {
    return (int *)PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar3 + 8) = uVar1;
  *(uint *)(iVar3 + 0xc) = uVar2;
  if (*(short *)(param_1 + 0x509a) == *(short *)(param_1 + 0x5098)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar3 + 4));
  }
  else {
    *(short *)(param_1 + 0x509a) = *(short *)(param_1 + 0x509a) + 1;
  }
  puVar9 = (undefined4 *)(iVar3 + 0x20);
  if ((uVar1 == 0xbfeffbfe) && ((uVar2 & 0xc) == 0)) goto LAB_000c4ac0;
  uVar11 = uVar2 & 0xc;
  iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_glePrologAVRTC,puVar9);
  puVar8 = puVar9 + iVar4;
  if (uVar1 != 0xbfeffbfe) {
    iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadMatrixPtrRTC,puVar8);
    if ((uVar2 & 2) == 0) {
      puVar5 = &_gleLoadMatrixVectorsRTC;
    }
    else {
      puVar5 = &_gleLoadMatrixVectorsZ0RTC;
    }
    iVar6 = ((int (*)())_gleRTCAddAChunk_c44b8)(puVar5,puVar8 + iVar4);
    puVar8 = puVar8 + iVar4 + iVar6;
  }
  if (uVar11 == 8) {
    puVar5 = &_gleFogExpInitAVRTC;
LAB_000c48cc:
    iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(puVar5,puVar8);
    puVar8 = puVar8 + iVar4;
  }
  else if (uVar11 < 9) {
    if (uVar11 == 4) {
      puVar5 = &_gleFogLinearInitAVRTC;
      goto LAB_000c48cc;
    }
  }
  else if (uVar11 == 0xc) {
    puVar5 = &_gleFogExp2InitAVRTC;
    goto LAB_000c48cc;
  }
  if (uVar1 == 0) {
    iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadVectorsRTC,puVar8);
    puVar9 = puVar8 + iVar4;
    if ((uVar2 & 1) == 0) {
      if ((uVar2 & 2) == 0) {
        puVar5 = &_gleFullMatrixMultRTC;
      }
      else {
        puVar5 = &_gleFullMatrixMultZ0RTC;
      }
    }
    else if ((uVar2 & 2) == 0) {
      puVar5 = &_gleFullMatrixMultW1RTC;
    }
    else {
      puVar5 = &_gleFullMatrixMultZ0W1RTC;
    }
LAB_000c4998:
    iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(puVar5,puVar9);
    iVar6 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleStoreVectorsRTC,puVar9 + iVar4);
    puVar10 = puVar9 + iVar4 + iVar6;
  }
  else {
    puVar10 = puVar8;
    if (uVar1 == 0x3fcff3fc) {
      iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleDiagMatrixSetupRTC,puVar8);
      puVar8 = puVar8 + iVar4;
      iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadVectorsRTC,puVar8);
      puVar9 = puVar8 + iVar4;
      puVar5 = &_gleDiagMatrixMultRTC;
      goto LAB_000c4998;
    }
  }
  if (uVar11 != 0) {
    if ((uVar2 & 0x10) == 0) {
      if (uVar1 == 0xbfeffbfe) {
        iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadVectorsToDstRTC,puVar10);
        puVar10 = puVar10 + iVar4;
      }
      if ((uVar2 & 0x20) == 0) goto LAB_000c4a24;
      puVar5 = &_gleFogStoreCoordAVRTC;
    }
    else {
      puVar5 = &_gleFogLoadCoordAVRTC;
    }
    iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(puVar5,puVar10);
    puVar10 = puVar10 + iVar4;
  }
LAB_000c4a24:
  if (uVar11 == 8) {
    puVar5 = &_gleFogExpAVRTC;
LAB_000c4a68:
    iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(puVar5,puVar10);
    puVar10 = puVar10 + iVar4;
  }
  else if (uVar11 < 9) {
    if (uVar11 == 4) {
      puVar5 = &_gleFogLinearAVRTC;
      goto LAB_000c4a68;
    }
  }
  else if (uVar11 == 0xc) {
    puVar5 = &_gleFogExp2AVRTC;
    goto LAB_000c4a68;
  }
  iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleIncVertex2PtrRTC,puVar10);
  puVar10 = puVar10 + iVar4;
  iVar4 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleEpilogAVRTC,puVar10);
  puVar9 = puVar10 + iVar4;
  uVar7 = ((int (*)())_gleRTCBuildABranch_c44ac)(*puVar10,(int)puVar8 - (int)puVar10 >> 2);
  *puVar10 = uVar7;
LAB_000c4ac0:
  iVar4 = (int)puVar9 + (-0x1c - iVar3) >> 2;
  *puVar9 = 0x4e800020;
  if (iVar4 < 0x71) {
    iVar3 = _gleShrinkFuncCacheElem(iVar3,iVar4);
    puVar5 = PTR__glePushInstructions_00112054;
    *(int *)(param_1 + 0x5094) = iVar3;
    (**(code **)puVar5)(iVar4,(int *)(iVar3 + 0x20));
    return (int *)(iVar3 + 0x20);
  }
                    
  _exit(1);
}

/* _gleBuildModelviewTransformFuncNO @ 0xc4b38 (1852 bytes) */
int _gleBuildModelviewTransformFuncNO(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int *piVar13;
  uint uVar14;
  uint *puVar15;
  uint *puVar16;
  uint *puVar17;
  int iVar18;
  int local_70 [15];
  int local_34;
  
  if (*(char *)(param_1 + 0x4661) != '\0') {
    return (int *)PTR__gleTransformModelviewBlend_001109f8;
  }
  uVar3 = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(param_1,param_1 + 0x1cc0);
  *(uint *)(param_1 + 0x5090) = uVar3;
  uVar14 = uVar3;
  if (((param_2 & 2) != 0) && (uVar14 = uVar3 | 0xff00, (uVar3 & 0xc0c000c) == 0xc0c000c)) {
    uVar14 = uVar3 & 0xffff00ff | 0xfb00;
  }
  uVar3 = param_2 | *(ushort *)(param_1 + 0x4fe8);
  if (*(short *)(0x3170 + param_1 + 4) == 0x1102) {
    uVar3 = uVar3 | 0x20;
  }
  if ((*(byte *)(param_1 + 0x50b4) & 1) == 0) {
    if ((uVar3 & 0x10) == 0) {
      uVar14 = uVar14 & 0xc0c0c0c | 0xb3e3f3f2;
    }
    else {
      uVar14 = 0xbfeffbfe;
    }
  }
  piVar12 = *(int **)(param_1 + 0x5094);
  piVar13 = piVar12;
  do {
    if (uVar14 == piVar13[2] && uVar3 == piVar13[3]) {
      if (piVar13 != piVar12) {
        _gleMoveFuncCacheElem(piVar12,piVar13);
        *(int **)(param_1 + 0x5094) = piVar13;
      }
      return piVar13 + 8;
    }
    piVar13 = (int *)*piVar13;
  } while (piVar13 != piVar12);
  iVar4 = _gleCreateFuncCacheElem(piVar13,0x60);
  if (iVar4 == 0) {
    return (int *)PTR__gleRTCNoop_00112058;
  }
  *(uint *)(iVar4 + 8) = uVar14;
  *(uint *)(iVar4 + 0xc) = uVar3;
  if (*(short *)(param_1 + 0x509a) == *(short *)(param_1 + 0x5098)) {
    ((void (*)())_gleDeleteFuncCacheElem)(*(undefined4 *)(iVar4 + 4));
  }
  else {
    *(short *)(param_1 + 0x509a) = *(short *)(param_1 + 0x509a) + 1;
  }
  puVar16 = (uint *)(iVar4 + 0x20);
  if ((uVar14 == 0xbfeffbfe) && ((uVar3 & 0xc) == 0)) goto LAB_000c5204;
  uVar11 = uVar3 & 0xc;
  iVar8 = 8;
  if (uVar11 == 8) {
LAB_000c4cfc:
    iVar8 = 0xe;
  }
  else if (uVar11 < 9) {
    if (uVar11 == 4) {
      iVar8 = 0xc;
    }
  }
  else if (uVar11 == 0xc) goto LAB_000c4cfc;
  uVar10 = 0;
  iVar18 = 0x10;
  bVar1 = false;
  uVar6 = 0;
  piVar13 = local_70;
  do {
    if ((uVar14 << ((uVar6 & 0x1f) << 1) & 0xc0000000) == 0) {
      *piVar13 = iVar8;
      bVar1 = true;
      if (0xd < iVar8) {
        uVar10 = uVar10 - 8;
        *puVar16 = iVar8 << 0x15 | uVar10 & 0xffff | 0xd8010000;
        puVar16 = puVar16 + 1;
      }
      iVar8 = iVar8 + 1;
    }
    uVar6 = uVar6 + 1;
    piVar13 = piVar13 + 1;
    iVar18 = iVar18 + -1;
  } while (iVar18 != 0);
  if (bVar1) {
    iVar8 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadMatrixPtrRTC,puVar16);
    puVar16 = puVar16 + iVar8;
  }
  iVar8 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleLoadCounterRTC,puVar16);
  puVar17 = puVar16 + iVar8;
  uVar10 = 0;
  uVar6 = 0;
  iVar8 = 0x10;
  do {
    if ((uVar14 << (uVar6 & 0x3f) & 0xc0000000) == 0) {
      *puVar17 = *(int *)((int)local_70 + uVar10) << 0x15 | uVar10 & 0xffff | 0xc0060000;
      puVar17 = puVar17 + 1;
    }
    uVar6 = uVar6 + 2;
    uVar10 = uVar10 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 4;
  uVar6 = 0;
  uVar7 = 3;
  uVar10 = 0xe00000;
  do {
    if ((uVar14 << ((uVar7 & 0x1f) << 1) & 0xc0c0c0c0) == 0xc0c0c0c0) {
      if (uVar6 == 0) {
        uVar2 = uVar10 | 0xc0030020;
        uVar6 = uVar7;
      }
      else {
        uVar2 = uVar10 | (uVar6 + 4) * 0x800 | 0xfc000090;
      }
      *puVar17 = uVar2;
      puVar17 = puVar17 + 1;
    }
    uVar7 = uVar7 - 1;
    uVar10 = uVar10 - 0x200000;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  uVar6 = uVar14;
  if ((uVar3 & 1) == 0) {
    uVar10 = 3;
  }
  else {
    uVar10 = uVar14 & 0x3030303;
    if (uVar10 == 0x3030302) {
LAB_000c4ee8:
      uVar7 = 1;
      uVar6 = uVar14 | 0x3030303;
    }
    else if (uVar10 == 0x3030301) {
      *puVar17 = 0xc064002c;
      puVar17[1] = 0xfce01850;
      uVar7 = 4;
      puVar17 = puVar17 + 2;
      uVar6 = uVar14 | 0x3030303;
    }
    else {
      uVar7 = 0;
      if (uVar10 == 0x3030300) {
        *puVar17 = local_34 << 0xb | 0xfce00090;
        puVar17 = puVar17 + 1;
        goto LAB_000c4ee8;
      }
    }
    if (uVar7 < 4) {
      do {
        if ((uVar6 >> ((uVar7 & 0x1f) << 1) & 3) - 1 < 2) {
          *puVar17 = 0xc064002c;
          puVar17 = puVar17 + 1;
          break;
        }
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < 4);
    }
    uVar10 = 2;
  }
  if (uVar11 == 8) {
LAB_000c4f70:
    puVar5 = &_gleFogExpInitRTC;
LAB_000c4f78:
    iVar8 = ((int (*)())_gleRTCAddAChunk_c44b8)(puVar5,puVar17);
    puVar17 = puVar17 + iVar8;
  }
  else if (uVar11 < 9) {
    if (uVar11 == 4) {
      puVar5 = &_gleFogLinearInitRTC;
      goto LAB_000c4f78;
    }
  }
  else if (uVar11 == 0xc) goto LAB_000c4f70;
  uVar2 = uVar10 * 10;
  uVar7 = uVar10 * 4 + 0x20;
  puVar16 = puVar17;
  do {
    uVar9 = 0xc0c0c0c0 >> ((uVar10 & 0x1f) << 1);
    if (((uVar6 & uVar9) == (uVar9 & ~(0x40000000 >> (uVar2 & 0x3f)))) &&
       (((uVar10 != 2 || (uVar11 == 0)) || ((uVar3 & 0x10) != 0)))) {
      uVar6 = uVar6 | uVar9;
    }
    uVar9 = 0xff000000 >> ((uVar10 & 7) << 3);
    if ((uVar6 & uVar9) != uVar9) {
      *puVar16 = uVar10 << 0x15 | uVar7 & 0xffff | 0xc0040000;
      puVar16 = puVar16 + 1;
    }
    uVar10 = uVar10 - 1;
    uVar2 = uVar2 - 10;
    uVar7 = uVar7 - 4;
  } while (-1 < (int)uVar10);
  puVar16 = (uint *)((int (*)())_gleEmitTransformInstructions)(puVar16,uVar6,local_70,0,4,uVar3 & 1);
  iVar8 = 4;
  uVar7 = 3;
  uVar6 = 0x2c;
  uVar10 = 0xe00000;
  uVar2 = 0x1e;
  do {
    uVar9 = 0xc0c0c0c0 >> ((uVar7 & 0x1f) << 1);
    if ((uVar14 & uVar9) != (uVar9 & ~(0x40000000 >> (uVar2 & 0x3f)))) {
      *puVar16 = uVar10 | uVar6 & 0xffff | 0xd0040000;
      puVar16 = puVar16 + 1;
    }
    uVar7 = uVar7 - 1;
    uVar2 = uVar2 - 10;
    uVar10 = uVar10 - 0x200000;
    uVar6 = uVar6 - 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if ((uVar3 & 0x10) == 0) {
    if ((uVar3 & 0x20) != 0) {
      puVar5 = &_gleFogStoreCoordRTC;
      goto LAB_000c50d8;
    }
  }
  else {
    puVar5 = &_gleFogLoadCoordRTC;
LAB_000c50d8:
    iVar8 = ((int (*)())_gleRTCAddAChunk_c44b8)(puVar5,puVar16);
    puVar16 = puVar16 + iVar8;
  }
  if (uVar11 == 8) {
    if ((*(uint *)PTR__gle_processor_0011204c & 1) == 0) {
      puVar5 = &_gleFogExpNORTC;
    }
    else {
      puVar5 = &_gleFogExpGRRTC;
    }
LAB_000c516c:
    iVar8 = ((int (*)())_gleRTCAddAChunk_c44b8)(puVar5,puVar16);
    puVar16 = puVar16 + iVar8;
  }
  else if (uVar11 < 9) {
    if (uVar11 == 4) {
      puVar5 = &_gleFogLinearNORTC;
      goto LAB_000c516c;
    }
  }
  else if (uVar11 == 0xc) {
    if ((*(uint *)PTR__gle_processor_0011204c & 1) == 0) {
      puVar5 = &_gleFogExp2NORTC;
    }
    else {
      puVar5 = &_gleFogExp2GRRTC;
    }
    goto LAB_000c516c;
  }
  uVar11 = 0;
  iVar8 = ((int (*)())_gleRTCAddAChunk_c44b8)(&_gleEndLoopRTC,puVar16);
  uVar3 = 0;
  puVar16 = puVar16 + iVar8;
  piVar13 = local_70;
  puVar15 = puVar16 + -1;
  iVar8 = 0x10;
  do {
    if (((uVar14 << ((uVar3 & 0x1f) << 1) & 0xc0000000) == 0) && (0xd < *piVar13)) {
      uVar11 = uVar11 - 8;
      *puVar16 = *piVar13 << 0x15 | uVar11 & 0xffff | 0xc8010000;
      puVar16 = puVar16 + 1;
    }
    uVar3 = uVar3 + 1;
    piVar13 = piVar13 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  uVar14 = ((int (*)())_gleRTCBuildABranch_c44ac)(*puVar15,(int)puVar17 - (int)puVar15 >> 2);
  *puVar15 = uVar14;
LAB_000c5204:
  iVar8 = (int)puVar16 + (-0x1c - iVar4) >> 2;
  *puVar16 = 0x4e800020;
  if (iVar8 < 0x61) {
    iVar4 = _gleShrinkFuncCacheElem(iVar4,iVar8);
    puVar5 = PTR__glePushInstructions_00112054;
    *(int *)(param_1 + 0x5094) = iVar4;
    (**(code **)puVar5)(iVar8,(int *)(iVar4 + 0x20));
    return (int *)(iVar4 + 0x20);
  }
                    
  _exit(1);
}

