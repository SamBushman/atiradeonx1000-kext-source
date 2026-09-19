/*
 * IOATIR500GLContext_stop_Port.cpp
 *
 * IOATIR500GLContext::stop (real addr 0x7fa0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");


/* real addr 0x7fa0 */
void IOATIR500GLContext::stop(IOService *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 *pIVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  SInt32 *piVar4;
  UInt8 *this_00;
  UInt8 *pVVar5;
  SInt32 iVar6;
  UInt8 *pVVar7;
  UInt8 *pIVar8;
  
  M<UInt32>(self + 0x294) = 0;
  piVar4 = M<SInt32 *>(self + 200);
  pIVar8 = (UInt8 *)piVar4[0x18];
  if (self == (UInt8 *)piVar4[0x18]) {
    piVar4[0x18] = M<SInt32>(self + 0x80);
    piVar4 = M<SInt32 *>(self + 200);
    if ((piVar4[0x18] == 0) && (piVar4[0x1a] == 0)) {
      VCALL(*piVar4, 0x538)(piVar4);
      piVar4 = M<SInt32 *>(self + 200);
    }
  }
  else {
    do {
      pIVar1 = pIVar8;
      pIVar8 = M<UInt8 *>(pIVar1 + 0x80);
      if (pIVar8 == (UInt8 *)0x0) break;
    } while (self != pIVar8);
    M<UInt32>(pIVar1 + 0x80) = M<UInt32>(self + 0x80);
  }
  piVar4[0x1ce] = piVar4[0x1ce] + -1;
  M<UInt32>(M<SInt32>(self + 200) + 0x5c8) = 0x20000;
  this->freeCommandBuffer();
  M<UInt32>(M<SInt32>(self + 200) + 0x5d8) = 0x10000;
  this_00 = M<UInt8 *>(self + 200);
  iVar6 = M<SInt32>(this_00 + 0x5cc);
  if (iVar6 != 0) {
    do {
      if ((M<SInt32 *>(iVar6 + 0x10) != (SInt32 *)0x0) &&
         (iVar3 = VCALL(*M<SInt32 *>(iVar6 + 0x10), 0xdc)(M<SInt32 *>(iVar6 + 0x10)), iVar3 == M<SInt32>(self + 0x78)))
      {
        VCALL(*M<SInt32 *>(iVar6 + 0x10), 0x18)(M<SInt32 *>(iVar6 + 0x10));
        M<UInt32>(iVar6 + 0x10) = 0;
      }
      iVar6 = M<SInt32>(iVar6 + 0x3c);
    } while (iVar6 != 0);
    this_00 = M<UInt8 *>(self + 200);
  }
  pVVar7 = M<UInt8 *>(self + 0xe8);
  if (pVVar7 != (UInt8 *)0x0) {
    while( true ) {
      pVVar5 = M<UInt8 *>(pVVar7 + 0x3c);
      if (M<UInt32>(this_00 + 0x5d4) < 0x10) {
        if (M<SInt32>(this_00 + 0x5d0) == 0) {
          M<UInt8 *>(this_00 + 0x5cc) = pVVar7;
          M<UInt8 *>(M<SInt32>(self + 200) + 0x5d0) = pVVar7;
          M<UInt32>(pVVar7 + 0x3c) = 0;
        }
        else {
          M<UInt8 *>(M<SInt32>(this_00 + 0x5d0) + 0x3c) = pVVar7;
          M<UInt8 *>(M<SInt32>(self + 200) + 0x5d0) = pVVar7;
          M<UInt32>(pVVar7 + 0x3c) = 0;
        }
        M<SInt32>(M<SInt32>(self + 200) + 0x5d4) = M<SInt32>(M<SInt32>(self + 200) + 0x5d4) + 1;
        pVVar7[0x54] = 0x0;
        if (M<SInt32 *>(pVVar7 + 0x10) != (SInt32 *)0x0) {
          VCALL(*M<SInt32 *>(pVVar7 + 0x10), 0x18)(M<SInt32 *>(pVVar7 + 0x10));
          M<UInt32>(pVVar7 + 0x10) = 0;
        }
      }
      else {
        ((IOATIR500Accelerator *)(this_00))->freeOneDataBuffer((VendorTextureBuffer *)(pVVar7));
      }
      if (pVVar5 == (UInt8 *)0x0) break;
      this_00 = M<UInt8 *>(self + 200);
      pVVar7 = pVVar5;
    }
    this_00 = M<UInt8 *>(self + 200);
  }
  M<UInt32>(self + 0xf0) = 0;
  M<UInt32>(self + 0xe8) = 0;
  M<UInt32>(self + 0xec) = 0;
  uVar2 = M<UInt32>(this_00 + 0x5d4);
  while (0xf < uVar2) {
    pVVar7 = M<UInt8 *>(this_00 + 0x5cc);
    M<UInt32>(this_00 + 0x5cc) = M<UInt32>(pVVar7 + 0x3c);
    M<SInt32>(M<SInt32>(self + 200) + 0x5d4) = M<SInt32>(M<SInt32>(self + 200) + 0x5d4) + -1;
    ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeOneDataBuffer((VendorTextureBuffer *)(pVVar7));
    this_00 = M<UInt8 *>(self + 200);
    uVar2 = M<UInt32>(this_00 + 0x5d4);
  }
  if (M<SInt32>(self + 0xfc) != 0) {
    this->freeAllContextBuffers();
  }
  if (M<SInt32>(self + 0xd4) != 0) {
    ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + 0xcc)));
  }
  if (M<SInt32 *>(self + 0xb8) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + 0xb8), 0x18)(M<SInt32 *>(self + 0xb8));
  }
  if (self == M<UInt8 *>(M<SInt32>(self + 200) + 0x78)) {
    M<UInt32>(M<SInt32>(self + 200) + 0x78) = 0;
  }
  if (M<UInt8 *>(self + 0x290) != (UInt8 *)0x0) {
    ((IOATIR500Surface *)(M<UInt8 *>(self + 0x290)))->remove_gl_context_from_list((IOATIR500GLContext *)(self));
    ((IOATIR500Surface *)(M<UInt8 *>(self + 0x290)))->prune_buffers();
    M<UInt32>(self + 0x290) = 0;
  }
  if (M<SInt32>(self + 0x88) != 0) {
    pIVar8 = self;
    do {
      if (M<SInt32>(pIVar8 + 0x2a4) != 0) {
        iVar6 = GH_OSDecrementAtomic(M<SInt32>(M<SInt32>(pIVar8 + 0x2a4) + 0x14) + 0x10);
        if (iVar6 == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + 0x88)))->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(pIVar8 + 0x2a4)));
        }
        M<UInt32>(pIVar8 + 0x2a4) = 0;
      }
      pIVar8 = pIVar8 + 4;
    } while (self + 0xa8 != pIVar8);
    VCALL(*M<SInt32 *>(self + 0x88), 0x18)(M<SInt32 *>(self + 0x88));
    M<UInt32>(self + 0x88) = 0;
  }
  IOUserClient::stop(real_param_1);
  return;
}
