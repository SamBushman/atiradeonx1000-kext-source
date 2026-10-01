/*
 * ATIR500Surface_copy_buffer_using_DMA_Port.cpp
 *
 * ATIR500Surface::copy_buffer_using_DMA (real addr 0x42a80, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
 * Tools/port_fn.py); replaces the earlier hand-written body, which the callee/atomics comparison (Tools/callee_compare.py) showed had
 * dropped or simplified parts of the original.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIR5002DContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"


UInt32 write_3dtexquad_cmds_for_copy_buffer_using_DMA(ATIRadeonX1000 *accel, UInt32 *cmd, UInt32 depthWords, UInt32 a3,
    UInt32 srcAddr, UInt32 srcPitch, UInt32 srcPitchShifted, UInt32 srcHeight, UInt32 srcSampleA, UInt32 srcShift,
    unsigned char srcBytes, UInt32 srcFormat, UInt32 dstAddr, UInt32 dstPitch, UInt32 dstPitchShifted, UInt32 dstSampleB,
    UInt32 dstShift, unsigned char dstBytes, long dstX, long dstY, long srcX, long srcY, UInt32 w, UInt32 h, bool flip);

/* real addr 0x42a80 */
UInt32 ATIR500Surface::copy_buffer_using_DMA(SInt32 param_1, SInt32 param_2, SInt32 param_3, SInt32 param_4, UInt32 param_5, UInt32 param_6, ATIR500SurfaceBuffer *real_param_7, VendorTransferBuffer *real_param_8, UInt32 param_9, UInt32 param_10, IODirection param_12, UInt32 param_13) {   /* Ghidra numbers the 12 real parameters 1-10, 12, 13 (slot 11 is skipped) */
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_7 = reinterpret_cast<UInt8 *>(real_param_7);
    UInt8 *param_8 = reinterpret_cast<UInt8 *>(real_param_8);

  bool bVar1;
  UInt16 uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  unsigned int uVar6;
  bool bVar7;
  SInt16 sVar8;
  unsigned int uVar9;
  int *piVar10;
  UInt32 uVar11;
  unsigned int uVar12;
  UInt32 uVar13;
  int iVar14;
  UInt8 *this_00;
  int iVar15;
  UInt8 bVar16;
  UInt32 uVar17;
  UInt32 uVar18;
  UInt32 uVar19;
  UInt32 uVar20;
  int iVar21;
  int iVar22;
  int *piVar23;
  int iVar24;
  UInt32 *puVar25;
  UInt8 bVar26;
  UInt8 bVar27;
  UInt32 local_98;
  UInt32 local_94 [3];
  void *local_88;
  UInt32 local_84;
  int local_80;
  UInt32 local_7c;
  UInt32 local_78;
  long local_74;
  int local_70;
  long local_6c;
  unsigned int local_68;
  unsigned int local_64;
  UInt32 local_60;
  UInt32 local_5c;
  
  iVar14 = M<int>(self + 0xd50);
  local_84 = (param_4 - 1) * param_10 + M<UInt16>(param_7 + 0x16) * param_3;
  if (M<char>(iVar14 + 0x80) == '\0') {
    return 0;
  }
  uVar9 = M<unsigned int>(param_7 + 0x3c) >> 0xb & 1;
  if ((param_7 < self + 0x558) || (bVar4 = true, self + 0x738 < param_7)) {
    bVar4 = false;
  }
  if (param_7 == (UInt8 *)(self + 0x4e0)) {
    return 0;
  }
  bVar1 = uVar9 == 0;
  bVar27 = bVar1 << 1;
  bVar16 = (UInt8)uVar9 ^ 1;
  if ((!bVar1) && ((M<unsigned int>(self + 0xbe8) & 0x7c0000) != 0)) {
    return 0;
  }
  if (((param_13 & 2) == 0) || (local_80 = 1, (M<unsigned int>(self + 0xbe8) & 0x70000000) != 0)) {
    local_80 = 0;
  }
  bVar5 = (param_13 & 1) == 0;
  bVar26 = bVar5 << 1;
  if (bVar5) {
    if (!bVar1) {
      bVar7 = (M<unsigned int>(self + 0xbe8) & 0x7c0000) == 0;
joined_r0x00042bb8:
      if (!bVar7) {
        return 0;
      }
    }
LAB_00042bcc:
    bVar16 = 1;
  }
  else if (param_12 != 1) {
    bVar7 = bVar1;
    if (M<char>(M<int>(param_7 + 0x24) + 0x58) != '\0') goto joined_r0x00042bb8;
    goto LAB_00042bcc;
  }
  bVar7 = param_12 != 1;
  if (bVar7) {
    if (param_12 != 2) goto LAB_00042bf0;
  }
  else if ((M<unsigned int>(iVar14 + 0x98) >> 3 & 1) == 0) {
LAB_00042bf0:
    bVar3 = false;
    goto LAB_00042bf4;
  }
  bVar3 = true;
LAB_00042bf4:
  if (((M<unsigned int>(iVar14 + 0x98) & 0x20000) != 0) && (!bVar3)) {
    return 0;
  }
  if ((bVar1) || (bVar5)) {
    if ((bVar4) && ((M<int>(self + 0xdac) != 0 && (!bVar5)))) {
      param_3 = (UInt32)M<UInt16>(param_7 + 0x14);
    }
  }
  else {
    param_3 = (UInt32)M<UInt16>(param_7 + 0x14);
    if ((param_4 & 0x1f) != 0) {
      param_4 = (((int)param_4 >> 5) + (unsigned int)((int)param_4 < 0 && (param_4 & 0x1f) != 0)) * 0x20 +
                0x20;
    }
  }
  if (M<int>(param_7 + 0x24) != 0) {
    M<UInt8>(M<int>(param_7 + 0x24) + 0x58) = bVar16;
    iVar14 = M<int>(self + 0xd50);
  }
  if (!bVar3) {
    iVar14 = M<int>(iVar14 + 0x8a4);
    bVar16 = (param_12 == 2) << 1;
    piVar10 = (int *)0x0;
    local_88 = (void *)0x0;
  }
  else {
    piVar10 = (int *)VCALL(*M<int *>(param_8 + 8), 0x14c)
                               (M<int *>(param_8 + 8),GH_kernel_task,0,
                                M<unsigned int>(iVar14 + 0x82c) | 1,0,0);
    if (piVar10 == (int *)0x0) {
      return 0;
    }
    bVar16 = (param_12 == 2) << 1;
    iVar14 = VCALL(*piVar10, 0xd0)(piVar10);
    local_88 = (void *)(iVar14 + param_9);
    if ((bool)(bVar16 >> 1 & 1)) {
      this_00 = M<UInt8 *>(self + 0xd50);
      if ((M<unsigned int>(this_00 + 0x98) & 0x80) != 0) {
        ((IOATIR500Accelerator *)(this_00))->flush_memory_for_out((const void *)(local_88), param_10 * param_4);
        this_00 = M<UInt8 *>(self + 0xd50);
      }
    }
    else {
      this_00 = M<UInt8 *>(self + 0xd50);
      if ((M<unsigned int>(this_00 + 0x98) & 0x80) != 0) {
        ((IOATIR500Accelerator *)(this_00))->flush_memory_for_in((const void *)(local_88), local_84);
        this_00 = M<UInt8 *>(self + 0xd50);
      }
    }
    iVar14 = M<int>(this_00 + 0x8a4);
  }
  iVar15 = M<int>(param_8 + 4);
  if (iVar15 == 0) {
    ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(param_8));
    iVar15 = M<int>(param_8 + 4);
  }
  if (local_80 != 0) {
    if ((int)M<SInt16>(self + 0xbd6) == (int)M<SInt16>(self + 0xbda)) {
      param_2 = ((unsigned int)M<UInt16>(param_7 + 0x1e) - param_2) - param_4;
    }
    else {
      param_2 = (M<SInt16>(self + 0xbda) - param_2) - param_4;
    }
  }
  if ((bool)(bVar16 >> 1 & 1)) {
    uVar19 = (UInt32)(UInt8)param_7[0x3a];
    local_98 = param_10;
    iVar21 = uVar19 * 0x1c;
    local_78 = iVar14 + param_9 + iVar15;
    local_5c = (int)param_10 >> (FormatTableLookup_0x0004d2dc(iVar21) >> 0xc & 7);
    if ((bool)(bVar27 >> 1 & 1)) {
      uVar9 = (unsigned int)M<UInt16>(param_7 + 0x1e);
    }
    else {
      uVar2 = M<UInt16>(param_7 + 0x1e);
      uVar9 = (unsigned int)uVar2;
      if ((uVar2 & 0x1f) != 0) {
        uVar9 = (uVar2 & 0xffffffe0) + 0x20;
      }
    }
    local_64 = (unsigned int)(UInt8)param_7[0x39];
    iVar15 = M<int>(param_7 + 8);
    uVar17 = 0;
    local_74 = param_1;
    iVar14 = VCALL(M<int>(self), 0x5f0)(self,param_7,param_5,param_6,0,0,local_94);
    uVar18 = (UInt32)(UInt8)param_7[0x3a];
    uVar20 = (UInt32)(UInt8)param_7[0x38];
    local_7c = iVar15 + iVar14;
    local_68 = 0;
    iVar22 = uVar18 * 0x1c;
    local_6c = 0;
    local_70 = 0;
    local_60 = (int)local_94[0] >> (FormatTableLookup_0x0004d2dc(iVar22) >> 0xc & 7);
    iVar14 = param_2;
  }
  else {
    local_94[0] = param_10;
    uVar18 = (UInt32)(UInt8)param_7[0x3a];
    iVar22 = uVar18 * 0x1c;
    iVar21 = M<int>(param_7 + 8);
    local_7c = iVar14 + param_9 + iVar15;
    local_60 = (int)param_10 >> (FormatTableLookup_0x0004d2dc(iVar22) >> 0xc & 7);
    local_68 = (unsigned int)(UInt8)param_7[0x39];
    iVar14 = VCALL(M<int>(self), 0x5f0)(self,param_7,param_5,param_6,0,0,&local_98);
    local_78 = iVar21 + iVar14;
    if ((bool)(bVar27 >> 1 & 1)) {
      uVar9 = (unsigned int)M<UInt16>(param_7 + 0x1e);
    }
    else {
      uVar2 = M<UInt16>(param_7 + 0x1e);
      uVar9 = (unsigned int)uVar2;
      if ((uVar2 & 0x1f) != 0) {
        uVar9 = (uVar2 & 0xffffffe0) + 0x20;
      }
    }
    uVar19 = (UInt32)(UInt8)param_7[0x3a];
    uVar17 = (UInt32)(UInt8)param_7[0x38];
    uVar20 = 0;
    local_64 = 0;
    iVar21 = uVar19 * 0x1c;
    iVar14 = 0;
    local_74 = 0;
    local_5c = (int)local_98 >> (FormatTableLookup_0x0004d2dc(iVar21) >> 0xc & 7);
    local_70 = param_2;
    local_6c = param_1;
  }
  if ((!(bool)(bVar26 >> 1 & 1)) && (!(bool)(bVar27 >> 1 & 1))) {
    uVar17 = 0;
    uVar20 = 0;
  }
  M<unsigned int>(M<int>(self + 0xc34) + 0x1c) = M<unsigned int>(M<int>(self + 0xc34) + 0x1c) | 1;
  uVar6 = M<UInt16>(self + 0xcae) + 1 & 3;
  M<SInt16>(self + 0xcae) = (SInt16)uVar6;
  if (M<int>(self + uVar6 * 0x1c + 0xc44) == 0) {
    iVar15 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(0,M<UInt32>(self + 0xcb0));
    if (iVar15 == 0) {
      return 0;
    }
  }
  else {
    piVar23 = M<int *>(self + 0xd50);
    iVar24 = piVar23[0x1e2];
    iVar15 = VCALL(*piVar23, 0x54c)(piVar23,M<UInt32>(self + uVar6 * 0x1c + 0xc4c));
    piVar23[0x1e2] = iVar24 + iVar15;
  }
  puVar25 = (UInt32 *)(M<int>(self + uVar6 * 0x1c + 0xc50) + 0x20);
  if ((bVar7) || ((bool)((bVar27 & 2) >> 1))) {
    uVar11 = 0;
  }
  else {
    uVar11 = this->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)(param_7),0,(UInt32 *)(puVar25));
  }
  uVar9 = write_3dtexquad_cmds_for_copy_buffer_using_DMA
                    (M<ATIRadeonX1000 *>(self + 0xd50),(UInt32 *)puVar25,uVar11,uVar19,local_78,local_98,
                     local_5c,uVar9,uVar17,FormatTableLookup_0x0004d2dc(iVar21) >> 0xc & 7,
                     (UInt8)local_64,uVar18,local_7c,local_94[0],local_60,uVar20,
                     FormatTableLookup_0x0004d2dc(iVar22) >> 0xc & 7,(UInt8)local_68,local_6c,local_70,
                     local_74,iVar14,param_3,param_4,SUB41m(local_80,0));
  if (!(bool)(bVar26 >> 1 & 1)) {
    M<UInt32>(M<int>(self + 0xd50) + 0xb90) = 1;
  }
  M<UInt32>(M<int>(self + 0xd50) + 0x78) = 0;
  uVar12 = uVar9;
  if ((uVar9 & 1) != 0) {
    uVar12 = uVar9 + 1;
    puVar25[uVar9] = 0x80000000;
  }
  M<unsigned int>(M<int>(self + uVar6 * 0x1c + 0xc50) + 0x14) = uVar12;
  iVar14 = M<int>(self + uVar6 * 0x1c + 0xc40);
  sVar8 = M<SInt16>(param_8 + 0xe) + 1;
  M<SInt16>(param_8 + 0xe) = sVar8;
  if (iVar14 == 0) {
    ((IOATIR500Surface *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + uVar6 * 0x1c + 0xc3c)));
    sVar8 = M<SInt16>(param_8 + 0xe);
    iVar14 = M<int>(self + uVar6 * 0x1c + 0xc40);
  }
  M<SInt16>(param_8 + 0xe) = sVar8 + -1;
  uVar13 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0xd50)))->submit_buffer((UInt32 *)(M<int>(self + uVar6 * 0x1c + 0xc50) + 0x20),iVar14 + 0x20,
                      M<UInt32>(M<int>(self + uVar6 * 0x1c + 0xc50) + 0x14));
  M<UInt32>(self + 0x7c) = uVar13;
  M<UInt32>(self + uVar6 * 0x1c + 0xc4c) = uVar13;
  if ((bool)(bVar26 >> 1 & 1)) {
    VCALL(*M<int *>(self + 0xd50), 0x54c)(M<int *>(self + 0xd50),uVar13);
    VCALL(*M<int *>(self + 0xd50), 0x5ac)(M<int *>(self + 0xd50),param_8);
    if (((bVar3) && (!bVar7)) &&
       ((M<unsigned int>(M<UInt8 *>(self + 0xd50) + 0x98) & 0x80) != 0)) {
      ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0xd50)))->flush_memory_for_in((const void *)(local_88),local_84);
    }
  }
  else {
    M<UInt32>(M<int>(param_8 + 0x14) + 8) = uVar13;
  }
  if (piVar10 != (int *)0x0) {
    VCALL(*piVar10, 0x18)(piVar10);
    return 1;
  }
  return 1;
}
