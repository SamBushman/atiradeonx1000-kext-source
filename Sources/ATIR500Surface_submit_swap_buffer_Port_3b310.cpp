/*
 * ATIR500Surface_submit_swap_buffer_Port_3b310.cpp
 *
 * ATIR500Surface::submit_swap_buffer (real addr 0x3b310, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3b310 */
void ATIR500Surface::submit_swap_buffer(UInt32 panel, eDoSwap doSwap, IOATIR500GLContext *context) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    /* Ghidra numbers the real arguments by register slot: panel = panel (r4), doSwap = doSwap (r5), context = contextAddress (r6) */
    UInt32 contextAddress = reinterpret_cast<UInt32>(context);

  bool bVar1;
  int iVar2;
  UInt32 uVar3;
  UInt32 *pendingBatch;
  UInt32 *puVar5;
  int iVar6;
  UInt8 *accelerator;
  int iVar8;
  unsigned int uVar9;
  int iVar10;
  UInt32 uVar11;
  int iVar12;
  int iVar13;
  UInt32 *slotHeader;
  UInt32 uVar15;
  int iVar16;
  int iVar17;
  UInt32 uVar18;
  unsigned int uVar19;
  UInt32 *puVar20;
  int iVar21;
  int *piVar23;
  unsigned int uVar24;
  int iVar25;
  UInt32 *cmd;
  UInt8 *pVVar27;
  UInt8 bVar28;
  
  if (M<SInt16>(self + kATIR500Surface_swapBatchBuilt) != 0) {
    M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
  }
  if (M<int>(self + kIOATIR500Surface_flipContext) == contextAddress) {
    if (doSwap != (UInt8)self[panel * 0x94 + 0xcad]) {
      self[panel * 0x94 + 0xcad] = SUB41m(doSwap,0);
      M<unsigned int>((int)Vol(PANEL_RECORD(self, panel)->entries[0].header) + 0x1c) =
           M<unsigned int>((int)Vol(PANEL_RECORD(self, panel)->entries[0].header) + 0x1c) | 1;
    }
  }
  else {
    M<int>(self + kIOATIR500Surface_flipContext) = contextAddress;
    M<unsigned int>((int)Vol(PANEL_RECORD(self, panel)->entries[0].header) + 0x1c) =
         M<unsigned int>((int)Vol(PANEL_RECORD(self, panel)->entries[0].header) + 0x1c) | 1;
  }
  PanelRecord *rec = PANEL_RECORD(self, panel);
  SwapBufferEntry *slot;     /* the submit slot in use: entries[1 + slotIndex] */
  iVar17 = (int)Vol(rec->entries[0].header);
  if ((M<unsigned int>(iVar17 + 0x1c) & 1) == 0) {
    slot = &rec->entries[1 + (unsigned int)Vol(rec->slotIndex)];
    pVVar27 = (UInt8 *)slot;
    if (((int)Vol(slot->memory) == 0) &&
       (iVar17 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(panel,Vol(rec->swapBufferSize)),
       iVar17 == 0)) {
      return;
    }
    goto LAB_0003b900;
  }
  bVar28 = (doSwap == 1) << 1;
  if (doSwap == 1) {
    iVar21 = M<int>(iVar17 + 0x18);
    puVar20 = (UInt32 *)(iVar17 + 0x20);
  }
  else if (doSwap == 2) {
    iVar21 = M<int>(iVar17 + 0x14) - M<int>(iVar17 + 0x18);
    puVar20 = (UInt32 *)(iVar17 + 0x20 + M<int>(iVar17 + 0x18) * 4);
  }
  else {
    iVar21 = M<int>(iVar17 + 0x14);
    puVar20 = (UInt32 *)(iVar17 + 0x20);
  }
  if (iVar21 == 0) {
    return;
  }
  uVar9 = Vol(rec->slotIndex) + 1 & 3;
  Vol(rec->slotIndex) = (UInt16)uVar9;
  slot = &rec->entries[1 + uVar9];
  pVVar27 = (UInt8 *)slot;
  if ((int)Vol(slot->memory) == 0) {
    iVar6 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(panel,Vol(rec->swapBufferSize));
    if (iVar6 == 0) {
      return;
    }
  }
  else {
    piVar23 = M<int *>(self + kIOATIR500Surface_accelerator);
    iVar12 = piVar23[0x1e2];
    iVar6 = VCALL(*piVar23, 0x54c)(piVar23,Vol(slot->stamp));
    piVar23[0x1e2] = iVar12 + iVar6;
  }
  slotHeader = (UInt32 *)Vol(slot->header);
  pendingBatch = (UInt32 *)Vol(rec->entries[0].header);
  uVar18 = pendingBatch[1];
  uVar15 = pendingBatch[2];
  uVar11 = pendingBatch[3];
  *slotHeader = *pendingBatch;
  slotHeader[1] = uVar18;
  slotHeader[2] = uVar15;
  slotHeader[3] = uVar11;
  uVar18 = pendingBatch[4];
  uVar15 = pendingBatch[5];
  uVar11 = pendingBatch[6];
  slotHeader[7] = pendingBatch[7];
  slotHeader[4] = uVar18;
  slotHeader[5] = uVar15;
  slotHeader[6] = uVar11;
  iVar6 = (int)Vol(slot->header);
  cmd = (UInt32 *)(iVar6 + 0x20);
  if (((((bool)(bVar28 >> 1 & 1)) || (contextAddress == 0)) || (M<SInt16>(contextAddress + 0x98) < 1)) ||
     ((iVar12 = M<int>(self + kIOATIR500Surface_accelerator), M<char>(iVar12 + 0x9b0) != '\0' &&
      (M<int>(panel * 0x18 + iVar12 + 0xb10) != 0)))) {
    iVar8 = 0;
  }
  else {
    uVar9 = M<UInt16>(panel * 0x78 + iVar12 + 0x14a) & 0xfff;
    *cmd = 0x1393;
    M<UInt32>(iVar6 + 0x24) = 10;
    M<UInt32>(iVar6 + 0x28) = 0xd0b;
    M<UInt32>(iVar6 + 0x2c) = 5;
    M<UInt32>(iVar6 + 0x30) = 0x5c8;
    M<UInt32>(iVar6 + 0x34) = 0x70000;
    if (panel == 0) {
      iVar2 = M<int>(iVar12 + 0x894);
      if (iVar2 == 0) {
        M<UInt32>(iVar6 + 0x38) = 0x194e;
        M<unsigned int>(iVar6 + 0x3c) = (uVar9 & ~M<unsigned int>(iVar12 + 0x898)) << 0x10 | 0x80000000;
        M<UInt32>(iVar6 + 0x40) = 0x5c8;
        M<UInt32>(iVar6 + 0x44) = 8;
        iVar8 = 10;
      }
      else {
LAB_0003b5e0:
        iVar8 = 6;
        if (iVar2 != 0) goto LAB_0003b5ec;
      }
    }
    else {
      if (panel != 1) {
        iVar2 = M<int>(iVar12 + 0x894);
        goto LAB_0003b5e0;
      }
LAB_0003b5ec:
      iVar8 = 10;
      M<UInt32>(iVar6 + 0x38) = 0x1b4e;
      M<unsigned int>(iVar6 + 0x3c) = (uVar9 & ~M<unsigned int>(iVar12 + 0x89c)) << 0x10 | 0x80000000;
      M<UInt32>(iVar6 + 0x40) = 0x5c8;
      M<UInt32>(iVar6 + 0x44) = 0x80000008;
    }
  }
  iVar6 = 0;
  puVar5 = cmd + iVar8;
  do {
    uVar3 = *puVar20;
    iVar6 = iVar6 + 1;
    puVar20 = puVar20 + 1;
    *puVar5 = uVar3;
    puVar5 = puVar5 + 1;
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  uVar9 = iVar8 + iVar6;
  if (((bool)(bVar28 >> 1 & 1)) || (M<SInt16>(contextAddress + 0x94) == 0)) {
    accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
  }
  else {
    accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
    iVar21 = panel * 0x78;
    uVar24 = 0;
    uVar19 = (unsigned int)M<UInt16>(accelerator + iVar21 + 0x144);
    if (uVar19 != 0) {
      uVar24 = (M<unsigned int>(accelerator + iVar21 + 0x134) & 0x3ff) / uVar19;
    }
    iVar6 = 0;
    if (M<UInt16>(accelerator + iVar21 + 0x142) != 0) {
      iVar6 = (int)((M<unsigned int>(accelerator + iVar21 + 0x134) & 0x3ff) - uVar24 * uVar19) /
              (int)(unsigned int)M<UInt16>(accelerator + iVar21 + 0x142);
    }
    iVar21 = (int)Vol(rec->entries[0].rectWordIndex);
    if (doSwap == 2) {
      iVar21 = iVar21 - M<int>((int)Vol(rec->entries[0].header) + 0x18);
    }
    iVar12 = (int)M<SInt16>(contextAddress + 0x90);
    iVar2 = M<int>(self + panel * 8 + 0xd60);
    iVar13 = (int)M<SInt16>(iVar2 + 10);
    iVar16 = iVar13 - ((int)M<SInt16>(contextAddress + 0x92) + (int)M<SInt16>(contextAddress + 0x96));
    iVar8 = iVar12;
    if (iVar12 < 0) {
      iVar8 = 0;
    }
    if (iVar16 < 0) {
      iVar16 = 0;
    }
    iVar12 = iVar12 + M<SInt16>(contextAddress + 0x94);
    iVar10 = iVar13 - M<SInt16>(contextAddress + 0x92);
    iVar6 = iVar6 + M<SInt16>(iVar2 + 4);
    iVar25 = uVar24 + (int)M<SInt16>(iVar2 + 6);
    if (M<SInt16>(iVar2 + 8) < iVar12) {
      iVar12 = (int)M<SInt16>(iVar2 + 8);
    }
    if (iVar13 < iVar10) {
      iVar10 = iVar13;
    }
    cmd[iVar21] = iVar8 + iVar6 & 0x1fffU | (iVar16 + iVar25) * 0x2000 & 0x3ffe000U;
    cmd[iVar21 + 1] =
         (iVar12 + iVar6) - 1U & 0x1fff | (iVar10 + iVar25 + -1) * 0x2000 & 0x3ffe000U;
  }
  if ((self[0xbed] == 0x0) &&
     ((((bool)(bVar28 >> 1 & 1) || (contextAddress == 0)) || (M<SInt16>(contextAddress + 0x98) < 1)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((accelerator[0x9b0] == 0x0) || (!bVar1)) {
LAB_0003b870:
    uVar11 = 0;
  }
  else if (M<int>(accelerator + panel * 0x18 + kIOATIR500Accelerator_swdsPanel0Flag) == 0) {
    if ((M<int>(accelerator + kIOATIR500Accelerator_scanoutOverlapsVram) == 0) ||
       (M<int>(accelerator + (unsigned int)(panel == 0) * 0x18 + kIOATIR500Accelerator_swdsPanel0Flag) == 0)) goto LAB_0003b870;
    uVar9 = ((ATIRadeonX1000 *)(accelerator))->SWDSWriteBlitToCmdBuf((UInt32 *)(cmd), uVar9, true, (unsigned int)(panel == 0));
    uVar11 = 1;
  }
  else {
    uVar9 = ((ATIRadeonX1000 *)(accelerator))->SWDSWriteBlitToCmdBuf((UInt32 *)(cmd), uVar9, true, panel);
    uVar11 = 1;
  }
  *(UInt32 *)Vol(slot->header) = uVar11;
  uVar19 = uVar9;
  if ((uVar9 & 1) != 0) {
    uVar19 = uVar9 + 1;
    cmd[uVar9] = 0x80000000;
  }
  M<unsigned int>((int)Vol(slot->header) + 0x14) = uVar19;
  M<unsigned int>((int)Vol(rec->entries[0].header) + 0x1c) =
       M<unsigned int>((int)Vol(rec->entries[0].header) + 0x1c) & 0xfffffffe;
LAB_0003b900:
  iVar17 = M<int>(pVVar27 + 0x14);
  if (M<int>(iVar17 + 0x14) != 0) {
    if (M<int>(pVVar27 + 4) == 0) {
      ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar27));
      iVar17 = M<int>(pVVar27 + 0x14);
    }
    M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x710) =
         M<int>(iVar17 + 0x14) * 4 + M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x710);
    accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
    uVar11 = ((ATIRadeonX1000 *)(accelerator))->submit_buffer((UInt32 *)(M<int>(pVVar27 + 0x14) + 0x20),
                        M<int>(pVVar27 + 4) + 0x20,M<UInt32>(M<int>(pVVar27 + 0x14) + 0x14));
    M<UInt32>(pVVar27 + 0x10) = uVar11;
    M<UInt32>(self + kIOATIR500Surface_submittedStamp) = uVar11;
    M<UInt32>(accelerator + panel * 0x20 + kIOATIR500Accelerator_framebuffer0SubmitStamp) = uVar11;
    iVar17 = M<int>(self + kIOATIR500Surface_accelerator);
    if ((M<char>(iVar17 + 0x9b0) != '\0') && (*M<int *>(pVVar27 + 0x14) != 0)) {
      if (M<int>(panel * 0x18 + iVar17 + 0xb10) == 0) {
        if ((M<int>(iVar17 + 0x894) != 0) &&
           (M<int>((unsigned int)(panel == 0) * 0x18 + iVar17 + 0xb10) != 0)) {
          M<UInt32>((unsigned int)(panel == 0) * 4 + iVar17 + 0xad4) = M<UInt32>(self + kIOATIR500Surface_submittedStamp);
          M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
        }
      }
      else {
        M<UInt32>(panel * 4 + iVar17 + 0xad4) = M<UInt32>(self + kIOATIR500Surface_submittedStamp);
        M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
      }
    }
  }
  return;
}
