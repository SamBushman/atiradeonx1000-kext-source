/*
 * IOATIR500DVDContext_freeAllContextBuffers_Port.cpp
 *
 * IOATIR500DVDContext::freeAllContextBuffers (real addr 0xe270, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0xe270 */
void IOATIR500DVDContext::freeAllContextBuffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool more;
  SInt32 slotIndex;
  UInt8 *slot;
  SInt32 *accel;
  UInt8 *slotBase;
  SInt32 oldWaitCounter;
  SInt32 counterAdvance;
  
  slot = self + kIOATIR500DVDContext_contextBufferRing;
  slotIndex = 0;
  accel = M<SInt32 *>(self + kIOATIR500DVDContext_accelerator);
  oldWaitCounter = accel[0x1e1];
  counterAdvance = VCALL(*accel, 0x54c)
                    (accel,M<UInt32>(self + M<SInt32>(self + kIOATIR500DVDContext_contextBufferRingIndex) * 0x18 + 0xd4));
  accel[0x1e1] = oldWaitCounter + counterAdvance;
  slotBase = self;
  do {
    if (M<SInt32>(slotBase + 200) != 0) {
      VCALL(*M<SInt32 *>(self + kIOATIR500DVDContext_accelerator), 0x5ac)(M<SInt32 *>(self + kIOATIR500DVDContext_accelerator),slot);
    }
    slot = slot + 0x18;
    VCALL(*M<SInt32 *>(slotBase + 0xcc), 0x18)(M<SInt32 *>(slotBase + 0xcc));
    more = slotIndex != 1;
    M<UInt32>(slotBase + 0xc4) = 0;
    M<UInt32>(slotBase + 200) = 0;
    M<UInt32>(slotBase + 0xcc) = 0;
    M<UInt16>(slotBase + 0xd2) = 0;
    M<UInt16>(slotBase + 0xd0) = 0;
    M<UInt32>(slotBase + 0xd4) = 0;
    M<UInt32>(slotBase + 0xd8) = 0;
    slotIndex = slotIndex + 1;
    slotBase = slotBase + 0x18;
  } while (more);
  VCALL(*M<SInt32 *>(self + kIOATIR500DVDContext_contextBufferDescriptor), 0x18)(M<SInt32 *>(self + kIOATIR500DVDContext_contextBufferDescriptor));
  M<UInt16>(self + kIOATIR500DVDContext_contextBufferInFlight) = 0;
  M<UInt16>(self + kIOATIR500DVDContext_contextBufferType) = 0;
  M<UInt32>(self + kIOATIR500DVDContext_contextBufferHeader) = 0;
  M<UInt32>(self + kIOATIR500DVDContext_contextBuffer) = 0;
  M<UInt32>(self + kIOATIR500DVDContext_contextBufferGartOffset) = 0;
  M<UInt32>(self + kIOATIR500DVDContext_contextBufferDescriptor) = 0;
  M<UInt32>(self + kIOATIR500DVDContext_contextBufferStamp) = 0;
  return;
}
