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
  
  iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0x94)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + 0xb4)),
                     (VendorTransferBuffer *)(neededBytes),M<UInt32>(self + 0xc4),aggressive);
  if ((iVar2 == 0) &&
     (iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0x94)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + 0x98)),(VendorTransferBuffer *)(neededBytes),M<UInt32>(self + 0xa8),
                         aggressive), iVar2 == 0)) {
    iVar2 = 0;
    candidate = (UInt8 *)(self + 0xcc);
    ringEntry = self;
    while (freed = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0x94)))->freeTransferToAllocGART((VendorTransferBuffer *)(candidate),(VendorTransferBuffer *)(neededBytes),
                              M<UInt32>(ringEntry + 0xdc),aggressive), freed == 0) {
      lastEntry = iVar2 == 1;
      candidate = candidate + 0x18;
      ringEntry = ringEntry + 0x18;
      iVar2 = iVar2 + 1;
      if (lastEntry) {
        return 0;
      }
    }
  }
  return 1;
}
