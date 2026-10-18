/*
 * ATIR500GLContext_compute_sc_hyperz_en_Port.cpp
 *
 * ATIR500GLContext::compute_sc_hyperz_en (real addr 0x26df0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x26df0 */
UInt32 ATIR500GLContext::compute_sc_hyperz_en(UInt32 requested) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 enableBit;
  UInt8 *depthBuffer;
  
  depthBuffer = self + kATIR500GLContext_textureDepthBuffer;
  if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
    depthBuffer = *(UInt8 **)
              ((UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
  }
  if ((depthBuffer[0x35] == 0x0) || (enableBit = 1, (requested & 1) == 0)) {
    enableBit = 0;
  }
  return requested & 0xfffffffe | enableBit;
}
