/*
 * IOATIR500GLContext_freeCommandBuffer_Port.cpp
 *
 * IOATIR500GLContext::freeCommandBuffer (real addr 0x7e70, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDesc(...) asm("__ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDescriptor");


/* real addr 0x7e70 */
void IOATIR500GLContext::freeCommandBuffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 accel;
  SInt32 *mapping;
  SInt32 context;
  
  if (M<SInt32>(self + 0xd4) != 0) {
    accel = M<SInt32>(self + 200);
    context = M<SInt32>(accel + 0x60);
    if (context == 0) {
      if (M<SInt32>(accel + 0x68) == 0) {
        return;
      }
    }
    else {
      while( true ) {
        if (M<UInt32>(accel + 0x5c8) < M<UInt32>(context + 0xb0)) {
          M<UInt32>(accel + 0x5c8) = M<UInt32>(context + 0xb0);
        }
        mapping = (SInt32 *)GH_ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDesc(context,M<UInt32>(self + 0xd4));
        if (mapping != (SInt32 *)0x0) {
          VCALL(*mapping, 0x18)(mapping);
        }
        context = M<SInt32>(context + 0x80);
        if (context == 0) break;
        accel = M<SInt32>(self + 200);
      }
      accel = M<SInt32>(self + 200);
    }
    context = M<SInt32>(accel + 0x68);
    if (context != 0) {
      while( true ) {
        if (M<UInt32>(accel + 0x5c8) < 0x80000) {
          M<UInt32>(accel + 0x5c8) = 0x80000;
        }
        mapping = (SInt32 *)GH_ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDesc(context,M<UInt32>(self + 0xd4));
        if (mapping != (SInt32 *)0x0) {
          VCALL(*mapping, 0x18)(mapping);
        }
        context = M<SInt32>(context + 0x80);
        if (context == 0) break;
        accel = M<SInt32>(self + 200);
      }
    }
  }
  return;
}
