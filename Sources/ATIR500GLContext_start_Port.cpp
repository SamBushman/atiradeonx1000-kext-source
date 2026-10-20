/*
 * ATIR500GLContext_start_Port.cpp
 *
 * ATIR500GLContext::start (real addr 0x28540, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern const VendorExternalMethod kGLSpecialMethod20 asm("__ZZN16ATIR500GLContext5startEP9IOServiceE11methodDescs");   /* IOATIR500GLContext_ExternalMethods.cpp */

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0x28540 */
bool ATIR500GLContext::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

  UInt16 unitFormat;
  UInt32 result;
  SInt32 baseResult;
  SInt32 attachmentsLeft;
  SInt32 unitsLeft;
  UInt8 *attachmentCursor;
  UInt8 *unitCursor;
  UInt8 *bufferCursor;
  
  GH_IOLockLock(M<UInt32>(providerBytes + 0x840));
  baseResult = IOATIR500GLContext::start(provider);
  if (baseResult == 0) {
    GH_IOLockUnlock(M<UInt32>(providerBytes + 0x840));
    result = 0;
  }
  else {
    M<UInt32>(self + kATIR500GLContext_renderToTexture) = 0;
    M<UInt32>(self + kATIR500GLContext_unknown_0x34c) = 0;
    M<UInt32>(self + kATIR500GLContext_unknown_0x350) = 0;
    M<UInt32>(self + kATIR500GLContext_scissorY) = 0;
    M<UInt32>(self + kATIR500GLContext_scissorX) = 0;
    bufferCursor = self + kATIR500GLContext_perUnitTextureArray;
    attachmentsLeft = 6;
    attachmentCursor = self;
    do {
      M<UInt16>(attachmentCursor + 0x3d4) = 0;
      M<UInt16>(attachmentCursor + 0x3d6) = 0;
      M<UInt16>(attachmentCursor + 0x3d8) = 0;
      M<UInt16>(attachmentCursor + 0x3dc) = 0;
      M<UInt16>(attachmentCursor + 0x3de) = 0;
      M<UInt16>(attachmentCursor + 0x3e0) = 1;
      M<UInt16>(attachmentCursor + 0x3e2) = 1;
      attachmentCursor[0x3f4] = 0x0;
      attachmentCursor[0x3f5] = 0x0;
      attachmentCursor[0x3f6] = 0x0;
      attachmentCursor[0x3f7] = 0xff;
      attachmentCursor[0x3f8] = 0x0;
      attachmentCursor[0x3f9] = 0x0;
      attachmentCursor[0x3fb] = 0x6;
      attachmentCursor[0x3fc] = 0x0;
      M<UInt32>(attachmentCursor + 0x3c0) = 0;
      M<UInt32>(attachmentCursor + 0x3c4) = 0;
      M<UInt32>(attachmentCursor + 0x3c8) = 0;
      M<UInt32>(attachmentCursor + 0x3cc) = 0;
      M<UInt32>(attachmentCursor + 0x3d0) = 0;
      M<UInt32>(attachmentCursor + 0x3e4) = 0;
      M<UInt32>(attachmentCursor + 1000) = 0xffffffff;
      M<UInt32>(attachmentCursor + 0x3ec) = 0;
      M<UInt32>(attachmentCursor + 0x3f0) = 0;
      M<UInt32>(bufferCursor + 0xc) = M<UInt32>(bufferCursor + 0xc) & 0xff0007ff | 0x111000;
      M<UInt32>(attachmentCursor + 0x400) = 0;
      bufferCursor = bufferCursor + 0x78;
      M<UInt32>(attachmentCursor + 0x404) = 0;
      attachmentCursor = attachmentCursor + 0x78;
      attachmentsLeft = attachmentsLeft + -1;
    } while (attachmentsLeft != 0);
    unitFormat = M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex);
    unitsLeft = 4;
    unitCursor = self;
    do {
      M<UInt16>(unitCursor + 0x3b2) = 0;
      M<UInt16>(unitCursor + 0x3aa) = unitFormat;
      unitCursor = unitCursor + 2;
      unitsLeft = unitsLeft + -1;
    } while (unitsLeft != 0);
    M<UInt16>(self + kATIR500GLContext_attachmentCount) = 1;
    M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x1c) = 9;
    M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x40) = 0x1000000;
    M<UInt8 **>(self + kATIR500GLContext_specialMethodTable) = (UInt8 **)&kGLSpecialMethod20; /* ATIR500GLContext::start(IOService*)::methodDescs */
    GH_IOLockUnlock(M<UInt32>(providerBytes + 0x840));
    result = 1;
  }
  return result;
}
