/*
 * IOATIR500Shared_free_Port.cpp
 *
 * IOATIR500Shared::free (real addr 0x184d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFree(...) asm("_IOFree");


/* real addr 0x184d0 */
void IOATIR500Shared::free() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 VVar1;
  SInt32 *piVar2;
  UInt8 *pVVar3;
  SInt32 iVar4;
  UInt8 *this_00;
  SInt32 *piVar5;
  UInt8 *pVVar6;
  
  pVVar3 = M<UInt8 *>(self + 0x24);
  iVar4 = 0;
  if (pVVar3 != (UInt8 *)0x0) {
    do {
      if (pVVar3[0x20] == 0x4) {
        pVVar6 = M<UInt8 *>(pVVar3 + 0x3c);
      }
      else {
        pVVar6 = M<UInt8 *>(pVVar3 + 0x3c);
        if (pVVar6 != (UInt8 *)0x0) {
          VVar1 = pVVar6[0x20];
          while ((VVar1 == 0x4 &&
                 (pVVar6 = M<UInt8 *>(pVVar6 + 0x3c),
                 pVVar6 != (UInt8 *)0x0))) {
            VVar1 = pVVar6[0x20];
          }
        }
        M<UInt32>(M<SInt32>(pVVar3 + 0x14) + 0x10) =
             (UInt32)M<UInt16>(M<SInt32>(pVVar3 + 0x14) + 0x12);
        this->delete_texture((VendorTextureBuffer *)(pVVar3));
      }
      pVVar3 = pVVar6;
    } while (pVVar6 != (UInt8 *)0x0);
    iVar4 = M<SInt32>(self + 0x24);
  }
  while (iVar4 != 0) {
    M<UInt32>(M<SInt32>(iVar4 + 0x14) + 0x10) = (UInt32)M<UInt16>(M<SInt32>(iVar4 + 0x14) + 0x12);
    this->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(self + 0x24)));
    iVar4 = M<SInt32>(self + 0x24);
  }
  this_00 = M<UInt8 *>(self + 0xc);
  if (self == M<UInt8 *>(this_00 + 0x6c)) {
    M<UInt32>(this_00 + 0x6c) = 0;
    M<UInt32>(M<SInt32>(self + 0xc) + 0x70) = 0;
    this_00 = M<UInt8 *>(self + 0xc);
  }
  ((IOATIR500Accelerator *)(this_00))->freeOrphanTexture(true);
  piVar2 = (SInt32 *)M<SInt32>(self + 0x20);
  while (piVar2 != (SInt32 *)0x0) {
    piVar5 = (SInt32 *)*piVar2;
    VCALL(*(SInt32 *)piVar2[3], 0x18)(piVar2[3]);
    VCALL(*(SInt32 *)piVar2[2], 0x18)(piVar2[2]);
    VCALL(*(SInt32 *)piVar2[1], 0x18)(piVar2[1]);
    GH_IOFree(piVar2,0x1c);
    iVar4 = M<SInt32>(self + 0xc);
    piVar2 = piVar5;
    if (iVar4 != 0) {
      M<SInt32>(iVar4 + 0x808) = M<SInt32>(iVar4 + 0x808) + -0x1c;
    }
  }
  this->free_handles();
  OSObject::free();
  return;
}
