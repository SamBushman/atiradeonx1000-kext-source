/*
 * ATIR500Surface_submit_flip_buffer_Port.cpp
 *
 * ATIR500Surface::submit_flip_buffer (real addr 0x3e5c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3e5c0 */
void ATIR500Surface::submit_flip_buffer(UInt32 panel, IOATIR500GLContext *context, UInt32 unused4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);
    UInt8 *contextBytes = reinterpret_cast<UInt8 *>(context);

  bool bVar1;
  bool bVar2;
  UInt8 bVar3;
  UInt16 uVar4;
  UInt16 uVar5;
  int iVar6;
  SInt16 sVar7;
  UInt32 *puVar9;
  UInt32 *packet;
  unsigned int uVar10;
  int iVar11;
  int valueIndex;
  int iVar12;
  unsigned int uVar13;
  UInt32 uVar14;
  unsigned int uVar15;
  unsigned int uVar16;
  int iVar17;
  int markerValueIndex;
  int slotHeaderAddr;
  int waited;
  UInt32 *puVar18;
  int iVar19;
  UInt32 uVar20;
  UInt32 uVar21;
  unsigned int uVar22;
  UInt8 *pVVar23;
  int *piVar24;
  UInt8 *pAccel;
  unsigned int wordIndex;
  int otherPanelRecord;
  int accel;
  
  if (M<SInt16>(self + kATIR500Surface_swapBatchBuilt) != 0) {
    M<UInt32>(M<int>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
  }
  if (M<UInt32>(self + kIOATIR500Surface_flipContext) != (UInt32)contextBytes) {
    M<UInt32>(self + kIOATIR500Surface_flipContext) = (UInt32)contextBytes;
    iVar17 = (int)Vol(PANEL_RECORD(self, panel)->entries[0].header);
    M<unsigned int>(iVar17 + 0x1c) = M<unsigned int>(iVar17 + 0x1c) | 1;
  }
  PanelRecord *rec = PANEL_RECORD(self, panel);
  SwapBufferEntry *slot;     /* the submit slot in use: entries[1 + slotIndex] */
  if ((M<unsigned int>((int)Vol(rec->entries[0].header) + 0x1c) & 1) == 0) {
    slot = &rec->entries[1 + (unsigned int)Vol(rec->slotIndex)];
    pVVar23 = (UInt8 *)slot;
    if (((int)Vol(slot->memory) == 0) &&
       (iVar17 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers((UInt32)panel,Vol(rec->swapBufferSize)),
       iVar17 == 0)) {
      return;
    }
    goto LAB_0003ee00;
  }
  uVar13 = Vol(rec->slotIndex) + 1 & 3;
  Vol(rec->slotIndex) = (UInt16)uVar13;
  slot = &rec->entries[1 + uVar13];
  pVVar23 = (UInt8 *)slot;
  if ((int)Vol(slot->memory) == 0) {
    iVar17 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers((UInt32)panel,Vol(rec->swapBufferSize));
    if (iVar17 == 0) {
      return;
    }
  }
  else {
    piVar24 = M<int *>(self + kIOATIR500Surface_accelerator);
    iVar12 = piVar24[0x1e2];
    waited = VCALL(*piVar24, 0x54c)(piVar24,Vol(slot->stamp));
    piVar24[0x1e2] = iVar12 + waited;
  }
  puVar18 = (UInt32 *)Vol(slot->header);
  puVar9 = (UInt32 *)Vol(rec->entries[0].header);
  uVar21 = puVar9[1];
  uVar20 = puVar9[2];
  uVar14 = puVar9[3];
  *puVar18 = *puVar9;
  puVar18[1] = uVar21;
  puVar18[2] = uVar20;
  puVar18[3] = uVar14;
  uVar14 = puVar9[7];
  uVar21 = puVar9[4];
  uVar20 = puVar9[6];
  puVar18[5] = puVar9[5];
  puVar18[7] = uVar14;
  puVar18[4] = uVar21;
  puVar18[6] = uVar20;
  slotHeaderAddr = (int)Vol(slot->header);
  packet = (UInt32 *)(slotHeaderAddr + 0x20);
  *packet = 0xd0b;
  M<UInt32>(slotHeaderAddr + 0x24) = 5;
  M<UInt32>(slotHeaderAddr + 0x28) = 0x1393;
  M<UInt32>(slotHeaderAddr + 0x2c) = 10;
  M<UInt32>(slotHeaderAddr + 0x30) = 0x5c8;
  M<UInt32>(slotHeaderAddr + 0x34) = 0x30000;
  if (contextBytes == 0) {
    wordIndex = 6;
    sVar7 = 0;
  }
  else {
    iVar19 = M<int>((unsigned int)M<UInt16>(contextBytes + 0xac) * 4 + self + kIOATIR500Surface_attachmentBuffers);
    iVar11 = M<int>(iVar19 + 0x40);
    uVar4 = M<UInt16>(iVar19 + 0x20);
    uVar13 = M<unsigned int>(iVar19 + 0x3c);
    iVar12 = M<int>(iVar19 + 8);
    bVar1 = (uVar13 & 0xf00000) != 0;
    if (bVar1) {
      uVar16 = (unsigned int)M<UInt16>(iVar19 + 0x14) / (uVar13 >> 0x14 & 0xf);
    }
    else {
      uVar16 = 0;
    }
    uVar5 = M<UInt16>(iVar19 + 0x16);
    uVar15 = 0x20 / uVar5;
    if (uVar16 < uVar15) {
      uVar16 = uVar15;
    }
    bVar3 = M<UInt8>(iVar19 + 0x38);
    uVar22 = 0x80000000;
    if (bVar3 < 2) {
      uVar22 = 0;
    }
    iVar6 = (unsigned int)M<UInt8>(iVar19 + 0x3a) * 0x1c;
    if (bVar1) {
      uVar13 = (unsigned int)M<UInt16>(iVar19 + 0x14) / (uVar13 >> 0x14 & 0xf);
    }
    else {
      uVar13 = 0;
    }
    if (uVar13 < uVar15) {
      uVar13 = uVar15;
    }
    uVar15 = FormatTableLookup_0x0004d2dc(iVar6);
    uVar10 = FormatTableLookup_0x0004d2e0(iVar6);
    M<UInt32>(slotHeaderAddr + 0x38) = 0x50b;
    M<unsigned int>(slotHeaderAddr + 0x3c) =
         uVar22 | iVar12 + (unsigned int)uVar4 * iVar11 >> 10 | uVar16 * uVar5 * 0x10000 & 0x3fc00000 |
                  (bVar3 & 1) << 0x1e;
    M<UInt32>(slotHeaderAddr + 0x40) = 0x138a;
    M<int>(slotHeaderAddr + 0x44) = iVar12;
    M<UInt32>(slotHeaderAddr + 0x48) = 0x138e;
    M<unsigned int>(slotHeaderAddr + 0x4c) =
         uVar10 >> 1 & 0x1e00000 |
         (uVar15 & 0xc00) << 9 | (bVar3 & 6) << 0x10 | (bVar3 & 1) << 0x10 | uVar13 & 0x3ffe;
    sVar7 = M<SInt16>(contextBytes + 0x98);
    wordIndex = 0xc;
  }
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb78) =
       M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb78) & 0xffdfffff |
       (M<UInt8>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x38) & 1) << 0x15;
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb78) =
       (unsigned int)(1 < M<UInt8>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x38)) * 0x100000 |
       M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb78) & 0xffefffff;
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb80) =
       (unsigned int)(sVar7 == 0) | M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb80) & 0xfffffffe;
  if (panel[self + 0xdb6] == 0x0) {
    uVar16 = 0;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) & 0xfeffffff;
  }
  else {
    uVar16 = M<UInt16>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x14) & 0x3fff;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) & 0xfeffffff | 0x1000000;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) & 0xfffffeff;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb88) & 0xfffeffff;
  }
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb7c) =
       M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb7c) & 0xffdfffff |
       (M<UInt8>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x38) & 1) << 0x15;
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb7c) =
       (unsigned int)(1 < M<UInt8>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x38)) * 0x100000 |
       M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb7c) & 0xffefffff;
  M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb84) =
       (unsigned int)(sVar7 == 0) | M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb84) & 0xfffffffe;
  if (panel[self + 0xdb6] == 0x0) {
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) & 0xfeffffff;
  }
  else {
    uVar16 = M<UInt16>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 0x14) & 0x3fff;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) & 0xfeffffff | 0x1000000;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) & 0xfffffeff;
    M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) =
         M<unsigned int>(M<int>(self + kIOATIR500Surface_accelerator) + 0xb8c) & 0xfffeffff;
  }
  accel = M<int>(self + kIOATIR500Surface_accelerator);
  if (M<int>(accel + 0x894) != 0) {
    M<unsigned int>(accel + 0xb80) = M<unsigned int>(accel + 0xb80) & 0xfffffffe | 1;
    accel = M<int>(self + kIOATIR500Surface_accelerator);
  }
  bVar1 = panel == 0;
  if ((bVar1) || (M<int>(accel + 0x894) != 0)) {
    if (panel[self + 0xdb6] != 0x0) {
      packet[wordIndex] = 0x1848;
      valueIndex = wordIndex + 1;
      wordIndex = wordIndex + 2;
      packet[valueIndex] = uVar16;
    }
    packet[wordIndex] = 0x1841;
    packet[wordIndex + 1] = M<UInt32>(accel + 0xb78);
    packet[wordIndex + 2] = 0x1852;
    packet[wordIndex + 3] = M<UInt32>(accel + 0xb80);
    packet[wordIndex + 4] = 0x1831;
    valueIndex = wordIndex + 5;
    wordIndex = wordIndex + 6;
    packet[valueIndex] = M<UInt32>(accel + 0xb88);
  }
  bVar2 = panel == 1;
  if ((bVar2) || (M<int>(accel + 0x894) != 0)) {
    if (panel[self + 0xdb6] != 0x0) {
      packet[wordIndex] = 0x1a48;
      valueIndex = wordIndex + 1;
      wordIndex = wordIndex + 2;
      packet[valueIndex] = uVar16;
    }
    packet[wordIndex] = 0x1a41;
    packet[wordIndex + 1] = M<UInt32>(accel + 0xb7c);
    packet[wordIndex + 2] = 0x1a52;
    packet[wordIndex + 3] = M<UInt32>(accel + 0xb84);
    packet[wordIndex + 4] = 0x1a31;
    valueIndex = wordIndex + 5;
    wordIndex = wordIndex + 6;
    packet[valueIndex] = M<UInt32>(accel + 0xb8c);
  }
  uVar14 = M<UInt32>(M<int>(self + kIOATIR500Surface_attachmentBuffers) + 8);
  if ((bVar1) || (uVar16 = wordIndex, M<int>(accel + 0x894) != 0)) {
    packet[wordIndex] = 0x1844;
    packet[wordIndex + 1] = uVar14;
    packet[wordIndex + 2] = 0x1844;
    packet[wordIndex + 3] = uVar14;
    packet[wordIndex + 4] = 0x1844;
    uVar16 = wordIndex + 6;
    packet[wordIndex + 5] = uVar14;
    if (panel[self + 0xdb6] != 0x0) {
      packet[uVar16] = 0x1846;
      uVar16 = wordIndex + 8;
      packet[wordIndex + 7] = M<UInt32>(M<int>(self + kIOATIR500Surface_attachmentBuffer5) + 8);
    }
  }
  if ((bVar2) || (wordIndex = uVar16, M<int>(accel + 0x894) != 0)) {
    packet[uVar16] = 0x1a44;
    packet[uVar16 + 1] = uVar14;
    packet[uVar16 + 2] = 0x1a44;
    packet[uVar16 + 3] = uVar14;
    packet[uVar16 + 4] = 0x1a44;
    wordIndex = uVar16 + 6;
    packet[uVar16 + 5] = uVar14;
    if (panel[self + 0xdb6] != 0x0) {
      packet[wordIndex] = 0x1a46;
      wordIndex = uVar16 + 8;
      packet[uVar16 + 7] = M<UInt32>(M<int>(self + kIOATIR500Surface_attachmentBuffer5) + 8);
    }
  }
  if (M<char>(accel + 0x9b0) == '\0') {
LAB_0003ed40:
    if (bVar1) {
      packet[wordIndex] = 0x5c8;
      markerValueIndex = wordIndex + 1;
      wordIndex = wordIndex + 2;
      packet[markerValueIndex] = 1;
    }
    else if (bVar2) {
      packet[wordIndex] = 0x5c8;
      markerValueIndex = wordIndex + 1;
      wordIndex = wordIndex + 2;
      packet[markerValueIndex] = 0x80000001;
    }
  }
  else if (M<int>((int)panel * 0x18 + accel + 0xb10) == 0) {
    if (M<int>(accel + 0x894) != 0) {
      if (bVar1) {
        otherPanelRecord = 0xb18;
      }
      else {
        otherPanelRecord = 0xb00;
      }
      if (M<int>(accel + otherPanelRecord + 0x10) != 0) goto LAB_0003eda0;
    }
    goto LAB_0003ed40;
  }
LAB_0003eda0:
  uVar16 = wordIndex;
  if ((wordIndex & 7) != 0) {
    uVar16 = wordIndex + 1;
    packet[wordIndex] = 0x80000000;
  }
  M<unsigned int>((int)Vol(slot->header) + 0x14) = uVar16;
LAB_0003ee00:
  if (M<int>(pVVar23 + 4) == 0) {
    ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar23));
  }
  M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x710) =
       M<int>(M<int>(pVVar23 + 0x14) + 0x14) * 4 + M<int>(M<int>(self + kIOATIR500Surface_accelerator) + 0x710);
  pAccel = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
  uVar14 = ((ATIRadeonX1000 *)pAccel)->submit_buffer
                     ((UInt32 *)(M<int>(pVVar23 + 0x14) + 0x20),M<int>(pVVar23 + 4) + 0x20,
                      M<UInt32>(M<int>(pVVar23 + 0x14) + 0x14));
  M<UInt32>(pVVar23 + 0x10) = uVar14;
  M<UInt32>(self + kIOATIR500Surface_submittedStamp) = uVar14;
  M<UInt32>(pAccel + (int)panel * 0x20 + 0xec) = uVar14;
  return;
}
