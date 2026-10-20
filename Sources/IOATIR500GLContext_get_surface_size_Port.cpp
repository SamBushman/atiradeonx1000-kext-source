/*
 * IOATIR500GLContext_get_surface_size_Port.cpp
 *
 * IOATIR500GLContext::get_surface_size (real addr 0x7ca0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x7ca0 */
IOReturn IOATIR500GLContext::get_surface_size(SInt32*outW, SInt32*outH, SInt32*outX, SInt32*outY) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 levelsLeft;
  SInt32 surface;
  UInt32 outXValue;
  UInt32 outHValue;
  UInt32 outWValue;
  UInt32 outYValue;
  
  surface = M<SInt32>(self + kIOATIR500GLContext_boundSurface);
  if (surface != 0) {
    levelsLeft = M<SInt32>(self + kIOATIR500GLContext_mipLevel);
    if (M<SInt32>(surface + kIOATIR500Surface_committedWidth) == M<SInt32>(surface + kIOATIR500Surface_width)) {
      outHValue = (UInt32)M<UInt16>(M<SInt32>(surface + kIOATIR500Surface_attachmentBuffers) + 0x1e);
      outXValue = (UInt32)M<UInt16>(M<SInt32>(surface + kIOATIR500Surface_attachmentBuffers) + 0x1c);
      outWValue = outXValue;
      outYValue = outHValue;
      if (0 < levelsLeft) {
        do {
          if (1 < outXValue) {
            outXValue = (SInt32)outXValue >> 1;
          }
          if (1 < outHValue) {
            outHValue = (SInt32)outHValue >> 1;
          }
          levelsLeft = levelsLeft + -1;
          outWValue = outXValue;
          outYValue = outHValue;
        } while (levelsLeft != 0);
      }
    }
    else {
      outHValue = (UInt32)M<SInt16>(surface + kIOATIR500Surface_committedHeight);
      outXValue = (UInt32)M<SInt16>(surface + kIOATIR500Surface_width);
      outWValue = (SInt32)M<SInt16>(surface + kIOATIR500Surface_committedWidth);
      outYValue = (SInt32)M<SInt16>(surface + kIOATIR500Surface_height);
    }
    *outW = outWValue;
    *outH = outHValue;
    *outX = outXValue;
    *outY = outYValue;
    return 0;
  }
  return 0xe00002bc;
}
