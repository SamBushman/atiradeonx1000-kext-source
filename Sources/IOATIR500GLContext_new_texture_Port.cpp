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
IOReturn IOATIR500GLContext::new_texture(sIOGLNewTextureData *real_param_2, sIOGLNewTextureReturnData *real_param_3, UInt32 param_4, UInt32 *param_5) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);
    UInt8 *param_3 = reinterpret_cast<UInt8 *>(real_param_3);

  int iVar1;
  UInt32 uVar2;
  
  GH_IOLockLock(M<UInt32>(M<int>(self + 200) + 0x840));
  switch(M<UInt32>(param_2)) {
  case 0:
    iVar1 = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_surface_texture(M<UInt32>(param_2 + 4),
                       M<UInt32>(param_2 + 8),M<UInt32>(param_2 + 0xc),(unsigned int *)(param_3 + 4));
    M<UInt32>(param_3) = 0;
    break;
  case 1:
    iVar1 = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_global_texture(M<UInt32>(param_2 + 4),
                       (unsigned int *)(param_3 + 4));
    M<UInt32>(param_3) = 0;
    break;
  case 2:
    iVar1 = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_texture(M<UInt32>(param_2 + 4),0,0,0,
                       (unsigned int *)param_3,(unsigned int *)(param_3 + 4));
    break;
  case 3:
    iVar1 = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_texture(M<UInt32>(param_2 + 4),
                       M<UInt32>(param_2 + 8),0,0,(unsigned int *)param_3,(unsigned int *)(param_3 + 4));
    break;
  default:
    uVar2 = 0xe00002be;
    M<UInt32>(param_3) = 0;
    M<UInt32>(param_3 + 4) = 0;
    goto LAB_000094e0;
  case 6:
    iVar1 = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_agpref_texture(M<unsigned int>(param_2 + 4),
                       M<unsigned int>(param_2 + 8),M<UInt32>(param_2 + 0xc),(unsigned int *)(param_3 + 4));
    if (iVar1 == 0) {
      M<UInt32>(param_3) = 0;
      uVar2 = 0xe00002be;
      goto LAB_000094e0;
    }
    M<UInt32>(param_3) = M<UInt32>(M<int>(iVar1 + 0x54) + 0x58);
    goto LAB_00009410;
  case 7:
    iVar1 = (int)((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->new_texture(M<UInt32>(param_2 + 4),
                       M<UInt32>(param_2 + 8),M<unsigned int>(param_2 + 0xc),M<UInt32>(param_2 + 0x10),
                       (unsigned int *)param_3,(unsigned int *)(param_3 + 4));
  }
  if (iVar1 == 0) {
    uVar2 = 0xe00002be;
  }
  else {
LAB_00009410:
    uVar2 = 0;
    VCALL(M<int>(self), 0x5c0)(self,iVar1);
  }
LAB_000094e0:
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 200) + 0x840));
  return uVar2;
}
