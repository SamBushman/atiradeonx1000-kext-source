/*
 * IOATIR500Surface_clientMemoryForType_Port.cpp
 *
 * IOATIR500Surface::clientMemoryForType (real addr 0x141b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x141b0 */
IOReturn IOATIR500Surface::clientMemoryForType(UInt32 param_1, UInt32*param_2, IOMemoryDescriptor**param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  UInt8 *pIVar2;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0xd50) + 0x840));
  if (param_1 < M<UInt32>(M<SInt32>(self + 0xd50) + 0xcc)) {
    pIVar2 = M<UInt8 *>(self + param_1 * 0x94 + 0xc28);
    VCALL(M<SInt32>(pIVar2), 0x14)(pIVar2);
    *param_2 = 0;
    *param_3 = (IOMemoryDescriptor *)pIVar2;
    this->init_swap_buffer_header((VendorSwapBufferHeader *)(M<VendorSwapBufferHeader *>(self + param_1 * 0x94 + 0xc34)),
               M<UInt32>(self + param_1 * 0x94 + 0xcb0));
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0xd50) + 0x840));
    uVar1 = 0;
  }
  else {
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0xd50) + 0x840));
    uVar1 = 0xe00002c2;
  }
  return uVar1;
}
