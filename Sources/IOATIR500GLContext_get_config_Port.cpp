/*
 * IOATIR500GLContext_get_config_Port.cpp
 *
 * IOATIR500GLContext::get_config (real addr 0xb010, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_IOLockSleep(...) asm("_IOLockSleep");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0xb010 */
IOReturn IOATIR500GLContext::get_config(UInt32*out0, UInt32*out1, UInt32*out2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool more;
  UInt32 bufferIndex;
  UInt32 *info;
  UInt32 infoRecords [97];
  SInt32 queryResult;
  SInt32 infoByteOffset;
  UInt32 out1Value;
  SInt32 walkIndex;
  SInt32 accelerator;
  SInt32 recordOffset;
  SInt32 lastIndex;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
  if ((M<SInt32>(self + kIOATIR500GLContext_boundSurface) != 0) && (0xff < M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xa4))) {
    accelerator = M<SInt32>(self + kIOATIR500GLContext_accelerator);
    if (M<char>(accelerator + kIOATIR500Accelerator_active) != '\0') goto LAB_0000b08c;
    do {
      GH_IOLockSleep(M<UInt32>(accelerator + kIOATIR500Accelerator_commandLock),accelerator,0);
    } while (M<char>(accelerator + kIOATIR500Accelerator_active) == '\0');
  }
  accelerator = M<SInt32>(self + kIOATIR500GLContext_accelerator);
LAB_0000b08c:
  *out0 = M<UInt32>(accelerator + kIOATIR500Accelerator_hwCapabilityBits);
  *out2 = M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x9c);
  if (M<SInt32>(self + kIOATIR500GLContext_boundSurface) == 0) {
    out1Value = VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x548)(M<SInt32 *>(self + kIOATIR500GLContext_accelerator));
  }
  else {
    bufferIndex = 0;
    recordOffset = 0;
    info = infoRecords;
    do {
      if ((1 << (bufferIndex & 0x3f) & M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask)) != 0) {
        *info = 0;
        info[1] = 0;
        info[2] = 0;
        info[3] = 0;
        queryResult = VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x540)
                          (M<SInt32 *>(self + kIOATIR500GLContext_accelerator),info,
                           M<UInt32>(recordOffset + M<SInt32>(self + kIOATIR500GLContext_boundSurface) + 0xb8),0x1000);
        if (queryResult == 0) {
          lastIndex = bufferIndex - 1;
          out1Value = 0;
          if (lastIndex < 0) goto LAB_0000b1f0;
          goto LAB_0000b174;
        }
      }
      more = bufferIndex != 0x16;
      recordOffset = recordOffset + 0x78;
      info = info + 4;
      bufferIndex = bufferIndex + 1;
    } while (more);
    lastIndex = 0x16;
    out1Value = VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x548)(M<SInt32 *>(self + kIOATIR500GLContext_accelerator));
LAB_0000b174:
    infoByteOffset = lastIndex << 4;
    walkIndex = 0;
    do {
      if ((1 << (lastIndex - walkIndex & 0x3fU) & M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask)) != 0) {
        VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x544)(M<SInt32 *>(self + kIOATIR500GLContext_accelerator),(SInt32)infoRecords + infoByteOffset);
      }
      walkIndex = walkIndex + 1;
      infoByteOffset = infoByteOffset + -0x10;
    } while (walkIndex != lastIndex + 1);
  }
LAB_0000b1f0:
  *out1 = out1Value;
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
  return 0;
}
