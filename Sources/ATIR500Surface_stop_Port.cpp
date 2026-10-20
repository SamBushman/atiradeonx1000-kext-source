/*
 * ATIR500Surface_stop_Port.cpp
 *
 * ATIR500Surface::stop (real addr 0x3b0c0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0x3b0c0 */
void ATIR500Surface::stop(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

  bool notLast;
  UInt32 stamp;
  SInt32 scratchRing;
  UInt32 wordCount;
  SInt32 bufferIndex;
  SInt32 vtable5dcResult;
  SInt32 panel;
  UInt8 *buffer;
  UInt8 *slotCursor;
  UInt32 *packet;
  
  bufferIndex = 0;
  buffer = self + kIOATIR500Surface_buffers;
  GH_IOLockLock(M<UInt32>(providerBytes + 0x840));
  slotCursor = self;
  do {
    if (slotCursor[0xdf] != 0xff) {
      VCALL(M<SInt32>(self), 0x600)(self,buffer);
    }
    notLast = bufferIndex != 0x16;
    buffer = buffer + 0x78;
    slotCursor = slotCursor + 0x78;
    bufferIndex = bufferIndex + 1;
  } while (notLast);
  if (((providerBytes[0x80] != 0x0) && (M<SInt32>(self + kIOATIR500Surface_panel) != 0xffff)) &&
     (M<UInt8 *>(providerBytes + M<SInt32>(self + kIOATIR500Surface_panel) * 0x20 + 0xe8) == self)) {
    scratchRing = M<SInt32>(providerBytes + 0x238);
    packet = (UInt32 *)(scratchRing + 0x120);
    VCALL(M<SInt32>(providerBytes), 0x54c)(providerBytes,M<UInt32>(providerBytes + 0x234));
    providerBytes[M<SInt32>(self + kIOATIR500Surface_panel) * 0x78 + 0x164] = SUB41m(M<UInt32>(self + kATIR500Surface_panelSide),0);
    vtable5dcResult = VCALL(M<SInt32>(self), 0x5dc)(self);
    if ((vtable5dcResult == 0) || (M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer1) == self + kIOATIR500Surface_buffer1)) {
      wordCount = 0;
    }
    else {
      panel = M<SInt32>(self + kIOATIR500Surface_panel);
      wordCount = 0x1844;
      if (panel != 0) {
        wordCount = 0x1a44;
      }
      *packet = wordCount;
      M<UInt32>(scratchRing + 0x124) = M<UInt32>(providerBytes + panel * 0x78 + 0x134);
      wordCount = 2;
      M<UInt8 *>(self + kIOATIR500Surface_attachmentBuffer1) = self + kIOATIR500Surface_buffer1;
    }
    stamp = ((ATIRadeonX1000 *)((UInt8 *)providerBytes))->submit_buffer((UInt32 *)(packet),M<SInt32>(providerBytes + 0x228) + 0x120,wordCount);
    M<UInt32>(providerBytes + 0x234) = stamp;
  }
  if (self[0xbf0] != 0x0) {
    this->free_overlay();
    self[0xbf0] = 0x0;
  }
  if (M<SInt32>(providerBytes + 0x8b8) != 0) {
    VCALL(M<SInt32>(providerBytes), 0x5ac)(providerBytes,providerBytes + 0x8a8);
    VCALL(*M<SInt32 *>(providerBytes + 0x8b0), 0x18)(M<SInt32 *>(providerBytes + 0x8b0));
    M<UInt32>(providerBytes + 0x8b8) = 0;
  }
  IOATIR500Surface::stop(provider);
  GH_IOLockUnlock(M<UInt32>(providerBytes + 0x840));
  return;
}
