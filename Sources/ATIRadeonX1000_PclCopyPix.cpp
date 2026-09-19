/*
 * ATIRadeonX1000_PclCopyPix.cpp
 *
 * RESOLVED (ledger pass): pcl_CopyPix (real addr 0x21e30, 5260 bytes) - builds the R500 3D-blit command stream for a
 * software "copy pixels" request described by a pcl_ParamsR500_t (source/destination surface descriptors, rectangles,
 * flags): copies the r500 3D-blit state packet into `cmd`, patches in the destination colour buffer (address, pitch,
 * size, format) and source texture (address, size, pitch, format) words, emits the viewport/scissor floats and one or
 * more textured quads (large or scaled copies are split into strips), and returns the pointer one past the last word
 * written. param_3 flips vertically, param_4 selects the alternate-buffer variant.
 *
 * Transcribed mechanically from the decompile (Tools/ghidra2cpp.py, Headers/GhidraCompat.h; conventions as in
 * ATIR500Surface_BuildSwap.cpp). pcl_ParamsR500_t's layout was never recovered as a struct: the body reads it at raw
 * offsets through the byte pointer `param_2`.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

struct pcl_ParamsR500_t;
extern "C" const r500_3d_blit_state_packet_struct _g_r500_3d_blit_state_packet;

UInt32 *pcl_CopyPix(UInt32 *param_1, pcl_ParamsR500_t *params, bool param_3, bool param_4) {
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(params);

  bool bVar1;
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
  UInt32 uVar23;
  SInt32 iVar24;
  SInt32 iVar25;
  UInt32 uVar26;
  UInt32 uVar27;
  UInt32 uVar28;
  UInt32 *puVar29;
  UInt32 uVar30;
  SInt32 iVar31;
  SInt32 iVar32;
  UInt32 uVar33;
  UInt32 uVar34;
  UInt32 in_register_00000014;
  UInt32 in_register_00000018;
  UInt32 uVar35;
  UInt32 uVar36;
  UInt32 *puVar37;
  UInt32 uVar38;
  UInt32 uVar39;
  UInt32 uVar40;
  UInt32 uVar41;
  UInt32 uVar42;
  UInt32 uVar43;
  SInt16 *psVar44;
  UInt32 uVar45;
  double dVar46;
  double dVar47;
  double dVar48;
  double dVar49;
  double dVar50;
  double dVar51;
  
  iVar32 = ((UInt32)param_4);
  dVar49 = (double)FLOAT_0004c370;
  dVar51 = (double)M<float>(param_2 + 0x6c);
  psVar44 = M<SInt16 *>(param_2 + 0x50);
  dVar50 = (double)M<float>(param_2 + 0x70);
  if (dVar51 != dVar49) {
    dVar49 = (double)(float)((double)FLOAT_0004c374 / dVar51);
  }
  dVar48 = (double)FLOAT_0004c370;
  if (dVar50 != dVar48) {
    dVar48 = (double)(float)((double)FLOAT_0004c374 / dVar50);
  }
  GCopy(param_1,(&_g_r500_3d_blit_state_packet),0x2f4);
  uVar38 = param_1[0xa2];
  iVar31 = 0xbd;
  param_1[0xa0] = M<UInt32>(param_2);
  param_1[0xa6] = M<UInt32>(param_2 + 4);
  param_1[0xa8] = M<UInt32>(param_2 + 8);
  param_1[0xaa] = M<UInt32>(param_2 + 0xc);
  param_1[0x9c] = M<UInt32>(param_2 + 0x14);
  param_1[0x9a] = M<UInt32>(param_2 + 0x18);
  param_1[0x8a] = M<UInt32>(param_2 + 0x1c);
  param_1[0xb2] = M<UInt32>(param_2 + 0x20);
  param_1[0xb3] = M<UInt32>(param_2 + 0x24);
  param_1[0xb] = M<UInt32>(param_2 + 0x28);
  uVar23 = M<UInt32>(param_2 + 0x10);
  param_1[0xa2] = uVar23 & 0x600 | uVar38 & 0xfffff9ff;
  param_1[0xa2] = M<UInt32>(param_2 + 0x10) & 0x1800 | uVar23 & 0x600 | uVar38 & 0xffffe1ff;
  if (M<SInt32>(param_2 + 0x88) != 0) {
    param_1[0x1e] = param_1[0x1e] & 0xfffffffc | 2;
  }
  dVar46 = DOUBLE_0004c3a8;
  fVar2 = FLOAT_0004c37c;
  fVar4 = FLOAT_0004c370;
  if (((double)FLOAT_0004c378 < dVar51) || ((double)FLOAT_0004c378 < dVar50)) {
    bVar1 = ((UInt32)param_3) != 0;
    if ((bVar1) || (dVar51 <= (double)FLOAT_0004c378)) {
      fVar4 = M<float>(param_2 + 0x5c);
      fVar2 = M<float>(param_2 + 0x54);
      fVar5 = M<float>(param_2 + 0x58);
      fVar6 = M<float>(param_2 + 0x60);
      fVar7 = fVar2 + fVar4;
      fVar3 = fVar5 + fVar6;
      fVar8 = FLOAT_0004c370;
      if (fVar4 != FLOAT_0004c370) {
        fVar8 = (float)((double)CONCAT44d(0x43300000,(SInt32)psVar44[2] ^ 0x80000000) - DOUBLE_0004c3a8)
                / fVar4;
      }
      fVar4 = (float)((double)CONCAT44d(0x43300000,(SInt32)*psVar44 ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar9 = -(fVar8 * fVar2 - fVar4);
      fVar10 = FLOAT_0004c370;
      if (fVar6 != FLOAT_0004c370) {
        fVar10 = (float)((double)CONCAT44d(0x43300000,(SInt32)psVar44[3] ^ 0x80000000) - DOUBLE_0004c3a8
                        ) / fVar6;
      }
      fVar6 = (float)((double)CONCAT44d(0x43300000,(SInt32)psVar44[1] ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar18 = -(fVar5 * fVar10 - fVar6);
      if (iVar32 != 0) {
        fVar10 = -fVar10;
        fVar18 = (float)((double)CONCAT44d(0x43300000,(SInt32)psVar44[1] + (SInt32)psVar44[3] ^ 0x80000000)
                        - DOUBLE_0004c3a8) - (fVar18 - fVar6);
      }
      if (bVar1) {
        fVar8 = -fVar8;
        fVar9 = (float)((double)CONCAT44d(0x43300000,(SInt32)*psVar44 + (SInt32)psVar44[2] ^ 0x80000000) -
                       DOUBLE_0004c3a8) - (fVar9 - fVar4);
      }
      uVar38 = (SInt32)dVar51 & 0xffff;
      uVar23 = (SInt32)dVar50 & 0xffff;
      if ((uVar38 < 0x1001) && (uVar23 < 0x1001)) {
        uVar26 = 0;
        uVar30 = 0;
        uVar39 = 0;
        uVar27 = 0;
        uVar40 = 0;
        fVar14 = FLOAT_0004c370;
        fVar6 = FLOAT_0004c370;
        fVar16 = FLOAT_0004c370;
        fVar19 = FLOAT_0004c370;
      }
      else {
        fVar14 = fVar10 * fVar5 + fVar18;
        fVar16 = fVar10 * fVar3 + fVar18;
        fVar4 = fVar2 * fVar8 + fVar9;
        fVar6 = fVar7 * fVar8 + fVar9;
        fVar19 = fVar14;
        if (fVar16 < fVar14) {
          fVar19 = fVar16;
          fVar16 = fVar14;
        }
        fVar14 = fVar4;
        if (fVar6 < fVar4) {
          fVar14 = fVar6;
          fVar6 = fVar4;
        }
        uVar27 = (SInt32)dVar51 & 0xfe00;
        uVar40 = (SInt32)fVar14 - 1;
        uVar40 = (((SInt32)uVar40 >> 9) + (UInt32)((SInt32)uVar40 < 0 && (uVar40 & 0x1ff) != 0)) * 0x200;
        uVar30 = 0;
        if ((-1 < (SInt32)uVar40) && (uVar30 = uVar27, (SInt32)uVar40 <= (SInt32)uVar27)) {
          uVar30 = uVar40 & 0xfe00;
        }
        uVar40 = 0x40;
        if ((0x40 < uVar23) && (uVar40 = (SInt32)dVar50 & 0xffc0, (SInt32)(uVar23 - uVar40) < 0x40)) {
          uVar40 = uVar40 - 0x40;
        }
        uVar26 = 0;
        uVar27 = (SInt32)fVar19 - 1;
        uVar27 = (((SInt32)uVar27 >> 6) + (UInt32)((SInt32)uVar27 < 0 && (uVar27 & 0x3f) != 0)) * 0x40;
        if ((-1 < (SInt32)uVar27) && (uVar26 = uVar40 & 0xffff, (SInt32)uVar27 <= (SInt32)uVar40)) {
          uVar26 = uVar27 & 0xffc0;
        }
        uVar40 = 0x200;
        if (0x1ff < uVar30) {
          uVar40 = uVar30;
        }
        uVar27 = uVar38 - 1;
        uVar39 = (((SInt32)uVar27 >> 9) + (UInt32)((SInt32)uVar27 < 0 && (uVar27 & 0x1ff) != 0)) * 0x200;
        uVar27 = (UInt32)fVar6;
        if ((FLOAT_0004c370 < fVar6) &&
           ((float)((double)CONCAT44d(0x43300000,uVar27 ^ 0x80000000) - DOUBLE_0004c3a8) < fVar6)) {
          uVar27 = uVar27 + 1;
        }
        if ((SInt32)uVar27 <= (SInt32)uVar39) {
          uVar39 = uVar27;
        }
        uVar27 = 1;
        if ((SInt32)uVar40 < (SInt32)uVar39) {
          uVar27 = (SInt32)((uVar39 - uVar40) + 0xbff) / 0xc00 & 0xff;
        }
        uVar40 = 0x40;
        if (0x3f < uVar26) {
          uVar40 = uVar26;
        }
        uVar39 = uVar23 - 1;
        uVar33 = (((SInt32)uVar39 >> 6) + (UInt32)((SInt32)uVar39 < 0 && (uVar39 & 0x3f) != 0)) * 0x40;
        uVar39 = (UInt32)fVar16;
        if ((FLOAT_0004c370 < fVar16) &&
           ((float)((double)CONCAT44d(0x43300000,uVar39 ^ 0x80000000) - DOUBLE_0004c3a8) < fVar16)) {
          uVar39 = uVar39 + 1;
        }
        if ((SInt32)uVar39 <= (SInt32)uVar33) {
          uVar33 = uVar39;
        }
        uVar39 = 1;
        if ((SInt32)uVar40 < (SInt32)uVar33) {
          uVar39 = (SInt32)((uVar33 - uVar40) + 0xf7f) / 0xf80 & 0xff;
        }
        uVar40 = uVar39 * uVar27 & 0xff;
      }
      puVar29 = param_1 + 0xbd;
      if (uVar40 != 0) {
        fVar4 = FLOAT_0004c370;
        if (fVar8 != FLOAT_0004c370) {
          fVar4 = FLOAT_0004c374 / fVar8;
        }
        fVar2 = FLOAT_0004c370;
        if (fVar10 != FLOAT_0004c370) {
          fVar2 = FLOAT_0004c374 / fVar10;
        }
        if (uVar39 != 0) {
          uVar33 = uVar23 - uVar26;
          uVar43 = 0;
          iVar32 = 0;
          uVar36 = uVar26;
          puVar37 = puVar29;
          do {
            if (uVar27 != 0) {
              uVar42 = uVar26 + iVar32;
              uVar34 = uVar38 - uVar30;
              iVar31 = 0;
              fVar5 = (float)((double)CONCAT44d(0x43300000,uVar42 ^ 0x80000000) - DOUBLE_0004c3a8);
              uVar35 = uVar30;
              uVar45 = uVar27;
              do {
                *puVar37 = uVar35;
                puVar37[1] = uVar36;
                uVar28 = uVar34;
                if ((SInt32)(uVar35 + 0x1000) <= (SInt32)uVar38) {
                  uVar28 = 0x1000;
                }
                uVar41 = uVar33;
                if ((SInt32)(uVar42 + 0x1000) <= (SInt32)uVar23) {
                  uVar41 = 0x1000;
                }
                puVar37[2] = uVar28;
                puVar37[3] = uVar41;
                fVar7 = fVar14;
                if (iVar31 != 0) {
                  fVar7 = (float)((double)CONCAT44d(0x43300000,uVar35 + 0x200 ^ 0x80000000) -
                                 DOUBLE_0004c3a8);
                }
                fVar8 = fVar19;
                if (uVar43 != 0) {
                  fVar8 = (float)((double)CONCAT44d(0x43300000,uVar42 + 0x40 ^ 0x80000000) -
                                 DOUBLE_0004c3a8);
                }
                fVar3 = fVar6;
                if (iVar31 != uVar27 - 1) {
                  fVar3 = (float)((double)CONCAT44d(0x43300000,uVar35 + 0xe00 ^ 0x80000000) -
                                 DOUBLE_0004c3a8);
                }
                fVar10 = fVar16;
                if (uVar43 != uVar39 - 1) {
                  fVar10 = (float)((double)CONCAT44d(0x43300000,uVar42 + 0xfc0 ^ 0x80000000) -
                                  DOUBLE_0004c3a8);
                }
                fVar11 = fVar19;
                if (fVar19 - fVar8 < 0.0) {
                  fVar11 = fVar8;
                }
                fVar12 = fVar10;
                if (fVar16 - fVar10 < 0.0) {
                  fVar12 = fVar16;
                }
                fVar13 = fVar14;
                if (fVar14 - fVar7 < 0.0) {
                  fVar13 = fVar7;
                }
                fVar15 = fVar6;
                if (fVar3 - fVar6 < 0.0) {
                  fVar15 = fVar3;
                }
                if (-(fVar19 - fVar8) < 0.0) {
                  fVar8 = fVar11;
                }
                if (-(fVar16 - fVar10) < 0.0) {
                  fVar12 = fVar10;
                }
                if (-(fVar14 - fVar7) < 0.0) {
                  fVar7 = fVar13;
                }
                if (-(fVar3 - fVar6) < 0.0) {
                  fVar3 = fVar15;
                }
                fVar15 = fVar2 * fVar8 + fVar2 * -fVar18;
                fVar17 = fVar2 * fVar12 + fVar2 * -fVar18;
                fVar11 = fVar4 * fVar7 + fVar4 * -fVar9;
                fVar10 = fVar4 * fVar3 + fVar4 * -fVar9;
                fVar13 = fVar12;
                fVar20 = fVar15;
                if (fVar17 < fVar15) {
                  fVar13 = fVar8;
                  fVar8 = fVar12;
                  fVar20 = fVar17;
                  fVar17 = fVar15;
                }
                fVar12 = fVar3;
                fVar15 = fVar11;
                if (fVar10 < fVar11) {
                  fVar12 = fVar7;
                  fVar7 = fVar3;
                  fVar15 = fVar10;
                  fVar10 = fVar11;
                }
                fVar3 = FLOAT_0004c370;
                if (uVar28 != 0) {
                  fVar3 = FLOAT_0004c374 /
                          (float)((double)CONCAT44d(0x43300000,uVar28 ^ 0x80000000) - DOUBLE_0004c3a8
                                 );
                }
                fVar11 = FLOAT_0004c370;
                if (uVar41 != 0) {
                  fVar11 = FLOAT_0004c374 /
                           (float)((double)CONCAT44d(0x43300000,uVar41 ^ 0x80000000) -
                                  DOUBLE_0004c3a8);
                }
                uVar28 = uVar35 ^ 0x80000000;
                iVar31 = iVar31 + 1;
                uVar35 = uVar35 + 0xc00;
                uVar34 = uVar34 - 0xc00;
                fVar22 = (fVar17 - fVar20) * FLOAT_0004c37c;
                fVar21 = (fVar10 - fVar15) * FLOAT_0004c37c;
                fVar17 = (fVar20 + fVar17) * FLOAT_0004c380;
                fVar10 = (fVar15 + fVar10) * FLOAT_0004c380;
                dVar49 = (double)CONCAT44d(0x43300000,uVar28) - DOUBLE_0004c3a8;
                puVar37[4] = 0x31080;
                puVar37[6] = (UInt32)(fVar11 * (fVar13 - fVar5));
                puVar37[8] = (UInt32)(fVar11 * (fVar8 - fVar5));
                puVar37[0xb] = 0xc0033500;
                puVar37[0xc] = 0x10031;
                puVar37[0xd] = (UInt32)fVar10;
                fVar8 = (float)dVar49;
                puVar37[0xe] = (UInt32)fVar17;
                puVar37[9] = 0x1087;
                puVar37[10] = (SInt32)fVar21 << 0x10 | (SInt32)fVar22;
                puVar37[0xf] = 0;
                puVar37[7] = (UInt32)(fVar3 * (fVar12 - fVar8));
                puVar37[5] = (UInt32)(fVar3 * (fVar7 - fVar8));
                puVar37 = puVar37 + 0x10;
                uVar45 = uVar45 - 1;
              } while (uVar45 != 0);
            }
            uVar43 = uVar43 + 1;
            iVar32 = iVar32 + 0xf80;
            uVar33 = uVar33 - 0xf80;
            uVar36 = uVar36 + 0xf80;
          } while (uVar43 != uVar39);
        }
      }
      else {
        fVar4 = FLOAT_0004c370;
        if (uVar38 != 0) {
          fVar4 = FLOAT_0004c374 /
                  (float)((double)CONCAT44d(0x43300000,uVar38 ^ 0x80000000) - DOUBLE_0004c3a8);
        }
        fVar6 = FLOAT_0004c370;
        if (uVar23 != 0) {
          fVar6 = FLOAT_0004c374 /
                  (float)((double)CONCAT44d(0x43300000,uVar23 ^ 0x80000000) - DOUBLE_0004c3a8);
        }
        fVar16 = (fVar7 - fVar2) * FLOAT_0004c37c;
        fVar14 = (fVar3 - fVar5) * FLOAT_0004c37c;
        fVar11 = (fVar5 + fVar3) * FLOAT_0004c380;
        fVar19 = (fVar2 + fVar7) * FLOAT_0004c380;
        *puVar29 = 0x31080;
        param_1[0xbe] = (UInt32)(fVar4 * (fVar2 * fVar8 + fVar9));
        param_1[0xbf] = (UInt32)(fVar6 * (fVar10 * fVar3 + fVar18));
        param_1[0xc0] = (UInt32)(fVar4 * (fVar7 * fVar8 + fVar9));
        param_1[0xc1] = (UInt32)(fVar6 * (fVar10 * fVar5 + fVar18));
        param_1[0xc4] = 0xc0033500;
        param_1[0xc5] = 0x10031;
        param_1[0xc6] = (UInt32)fVar19;
        param_1[199] = (UInt32)fVar11;
        param_1[0xc2] = 0x1087;
        param_1[0xc3] = (SInt32)fVar16 << 0x10 | (SInt32)fVar14;
        param_1[200] = 0;
      }
      uVar38 = param_1[0xaa];
      uVar23 = param_1[0xa0];
      uVar27 = uVar23 >> 2 & 1;
      uVar30 = uVar23 >> 3 & 3;
      if (uVar40 != 0) {
        if (uVar40 == 0) {
          iVar32 = 0;
        }
        else {
          iVar31 = (M<UInt32>(param_2 + 0x2c) & 0xff) * 0x1c;
          iVar32 = 0;
          puVar37 = puVar29;
          do {
            if (uVar30 == 0) {
              uVar26 = FormatTableLookup_0x0004d2dc(iVar31);
              iVar24 = 0;
            }
            else {
              uVar26 = FormatTableLookup_0x0004d2dc(iVar31);
              iVar24 = -(uVar26 >> 8 & 3);
            }
            uVar26 = uVar26 >> 0xc & 7;
            iVar24 = (SInt32)*puVar37 >> ((iVar24 - uVar26) + 5 & 0x3f);
            if (uVar27 == 0) {
              iVar24 = iVar24 << 5;
            }
            else {
              iVar24 = (iVar24 << 0xc) >> 3;
            }
            iVar32 = iVar32 + 1;
            *puVar37 = 0x1150;
            puVar37[1] = (uVar23 & 0xffffffe0) +
                         iVar24 + (((uVar38 & 0x3fff) + 1) * puVar37[1] << uVar26) & 0xffffffe0 |
                         uVar30 << 3 | uVar27 << 2;
            uVar36 = puVar37[2];
            uVar26 = param_1[0xa6];
            puVar37[2] = 0x1120;
            puVar37[3] = (puVar37[3] - 1) * 0x800 & 0x3ff800 |
                         uVar36 - 1 & 0x7ff | uVar26 & 0xffc00000;
            puVar37 = puVar37 + 0x10;
            uVar40 = uVar40 - 1;
          } while (uVar40 != 0);
          iVar32 = iVar32 * 0x10;
        }
        puVar29 = puVar29 + iVar32;
      }
      else {
        puVar29 = param_1 + 0xc9;
      }
      iVar32 = (SInt32)puVar29 - (SInt32)param_1 >> 2;
    }
    else {
      uVar36 = param_1[0xa0];
      uVar23 = (SInt32)dVar51 >> 1 & 0xfffffe00;
      uVar38 = (SInt32)dVar51 - uVar23;
      uVar40 = uVar23 + 2;
      if ((uVar36 & 0x18) == 0) {
        uVar30 = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)param_2[0x2f] * 0x1c);
        iVar24 = 0;
      }
      else {
        uVar30 = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)param_2[0x2f] * 0x1c);
        iVar24 = -(uVar30 >> 8 & 3);
      }
      iVar25 = (SInt32)uVar23 >> ((iVar24 - (uVar30 >> 0xc & 7)) + 5 & 0x3f);
      iVar24 = iVar25 << 5;
      if ((uVar36 >> 2 & 1) != 0) {
        iVar24 = (iVar25 << 0xc) >> 3;
      }
      uVar30 = uVar23 + 1 & 0x7ff | param_1[0xa6] & 0xfffff800;
      param_1[0xa6] = uVar30;
      fVar2 = (float)((double)CONCAT44d(0x43300000,uVar40 ^ 0x80000000) - dVar46);
      if (fVar2 != fVar4) {
        fVar4 = FLOAT_0004c374 / fVar2;
      }
      uVar39 = (UInt32)*psVar44;
      uVar26 = uVar39 + (SInt32)psVar44[2];
      uVar27 = uVar40;
      if ((SInt32)uVar26 < (SInt32)uVar40) {
        uVar27 = uVar26;
      }
      if ((SInt32)uVar40 < (SInt32)uVar26) {
        fVar5 = M<float>(param_2 + 0x54);
        fVar2 = (float)((double)CONCAT44d(0x43300000,uVar40 - uVar39 ^ 0x80000000) - DOUBLE_0004c3a8)
        ;
      }
      else {
        fVar5 = M<float>(param_2 + 0x54);
        fVar2 = fVar5 + M<float>(param_2 + 0x5c);
      }
      fVar6 = fVar4 * (float)((double)CONCAT44d(0x43300000,uVar27 ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar4 = fVar4 * (float)((double)CONCAT44d(0x43300000,uVar39 ^ 0x80000000) - DOUBLE_0004c3a8);
      if (iVar32 == 0) {
        uVar27 = (UInt32)psVar44[1];
        uVar40 = uVar27 + (SInt32)psVar44[3];
      }
      else {
        uVar40 = (UInt32)psVar44[1];
        uVar27 = uVar40 + (SInt32)psVar44[3];
      }
      dVar49 = (double)CONCAT44d(0x43300000,uVar27 ^ 0x80000000) - DOUBLE_0004c3a8;
      dVar50 = (double)CONCAT44d(0x43300000,uVar40 ^ 0x80000000) - DOUBLE_0004c3a8;
      fVar7 = M<float>(param_2 + 0x58);
      fVar8 = M<float>(param_2 + 0x60);
      if (fVar4 < fVar6) {
        fVar3 = ((fVar7 + fVar8) - fVar7) * FLOAT_0004c37c;
        fVar9 = (fVar2 - fVar5) * FLOAT_0004c37c;
        fVar5 = (fVar2 + fVar5) * FLOAT_0004c380;
        fVar2 = (fVar7 + fVar7 + fVar8) * FLOAT_0004c380;
        param_1[0xbd] = 0x31080;
        param_1[0xbe] = (UInt32)fVar4;
        param_1[0xc2] = 0x1087;
        param_1[0xbf] = (UInt32)(float)(dVar48 * (double)(float)dVar50);
        param_1[0xc0] = (UInt32)fVar6;
        param_1[0xc1] = (UInt32)(float)(dVar48 * (double)(float)dVar49);
        param_1[0xc4] = 0xc0033500;
        param_1[0xc5] = 0x10031;
        param_1[0xc6] = (UInt32)fVar5;
        param_1[199] = (UInt32)fVar2;
        param_1[200] = 0;
        param_1[0xc3] = (SInt32)fVar9 << 0x10 | (SInt32)fVar3;
        iVar31 = 0xc9;
        fVar5 = M<float>(param_2 + 0x54);
        fVar7 = M<float>(param_2 + 0x58);
        fVar8 = M<float>(param_2 + 0x60);
        uVar36 = param_1[0xa0];
        uVar30 = param_1[0xa6];
      }
      param_1[iVar31] = 0x1150;
      param_1[iVar31 + 1] = uVar36 + iVar24;
      param_1[iVar31 + 2] = 0x1120;
      iVar24 = iVar31 + 4;
      param_1[iVar31 + 3] = uVar38 - 1 & 0x7ff | uVar30 & 0xfffff800;
      fVar4 = (float)((double)CONCAT44d(0x43300000,uVar38 ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar2 = FLOAT_0004c370;
      if (fVar4 != FLOAT_0004c370) {
        fVar2 = FLOAT_0004c374 / fVar4;
      }
      uVar40 = (UInt32)*psVar44;
      uVar38 = uVar23;
      if ((SInt32)uVar40 > (SInt32)uVar23) {
        uVar38 = uVar40;
      }
      fVar4 = fVar5;
      if ((SInt32)uVar40 <= (SInt32)uVar23) {
        fVar4 = (float)((double)CONCAT44d(0x43300000,uVar23 - uVar40 ^ 0x80000000) - DOUBLE_0004c3a8)
        ;
      }
      fVar6 = fVar2 * ((float)((double)CONCAT44d(0x43300000,uVar38 ^ 0x80000000) - DOUBLE_0004c3a8) -
                      (float)((double)CONCAT44d(0x43300000,uVar23 ^ 0x80000000) - DOUBLE_0004c3a8));
      fVar2 = fVar2 * (float)((double)CONCAT44d(0x43300000,
                                               (uVar40 + (SInt32)psVar44[2]) - uVar23 ^ 0x80000000) -
                             DOUBLE_0004c3a8);
      if (iVar32 == 0) {
        uVar38 = (UInt32)psVar44[1];
        uVar23 = uVar38 + (SInt32)psVar44[3];
      }
      else {
        uVar23 = (UInt32)psVar44[1];
        uVar38 = uVar23 + (SInt32)psVar44[3];
      }
      dVar49 = (double)CONCAT44d(0x43300000,uVar38 ^ 0x80000000) - DOUBLE_0004c3a8;
      dVar50 = (double)CONCAT44d(0x43300000,uVar23 ^ 0x80000000) - DOUBLE_0004c3a8;
      iVar32 = iVar24;
      if (fVar6 < fVar2) {
        fVar9 = ((fVar5 + M<float>(param_2 + 0x5c)) - fVar4) * FLOAT_0004c37c;
        fVar3 = ((fVar7 + fVar8) - fVar7) * FLOAT_0004c37c;
        iVar32 = iVar24 * 4 + 0x30 >> 2;
        fVar7 = (fVar7 + fVar7 + fVar8) * FLOAT_0004c380;
        fVar4 = (fVar4 + fVar5 + M<float>(param_2 + 0x5c)) * FLOAT_0004c380;
        param_1[iVar24] = 0x31080;
        param_1[iVar31 + 5] = (UInt32)fVar6;
        param_1[iVar31 + 6] = (UInt32)(float)(dVar48 * (double)(float)dVar50);
        param_1[iVar31 + 7] = (UInt32)fVar2;
        param_1[iVar31 + 9] = 0x1087;
        param_1[iVar31 + 8] = (UInt32)(float)(dVar48 * (double)(float)dVar49);
        param_1[iVar31 + 0xb] = 0xc0033500;
        param_1[iVar31 + 0xc] = 0x10031;
        param_1[iVar31 + 0xd] = (UInt32)fVar4;
        param_1[iVar31 + 0xe] = (UInt32)fVar7;
        param_1[iVar31 + 0xf] = 0;
        param_1[iVar31 + 10] = (SInt32)fVar9 << 0x10 | (SInt32)fVar3;
      }
    }
  }
  else {
    dVar50 = (double)CONCAT44d(0x43300000,(SInt32)*psVar44 ^ 0x80000000) - DOUBLE_0004c3a8;
    dVar51 = (double)CONCAT44d(0x43300000,(SInt32)*psVar44 + (SInt32)psVar44[2] ^ 0x80000000) -
             DOUBLE_0004c3a8;
    if (iVar32 == 0) {
      uVar38 = (UInt32)psVar44[1];
      uVar23 = uVar38 + (SInt32)psVar44[3];
    }
    else {
      uVar23 = (UInt32)psVar44[1];
      uVar38 = uVar23 + (SInt32)psVar44[3];
    }
    dVar46 = (double)CONCAT44d(0x43300000,uVar38 ^ 0x80000000) - DOUBLE_0004c3a8;
    dVar47 = (double)CONCAT44d(0x43300000,uVar23 ^ 0x80000000) - DOUBLE_0004c3a8;
    fVar4 = M<float>(param_2 + 0x54);
    fVar5 = M<float>(param_2 + 0x58);
    fVar6 = M<float>(param_2 + 0x5c);
    fVar7 = M<float>(param_2 + 0x60);
    param_1[0xbd] = 0x31080;
    fVar8 = FLOAT_0004c380;
    param_1[0xbe] = (UInt32)(float)(dVar49 * (double)(float)dVar50);
    param_1[0xbf] = (UInt32)(float)(dVar48 * (double)(float)dVar47);
    param_1[0xc0] = (UInt32)(float)(dVar49 * (double)(float)dVar51);
    param_1[0xc1] = (UInt32)(float)(dVar48 * (double)(float)dVar46);
    param_1[0xc2] = 0x1087;
    param_1[0xc4] = 0xc0033500;
    param_1[0xc5] = 0x10031;
    param_1[0xc6] = (UInt32)((fVar4 + fVar4 + fVar6) * fVar8);
    param_1[199] = (UInt32)((fVar5 + fVar5 + fVar7) * fVar8);
    param_1[200] = 0;
    param_1[0xc3] =
         (SInt32)(((fVar4 + fVar6) - fVar4) * fVar2) << 0x10 | (SInt32)(((fVar5 + fVar7) - fVar5) * fVar2)
    ;
    iVar32 = 0xc9;
  }
  param_1[iVar32] = 0x1393;
  param_1[iVar32 + 1] = 10;
  return param_1 + iVar32 + 2;
}
