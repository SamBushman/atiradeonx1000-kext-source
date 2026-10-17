/*
 * ATIR500Surface_dealloc_surface_Port.cpp
 *
 * ATIR500Surface::dealloc_surface (real addr 0x3df70, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3df70 */
UInt32 ATIR500Surface::dealloc_surface(UInt32 surfaceIndex) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 slot;
  SInt32 iVar2;
  UInt32 uVar3;
  UInt32 submitStamp;
  SInt32 bufferOffset;
  UInt8 *entry;
  SInt32 iVar7;
  SInt32 *accel;
  PanelRecord *rec0 = PANEL_RECORD(self, 0);     /* the surface's first panel */
  
  if (2 < surfaceIndex - 6) goto LAB_0003e150;
  bufferOffset = surfaceIndex * 0x78;
  if ((M<SInt32>(self + bufferOffset + 0xb0) != 0) && (accel = M<SInt32 *>(self + 0xd50), accel[0x2e5] != 0)
     ) {
    slot = Vol(rec0->slotIndex) + 1 & 3;
    Vol(rec0->slotIndex) = (UInt16)slot;
    entry = (UInt8 *)&rec0->entries[1 + slot];     /* the submit slot in use */
    if ((SInt32)Vol(rec0->entries[1 + slot].memory) == 0) {
      iVar2 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(0,Vol(rec0->swapBufferSize));
      if (iVar2 != 0) goto LAB_0003e028;
      entry = (UInt8 *)0x0;
    }
    else {
      iVar7 = accel[0x1e2];
      iVar2 = VCALL(*accel, 0x54c)(accel,Vol(rec0->entries[1 + slot].stamp));
      accel[0x1e2] = iVar7 + iVar2;
LAB_0003e028:
      if ((SInt32)Vol(rec0->entries[1 + slot].gartOffset) == 0) {
        ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(entry));
      }
    }
    self[bufferOffset + 0xdc] = 0x0;
    if (entry != (UInt8 *)0x0) {
      uVar3 = this->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)((UInt8 *)(self + bufferOffset + 0xa8)),0,
                         (UInt32 *)(M<SInt32>(entry + 0x14) + 0x20));
      if ((uVar3 & 1) != 0) {
        iVar2 = uVar3 * 4;
        uVar3 = uVar3 + 1;
        M<UInt32>(iVar2 + M<SInt32>(entry + 0x14) + 0x20) = 0x80000000;
      }
      M<UInt32>((SInt32)Vol(rec0->entries[0].header) + 0x1c) = M<UInt32>((SInt32)Vol(rec0->entries[0].header) + 0x1c) | 1;
      M<UInt32>(M<SInt32>(self + 0xd50) + 0x710) =
           uVar3 * 4 + M<SInt32>(M<SInt32>(self + 0xd50) + 0x710);
      submitStamp = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0xd50)))->submit_buffer((UInt32 *)(M<SInt32>(entry + 0x14) + 0x20),M<SInt32>(entry + 4) + 0x20,uVar3);
      M<UInt32>(entry + 0x10) = submitStamp;
    }
  }
  uVar3 = M<UInt32>(self + bufferOffset + 0xd0);
  if ((uVar3 & 0x3ff) != 0x3ff) {
    HZMEM_Free((_HZDATA *)((UInt8 *)(M<SInt32>(self + 0xd50) + 0x870)),uVar3,0);
    self[bufferOffset + 0xdc] = 0x0;
    uVar3 = M<UInt32>(self + bufferOffset + 0xd0) & 0xfffffc00 | 0x3ff;
    M<UInt32>(self + bufferOffset + 0xd0) = uVar3;
  }
  if ((uVar3 & 0xffc00) != 0xffc00) {
    HZMEM_Free((_HZDATA *)((UInt8 *)(M<SInt32>(self + 0xd50) + 0x870)),uVar3,1);
    self[bufferOffset + 0xdd] = 0x0;
    M<UInt32>(self + bufferOffset + 0xd0) = M<UInt32>(self + bufferOffset + 0xd0) & 0xfff003ff | 0xffc00;
  }
LAB_0003e150:
  if ((surfaceIndex == 9) && ((M<UInt32>(self + 0x508) & 0x3ff00000) != 0x3ff00000)) {
    HZMEM_Free((_HZDATA *)((UInt8 *)(M<SInt32>(self + 0xd50) + 0x870)),M<UInt32>(self + 0x508),2);
    self[0x516] = 0x0;
    M<UInt32>(self + 0x508) = M<UInt32>(self + 0x508) & 0xc00fffff | 0x3ff00000;
  }
  IOATIR500Surface::dealloc_surface(surfaceIndex);
  return 1;
}
