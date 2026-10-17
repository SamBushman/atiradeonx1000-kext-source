/*
 * IOATIR500Shared_free_texvert_Port.cpp
 *
 * IOATIR500Shared::free_texvert (real addr 0x18710, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x18710 */
void IOATIR500Shared::free_texvert(IOATIR500Accelerator *accel, IOTextureBuffer *texture) {
    UInt8 *accelBytes = reinterpret_cast<UInt8 *>(accel);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  SInt32 hasBacking;
  UInt32 freeSize;
  SInt32 nextNode;
  UInt8 bufferType;
  SInt32 prevNode;
  
  prevNode = M<SInt32>(textureBytes + 0x24);
  hasBacking = M<SInt32>(textureBytes + 4);
  M<UInt32>(prevNode + 0x28) = M<UInt32>(textureBytes + 0x28);
  nextNode = M<SInt32>(textureBytes + 0x28);
  M<UInt8 *>(textureBytes + 0x28) = textureBytes;
  M<SInt32>(nextNode + 0x24) = prevNode;
  M<UInt8 *>(textureBytes + 0x24) = textureBytes;
  if (hasBacking != 0) {
    /* #155 FIX (2026-10-11): this vtable+0x5ac call is missing its second argument - confirmed via
     * stock's own disassembly (real addr 0x18710+0x44: r4/textureBytes stays live, untouched, from this
     * function's entry all the way to the bctrl, so stock genuinely passes (accelBytes, textureBytes)).
     * Confirmed independently by the sibling call site at the same vtable slot in
     * IOATIR500Accelerator_free_gart_wirings_Port.cpp (`VCALL(self,0x5ac)(self,pIVar6)`, 2 args).
     * Same dropped-argument defect class as removeEventSource()/IOLockFree earlier in this issue.
     * This runs on the garbage_collector interrupt path implicated in #155's teardown hang - live-
     * tested fixing this alone, does NOT resolve the hang (the hang persisted identically), but
     * it's a real, independently-verified bug worth keeping regardless. */
    VCALL(M<SInt32>(accelBytes), 0x5ac)(accelBytes, textureBytes);
  }
  if (M<UInt8 *>(textureBytes + 0x1c) != (UInt8 *)0x0) {
    ((IOATIR500Shared *)(M<UInt8 *>(textureBytes + 0x1c)))->free_buf_handle(textureBytes,*M<UInt32 *>(textureBytes + 0x14));   /* record, handle - the owner is `this` of the call */
  }
  bufferType = textureBytes[0x20];
  if (((UInt32)bufferType - 3 < 5) && (M<SInt32 *>(textureBytes + 8) != (SInt32 *)0x0)) {
    VCALL(*M<SInt32 *>(textureBytes + 8), 0x18)(M<SInt32 *>(textureBytes + 8));
    bufferType = textureBytes[0x20];
    M<UInt32>(textureBytes + 8) = 0;
  }
  freeSize = 0xc0;
  if (bufferType != 0x5) {
    freeSize = 0x80;
  }
  VCALL(M<SInt32>(accelBytes), 0x574)(accelBytes,textureBytes,freeSize);
  return;
}
