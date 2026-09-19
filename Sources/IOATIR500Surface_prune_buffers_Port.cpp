/*
 * IOATIR500Surface_prune_buffers_Port.cpp
 *
 * IOATIR500Surface::prune_buffers (real addr 0x12e80, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12e80 */
void IOATIR500Surface::prune_buffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  UInt32 uVar5;
  UInt8 *pIVar6;
  
  if ((M<UInt32>(self + 0xbe8) & 0x20) == 0) {
    uVar5 = M<UInt32>(self + 0xc18);
    if ((uVar5 & 2) == 0) {
      M<UInt8 *>(self + 0xb84) = self + 0x300;
      M<UInt8 *>(self + 0xb80) = self + 0x300;
      iVar4 = M<SInt32>(self + 0xc14) * 0x78 + M<SInt32>(self + 0xd50) + 300;
      M<SInt32>(self + 0xb70) = iVar4;
      M<SInt32>(self + 0xb74) = iVar4;
    }
    else if (M<SInt32>(self + 0xb74) == M<SInt32>(self + 0xb70)) {
      M<UInt8 *>(self + 0xb74) = self + 0x120;
      M<UInt8 *>(self + 0xb80) = self + 0x288;
    }
    goto LAB_00012fec;
  }
  uVar5 = M<UInt32>(self + 0xc18);
  if ((uVar5 & 1) == 0) {
    if ((uVar5 & 2) == 0) {
      uVar3 = M<UInt32>(self + 0xbf8);
      if ((uVar3 & 2) != 0) {
        uVar2 = M<UInt32>(self + 0xc1c) | 1;
        M<UInt32>(self + 0xc1c) = uVar2;
        goto LAB_00012f00;
      }
    }
    else {
      uVar3 = M<UInt32>(self + 0xbf8);
    }
    uVar2 = M<UInt32>(self + 0xc1c) | 2;
    M<UInt32>(self + 0xc1c) = uVar2;
  }
  else {
    uVar3 = M<UInt32>(self + 0xbf8);
    uVar2 = M<UInt32>(self + 0xc1c) | 1;
    M<UInt32>(self + 0xc1c) = uVar2;
  }
LAB_00012f00:
  uVar5 = uVar5 | uVar2;
  M<UInt32>(self + 0xc18) = uVar5;
  if ((uVar5 & 1) == 0) {
    M<UInt8 *>(self + 0xb70) = self + 0x120;
  }
  else {
    M<UInt8 *>(self + 0xb70) = self + 0xa8;
  }
  if ((uVar5 & 2) == 0) {
    M<UInt8 *>(self + 0xb74) = self + 0xa8;
  }
  else {
    M<UInt8 *>(self + 0xb74) = self + 0x120;
  }
  if ((M<UInt32>(self + 0xbe8) & 0x10) != 0) {
    if ((uVar5 & 0x20) == 0) {
      M<UInt8 *>(self + 0xb84) = self + 0x288;
    }
    else {
      M<UInt8 *>(self + 0xb84) = self + 0x300;
    }
    if ((uVar5 & 0x10) == 0) {
      M<UInt8 *>(self + 0xb80) = self + 0x300;
    }
    else {
      M<UInt8 *>(self + 0xb80) = self + 0x288;
    }
  }
  M<UInt32>(self + 0xbf8) = uVar3 | 0x10000000;
LAB_00012fec:
  uVar3 = 0;
  pIVar6 = self;
  while( true ) {
    if ((1 << (uVar3 & 0x3f) & uVar5) == 0) {
      VCALL(M<SInt32>(self), 0x5cc)(self,uVar3);
      if (M<SInt32>(pIVar6 + 0xcc) != 0) {
        this->free_buffer_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(self + uVar3 * 0x78 + 0xa8)));
      }
      if (M<SInt32>(pIVar6 + 0xb8) != 0) {
        M<UInt16>(pIVar6 + 0xbc) = 0;
        M<UInt16>(pIVar6 + 0xbe) = 0;
        M<UInt16>(pIVar6 + 0xc0) = 0;
        M<UInt16>(pIVar6 + 0xc4) = 0;
        pIVar6[0xe4] = 0x0;
        pIVar6[0xdc] = 0x0;
        pIVar6[0xdd] = 0x0;
        pIVar6[0xde] = 0x0;
        pIVar6[0xe0] = 0x0;
        pIVar6[0xe1] = 0x0;
        pIVar6[0xdf] = 0xff;
        M<UInt16>(pIVar6 + 0xc6) = 0;
        M<UInt16>(pIVar6 + 200) = 1;
        M<UInt16>(pIVar6 + 0xca) = 1;
        M<UInt32>(pIVar6 + 0xa8) = 0;
        M<UInt32>(pIVar6 + 0xac) = 0;
        M<UInt32>(pIVar6 + 0xb0) = 0;
        M<UInt32>(pIVar6 + 0xb4) = 0;
        M<UInt32>(pIVar6 + 0xb8) = 0;
        M<UInt32>(pIVar6 + 0xcc) = 0;
        M<UInt32>(pIVar6 + 0xd0) = 0xffffffff;
        M<UInt32>(pIVar6 + 0xd4) = 0;
        M<UInt32>(pIVar6 + 0xd8) = 0;
        pIVar6[0xe3] = 0x6;
        M<UInt32>(self + uVar3 * 0x78 + 0xe4) =
             M<UInt32>(self + uVar3 * 0x78 + 0xe4) & 0xff0007ff | 0x111000;
        M<UInt32>(pIVar6 + 0xec) = 0;
        M<UInt32>(pIVar6 + 0xe8) = 0;
      }
    }
    bVar1 = uVar3 == 0x16;
    pIVar6 = pIVar6 + 0x78;
    uVar3 = uVar3 + 1;
    if (bVar1) break;
    uVar5 = M<UInt32>(self + 0xc18);
  }
  VCALL(M<SInt32>(self), 0x5c8)(self);
  if (M<SInt32>(self + 0xc14) == 0xffff) {
    iVar4 = M<SInt32>(self + 0xd50);
  }
  else {
    iVar4 = M<SInt32>(self + 0xd50);
    if (self == M<UInt8 *>(M<SInt32>(self + 0xc14) * 0x20 + iVar4 + 0xe8)) {
      VCALL(M<SInt32>(self), 0x5a4)(self);
      iVar4 = M<SInt32>(self + 0xd50);
    }
  }
  M<UInt32>(iVar4 + 0x78) = 0;
  return;
}
