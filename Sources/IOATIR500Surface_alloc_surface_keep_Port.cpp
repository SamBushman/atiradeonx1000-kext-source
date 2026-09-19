/*
 * IOATIR500Surface_alloc_surface_keep_Port.cpp
 *
 * IOATIR500Surface::alloc_surface_keep (real addr 0x13210, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x13210 */
bool IOATIR500Surface::alloc_surface_keep(IOATIR500Surface *real_param_1, VendorTextureBuffer**param_2, SInt32 param_3, UInt32 param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  UInt8 *pAVar2;
  
  pAVar2 = (UInt8 *)(self + param_4 * 0x78 + 0xa8);
  if ((M<SInt32>(self + param_4 * 0x78 + 0xb8) == 0) || (M<SInt32>(self + param_4 * 0x78 + 0xb0) != 0)
     ) {
    if (M<SInt32>(self + param_4 * 0x78 + 0xcc) != 0) {
      this->free_buffer_backing_store((ATIR500SurfaceBuffer *)(pAVar2));
    }
  }
  else {
    iVar1 = VCALL(M<SInt32>(self), 0x5d0)(self,pAVar2);
    if ((iVar1 == 0) &&
       (iVar1 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0xd50)))->freeToAllocSurfaceVRAM((IOATIR500Surface *)(self),(IOATIR500Surface *)(param_1),(VendorTextureBuffer **)(param_2),param_3,
                           (ATIR500SurfaceBuffer *)(pAVar2)), iVar1 == 0)) {
      return 0;
    }
    if ((3U >> (param_4 & 0x3f) & 1) != 0) {
      M<UInt32>(self + 0xbf8) = M<UInt32>(self + 0xbf8) | 0x10000000;
    }
    if (M<SInt32>(self + param_4 * 0x78 + 0xcc) != 0) {
      this->move_buffer_from_backing_store((ATIR500SurfaceBuffer *)(pAVar2));
    }
  }
  M<UInt32>(self + 0xbf8) =
       (-2 << (param_4 & 0x1f) | 0xfffffffeU >> 0x20 - (param_4 & 0x1f)) & M<UInt32>(self + 0xbf8);
  return 1;
}
