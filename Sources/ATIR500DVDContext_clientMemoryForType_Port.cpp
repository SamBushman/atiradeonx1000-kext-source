/*
 * ATIR500DVDContext_clientMemoryForType_Port.cpp
 *
 * ATIR500DVDContext::clientMemoryForType (real addr 0x352a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x352a0 */
IOReturn ATIR500DVDContext::clientMemoryForType(UInt32 param_1, UInt32*param_2, IOMemoryDescriptor**param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  
  if (param_1 < 4) {
    uVar1 = ((IOATIR500DVDContext *)((UInt8 *)self))->clientMemoryForType(param_1,(UInt32 *)(param_2),(IOMemoryDescriptor **)(param_3));
  }
  else {
    if (param_1 == 4) {
      GH_IOLockLock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
      if (M<int>(self + 0x164) == 0) {
        VCALL(*M<int *>(self + 0x8c), 0x5ec)
                  (M<int *>(self + 0x8c),M<UInt32>(self + 0x194));
        VCALL(*M<int *>(self + 0x18c), 0x14)(M<int *>(self + 0x18c));
        *param_2 = 0;
        *param_3 = M<IOMemoryDescriptor *>(self + 0x18c);
        ((IOATIR500DVDContext *)((UInt8 *)self))->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + 0x198)),
                   M<UInt32>(self + 0x19c),0);
        M<UInt32>(M<int>(self + 0x198) + 0x18) = M<UInt32>(self + 0x150);
        M<UInt32>(self + 0x164) = 1;
      }
      else {
        VCALL(*M<int *>(self + 0x8c), 0x5ec)
                  (M<int *>(self + 0x8c),M<UInt32>(self + 0x178));
        VCALL(*M<int *>(self + 0x170), 0x14)(M<int *>(self + 0x170));
        *param_2 = 0;
        *param_3 = M<IOMemoryDescriptor *>(self + 0x170);
        ((IOATIR500DVDContext *)((UInt8 *)self))->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + 0x17c)),
                   M<UInt32>(self + 0x180),0);
        M<UInt32>(M<int>(self + 0x17c) + 0x18) = M<UInt32>(self + 0x150);
        M<UInt32>(self + 0x164) = 0;
      }
    }
    else {
      if (param_1 != 5) {
        return 0xe00002c2;
      }
      GH_IOLockLock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
      if (M<int>(self + 0x1a0) == 0) {
        VCALL(*M<int *>(self + 0x8c), 0x5ec)
                  (M<int *>(self + 0x8c),M<UInt32>(self + 0x1d0));
        VCALL(*M<int *>(self + 0x1c8), 0x14)(M<int *>(self + 0x1c8));
        *param_2 = 0;
        *param_3 = M<IOMemoryDescriptor *>(self + 0x1c8);
        ((IOATIR500DVDContext *)((UInt8 *)self))->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + 0x1d4)),
                   M<UInt32>(self + 0x1d8),0);
        M<UInt32>(M<int>(self + 0x1d4) + 0x18) = M<UInt32>(self + 0x150);
        M<UInt32>(self + 0x1a0) = 1;
      }
      else {
        VCALL(*M<int *>(self + 0x8c), 0x5ec)
                  (M<int *>(self + 0x8c),M<UInt32>(self + 0x1b4));
        VCALL(*M<int *>(self + 0x1ac), 0x14)(M<int *>(self + 0x1ac));
        *param_2 = 0;
        *param_3 = M<IOMemoryDescriptor *>(self + 0x1ac);
        ((IOATIR500DVDContext *)((UInt8 *)self))->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + 0x1b8)),
                   M<UInt32>(self + 0x1bc),0);
        M<UInt32>(M<int>(self + 0x1b8) + 0x18) = M<UInt32>(self + 0x150);
        M<UInt32>(self + 0x1a0) = 0;
      }
    }
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x8c) + 0x840));
    uVar1 = 0;
  }
  return uVar1;
}
