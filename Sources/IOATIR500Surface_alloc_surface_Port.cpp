/*
 * IOATIR500Surface_alloc_surface_Port.cpp
 *
 * IOATIR500Surface::alloc_surface (real addr 0x13360, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* PERF NOTE (NOT APPLIED). Estimated cycles rebuilt/stock 1.13-1.14. Cause: loads and stores equal stock; the rebuilt code has 17 more branches and 66 more
 * register-to-register instructions over the sampled seeds (probably early-exit tests compiled as separate compare/branch pairs plus result copies; not traced to a line). Closing it, if that is the cause:
 * fold the early-exit tests into one return path as the shipped code does; a small function, so a few cycles per call. */
/* real addr 0x13360 */
bool IOATIR500Surface::alloc_surface(UInt32 index, bool moveFromBacking) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 allocated;
  UInt32 in_register_00000014;
  UInt8 *surfaceBuffer;
  
  surfaceBuffer = (UInt8 *)(self + index * 0x78 + 0xa8);
  if ((M<SInt32>(self + index * 0x78 + 0xb8) == 0) || (M<SInt32>(self + index * 0x78 + 0xb0) != 0)
     ) {
    if (M<SInt32>(self + index * 0x78 + 0xcc) == 0) goto LAB_00013448;
  }
  else {
    allocated = VCALL(M<SInt32>(self), 0x5d0)(self,surfaceBuffer);
    if ((allocated == 0) &&
       (allocated = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500Surface_accelerator)))->freeToAllocSurfaceVRAM((IOATIR500Surface *)(self),(IOATIR500Surface *)((UInt8 *)0x0),
                           (VendorTextureBuffer **)((UInt8 **)0x0),0,(ATIR500SurfaceBuffer *)(surfaceBuffer)), allocated == 0)) {
      return 0;
    }
    if ((3U >> (index & 0x3f) & 1) != 0) {
      M<UInt32>(self + kIOATIR500Surface_stateBits) = M<UInt32>(self + kIOATIR500Surface_stateBits) | 0x10000000;
    }
    if (M<SInt32>(self + index * 0x78 + 0xcc) == 0) goto LAB_00013448;
    if (((UInt32)moveFromBacking) != 0) {
      this->move_buffer_from_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
      goto LAB_00013448;
    }
  }
  this->free_buffer_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
LAB_00013448:
  M<UInt32>(self + kIOATIR500Surface_stateBits) =
       (-2 << (index & 0x1f) | 0xfffffffeU >> 0x20 - (index & 0x1f)) & M<UInt32>(self + kIOATIR500Surface_stateBits);
  return 1;
}
