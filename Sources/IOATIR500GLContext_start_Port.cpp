/*
 * IOATIR500GLContext_start_Port.cpp
 *
 * IOATIR500GLContext::start (real addr 0x7690, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
/* placement new for the hand-made allocation of IOATIR500Shared (see ATIRadeonX1000_ContextFactories.cpp) */
inline void *operator new(size_t, void *where) { return where; }

extern const VendorExternalMethod kGLRegularMethods[20] asm("__ZZN18IOATIR500GLContext5startEP9IOServiceE11methodDescs");   /* IOATIR500GLContext_ExternalMethods.cpp */

extern "C" UInt32 GH_ZN8OSObjectnwEm(...) asm("__ZN8OSObjectnwEm");


/* real addr 0x7690 */
bool IOATIR500GLContext::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

  UInt8 *shared;
  SInt32 *accel;
  SInt32 baseResult;
  SInt32 ringLeft;
  SInt32 unitIndex;
  SInt32 slotsLeft;
  SInt32 sharedResult;
  SInt32 readyResult;
  SInt32 setupResult;
  UInt8 *entryCursor;
  UInt8 *unitCursor;
  UInt8 *slotCursor;
  bool moreUnits;
  UInt8 crEqualBits;
  
  baseResult = IOUserClient::start(provider);
  if (baseResult == 0) {
    return 0;
  }
  M<UInt8 *>(self + kIOATIR500GLContext_accelerator) = providerBytes;
  M<UInt32>(self + kIOATIR500GLContext_contextBufferHeader) = 0;
  M<UInt32>(self + kIOATIR500GLContext_started) = 0;
  M<UInt32>(self + kIOATIR500GLContext_lastSubmitStamp) = 0;
  M<UInt16>(self + kIOATIR500GLContext_commandBufferState) = 1;
  M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) = 1;
  M<UInt32>(self + kIOATIR500GLContext_boundSurface) = 0;
  M<UInt32>(self + kIOATIR500GLContext_surfaceIndex) = 0;
  M<UInt32>(self + kIOATIR500GLContext_mipLevel) = 0;
  M<UInt32>(self + kIOATIR500GLContext_clientHandle) = 0;
  M<UInt32>(self + kIOATIR500GLContext_nextContext) = 0;
  M<UInt32>(self + kIOATIR500GLContext_commandBuffer) = 0;
  M<UInt32>(self + kIOATIR500GLContext_commandBufferGartOffset) = 0;
  M<UInt32>(self + kIOATIR500GLContext_commandBufferDescriptor) = 0;
  M<UInt16>(self + kIOATIR500GLContext_commandBufferInFlight) = 0;
  M<UInt32>(self + kIOATIR500GLContext_commandBufferStamp) = 0;
  M<UInt32>(self + kIOATIR500GLContext_commandBufferHeader) = 0;
  M<UInt32>(self + kIOATIR500GLContext_commandBufferSize) = 0;
  M<UInt32>(self + kIOATIR500GLContext_dataBufferListHead) = 0;
  M<UInt32>(self + kIOATIR500GLContext_dataBufferListTail) = 0;
  M<UInt32>(self + kIOATIR500GLContext_dataBufferCount) = 0;
  M<UInt32>(self + kIOATIR500GLContext_contextBufferRingIndex) = 0;
  M<UInt32>(self + kIOATIR500GLContext_contextBuffer) = 0;
  M<UInt32>(self + kIOATIR500GLContext_contextBufferGartOffset) = 0;
  M<UInt32>(self + kIOATIR500GLContext_contextBufferDescriptor) = 0;
  M<UInt16>(self + kIOATIR500GLContext_contextBufferInFlight) = 0;
  M<UInt16>(self + kIOATIR500GLContext_contextBufferType) = 0;
  M<UInt32>(self + kIOATIR500GLContext_contextBufferStamp) = 0;
  M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) = 6;
  ringLeft = 0x10;
  M<UInt32>(self + kIOATIR500GLContext_commandBufferSizeHint) = 0x20000;
  M<UInt32>(self + kIOATIR500GLContext_dataBufferSizeHint) = 0x10000;
  entryCursor = self;
  do {
    M<UInt32>(entryCursor + 0x10c) = 0;
    M<UInt32>(entryCursor + 0x110) = 0;
    M<UInt32>(entryCursor + 0x114) = 0;
    M<UInt16>(entryCursor + 0x11a) = 0;
    M<UInt16>(entryCursor + 0x118) = 0;
    M<UInt32>(entryCursor + 0x11c) = 0;
    M<UInt32>(entryCursor + 0x120) = 0;
    entryCursor = entryCursor + 0x18;
    ringLeft = ringLeft + -1;
  } while (ringLeft != 0);
  M<UInt16>(self + kIOATIR500GLContext_swapIntervalNumerator) = 0;
  M<UInt16>(self + kIOATIR500GLContext_swapRectX) = 0;
  M<UInt16>(self + kIOATIR500GLContext_swapRectY) = 0;
  M<UInt16>(self + kIOATIR500GLContext_swapRectWidth) = 0;
  M<UInt16>(self + kIOATIR500GLContext_swapIntervalDenominator) = 1;
  M<UInt16>(self + kIOATIR500GLContext_swapRectHeight) = 0;
  unitIndex = 0;
  unitCursor = self;
  do {
    moreUnits = unitIndex != 2;
    M<UInt32>(unitCursor + 0x9c) = 0;
    unitIndex = unitIndex + 1;
    unitCursor = unitCursor + 4;
  } while (moreUnits);
  M<UInt32>(self + kIOATIR500GLContext_unknown_0xc4) = 0;
  slotsLeft = 0x2a;
  M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = 0x20000000;
  slotCursor = self;
  do {
    M<UInt32>(slotCursor + 0x2a4) = 0;
    slotCursor = slotCursor + 4;
    slotsLeft = slotsLeft + -1;
  } while (slotsLeft != 0);
  /* the null check must be explicit: `new IOATIR500Shared()` compiled to an unconditional constructor call (same as #187), which writes through a null `this`
   * when OSObject::operator new fails; the shipped code tests the allocation first (difftest: IOATIR500GLContext::start hand world) */
  { void *mem = OSObject::operator new(0x28);
    shared = mem ? (UInt8 *)::new (mem) IOATIR500Shared() : (UInt8 *)0; }
  crEqualBits = (shared == (UInt8 *)0x0) << 1;
  M<UInt8 *>(self + kIOATIR500GLContext_clientHandle) = shared;
  if (!(bool)(crEqualBits >> 1 & 1)) {
    sharedResult = VCALL(M<SInt32>(shared), 0x48)(shared);
    if (sharedResult == 0) {
      VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_clientHandle), 0x18)(M<SInt32 *>(self + kIOATIR500GLContext_clientHandle));
      M<UInt32>(self + kIOATIR500GLContext_clientHandle) = 0;
    }
    else {
      M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0xc) = M<UInt32>(self + kIOATIR500GLContext_accelerator);
      M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 8) = M<UInt32>(self + kIOATIR500GLContext_task);
      accel = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
      if ((accel[0x18] == 0) && (accel[0x1a] == 0)) {
        readyResult = VCALL(*accel, 0x530)(accel);
        if (readyResult == 0) goto stopAndFail;
        accel = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
      }
      M<SInt32>(self + kIOATIR500GLContext_nextLiveContext) = accel[0x18];
      accel[0x18] = (SInt32)self;
      M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x738) = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x738) + 1;
      setupResult = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->getVRAMDescriptors();
      if (((setupResult != 0) &&
          (setupResult = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->allocCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)),0x20000), setupResult != 0)) &&
         (setupResult = this->allocAllContextBuffers(0x8000), setupResult != 0)) {
        M<UInt32>(self + kIOATIR500GLContext_started) = 1;
        M<UInt8 **>(self + kIOATIR500GLContext_regularMethodTable) = (UInt8 **)kGLRegularMethods; /* IOATIR500GLContext::start(IOService*)::methodDescs */
        return 1;
      }
    }
  }
stopAndFail:
  IOATIR500GLContext::stop(provider);
  return 0;
}
