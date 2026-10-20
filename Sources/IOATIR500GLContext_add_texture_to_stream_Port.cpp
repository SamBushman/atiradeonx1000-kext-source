/*
 * IOATIR500GLContext_add_texture_to_stream_Port.cpp
 *
 * IOATIR500GLContext::add_texture_to_stream (real addr 0x72c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOGetTime(...) asm("_IOGetTime");


/* real addr 0x72c0 */
void IOATIR500GLContext::add_texture_to_stream(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  UInt8 kind;
  UInt8 *source;
  int linkedTexture;
  int textureHeader;
  int nextNode;
  int *backingDescriptor;
  
  kind = textureBytes[0x20];
  if (kind == 0x6) {
    linkedTexture = M<int>(textureBytes + 0x54);
    textureHeader = M<int>(textureBytes + 0x14);
    M<SInt16>(linkedTexture + 0xe) = M<SInt16>(linkedTexture + 0xe) + 1;
    M<UInt8>(textureHeader + 0x14) = M<UInt8>(textureHeader + 0x14) | M<UInt8>(M<int>(linkedTexture + 0x14) + 0x14);
    if (M<int>(linkedTexture + 4) != 0) {
      GH_IOGetTime(linkedTexture + 0x2c);
      nextNode = M<int>(linkedTexture + 0x34);
      M<UInt32>(nextNode + 0x38) = M<UInt32>(linkedTexture + 0x38);
      M<int>(M<int>(linkedTexture + 0x38) + 0x34) = nextNode;
      M<UInt32>(linkedTexture + 0x34) = M<UInt32>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x6d0);
      M<int>(linkedTexture + 0x38) = M<int>(self + kIOATIR500GLContext_accelerator) + 0x69c;
      M<int>(M<int>(self + kIOATIR500GLContext_accelerator) + 0x6d0) = linkedTexture;
      M<int>(M<int>(linkedTexture + 0x34) + 0x38) = linkedTexture;
    }
  }
  else if (kind == 0x0) {
    backingDescriptor = M<int *>(textureBytes + 0x50);
    if (backingDescriptor != (int *)0x0) {
      VCALL(*backingDescriptor, 0x5b8)(backingDescriptor,3);
    }
  }
  else if (kind == 0x1) {
    source = M<UInt8 *>(textureBytes + 0x50);
    if (source != (UInt8 *)0x0) {
      this->add_texture_to_stream((VendorTextureBuffer *)(source));
      M<UInt8>(M<int>(textureBytes + 0x14) + 0x14) =
           M<UInt8>(M<int>(textureBytes + 0x14) + 0x14) | M<UInt8>(M<int>(source + 0x14) + 0x14);
    }
  }
  else if ((kind == 0x8) && (M<int>(textureBytes + 0x48) == 0)) {
    M<SInt16>(textureBytes + 0xe) = M<SInt16>(textureBytes + 0xe) + 1;
  }
  return;
}
