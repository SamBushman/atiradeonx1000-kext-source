/*
 * ATIRadeonX1000_SWDSWriteBlit.cpp
 *
 * RESOLVED (ledger pass): ATIRadeonX1000::SWDSWriteBlitToCmdBuf (real addr 0x23320, 4040 bytes): emits the software display scaler
 * blit (per-panel surface, 3D blit state packet or pcl_CopyPix for tall surfaces) into a command buffer and returns the new
 * dword count.
 * Mechanically ported from the Ghidra decompile of the shipped kext (Tools/port_fn.py); the resolved data references
 * (metaClass / page_shift / page_size / plane symbols) come from the kext relocation table.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 GH_IOFreeAligned(...) asm("_IOFreeAligned");
extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");
extern "C" UInt32 GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(...) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");
extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEPvm11IODirection(...) asm("__ZN18IOMemoryDescriptor11withAddressEPvm11IODirection");
extern "C" UInt32 GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(...) asm("__ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_E");
extern "C" UInt32 GH_ZN8OSObjectnwEm(...) asm("__ZN8OSObjectnwEm");
extern "C" UInt32 GH_ZN8OSSymbol17withCStringNoCopyEPKc(...) asm("__ZN8OSSymbol17withCStringNoCopyEPKc");
extern "C" UInt32 GH_ZN9IOServiceC1Ev(...) asm("__ZN9IOServiceC1Ev");
extern "C" UInt32 GH_memcpy(...) asm("_memcpy");
extern "C" UInt32 GH_memset(...) asm("_memset");

struct pcl_ParamsR500_t;
UInt32 *pcl_CopyPix(UInt32 *param_1, pcl_ParamsR500_t *params, bool param_3, bool param_4);
extern "C" const r500_3d_blit_state_packet_struct g_r500_3d_blit_state_packet;

/* real addr 0x23320 */
UInt32 ATIRadeonX1000::SWDSWriteBlitToCmdBuf(UInt32 *param_1, UInt32 param_2, bool param_3, UInt32 param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt8 AVar2;
  UInt16 uVar3;
  UInt16 uVar4;
  float fVar5;
  float fVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  SInt32 iVar9;
  UInt32 uVar10;
  UInt32 uVar11;
  UInt32 uVar12;
  UInt32 in_register_00000018;
  UInt32 uVar13;
  SInt32 iVar14;
  UInt32 uVar15;
  SInt32 iVar16;
  UInt32 uVar17;
  UInt32 uVar18;
  UInt32 uVar19;
  UInt32 uVar20;
  UInt32 *puVar21;
  UInt32 blk[35];   /* the pcl_ParamsR500_t block on the shipped stack: 0x8c bytes at sp+0x40 (Ghidra blk[0] .. blk[34]) */
  UInt16 rect[4];   /* the 8-byte rectangle at sp+0x38 (Ghidra rect[0] .. rect[3]) */
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  UInt32 local_a8;
  UInt32 uStack_a4;
  UInt32 local_a0;
  UInt32 uStack_9c;
  UInt32 local_98;
  UInt32 uStack_94;
  UInt32 local_90;
  UInt32 uStack_8c;
  
  dVar25 = DOUBLE_0004c3b0;
  uStack_a4 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x9d8);
  iVar16 = M<SInt32>(self + param_4 * 4 + 0xb5c);
  local_a8 = 0x43300000;
  uStack_9c = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x9da);
  local_a0 = 0x43300000;
  M<UInt32>(self + 0x78) = 0;
  BF(blk[23]) = (float)((double)CONCAT44d(0x43300000,uStack_a4) - dVar25);
  dVar24 = (double)BF(blk[23]);
  BF(blk[24]) = (float)((double)CONCAT44d(0x43300000,uStack_9c) - dVar25);
  dVar25 = (double)BF(blk[24]);
  if (((UInt32)param_3) != 0) {
    uVar3 = M<UInt16>(self + param_4 * 0x78 + 0x9da);
    param_1[param_2] = 0x5c8;
    param_1[param_2 + 1] = 0x70000;
    if (param_4 == 0) {
      param_1[param_2 + 2] = 0x194e;
      param_1[param_2 + 3] = ((UInt32)uVar3 & ~M<UInt32>(self + 0x898)) << 0x10 | 0x80000000;
      param_1[param_2 + 4] = 0x5c8;
      iVar9 = param_2 + 5;
      param_2 = param_2 + 6;
      param_1[iVar9] = 8;
    }
    else {
      param_1[param_2 + 2] = 0x1b4e;
      param_1[param_2 + 3] = ((UInt32)uVar3 & ~M<UInt32>(self + 0x89c)) << 0x10 | 0x80000000;
      param_1[param_2 + 4] = 0x5c8;
      iVar9 = param_2 + 5;
      param_2 = param_2 + 6;
      param_1[iVar9] = 0x80000008;
    }
  }
  if (0x1000 < M<UInt16>(self + param_4 * 0x78 + 0x148)) {
    rect[0] = 0;
    rect[1] = 1;
    blk[17] = blk[17] | 0xf8000000;
    uVar17 = 0;
    rect[2] = M<UInt16>(self + param_4 * 0x78 + 0x148);
    blk[10] = M<UInt32>(self + 0xb74);
    rect[3] = M<UInt16>(self + param_4 * 0x78 + 0x14a);
    uStack_94 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x148);
    blk[11] = (UInt32)(UInt8)self[param_4 * 0x78 + 0x166];
    blk[12] = (UInt32)(UInt8)self[param_4 * 0x78 + 0x9f6];
    local_98 = 0x43300000;
    uStack_8c = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x14a);
    blk[4] = 0x1492;
    blk[8] = 0;
    local_90 = 0x43300000;
    blk[18] = 1;
    blk[20] = (UInt32)rect;
    blk[19] = 0;
    blk[26] = 0;
    blk[32] = 0x3f800000;
    blk[34] = 0;
    blk[21] = 0;
    blk[22] = 0;
    blk[25] = 0;
    blk[29] = 0x3f800000;
    blk[30] = 0x3f800000;
    blk[31] = 0x3f800000;
    BF(blk[27]) = (float)((double)CONCAT44d(0x43300000,uStack_94) - DOUBLE_0004c3b0);
    BF(blk[28]) = (float)((double)CONCAT44d(0x43300000,uStack_8c) - DOUBLE_0004c3b0);
    blk[6] = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x9dc) *
                M<SInt32>(self + param_4 * 0x78 + 0x9fc) + M<SInt32>(self + param_4 * 0x78 + 0x9c4) &
                0xffffffe0;
    if ((M<UInt32>(self + param_4 * 0x78 + 0x9f8) & 0xf00000) != 0) {
      uVar17 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x9d0) /
               (M<UInt32>(self + param_4 * 0x78 + 0x9f8) >> 0x14 & 0xf);
    }
    uVar10 = 0x20 / M<UInt16>(self + param_4 * 0x78 + 0x9d2);
    if (0x20 / M<UInt16>(self + param_4 * 0x78 + 0x9d2) <= uVar17) {
      uVar10 = uVar17;
    }
    uVar17 = FormatTableLookup_0x0004d2e0((UInt32)(UInt8)self[param_4 * 0x78 + 0x9f6] * 0x1c);
    blk[5] = uVar10 & 0x3ffe | ((UInt8)self[param_4 * 0x78 + 0x9f4] & 1) << 0x10 |
                ((UInt8)self[param_4 * 0x78 + 0x9f4] & 6) << 0x10 |
                ((UInt8)self[param_4 * 0x78 + 0x9f5] & 3) << 0x13 |
                FormatTableLookup_0x0004d2e0((UInt32)(UInt8)self[param_4 * 0x78 + 0x9f6] * 0x1c) >> 1 &
                0x1e00000;
    blk[7] = (uVar17 & 0x600) << 5 |
                (uVar17 & 0x1800) << 1 |
                uVar17 >> 3 & 0xc00 | uVar17 >> 7 & 0x300 | uVar17 >> 0x11 & 0x1f;
    if (((M<UInt32>(self + param_4 * 0x78 + 0x9f8) & 0xf00000) == 0) ||
       (uVar10 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x9d8) /
                 (M<UInt32>(self + param_4 * 0x78 + 0x9f8) >> 0x14 & 0xf), uVar17 = uVar10 - 1,
       uVar10 == 0)) {
      uVar17 = 0;
    }
    uVar10 = 0;
    if (M<UInt16>(self + param_4 * 0x78 + 0x9da) != 0) {
      uVar10 = M<UInt16>(self + param_4 * 0x78 + 0x9da) - 1;
    }
    blk[9] = uVar17 & 0x1fff | (uVar10 & 0x1fff) << 0xd;
    blk[0] = ((UInt8)self[param_4 * 0x78 + 0x164] & 7) << 2 |
                (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x14c) *
                M<SInt32>(self + param_4 * 0x78 + 0x16c) + M<SInt32>(self + param_4 * 0x78 + 0x134) &
                0xffffffe0;
    if (((M<UInt32>(self + param_4 * 0x78 + 0x168) & 0xf00000) == 0) ||
       (uVar10 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x148) /
                 (M<UInt32>(self + param_4 * 0x78 + 0x168) >> 0x14 & 0xf), uVar17 = uVar10 - 1,
       uVar10 == 0)) {
      uVar17 = 0;
    }
    uVar10 = 0;
    if (M<UInt16>(self + param_4 * 0x78 + 0x14a) != 0) {
      uVar10 = M<UInt16>(self + param_4 * 0x78 + 0x14a) - 1;
    }
    uVar11 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)self[param_4 * 0x78 + 0x166] * 0x1c);
    blk[1] = uVar17 & 0x7ff | (uVar10 & 0x7ff) << 0xb | 0x80000000;
    blk[2] = uVar11 >> 0x13 & 0x1f | (uVar11 & 0x40) << 0x10 | uVar11 >> 7 & 0xe00 |
                uVar11 >> 1 & 0x7000 | (uVar11 & 0x1c00) << 5 | (uVar11 & 0x380) << 0xb;
    uVar17 = M<UInt32>(self + param_4 * 0x78 + 0x168);
    bVar1 = (uVar17 & 0xf00000) == 0;
    if (bVar1) {
      uVar10 = 0;
    }
    else {
      uVar10 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x140) / (uVar17 >> 0x14 & 0xf);
    }
    uVar11 = 0x20 / M<UInt16>(self + param_4 * 0x78 + 0x142);
    if (0x20 / M<UInt16>(self + param_4 * 0x78 + 0x142) <= uVar10) {
      uVar11 = uVar10;
    }
    if ((bVar1) ||
       (uVar10 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x148) / (uVar17 >> 0x14 & 0xf),
       uVar17 = uVar10 - 1, uVar10 == 0)) {
      uVar17 = 0;
    }
    uVar10 = 0;
    if (M<UInt16>(self + param_4 * 0x78 + 0x14a) != 0) {
      uVar10 = M<UInt16>(self + param_4 * 0x78 + 0x14a) - 1;
    }
    blk[3] = uVar11 - 1 & 0x3fff | (uVar17 & 0x800) << 4 | (uVar10 & 0x800) << 5;
    if (((M<UInt32>(self + param_4 * 0x78 + 0x168) & 0xf00000) == 0) ||
       (blk[13] = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x148) /
                    (M<UInt32>(self + param_4 * 0x78 + 0x168) >> 0x14 & 0xf), blk[13] == 0)) {
      blk[13] = 1;
    }
    blk[14] = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x14a);
    if (blk[14] == 0) {
      blk[14] = 1;
    }
    blk[15] = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x140) *
                (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x142);
    if (blk[15] < 0x20) {
      blk[15] = 0x20;
    }
    blk[33] = M<UInt32>(self + 0x8c4);
    blk[16] = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x14c) *
                M<SInt32>(self + param_4 * 0x78 + 0x16c) + M<SInt32>(self + param_4 * 0x78 + 0x134);
    if (iVar16 == 0xb4) {
      iVar16 = (SInt32)pcl_CopyPix(param_1 + param_2,(pcl_ParamsR500_t *)&blk[0],true,true);
      return iVar16 - (SInt32)param_1 >> 2;
    }
    iVar16 = (SInt32)pcl_CopyPix(param_1 + param_2,(pcl_ParamsR500_t *)&blk[0],false,false);
    return iVar16 - (SInt32)param_1 >> 2;
  }
  puVar21 = param_1 + param_2;
  GH_memcpy(puVar21,&g_r500_3d_blit_state_packet,0x2f4);
  iVar14 = (UInt32)(UInt8)self[param_4 * 0x78 + 0x9f6] * 0x1c;
  iVar9 = (SInt32)puVar21 + (0x2f4 - (SInt32)param_1) >> 2;
  uVar17 = 0;
  puVar21[0x9a] =
       (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x9dc) * M<SInt32>(self + param_4 * 0x78 + 0x9fc) +
       M<SInt32>(self + param_4 * 0x78 + 0x9c4) & 0xffffffe0;
  if ((M<UInt32>(self + param_4 * 0x78 + 0x9f8) & 0xf00000) != 0) {
    uVar17 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x9d0) /
             (M<UInt32>(self + param_4 * 0x78 + 0x9f8) >> 0x14 & 0xf);
  }
  uVar10 = 0x20 / M<UInt16>(self + param_4 * 0x78 + 0x9d2);
  if (0x20 / M<UInt16>(self + param_4 * 0x78 + 0x9d2) <= uVar17) {
    uVar10 = uVar17;
  }
  uVar7 = puVar21[0x8a];
  puVar21[0x9c] =
       uVar10 & 0x3ffe | ((UInt8)self[param_4 * 0x78 + 0x9f4] & 1) << 0x10 |
       ((UInt8)self[param_4 * 0x78 + 0x9f4] & 6) << 0x10 |
       ((UInt8)self[param_4 * 0x78 + 0x9f5] & 3) << 0x13 |
       FormatTableLookup_0x0004d2e0((UInt32)(UInt8)self[param_4 * 0x78 + 0x9f6] * 0x1c) >> 1 & 0x1e00000;
  uVar17 = FormatTableLookup_0x0004d2e0(iVar14) >> 0x11 & 0x1f;
  puVar21[0x8a] = uVar17 | uVar7 & 0xffffffe0;
  uVar10 = FormatTableLookup_0x0004d2e0(iVar14) >> 7 & 0x300;
  puVar21[0x8a] = uVar10 | uVar17 | uVar7 & 0xfffffce0;
  uVar11 = FormatTableLookup_0x0004d2e0(iVar14) >> 3 & 0xc00;
  puVar21[0x8a] = uVar11 | uVar10 | uVar17 | uVar7 & 0xfffff0e0;
  uVar13 = (FormatTableLookup_0x0004d2e0(iVar14) & 0x1800) << 1;
  puVar21[0x8a] = uVar13 | uVar11 | uVar10 | uVar17 | uVar7 & 0xffffc0e0;
  puVar21[0x8a] =
       (FormatTableLookup_0x0004d2e0(iVar14) & 0x600) << 5 |
       uVar13 | uVar11 | uVar10 | uVar17 | uVar7 & 0xffff00e0;
  if (((M<UInt32>(self + param_4 * 0x78 + 0x9f8) & 0xf00000) == 0) ||
     (uVar10 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x9d8) /
               (M<UInt32>(self + param_4 * 0x78 + 0x9f8) >> 0x14 & 0xf), uVar17 = uVar10 - 1,
     uVar10 == 0)) {
    uVar17 = 0;
  }
  uVar10 = 0;
  if (M<UInt16>(self + param_4 * 0x78 + 0x9da) != 0) {
    uVar10 = M<UInt16>(self + param_4 * 0x78 + 0x9da) - 1;
  }
  puVar21[0xb3] = uVar17 & 0x1fff | (uVar10 & 0x1fff) << 0xd;
  AVar2 = self[param_4 * 0x78 + 0x166];
  puVar21[0xa0] =
       ((UInt8)self[param_4 * 0x78 + 0x164] & 7) << 2 |
       (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x14c) * M<SInt32>(self + param_4 * 0x78 + 0x16c) +
       M<SInt32>(self + param_4 * 0x78 + 0x134) & 0xffffffe0;
  if (((M<UInt32>(self + param_4 * 0x78 + 0x168) & 0xf00000) == 0) ||
     (uVar10 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x148) /
               (M<UInt32>(self + param_4 * 0x78 + 0x168) >> 0x14 & 0xf), uVar17 = uVar10 - 1,
     uVar10 == 0)) {
    uVar17 = 0;
  }
  uVar10 = 0;
  if (M<UInt16>(self + param_4 * 0x78 + 0x14a) != 0) {
    uVar10 = M<UInt16>(self + param_4 * 0x78 + 0x14a) - 1;
  }
  puVar21[0xa6] = uVar17 & 0x7ff | (uVar10 & 0x7ff) << 0xb | 0x80000000;
  uVar17 = FormatTableLookup_0x0004d2e4((UInt32)(UInt8)AVar2 * 0x1c);
  puVar21[0xa8] =
       uVar17 >> 0x13 & 0x1f | (uVar17 & 0x40) << 0x10 | uVar17 >> 7 & 0xe00 | uVar17 >> 1 & 0x7000
       | (uVar17 & 0x1c00) << 5 | (uVar17 & 0x380) << 0xb;
  uVar17 = M<UInt32>(self + param_4 * 0x78 + 0x168);
  bVar1 = (uVar17 & 0xf00000) == 0;
  if (bVar1) {
    uVar10 = 0;
  }
  else {
    uVar10 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x140) / (uVar17 >> 0x14 & 0xf);
  }
  uVar11 = 0x20 / M<UInt16>(self + param_4 * 0x78 + 0x142);
  if (0x20 / M<UInt16>(self + param_4 * 0x78 + 0x142) <= uVar10) {
    uVar11 = uVar10;
  }
  if ((bVar1) ||
     (uVar10 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x148) / (uVar17 >> 0x14 & 0xf),
     uVar17 = uVar10 - 1, uVar10 == 0)) {
    uVar17 = 0;
  }
  uVar10 = 0;
  if (M<UInt16>(self + param_4 * 0x78 + 0x14a) != 0) {
    uVar10 = M<UInt16>(self + param_4 * 0x78 + 0x14a) - 1;
  }
  puVar21[0xaa] = uVar11 - 1 & 0x3fff | (uVar17 & 0x800) << 4 | (uVar10 & 0x800) << 5;
  uVar15 = M<UInt32>(self + 0xb74);
  puVar21[0xa2] = puVar21[0xa2] & 0xffffe1ff | 0x1400;
  puVar21[5] = 0x30000;
  puVar21[0xb] = uVar15;
  if (M<UInt16>(self + param_4 * 0x78 + 0x14a) < 0x1001) {
LAB_00023ca0:
    if (iVar16 == 0xb4) {
      uVar20 = 0x3f800000;
      uVar18 = 0;
      uVar15 = 0x3f800000;
      uVar19 = 0;
    }
    else {
      if (iVar16 == 0x10e) goto LAB_00023c68;
      if (iVar16 == 0x5a) goto LAB_00023c18;
      uVar20 = 0;
      uVar18 = 0x3f800000;
      uVar15 = 0;
      uVar19 = 0x3f800000;
    }
  }
  else {
    if (((M<UInt32>(self + param_4 * 0x78 + 0x168) & 0xf00000) == 0) ||
       (uVar17 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x148) /
                 (M<UInt32>(self + param_4 * 0x78 + 0x168) >> 0x14 & 0xf), uVar10 = uVar17 - 1,
       uVar17 == 0)) {
      uVar10 = 0;
    }
    puVar21[0xa6] = uVar10 & 0x7ff | 0x803ff800;
    if (iVar16 == 0x5a) {
      uVar17 = 0;
      if (M<UInt16>(self + param_4 * 0x78 + 0x9da) != 0) {
        uVar17 = M<UInt16>(self + param_4 * 0x78 + 0x9da) - 1;
      }
      puVar21[0xb3] = (uVar17 & 0x1fff) << 0xd | 0xfff;
LAB_00023c18:
      uVar17 = puVar21[0x98];
      uVar19 = 0;
      uVar18 = 0x3f800000;
    }
    else {
      if (iVar16 != 0x10e) goto LAB_00023ca0;
      if (((M<UInt32>(self + param_4 * 0x78 + 0x9f8) & 0xf00000) == 0) ||
         (uVar10 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x9d8) /
                   (M<UInt32>(self + param_4 * 0x78 + 0x9f8) >> 0x14 & 0xf),
         uVar17 = uVar10 - 0x1001, uVar10 == 0)) {
        uVar17 = 0xfffff000;
      }
      puVar21[0xb2] = uVar17 & 0x1fff;
