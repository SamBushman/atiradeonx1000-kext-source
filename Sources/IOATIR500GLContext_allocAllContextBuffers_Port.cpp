/*
 * IOATIR500GLContext_allocAllContextBuffers_Port.cpp
 *
 * IOATIR500GLContext::allocAllContextBuffers (real addr 0x74d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x74d0 */
bool IOATIR500GLContext::allocAllContextBuffers(UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 *descriptor;
  VendorContextBufferHeader *header;
  UInt32 result;
  SInt32 iVar5;
  SInt32 bufferIndex;
  UInt8 *pIVar7;
  
  descriptor = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(0x10023,size,GH_page_size);
  result = 0;
  M<SInt32 *>(self + kIOATIR500GLContext_contextBufferDescriptor) = descriptor;
  if (descriptor != (SInt32 *)0x0) {
    bufferIndex = 0;
    header = (VendorContextBufferHeader *)VCALL(*descriptor, 0x1cc)(descriptor);
    M<VendorContextBufferHeader *>(self + kIOATIR500GLContext_contextBufferHeader) = header;
    this->init_context_buffer_header((VendorContextBufferHeader *)(header),size);
    pIVar7 = self;
    do {
      descriptor = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x82c) | 0x10023,size,
                                   GH_page_size);
      M<SInt32 *>(pIVar7 + 0x114) = descriptor;
      if (descriptor == (SInt32 *)0x0) {
        if (-1 < bufferIndex + -1) {
          iVar5 = 0;
          pIVar7 = self + (bufferIndex + -1) * 0x18 + 0x114;
          do {
            iVar5 = iVar5 + 1;
            VCALL(*M<SInt32 *>(pIVar7), 0x18)(M<SInt32 *>(pIVar7));
            M<UInt32>(pIVar7 + -8) = 0;
            M<UInt32>(pIVar7 + -4) = 0;
            M<UInt32>(pIVar7) = 0;
            M<UInt16>(pIVar7 + 6) = 0;
            M<UInt16>(pIVar7 + 4) = 0;
            M<UInt32>(pIVar7 + 8) = 0;
            M<UInt32>(pIVar7 + 0xc) = 0;
            pIVar7 = pIVar7 + -0x18;
          } while (iVar5 != bufferIndex);
        }
        VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_contextBufferDescriptor), 0x18)(M<SInt32 *>(self + kIOATIR500GLContext_contextBufferDescriptor));
        M<UInt32>(self + kIOATIR500GLContext_contextBufferHeader) = 0;
        M<UInt32>(self + kIOATIR500GLContext_contextBuffer) = 0;
        M<UInt32>(self + kIOATIR500GLContext_contextBufferGartOffset) = 0;
        M<UInt32>(self + kIOATIR500GLContext_contextBufferDescriptor) = 0;
        M<UInt16>(self + kIOATIR500GLContext_contextBufferInFlight) = 0;
        M<UInt16>(self + kIOATIR500GLContext_contextBufferType) = 0;
        M<UInt32>(self + kIOATIR500GLContext_contextBufferStamp) = 0;
        return 0;
      }
      header = (VendorContextBufferHeader *)VCALL(*descriptor, 0x1cc)(descriptor);
      M<VendorContextBufferHeader *>(pIVar7 + 0x120) = header;
      pIVar7 = pIVar7 + 0x18;
      this->init_context_buffer_header((VendorContextBufferHeader *)(header),size);
      bVar1 = bufferIndex != 0xf;
      bufferIndex = bufferIndex + 1;
    } while (bVar1);
    result = 1;
  }
  return result;
}
