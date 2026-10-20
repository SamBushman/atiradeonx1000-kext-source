/*
 * IOATIR500GLContext_freeAllContextBuffers_Port.cpp
 *
 * IOATIR500GLContext::freeAllContextBuffers (real addr 0x7000, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x7000 */
void IOATIR500GLContext::freeAllContextBuffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 bufferIndex;
  SInt32 *accel;
  UInt8 *buffer;
  bool moreBuffers;
  SInt32 waited;
  SInt32 waitTotal;
  UInt8 *entryCursor;
  
  buffer = self + kIOATIR500GLContext_contextBufferRing;
  bufferIndex = 0;
  accel = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
  waitTotal = accel[0x1e0];
  waited = VCALL(*accel, 0x54c)
                    (accel,M<UInt32>(self + M<SInt32>(self + kIOATIR500GLContext_contextBufferRingIndex) * 0x18 + 0x11c));
  accel[0x1e0] = waitTotal + waited;
  entryCursor = self;
  do {
    if (M<SInt32>(entryCursor + 0x110) != 0) {
      VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x5ac)(M<SInt32 *>(self + kIOATIR500GLContext_accelerator),buffer);
    }
    buffer = buffer + 0x18;
    VCALL(*M<SInt32 *>(entryCursor + 0x114), 0x18)(M<SInt32 *>(entryCursor + 0x114));
    moreBuffers = bufferIndex != 0xf;
    M<UInt32>(entryCursor + 0x10c) = 0;
    M<UInt32>(entryCursor + 0x110) = 0;
    M<UInt32>(entryCursor + 0x114) = 0;
    M<UInt16>(entryCursor + 0x11a) = 0;
    M<UInt16>(entryCursor + 0x118) = 0;
    M<UInt32>(entryCursor + 0x11c) = 0;
    M<UInt32>(entryCursor + 0x120) = 0;
    bufferIndex = bufferIndex + 1;
    entryCursor = entryCursor + 0x18;
  } while (moreBuffers);
  VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_contextBufferDescriptor), 0x18)(M<SInt32 *>(self + kIOATIR500GLContext_contextBufferDescriptor));
  M<UInt16>(self + kIOATIR500GLContext_contextBufferInFlight) = 0;
  M<UInt16>(self + kIOATIR500GLContext_contextBufferType) = 0;
  M<UInt32>(self + kIOATIR500GLContext_contextBufferHeader) = 0;
  M<UInt32>(self + kIOATIR500GLContext_contextBuffer) = 0;
  M<UInt32>(self + kIOATIR500GLContext_contextBufferGartOffset) = 0;
  M<UInt32>(self + kIOATIR500GLContext_contextBufferDescriptor) = 0;
  M<UInt32>(self + kIOATIR500GLContext_contextBufferStamp) = 0;
  return;
}
