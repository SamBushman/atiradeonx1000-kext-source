/*
 * ATIRadeonX1000_Write3DTexQuad.cpp
 *
 * RESOLVED (ledger pass): write_3dtexquad_cmds_for_copy_buffer_using_DMA (real addr 0x41150, 6360 bytes), the free
 * function ATIR500Surface::copy_buffer_using_DMA calls to build the 3D textured-quad blit that copies a surface buffer
 * to or from client memory through the GART: it copies the r500 3D-blit state packet into the command stream, patches
 * in the source texture and destination colour-buffer descriptors (address, size, pitch, format from the three
 * function-local tables below), emits the viewport/scissor words and one or two textured quads (large or scaled copies
 * are split into strips), and returns the new command-stream length in words.
 *
 * Transcribed mechanically from the shipped kext's decompile with Tools/ghidra2cpp.py (see Headers/GhidraCompat.h and
 * ATIR500Surface_BuildSwap.cpp for the conventions). The rectangle {x, y, w, h} that Ghidra shows as the four stack
 * shorts local_368/sStack_366/local_364/sStack_362 is (param_19, param_20, param_23, param_24) truncated to 16 bits;
 * param_25 is the "flip vertically" flag (the decompile's stack overflow slot _in_stack_00000078).
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" const r500_3d_blit_state_packet_struct _g_r500_3d_blit_state_packet;

UInt32 write_3dtexquad_cmds_for_copy_buffer_using_DMA(ATIRadeonX1000 *accelerator, UInt32 *param_2, UInt32 param_3,
    UInt32 param_4, UInt32 param_5, UInt32 param_6, UInt32 param_7, UInt32 param_8, UInt32 param_9, UInt32 param_10,
    unsigned char param_11, UInt32 param_12, UInt32 param_13, UInt32 param_14, UInt32 param_15, UInt32 param_16,
    UInt32 param_17, unsigned char param_18, long param_19, long param_20, long param_21, long param_22,
    UInt32 param_23, UInt32 param_24, bool param_25) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(accelerator);
    static const UInt32 out_fmt[5] = { 0x00000001, 0x00000000, 0x00000001, 0x00000005, 0x00000015 };
    static const UInt32 rb3d_dst_format[5] = { 0x00000009, 0x0000000f, 0x00000006, 0x0000000a, 0x00000007 };
    static const UInt32 texture_type[5] = { 0x00000000, 0x0000000a, 0x0000000c, 0x0000000e, 0x0000001d };

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
  SInt32 iVar22;
  SInt32 iVar23;
  UInt32 uVar24;
  UInt32 uVar25;
  UInt32 uVar26;
  UInt32 *puVar27;
  UInt32 uVar28;
  UInt32 uVar29;
  SInt32 iVar30;
  UInt32 uVar31;
  UInt32 uVar32;
  UInt32 *puVar33;
  UInt32 uVar34;
  UInt32 uVar35;
  UInt32 uVar36;
  UInt32 uVar37;
  UInt32 uVar38;
  UInt32 uVar39;
  UInt32 uVar40;
  UInt32 *puVar41;
  UInt32 uVar42;
  UInt32 uVar43;
  double dVar44;
  double dVar45;
  double dVar46;
  double dVar47;
  double dVar48;
  double dVar49;
  double dVar50;
  double dVar51;
  SInt16 local_368;
  SInt16 sStack_366;
  SInt16 local_364;
  SInt16 sStack_362;
  UInt32 local_360;
  UInt32 local_35c;
  UInt32 local_358;
  UInt32 local_354;
  UInt32 local_350;
  UInt32 local_34c;
  UInt32 local_348;
  UInt32 local_344;
  UInt32 local_340;
  UInt32 local_33c;
  UInt32 local_338;
  UInt32 local_334;
  UInt32 local_330;
  UInt32 local_31c;
  UInt32 local_318;
  UInt32 local_314;
  SInt16 *local_310;
  float local_30c;
  float local_308;
  float local_304;
  float local_300;
  float local_2fc;
  float local_2f8;
  float local_2f4;
  float local_2f0;
  UInt32 local_2ec;
  UInt32 local_2e8;
  UInt32 local_2e4;
  UInt32 local_2e0;
  UInt32 local_2dc;
  SInt32 local_2d8;
  UInt32 local_2c8;
  UInt32 uStack_2c4;
  UInt32 local_2c0;
  UInt32 uStack_2bc;
  UInt32 local_2b8;
  SInt32 iStack_2b4;
  UInt32 local_2b0;
  SInt32 iStack_2ac;
  UInt32 local_2a8;
  UInt32 uStack_2a4;
  UInt32 local_2a0;
  UInt32 uStack_29c;
  UInt32 local_298;
  UInt32 uStack_294;
  UInt32 local_290;
  UInt32 uStack_28c;
  SInt64 local_288;
  SInt64 local_280;
  SInt64 local_278;
  SInt64 local_270;
  SInt64 local_268;
  SInt64 local_260;
  SInt64 local_258;
  SInt64 local_250;
  
  iStack_2b4 = param_21 + param_23;
  iStack_2ac = param_22 + param_24;
  uStack_2c4 = param_21 ^ 0x80000000;
  uStack_2bc = param_22 ^ 0x80000000;
  local_2c8 = 0x43300000;
  local_2c0 = 0x43300000;
  local_2b8 = 0x43300000;
  local_368 = (SInt16)param_19;
  sStack_362 = (SInt16)param_24;
  sStack_366 = (SInt16)param_20;
  local_364 = (SInt16)param_23;
  local_2b0 = 0x43300000;
  local_338 = M<UInt32>(param_1 + 0xb74);
  local_350 = 0xa92;
  uStack_29c = param_24;
  local_2a8 = 0x43300000;
  local_2a0 = 0x43300000;
  local_298 = 0x43300000;
  uStack_2a4 = param_23;
  local_330 = param_12;
  local_310 = &local_368;
  local_290 = 0x43300000;
  local_31c = local_31c | 0xf8000000;
  local_2f8 = FLOAT_0004c370;
  local_318 = 1;
  local_314 = 0;
  dVar45 = (double)CONCAT44d(0x43300000,iStack_2b4) - DOUBLE_0004c3b0;
  local_30c = FLOAT_0004c370;
  local_308 = FLOAT_0004c370;
  local_2fc = FLOAT_0004c370;
  local_2e0 = 0x3f800000;
  uVar32 = 0;
  local_2dc = 1;
  local_2d8 = 0;
  local_2f4 = (float)((double)CONCAT44d(0x43300000,param_7) - DOUBLE_0004c3b0);
  local_2ec = 0x3f800000;
  local_2e8 = 0x3f800000;
  local_304 = (float)((double)CONCAT44d(0x43300000,param_23) - DOUBLE_0004c3b0);
  local_2e4 = 0x3f800000;
  local_300 = (float)((double)CONCAT44d(0x43300000,param_24) - DOUBLE_0004c3b0);
  dVar46 = (double)(float)dVar45;
  dVar47 = (double)CONCAT44d(0x43300000,uStack_2bc) - DOUBLE_0004c3a8;
  dVar44 = (double)CONCAT44d(0x43300000,uStack_2c4) - DOUBLE_0004c3a8;
  dVar48 = (double)(float)dVar47;
  dVar49 = (double)CONCAT44d(0x43300000,iStack_2ac) - DOUBLE_0004c3b0;
  dVar51 = (double)(float)dVar44;
  dVar50 = (double)(float)dVar49;
  local_2f0 = (float)((double)CONCAT44d(0x43300000,param_8) - DOUBLE_0004c3b0);
  if (param_10 != 4) {
    uVar32 = (param_9 & 6) << 2;
  }
  uVar34 = param_7 - 1;
  local_35c = uVar34 & 0x7ff | (param_8 - 1) * 0x800 & 0x3ff800 | 0x80000000;
  local_360 = uVar32 | (param_9 & 1) << 2 | param_11 & 3 | param_5 & 0xffffffe0;
  local_348 = param_13 & 0xffffffe0;
  local_354 = uVar34 & 0x3fff | uVar34 * 0x10 & 0x8000 | (param_8 - 1) * 0x20 & 0x10000;
  local_358 = (UInt32)(param_10 != 0) * 0x2000 |
              (UInt32)texture_type[param_10] & 0x1f | 0x8600;
  uVar32 = 0;
  if (param_17 != 4) {
    uVar32 = (param_16 & 6) << 0x10;
  }
  local_34c = uVar32 | (param_16 & 1) << 0x10 | param_15 & 0x3ffe | (param_18 & 3) << 0x13 |
              (rb3d_dst_format[param_10] & 0xf) << 0x15;
  local_344 = out_fmt[param_10] & 0x1f | 0x1b00;
  if (DOUBLE_0004c3c8 <= dVar51) {
    iVar30 = (SInt32)(dVar51 - DOUBLE_0004c3c8);
    local_280 = (SInt64)iVar30;
    uVar32 = iVar30 + 0x80000000;
  }
  else {
    uVar32 = (UInt32)dVar44;
    local_288 = (SInt64)(SInt32)uVar32;
  }
  if (DOUBLE_0004c3c8 <= dVar48) {
    iVar30 = (SInt32)(dVar48 - DOUBLE_0004c3c8);
    local_270 = (SInt64)iVar30;
    uVar34 = iVar30 + 0x80000000;
  }
  else {
    uVar34 = (UInt32)dVar47;
    local_278 = (SInt64)(SInt32)uVar34;
  }
  local_340 = uVar32 & 0x1fff | (uVar34 & 0x1fff) << 0xd;
  if (DOUBLE_0004c3c8 <= dVar46) {
    iVar30 = (SInt32)(dVar46 - DOUBLE_0004c3c8);
    local_260 = (SInt64)iVar30;
    uVar32 = iVar30 + 0x80000000;
  }
  else {
    uVar32 = (UInt32)dVar45;
    local_268 = (SInt64)(SInt32)uVar32;
  }
  if (DOUBLE_0004c3c8 <= dVar50) {
    iVar30 = (SInt32)(dVar50 - DOUBLE_0004c3c8);
    local_250 = (SInt64)iVar30;
    uVar34 = iVar30 + 0x80000000;
  }
  else {
    uVar34 = (UInt32)dVar49;
    local_258 = (SInt64)(SInt32)uVar34;
  }
  dVar46 = (double)local_2f4;
  dVar45 = (double)local_2f0;
  local_33c = uVar32 & 0x1fff | (uVar34 & 0x1fff) << 0xd;
  dVar44 = (double)FLOAT_0004c370;
  puVar41 = param_2 + param_3;
  if (dVar46 != dVar44) {
    dVar44 = (double)(float)((double)FLOAT_0004c374 / dVar46);
  }
  dVar47 = (double)FLOAT_0004c370;
  if (dVar45 != dVar47) {
    dVar47 = (double)(float)((double)FLOAT_0004c374 / dVar45);
  }
  local_334 = param_4;
  uStack_294 = param_7;
  uStack_28c = param_8;
  GCopy(puVar41,(&_g_r500_3d_blit_state_packet),0x2f4);
  puVar41[0xaa] = local_354;
  puVar41[0xa0] = local_360;
  iVar30 = 0xbd;
  puVar41[0xa6] = local_35c;
  puVar41[0xa8] = local_358;
  puVar41[0x9c] = local_34c;
  puVar41[0x9a] = local_348;
  puVar41[0x8a] = local_344;
  puVar41[0xb2] = local_340;
  puVar41[0xb3] = local_33c;
  puVar41[0xb] = local_338;
  puVar41[0xa2] = local_350 & 0x1800 | local_350 & 0x600 | puVar41[0xa2] & 0xffffe1ff;
  if (local_2d8 != 0) {
    puVar41[0x1e] = puVar41[0x1e] & 0xfffffffc | 2;
  }
  dVar48 = DOUBLE_0004c3a8;
  fVar5 = FLOAT_0004c380;
  fVar1 = FLOAT_0004c37c;
  fVar2 = FLOAT_0004c370;
  if (((double)FLOAT_0004c378 < dVar46) || ((double)FLOAT_0004c378 < dVar45)) {
    if (dVar46 <= (double)FLOAT_0004c378) {
      fVar2 = local_30c + local_304;
      fVar5 = local_308 + local_300;
      fVar1 = FLOAT_0004c370;
      if (local_304 != FLOAT_0004c370) {
        fVar1 = (float)((double)CONCAT44d(0x43300000,(SInt32)local_364 ^ 0x80000000) - DOUBLE_0004c3a8)
                / local_304;
      }
      fVar4 = local_30c * fVar1;
      fVar6 = (float)((double)CONCAT44d(0x43300000,(SInt32)local_368 ^ 0x80000000) - DOUBLE_0004c3a8) -
              fVar4;
      fVar7 = FLOAT_0004c370;
      if (local_300 != FLOAT_0004c370) {
        fVar7 = (float)((double)CONCAT44d(0x43300000,(SInt32)sStack_362 ^ 0x80000000) - DOUBLE_0004c3a8)
                / local_300;
      }
      fVar3 = (float)((double)CONCAT44d(0x43300000,(SInt32)sStack_366 ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar17 = -(local_308 * fVar7 - fVar3);
      if (param_25 != 0) {
        fVar7 = -fVar7;
        fVar17 = (float)((double)CONCAT44d(0x43300000,(SInt32)sStack_366 + (SInt32)sStack_362 ^ 0x80000000)
                        - DOUBLE_0004c3a8) - (fVar17 - fVar3);
      }
      uVar34 = (SInt32)dVar46 & 0xffff;
      uVar32 = (SInt32)dVar45 & 0xffff;
      if ((uVar34 < 0x1001) && (uVar32 < 0x1001)) {
        uVar24 = 0;
        uVar28 = 0;
        uVar35 = 0;
        uVar25 = 0;
        uVar42 = 0;
        fVar11 = FLOAT_0004c370;
        fVar8 = FLOAT_0004c370;
        fVar13 = FLOAT_0004c370;
        fVar18 = FLOAT_0004c370;
      }
      else {
        fVar11 = fVar7 * local_308 + fVar17;
        fVar13 = fVar7 * fVar5 + fVar17;
        fVar3 = fVar4 + fVar6;
        fVar8 = fVar2 * fVar1 + fVar6;
        fVar18 = fVar11;
        if (fVar13 < fVar11) {
          fVar18 = fVar13;
          fVar13 = fVar11;
        }
        fVar11 = fVar3;
        if (fVar8 < fVar3) {
          fVar11 = fVar8;
          fVar8 = fVar3;
        }
        uVar25 = (SInt32)dVar46 & 0xfe00;
        uVar42 = (SInt32)fVar11 - 1;
        uVar42 = (((SInt32)uVar42 >> 9) + (UInt32)((SInt32)uVar42 < 0 && (uVar42 & 0x1ff) != 0)) * 0x200;
        uVar28 = 0;
        if ((-1 < (SInt32)uVar42) && (uVar28 = uVar25, (SInt32)uVar42 <= (SInt32)uVar25)) {
          uVar28 = uVar42 & 0xfe00;
        }
        uVar42 = 0x40;
        if ((0x40 < uVar32) && (uVar42 = (SInt32)dVar45 & 0xffc0, (SInt32)(uVar32 - uVar42) < 0x40)) {
          uVar42 = uVar42 - 0x40;
        }
        uVar24 = 0;
        uVar25 = (SInt32)fVar18 - 1;
        uVar25 = (((SInt32)uVar25 >> 6) + (UInt32)((SInt32)uVar25 < 0 && (uVar25 & 0x3f) != 0)) * 0x40;
        if ((-1 < (SInt32)uVar25) && (uVar24 = uVar42 & 0xffff, (SInt32)uVar25 <= (SInt32)uVar42)) {
          uVar24 = uVar25 & 0xffc0;
        }
        uVar42 = 0x200;
        if (0x1ff < uVar28) {
          uVar42 = uVar28;
        }
        uVar25 = uVar34 - 1;
        uVar35 = (((SInt32)uVar25 >> 9) + (UInt32)((SInt32)uVar25 < 0 && (uVar25 & 0x1ff) != 0)) * 0x200;
        uVar25 = (UInt32)fVar8;
        if ((FLOAT_0004c370 < fVar8) &&
           ((float)((double)CONCAT44d(0x43300000,uVar25 ^ 0x80000000) - DOUBLE_0004c3a8) < fVar8)) {
          uVar25 = uVar25 + 1;
        }
        if ((SInt32)uVar25 <= (SInt32)uVar35) {
          uVar35 = uVar25;
        }
        uVar25 = 1;
        if ((SInt32)uVar42 < (SInt32)uVar35) {
          uVar25 = (SInt32)((uVar35 - uVar42) + 0xbff) / 0xc00 & 0xff;
        }
        uVar42 = 0x40;
        if (0x3f < uVar24) {
          uVar42 = uVar24;
        }
        uVar35 = uVar32 - 1;
        uVar37 = (((SInt32)uVar35 >> 6) + (UInt32)((SInt32)uVar35 < 0 && (uVar35 & 0x3f) != 0)) * 0x40;
        uVar35 = (UInt32)fVar13;
        if ((FLOAT_0004c370 < fVar13) &&
           ((float)((double)CONCAT44d(0x43300000,uVar35 ^ 0x80000000) - DOUBLE_0004c3a8) < fVar13)) {
          uVar35 = uVar35 + 1;
        }
        if ((SInt32)uVar35 <= (SInt32)uVar37) {
          uVar37 = uVar35;
        }
        uVar35 = 1;
        if ((SInt32)uVar42 < (SInt32)uVar37) {
          uVar35 = (SInt32)((uVar37 - uVar42) + 0xf7f) / 0xf80 & 0xff;
        }
        uVar42 = uVar35 * uVar25 & 0xff;
      }
      puVar27 = puVar41 + 0xbd;
      if (uVar42 != 0) {
        fVar2 = FLOAT_0004c370;
        if (fVar1 != FLOAT_0004c370) {
          fVar2 = FLOAT_0004c374 / fVar1;
        }
        fVar1 = FLOAT_0004c370;
        if (fVar7 != FLOAT_0004c370) {
          fVar1 = FLOAT_0004c374 / fVar7;
        }
        if (uVar35 != 0) {
          uVar37 = uVar32 - uVar24;
          uVar38 = 0;
          iVar30 = 0;
          puVar33 = puVar27;
          uVar39 = uVar24;
          do {
            if (uVar25 != 0) {
              uVar40 = uVar24 + iVar30;
              uVar29 = uVar34 - uVar28;
              iVar22 = 0;
              fVar5 = (float)((double)CONCAT44d(0x43300000,uVar40 ^ 0x80000000) - DOUBLE_0004c3a8);
              uVar31 = uVar28;
              uVar43 = uVar25;
              do {
                *puVar33 = uVar31;
                puVar33[1] = uVar39;
                uVar26 = uVar29;
                if ((SInt32)(uVar31 + 0x1000) <= (SInt32)uVar34) {
                  uVar26 = 0x1000;
                }
                uVar36 = uVar37;
                if ((SInt32)(uVar40 + 0x1000) <= (SInt32)uVar32) {
                  uVar36 = 0x1000;
                }
                puVar33[2] = uVar26;
                puVar33[3] = uVar36;
                fVar4 = fVar11;
                if (iVar22 != 0) {
                  fVar4 = (float)((double)CONCAT44d(0x43300000,uVar31 + 0x200 ^ 0x80000000) -
                                 DOUBLE_0004c3a8);
                }
                fVar7 = fVar18;
                if (uVar38 != 0) {
                  fVar7 = (float)((double)CONCAT44d(0x43300000,uVar40 + 0x40 ^ 0x80000000) -
                                 DOUBLE_0004c3a8);
                }
                fVar3 = fVar8;
                if (iVar22 != uVar25 - 1) {
                  fVar3 = (float)((double)CONCAT44d(0x43300000,uVar31 + 0xe00 ^ 0x80000000) -
                                 DOUBLE_0004c3a8);
                }
                fVar9 = fVar13;
                if (uVar38 != uVar35 - 1) {
                  fVar9 = (float)((double)CONCAT44d(0x43300000,uVar40 + 0xfc0 ^ 0x80000000) -
                                 DOUBLE_0004c3a8);
                }
                fVar15 = fVar7;
                if (fVar7 - fVar18 < 0.0) {
                  fVar15 = fVar18;
                }
                fVar14 = fVar13;
                if (fVar9 - fVar13 < 0.0) {
                  fVar14 = fVar9;
                }
                fVar10 = fVar4;
                if (fVar4 - fVar11 < 0.0) {
                  fVar10 = fVar11;
                }
                fVar12 = fVar8;
                if (fVar3 - fVar8 < 0.0) {
                  fVar12 = fVar3;
                }
                if (-(fVar7 - fVar18) < 0.0) {
                  fVar15 = fVar7;
                }
                if (-(fVar9 - fVar13) < 0.0) {
                  fVar9 = fVar14;
                }
                if (-(fVar4 - fVar11) < 0.0) {
                  fVar10 = fVar4;
                }
                if (-(fVar3 - fVar8) < 0.0) {
                  fVar3 = fVar12;
                }
                fVar12 = fVar1 * fVar15 + fVar1 * -fVar17;
                fVar16 = fVar1 * fVar9 + fVar1 * -fVar17;
                fVar7 = fVar2 * fVar10 + fVar2 * -fVar6;
                fVar4 = fVar2 * fVar3 + fVar2 * -fVar6;
                fVar14 = fVar9;
                fVar19 = fVar12;
                if (fVar16 < fVar12) {
                  fVar14 = fVar15;
                  fVar15 = fVar9;
                  fVar19 = fVar16;
                  fVar16 = fVar12;
                }
                fVar9 = fVar3;
                fVar12 = fVar7;
                if (fVar4 < fVar7) {
                  fVar9 = fVar10;
                  fVar10 = fVar3;
                  fVar12 = fVar4;
                  fVar4 = fVar7;
                }
                fVar7 = FLOAT_0004c370;
                if (uVar26 != 0) {
                  fVar7 = FLOAT_0004c374 /
                          (float)((double)CONCAT44d(0x43300000,uVar26 ^ 0x80000000) - DOUBLE_0004c3a8
                                 );
                }
                fVar3 = FLOAT_0004c370;
                if (uVar36 != 0) {
                  fVar3 = FLOAT_0004c374 /
                          (float)((double)CONCAT44d(0x43300000,uVar36 ^ 0x80000000) - DOUBLE_0004c3a8
                                 );
                }
                uVar26 = uVar31 ^ 0x80000000;
                iVar22 = iVar22 + 1;
                uVar31 = uVar31 + 0xc00;
                uVar29 = uVar29 - 0xc00;
                fVar21 = (fVar16 - fVar19) * FLOAT_0004c37c;
                fVar20 = (fVar4 - fVar12) * FLOAT_0004c37c;
                fVar16 = (fVar16 + fVar19) * FLOAT_0004c380;
                fVar4 = (fVar4 + fVar12) * FLOAT_0004c380;
                dVar44 = (double)CONCAT44d(0x43300000,uVar26) - DOUBLE_0004c3a8;
                puVar33[4] = 0x31080;
                puVar33[6] = (UInt32)(fVar3 * (fVar14 - fVar5));
                puVar33[8] = (UInt32)(fVar3 * (fVar15 - fVar5));
                puVar33[0xb] = 0xc0033500;
                puVar33[0xc] = 0x10031;
                puVar33[0xd] = (UInt32)fVar4;
                fVar4 = (float)dVar44;
                puVar33[0xe] = (UInt32)fVar16;
                puVar33[9] = 0x1087;
                puVar33[10] = (SInt32)fVar20 << 0x10 | (SInt32)fVar21;
                puVar33[0xf] = 0;
                puVar33[7] = (UInt32)(fVar7 * (fVar9 - fVar4));
                puVar33[5] = (UInt32)(fVar7 * (fVar10 - fVar4));
                puVar33 = puVar33 + 0x10;
                uVar43 = uVar43 - 1;
              } while (uVar43 != 0);
            }
            uVar38 = uVar38 + 1;
            iVar30 = iVar30 + 0xf80;
            uVar37 = uVar37 - 0xf80;
            uVar39 = uVar39 + 0xf80;
          } while (uVar38 != uVar35);
        }
      }
      else {
        fVar3 = FLOAT_0004c370;
        if (uVar34 != 0) {
          fVar3 = FLOAT_0004c374 /
                  (float)((double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - DOUBLE_0004c3a8);
        }
        fVar8 = FLOAT_0004c370;
        if (uVar32 != 0) {
          fVar8 = FLOAT_0004c374 /
                  (float)((double)CONCAT44d(0x43300000,uVar32 ^ 0x80000000) - DOUBLE_0004c3a8);
        }
        fVar13 = (fVar2 - local_30c) * FLOAT_0004c37c;
        fVar11 = (fVar5 - local_308) * FLOAT_0004c37c;
        fVar9 = (local_308 + fVar5) * FLOAT_0004c380;
        fVar18 = (local_30c + fVar2) * FLOAT_0004c380;
        *puVar27 = 0x31080;
        puVar41[0xbe] = (UInt32)(fVar3 * (fVar4 + fVar6));
        puVar41[0xbf] = (UInt32)(fVar8 * (fVar7 * fVar5 + fVar17));
        puVar41[0xc0] = (UInt32)(fVar3 * (fVar2 * fVar1 + fVar6));
        puVar41[0xc1] = (UInt32)(fVar8 * (fVar7 * local_308 + fVar17));
        puVar41[0xc4] = 0xc0033500;
        puVar41[0xc5] = 0x10031;
        puVar41[0xc6] = (UInt32)fVar18;
        puVar41[199] = (UInt32)fVar9;
        puVar41[0xc2] = 0x1087;
        puVar41[0xc3] = (SInt32)fVar13 << 0x10 | (SInt32)fVar11;
        puVar41[200] = 0;
      }
      uVar34 = puVar41[0xaa];
      uVar32 = puVar41[0xa0];
      uVar25 = uVar32 >> 3 & 3;
      uVar28 = uVar32 >> 2 & 1;
      if (uVar42 != 0) {
        if (uVar42 == 0) {
          iVar30 = 0;
        }
        else {
          iVar22 = (local_334 & 0xff) * 0x1c;
          iVar30 = 0;
          puVar33 = puVar27;
          do {
            if (uVar25 == 0) {
              uVar24 = FormatTableLookup_0x0004d2dc(iVar22);
              iVar23 = 0;
            }
            else {
              uVar24 = FormatTableLookup_0x0004d2dc(iVar22);
              iVar23 = -(uVar24 >> 8 & 3);
            }
            uVar24 = uVar24 >> 0xc & 7;
            iVar23 = (SInt32)*puVar33 >> ((iVar23 - uVar24) + 5 & 0x3f);
            if (uVar28 == 0) {
              iVar23 = iVar23 << 5;
            }
            else {
              iVar23 = (iVar23 << 0xc) >> 3;
            }
            iVar30 = iVar30 + 1;
            *puVar33 = 0x1150;
            puVar33[1] = (uVar32 & 0xffffffe0) +
                         iVar23 + (((uVar34 & 0x3fff) + 1) * puVar33[1] << uVar24) & 0xffffffe0 |
                         uVar28 << 2 | uVar25 << 3;
            uVar39 = puVar33[2];
            uVar24 = puVar41[0xa6];
            puVar33[2] = 0x1120;
            puVar33[3] = (puVar33[3] - 1) * 0x800 & 0x3ff800 |
                         uVar39 - 1 & 0x7ff | uVar24 & 0xffc00000;
            puVar33 = puVar33 + 0x10;
            uVar42 = uVar42 - 1;
          } while (uVar42 != 0);
          iVar30 = iVar30 * 0x10;
        }
        puVar27 = puVar27 + iVar30;
      }
      else {
        puVar27 = puVar41 + 0xc9;
      }
      iVar22 = (SInt32)puVar27 - (SInt32)puVar41 >> 2;
    }
    else {
      uVar39 = puVar41[0xa0];
      iVar22 = (local_334 & 0xff) * 0x1c;
      uVar32 = (SInt32)dVar46 >> 1 & 0xfffffe00;
      uVar42 = (SInt32)dVar46 - uVar32;
      uVar34 = uVar32 + 2;
      if ((uVar39 & 0x18) == 0) {
        uVar28 = FormatTableLookup_0x0004d2dc(iVar22);
        iVar22 = 0;
      }
      else {
        uVar28 = FormatTableLookup_0x0004d2dc(iVar22);
        iVar22 = -(uVar28 >> 8 & 3);
      }
      iVar23 = (SInt32)uVar32 >> ((iVar22 - (uVar28 >> 0xc & 7)) + 5 & 0x3f);
      iVar22 = iVar23 << 5;
      if ((uVar39 >> 2 & 1) != 0) {
        iVar22 = (iVar23 << 0xc) >> 3;
      }
      uVar28 = uVar32 + 1 & 0x7ff | puVar41[0xa6] & 0xfffff800;
      puVar41[0xa6] = uVar28;
      fVar1 = (float)((double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - dVar48);
      if (fVar1 != fVar2) {
        fVar2 = FLOAT_0004c374 / fVar1;
      }
      uVar35 = (UInt32)local_368;
      uVar24 = uVar35 + (SInt32)local_364;
      uVar25 = uVar34;
      if ((SInt32)uVar24 < (SInt32)uVar34) {
        uVar25 = uVar24;
      }
      if ((SInt32)uVar34 < (SInt32)uVar24) {
        fVar1 = (float)((double)CONCAT44d(0x43300000,uVar34 - uVar35 ^ 0x80000000) - DOUBLE_0004c3a8)
        ;
      }
      else {
        fVar1 = local_30c + local_304;
      }
      fVar5 = fVar2 * (float)((double)CONCAT44d(0x43300000,uVar25 ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar2 = fVar2 * (float)((double)CONCAT44d(0x43300000,uVar35 ^ 0x80000000) - DOUBLE_0004c3a8);
      if (param_25 == 0) {
        uVar25 = (UInt32)sStack_366;
        uVar34 = uVar25 + (SInt32)sStack_362;
      }
      else {
        uVar34 = (UInt32)sStack_366;
        uVar25 = uVar34 + (SInt32)sStack_362;
      }
      dVar44 = (double)CONCAT44d(0x43300000,uVar25 ^ 0x80000000) - DOUBLE_0004c3a8;
      dVar45 = (double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - DOUBLE_0004c3a8;
      local_300 = local_308 + local_300;
      if (fVar2 < fVar5) {
        fVar6 = (local_300 - local_308) * FLOAT_0004c37c;
        fVar4 = (fVar1 - local_30c) * FLOAT_0004c37c;
        fVar1 = (fVar1 + local_30c) * FLOAT_0004c380;
        fVar7 = (local_308 + local_300) * FLOAT_0004c380;
        puVar41[0xbd] = 0x31080;
        puVar41[0xbe] = (UInt32)fVar2;
        puVar41[0xc2] = 0x1087;
        puVar41[0xbf] = (UInt32)(float)(dVar47 * (double)(float)dVar45);
        puVar41[0xc0] = (UInt32)fVar5;
        puVar41[0xc1] = (UInt32)(float)(dVar47 * (double)(float)dVar44);
        puVar41[0xc4] = 0xc0033500;
        puVar41[0xc5] = 0x10031;
        puVar41[0xc6] = (UInt32)fVar1;
        puVar41[199] = (UInt32)fVar7;
        puVar41[200] = 0;
        puVar41[0xc3] = (SInt32)fVar4 << 0x10 | (SInt32)fVar6;
        iVar30 = 0xc9;
        uVar39 = puVar41[0xa0];
        uVar28 = puVar41[0xa6];
      }
      puVar41[iVar30] = 0x1150;
      puVar41[iVar30 + 1] = uVar39 + iVar22;
      puVar41[iVar30 + 2] = 0x1120;
      iVar23 = iVar30 + 4;
      puVar41[iVar30 + 3] = uVar42 - 1 & 0x7ff | uVar28 & 0xfffff800;
      fVar2 = (float)((double)CONCAT44d(0x43300000,uVar42 ^ 0x80000000) - DOUBLE_0004c3a8);
      fVar1 = FLOAT_0004c370;
      if (fVar2 != FLOAT_0004c370) {
        fVar1 = FLOAT_0004c374 / fVar2;
      }
      uVar42 = (UInt32)local_368;
      uVar34 = uVar32;
      if ((SInt32)uVar42 > (SInt32)uVar32) {
        uVar34 = uVar42;
      }
      fVar2 = local_30c;
      if ((SInt32)uVar42 <= (SInt32)uVar32) {
        fVar2 = (float)((double)CONCAT44d(0x43300000,uVar32 - uVar42 ^ 0x80000000) - DOUBLE_0004c3a8)
        ;
      }
      fVar5 = fVar1 * ((float)((double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - DOUBLE_0004c3a8) -
                      (float)((double)CONCAT44d(0x43300000,uVar32 ^ 0x80000000) - DOUBLE_0004c3a8));
      fVar1 = fVar1 * (float)((double)CONCAT44d(0x43300000,
                                               (uVar42 + (SInt32)local_364) - uVar32 ^ 0x80000000) -
                             DOUBLE_0004c3a8);
      if (param_25 == 0) {
        uVar34 = (UInt32)sStack_366;
        uVar32 = uVar34 + (SInt32)sStack_362;
      }
      else {
        uVar32 = (UInt32)sStack_366;
        uVar34 = uVar32 + (SInt32)sStack_362;
      }
      dVar44 = (double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - DOUBLE_0004c3a8;
      dVar45 = (double)CONCAT44d(0x43300000,uVar32 ^ 0x80000000) - DOUBLE_0004c3a8;
      iVar22 = iVar23;
      if (fVar5 < fVar1) {
        fVar4 = ((local_30c + local_304) - fVar2) * FLOAT_0004c37c;
        fVar6 = (local_300 - local_308) * FLOAT_0004c37c;
        iVar22 = iVar23 * 4 + 0x30 >> 2;
        fVar7 = (local_308 + local_300) * FLOAT_0004c380;
        fVar2 = (fVar2 + local_30c + local_304) * FLOAT_0004c380;
        puVar41[iVar23] = 0x31080;
        puVar41[iVar30 + 5] = (UInt32)fVar5;
        puVar41[iVar30 + 6] = (UInt32)(float)(dVar47 * (double)(float)dVar45);
        puVar41[iVar30 + 7] = (UInt32)fVar1;
        puVar41[iVar30 + 9] = 0x1087;
        puVar41[iVar30 + 8] = (UInt32)(float)(dVar47 * (double)(float)dVar44);
        puVar41[iVar30 + 0xb] = 0xc0033500;
        puVar41[iVar30 + 0xc] = 0x10031;
        puVar41[iVar30 + 0xd] = (UInt32)fVar2;
        puVar41[iVar30 + 0xe] = (UInt32)fVar7;
        puVar41[iVar30 + 0xf] = 0;
        puVar41[iVar30 + 10] = (SInt32)fVar4 << 0x10 | (SInt32)fVar6;
      }
    }
  }
  else {
    dVar45 = (double)CONCAT44d(0x43300000,(SInt32)local_368 ^ 0x80000000) - DOUBLE_0004c3a8;
    dVar46 = (double)CONCAT44d(0x43300000,(SInt32)local_368 + (SInt32)local_364 ^ 0x80000000) -
             DOUBLE_0004c3a8;
    if (param_25 == 0) {
      uVar34 = (UInt32)sStack_366;
      uVar32 = uVar34 + (SInt32)sStack_362;
    }
    else {
      uVar32 = (UInt32)sStack_366;
      uVar34 = uVar32 + (SInt32)sStack_362;
    }
    dVar48 = (double)CONCAT44d(0x43300000,uVar34 ^ 0x80000000) - DOUBLE_0004c3a8;
    dVar49 = (double)CONCAT44d(0x43300000,uVar32 ^ 0x80000000) - DOUBLE_0004c3a8;
    puVar41[0xbd] = 0x31080;
    puVar41[0xbe] = (UInt32)(float)(dVar44 * (double)(float)dVar45);
    puVar41[0xbf] = (UInt32)(float)(dVar47 * (double)(float)dVar49);
    puVar41[0xc0] = (UInt32)(float)(dVar44 * (double)(float)dVar46);
    puVar41[0xc1] = (UInt32)(float)(dVar47 * (double)(float)dVar48);
    puVar41[0xc2] = 0x1087;
    puVar41[0xc4] = 0xc0033500;
    puVar41[0xc5] = 0x10031;
    puVar41[0xc6] = (UInt32)((local_30c + local_30c + local_304) * fVar5);
    puVar41[199] = (UInt32)((local_308 + local_308 + local_300) * fVar5);
    puVar41[200] = 0;
    puVar41[0xc3] =
         (SInt32)(((local_30c + local_304) - local_30c) * fVar1) << 0x10 |
         (SInt32)(((local_308 + local_300) - local_308) * fVar1);
    iVar22 = 0xc9;
  }
  puVar41[iVar22] = 0x1393;
  puVar41[iVar22 + 1] = 10;
  iVar30 = (SInt32)puVar41 + ((iVar22 + 2) * 4 - (SInt32)param_2) >> 2;
  param_2[iVar30] = 0x1393;
  param_2[iVar30 + 1] = 10;
  param_2[iVar30 + 2] = 0x5c8;
  param_2[iVar30 + 3] = 0x20000;
  return iVar30 + 4;
}
