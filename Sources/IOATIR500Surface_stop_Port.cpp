/*
 * IOATIR500Surface_stop_Port.cpp
 *
 * IOATIR500Surface::stop (real addr 0x134b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFreeAligned(...) asm("_IOFreeAligned");


/* real addr 0x134b0 */
void IOATIR500Surface::stop(IOService *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  bool bVar1;
  UInt8 IVar2;
  UInt8 *this_00;
  UInt8 *this_01;
  UInt8 *pIVar3;
  UInt8 *pIVar4;
  SInt32 *piVar5;
  SInt32 iVar6;
  SInt32 iVar7;
  UInt32 uVar8;
  UInt8 *pIVar9;
  UInt8 *pIVar10;
  
  M<UInt32>(self + 0xd58) = 0;
  iVar6 = M<SInt32>(self + 0x9c);
  iVar7 = M<SInt32>(self + 0xd50);
  M<UInt32>(iVar6 + 0xa0) = M<UInt32>(self + 0xa0);
  M<SInt32>(M<SInt32>(self + 0xa0) + 0x9c) = iVar6;
  if (self == M<UInt8 *>(iVar7 + 0x5c)) {
    if (self == M<UInt8 *>(self + 0x9c)) {
      M<UInt32>(iVar7 + 0x5c) = 0;
      iVar7 = M<SInt32>(self + 0xd50);
    }
    else {
      M<UInt8 *>(iVar7 + 0x5c) = M<UInt8 *>(self + 0x9c);
      iVar7 = M<SInt32>(self + 0xd50);
    }
  }
  M<SInt32>(iVar7 + 0x730) = M<SInt32>(iVar7 + 0x730) + -1;
  if (M<SInt32>(self + 0xd48) != 0) {
    iVar6 = M<SInt32>(M<SInt32>(self + 0xd50) + 0x21c);
    if (iVar6 != 0) {
      M<SInt32>(M<SInt32>(self + 0xd50) + 0x21c) = iVar6 + -1;
    }
  }
  iVar6 = M<SInt32>(self + 0xbcc);
  while (iVar6 != 0) {
    M<UInt32>(iVar6 + 0x50) = 0;
    M<UInt8>(M<SInt32>(iVar6 + 0x14) + 0x14) = 1;
    M<UInt32>(self + 0xbcc) = M<UInt32>(iVar6 + 0x54);
    M<UInt32>(iVar6 + 0x54) = 0;
    iVar6 = M<SInt32>(self + 0xbcc);
  }
  if ((M<SInt32>(self + 0xc14) != 0xffff) &&
     (self == M<UInt8 *>(M<SInt32>(self + 0xc14) * 0x20 + M<SInt32>(self + 0xd50) + 0xe8))
     ) {
    VCALL(M<SInt32>(self), 0x5a8)(self);
    M<UInt32>(M<SInt32>(self + 0xc14) * 0x20 + M<SInt32>(self + 0xd50) + 0xe8) = 0;
    M<UInt32>(self + 0xc14) = 0xffff;
  }
  IVar2 = self[0xbd0];
  if (IVar2 != 0x0) {
    if (IVar2 == 0x3) {
      iVar6 = M<SInt32>(self + 0xb70);
      if (M<SInt32>(self + 0xd8c) == 0) {
        iVar7 = M<SInt32>(iVar6 + 0x24);
        if ((iVar7 != 0) && (piVar5 = M<SInt32 *>(iVar7 + 0x10), piVar5 != (SInt32 *)0x0)) {
          VCALL(*piVar5, 0x18)(piVar5);
          M<UInt32>(M<SInt32>(iVar6 + 0x24) + 0x10) = 0;
        }
      }
      else {
        this->free_buffer_backing_orphans();
      }
    }
    else if (IVar2 == 0x1) {
      VCALL(M<SInt32>(self), 0x600)(self,M<UInt32>(self + 0xb70));
    }
    self[0xbd0] = 0x0;
  }
  if (M<SInt32 *>(self + 0xd84) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0xd84), 0x18)(M<SInt32 *>(self + 0xd84));
    M<UInt32>(self + 0xd84) = 0;
  }
  if (M<SInt32 *>(self + 0xd88) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0xd88), 0x18)(M<SInt32 *>(self + 0xd88));
    M<UInt32>(self + 0xd88) = 0;
  }
  this_00 = M<UInt8 *>(self + 0x88);
  while (this_00 != (UInt8 *)0x0) {
    ((IOATIR500GLContext *)(this_00))->remove_surface();
    pIVar3 = M<UInt8 *>(this_00 + 0x84);
    M<UInt32>(this_00 + 0x84) = 0;
    this_00 = pIVar3;
  }
  this_01 = M<UInt8 *>(self + 0x8c);
  while (this_01 != (UInt8 *)0x0) {
    ((IOATIR5002DContext *)(this_01))->remove_surface();
    pIVar4 = M<UInt8 *>(this_01 + 0x84);
    M<UInt32>(this_01 + 0x84) = 0;
    this_01 = pIVar4;
  }
  if (M<UInt8 *>(self + 0x90) != (UInt8 *)0x0) {
    ((IOATIR500DVDContext *)(M<UInt8 *>(self + 0x90)))->remove_surface();
  }
  iVar6 = 0;
  pIVar9 = self;
  do {
    VCALL(M<SInt32>(self), 0x5cc)(self,iVar6);
    if (M<UInt8 *>(pIVar9 + 0xcc) != (UInt8 *)0x0) {
      this->delete_buffer_backing((IOTextureBuffer *)(M<UInt8 *>(pIVar9 + 0xcc)));
      M<UInt32>(pIVar9 + 0xcc) = 0;
    }
    bVar1 = iVar6 != 0x16;
    pIVar9 = pIVar9 + 0x78;
    iVar6 = iVar6 + 1;
  } while (bVar1);
  if (M<SInt32>(M<SInt32>(self + 0xd50) + 0xcc) != 0) {
    uVar8 = 0;
    pIVar9 = self;
    pIVar10 = self;
    do {
      if (M<SInt32>(pIVar9 + 0xc28) != 0) {
        this->freeAllSwapBuffers(uVar8);
      }
      if (M<SInt32>(pIVar10 + 0xd60) != 0) {
        GH_IOFreeAligned(M<SInt32>(pIVar10 + 0xd60),M<UInt32>(pIVar10 + 0xd64));
        iVar6 = M<SInt32>(self + 0xd50);
        if (iVar6 != 0) {
          M<SInt32>(iVar6 + 0x804) = M<SInt32>(iVar6 + 0x804) - M<SInt32>(pIVar10 + 0xd64);
        }
        M<UInt32>(pIVar10 + 0xd64) = 0;
        M<UInt32>(pIVar10 + 0xd60) = 0;
      }
      uVar8 = uVar8 + 1;
      pIVar9 = pIVar9 + 0x94;
      pIVar10 = pIVar10 + 8;
    } while (uVar8 < M<UInt32>(M<SInt32>(self + 0xd50) + 0xcc));
  }
  if (M<SInt32>(self + 0xd8c) != 0) {
    this->free_buffer_backing_orphans();
  }
  IOUserClient::stop(real_param_1);
  return;
}
