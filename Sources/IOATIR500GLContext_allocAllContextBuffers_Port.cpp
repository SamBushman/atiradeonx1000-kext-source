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

  SInt32 *descriptor;
  VendorContextBufferHeader *header;
  UInt32 result;
  SInt32 bufferIndex;
  bool moreBuffers;
  SInt32 releasedCount;
  UInt8 *entryCursor;
  UInt8 *unwindCursor;
  
  descriptor = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(0x10023,size,GH_page_size);
  result = 0;
  M<SInt32 *>(self + kIOATIR500GLContext_contextBufferDescriptor) = descriptor;
  if (descriptor != (SInt32 *)0x0) {
    bufferIndex = 0;
    header = (VendorContextBufferHeader *)VCALL(*descriptor, 0x1cc)(descriptor);
    M<VendorContextBufferHeader *>(self + kIOATIR500GLContext_contextBufferHeader) = header;
    this->init_context_buffer_header((VendorContextBufferHeader *)(header),size);
    entryCursor = self;
    do {
      descriptor = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x82c) | 0x10023,size,
                                   GH_page_size);
      M<SInt32 *>(entryCursor + 0x114) = descriptor;
      if (descriptor == (SInt32 *)0x0) {
        if (-1 < bufferIndex + -1) {
          releasedCount = 0;
          unwindCursor = self + (bufferIndex + -1) * 0x18 + 0x114;
          do {
            releasedCount = releasedCount + 1;
            VCALL(*M<SInt32 *>(unwindCursor), 0x18)(M<SInt32 *>(unwindCursor));
            M<UInt32>(unwindCursor + -8) = 0;
            M<UInt32>(unwindCursor + -4) = 0;
            M<UInt32>(unwindCursor) = 0;
            M<UInt16>(unwindCursor + 6) = 0;
            M<UInt16>(unwindCursor + 4) = 0;
            M<UInt32>(unwindCursor + 8) = 0;
            M<UInt32>(unwindCursor + 0xc) = 0;
            unwindCursor = unwindCursor + -0x18;
          } while (releasedCount != bufferIndex);
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
      M<VendorContextBufferHeader *>(entryCursor + 0x120) = header;
      entryCursor = entryCursor + 0x18;
      this->init_context_buffer_header((VendorContextBufferHeader *)(header),size);
      moreBuffers = bufferIndex != 0xf;
      bufferIndex = bufferIndex + 1;
    } while (moreBuffers);
    result = 1;
  }
  return result;
}
