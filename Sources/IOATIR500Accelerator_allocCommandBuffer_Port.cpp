/*
 * IOATIR500Accelerator_allocCommandBuffer_Port.cpp
 *
 * IOATIR500Accelerator::allocCommandBuffer (real addr 0x23e0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x23e0 */
bool IOATIR500Accelerator::allocCommandBuffer(VendorCommandBuffer *outBuffer, UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *outBufferBytes = reinterpret_cast<UInt8 *>(outBuffer);

  SInt32 *backing;
  VendorCommandBufferHeader *header;
  
  backing = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(M<UInt32>(self + 0x82c) | 0x10022,size,GH_page_size);
  M<SInt32 *>(outBufferBytes + 8) = backing;
  if (backing != (SInt32 *)0x0) {
    M<UInt32>(outBufferBytes + 0x18) = size;
    header = (VendorCommandBufferHeader *)VCALL(*backing, 0x1cc)(backing);
    M<VendorCommandBufferHeader *>(outBufferBytes + 0x14) = header;
    this->init_command_buffer_header((VendorCommandBufferHeader *)(header),size);
  }
  return backing != (SInt32 *)0x0;
}
