/*
 * IOATIR500DVDContext_lock_all_buffers_Port.cpp
 *
 * IOATIR500DVDContext::lock_all_buffers (real addr 0xfd00, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xfd00 */
IOReturn IOATIR500DVDContext::lock_all_buffers(UInt32 unused1, sIODVDContextLockBufferData *out) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *outCursor = reinterpret_cast<UInt8 *>(out);

  int entryOffset;
  UInt32 surface;
  int iVar3;
  int iVar4;
  UInt32 result;
  
  iVar4 = 0;
  while( true ) {
    GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
    surface = M<UInt32>(self + kIOATIR500DVDContext_boundSurface);
    if (surface == 0) break;
    if ((M<unsigned int>(surface + 0xbf8) & M<unsigned int>(self + kIOATIR500DVDContext_surfaceFlagsBitmask) & 0x207ffc00) == 0) {
LAB_0000fe04:
      iVar4 = 10;
      iVar3 = 0xd;
      while( true ) {
        entryOffset = iVar4 * 4;
        iVar4 = iVar4 + 1;
        M<UInt32>(outCursor) = M<UInt32>(M<int>(entryOffset + surface + 0xb70) + 8);
        M<unsigned int>(outCursor + 4) =
             (unsigned int)M<UInt16>(M<int>(entryOffset + M<int>(self + kIOATIR500DVDContext_boundSurface) + 0xb70) + 0x18);
        outCursor = outCursor + 8;
        iVar3 = iVar3 + -1;
        if (iVar3 == 0) break;
        surface = M<UInt32>(self + kIOATIR500DVDContext_boundSurface);
      }
      result = 0;
      M<SInt16>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0xbd2) = M<SInt16>(M<int>(self + kIOATIR500DVDContext_boundSurface) + 0xbd2) + 1;
      goto LAB_0000fea0;
    }
    if ((M<unsigned int>(surface + 0xbf8) & 0x20000000) != 0) break;
    iVar3 = ((IOATIR500Surface *)(surface))->alloc_surfaces(M<UInt32>(self + kIOATIR500DVDContext_surfaceFlagsBitmask) & 0x207ffc00, false);
    if (iVar3 == 0) {
LAB_0000fe00:
      surface = M<UInt32>(self + kIOATIR500DVDContext_boundSurface);
      goto LAB_0000fe04;
    }
    if (iVar3 == 2) break;
    if (iVar4 == 1000) {
      iVar4 = ((IOATIR500Surface *)(M<UInt32>(self + kIOATIR500DVDContext_boundSurface)))->alloc_surfaces(M<UInt32>(self + kIOATIR500DVDContext_surfaceFlagsBitmask) & 0x207ffc00, true);
      if (iVar4 == 0) goto LAB_0000fe00;
      iVar4 = 0xd;
      do {
        M<UInt32>(outCursor + 4) = 0;
        M<UInt32>(outCursor) = 0;
        outCursor = outCursor + 8;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      goto LAB_0000fdd0;
    }
    iVar4 = iVar4 + 1;
    GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
    GH_thread_block(0);
    GH_IOSleep(1);
  }
  iVar4 = 0xd;
  do {
    M<UInt32>(outCursor) = 0;
    M<UInt32>(outCursor + 4) = 0;
    outCursor = outCursor + 8;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
LAB_0000fdd0:
  result = 0xe00002cc;
LAB_0000fea0:
  GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR500DVDContext_accelerator) + 0x840));
  return result;
}
