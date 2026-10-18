/*
 * IOATIR500Surface_dealloc_surface_Port.cpp
 *
 * IOATIR500Surface::dealloc_surface (real addr 0x12580, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12580 */
UInt32 IOATIR500Surface::dealloc_surface(UInt32 surfaceIndex) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 listNode;
  
  if (M<SInt32>(self + surfaceIndex * 0x78 + 0xb0) != 0) {
    if ((3 >> (surfaceIndex & 0x3f) & 1U) != 0) {
      for (listNode = M<SInt32>(self + kIOATIR500Surface_backingStoreList); listNode != 0; listNode = M<SInt32>(listNode + 0x54)) {
        M<UInt8>(M<SInt32>(listNode + 0x14) + 0x14) = 1;
      }
    }
    ((ATIR500Memory *)(M<UInt8 *>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x7c)))->dealloc((GLKMemoryElement *)((UInt8 *)(self + surfaceIndex * 0x78 + 0xa8)));
  }
  M<UInt32>(self + kIOATIR500Surface_stateBits) = 1 << (surfaceIndex & 0x3f) | M<UInt32>(self + kIOATIR500Surface_stateBits);
  return 1;
}
