/*
 * ATIR5002DContext_write_2_regs_Port.cpp
 *
 * ATIR5002DContext::write_2_regs (real addr 0x325d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x325d0 */
IOReturn ATIR5002DContext::write_2_regs(UInt32 offset1, UInt32 offset2, UInt32*values, UInt32 byteCount) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 value;
  SInt32 accel;
  UInt32 wordsDone;
  SInt32 registers;
  UInt32 result;
  
  registers = M<SInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x860);
  if ((byteCount & 7) == 0) {
    GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR5002DContext_accelerator) + 0x840));
    accel = M<SInt32>(self + kIOATIR5002DContext_accelerator);
    if (M<char>(accel + kIOATIR500Accelerator_active) == '\0') {
      result = 0xe00002d8;
    }
    else {
      if (byteCount >> 3 != 0) {
        wordsDone = 0;
        do {
          value = *values;
          storeWordByteReversed(&M<UInt8>(registers + (offset1 & 0x1ffc)), value);
          value = values[1];
          storeWordByteReversed(&M<UInt8>(registers + (offset2 & 0x1ffc)), value);
          wordsDone = wordsDone + 2;
          values = values + 2;
        } while (wordsDone < byteCount >> 3);
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
