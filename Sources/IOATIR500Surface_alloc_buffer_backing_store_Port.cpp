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
bool IOATIR500Surface::alloc_buffer_backing_store(ATIR500SurfaceBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 *pIVar1;
  SInt32 iVar2;
  
  pIVar1 = (UInt8 *)
           GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(M<UInt32>(M<SInt32>(self + 0xd50) + 0x220),0x10063,
                        (GH_page_size + M<SInt32>(param_1 + 0x10)) - 1U & -GH_page_size);
  if (pIVar1 != (UInt8 *)0x0) {
    self[0xbf7] = 0x1;
    this->attach_buffer_backing_store((ATIR500SurfaceBuffer *)(param_1),(IOMemoryDescriptor *)(pIVar1),0,(UInt32)M<UInt16>(param_1 + 0x18));
    iVar2 = M<SInt32>(param_1 + 0x24);
    M<UInt8>(iVar2 + 0x59) = 0;
    M<SInt32>(iVar2 + 0x54) = M<SInt32>(self + 0x7c) + -1;
  }
  else {
    VCALL(M<SInt32>(self), 0x5cc)(self,((SInt32)param_1 - (SInt32)(self + 0xa8) >> 3) * -0x11111111)
    ;
  }
  return pIVar1 != (UInt8 *)0x0;
}