LAB_00023c68:
      uVar17 = puVar21[0x98];
      uVar19 = 0x3f800000;
      uVar18 = 0;
    }
    puVar21[0x98] = uVar17 & 0xfffff000 | 1;
    uVar15 = uVar18;
    uVar20 = uVar19;
  }
  if (0x1000 < M<UInt16>(self + param_4 * 0x78 + 0x14a)) {
    if (iVar16 == 0x5a) {
      dVar23 = (double)FLOAT_0004c37c;
      iVar14 = iVar9 * 4 + 0x30 >> 2;
      fVar5 = (float)(dVar25 + (double)FLOAT_0004c370) * FLOAT_0004c380;
      param_1[iVar9] = 0x31080;
      param_1[iVar9 + 5] = 0x1087;
      param_1[iVar9 + 7] = 0xc0033500;
      param_1[iVar9 + 8] = 0x10031;
      param_1[iVar9 + 9] = 0x45000000;
      param_1[iVar9 + 10] = FBITS(fVar5);
      param_1[iVar9 + 1] = uVar20;
      param_1[iVar9 + 2] = uVar19;
      param_1[iVar9 + 3] = uVar18;
      param_1[iVar9 + 4] = uVar15;
      param_1[iVar9 + 0xb] = 0;
      param_1[iVar9 + 6] = (SInt32)(dVar25 * dVar23) | 0x60000000;
      goto LAB_00023f44;
    }
    if (iVar16 == 0x10e) {
      dVar23 = (double)FLOAT_0004c37c;
      dVar22 = (double)FLOAT_0004c378;
      iVar14 = iVar9 * 4 + 0x30 >> 2;
      fVar5 = (float)(dVar25 + (double)FLOAT_0004c370) * FLOAT_0004c380;
      fVar6 = (float)(dVar24 + (double)(float)(dVar24 - dVar22)) * FLOAT_0004c380;
      param_1[iVar9] = 0x31080;
      param_1[iVar9 + 7] = 0xc0033500;
      param_1[iVar9 + 5] = 0x1087;
      param_1[iVar9 + 8] = 0x10031;
      param_1[iVar9 + 9] = FBITS(fVar6);
      param_1[iVar9 + 10] = FBITS(fVar5);
      param_1[iVar9 + 0xb] = 0;
      param_1[iVar9 + 1] = uVar20;
      param_1[iVar9 + 2] = uVar19;
      param_1[iVar9 + 3] = uVar18;
      param_1[iVar9 + 4] = uVar15;
      param_1[iVar9 + 6] =
           (SInt32)((double)(float)(dVar24 - (double)(float)(dVar24 - dVar22)) * dVar23) << 0x10 |
           (SInt32)(dVar25 * dVar23);
      goto LAB_00023f44;
    }
  }
  dVar23 = (double)FLOAT_0004c37c;
  fVar5 = (float)(dVar25 + (double)FLOAT_0004c370) * FLOAT_0004c380;
  fVar6 = (float)(dVar24 + (double)FLOAT_0004c370) * FLOAT_0004c380;
  param_1[iVar9] = 0x31080;
  param_1[iVar9 + 7] = 0xc0033500;
  param_1[iVar9 + 8] = 0x10031;
  param_1[iVar9 + 5] = 0x1087;
  param_1[iVar9 + 9] = FBITS(fVar6);
  param_1[iVar9 + 10] = FBITS(fVar5);
  param_1[iVar9 + 1] = uVar20;
  param_1[iVar9 + 2] = uVar19;
  param_1[iVar9 + 3] = uVar18;
  param_1[iVar9 + 4] = uVar15;
  param_1[iVar9 + 0xb] = 0;
  param_1[iVar9 + 6] = (SInt32)(dVar24 * dVar23) << 0x10 | (SInt32)(dVar25 * dVar23);
  iVar14 = iVar9 * 4 + 0x30 >> 2;
