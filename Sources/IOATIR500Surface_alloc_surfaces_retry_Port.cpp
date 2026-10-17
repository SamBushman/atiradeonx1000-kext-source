/*
 * IOATIR500Surface_alloc_surfaces_retry_Port.cpp
 *
 * IOATIR500Surface::alloc_surfaces_retry (real addr 0x14860, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0x14860 */
IOReturn IOATIR500Surface::alloc_surfaces_retry(UInt32 flags, eLockType lockType) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 lockState;
  int pageqResult;
  UInt32 result;
  int retriesLeft;
  UInt8 isWriteLock;
  UInt8 isReadLock;
  UInt8 isNoLock;
  
  isNoLock = (lockType == 0) << 1;
  isWriteLock = (lockType == 2) << 1;
  isReadLock = (lockType == 1) << 1;
  retriesLeft = 0x3e9;
  do {
    if ((bool)(isNoLock >> 1 & 1)) {
      if (M<char>(M<int>(self + 0xd50) + 0x80) == '\0') {
        return 0xe00002be;
      }
    }
    else {
      if ((bool)(isReadLock >> 1 & 1)) {
        lockState = self[0xbd0];
      }
      else {
        if (!(bool)(isWriteLock >> 1 & 1)) goto LAB_000148e0;
        lockState = self[0xbd1];
      }
      if (lockState != 0x0) goto LAB_00014970;
    }
LAB_000148e0:
    if ((M<unsigned int>(self + 0xbf8) & 0x20000000) != 0) goto LAB_00014970;
    if ((M<unsigned int>(self + 0xbf8) & flags) == 0) goto LAB_00014968;
    if ((!(bool)(isNoLock >> 1 & 1)) && (M<char>(M<int>(self + 0xd50) + 0x80) == '\0')) {
      return 0xe00002be;
    }
    /* the decompile passed `this` as a leading argument and dropped the last one: shipped asm 0x14910 is (this, mask = flags, keepMask = 0, bool = 0) */
    pageqResult = this->alloc_surfaces_pageq(flags,0,false);
    if (pageqResult == 0) goto LAB_00014968;
    if (pageqResult == 2) goto LAB_00014970;
    retriesLeft = retriesLeft + -1;
    if (retriesLeft == 0) {
      retriesLeft = this->alloc_surfaces_pageq(M<unsigned int>(self + 0xc1c) & 3,0,true);   /* shipped asm 0x14988: r4 = self[0xc1c] & 3, r5 = 0, r6 = 1 */
      if (retriesLeft == 0) {
LAB_00014968:
        result = 0;
      }
      else {
LAB_00014970:
        result = 0xe00002cc;
      }
      return result;
    }
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
    GH_thread_block(0);
    GH_IOSleep(1);
    GH_IOLockLock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  } while( true );
}
