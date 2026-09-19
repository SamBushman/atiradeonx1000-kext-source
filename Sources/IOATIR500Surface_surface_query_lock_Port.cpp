/*
 * IOATIR500Surface_surface_query_lock_Port.cpp
 *
 * IOATIR500Surface::surface_query_lock (real addr 0x151a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x151a0 */
IOReturn IOATIR500Surface::surface_query_lock() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0xd50) + 0x840));
  if (((M<UInt32>(self + 0xbd0) & 0xffff0000) == 0) &&
     (M<SInt32>(M<SInt32>(self + 0xb70) + 0x10) != 0)) {
    if ((M<UInt32>(self + 0xbf8) & 0x20000000) == 0) {
      uVar1 = M<UInt32>(self + 0xbf8) & M<UInt32>(self + 0xc1c);
      if ((uVar1 & 3) != 0) {
        uVar1 = uVar1 & 1 ^ 1;
        if ((M<SInt32>(self + uVar1 * 0x78 + 0xb8) != 0) &&
           (M<SInt32>(self + uVar1 * 0x78 + 0xb0) == 0)) {
          iVar2 = VCALL(M<SInt32>(self), 0x5d0)(self);
          if (iVar2 != 0) {
            uVar3 = 0;
            VCALL(M<SInt32>(self), 0x5cc)(self,uVar1);
            goto LAB_00015280;
          }
          goto LAB_00015270;
        }
      }
      uVar3 = 0;
      goto LAB_00015280;
    }
  }
LAB_00015270:
  uVar3 = 0xe00002cc;
LAB_00015280:
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0xd50) + 0x840));
  return uVar3;
}
