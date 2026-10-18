/*
 * IOATIR500Surface_alloc_buffer_backing_store_Port.cpp
 *
 * IOATIR500Surface::alloc_buffer_backing_store (real addr 0x12900, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(...) asm("__ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj");


/* real addr 0x12900 */
bool IOATIR500Surface::alloc_buffer_backing_store(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  UInt8 *memory;
  SInt32 backingStore;
  
  memory = (UInt8 *)
           GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x220),0x10063,
                        (GH_page_size + M<SInt32>(bufferBytes + 0x10)) - 1U & -GH_page_size,
                        GH_page_size);   /* #175: 4th argument (alignment) - stock leaves r6 = _page_size live from the capacity computation (0x12944: r6 never rewritten); Ghidra dropped it */
  if (memory != (UInt8 *)0x0) {
    self[0xbf7] = 0x1;
    this->attach_buffer_backing_store((ATIR500SurfaceBuffer *)(bufferBytes),(IOMemoryDescriptor *)(memory),0,(UInt32)M<UInt16>(bufferBytes + 0x18));
    backingStore = M<SInt32>(bufferBytes + 0x24);
    M<UInt8>(backingStore + 0x59) = 0;
    M<SInt32>(backingStore + 0x54) = M<SInt32>(self + kIOATIR500Surface_stamp) + -1;
  }
  else {
    VCALL(M<SInt32>(self), 0x5cc)(self,((SInt32)bufferBytes - (SInt32)(self + kIOATIR500Surface_buffers) >> 3) * -0x11111111)
    ;
  }
  return memory != (UInt8 *)0x0;
}
