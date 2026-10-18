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
IOReturn IOATIR500Surface::clientMemoryForType(UInt32 type, UInt32*options, IOMemoryDescriptor**memory) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 result;
  UInt8 *memoryDescriptor;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x840));
  if (type < M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xcc)) {
    memoryDescriptor = (UInt8 *)Vol(PANEL_RECORD(self, type)->entries[0].memory);
    VCALL(M<SInt32>(memoryDescriptor), 0x14)(memoryDescriptor);
    *options = 0;
    *memory = (IOMemoryDescriptor *)memoryDescriptor;
    this->init_swap_buffer_header((VendorSwapBufferHeader *)(Vol(PANEL_RECORD(self, type)->entries[0].header)),
               Vol(PANEL_RECORD(self, type)->swapBufferSize));
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x840));
    result = 0;
  }
  else {
    GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x840));
    result = 0xe00002c2;
  }
  return result;
}
