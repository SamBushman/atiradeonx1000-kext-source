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
IOReturn IOATIR500Accelerator::setup_stereo(UInt32 param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  UInt8 *this_00;
  
  if (self[0x81] != 0x0) {
    M<UInt32>(self + param_1 * 4 + 0x124) = param_2;
    return 0;
  }
  iVar1 = param_1 * 4;
  if (M<UInt32>(self + iVar1 + 0x11c) == param_2) {
    return 0;
  }
  iVar2 = M<SInt32>(self + iVar1 + 0x114);
  if ((param_2 & 1) == 0) {
    param_2 = param_2 & 0xfffffffd;
  }
  else {
    if (M<SInt32>(self + param_1 * 0x78 + 0x1ac) == 0) {
      GH_memcpy(self + param_1 * 0x78 + 0x1a4,self + param_1 * 0x78 + 300,0x78);
      M<UInt32>(self + param_1 * 0x78 + 0x1b0) = 0;
      M<UInt32>(self + param_1 * 0x78 + 0x1a4) = 0;
      M<UInt32>(self + param_1 * 0x78 + 0x1a8) = 0;
      M<UInt32>(self + param_1 * 0x78 + 0x1ac) = 0;
      iVar3 = VCALL(M<SInt32>(self), 0x56c)
                        (self,(UInt8 *)(self + param_1 * 0x78 + 0x1a4));
      if ((iVar3 == 0) &&
         (iVar3 = this->freeToAllocSurfaceVRAM((IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Surface *)((UInt8 *)0x0),
                             (VendorTextureBuffer **)((UInt8 **)0x0),0,
                             (ATIR500SurfaceBuffer *)((UInt8 *)(self + param_1 * 0x78 + 0x1a4))), iVar3 == 0))
      {
        iVar3 = -0x1ffffd43;
        goto LAB_0000561c;
      }
    }
    M<UInt32>(self + iVar1 + 0x114) = 2;
  }
  if (((param_2 ^ M<UInt32>(self + iVar1 + 0x11c)) & 2) == 0) {
    iVar3 = 0;
LAB_000055e0:
    if ((param_2 & 1) == 0) goto LAB_000055e8;
  }
  else {
    VCALL(M<SInt32>(self), 0x54c)(self,M<SInt32>(self + 0x50) + -1);
    iVar3 = VCALL(M<SInt32>(self), 0x5cc)(self,param_1,param_2);
    if (iVar3 == 0) goto LAB_000055e0;
    param_2 = 0;
LAB_000055e8:
    if (M<SInt32>(self + param_1 * 0x78 + 0x1ac) != 0) {
      ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)((UInt8 *)(self + param_1 * 0x78 + 0x1a4)));
    }
    M<UInt32>(self + iVar1 + 0x114) = 1;
  }
  M<UInt32>(self + iVar1 + 0x11c) = param_2;
LAB_0000561c:
  if ((iVar2 != M<SInt32>(self + iVar1 + 0x114)) &&
     (this_00 = M<UInt8 *>(self + 0x5c), this_00 != (UInt8 *)0x0)) {
    do {
      ((IOATIR500Surface *)(this_00))->freeAllSwapBuffers(param_1);
      ((IOATIR500Surface *)(this_00))->allocMasterSwapBuffer(param_1, 0x9000);
      ((IOATIR500Surface *)(this_00))->allocAllSlaveSwapBuffers(param_1, 0x9000);
      this_00 = M<UInt8 *>(this_00 + 0x9c);
    } while (this_00 != M<UInt8 *>(self + 0x5c));
  }
  return iVar3;
}
