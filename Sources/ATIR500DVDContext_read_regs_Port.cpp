/*
 * ATIR500DVDContext_read_regs_Port.cpp
 *
 * ATIR500DVDContext::read_regs (real addr 0x35120, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x35120 */
IOReturn ATIR500DVDContext::read_regs(UInt32*offsets, UInt32*outValues, UInt32 byteCount, UInt32*inOutCount) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *registerAddress;
  SInt32 iVar2;
  SInt32 registers;
  UInt32 uVar4;
  UInt32 result;
  UInt32 actualBytes;
  UInt32 dwordsLeft;
  SInt32 accelAddr;
  SInt32 byteOffset;
  
  actualBytes = *inOutCount;
  registers = M<SInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x860);
  if ((actualBytes == byteCount) && ((actualBytes & 3) == 0)) {
    GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x840));
    accelAddr = M<SInt32>(self + kIOATIR500DVDContext_accelerator);
    if (M<char>(accelAddr + kIOATIR500Accelerator_active) == '\0') {
      result = 0xe00002d8;
    }
    else {
      dwordsLeft = actualBytes >> 2;
      if (dwordsLeft != 0) {
        byteOffset = 0;
        do {
          registerAddress = (UInt8 *)(registers + (M<UInt32>((SInt32)offsets + byteOffset) & 0x1ffc));
          M<UInt32>((SInt32)outValues + byteOffset) =
               loadWordByteReversed(registerAddress);
          byteOffset = byteOffset + 4;
          dwordsLeft = dwordsLeft - 1;
        } while (dwordsLeft != 0);
        accelAddr = M<SInt32>(self + kIOATIR500DVDContext_accelerator);
      }
      result = 0;
    }
    GH_IOLockUnlock(M<UInt32>(accelAddr + kIOATIR500Accelerator_commandLock));
  }
  else {
    result = 0xe00002c2;
  }
  return result;
}
