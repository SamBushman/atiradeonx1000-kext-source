/*
 * IOATIR500Accelerator_freeCommandBuffer_Port.cpp
 *
 * IOATIR500Accelerator::freeCommandBuffer (real addr 0x1f10, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1f10 */
void IOATIR500Accelerator::freeCommandBuffer(VendorCommandBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  if (M<SInt32>(bufferBytes + 4) != 0) {
    VCALL(M<SInt32>(self), 0x54c)(self,M<UInt32>(bufferBytes + 0x10));
    VCALL(M<SInt32>(self), 0x5ac)(self,bufferBytes);
  }
  VCALL(*M<SInt32 *>(bufferBytes + 8), 0x18)(M<SInt32 *>(bufferBytes + 8));
  M<UInt16>(bufferBytes + 0xc) = 1;
  M<UInt16>(bufferBytes + 0xe) = 0;
  M<UInt32>(bufferBytes + 0x18) = 0;
  M<UInt32>(bufferBytes) = 0;
  M<UInt32>(bufferBytes + 4) = 0;
  M<UInt32>(bufferBytes + 8) = 0;
  M<UInt32>(bufferBytes + 0x10) = 0;
  M<UInt32>(bufferBytes + 0x14) = 0;
  return;
}
