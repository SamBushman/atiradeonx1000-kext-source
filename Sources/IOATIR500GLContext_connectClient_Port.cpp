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
IOReturn IOATIR500GLContext::connectClient(IOUserClient *client) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *clientBytes = reinterpret_cast<UInt8 *>(client);

  SInt32 *handle;
  UInt32 result;
  
  if (M<SInt32>(self + 0x78) == M<SInt32>(clientBytes + 0x78)) {
    GH_IOLockLock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
    VCALL(*M<SInt32 *>(self + 0x88), 0x18)(M<SInt32 *>(self + 0x88));
    handle = M<SInt32 *>(clientBytes + 0x88);
    M<SInt32 *>(self + 0x88) = handle;
    VCALL(*handle, 0x14)(handle);
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
    result = 0;
  }
  else {
    result = 0xe00002bc;
  }
  return result;
}
