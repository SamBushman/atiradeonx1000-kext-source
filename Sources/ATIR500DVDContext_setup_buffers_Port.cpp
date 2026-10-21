/*
 * ATIR500DVDContext_setup_buffers_Port.cpp
 *
 * ATIR500DVDContext::setup_buffers (real addr 0x34260, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x34260 */
IOReturn ATIR500DVDContext::setup_buffers(UInt32 top, UInt32 right, UInt32 bottom, UInt32 left, UInt32 controlFlags) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  if ((M<SInt32>(self + kIOATIR500DVDContext_boundSurface) != 0) && (M<char>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x80) != '\0')) {
    M<UInt8>(M<SInt32>(self + kIOATIR500DVDContext_boundSurface) + 0xbed) = 1;
    M<UInt8>(M<SInt32>(self + kIOATIR500DVDContext_boundSurface) + 0xbee) = 1;
    storeHalf(&M<UInt16>(M<SInt32>(self + kIOATIR500DVDContext_boundSurface) + 0x94), top);
    storeHalf(&M<UInt16>(M<SInt32>(self + kIOATIR500DVDContext_boundSurface) + 0x9a), bottom);
    storeHalf(&M<UInt16>(M<SInt32>(self + kIOATIR500DVDContext_boundSurface) + 0x96), left);
    storeHalf(&M<UInt16>(M<SInt32>(self + kIOATIR500DVDContext_boundSurface) + 0x98), right);
    M<UInt32>(self + kIOATIR500DVDContext_surfaceFlagsBitmask) = controlFlags & 0xfffffc00 | 0x20000002;
    return 0;
  }
  return 0xe00002d8;
}
