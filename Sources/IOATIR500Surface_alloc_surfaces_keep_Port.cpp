/*
 * IOATIR500Surface_alloc_surfaces_keep_Port.cpp
 *
 * IOATIR500Surface::alloc_surfaces_keep (real addr 0x124b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x124b0 */
UInt32 IOATIR500Surface::alloc_surfaces_keep(IOATIR500Surface *excludeSurface, VendorTextureBuffer**excludeList, SInt32 excludeCount, UInt32 mask) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *excludeSurfaceBytes = reinterpret_cast<UInt8 *>(excludeSurface);

  bool isLast;
  UInt32 stateBits;
  UInt32 kept;
  UInt32 allKept;
  UInt32 index;
  
  index = 0;
  allKept = 1;
  stateBits = M<UInt32>(self + kIOATIR500Surface_stateBits);
  while( true ) {
    if ((mask & stateBits & 1 << (index & 0x3f)) != 0) {
      kept = VCALL(M<SInt32>(self), 0x5f8)(self,excludeSurfaceBytes,excludeList,excludeCount,index);
      allKept = allKept & kept;
    }
    isLast = index == 0x16;
    index = index + 1;
    if (isLast) break;
    if (allKept == 0) {
      return 2;
    }
  }
  if (allKept == 0) {
    return 2;
  }
  return 0;
}
