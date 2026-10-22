/*
 * IOATIR5002DContext_allocAllContextBuffers_Port.cpp
 *
 * IOATIR5002DContext::allocAllContextBuffers (real addr 0xbee0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(...) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj");


/* real addr 0xbee0 */
bool IOATIR5002DContext::allocAllContextBuffers(UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool more;
  SInt32 *descriptor;
  VendorContextBufferHeader *header;
  UInt32 result;
  SInt32 released;
  SInt32 bufferIndex;
  UInt8 *slotCursor;
  
  descriptor = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(0x10023,size,GH_page_size);
  result = 0;
  M<SInt32 *>(self + kIOATIR5002DContext_contextBufferDescriptor) = descriptor;
  if (descriptor != (SInt32 *)0x0) {
    bufferIndex = 0;
    header = (VendorContextBufferHeader *)VCALL(*descriptor, 0x1cc)(descriptor);
    M<VendorContextBufferHeader *>(self + kIOATIR5002DContext_contextBufferHeader) = header;
    this->init_context_buffer_header((VendorContextBufferHeader *)(header),size);
    slotCursor = self;
    do {
      descriptor = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x82c) | 0x10023,size,
                                   GH_page_size);
      M<SInt32 *>(slotCursor + 0xd4) = descriptor;
      if (descriptor == (SInt32 *)0x0) {
        if (-1 < bufferIndex + -1) {
          released = 0;
          slotCursor = self + (bufferIndex + -1) * 0x18 + 0xd4;
          do {
            released = released + 1;
            VCALL(*M<SInt32 *>(slotCursor), 0x18)(M<SInt32 *>(slotCursor));
            M<UInt32>(slotCursor + -8) = 0;
            M<UInt32>(slotCursor + -4) = 0;
            M<UInt32>(slotCursor) = 0;
            M<UInt16>(slotCursor + 6) = 0;
            M<UInt16>(slotCursor + 4) = 0;
            M<UInt32>(slotCursor + 8) = 0;
            M<UInt32>(slotCursor + 0xc) = 0;
            slotCursor = slotCursor + -0x18;
          } while (released != bufferIndex);
        }
        VCALL(*M<SInt32 *>(self + kIOATIR5002DContext_contextBufferDescriptor), 0x18)(M<SInt32 *>(self + kIOATIR5002DContext_contextBufferDescriptor));
        M<UInt32>(self + kIOATIR5002DContext_contextBufferHeader) = 0;
        M<UInt32>(self + kIOATIR5002DContext_contextBuffer) = 0;
        M<UInt32>(self + kIOATIR5002DContext_contextBufferGartOffset) = 0;
        M<UInt32>(self + kIOATIR5002DContext_contextBufferDescriptor) = 0;
        M<UInt16>(self + kIOATIR5002DContext_contextBufferInFlight) = 0;
        M<UInt16>(self + kIOATIR5002DContext_contextBufferType) = 0;
        M<UInt32>(self + kIOATIR5002DContext_contextBufferStamp) = 0;
        return 0;
      }
      header = (VendorContextBufferHeader *)VCALL(*descriptor, 0x1cc)(descriptor);
      M<VendorContextBufferHeader *>(slotCursor + 0xe0) = header;
      slotCursor = slotCursor + 0x18;
      this->init_context_buffer_header((VendorContextBufferHeader *)(header),size);
      more = bufferIndex != 1;
      bufferIndex = bufferIndex + 1;
    } while (more);
    result = 1;
  }
  return result;
}
