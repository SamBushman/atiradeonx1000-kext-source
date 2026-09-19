/*
 * IOATIR500Accelerator_allocDataBufferBacking_Port.cpp
 *
 * IOATIR500Accelerator::allocDataBufferBacking (real addr 0x30d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x30d0 */
bool IOATIR500Accelerator::allocDataBufferBacking(VendorTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  
  iVar1 = GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(0,0x10422,M<UInt32>(param_1 + 0x50),GH_page_size);
  M<SInt32>(param_1 + 8) = iVar1;
  return iVar1 != 0;
}
