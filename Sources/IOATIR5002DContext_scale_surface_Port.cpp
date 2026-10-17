/*
 * IOATIR5002DContext_scale_surface_Port.cpp
 *
 * IOATIR5002DContext::scale_surface (real addr 0xcb90, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xcb90 */
IOReturn IOATIR5002DContext::scale_surface(UInt32 flags, UInt32 xScale, UInt32 yScale) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 result;
  /* real stock writes these as ONE contiguous 12-byte stack buffer and passes its base address to set_scaling,
   * which reads it back at fixed byte offsets (+0,+2,+4,+6,+8,+10) as an IOAccelSurfaceScaling prefix - see the
   * identical fix + full writeup in IOATIR500GLContext_scale_surface_Port.cpp (issue #160). Six separate named
   * locals have no layout guarantee relative to each other; a real array is the only layout C guarantees. */
  UInt16 local_scale_buf[6];

  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 0x94) + 0x840));
  if ((M<UInt8 *>(self + 0x100) == (UInt8 *)0x0) || ((flags & 1) == 0)) {
    result = 0xe00002c7;
  }
  else {
    local_scale_buf[2] = (UInt16)xScale;
    local_scale_buf[3] = (UInt16)yScale;
    local_scale_buf[1] = 0;
    local_scale_buf[0] = 0;
    local_scale_buf[4] = local_scale_buf[2];
    local_scale_buf[5] = local_scale_buf[3];
    result = ((IOATIR500Surface *)(M<UInt8 *>(self + 0x100)))->set_scaling(flags >> 2 & 1 | flags & 2,
                       (IOAccelSurfaceScaling *)local_scale_buf);
  }
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 0x94) + 0x840));
  return result;
}
