/*
 * ATIR500GLContext_compute_zb_bw_cntl_Port.cpp
 *
 * ATIR500GLContext::compute_zb_bw_cntl (real addr 0x26e40, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x26e40 */
UInt32 ATIR500GLContext::compute_zb_bw_cntl(UInt32 requested) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *depthBuffer;
  UInt32 bandwidthBits;
  
  depthBuffer = self + kATIR500GLContext_textureDepthBuffer;
  if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
    depthBuffer = *(UInt8 **)
              ((UInt32)M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
  }
  bandwidthBits = 0;
  if ((depthBuffer[0x34] != 0x0) &&
     ((2 < M<UInt16>(depthBuffer + 0x16) || (bandwidthBits = 4, 2 < (M<UInt32>(depthBuffer + 0x3c) >> 0x14 & 0xf))))
     ) {
    bandwidthBits = 0x1c;
  }
  if ((depthBuffer[0x35] != 0x0) && ((requested & 1) != 0)) {
    bandwidthBits = bandwidthBits | 1;
  }
  return requested & 0xffffffe2 | bandwidthBits;
}