LAB_00023f44:
  uVar17 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x14a);
  if (0x1000 < uVar17) {
    if (iVar16 == 0x5a) {
      iVar16 = M<SInt32>(self + param_4 * 0x78 + 0x16c);
      uVar3 = M<UInt16>(self + param_4 * 0x78 + 0x14c);
      uVar4 = M<UInt16>(self + param_4 * 0x78 + 0x144);
      iVar9 = M<SInt32>(self + param_4 * 0x78 + 0x134);
      uVar7 = puVar21[0xa0];
      uVar13 = puVar21[0xa6];
      uVar11 = puVar21[0xb2];
      uVar10 = puVar21[0xb3];
      if (((M<UInt32>(self + param_4 * 0x78 + 0x9f8) & 0xf00000) == 0) ||
         (uVar12 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x9d8) /
                   (M<UInt32>(self + param_4 * 0x78 + 0x9f8) >> 0x14 & 0xf), uVar8 = uVar12 - 1,
         uVar12 == 0)) {
        uVar8 = 0;
      }
      param_1[iVar14] = 0x1150;
      param_1[iVar14 + 1] =
           (UInt32)uVar3 * iVar16 + iVar9 + (UInt32)uVar4 * 0x1000 & 0xffffffe0 | uVar7 & 0x1f;
      param_1[iVar14 + 2] = 0x1120;
      param_1[iVar14 + 3] = (uVar17 - 0x1001) * 0x800 & 0x3ff800 | uVar13 & 0xffc007ff;
      param_1[iVar14 + 4] = 0x10f8;
      param_1[iVar14 + 5] = uVar11 & 0xffffe000 | 0xfff;
      param_1[iVar14 + 6] = 0x10f9;
      param_1[iVar14 + 7] = uVar8 & 0x1fff | uVar10 & 0xffffe000;
      dVar23 = (double)FLOAT_0004c378;
      dVar22 = (double)FLOAT_0004c37c;
      fVar5 = (float)(dVar24 + dVar23) * FLOAT_0004c380;
      fVar6 = (float)(dVar25 + (double)FLOAT_0004c370) * FLOAT_0004c380;
      param_1[iVar14 + 8] = 0x31080;
      param_1[iVar14 + 0xd] = 0x1087;
      param_1[iVar14 + 9] = uVar20;
      param_1[iVar14 + 10] = uVar19;
      param_1[iVar14 + 0xb] = uVar18;
      param_1[iVar14 + 0xc] = uVar15;
      param_1[iVar14 + 0xf] = 0xc0033500;
      param_1[iVar14 + 0x10] = 0x10031;
      param_1[iVar14 + 0x11] = FBITS(fVar5);
      param_1[iVar14 + 0x12] = FBITS(fVar6);
      param_1[iVar14 + 0x13] = 0;
      param_1[iVar14 + 0xe] =
           (SInt32)((double)(float)(dVar24 - dVar23) * dVar22) << 0x10 | (SInt32)(dVar25 * dVar22);
      iVar14 = (iVar14 + 8) * 4 + 0x30 >> 2;
    }
    else if (iVar16 == 0x10e) {
      iVar16 = M<SInt32>(self + param_4 * 0x78 + 0x16c);
      uVar3 = M<UInt16>(self + param_4 * 0x78 + 0x14c);
      uVar4 = M<UInt16>(self + param_4 * 0x78 + 0x144);
      iVar9 = M<SInt32>(self + param_4 * 0x78 + 0x134);
      uVar7 = puVar21[0xa0];
      uVar13 = puVar21[0xa6];
      uVar11 = puVar21[0xb2];
      uVar10 = puVar21[0xb3];
      if (((M<UInt32>(self + param_4 * 0x78 + 0x9f8) & 0xf00000) == 0) ||
         (uVar12 = (UInt32)M<UInt16>(self + param_4 * 0x78 + 0x9d8) /
                   (M<UInt32>(self + param_4 * 0x78 + 0x9f8) >> 0x14 & 0xf), uVar8 = uVar12 - 0x1001
         , uVar12 == 0)) {
        uVar8 = 0xfffff000;
      }
      param_1[iVar14] = 0x1150;
      param_1[iVar14 + 1] =
           (UInt32)uVar3 * iVar16 + iVar9 + (UInt32)uVar4 * 0x1000 & 0xffffffe0 | uVar7 & 0x1f;
      param_1[iVar14 + 2] = 0x1120;
      param_1[iVar14 + 3] = (uVar17 - 0x1001) * 0x800 & 0x3ff800 | uVar13 & 0xffc007ff;
      param_1[iVar14 + 4] = 0x10f8;
      param_1[iVar14 + 5] = uVar11 & 0xffffe000;
      param_1[iVar14 + 6] = 0x10f9;
      param_1[iVar14 + 7] = uVar8 & 0x1fff | uVar10 & 0xffffe000;
      dVar23 = (double)FLOAT_0004c37c;
      dVar22 = (double)FLOAT_0004c378;
      fVar5 = (float)(dVar25 + (double)FLOAT_0004c370) * FLOAT_0004c380;
      fVar6 = (float)((double)(float)(dVar24 - dVar22) + (double)FLOAT_0004c370) * FLOAT_0004c380;
      param_1[iVar14 + 8] = 0x31080;
      param_1[iVar14 + 0xd] = 0x1087;
      param_1[iVar14 + 9] = uVar20;
      param_1[iVar14 + 10] = uVar19;
      param_1[iVar14 + 0xb] = uVar18;
      param_1[iVar14 + 0xc] = uVar15;
      param_1[iVar14 + 0xf] = 0xc0033500;
      param_1[iVar14 + 0x10] = 0x10031;
      param_1[iVar14 + 0x11] = FBITS(fVar6);
      param_1[iVar14 + 0x12] = FBITS(fVar5);
      param_1[iVar14 + 0x13] = 0;
      param_1[iVar14 + 0xe] =
           (SInt32)((double)(float)(dVar24 - dVar22) * dVar23) << 0x10 | (SInt32)(dVar25 * dVar23);
      iVar14 = (iVar14 + 8) * 4 + 0x30 >> 2;
    }
  }
  param_1[iVar14] = 0x1393;
  param_1[iVar14 + 1] = 10;
  return iVar14 + 2;
}

