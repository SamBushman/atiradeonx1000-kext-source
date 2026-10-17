/*
 * IOATIR500GLContext_new_texture_Port.cpp
 *
 * IOATIR500GLContext::new_texture (real addr 0x9320, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x9320 */
IOReturn IOATIR500GLContext::new_texture(sIOGLNewTextureData *newTextureData, sIOGLNewTextureReturnData *returnData, UInt32 structSize, UInt32 *sizeOut) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);
    UInt8 *newTextureDataBytes = reinterpret_cast<UInt8 *>(newTextureData);
    UInt8 *returnDataBytes = reinterpret_cast<UInt8 *>(returnData);

  int texture;
  UInt32 result;
  
  GH_IOLockLock(M<UInt32>(M<int>(self + 200) + 0x840));
  switch(M<UInt32>(newTextureDataBytes)) {
  case 0:
    texture = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_surface_texture(M<UInt32>(newTextureDataBytes + 4),
                       M<UInt32>(newTextureDataBytes + 8),M<UInt32>(newTextureDataBytes + 0xc),(unsigned int *)(returnDataBytes + 4));
    M<UInt32>(returnDataBytes) = 0;
    break;
  case 1:
    texture = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_global_texture(M<UInt32>(newTextureDataBytes + 4),
                       (unsigned int *)(returnDataBytes + 4));
    M<UInt32>(returnDataBytes) = 0;
    break;
  case 2:
    texture = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_texture(M<UInt32>(newTextureDataBytes + 4),0,0,0,
                       (unsigned int *)returnDataBytes,(unsigned int *)(returnDataBytes + 4));
    break;
  case 3:
    texture = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_texture(M<UInt32>(newTextureDataBytes + 4),
                       M<UInt32>(newTextureDataBytes + 8),0,0,(unsigned int *)returnDataBytes,(unsigned int *)(returnDataBytes + 4));
    break;
  default:
    result = 0xe00002be;
    M<UInt32>(returnDataBytes) = 0;
    M<UInt32>(returnDataBytes + 4) = 0;
    goto LAB_000094e0;
  case 6:
    texture = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_agpref_texture(M<unsigned int>(newTextureDataBytes + 4),
                       M<unsigned int>(newTextureDataBytes + 8),M<UInt32>(newTextureDataBytes + 0xc),(unsigned int *)(returnDataBytes + 4));
    if (texture == 0) {
      M<UInt32>(returnDataBytes) = 0;
      result = 0xe00002be;
      goto LAB_000094e0;
    }
    M<UInt32>(returnDataBytes) = M<UInt32>(M<int>(texture + 0x54) + 0x58);
    goto LAB_00009410;
  case 7:
    texture = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_texture(M<UInt32>(newTextureDataBytes + 4),
                       M<UInt32>(newTextureDataBytes + 8),M<unsigned int>(newTextureDataBytes + 0xc),M<UInt32>(newTextureDataBytes + 0x10),
                       (unsigned int *)returnDataBytes,(unsigned int *)(returnDataBytes + 4));
  }
  if (texture == 0) {
    result = 0xe00002be;
  }
  else {
LAB_00009410:
    result = 0;
    VCALL(M<int>(self), 0x5c0)(self,texture);
  }
LAB_000094e0:
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
  return result;
}
