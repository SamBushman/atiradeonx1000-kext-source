/*
 * IOATIR500Shared_free_Port.cpp
 *
 * IOATIR500Shared::free (real addr 0x184d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFree(...) asm("_IOFree");


/* real addr 0x184d0 */
void IOATIR500Shared::free() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 VVar1;
  SInt32 *chunk;
  UInt8 *texture;
  SInt32 iVar4;
  UInt8 *accel;
  SInt32 *nextChunk;
  UInt8 *nextTexture;
  
  texture = M<UInt8 *>(self + kIOATIR500Shared_textureListHead);
  iVar4 = 0;
  if (texture != (UInt8 *)0x0) {
    do {
      if (texture[0x20] == 0x4) {
        nextTexture = M<UInt8 *>(texture + 0x3c);
      }
      else {
        nextTexture = M<UInt8 *>(texture + 0x3c);
        if (nextTexture != (UInt8 *)0x0) {
          VVar1 = nextTexture[0x20];
          while ((VVar1 == 0x4 &&
                 (nextTexture = M<UInt8 *>(nextTexture + 0x3c),
                 nextTexture != (UInt8 *)0x0))) {
            VVar1 = nextTexture[0x20];
          }
        }
        M<UInt32>(M<SInt32>(texture + 0x14) + 0x10) =
             (UInt32)M<UInt16>(M<SInt32>(texture + 0x14) + 0x12);
        this->delete_texture((VendorTextureBuffer *)(texture));
      }
      texture = nextTexture;
    } while (nextTexture != (UInt8 *)0x0);
    iVar4 = M<SInt32>(self + kIOATIR500Shared_textureListHead);
  }
  while (iVar4 != 0) {
    M<UInt32>(M<SInt32>(iVar4 + 0x14) + 0x10) = (UInt32)M<UInt16>(M<SInt32>(iVar4 + 0x14) + 0x12);
    this->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(self + kIOATIR500Shared_textureListHead)));
    iVar4 = M<SInt32>(self + kIOATIR500Shared_textureListHead);
  }
  accel = M<UInt8 *>(self + kIOATIR500Shared_accelerator);
  if (self == M<UInt8 *>(accel + 0x6c)) {
    M<UInt32>(accel + 0x6c) = 0;
    M<UInt32>(M<SInt32>(self + kIOATIR500Shared_accelerator) + 0x70) = 0;
    accel = M<UInt8 *>(self + kIOATIR500Shared_accelerator);
  }
  ((IOATIR500Accelerator *)(accel))->freeOrphanTexture(true);
  chunk = (SInt32 *)M<SInt32>(self + kIOATIR500Shared_chunkList);
  while (chunk != (SInt32 *)0x0) {
    nextChunk = (SInt32 *)*chunk;
    VCALL(*(SInt32 *)chunk[3], 0x18)(chunk[3]);
    VCALL(*(SInt32 *)chunk[2], 0x18)(chunk[2]);
    VCALL(*(SInt32 *)chunk[1], 0x18)(chunk[1]);
    GH_IOFree(chunk,0x1c);
    iVar4 = M<SInt32>(self + kIOATIR500Shared_accelerator);
    chunk = nextChunk;
    if (iVar4 != 0) {
      M<SInt32>(iVar4 + 0x808) = M<SInt32>(iVar4 + 0x808) + -0x1c;
    }
  }
  this->free_handles();
  OSObject::free();
  return;
}
