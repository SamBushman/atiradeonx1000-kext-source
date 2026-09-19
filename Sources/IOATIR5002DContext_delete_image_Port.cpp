/*
 * IOATIR5002DContext_delete_image_Port.cpp
 *
 * IOATIR5002DContext::delete_image (real addr 0xd450, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0xd450 */
IOReturn IOATIR5002DContext::delete_image(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *this_00;
  UInt8 *pVVar1;
  int iVar2;
  ATIR500SurfaceBuffer *pAVar3;
  UInt32 uVar4;
  
  GH_IOLockLock(M<UInt32>(M<int>(self + 0x94) + 0x840));
  this_00 = M<UInt8 *>(self + 0x88);
  if (this_00 == (UInt8 *)0x0) {
    uVar4 = 0xe00002be;
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x94) + 0x840));
  }
  else if ((param_1 < M<unsigned int>(this_00 + 0x14)) &&
          (pVVar1 = M<UInt8 *>(param_1 * 4 + M<int>(this_00 + 0x10)),
          pVVar1 != (UInt8 *)0x0)) {
    if (M<UInt8 *>(self + 0x114) == pVVar1) {
      M<UInt32>(self + 0x114) = 0;
    }
    if (M<int>(self + 0x100) != 0) {
      pAVar3 = M<ATIR500SurfaceBuffer *>(M<int>(self + 0x100) + 0xb70);
      iVar2 = M<int>(pAVar3 + 0x24);
      if ((iVar2 != 0) && (M<int>(iVar2 + 8) == M<int>(pVVar1 + 8))) {
        M<UInt8>(iVar2 + 0x59) = 0;
        ((IOATIR500Surface *)(M<UInt8 *>(self + 0x100)))->free_buffer_backing_store((ATIR500SurfaceBuffer *)(pAVar3));
        this_00 = M<UInt8 *>(self + 0x88);
      }
    }
    uVar4 = ((IOATIR500Shared *)(this_00))->delete_texture((VendorTextureBuffer *)(pVVar1));
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x94) + 0x840));
  }
  else {
    uVar4 = 0xe00002c2;
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x94) + 0x840));
  }
  return uVar4;
}
