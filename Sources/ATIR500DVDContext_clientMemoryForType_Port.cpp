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
IOReturn ATIR500DVDContext::clientMemoryForType(UInt32 type, UInt32*options, IOMemoryDescriptor**memory) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 result;
  
  if (type < 4) {
    /* #177: explicit base-class call, as the shipped kext does (a direct call to 0xf0c0). `((IOATIR500DVDContext *)self)->clientMemoryForType(..)` is a VIRTUAL call under -fapple-kext and
     * re-enters this function through vtable +0x580 forever (kernel stack overflow, whole-machine hang on any IOConnectMapMemory of type 0-3). Same bug class as #155. */
    result = IOATIR500DVDContext::clientMemoryForType(type,(UInt32 *)(options),(IOMemoryDescriptor **)(memory));
  }
  else {
    if (type == 4) {
      GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
      if (M<int>(self + kATIR500DVDContext_lumaBufferToggle) == 0) {
        VCALL(*M<int *>(self + kIOATIR500DVDContext_accelerator), 0x5ec)
                  (M<int *>(self + kIOATIR500DVDContext_accelerator),M<UInt32>(self + kATIR500DVDContext_idctLumaBuffer1Stamp));
        VCALL(*M<int *>(self + kATIR500DVDContext_idctLumaBuffer1Descriptor), 0x14)(M<int *>(self + kATIR500DVDContext_idctLumaBuffer1Descriptor));
        *options = 0;
        *memory = M<IOMemoryDescriptor *>(self + kATIR500DVDContext_idctLumaBuffer1Descriptor);
        ((IOATIR500DVDContext *)((UInt8 *)self))->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + kATIR500DVDContext_idctLumaBuffer1Header)),
                   M<UInt32>(self + kATIR500DVDContext_idctLumaBuffer1Size),0);
        M<UInt32>(M<int>(self + kATIR500DVDContext_idctLumaBuffer1Header) + 0x18) = M<UInt32>(self + kATIR500DVDContext_idctTimeStampCounter);
        M<UInt32>(self + kATIR500DVDContext_lumaBufferToggle) = 1;
      }
      else {
        VCALL(*M<int *>(self + kIOATIR500DVDContext_accelerator), 0x5ec)
                  (M<int *>(self + kIOATIR500DVDContext_accelerator),M<UInt32>(self + kATIR500DVDContext_idctLumaBuffer0Stamp));
        VCALL(*M<int *>(self + kATIR500DVDContext_idctLumaBuffer0Descriptor), 0x14)(M<int *>(self + kATIR500DVDContext_idctLumaBuffer0Descriptor));
        *options = 0;
        *memory = M<IOMemoryDescriptor *>(self + kATIR500DVDContext_idctLumaBuffer0Descriptor);
        ((IOATIR500DVDContext *)((UInt8 *)self))->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + kATIR500DVDContext_idctLumaBuffer0Header)),
                   M<UInt32>(self + kATIR500DVDContext_idctLumaBuffer0Size),0);
        M<UInt32>(M<int>(self + kATIR500DVDContext_idctLumaBuffer0Header) + 0x18) = M<UInt32>(self + kATIR500DVDContext_idctTimeStampCounter);
        M<UInt32>(self + kATIR500DVDContext_lumaBufferToggle) = 0;
      }
    }
    else {
      if (type != 5) {
        return 0xe00002c2;
      }
      GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
      if (M<int>(self + kATIR500DVDContext_chromaBufferToggle) == 0) {
        VCALL(*M<int *>(self + kIOATIR500DVDContext_accelerator), 0x5ec)
                  (M<int *>(self + kIOATIR500DVDContext_accelerator),M<UInt32>(self + kATIR500DVDContext_idctChromaBuffer1Stamp));
        VCALL(*M<int *>(self + kATIR500DVDContext_idctChromaBuffer1Descriptor), 0x14)(M<int *>(self + kATIR500DVDContext_idctChromaBuffer1Descriptor));
        *options = 0;
        *memory = M<IOMemoryDescriptor *>(self + kATIR500DVDContext_idctChromaBuffer1Descriptor);
        ((IOATIR500DVDContext *)((UInt8 *)self))->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + kATIR500DVDContext_idctChromaBuffer1Header)),
                   M<UInt32>(self + kATIR500DVDContext_idctChromaBuffer1Size),0);
        M<UInt32>(M<int>(self + kATIR500DVDContext_idctChromaBuffer1Header) + 0x18) = M<UInt32>(self + kATIR500DVDContext_idctTimeStampCounter);
        M<UInt32>(self + kATIR500DVDContext_chromaBufferToggle) = 1;
      }
      else {
        VCALL(*M<int *>(self + kIOATIR500DVDContext_accelerator), 0x5ec)
                  (M<int *>(self + kIOATIR500DVDContext_accelerator),M<UInt32>(self + kATIR500DVDContext_idctChromaBuffer0Stamp));
        VCALL(*M<int *>(self + kATIR500DVDContext_idctChromaBuffer0Descriptor), 0x14)(M<int *>(self + kATIR500DVDContext_idctChromaBuffer0Descriptor));
        *options = 0;
        *memory = M<IOMemoryDescriptor *>(self + kATIR500DVDContext_idctChromaBuffer0Descriptor);
        ((IOATIR500DVDContext *)((UInt8 *)self))->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + kATIR500DVDContext_idctChromaBuffer0Header)),
                   M<UInt32>(self + kATIR500DVDContext_idctChromaBuffer0Size),0);
        M<UInt32>(M<int>(self + kATIR500DVDContext_idctChromaBuffer0Header) + 0x18) = M<UInt32>(self + kATIR500DVDContext_idctTimeStampCounter);
        M<UInt32>(self + kATIR500DVDContext_chromaBufferToggle) = 0;
      }
    }
    GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
    result = 0;
  }
  return result;
}
