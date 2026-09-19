/*
 * IOATIR500GLContext_connectClient_Port.cpp
 *
 * IOATIR500GLContext::connectClient (real addr 0x86d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x86d0 */
IOReturn IOATIR500GLContext::connectClient(IOUserClient *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 *piVar1;
  UInt32 uVar2;
  
  if (M<SInt32>(self + 0x78) == M<SInt32>(param_1 + 0x78)) {
    GH_IOLockLock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
    VCALL(*M<SInt32 *>(self + 0x88), 0x18)(M<SInt32 *>(self + 0x88));
    piVar1 = M<SInt32 *>(param_1 + 0x88);
    M<SInt32 *>(self + 0x88) = piVar1;
    VCALL(*piVar1, 0x14)(piVar1);
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
    uVar2 = 0;
  }
  else {
    uVar2 = 0xe00002bc;
  }
  return uVar2;
}
