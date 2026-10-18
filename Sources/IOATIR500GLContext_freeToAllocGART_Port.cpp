/*
 * IOATIR500GLContext_freeToAllocGART_Port.cpp
 *
 * IOATIR500GLContext::freeToAllocGART (real addr 0x7a50, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x7a50 */
bool IOATIR500GLContext::freeToAllocGART(VendorTransferBuffer *needed, bool aggressive) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  bool bVar1;
  SInt32 freed;
  SInt32 iVar3;
  UInt32 result;
  UInt8 *pIVar5;
  UInt8 *candidate;
  
  freed = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_contextBuffer)),
                     (VendorTransferBuffer *)(neededBytes),M<UInt32>(self + kIOATIR500GLContext_contextBufferStamp),aggressive);
  if ((freed == 0) &&
     (freed = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)),(VendorTransferBuffer *)(neededBytes),M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp),
                         aggressive), freed == 0)) {
    freed = 0;
    candidate = (UInt8 *)(self + kIOATIR500GLContext_contextBufferRing);
    pIVar5 = self;
    do {
      iVar3 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)(candidate),(VendorTransferBuffer *)(neededBytes),
                         M<UInt32>(pIVar5 + 0x11c),aggressive);
      if (iVar3 != 0) goto LAB_00007b30;
      bVar1 = freed != 0xf;
      candidate = candidate + 0x18;
      pIVar5 = pIVar5 + 0x18;
      freed = freed + 1;
    } while (bVar1);
    for (candidate = M<UInt8 *>(self + kIOATIR500GLContext_dataBufferListHead); candidate != (UInt8 *)0x0;
        candidate = M<UInt8 *>(candidate + 0x3c)) {
      freed = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)(candidate),(VendorTransferBuffer *)(neededBytes),
                         M<UInt32>(candidate + 0x5c),aggressive);
      if (freed != 0) goto LAB_00007b30;
    }
    result = 0;
  }
  else {
LAB_00007b30:
    result = 1;
  }
  return result;
}
