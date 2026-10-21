/*
 * IOATIR500Accelerator_freeTransferToAllocGART_Port.cpp
 *
 * IOATIR500Accelerator::freeTransferToAllocGART (real addr 0x3580, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3580 */
bool IOATIR500Accelerator::freeTransferToAllocGART(VendorTransferBuffer *candidate, VendorTransferBuffer *needed, UInt32 stamp, bool aggressive) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *candidateBytes = reinterpret_cast<UInt8 *>(candidate);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  UInt32 result;
  UInt32 in_register_0000001c;
  SInt32 waitStat;
  SInt32 stampReached;
  SInt32 waitTime;
  
  if ((M<SInt32>(candidateBytes + 4) == 0) || (M<SInt16>(candidateBytes + 0xe) != 0)) {
notFreed:
    result = 0;
  }
  else {
    if (((UInt32)aggressive) == 0) {
      stampReached = VCALL(M<SInt32>(self), 0x554)(self,stamp);
      if (stampReached == 0) goto notFreed;
    }
    else {
      /* #155 follow-up FIX (2026-10-11): stock's own disassembly (real addr 0x3580) shows stamp
       * (the 3rd real parameter, r6 at entry) gets moved into r4 unconditionally early in the
       * function (`mr r4,r6` at +0x20) and is never overwritten before this call - stock genuinely
       * passes (self, stamp) to waitForTimeStamp here. Our port dropped stamp. Same benign-
       * in-practice dropped-argument defect class as the sibling fix in freeOrphanTexture_Port.cpp
       * (self+0x790 is a cosmetic stat only). */
      waitStat = M<SInt32>(self + kIOATIR500Accelerator_removeFromGARTWaitTime);
      waitTime = VCALL(M<SInt32>(self), 0x54c)(self, stamp);
      M<SInt32>(self + kIOATIR500Accelerator_removeFromGARTWaitTime) = waitStat + waitTime;
    }
    VCALL(M<SInt32>(self), 0x5ac)(self,candidateBytes);
    result = VCALL(M<SInt32>(self), 0x5a8)(self,neededBytes);
  }
  return result;
}
