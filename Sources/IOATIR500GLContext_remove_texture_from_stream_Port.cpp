/*
 * IOATIR500GLContext_remove_texture_from_stream_Port.cpp
 *
 * IOATIR500GLContext::remove_texture_from_stream (real addr 0x71b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x71b0 */
void IOATIR500GLContext::remove_texture_from_stream(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  UInt8 kind;
  UInt32 stamp;
  SInt32 iVar3;
  SInt32 *piVar4;
  
  do {
    stamp = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x50);
    M<UInt32>(M<SInt32>(textureBytes + 0x14) + 8) = stamp;
    kind = textureBytes[0x20];
    if (kind == 0x6) {
      iVar3 = M<SInt32>(textureBytes + 0x54);
      M<UInt32>(M<SInt32>(iVar3 + 0x14) + 8) = stamp;
      M<SInt16>(iVar3 + 0xe) = M<SInt16>(iVar3 + 0xe) + -1;
      return;
    }
    if (kind == 0x0) {
      piVar4 = M<SInt32 *>(textureBytes + 0x50);
      if (piVar4 == (SInt32 *)0x0) {
        return;
      }
      VCALL(*piVar4, 0x5b4)(piVar4,stamp,3);
      VCALL(*piVar4, 0x5bc)(piVar4,3);
      return;
    }
    if (kind != 0x1) {
      if (kind != 0x8) {
        return;
      }
      if (M<SInt32>(textureBytes + 0x48) == 0) {
        M<SInt16>(textureBytes + 0xe) = M<SInt16>(textureBytes + 0xe) + -1;
      }
      M<UInt32>(textureBytes + 0x5c) = stamp;
      return;
    }
    textureBytes = M<UInt8 *>(textureBytes + 0x50);
  } while (textureBytes != (UInt8 *)0x0);
  return;
}
