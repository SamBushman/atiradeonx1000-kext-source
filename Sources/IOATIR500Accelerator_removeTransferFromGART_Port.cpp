/*
 * IOATIR500Accelerator_removeTransferFromGART_Port.cpp
 *
 * IOATIR500Accelerator::removeTransferFromGART (real addr 0x34f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x34f0 */
void IOATIR500Accelerator::removeTransferFromGART(VendorTransferBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  SInt32 prevNode;
  SInt32 nextNode;
  
  if (bufferBytes != (UInt8 *)0x0) {
    if (M<SInt16>(bufferBytes + 0xc) == 4) {
      prevNode = M<SInt32>(bufferBytes + 0x34);
      M<UInt32>(prevNode + 0x38) = M<UInt32>(bufferBytes + 0x38);
      nextNode = M<SInt32>(bufferBytes + 0x38);
      M<UInt8 *>(bufferBytes + 0x38) = bufferBytes;
      M<SInt32>(nextNode + 0x34) = prevNode;
      M<UInt8 *>(bufferBytes + 0x34) = bufferBytes;
    }
    VCALL(M<SInt32>(self), 0x5a4)
              (self,M<UInt32>(bufferBytes + 8),M<UInt32>(bufferBytes + 4));
    M<UInt32>(bufferBytes + 4) = 0;
  }
  return;
}
