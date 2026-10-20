/*
 * ATIR500GLContext_build_scissor_Port.cpp
 *
 * ATIR500GLContext::build_scissor (real addr 0x27ee0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x27ee0 */
void ATIR500GLContext::build_scissor() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 levelWidth;
  SInt32 formatShiftAdjust;
  UInt8 *colorBuffer;
  UInt32 mipLevel;
  UInt32 scissorHeight;
  UInt32 levelHeight;
  UInt32 formatClass;
  UInt32 formatInfo;
  
  if (M<SInt32>(self + kATIR500GLContext_renderToTexture) == 0) {
    mipLevel = M<UInt32>(self + kIOATIR500GLContext_mipLevel);
    colorBuffer = *(UInt8 **)
              ((UInt32)M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) * 4 + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb70);
  }
  else {
    mipLevel = 0;
    colorBuffer = self + (UInt32)M<UInt16>(self + kATIR500GLContext_currentAttachment) * 0x78 + 0x3c0;
  }
  if (((M<UInt32>(colorBuffer + 0x3c) & 0xf00000) == 0) ||
     (levelWidth = (SInt32)(M<UInt16>(colorBuffer + 0x1c)) / (SInt32)(M<UInt32>(colorBuffer + 0x3c) >> 0x14 & 0xf) >>
              mipLevel, levelWidth == 0)) {
    levelWidth = 1;
  }
  levelHeight = (SInt32)(UInt32)M<UInt16>(colorBuffer + 0x1e) >> mipLevel;
  scissorHeight = 1;
  if (levelHeight != 0) {
    scissorHeight = levelHeight;
  }
  formatInfo = FormatTableLookup_0x0004d2dc((UInt32)(UInt8)colorBuffer[0x3a] * 0x1c);
  formatClass = formatInfo >> 3 & 0x1f;
  if ((formatClass < 3) || ((formatShiftAdjust = 1, 4 < formatClass && (formatShiftAdjust = 2, formatClass != 6)))) {
    formatShiftAdjust = 0;
  }
  M<UInt32>(self + kATIR500GLContext_scissorX) =
       levelWidth << ((formatInfo >> 0xc & 7) - formatShiftAdjust) & 0x3fffU | (scissorHeight & 0x3fff) << 0x10;
  return;
}
