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
void IOATIR500Accelerator::freeOrphanTexture(bool param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 IVar1;
  bool bVar2;
  SInt32 iVar3;
  UInt32 in_register_00000010;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt8 *pIVar6;
  UInt8 bVar7;
  
  pIVar6 = M<UInt8 *>(self + 0x664);
  if (pIVar6 == (UInt8 *)(self + 0x63c)) {
    return;
  }
  bVar7 = (((UInt32)param_1) == 0) << 1;
  bVar2 = false;
  while( true ) {
    IVar1 = pIVar6[0x20];
    if ((IVar1 == 0x3) || (IVar1 == 0x7)) {
      uVar4 = M<UInt32>(M<SInt32>(pIVar6 + 0x14) + 0xc);
    }
    else {
      if (1 < (UInt8)((char)IVar1 - 4U)) {
        return;
      }
      uVar4 = M<UInt32>(M<SInt32>(pIVar6 + 0x14) + 8);
    }
    if ((bool)(bVar7 >> 1 & 1)) {
      iVar3 = VCALL(M<SInt32>(self), 0x554)(self,uVar4);
      if (iVar3 == 0) {
        if (self[0x82] != 0x0) {
          return;
        }
        VCALL(*M<SInt32 *>(self + 0xb8), 300)(M<SInt32 *>(self + 0xb8),100);
        self[0x82] = 0x1;
        return;
      }
    }
    else {
      iVar5 = M<SInt32>(self + 0x790);
      iVar3 = VCALL(M<SInt32>(self), 0x54c)(self);
      M<SInt32>(self + 0x790) = iVar5 + iVar3;
    }
    if (bVar2) {
      GH_thread_block(0);
    }
    IOATIR500Shared::free_texvert(this, (IOTextureBuffer *)pIVar6);
    pIVar6 = M<UInt8 *>(self + 0x664);
    if (pIVar6 == (UInt8 *)(self + 0x63c)) break;
    bVar2 = true;
  }
  return;
}
