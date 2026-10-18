/*
 * IOATIR500Accelerator_setup_stereo_Port.cpp
 *
 * IOATIR500Accelerator::setup_stereo (real addr 0x5460, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_memcpy(...) asm("_memcpy");


/* real addr 0x5460 */
IOReturn IOATIR500Accelerator::setup_stereo(UInt32 panel, UInt32 stereoMode) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 panelOffset;
  SInt32 oldBufferCount;
  SInt32 result;
  UInt8 *surface;
  
  if (self[0x81] != 0x0) {
    M<UInt32>(self + panel * 4 + 0x124) = stereoMode;
    return 0;
  }
  panelOffset = panel * 4;
  if (M<UInt32>(self + panelOffset + 0x11c) == stereoMode) {
    return 0;
  }
  oldBufferCount = M<SInt32>(self + panelOffset + 0x114);
  if ((stereoMode & 1) == 0) {
    stereoMode = stereoMode & 0xfffffffd;
  }
  else {
    if (M<SInt32>(self + panel * 0x78 + 0x1ac) == 0) {
      GH_memcpy(self + panel * 0x78 + 0x1a4,self + panel * 0x78 + 300,0x78);
      M<UInt32>(self + panel * 0x78 + 0x1b0) = 0;
      M<UInt32>(self + panel * 0x78 + 0x1a4) = 0;
      M<UInt32>(self + panel * 0x78 + 0x1a8) = 0;
      M<UInt32>(self + panel * 0x78 + 0x1ac) = 0;
      result = VCALL(M<SInt32>(self), 0x56c)
                        (self,(UInt8 *)(self + panel * 0x78 + 0x1a4));
      if ((result == 0) &&
         (result = this->freeToAllocSurfaceVRAM((IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Surface *)((UInt8 *)0x0),
                             (VendorTextureBuffer **)((UInt8 **)0x0),0,
                             (ATIR500SurfaceBuffer *)((UInt8 *)(self + panel * 0x78 + 0x1a4))), result == 0))
      {
        result = -0x1ffffd43;
        goto LAB_0000561c;
      }
    }
    M<UInt32>(self + panelOffset + 0x114) = 2;
  }
  if (((stereoMode ^ M<UInt32>(self + panelOffset + 0x11c)) & 2) == 0) {
    result = 0;
LAB_000055e0:
    if ((stereoMode & 1) == 0) goto LAB_000055e8;
  }
  else {
    VCALL(M<SInt32>(self), 0x54c)(self,M<SInt32>(self + kIOATIR500Accelerator_submitStamp) + -1);
    result = VCALL(M<SInt32>(self), 0x5cc)(self,panel,stereoMode);
    if (result == 0) goto LAB_000055e0;
    stereoMode = 0;
LAB_000055e8:
    if (M<SInt32>(self + panel * 0x78 + 0x1ac) != 0) {
      ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->dealloc((GLKMemoryElement *)((UInt8 *)(self + panel * 0x78 + 0x1a4)));
    }
    M<UInt32>(self + panelOffset + 0x114) = 1;
  }
  M<UInt32>(self + panelOffset + 0x11c) = stereoMode;
LAB_0000561c:
  if ((oldBufferCount != M<SInt32>(self + panelOffset + 0x114)) &&
     (surface = M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead), surface != (UInt8 *)0x0)) {
    do {
      ((IOATIR500Surface *)(surface))->freeAllSwapBuffers(panel);
      ((IOATIR500Surface *)(surface))->allocMasterSwapBuffer(panel, 0x9000);
      ((IOATIR500Surface *)(surface))->allocAllSlaveSwapBuffers(panel, 0x9000);
      surface = M<UInt8 *>(surface + 0x9c);
    } while (surface != M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead));
  }
  return result;
}
