/*
 * ATIR500GLContext_GetQueryOffset_Port.cpp
 *
 * ATIR500GLContext::GetQueryOffset (real addr 0x26f60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x26f60 */
UInt32 ATIR500GLContext::GetQueryOffset(VendorTextureBuffer *buffer, UInt32 queryIndex, UInt32 selector) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  SInt32 queryOffset;
  
  if (selector == 0) {
    queryOffset = queryIndex * 0x20 + 0x210;
  }
  else {
    queryOffset = queryIndex * 0x20 + 0x10;
  }
  return *(SInt32 *)(bufferBytes + 0x50) + M<SInt32>(M<SInt32>(bufferBytes + 0x54) + 4) + queryOffset +
         M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x8a4);
}
