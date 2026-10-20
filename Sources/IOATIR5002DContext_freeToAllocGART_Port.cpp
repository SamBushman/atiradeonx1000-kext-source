/*
 * IOATIR5002DContext_freeToAllocGART_Port.cpp
 *
 * IOATIR5002DContext::freeToAllocGART (real addr 0xbbc0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0xbbc0 */
bool IOATIR5002DContext::freeToAllocGART(VendorTransferBuffer *needed, bool aggressive) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  bool lastEntry;
  SInt32 iVar2;
  SInt32 freed;
  UInt8 *candidate;
  UInt8 *ringEntry;
  SInt32 freedBuffer;
  SInt32 ringIndex;
  
  freedBuffer = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR5002DContext_contextBuffer)),
                     (VendorTransferBuffer *)(neededBytes),M<UInt32>(self + kIOATIR5002DContext_contextBufferStamp),aggressive);
  if ((freedBuffer == 0) &&
     (freedBuffer = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR5002DContext_commandBuffer)),(VendorTransferBuffer *)(neededBytes),M<UInt32>(self + kIOATIR5002DContext_commandBufferStamp),
                         aggressive), freedBuffer == 0)) {
    ringIndex = 0;
    candidate = (UInt8 *)(self + kIOATIR5002DContext_contextBufferRing);
    ringEntry = self;
    while (freed = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR5002DContext_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)(candidate),(VendorTransferBuffer *)(neededBytes),
                              M<UInt32>(ringEntry + 0xdc),aggressive), freed == 0) {
      lastEntry = ringIndex == 1;
      candidate = candidate + 0x18;
      ringEntry = ringEntry + 0x18;
      ringIndex = ringIndex + 1;
      if (lastEntry) {
        return 0;
      }
    }
  }
  return 1;
}
