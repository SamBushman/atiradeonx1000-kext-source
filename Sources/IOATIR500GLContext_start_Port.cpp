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

  bool bVar1;
  UInt8 *pIVar2;
  SInt32 iVar3;
  UInt8 *shared;
  SInt32 *accel;
  UInt8 bVar5;
  
  iVar3 = IOUserClient::start(provider);
  if (iVar3 == 0) {
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
  iVar3 = 0x10;
  M<UInt32>(self + kIOATIR500GLContext_commandBufferSizeHint) = 0x20000;
  M<UInt32>(self + kIOATIR500GLContext_dataBufferSizeHint) = 0x10000;
  pIVar2 = self;
  do {
    M<UInt32>(pIVar2 + 0x10c) = 0;
    M<UInt32>(pIVar2 + 0x110) = 0;
    M<UInt32>(pIVar2 + 0x114) = 0;
    M<UInt16>(pIVar2 + 0x11a) = 0;
    M<UInt16>(pIVar2 + 0x118) = 0;
    M<UInt32>(pIVar2 + 0x11c) = 0;
    M<UInt32>(pIVar2 + 0x120) = 0;
    pIVar2 = pIVar2 + 0x18;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  M<UInt16>(self + kIOATIR500GLContext_swapIntervalNumerator) = 0;
  M<UInt16>(self + kIOATIR500GLContext_swapRectX) = 0;
  M<UInt16>(self + kIOATIR500GLContext_swapRectY) = 0;
  M<UInt16>(self + kIOATIR500GLContext_swapRectWidth) = 0;
  M<UInt16>(self + kIOATIR500GLContext_swapIntervalDenominator) = 1;
  M<UInt16>(self + kIOATIR500GLContext_swapRectHeight) = 0;
  iVar3 = 0;
  pIVar2 = self;
  do {
    bVar1 = iVar3 != 2;
    M<UInt32>(pIVar2 + 0x9c) = 0;
    iVar3 = iVar3 + 1;
    pIVar2 = pIVar2 + 4;
  } while (bVar1);
  M<UInt32>(self + kIOATIR500GLContext_unknown_0xc4) = 0;
  iVar3 = 0x2a;
  M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask) = 0x20000000;
  pIVar2 = self;
  do {
    M<UInt32>(pIVar2 + 0x2a4) = 0;
    pIVar2 = pIVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  /* the null check must be explicit: `new IOATIR500Shared()` compiled to an unconditional constructor call (same as #187), which writes through a null `this`
   * when OSObject::operator new fails; the shipped code tests the allocation first (difftest: IOATIR500GLContext::start hand world) */
  { void *mem = OSObject::operator new(0x28);
    shared = mem ? (UInt8 *)::new (mem) IOATIR500Shared() : (UInt8 *)0; }
  bVar5 = (shared == (UInt8 *)0x0) << 1;
  M<UInt8 *>(self + kIOATIR500GLContext_clientHandle) = shared;
  if (!(bool)(bVar5 >> 1 & 1)) {
    iVar3 = VCALL(M<SInt32>(shared), 0x48)(shared);
    if (iVar3 == 0) {
      VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_clientHandle), 0x18)(M<SInt32 *>(self + kIOATIR500GLContext_clientHandle));
      M<UInt32>(self + kIOATIR500GLContext_clientHandle) = 0;
    }
    else {
      M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0xc) = M<UInt32>(self + kIOATIR500GLContext_accelerator);
      M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 8) = M<UInt32>(self + kIOATIR500GLContext_task);
      accel = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
      if ((accel[0x18] == 0) && (accel[0x1a] == 0)) {
        iVar3 = VCALL(*accel, 0x530)(accel);
        if (iVar3 == 0) goto LAB_0000790c;
        accel = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
      }
      M<SInt32>(self + kIOATIR500GLContext_nextLiveContext) = accel[0x18];
      accel[0x18] = (SInt32)self;
      M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x738) = M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x738) + 1;
      iVar3 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->getVRAMDescriptors();
      if (((iVar3 != 0) &&
          (iVar3 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->allocCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + kIOATIR500GLContext_commandBuffer)),0x20000), iVar3 != 0)) &&
         (iVar3 = this->allocAllContextBuffers(0x8000), iVar3 != 0)) {
        M<UInt32>(self + kIOATIR500GLContext_started) = 1;
        M<UInt8 **>(self + kIOATIR500GLContext_regularMethodTable) = (UInt8 **)kGLRegularMethods; /* IOATIR500GLContext::start(IOService*)::methodDescs */
        return 1;
      }
    }
  }
LAB_0000790c:
  IOATIR500GLContext::stop(provider);
  return 0;
}
