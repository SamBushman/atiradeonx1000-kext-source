/*
 * ATIR500GLContext_GetTextureOffset_Port.cpp
 *
 * ATIR500GLContext::GetTextureOffset (real addr 0x280c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x280c0 */
UInt32 ATIR500GLContext::GetTextureOffset(VendorTextureBuffer *texture, bool forWrite) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  UInt8 type;
  SInt32 offset;
  UInt32 in_register_00000014;
  UInt8 *surface;
  UInt32 bufferMask [8];
  
  type = textureBytes[0x20];
  if ((type == 0x3) || (type == 0x7)) {
    offset = 0;
    if (((UInt32)forWrite) == 0) {
      offset = M<SInt32>(textureBytes + 0x60);
    }
    offset = offset + M<SInt32>(textureBytes + 0x48);
  }
  else {
    if (type == 0x6) {
      if (M<SInt32>(M<SInt32>(textureBytes + 0x54) + 4) != 0) {
        offset = 0;
        if (((UInt32)forWrite) == 0) {
          offset = M<SInt32>(textureBytes + 0x60);
        }
        return *(SInt32 *)(M<SInt32>(textureBytes + 0x54) + 4) +
               offset + M<SInt32>(textureBytes + 0x50) + M<SInt32>(M<SInt32>(self + 200) + 0x8a4);
      }
    }
    else if ((type == 0x0) &&
            (surface = M<UInt8 *>(textureBytes + 0x50), surface != (UInt8 *)0x0))
    {
      offset = ((IOATIR500Surface *)(surface))->surface_buffer_idx_mask(M<UInt32>(textureBytes + 0x58),(UInt32 *)(bufferMask));
      offset = M<SInt32>(surface + offset * 4 + 0xb70);
      return (UInt32)M<UInt16>(offset + 0x20) * M<SInt32>(M<SInt32>(textureBytes + 0x60) * 4 + offset + 0x40)
             + M<SInt32>(offset + 8);
    }
    offset = 0;
  }
  return offset;
}
