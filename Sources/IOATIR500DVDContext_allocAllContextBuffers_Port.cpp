/*
 * IOATIR500DVDContext_allocAllContextBuffers_Port.cpp
 *
 * IOATIR500DVDContext::allocAllContextBuffers (real addr 0xeab0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xeab0 */
bool IOATIR500DVDContext::allocAllContextBuffers(UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool more;
  SInt32 *descriptor;
  VendorContextBufferHeader *header;
  UInt32 result;
  SInt32 released;
  SInt32 slotIndex;
  UInt8 *pIVar7;
  
  descriptor = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(0x10023,size,GH_page_size);
  result = 0;
  M<SInt32 *>(self + kIOATIR500DVDContext_contextBufferDescriptor) = descriptor;
  if (descriptor != (SInt32 *)0x0) {
    slotIndex = 0;
    header = (VendorContextBufferHeader *)VCALL(*descriptor, 0x1cc)(descriptor);
    M<VendorContextBufferHeader *>(self + kIOATIR500DVDContext_contextBufferHeader) = header;
    this->init_context_buffer_header((VendorContextBufferHeader *)(header),size);
    pIVar7 = self;
    do {
      descriptor = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(0x10023,size,GH_page_size);
      M<SInt32 *>(pIVar7 + 0xcc) = descriptor;
      if (descriptor == (SInt32 *)0x0) {
        if (-1 < slotIndex + -1) {
          released = 0;
          pIVar7 = self + (slotIndex + -1) * 0x18 + 0xcc;
          do {
            released = released + 1;
            VCALL(*M<SInt32 *>(pIVar7), 0x18)(M<SInt32 *>(pIVar7));
            M<UInt32>(pIVar7 + -8) = 0;
            M<UInt32>(pIVar7 + -4) = 0;
            M<UInt32>(pIVar7) = 0;
            M<UInt16>(pIVar7 + 6) = 0;
            M<UInt16>(pIVar7 + 4) = 0;
            M<UInt32>(pIVar7 + 8) = 0;
            M<UInt32>(pIVar7 + 0xc) = 0;
            pIVar7 = pIVar7 + -0x18;
          } while (released != slotIndex);
        }
        VCALL(*M<SInt32 *>(self + kIOATIR500DVDContext_contextBufferDescriptor), 0x18)(M<SInt32 *>(self + kIOATIR500DVDContext_contextBufferDescriptor));
        M<UInt32>(self + kIOATIR500DVDContext_contextBufferHeader) = 0;
        M<UInt32>(self + kIOATIR500DVDContext_contextBuffer) = 0;
        M<UInt32>(self + kIOATIR500DVDContext_contextBufferGartOffset) = 0;
        M<UInt32>(self + kIOATIR500DVDContext_contextBufferDescriptor) = 0;
        M<UInt16>(self + kIOATIR500DVDContext_contextBufferInFlight) = 0;
        M<UInt16>(self + kIOATIR500DVDContext_contextBufferType) = 0;
        M<UInt32>(self + kIOATIR500DVDContext_contextBufferStamp) = 0;
        return 0;
      }
      header = (VendorContextBufferHeader *)VCALL(*descriptor, 0x1cc)(descriptor);
      M<VendorContextBufferHeader *>(pIVar7 + 0xd8) = header;
      pIVar7 = pIVar7 + 0x18;
      this->init_context_buffer_header((VendorContextBufferHeader *)(header),size);
      more = slotIndex != 1;
      slotIndex = slotIndex + 1;
    } while (more);
    result = 1;
  }
  return result;
}
