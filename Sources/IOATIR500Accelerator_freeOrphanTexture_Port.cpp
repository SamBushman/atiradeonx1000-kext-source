/*
 * IOATIR500Accelerator_freeOrphanTexture_Port.cpp
 *
 * IOATIR500Accelerator::freeOrphanTexture (real addr 0x3680, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0x3680 */
void IOATIR500Accelerator::freeOrphanTexture(bool aggressive) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 bufferType;
  bool blockedOnce;
  SInt32 iVar3;
  UInt32 in_register_00000010;
  UInt32 stamp;
  SInt32 waitStat;
  UInt8 *texvert;
  UInt8 notAggressive;
  
  texvert = M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_next);
  if (texvert == (UInt8 *)(self + kIOATIR500Accelerator_orphanTextureList)) {
    return;
  }
  notAggressive = (((UInt32)aggressive) == 0) << 1;
  blockedOnce = false;
  while( true ) {
    bufferType = texvert[0x20];
    if ((bufferType == 0x3) || (bufferType == 0x7)) {
      stamp = M<UInt32>(M<SInt32>(texvert + 0x14) + 0xc);
    }
    else {
      if (1 < (UInt8)((char)bufferType - 4U)) {
        return;
      }
      stamp = M<UInt32>(M<SInt32>(texvert + 0x14) + 8);
    }
    if ((bool)(notAggressive >> 1 & 1)) {
      iVar3 = VCALL(M<SInt32>(self), 0x554)(self,stamp);
      if (iVar3 == 0) {
        if (self[0x82] != 0x0) {
          return;
        }
        VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorTimer), 300)(M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorTimer),100);
        self[0x82] = 0x1;
        return;
      }
    }
    else {
      /* #155 follow-up FIX (2026-10-11): stock's own disassembly (real addr 0x3680+0x7c) shows r4
       * still holding stamp (loaded a few instructions earlier for the branch above) live across
       * this call - waitForTimeStamp(UInt32) genuinely takes stamp as its target stamp here, not
       * just `self`. Our port never wrote it explicitly, so an unoptimized (-O0) build can't rely
       * on the same register-reuse coincidence stock's optimized build gets for free. Confirmed
       * benign in practice: self+0x790 (the only consumer of this call's return value) is a purely
       * cosmetic IOKit performance-stat property (IOATIR500Accelerator_StopGartStats.cpp's
       * writePerformanceStats), not used in any control-flow decision - but a real, independently
       * verified dropped-argument bug, same class as removeEventSource()/IOLockFree/free_texvert. */
      waitStat = M<SInt32>(self + kIOATIR500Accelerator_removeFromGARTWaitTime);
      iVar3 = VCALL(M<SInt32>(self), 0x54c)(self, stamp);
      M<SInt32>(self + kIOATIR500Accelerator_removeFromGARTWaitTime) = waitStat + iVar3;
    }
    if (blockedOnce) {
      GH_thread_block(0);
    }
    IOATIR500Shared::free_texvert(this, (IOTextureBuffer *)texvert);
    texvert = M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_next);
    if (texvert == (UInt8 *)(self + kIOATIR500Accelerator_orphanTextureList)) break;
    blockedOnce = true;
  }
  return;
}
