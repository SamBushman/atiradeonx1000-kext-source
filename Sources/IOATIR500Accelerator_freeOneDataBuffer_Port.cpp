/*
 * IOATIR500Accelerator_freeOneDataBuffer_Port.cpp
 *
 * IOATIR500Accelerator::freeOneDataBuffer (real addr 0x32d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x32d0 */
void IOATIR500Accelerator::freeOneDataBuffer(VendorTextureBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  SInt32 nextNode;
  SInt32 *backing;
  SInt32 prevNode;
  
  if (M<SInt32>(bufferBytes + 0x48) != 0) {
    /* #171: stock 0x32fc: r4 = the buffer (incoming), deallocate_texture(VendorTextureBuffer*) */
    VCALL(M<SInt32>(self), 0x524)(self,bufferBytes);
    prevNode = M<SInt32>(bufferBytes + 0x24);
    M<UInt32>(prevNode + 0x28) = M<UInt32>(bufferBytes + 0x28);
    nextNode = M<SInt32>(bufferBytes + 0x28);
    M<UInt8 *>(bufferBytes + 0x28) = bufferBytes;
    M<SInt32>(nextNode + 0x24) = prevNode;
    M<UInt8 *>(bufferBytes + 0x24) = bufferBytes;
  }
  if (M<SInt32 *>(bufferBytes + 0x10) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(bufferBytes + 0x10), 0x18)(M<SInt32 *>(bufferBytes + 0x10));
    M<UInt32>(bufferBytes + 0x10) = 0;
  }
  backing = M<SInt32 *>(bufferBytes + 8);
  if (backing != (SInt32 *)0x0) {
    if (M<SInt32>(bufferBytes + 4) != 0) {
      VCALL(M<SInt32>(self), 0x54c)(self,M<UInt32>(bufferBytes + 0x5c));
      VCALL(M<SInt32>(self), 0x5ac)(self,bufferBytes);
      backing = M<SInt32 *>(bufferBytes + 8);
    }
    VCALL(*backing, 0x18)(backing);
  }
  VCALL(M<SInt32>(self), 0x574)(self,bufferBytes,0xc0);
  M<SInt32>(self + 0x750) = M<SInt32>(self + 0x750) + -1;
  return;
}
