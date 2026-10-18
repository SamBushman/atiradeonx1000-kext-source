/*
 * IOATIR500DVDContext_freeToAllocGART_Port.cpp
 *
 * IOATIR500DVDContext::freeToAllocGART (real addr 0xe8a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0xe8a0 */
bool IOATIR500DVDContext::freeToAllocGART(VendorTransferBuffer *needed, bool aggressive) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  bool lastSlot;
  SInt32 iVar2;
  SInt32 freed;
  UInt8 *slot;
  UInt8 *slotBase;
  
  iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500DVDContext_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500DVDContext_contextBuffer)),
                     (VendorTransferBuffer *)(neededBytes),M<UInt32>(self + kIOATIR500DVDContext_contextBufferStamp),aggressive);
  if ((iVar2 == 0) &&
     (iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500DVDContext_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500DVDContext_commandBuffer)),(VendorTransferBuffer *)(neededBytes),M<UInt32>(self + kIOATIR500DVDContext_commandBufferStamp),
                         aggressive), iVar2 == 0)) {
    iVar2 = 0;
    slot = (UInt8 *)(self + kIOATIR500DVDContext_contextBufferRing);
    slotBase = self;
    while (freed = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500DVDContext_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)(slot),(VendorTransferBuffer *)(neededBytes),
                              M<UInt32>(slotBase + 0xd4),aggressive), freed == 0) {
      lastSlot = iVar2 == 1;
      slot = slot + 0x18;
      slotBase = slotBase + 0x18;
      iVar2 = iVar2 + 1;
      if (lastSlot) {
        return 0;
      }
    }
  }
  return 1;
}
