/*
 * ATIR500Surface_BuildSwap.cpp
 *
 * RESOLVED (ledger pass): ATIR500Surface::build_swap (real addr 0x3eec0, vtable +0x5c0, 8704 bytes) - the routine that
 * turns a surface's pending swap into the per-panel command stream: for each active display panel it builds (in the
 * panel's pending-write batch at this+0xc34+panel*0x94) the 3D-blit state packet copy, the source/destination surface
 * descriptors, the viewport/scissor floats and the textured-quad vertices for scaled swaps, and the 0x1393/0x194e/
 * 0x1b4e window-select preambles, choosing per-panel between a plain copy and the scaled-blit path.
 *
 * Transcribed mechanically from the shipped kext's decompile with Tools/ghidra2cpp.py (Headers/GhidraCompat.h): the
 * arithmetic, control flow and variable names of the decompile are kept as they are (the pseudo-C is the transcription),
 * with these conventions:
 *   M<T>(addr)          typed memory access (`*(T *)addr`);  self = this as a byte pointer (Ghidra models the class as
 *                       one byte, so `this + 0xd50` is byte arithmetic)
 *   FBITS(f)            a float written into a raw UInt32 slot (Ghidra prints it as `slot = (float)x`)
 *   CONCAT44d(a, b)     the int/uint -> double conversion idiom (0x43300000:x minus the 2^52 bias constant)
 *   FormatTableLookup_* words of the kext's ati_format_info_table (0x4d2d0, 0x1c-byte entries) at the given field
 * Object layout used: this+0xd50 accelerator, +0xd60 per-panel region records, +0xc34+panel*0x94 pending batch header,
 * +0xb70/+0xb74 current / previous buffer record, +0xbe8 mode bits, +0xa8.. buffer records (0x78 stride).
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 FormatTableLookup_0x0004d2d8(UInt32 byteOffset);
extern "C" UInt32 FormatTableLookup_0x0004d2dc(UInt32 byteOffset);
extern "C" UInt32 FormatTableLookup_0x0004d2e0(UInt32 byteOffset);
extern "C" UInt32 FormatTableLookup_0x0004d2e4(UInt32 byteOffset);
extern "C" const r500_3d_blit_state_packet_struct g_r500_3d_blit_state_packet;

void ATIR500Surface::build_swap() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  UInt8 AVar5;
  UInt8 bVar6;
  UInt8 bVar7;
  float widthRatio;
  SInt16 regionX;
  SInt16 regionWidth;
  SInt16 surfaceWidth;
  SInt16 surfaceHeight;
  UInt16 uVar13;
  UInt16 uVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  UInt32 uVar17;
  SInt32 iVar18;
  UInt32 uVar19;
  UInt32 uVar20;
  UInt32 uVar21;
  UInt32 uVar22;
  UInt32 uVar23;
  UInt32 uVar24;
  UInt32 uVar25;
  SInt32 iVar26;
  SInt32 *piVar27;
  SInt32 iVar28;
  UInt32 uVar29;
  UInt32 uVar30;
  UInt32 uVar31;
  SInt32 iVar32;
  SInt32 iVar33;
  SInt32 iVar34;
  SInt32 iVar35;
  SwapBufferEntry *batchEntry;     /* entries[0] of the panel being built: its `header` is the pending swap-write batch */
  PanelRecord *panelRec;
  UInt32 uVar38;
  UInt32 *batchWords;
  UInt32 uVar40;
  float heightRatio;
  UInt32 uVar42;
  SInt32 iVar43;
  SInt32 iVar44;
  UInt32 *blitPacket;
  UInt8 bVar46;
  double dVar47;
  double dVar48;
  double dVar49;
  double dVar50;
  double dVar51;
  double dVar52;
  double dVar53;
  double dVar54;
  double dVar55;
  double half;
  double one;
  double zero;
  double dVar59;
  double signedIntBias;
  double dVar61;
  double dVar62;
  double dVar63;
  double dVar64;
  double dVar65;
  double dVar66;
  double dVar67;
  double dVar68;
  UInt8 *local_108;
  UInt32 panel;
  SInt32 *local_100;
  SInt32 surfaceBuffer;
  SInt32 packetIndex;
  SInt32 textureOffsetWord;
  
  M<UInt16>(self + 0xdb4) = 0;
  iVar32 = M<SInt32>(self + 0xd50);
  if (M<SInt32>(iVar32 + 0xcc) != 0) {
    panel = 0;
    zero = (double)FLOAT_0004c370;
    one = (double)FLOAT_0004c374;
    half = (double)FLOAT_0004c380;
    panelRec = PANEL_RECORD(self, 0);
    signedIntBias = DOUBLE_0004c3a8;
    local_108 = self;
    do {
      bVar1 = (M<UInt32>(self + 0xbe8) & 0x20) == 0;
      if (bVar1) {
        surfaceBuffer = M<SInt32>(self + 0xb74);
      }
      else {
        surfaceBuffer = M<SInt32>(self + 0xb70);
      }
      iVar32 = panel * 0x78 + iVar32;
      if ((self[0xbf1] == 0x10) ||
         ((self[0xbf1] != 0x20 && (M<SInt32>(self + 0xbe0) == M<SInt32>(self + 0xbe4))
          ))) {
        iVar35 = 1;
      }
      else {
        iVar35 = 2;
      }
      piVar27 = M<SInt32 *>(local_108 + 0xd60);
      iVar34 = *piVar27;
      local_100 = piVar27 + 3;
      if (iVar34 == 0) {
        local_100 = piVar27 + 1;
        iVar34 = 1;
      }
      uVar40 = (UInt32)M<SInt16>((SInt32)piVar27 + 10);
      regionX = M<SInt16>(piVar27 + 1);
      uVar38 = (UInt32)M<SInt16>((SInt32)piVar27 + 6);
      regionWidth = M<SInt16>(piVar27 + 2);
      if ((M<SInt32>(self + 0x90) != 0) && (M<SInt32>(self + 0xda4) != 0)) {
        if ((SInt32)regionWidth == 0) {
          return;
        }
        if (uVar40 == 0) {
          return;
        }
      }
      iVar44 = (SInt32)Vol(panelRec->entries[0].header);
      batchEntry = &panelRec->entries[0];
      bVar46 = (panel == 0) << 1;
      batchWords = (UInt32 *)(iVar44 + 0x20);
      if (((panel != 0) || (M<SInt32>(self + 0xb70) == M<SInt32>(self + 0xb74))) || (bVar1)) {
        iVar44 = 0;
      }
      else {
        *batchWords = 0xd0b;
        M<UInt32>(iVar44 + 0x24) = 5;
        GCopy(iVar44 + 0x28,(&g_r500_3d_blit_state_packet),0x2f4);
        iVar26 = (iVar44 + 0x31c) - (SInt32)batchWords >> 2;
        iVar28 = (UInt32)(UInt8)self[0xe2] * 0x1c;
        uVar29 = 0;
        M<UInt32>(iVar44 + 0x290) =
             (UInt32)M<UInt16>(self + 200) * M<SInt32>(self + 0xe8) + M<SInt32>(self + 0xb0) &
             0xffffffe0;
        if ((M<UInt32>(self + 0xe4) & 0xf00000) != 0) {
          uVar29 = (UInt32)M<UInt16>(self + 0xbc) / (M<UInt32>(self + 0xe4) >> 0x14 & 0xf);
        }
        uVar19 = 0x20 / M<UInt16>(self + 0xbe);
        if (0x20 / M<UInt16>(self + 0xbe) <= uVar29) {
          uVar19 = uVar29;
        }
        uVar15 = M<UInt32>(iVar44 + 0x250);
        M<UInt32>(iVar44 + 0x298) =
             uVar19 & 0x3ffe | ((UInt8)self[0xe0] & 1) << 0x10 | ((UInt8)self[0xe0] & 6) << 0x10 |
             ((UInt8)self[0xe1] & 3) << 0x13 |
             FormatTableLookup_0x0004d2e0((UInt32)(UInt8)self[0xe2] * 0x1c) >> 1 & 0x1e00000;
        uVar29 = FormatTableLookup_0x0004d2e0(iVar28) >> 0x11 & 0x1f;
        M<UInt32>(iVar44 + 0x250) = uVar29 | uVar15 & 0xffffffe0;
        uVar19 = FormatTableLookup_0x0004d2e0(iVar28) >> 7 & 0x300;
        M<UInt32>(iVar44 + 0x250) = uVar19 | uVar29 | uVar15 & 0xfffffce0;
        uVar17 = FormatTableLookup_0x0004d2e0(iVar28) >> 3 & 0xc00;
        M<UInt32>(iVar44 + 0x250) = uVar17 | uVar19 | uVar29 | uVar15 & 0xfffff0e0;
        uVar42 = (FormatTableLookup_0x0004d2e0(iVar28) & 0x1800) << 1;
        M<UInt32>(iVar44 + 0x250) = uVar42 | uVar17 | uVar19 | uVar29 | uVar15 & 0xffffc0e0;
        M<UInt32>(iVar44 + 0x250) =
             (FormatTableLookup_0x0004d2e0(iVar28) & 0x600) << 5 |
             uVar42 | uVar17 | uVar19 | uVar29 | uVar15 & 0xffff00e0;
        if (((M<UInt32>(self + 0xe4) & 0xf00000) == 0) ||
           (uVar19 = (UInt32)M<UInt16>(self + 0xc4) / (M<UInt32>(self + 0xe4) >> 0x14 & 0xf),
           uVar29 = uVar19 - 1, uVar19 == 0)) {
          uVar29 = 0;
        }
        uVar19 = 0;
        if (M<UInt16>(self + 0xc6) != 0) {
          uVar19 = M<UInt16>(self + 0xc6) - 1;
        }
        M<UInt32>(iVar44 + 0x2f4) = uVar29 & 0x1fff | (uVar19 & 0x1fff) << 0xd;
        AVar5 = self[0x15a];
        M<UInt32>(iVar44 + 0x2a8) =
             ((UInt8)self[0x158] & 7) << 2 |
             (UInt32)M<UInt16>(self + 0x140) * M<SInt32>(self + 0x160) + M<SInt32>(self + 0x128) &
             0xffffffe0;
        if (((M<UInt32>(self + 0x15c) & 0xf00000) == 0) ||
           (uVar19 = (UInt32)M<UInt16>(self + 0x13c) / (M<UInt32>(self + 0x15c) >> 0x14 & 0xf),
           uVar29 = uVar19 - 1, uVar19 == 0)) {
          uVar29 = 0;
        }
        uVar19 = 0;
        if (M<UInt16>(self + 0x13e) != 0) {
          uVar19 = M<UInt16>(self + 0x13e) - 1;
        }
        M<UInt32>(iVar44 + 0x2c0) = uVar29 & 0x7ff | (uVar19 & 0x7ff) << 0xb | 0x80000000;
        uVar29 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)AVar5 * 0x1c);
        M<UInt32>(iVar44 + 0x2c8) =
             uVar29 >> 0x13 & 0x1f | (uVar29 & 0x40) << 0x10 | uVar29 >> 7 & 0xe00 |
             uVar29 >> 1 & 0x7000 | (uVar29 & 0x1c00) << 5 | (uVar29 & 0x380) << 0xb;
        uVar29 = M<UInt32>(self + 0x15c);
        bVar1 = (uVar29 & 0xf00000) == 0;
        if (bVar1) {
          uVar19 = 0;
        }
        else {
          uVar19 = (UInt32)M<UInt16>(self + 0x134) / (uVar29 >> 0x14 & 0xf);
        }
        uVar17 = 0x20 / M<UInt16>(self + 0x136);
        if (0x20 / M<UInt16>(self + 0x136) <= uVar19) {
          uVar17 = uVar19;
        }
        if ((bVar1) ||
           (uVar19 = (UInt32)M<UInt16>(self + 0x13c) / (uVar29 >> 0x14 & 0xf), uVar29 = uVar19 - 1,
           uVar19 == 0)) {
          uVar29 = 0;
        }
        uVar19 = 0;
        if (M<UInt16>(self + 0x13e) != 0) {
          uVar19 = M<UInt16>(self + 0x13e) - 1;
        }
        M<UInt32>(iVar44 + 0x2d0) =
             uVar17 - 1 & 0x3fff | (uVar29 & 0x800) << 4 | (uVar19 & 0x800) << 5;
        dVar54 = (double)FLOAT_0004c37c;
        iVar28 = iVar26 * 4 + 0x30 >> 2;
        uVar16 = M<UInt32>(M<SInt32>(self + 0xd50) + 0xb74);
        M<UInt32>(iVar44 + 0x2b0) = M<UInt32>(iVar44 + 0x2b0) & 0xffffe1ff | 0x1400;
        M<UInt32>(iVar44 + 0x3c) = 0x70000;
        M<UInt32>(iVar44 + 0x54) = uVar16;
        surfaceWidth = M<SInt16>(self + 0xbd4);
        surfaceHeight = M<SInt16>(self + 0xbd6);
        batchWords[iVar26] = 0x31080;
        batchWords[iVar26 + 5] = 0x1087;
        batchWords[iVar26 + 1] = FBITS((float)zero);
        batchWords[iVar26 + 2] = FBITS((float)one);
        batchWords[iVar26 + 3] = FBITS((float)one);
        batchWords[iVar26 + 4] = FBITS((float)zero);
        dVar47 = (double)(float)((double)CONCAT44d(0x43300000,(SInt32)surfaceWidth ^ 0x80000000) - signedIntBias);
        dVar55 = (double)(float)((double)CONCAT44d(0x43300000,(SInt32)surfaceHeight ^ 0x80000000) - signedIntBias);
        batchWords[iVar26 + 7] = 0xc0033500;
        batchWords[iVar26 + 8] = 0x10031;
        batchWords[iVar26 + 9] = FBITS((float)((double)(float)(dVar47 + zero) * half));
        batchWords[iVar26 + 10] = FBITS((float)((double)(float)(dVar55 + zero) * half));
        batchWords[iVar26 + 0xb] = 0;
        batchWords[iVar26 + 6] = (SInt32)(dVar47 * dVar54) << 0x10 | (SInt32)(dVar55 * dVar54);
        batchWords[iVar28] = 0x1393;
        batchWords[iVar28 + 1] = 10;
        batchWords[iVar28 + 2] = 0x5c8;
        iVar44 = iVar28 + 4;
        batchWords[iVar28 + 3] = 0x70000;
      }
      M<SInt32>((SInt32)Vol(batchEntry->header) + 0x18) = iVar44;
      if (panelRec->active != 0x0) {
        iVar26 = iVar44;
        if (self[0xbed] == 0x0) {
          iVar28 = M<SInt32>(self + 0xd50);
        }
        else {
          iVar28 = M<SInt32>(self + 0xd50);
          if ((M<char>(iVar28 + 0x9b0) == '\0') ||
             (M<SInt32>(panel * 0x18 + iVar28 + 0xb10) == 0)) {
            if ((SInt32)uVar38 < 0) {
              uVar29 = 0;
              uVar19 = uVar40;
            }
            else {
              uVar29 = uVar38;
              uVar19 = uVar38 + uVar40;
            }
            uVar17 = (UInt32)M<UInt16>(iVar32 + 0x14a);
            if (uVar17 < uVar29) {
              uVar29 = uVar17;
            }
            if (uVar17 < uVar19) {
              uVar19 = uVar17;
            }
            batchWords[iVar44] = 0x1393;
            batchWords[iVar44 + 1] = 10;
            batchWords[iVar44 + 2] = 0xd0b;
            batchWords[iVar44 + 3] = 5;
            batchWords[iVar44 + 4] = 0x5c8;
            iVar26 = iVar44 + 6;
            batchWords[iVar44 + 5] = 0x70000;
            if ((bool)(bVar46 >> 1 & 1)) {
              iVar18 = M<SInt32>(iVar28 + 0x894);
              if (iVar18 == 0) {
                batchWords[iVar26] = 0x194e;
                batchWords[iVar44 + 7] =
                     uVar29 & ~M<UInt32>(iVar28 + 0x898) |
                     (uVar19 & ~M<UInt32>(iVar28 + 0x898)) << 0x10 | 0x80000000;
                batchWords[iVar44 + 8] = 0x5c8;
                iVar26 = iVar44 + 10;
                batchWords[iVar44 + 9] = 8;
              }
              else {
LAB_0003f644:
                if (iVar18 != 0) goto LAB_0003f654;
              }
            }
            else {
              if (panel != 1) {
                iVar18 = M<SInt32>(iVar28 + 0x894);
                goto LAB_0003f644;
              }
LAB_0003f654:
              batchWords[iVar26] = 0x1b4e;
              batchWords[iVar44 + 7] =
                   uVar29 & ~M<UInt32>(iVar28 + 0x89c) |
                   (uVar19 & ~M<UInt32>(iVar28 + 0x89c)) << 0x10 | 0x80000000;
              batchWords[iVar44 + 8] = 0x5c8;
              batchWords[iVar44 + 9] = 0x80000008;
              iVar26 = iVar44 + 10;
            }
          }
        }
        if (M<SInt32>(self + 0xbe0) == M<SInt32>(self + 0xbe4)) {
          heightRatio = 1.0;
          widthRatio = 1.0;
        }
        else {
          widthRatio = FLOAT_0004c370;
          if ((SInt32)M<SInt16>(self + 0xbe4) != 0) {
            widthRatio = (float)((double)CONCAT44d(0x43300000,(SInt32)M<SInt16>(self + 0xbe0) ^ 0x80000000)
                           - DOUBLE_0004c3a8) /
                    (float)((double)CONCAT44d(0x43300000,(SInt32)M<SInt16>(self + 0xbe4) ^ 0x80000000)
                           - DOUBLE_0004c3a8);
          }
          heightRatio = 0.0;
          if ((SInt32)M<SInt16>(self + 0xbe6) != 0) {
            heightRatio = (float)((double)CONCAT44d(0x43300000,(SInt32)M<SInt16>(self + 0xbe2) ^ 0x80000000)
                            - DOUBLE_0004c3a8) /
                     (float)((double)CONCAT44d(0x43300000,(SInt32)M<SInt16>(self + 0xbe6) ^ 0x80000000)
                            - signedIntBias);
          }
        }
        uVar29 = (UInt32)M<UInt8>(surfaceBuffer + 0x3a);
        uVar19 = (UInt32)M<UInt8>(iVar32 + 0x166);
        uVar16 = M<UInt32>(iVar28 + 0xb74);
        if (uVar29 == uVar19) {
          bVar1 = false;
          uVar17 = uVar19;
        }
        else {
          bVar1 = ((FormatTableLookup_0x0004d2d8(uVar19 * 0x1c) ^
                   FormatTableLookup_0x0004d2d8(uVar29 * 0x1c)) & 0xffffc000) != 0;
          uVar17 = uVar29;
        }
        uVar15 = (UInt32)M<UInt16>(surfaceBuffer + 0x1e);
        uVar42 = (UInt32)M<UInt16>(surfaceBuffer + 0x1c);
        iVar44 = M<SInt32>(iVar32 + 0x16c);
        uVar13 = M<UInt16>(iVar32 + 0x14c);
        iVar18 = M<SInt32>(iVar32 + 0x134);
        bVar2 = (M<UInt32>(iVar32 + 0x168) & 0xf00000) == 0;
        if (bVar2) {
          uVar30 = 0;
        }
        else {
          uVar30 = (UInt32)M<UInt16>(iVar32 + 0x140) / (M<UInt32>(iVar32 + 0x168) >> 0x14 & 0xf);
        }
        uVar20 = 0x20 / M<UInt16>(iVar32 + 0x142);
        if (uVar20 <= uVar30) {
          uVar20 = uVar30;
        }
        uVar19 = FormatTableLookup_0x0004d2e0(uVar19 * 0x1c);
        bVar46 = M<UInt8>(iVar32 + 0x164);
        bVar6 = M<UInt8>(iVar32 + 0x165);
        if ((bVar2) ||
           (uVar21 = (UInt32)M<UInt16>(iVar32 + 0x148) / (M<UInt32>(iVar32 + 0x168) >> 0x14 & 0xf),
           uVar30 = uVar21 - 1, uVar21 == 0)) {
          uVar30 = 0;
        }
        uVar21 = 0;
        if (M<UInt16>(iVar32 + 0x14a) != 0) {
          uVar21 = M<UInt16>(iVar32 + 0x14a) - 1;
        }
        uVar14 = M<UInt16>(surfaceBuffer + 0x20);
        iVar32 = M<SInt32>(surfaceBuffer + 0x40);
        iVar33 = M<SInt32>(surfaceBuffer + 8);
        bVar7 = M<UInt8>(surfaceBuffer + 0x38);
        bVar2 = (M<UInt32>(surfaceBuffer + 0x3c) & 0xf00000) == 0;
        if ((bVar2) ||
           (uVar22 = uVar42 / (M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf), uVar23 = uVar22 - 1,
           uVar22 == 0)) {
          uVar23 = 0;
        }
        if (uVar15 != 0) {
          uVar22 = uVar15 - 1;
        }
        else {
          uVar22 = 0;
        }
        uVar17 = FormatTableLookup_0x0004d2e4(uVar17 * 0x1c);
        if (bVar2) {
          uVar24 = 0;
        }
        else {
          uVar24 = (UInt32)M<UInt16>(surfaceBuffer + 0x14) / (M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf);
        }
        uVar31 = 0x20 / M<UInt16>(surfaceBuffer + 0x16);
        if (uVar31 <= uVar24) {
          uVar31 = uVar24;
        }
        if ((bVar2) ||
           (uVar24 = uVar42 / (M<UInt32>(surfaceBuffer + 0x3c) >> 0x14 & 0xf), uVar25 = uVar24 - 1,
           uVar24 == 0)) {
          uVar25 = 0;
        }
        if (uVar15 != 0) {
          uVar24 = uVar15 - 1;
        }
        else {
          uVar24 = 0;
        }
        dVar66 = (double)(float)((double)CONCAT44d(0x43300000,uVar42) - DOUBLE_0004c3b0);
        dVar68 = (double)(float)((double)CONCAT44d(0x43300000,(SInt32)regionX ^ 0x80000000) - signedIntBias);
        dVar67 = (double)(float)((double)CONCAT44d(0x43300000,uVar38 ^ 0x80000000) - signedIntBias);
        dVar47 = (double)(float)((double)CONCAT44d(0x43300000,(SInt32)regionWidth ^ 0x80000000) - signedIntBias);
        dVar55 = (double)FLOAT_0004c370;
        blitPacket = batchWords + iVar26;
        dVar54 = (double)(float)((double)CONCAT44d(0x43300000,uVar40 ^ 0x80000000) - signedIntBias);
        dVar65 = (double)(float)((double)CONCAT44d(0x43300000,uVar15) - DOUBLE_0004c3b0);
        dVar61 = (double)(float)((double)CONCAT44d(0x43300000,
                                                  (SInt32)M<SInt16>(self + 0xbdc) ^ 0x80000000) -
                                signedIntBias);
        dVar62 = (double)(float)((double)CONCAT44d(0x43300000,
                                                  (SInt32)M<SInt16>(self + 0xbde) ^ 0x80000000) -
                                signedIntBias);
        dVar63 = (double)widthRatio;
        dVar64 = (double)heightRatio;
        iVar43 = M<SInt32>(iVar28 + 0x8c4);
        if (dVar66 != dVar55) {
          dVar55 = (double)(float)(one / dVar66);
        }
        dVar59 = (double)FLOAT_0004c370;
        if (dVar65 != dVar59) {
          dVar59 = (double)(float)(one / dVar65);
        }
        iVar26 = 0xbd;
        GCopy(blitPacket,(&g_r500_3d_blit_state_packet),0x2f4);
        uVar38 = blitPacket[0xa2];
        blitPacket[0xa0] = (bVar7 & 7) << 2 | (UInt32)uVar14 * iVar32 + iVar33 & 0xffffffe0;
        blitPacket[0xa6] = uVar23 & 0x7ff | (uVar22 & 0x7ff) << 0xb | 0x80000000;
        blitPacket[0xa8] =
             uVar17 >> 0x13 & 0x1f | (uVar17 & 0x40) << 0x10 | uVar17 >> 7 & 0xe00 |
             uVar17 >> 1 & 0x7000 | (uVar17 & 0x1c00) << 5 | (uVar17 & 0x380) << 0xb;
        blitPacket[0xaa] = uVar31 - 1 & 0x3fff | (uVar25 & 0x800) << 4 | (uVar24 & 0x800) << 5;
        blitPacket[0x9c] =
             uVar20 & 0x3ffe | (bVar46 & 1) << 0x10 | (bVar46 & 6) << 0x10 | (bVar6 & 3) << 0x13 |
             uVar19 >> 1 & 0x1e00000;
        blitPacket[0x9a] = (UInt32)uVar13 * iVar44 + iVar18 & 0xffffffe0;
        blitPacket[0x8a] =
             (uVar19 & 0x600) << 5 |
             (uVar19 & 0x1800) << 1 |
             uVar19 >> 3 & 0xc00 | uVar19 >> 7 & 0x300 | uVar19 >> 0x11 & 0x1f;
        blitPacket[0xb2] = 0;
        blitPacket[0xb3] = uVar30 & 0x1fff | (uVar21 & 0x1fff) << 0xd;
        blitPacket[0xb] = uVar16;
        blitPacket[0xa2] = iVar35 << 9 | uVar38 & 0xfffff9ff;
        blitPacket[0xa2] = iVar35 << 0xb | iVar35 << 9 | uVar38 & 0xffffe1ff;
        if (bVar1) {
          blitPacket[0x1e] = blitPacket[0x1e] & 0xfffffffc | 2;
        }
        dVar48 = (double)FLOAT_0004c378;
        if (((dVar48 < dVar66) && (iVar43 != 0)) || (dVar48 < dVar65)) {
          if (dVar66 <= (double)FLOAT_0004c378) {
            uVar19 = FormatTableLookup_0x0004d2dc(uVar29 * 0x1c);
            uVar29 = blitPacket[0xaa];
            uVar40 = (SInt32)dVar65 >> 1;
            uVar38 = uVar40 & 0xffffffc0;
            uVar42 = (SInt32)dVar65 - uVar38;
            uVar17 = uVar38 + 1;
            dVar65 = dVar67;
            if (dVar64 != zero) {
              dVar65 = (double)(float)(dVar67 + (double)(float)((double)(float)((double)(float)((
                                                  double)CONCAT44d(0x43300000,
                                                                  uVar38 + uVar17 ^ 0x80000000) -
                                                  signedIntBias) * half + dVar62) / dVar64));
            }
            if (dVar65 <= zero) {
              dVar65 = dVar65 - half;
            }
            else {
              dVar65 = dVar65 + half;
            }
            dVar66 = (double)(float)((double)(float)((double)CONCAT44d(0x43300000,
                                                                      (SInt32)dVar65 ^ 0x80000000) -
                                                    signedIntBias) - dVar67);
            blitPacket[0xa6] = (uVar40 & 0x7c0) << 0xb | blitPacket[0xa6] & 0xffc007ff;
            blitPacket[0xbd] = 0x1040;
            iVar32 = 0xbf;
            blitPacket[0xbe] = 0;
            dVar65 = DOUBLE_0004c3a8;
            fVar4 = FLOAT_0004c380;
            heightRatio = FLOAT_0004c37c;
            widthRatio = FLOAT_0004c370;
            if (uVar17 != 0) {
              widthRatio = (float)(one / (double)(float)((double)CONCAT44d(0x43300000,
                                                                        uVar17 ^ 0x80000000) -
                                                      signedIntBias));
            }
            if (iVar34 != 0) {
              dVar59 = (double)(float)(dVar68 + dVar47);
              dVar48 = (double)(float)(dVar67 + dVar66);
              packetIndex = iVar32;
              piVar27 = local_100;
              iVar35 = iVar34;
              do {
                dVar50 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)M<SInt16>(piVar27) ^ 0x80000000) -
                                        dVar65);
                fVar3 = (float)(dVar68 - dVar50);
                dVar49 = dVar68;
                if (fVar3 < 0.0) {
                  dVar49 = dVar50;
                }
                if (-fVar3 < 0.0) {
                  dVar49 = dVar68;
                }
                dVar52 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)(SInt16)*piVar27 ^ 0x80000000) -
                                        dVar65);
                fVar3 = (float)(dVar67 - dVar52);
                dVar50 = dVar67;
                if (fVar3 < 0.0) {
                  dVar50 = dVar52;
                }
                if (-fVar3 < 0.0) {
                  dVar50 = dVar67;
                }
                dVar51 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)M<SInt16>(piVar27) +
                                                          (SInt32)M<SInt16>(piVar27 + 1) ^ 0x80000000)
                                        - dVar65);
                fVar3 = (float)(dVar51 - dVar59);
                dVar52 = dVar59;
                if (fVar3 < 0.0) {
                  dVar52 = dVar51;
                }
                if (-fVar3 < 0.0) {
                  dVar52 = dVar59;
                }
                dVar53 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)(SInt16)*piVar27 +
                                                          (SInt32)M<SInt16>((SInt32)piVar27 + 6) ^
                                                          0x80000000) - dVar65);
                fVar3 = (float)(dVar53 - dVar48);
                dVar51 = dVar48;
                if (fVar3 < 0.0) {
                  dVar51 = dVar53;
                }
                if (-fVar3 < 0.0) {
                  dVar51 = dVar48;
                }
                iVar32 = packetIndex;
                if ((FLOAT_0004c370 < (float)(dVar52 - dVar49)) &&
                   (FLOAT_0004c370 < (float)(dVar51 - dVar50))) {
                  blitPacket[packetIndex] = 0x31080;
                  blitPacket[packetIndex + 5] = 0x1087;
                  iVar32 = packetIndex * 4 + 0x30 >> 2;
                  blitPacket[packetIndex + 1] = FBITS((float)(dVar55 * (double)(float)(dVar63 * (double)(float)(dVar49 - dVar68) -
                                                       dVar61)));
                  blitPacket[packetIndex + 2] =
                       FBITS(widthRatio * (float)(dVar64 * (double)(float)(dVar51 - dVar67) - dVar62));
                  blitPacket[packetIndex + 3] = FBITS((float)(dVar55 * (double)(float)(dVar63 * (double)(float)(dVar52 - dVar68) -
                                                       dVar61)));
                  blitPacket[packetIndex + 4] =
                       FBITS(widthRatio * (float)(dVar64 * (double)(float)(dVar50 - dVar67) - dVar62));
                  blitPacket[packetIndex + 7] = 0xc0033500;
                  blitPacket[packetIndex + 9] = FBITS((float)(dVar49 + dVar52) * fVar4);
                  blitPacket[packetIndex + 10] = FBITS((float)(dVar50 + dVar51) * fVar4);
                  blitPacket[packetIndex + 8] = 0x10031;
                  blitPacket[packetIndex + 0xb] = 0;
                  blitPacket[packetIndex + 6] =
                       (SInt32)((float)(dVar52 - dVar49) * heightRatio) << 0x10 |
                       (SInt32)((float)(dVar51 - dVar50) * heightRatio);
                }
                piVar27 = piVar27 + 2;
                iVar35 = iVar35 + -1;
                packetIndex = iVar32;
              } while (iVar35 != 0);
            }
            textureOffsetWord = blitPacket[0xa0];
            blitPacket[iVar32] = 0x1150;
            blitPacket[iVar32 + 1] =
                 textureOffsetWord + (uVar38 * ((uVar29 & 0x3fff) + 1) << (uVar19 >> 0xc & 7) & 0xffffffe0);
            uVar40 = blitPacket[0xa6];
            blitPacket[iVar32 + 2] = 0x1120;
            blitPacket[iVar32 + 3] = (uVar42 - 1) * 0x800 & 0x3ff800 | uVar40 & 0xffc007ff;
            blitPacket[iVar32 + 4] = 0x1040;
            iVar26 = iVar32 + 6;
            blitPacket[iVar32 + 5] = 0;
            dVar65 = DOUBLE_0004c3a8;
            fVar4 = FLOAT_0004c380;
            heightRatio = FLOAT_0004c37c;
            widthRatio = FLOAT_0004c370;
            if (uVar42 != 0) {
              widthRatio = (float)(one / (double)(float)((double)CONCAT44d(0x43300000,
                                                                        uVar42 ^ 0x80000000) -
                                                      signedIntBias));
            }
            dVar62 = (double)(float)(dVar62 + (double)(float)((double)CONCAT44d(0x43300000,
                                                                               uVar38 ^ 0x80000000)
                                                             - signedIntBias));
            if (iVar34 != 0) {
              dVar66 = (double)(float)(dVar67 + dVar66);
              dVar47 = (double)(float)(dVar68 + dVar47);
              dVar54 = (double)(float)(dVar67 + dVar54);
              iVar32 = iVar26;
              iVar43 = iVar34;
              do {
                dVar48 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)M<SInt16>(local_100) ^ 0x80000000) -
                                        dVar65);
                fVar3 = (float)(dVar68 - dVar48);
                dVar59 = dVar68;
                if (fVar3 < 0.0) {
                  dVar59 = dVar48;
                }
                if (-fVar3 < 0.0) {
                  dVar59 = dVar68;
                }
                dVar48 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)(SInt16)*local_100 ^ 0x80000000) -
                                        dVar65);
                fVar3 = (float)(dVar48 - dVar66);
                if (fVar3 < 0.0) {
                  dVar48 = dVar66;
                }
                dVar49 = dVar66;
                if (-fVar3 < 0.0) {
                  dVar49 = dVar48;
                }
                dVar50 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)M<SInt16>(local_100) +
                                                          (SInt32)M<SInt16>(local_100 + 1) ^
                                                          0x80000000) - dVar65);
                fVar3 = (float)(dVar50 - dVar47);
                dVar48 = dVar47;
                if (fVar3 < 0.0) {
                  dVar48 = dVar50;
                }
                if (-fVar3 < 0.0) {
                  dVar48 = dVar47;
                }
                dVar52 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)(SInt16)*local_100 +
                                                          (SInt32)M<SInt16>((SInt32)local_100 + 6) ^
                                                          0x80000000) - dVar65);
                fVar3 = (float)(dVar52 - dVar54);
                dVar50 = dVar54;
                if (fVar3 < 0.0) {
                  dVar50 = dVar52;
                }
                if (-fVar3 < 0.0) {
                  dVar50 = dVar54;
                }
                iVar26 = iVar32;
                if ((FLOAT_0004c370 < (float)(dVar48 - dVar59)) &&
                   (FLOAT_0004c370 < (float)(dVar50 - dVar49))) {
                  blitPacket[iVar32] = 0x31080;
                  blitPacket[iVar32 + 5] = 0x1087;
                  iVar26 = iVar32 * 4 + 0x30 >> 2;
                  blitPacket[iVar32 + 1] = FBITS((float)(dVar55 * (double)(float)(dVar63 * (double)(float)(dVar59 - dVar68) -
                                                       dVar61)));
                  blitPacket[iVar32 + 2] =
                       FBITS(widthRatio * (float)(dVar64 * (double)(float)(dVar50 - dVar67) - dVar62));
                  blitPacket[iVar32 + 3] = FBITS((float)(dVar55 * (double)(float)(dVar63 * (double)(float)(dVar48 - dVar68) -
                                                       dVar61)));
                  blitPacket[iVar32 + 4] =
                       FBITS(widthRatio * (float)(dVar64 * (double)(float)(dVar49 - dVar67) - dVar62));
                  blitPacket[iVar32 + 7] = 0xc0033500;
                  blitPacket[iVar32 + 9] = FBITS((float)(dVar59 + dVar48) * fVar4);
                  blitPacket[iVar32 + 10] = FBITS((float)(dVar49 + dVar50) * fVar4);
                  blitPacket[iVar32 + 8] = 0x10031;
                  blitPacket[iVar32 + 0xb] = 0;
                  blitPacket[iVar32 + 6] =
                       (SInt32)((float)(dVar48 - dVar59) * heightRatio) << 0x10 |
                       (SInt32)((float)(dVar50 - dVar49) * heightRatio);
                }
                local_100 = local_100 + 2;
                iVar43 = iVar43 + -1;
                iVar32 = iVar26;
              } while (iVar43 != 0);
            }
          }
          else {
            uVar38 = (SInt32)dVar66 >> 1 & 0xfffffe00;
            uVar19 = (SInt32)dVar66 - uVar38;
            uVar40 = uVar38 + 2;
            if ((blitPacket[0xa0] & 0x18) == 0) {
              uVar29 = FormatTableLookup_0x0004d2dc(uVar29 * 0x1c);
              iVar32 = 0;
            }
            else {
              uVar29 = FormatTableLookup_0x0004d2dc(uVar29 * 0x1c);
              iVar32 = -(uVar29 >> 8 & 3);
            }
            iVar43 = (SInt32)uVar38 >> ((iVar32 - (uVar29 >> 0xc & 7)) + 5 & 0x3f);
            iVar32 = iVar43 << 5;
            if (((UInt32)blitPacket[0xa0] >> 2 & 1) != 0) {
              iVar32 = (iVar43 << 0xc) >> 3;
            }
            dVar55 = dVar68;
            if (dVar63 != zero) {
              dVar55 = (double)(float)(dVar68 + (double)(float)((double)(float)((double)(float)((
                                                  double)CONCAT44d(0x43300000,
                                                                  uVar38 + uVar40 ^ 0x80000000) -
                                                  signedIntBias) * half + dVar61) / dVar63));
            }
            if (dVar55 <= zero) {
              dVar55 = dVar55 - half;
            }
            else {
              dVar55 = dVar55 + half;
            }
            dVar65 = (double)(float)((double)(float)((double)CONCAT44d(0x43300000,
                                                                      (SInt32)dVar55 ^ 0x80000000) -
                                                    signedIntBias) - dVar68);
            blitPacket[0xa6] = uVar38 + 1 & 0x7ff | blitPacket[0xa6] & 0xfffff800;
            dVar55 = DOUBLE_0004c3a8;
            fVar4 = FLOAT_0004c380;
            heightRatio = FLOAT_0004c37c;
            widthRatio = FLOAT_0004c370;
            if (uVar40 != 0) {
              widthRatio = (float)(one / (double)(float)((double)CONCAT44d(0x43300000,
                                                                        uVar40 ^ 0x80000000) -
                                                      signedIntBias));
            }
            if (iVar34 != 0) {
              dVar66 = (double)(float)(dVar68 + dVar65);
              dVar48 = (double)(float)(dVar67 + dVar54);
              piVar27 = local_100;
              packetIndex = iVar26;
              iVar35 = iVar34;
              do {
                dVar50 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)M<SInt16>(piVar27) ^ 0x80000000) -
                                        dVar55);
                fVar3 = (float)(dVar68 - dVar50);
                dVar49 = dVar68;
                if (fVar3 < 0.0) {
                  dVar49 = dVar50;
                }
                if (-fVar3 < 0.0) {
                  dVar49 = dVar68;
                }
                dVar52 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)(SInt16)*piVar27 ^ 0x80000000) -
                                        dVar55);
                fVar3 = (float)(dVar67 - dVar52);
                dVar50 = dVar67;
                if (fVar3 < 0.0) {
                  dVar50 = dVar52;
                }
                if (-fVar3 < 0.0) {
                  dVar50 = dVar67;
                }
                dVar51 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)M<SInt16>(piVar27) +
                                                          (SInt32)M<SInt16>(piVar27 + 1) ^ 0x80000000)
                                        - dVar55);
                fVar3 = (float)(dVar51 - dVar66);
                dVar52 = dVar66;
                if (fVar3 < 0.0) {
                  dVar52 = dVar51;
                }
                if (-fVar3 < 0.0) {
                  dVar52 = dVar66;
                }
                dVar51 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)(SInt16)*piVar27 +
                                                          (SInt32)M<SInt16>((SInt32)piVar27 + 6) ^
                                                          0x80000000) - dVar55);
                fVar3 = (float)(dVar48 - dVar51);
                if (fVar3 < 0.0) {
                  dVar51 = dVar48;
                }
                dVar53 = dVar48;
                if (-fVar3 < 0.0) {
                  dVar53 = dVar51;
                }
                iVar26 = packetIndex;
                if ((FLOAT_0004c370 < (float)(dVar52 - dVar49)) &&
                   (FLOAT_0004c370 < (float)(dVar53 - dVar50))) {
                  blitPacket[packetIndex] = 0x31080;
                  blitPacket[packetIndex + 5] = 0x1087;
                  iVar26 = packetIndex * 4 + 0x30 >> 2;
                  blitPacket[packetIndex + 1] =
                       FBITS(widthRatio * (float)(dVar63 * (double)(float)(dVar49 - dVar68) - dVar61));
                  blitPacket[packetIndex + 2] = FBITS((float)(dVar59 * (double)(float)(dVar64 * (double)(float)(dVar53 - dVar67) -
                                                       dVar62)));
                  blitPacket[packetIndex + 3] =
                       FBITS(widthRatio * (float)(dVar63 * (double)(float)(dVar52 - dVar68) - dVar61));
                  blitPacket[packetIndex + 4] = FBITS((float)(dVar59 * (double)(float)(dVar64 * (double)(float)(dVar50 - dVar67) -
                                                       dVar62)));
                  blitPacket[packetIndex + 7] = 0xc0033500;
                  blitPacket[packetIndex + 9] = FBITS((float)(dVar49 + dVar52) * fVar4);
                  blitPacket[packetIndex + 10] = FBITS((float)(dVar50 + dVar53) * fVar4);
                  blitPacket[packetIndex + 8] = 0x10031;
                  blitPacket[packetIndex + 0xb] = 0;
                  blitPacket[packetIndex + 6] =
                       (SInt32)((float)(dVar52 - dVar49) * heightRatio) << 0x10 |
                       (SInt32)((float)(dVar53 - dVar50) * heightRatio);
                }
                piVar27 = piVar27 + 2;
                iVar35 = iVar35 + -1;
                packetIndex = iVar26;
              } while (iVar35 != 0);
            }
            textureOffsetWord = blitPacket[0xa0];
            blitPacket[iVar26] = 0x1150;
            blitPacket[iVar26 + 1] = textureOffsetWord + iVar32;
            uVar40 = blitPacket[0xa6];
            blitPacket[iVar26 + 2] = 0x1120;
            iVar32 = iVar26 + 3;
            iVar26 = iVar26 + 4;
            blitPacket[iVar32] = uVar19 - 1 & 0x7ff | uVar40 & 0xfffff800;
            dVar55 = DOUBLE_0004c3a8;
            fVar4 = FLOAT_0004c380;
            heightRatio = FLOAT_0004c37c;
            widthRatio = FLOAT_0004c370;
            if (uVar19 != 0) {
              widthRatio = (float)(one / (double)(float)((double)CONCAT44d(0x43300000,
                                                                        uVar19 ^ 0x80000000) -
                                                      signedIntBias));
            }
            dVar61 = (double)(float)(dVar61 + (double)(float)((double)CONCAT44d(0x43300000,
                                                                               uVar38 ^ 0x80000000)
                                                             - signedIntBias));
            if (iVar34 != 0) {
              dVar65 = (double)(float)(dVar68 + dVar65);
              dVar47 = (double)(float)(dVar68 + dVar47);
              dVar54 = (double)(float)(dVar67 + dVar54);
              iVar32 = iVar26;
              iVar43 = iVar34;
              do {
                dVar48 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)M<SInt16>(local_100) ^ 0x80000000) -
                                        dVar55);
                fVar3 = (float)(dVar65 - dVar48);
                dVar66 = dVar65;
                if (fVar3 < 0.0) {
                  dVar66 = dVar48;
                }
                if (-fVar3 < 0.0) {
                  dVar66 = dVar65;
                }
                dVar49 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)(SInt16)*local_100 ^ 0x80000000) -
                                        dVar55);
                fVar3 = (float)(dVar67 - dVar49);
                dVar48 = dVar67;
                if (fVar3 < 0.0) {
                  dVar48 = dVar49;
                }
                if (-fVar3 < 0.0) {
                  dVar48 = dVar67;
                }
                dVar49 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)M<SInt16>(local_100) +
                                                          (SInt32)M<SInt16>(local_100 + 1) ^
                                                          0x80000000) - dVar55);
                fVar3 = (float)(dVar47 - dVar49);
                if (fVar3 < 0.0) {
                  dVar49 = dVar47;
                }
                dVar50 = dVar47;
                if (-fVar3 < 0.0) {
                  dVar50 = dVar49;
                }
                dVar49 = (double)(float)((double)CONCAT44d(0x43300000,
                                                          (SInt32)(SInt16)*local_100 +
                                                          (SInt32)M<SInt16>((SInt32)local_100 + 6) ^
                                                          0x80000000) - dVar55);
                fVar3 = (float)(dVar54 - dVar49);
                if (fVar3 < 0.0) {
                  dVar49 = dVar54;
                }
                dVar52 = dVar54;
                if (-fVar3 < 0.0) {
                  dVar52 = dVar49;
                }
                iVar26 = iVar32;
                if ((FLOAT_0004c370 < (float)(dVar50 - dVar66)) &&
                   (FLOAT_0004c370 < (float)(dVar52 - dVar48))) {
                  blitPacket[iVar32] = 0x31080;
                  blitPacket[iVar32 + 5] = 0x1087;
                  iVar26 = iVar32 * 4 + 0x30 >> 2;
                  blitPacket[iVar32 + 1] =
                       FBITS(widthRatio * (float)(dVar63 * (double)(float)(dVar66 - dVar68) - dVar61));
                  blitPacket[iVar32 + 2] = FBITS((float)(dVar59 * (double)(float)(dVar64 * (double)(float)(dVar52 - dVar67) -
                                                       dVar62)));
                  blitPacket[iVar32 + 3] =
                       FBITS(widthRatio * (float)(dVar63 * (double)(float)(dVar50 - dVar68) - dVar61));
                  blitPacket[iVar32 + 4] = FBITS((float)(dVar59 * (double)(float)(dVar64 * (double)(float)(dVar48 - dVar67) -
                                                       dVar62)));
                  blitPacket[iVar32 + 7] = 0xc0033500;
                  blitPacket[iVar32 + 9] = FBITS((float)(dVar66 + dVar50) * fVar4);
                  blitPacket[iVar32 + 10] = FBITS((float)(dVar48 + dVar52) * fVar4);
                  blitPacket[iVar32 + 8] = 0x10031;
                  blitPacket[iVar32 + 0xb] = 0;
                  blitPacket[iVar32 + 6] =
                       (SInt32)((float)(dVar50 - dVar66) * heightRatio) << 0x10 |
                       (SInt32)((float)(dVar52 - dVar48) * heightRatio);
                }
                local_100 = local_100 + 2;
                iVar43 = iVar43 + -1;
                iVar32 = iVar26;
              } while (iVar43 != 0);
            }
          }
        }
        else {
          if (dVar48 < dVar66) {
            uVar38 = (UInt32)dVar66;
            uVar40 = (SInt32)uVar38 >> 1 & 0xfffffe00;
            uVar17 = uVar40 + 2;
            uVar19 = uVar38 - uVar40;
            if ((blitPacket[0xa0] & 0x18) == 0) {
              uVar29 = FormatTableLookup_0x0004d2dc(uVar29 * 0x1c);
              iVar32 = 0;
            }
            else {
              uVar29 = FormatTableLookup_0x0004d2dc(uVar29 * 0x1c);
              iVar32 = -(uVar29 >> 8 & 3);
            }
            iVar43 = (SInt32)uVar40 >> ((iVar32 - (uVar29 >> 0xc & 7)) + 5 & 0x3f);
            iVar32 = iVar43 << 5;
            if (((UInt32)blitPacket[0xa0] >> 2 & 1) != 0) {
              iVar32 = (iVar43 << 0xc) >> 3;
            }
            widthRatio = FLOAT_0004c370;
            if (uVar17 != 0) {
              widthRatio = (float)((double)CONCAT44d(0x43300000,uVar38 ^ 0x80000000) - signedIntBias) /
                      (float)((double)CONCAT44d(0x43300000,uVar17 ^ 0x80000000) - signedIntBias);
            }
            heightRatio = FLOAT_0004c370;
            if (uVar19 != 0) {
              heightRatio = (float)((double)CONCAT44d(0x43300000,uVar38 ^ 0x80000000) - signedIntBias) /
                       (float)((double)CONCAT44d(0x43300000,uVar19 ^ 0x80000000) - signedIntBias);
            }
            fVar4 = FLOAT_0004c3a0;
            fVar3 = FLOAT_0004c3a0;
            if (uVar38 != 0) {
              fVar3 = (float)((double)CONCAT44d(0x43300000,uVar38 ^ 0x80000000) - signedIntBias);
              fVar4 = -((float)((double)CONCAT44d(0x43300000,uVar40 ^ 0x80000000) - signedIntBias) / fVar3);
              fVar3 = -((float)((double)(float)((double)CONCAT44d(0x43300000,
                                                                 uVar40 + uVar17 ^ 0x80000000) -
                                               signedIntBias) * half) / fVar3);
            }
            blitPacket[0xdb] = 0x1040;
            blitPacket[0xcf] = 0x1101;
            blitPacket[0xc0] = FBITS(widthRatio);
            blitPacket[0xd1] = 0x1111;
            blitPacket[0xc4] = 0x3f800000;
            blitPacket[0xd3] = 0x1121;
            blitPacket[200] = FBITS(heightRatio * fVar4);
            blitPacket[0xc6] = FBITS(heightRatio);
            blitPacket[0xce] = FBITS(fVar3);
            blitPacket[0xc2] = 0x3f800000;
            blitPacket[0xdc] = 0;
            blitPacket[0xbf] = 0x1095;
            blitPacket[0xc1] = 0x1095;
            blitPacket[0xc3] = 0x1095;
            blitPacket[0xc5] = 0x1095;
            blitPacket[199] = 0x1095;
            blitPacket[0xc9] = 0x1095;
            blitPacket[0xca] = 0;
            blitPacket[0xcb] = 0x1095;
            blitPacket[0xcc] = 0;
            blitPacket[0xd5] = 0x1131;
            blitPacket[0xd7] = 0x1141;
            blitPacket[0xbd] = 0x1094;
            blitPacket[0xd9] = 0x1151;
            blitPacket[0xbe] = 0x10000;
            blitPacket[0xcd] = 0x1095;
            blitPacket[0xd0] = blitPacket[0xa2];
            blitPacket[0xd2] = blitPacket[0xa4];
            iVar26 = 0xdd;
            blitPacket[0xd4] = blitPacket[0xa6];
            blitPacket[0xd6] = blitPacket[0xa8];
            blitPacket[0xd0] = blitPacket[0xa2] & 0xfffffff | 0x10000000;
            blitPacket[0xd8] = blitPacket[0xaa];
            blitPacket[0xda] = blitPacket[0xa0] + iVar32;
            blitPacket[0x3c] = 3;
            blitPacket[0xa6] = uVar40 + 1 & 0x7ff | blitPacket[0xa6] & 0xfffff800;
            blitPacket[0xd4] = uVar19 - 1 & 0x7ff | blitPacket[0xd4] & 0xfffff800;
            blitPacket[0x42] = 0x7800;
            blitPacket[0x4c] = 0x1c490010;
            blitPacket[0x48] = 0x442220;
            blitPacket[0x4a] = 0xc00000;
            blitPacket[0x46] = 0x10100000;
            blitPacket[0x54] = 0x29a220;
            blitPacket[0x40] = 0;
            blitPacket[0x41] = 0x1095;
            blitPacket[0x43] = 0x1095;
            blitPacket[0x45] = 0x1095;
            blitPacket[0x47] = 0x1095;
            blitPacket[0x4e] = 0x3800;
            blitPacket[0x50] = 0x10140000;
            blitPacket[0x3f] = 0x1094;
            blitPacket[0x44] = 0x40000;
            blitPacket[0x49] = 0x1095;
            blitPacket[0x52] = 0x40000;
            blitPacket[0x56] = 0x810000;
            blitPacket[0x4b] = 0x1095;
            blitPacket[0x4d] = 0x1095;
            blitPacket[0x4f] = 0x1095;
            blitPacket[0x51] = 0x1095;
            blitPacket[0x53] = 0x1095;
            blitPacket[0x55] = 0x1095;
            blitPacket[0x58] = 0x20222020;
            blitPacket[0x5e] = 0xe401e401;
            blitPacket[0x6a] = 0xe402e402;
            blitPacket[0x72] = 0x78105;
            blitPacket[0x76] = 0x100800;
            blitPacket[0x57] = 0x1095;
            blitPacket[0x59] = 0x1095;
            blitPacket[0x5b] = 0x1095;
            blitPacket[0x5d] = 0x1095;
            blitPacket[0x5f] = 0x1095;
            blitPacket[0x60] = 0;
            blitPacket[0x61] = 0x1095;
            blitPacket[0x62] = 0;
            blitPacket[99] = 0x1095;
            blitPacket[100] = 0;
            blitPacket[0x65] = 0x1095;
            blitPacket[0x67] = 0x1095;
            blitPacket[0x69] = 0x1095;
            blitPacket[0x6b] = 0x1095;
            blitPacket[0x6c] = 0;
            blitPacket[0x6d] = 0x1095;
            blitPacket[0x5a] = 0x7c03;
            blitPacket[0x5c] = 0x2400000;
            blitPacket[0x66] = 0x7c07;
            blitPacket[0x68] = 0x2410000;
            blitPacket[0x6e] = 0;
            blitPacket[0x6f] = 0x1095;
            blitPacket[0x83] = 0x118d;
            blitPacket[0x85] = 0x118e;
            blitPacket[0x70] = 0;
            blitPacket[0x71] = 0x1095;
            blitPacket[0x73] = 0x1095;
            blitPacket[0x74] = 0x100800;
            blitPacket[0x75] = 0x1095;
            blitPacket[0x77] = 0x1095;
            blitPacket[0x78] = 0x444221;
            blitPacket[0x7a] = 0x70d006;
            blitPacket[0x7c] = 0x1836c008;
            blitPacket[0x79] = 0x1095;
            blitPacket[0x7b] = 0x1095;
            blitPacket[0x84] = 0x40000;
            blitPacket[0x86] = 0;
            blitPacket[0x88] = 0x40000;
            blitPacket[0x87] = 0x118c;
            blitPacket[0x82] = 2;
          }
          dVar65 = DOUBLE_0004c3a8;
          heightRatio = FLOAT_0004c380;
          widthRatio = FLOAT_0004c37c;
          if (iVar34 != 0) {
            dVar47 = (double)(float)(dVar68 + dVar47);
            dVar54 = (double)(float)(dVar67 + dVar54);
            iVar32 = iVar26;
            iVar43 = iVar34;
            do {
              dVar48 = (double)(float)((double)CONCAT44d(0x43300000,
                                                        (SInt32)M<SInt16>(local_100) ^ 0x80000000) -
                                      dVar65);
              fVar4 = (float)(dVar68 - dVar48);
              dVar66 = dVar68;
              if (fVar4 < 0.0) {
                dVar66 = dVar48;
              }
              if (-fVar4 < 0.0) {
                dVar66 = dVar68;
              }
              dVar49 = (double)(float)((double)CONCAT44d(0x43300000,
                                                        (SInt32)(SInt16)*local_100 ^ 0x80000000) -
                                      dVar65);
              fVar4 = (float)(dVar67 - dVar49);
              dVar48 = dVar67;
              if (fVar4 < 0.0) {
                dVar48 = dVar49;
              }
              if (-fVar4 < 0.0) {
                dVar48 = dVar67;
              }
              dVar50 = (double)(float)((double)CONCAT44d(0x43300000,
                                                        (SInt32)M<SInt16>(local_100) +
                                                        (SInt32)M<SInt16>(local_100 + 1) ^ 0x80000000)
                                      - dVar65);
              fVar4 = (float)(dVar50 - dVar47);
              dVar49 = dVar47;
              if (fVar4 < 0.0) {
                dVar49 = dVar50;
              }
              if (-fVar4 < 0.0) {
                dVar49 = dVar47;
              }
              dVar52 = (double)(float)((double)CONCAT44d(0x43300000,
                                                        (SInt32)(SInt16)*local_100 +
                                                        (SInt32)M<SInt16>((SInt32)local_100 + 6) ^
                                                        0x80000000) - dVar65);
              fVar4 = (float)(dVar52 - dVar54);
              dVar50 = dVar54;
              if (fVar4 < 0.0) {
                dVar50 = dVar52;
              }
              if (-fVar4 < 0.0) {
                dVar50 = dVar54;
              }
              iVar26 = iVar32;
              if ((FLOAT_0004c370 < (float)(dVar49 - dVar66)) &&
                 (FLOAT_0004c370 < (float)(dVar50 - dVar48))) {
                blitPacket[iVar32] = 0x31080;
                blitPacket[iVar32 + 5] = 0x1087;
                iVar26 = iVar32 * 4 + 0x30 >> 2;
                blitPacket[iVar32 + 1] = FBITS((float)(dVar55 * (double)(float)(dVar63 * (double)(float)(dVar66 - dVar68) -
                                                     dVar61)));
                blitPacket[iVar32 + 2] = FBITS((float)(dVar59 * (double)(float)(dVar64 * (double)(float)(dVar50 - dVar67) -
                                                     dVar62)));
                blitPacket[iVar32 + 3] = FBITS((float)(dVar55 * (double)(float)(dVar63 * (double)(float)(dVar49 - dVar68) -
                                                     dVar61)));
                blitPacket[iVar32 + 4] = FBITS((float)(dVar59 * (double)(float)(dVar64 * (double)(float)(dVar48 - dVar67) -
                                                     dVar62)));
                blitPacket[iVar32 + 7] = 0xc0033500;
                blitPacket[iVar32 + 9] = FBITS((float)(dVar66 + dVar49) * heightRatio);
                blitPacket[iVar32 + 10] = FBITS((float)(dVar48 + dVar50) * heightRatio);
                blitPacket[iVar32 + 8] = 0x10031;
                blitPacket[iVar32 + 0xb] = 0;
                blitPacket[iVar32 + 6] =
                     (SInt32)((float)(dVar49 - dVar66) * widthRatio) << 0x10 |
                     (SInt32)((float)(dVar50 - dVar48) * widthRatio);
              }
              local_100 = local_100 + 2;
              iVar43 = iVar43 + -1;
              iVar32 = iVar26;
            } while (iVar43 != 0);
          }
        }
        blitPacket[iVar26] = 0x1393;
        blitPacket[iVar26 + 1] = 10;
        Vol(panelRec->entries[0].rectWordIndex) = (SInt32)blitPacket + (0x2c8 - (SInt32)batchWords) >> 2;
        iVar44 = (SInt32)blitPacket + ((iVar26 + 2) * 4 - (SInt32)batchWords) >> 2;
      }
      panelRec = panelRec + 1;
      panel = panel + 1;
      M<SInt32>((SInt32)Vol(batchEntry->header) + 0xc) = iVar34;
      local_108 = local_108 + 8;
      M<SInt32>((SInt32)Vol(batchEntry->header) + 0x14) = iVar44;
      M<UInt32>((SInt32)Vol(batchEntry->header) + 0x1c) = M<UInt32>((SInt32)Vol(batchEntry->header) + 0x1c) | 1;
      M<UInt16>(self + 0xdb4) = 1;
      iVar32 = M<SInt32>(self + 0xd50);
    } while (panel < M<UInt32>(iVar32 + 0xcc));
  }
  return;
}
