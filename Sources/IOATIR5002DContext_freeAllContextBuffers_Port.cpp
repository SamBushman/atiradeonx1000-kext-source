/*
 * IOATIR5002DContext_freeAllContextBuffers_Port.cpp
 *
 * IOATIR5002DContext::freeAllContextBuffers (real addr 0xb6c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0xb6c0 */
void IOATIR5002DContext::freeAllContextBuffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool more;
  SInt32 waited;
  SInt32 bufferIndex;
  UInt8 *buffer;
  SInt32 *accel;
  SInt32 counterBefore;
  UInt8 *entry;
  
  buffer = self + kIOATIR5002DContext_contextBufferRing;
  bufferIndex = 0;
  accel = M<SInt32 *>(self + kIOATIR5002DContext_accelerator);
  counterBefore = accel[0x1df];
  waited = VCALL(*accel, 0x54c)
                    (accel,M<UInt32>(self + M<SInt32>(self + kIOATIR5002DContext_contextBufferRingIndex) * 0x18 + 0xdc));
  accel[0x1df] = counterBefore + waited;
  entry = self;
  do {
    if (M<SInt32>(entry + 0xd0) != 0) {
      VCALL(*M<SInt32 *>(self + kIOATIR5002DContext_accelerator), 0x5ac)(M<SInt32 *>(self + kIOATIR5002DContext_accelerator),buffer);
    }
    buffer = buffer + 0x18;
    VCALL(*M<SInt32 *>(entry + 0xd4), 0x18)(M<SInt32 *>(entry + 0xd4));
    more = bufferIndex != 1;
    M<UInt32>(entry + 0xcc) = 0;
    M<UInt32>(entry + 0xd0) = 0;
    M<UInt32>(entry + 0xd4) = 0;
    M<UInt16>(entry + 0xda) = 0;
    M<UInt16>(entry + 0xd8) = 0;
    M<UInt32>(entry + 0xdc) = 0;
    M<UInt32>(entry + 0xe0) = 0;
    bufferIndex = bufferIndex + 1;
    entry = entry + 0x18;
  } while (more);
  VCALL(*M<SInt32 *>(self + kIOATIR5002DContext_contextBufferDescriptor), 0x18)(M<SInt32 *>(self + kIOATIR5002DContext_contextBufferDescriptor));
  M<UInt16>(self + kIOATIR5002DContext_contextBufferInFlight) = 0;
  M<UInt16>(self + kIOATIR5002DContext_contextBufferType) = 0;
  M<UInt32>(self + kIOATIR5002DContext_contextBufferHeader) = 0;
  M<UInt32>(self + kIOATIR5002DContext_contextBuffer) = 0;
  M<UInt32>(self + kIOATIR5002DContext_contextBufferGartOffset) = 0;
  M<UInt32>(self + kIOATIR5002DContext_contextBufferDescriptor) = 0;
  M<UInt32>(self + kIOATIR5002DContext_contextBufferStamp) = 0;
  return;
}
