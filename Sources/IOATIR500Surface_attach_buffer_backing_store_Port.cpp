/*
 * IOATIR500Surface_attach_buffer_backing_store_Port.cpp
 *
 * IOATIR500Surface::attach_buffer_backing_store (real addr 0x12640, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12640 */
UInt32 IOATIR500Surface::attach_buffer_backing_store(ATIR500SurfaceBuffer *buffer, IOMemoryDescriptor*memory, UInt32 pageOffset, UInt32 alignedPitch) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  UInt32 result;
  SInt32 backingStore;
  SInt32 *attachedMemory;
  
  backingStore = VCALL(*M<SInt32 *>(self + kIOATIR500Surface_accelerator), 0x570)(M<SInt32 *>(self + kIOATIR500Surface_accelerator),0xc0);
  result = 0;
  if (backingStore != 0) {
    M<SInt32>(bufferBytes + 0x24) = backingStore;
    M<UInt32>(backingStore + 0x80) = 0;
    M<SInt32>(backingStore + 0x14) = backingStore + 0x80;
    M<UInt32>(backingStore + 0x84) = 0;
    M<UInt32>(M<SInt32>(backingStore + 0x14) + 8) = 0;
    M<UInt32>(M<SInt32>(backingStore + 0x14) + 0xc) = 0;
    M<UInt32>(M<SInt32>(backingStore + 0x14) + 0x10) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x1c) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x1e) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x20) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x22) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x24) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x26) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x28) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x2a) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x2c) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x2e) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x30) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x32) = 0;
    M<UInt8>(M<SInt32>(backingStore + 0x14) + 0x14) = 1;
    M<UInt8>(M<SInt32>(backingStore + 0x14) + 0x15) = 0;
    M<UInt8>(M<SInt32>(backingStore + 0x14) + 0x16) = 0;
    M<UInt8>(M<SInt32>(backingStore + 0x14) + 0x34) = 0;
    M<UInt8>(M<SInt32>(backingStore + 0x14) + 0x35) = 0;
    M<UInt8>(M<SInt32>(backingStore + 0x14) + 0x17) = 0;
    M<UInt16>(M<SInt32>(backingStore + 0x14) + 0x36) = 0;
    M<UInt8 *>(backingStore + 8) = (UInt8 *)memory;
    M<UInt8>(M<SInt32>(backingStore + 0x14) + 0x16) = 5;
    M<UInt8>(backingStore + 0x20) = 5;
    storeHalf(&M<UInt16>(backingStore + 0x50), pageOffset);
    storeHalf(&M<UInt16>(backingStore + 0x52), alignedPitch);
    M<UInt8>(backingStore + 0x58) = 1;
    M<UInt32>(backingStore + 0x54) = M<UInt32>(self + kIOATIR500Surface_stamp);
    if (((self[0xbf7] == 0x0) || (M<SInt32>(bufferBytes + 0x24) == 0)) ||
       (attachedMemory = M<SInt32 *>(M<SInt32>(bufferBytes + 0x24) + 8), attachedMemory == (SInt32 *)0x0)) {
      result = 1;
    }
    else {
      VCALL(*attachedMemory, 0xdc)(attachedMemory,2,0);
      result = 1;
    }
  }
  return result;
}
