/*
 * ATIR500DVDContext_doIDCT_Port.cpp
 *
 * ATIR500DVDContext::doIDCT (real addr 0x35540, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x35540 */
IOReturn ATIR500DVDContext::doIDCT(sATIDVDIDCTInfo *info, UInt32 infoSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = self;   /* Ghidra's param_1 IS `this` (r3); the first real argument (r4) is its infoBytes (#86) */
    UInt8 *infoBytes = reinterpret_cast<UInt8 *>(info);

  SInt32 iVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  UInt8 *bufferSlot;
  UInt32 uVar5;
  
  VCALL(*M<SInt32 *>(param_1 + kIOATIR500DVDContext_accelerator), 0x54c)
            (M<SInt32 *>(param_1 + kIOATIR500DVDContext_accelerator),M<UInt32>(param_1 + kIOATIR500DVDContext_lastSubmitStamp));
  if (((M<SInt32>(param_1 + kIOATIR500DVDContext_boundSurface) != 0) &&
      (iVar1 = M<SInt32>(param_1 + kIOATIR500DVDContext_accelerator), M<char>(iVar1 + 0x80) != '\0')) &&
     (M<SInt32>(iVar1 + 0x8bc) != 0)) {
    GH_IOLockLock(M<UInt32>(iVar1 + 0x840));
    iVar1 = M<SInt32>(param_1 + kIOATIR500DVDContext_boundSurface);
    uVar2 = (SInt32)M<SInt16>(iVar1 + 0x9a) - (SInt32)M<SInt16>(iVar1 + 0x94);
    if (M<SInt32>(infoBytes + 0xc) == 0) {
      bufferSlot = (UInt8 *)(param_1 + kATIR500DVDContext_idctLumaBuffer0);
      if (M<SInt32>(param_1 + kATIR500DVDContext_lumaBufferToggle) != 0) {
        bufferSlot = (UInt8 *)(param_1 + kATIR500DVDContext_idctLumaBuffer1);
      }
      iVar1 = M<SInt32>(infoBytes + 8) * 0x78 + iVar1 + 0x558;
    }
    else {
      if (M<SInt32>(infoBytes + 0xc) != 1) {
        return 0xe00002c2;
      }
      bufferSlot = (UInt8 *)(param_1 + kATIR500DVDContext_idctChromaBuffer0);
      if (M<SInt32>(param_1 + kATIR500DVDContext_chromaBufferToggle) != 0) {
        bufferSlot = (UInt8 *)(param_1 + kATIR500DVDContext_idctChromaBuffer1);
      }
      iVar1 = iVar1 + 0x8a0;
    }
    if (M<SInt32>(infoBytes) == 0) {
      uVar3 = (UInt32)M<UInt16>(iVar1 + 0x18);
      uVar5 = (UInt32)M<UInt16>(iVar1 + 0x18);
    }
    else {
      uVar3 = (UInt32)M<UInt16>(iVar1 + 0x18);
      uVar5 = uVar3 << 1;
    }
    if (M<SInt32>(infoBytes + 4) == 0) {
      M<UInt32>(infoBytes + 0x2c) = M<UInt32>(iVar1 + 8);
      M<UInt32>(infoBytes + 0x30) = uVar2 * M<UInt16>(iVar1 + 0x18) + M<SInt32>(iVar1 + 8);
    }
    else {
      M<UInt32>(infoBytes + 0x2c) = uVar3 + M<SInt32>(iVar1 + 8);
      M<UInt32>(infoBytes + 0x30) =
           (UInt32)M<UInt16>(iVar1 + 0x18) + uVar2 * M<UInt16>(iVar1 + 0x18) + M<SInt32>(iVar1 + 8)
      ;
    }
    M<UInt32>(infoBytes + 0x1c) = uVar5 * uVar2 + -1;
    M<UInt32>(infoBytes + 0x28) = uVar5 | uVar5 << 0x10;
    M<UInt32>(infoBytes + 0x20) = uVar5 * (uVar2 >> 1) + -1;
    if (M<SInt32>(infoBytes + 0x2c) != 0) {
      iVar1 = M<SInt32>(bufferSlot + 4);
      if (iVar1 == 0) {
        ((IOATIR500DVDContext *)(param_1))->map_transfer_to_GART((VendorTransferBuffer *)(bufferSlot));
        iVar1 = M<SInt32>(bufferSlot + 4);
      }
      uVar5 = M<UInt32>(M<UInt8 *>(param_1 + kIOATIR500DVDContext_accelerator) + 0x854);
      uVar2 = ((ATIRadeonX1000 *)(M<UInt8 *>(param_1 + kIOATIR500DVDContext_accelerator)))->submit_idct_buffer_consumed((UInt32 *)(M<SInt32>(bufferSlot + 0x14) + 0x20),iVar1 + 0x20,
                         (sATIDVDIDCTInfo *)infoBytes);
      M<UInt32>(param_1 + kATIR500DVDContext_idctTimeStampCounter) = uVar2;
      if (uVar5 <= uVar2) {
        M<UInt32>(bufferSlot + 0x10) = uVar2;
        if (M<SInt32>(infoBytes + 0xc) == 0) {
          M<UInt32>(param_1 + kATIR500DVDContext_idctTimeStamp) = M<UInt32>(param_1 + kATIR500DVDContext_idctTimeStampCounter);
        }
        GH_IOLockUnlock(M<UInt32>(M<SInt32>(param_1 + kIOATIR500DVDContext_accelerator) + 0x840));
        return 0;
      }
    }
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(param_1 + kIOATIR500DVDContext_accelerator) + 0x840));
  }
  return 0xe00002d8;
}
