/*
 * ATIR500GLContext_get_hw_info_Port.cpp
 *
 * ATIR500GLContext::get_hw_info (real addr 0x27210, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x27210 */
IOReturn ATIR500GLContext::get_hw_info(UInt32*out0, UInt32*out1, UInt32*out2, UInt32*out3, UInt32*out4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 value;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
  value = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->getNumPipes();
  *out0 = value;
  value = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->getChipID();
  *out1 = value;
  value = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->getChipRev();
  *out2 = value;
  value = ((ATIRadeonX1000 *)(M<UInt8 *>(self + kIOATIR500GLContext_accelerator)))->getNumZPipes();
  *out3 = value;
  *out4 = 0;
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
  return 0;
}
