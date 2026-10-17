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
IOReturn IOATIR5002DContext::delete_image(UInt32 textureID) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *shared;
  UInt8 *texture;
  int backingStore;
  UInt8 *surfaceBuffer;   /* #176: byte pointer - typed ATIR500SurfaceBuffer* scaled `surfaceBuffer + 0x24` by sizeof=0x80 */
  UInt32 result;
  
  GH_IOLockLock(M<UInt32>(M<int>(self + 0x94) + 0x840));
  shared = M<UInt8 *>(self + 0x88);
  if (shared == (UInt8 *)0x0) {
    result = 0xe00002be;
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x94) + 0x840));
  }
  else if ((textureID < M<unsigned int>(shared + 0x14)) &&
          (texture = M<UInt8 *>(textureID * 4 + M<int>(shared + 0x10)),
          texture != (UInt8 *)0x0)) {
    if (M<UInt8 *>(self + 0x114) == texture) {
      M<UInt32>(self + 0x114) = 0;
    }
    if (M<int>(self + 0x100) != 0) {
      surfaceBuffer = M<UInt8 *>(M<int>(self + 0x100) + 0xb70);
      backingStore = M<int>(surfaceBuffer + 0x24);
      if ((backingStore != 0) && (M<int>(backingStore + 8) == M<int>(texture + 8))) {
        M<UInt8>(backingStore + 0x59) = 0;
        ((IOATIR500Surface *)(M<UInt8 *>(self + 0x100)))->free_buffer_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
        shared = M<UInt8 *>(self + 0x88);
      }
    }
    result = ((IOATIR500Shared *)(shared))->delete_texture((VendorTextureBuffer *)(texture));
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x94) + 0x840));
  }
  else {
    result = 0xe00002c2;
    GH_IOLockUnlock(M<UInt32>(M<int>(self + 0x94) + 0x840));
  }
  return result;
}
