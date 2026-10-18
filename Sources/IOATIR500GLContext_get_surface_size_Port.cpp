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

  UInt32 uVar1;
  UInt32 uVar2;
  SInt32 levelsLeft;
  SInt32 surface;
  UInt32 uVar5;
  UInt32 uVar6;
  
  surface = M<SInt32>(self + kIOATIR500GLContext_boundSurface);
  if (surface != 0) {
    levelsLeft = M<SInt32>(self + kIOATIR500GLContext_mipLevel);
    if (M<SInt32>(surface + 0xbd8) == M<SInt32>(surface + 0xbd4)) {
      uVar2 = (UInt32)M<UInt16>(M<SInt32>(surface + 0xb70) + 0x1e);
      uVar1 = (UInt32)M<UInt16>(M<SInt32>(surface + 0xb70) + 0x1c);
      uVar5 = uVar1;
      uVar6 = uVar2;
      if (0 < levelsLeft) {
        do {
          if (1 < uVar1) {
            uVar1 = (SInt32)uVar1 >> 1;
          }
          if (1 < uVar2) {
            uVar2 = (SInt32)uVar2 >> 1;
          }
          levelsLeft = levelsLeft + -1;
          uVar5 = uVar1;
          uVar6 = uVar2;
        } while (levelsLeft != 0);
      }
    }
    else {
      uVar2 = (UInt32)M<SInt16>(surface + 0xbda);
      uVar1 = (UInt32)M<SInt16>(surface + 0xbd4);
      uVar5 = (SInt32)M<SInt16>(surface + 0xbd8);
      uVar6 = (SInt32)M<SInt16>(surface + 0xbd6);
    }
    *outW = uVar5;
    *outH = uVar2;
    *outX = uVar1;
    *outY = uVar6;
    return 0;
  }
  return 0xe00002bc;
}
