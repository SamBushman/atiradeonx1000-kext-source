/*
 * ATIR5002DContext_write_regs_Port.cpp
 *
 * ATIR5002DContext::write_regs (real addr 0x33740, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x33740 */
IOReturn ATIR5002DContext::write_regs(UInt32*offsetValuePairs, UInt32 pairByteCount) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 accel;
  UInt32 value;
  UInt32 wordsDone;
  SInt32 registers;
  UInt32 result;
  
  registers = M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x860);
  if ((pairByteCount & 7) == 0) {
    GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x840));
    accel = M<SInt32>(self + kIOATIR5002DContext_accelerator);
    if (M<char>(accel + kIOATIR500Accelerator_active) == '\0') {
      result = 0xe00002d8;
    }
    else {
      if (pairByteCount >> 3 != 0) {
        wordsDone = 0;
        do {
          value = offsetValuePairs[1];
          M<UInt32>(registers + (*offsetValuePairs & 0x1ffc)) =
               value << 0x18 | (value & 0xff00) << 8 | value >> 8 & 0xff00 | value >> 0x18;
          wordsDone = wordsDone + 2;
          offsetValuePairs = offsetValuePairs + 2;
        } while (wordsDone < pairByteCount >> 3);
      }
      result = 0;
    }
    GH_IOLockUnlock(M<UInt32>(accel + kIOATIR500Accelerator_commandLock));
  }
  else {
    result = 0xe00002c2;
  }
  return result;
}
