/*
 * ATIR500GLContext_clientMemoryForType_Port.cpp
 *
 * ATIR500GLContext::clientMemoryForType (real addr 0x27000, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x27000 */
IOReturn ATIR500GLContext::clientMemoryForType(UInt32 param_1, UInt32*param_2, IOMemoryDescriptor**param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  
  if (param_1 == 0) {
    if (M<SInt32 *>(M<SInt32>(self + 200) + 0x8d8) == (SInt32 *)0x0) {
      uVar1 = 0xe00002be;
    }
    else {
      VCALL(*M<SInt32 *>(M<SInt32>(self + 200) + 0x8d8), 0x14)(M<SInt32 *>(M<SInt32>(self + 200) + 0x8d8));
      uVar1 = 0;
      *param_2 = 0x1000;
      *param_3 = (IOMemoryDescriptor *)(M<UInt8 *>(M<SInt32>(self + 200) + 0x8d8));
    }
  }
  else {
    uVar1 = IOATIR500GLContext::clientMemoryForType(param_1, param_2, param_3);
  }
  return uVar1;
}
