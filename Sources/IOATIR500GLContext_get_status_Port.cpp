/*
 * IOATIR500GLContext_get_status_Port.cpp
 *
 * IOATIR500GLContext::get_status (real addr 0xb250, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xb250 */
IOReturn IOATIR500GLContext::get_status(UInt32*out0) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool more;
  UInt32 bufferIndex;
  UInt32 *info;
  UInt32 infoRecords [94];
  SInt32 surface;
  SInt32 recordOffset;
  SInt32 lastIndex;
  SInt32 accelerator;
  SInt32 queryResult;
  SInt32 infoByteOffset;
  SInt32 walkIndex;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
  surface = M<SInt32>(self + kIOATIR500GLContext_boundSurface);
  if (surface != 0) {
    if ((0xff < M<UInt32>(surface + kIOATIR500Surface_requestedId)) &&
       (accelerator = M<SInt32>(self + kIOATIR500GLContext_accelerator), M<char>(accelerator + 0x80) == '\0')) {
      do {
        GH_IOLockSleep(M<UInt32>(accelerator + 0x840),accelerator,0);
      } while (M<char>(accelerator + 0x80) == '\0');
      surface = M<SInt32>(self + kIOATIR500GLContext_boundSurface);
      if (surface == 0) goto LAB_0000b3e4;
    }
    if ((M<UInt32>(surface + kIOATIR500Surface_stateBits) & 0x20000000) == 0) {
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
            *out0 = 0;
            if (lastIndex < 0) goto LAB_0000b3ec;
            goto LAB_0000b38c;
          }
        }
        more = bufferIndex != 0x16;
        recordOffset = recordOffset + 0x78;
        info = info + 4;
        bufferIndex = bufferIndex + 1;
      } while (more);
      lastIndex = 0x16;
      *out0 = 1;
LAB_0000b38c:
      infoByteOffset = lastIndex << 4;
      walkIndex = 0;
      do {
        if ((1 << (lastIndex - walkIndex & 0x3fU) & M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask)) != 0) {
          VCALL(*M<SInt32 *>(self + kIOATIR500GLContext_accelerator), 0x544)
                    (M<SInt32 *>(self + kIOATIR500GLContext_accelerator),(SInt32)infoRecords + infoByteOffset);
        }
        walkIndex = walkIndex + 1;
        infoByteOffset = infoByteOffset + -0x10;
      } while (lastIndex + 1 != walkIndex);
      goto LAB_0000b3ec;
    }
  }
LAB_0000b3e4:
  *out0 = 0;
LAB_0000b3ec:
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
  return 0;
}
