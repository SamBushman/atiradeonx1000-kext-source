/*
 * IOATIR500DVDContext_stop_Port.cpp
 *
 * IOATIR500DVDContext::stop (real addr 0xe3a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDesc(...) asm("__ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDescriptor");


/* real addr 0xe3a0 */
void IOATIR500DVDContext::stop(IOService *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 *pIVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  UInt8 *pIVar5;
  
  M<UInt32>(self + 0xfc) = 0;
  piVar2 = M<int *>(self + 0x8c);
  pIVar5 = (UInt8 *)piVar2[0x1a];
  if (self == (UInt8 *)piVar2[0x1a]) {
    piVar2[0x1a] = M<int>(self + 0x80);
    piVar2 = M<int *>(self + 0x8c);
    if ((piVar2[0x1a] == 0) && (piVar2[0x18] == 0)) {
      VCALL(*piVar2, 0x538)(piVar2);
      piVar2 = M<int *>(self + 0x8c);
    }
  }
  else {
    do {
      pIVar1 = pIVar5;
      pIVar5 = M<UInt8 *>(pIVar1 + 0x80);
      if (pIVar5 == (UInt8 *)0x0) break;
    } while (self != pIVar5);
    M<UInt32>(pIVar1 + 0x80) = M<UInt32>(self + 0x80);
  }
  piVar2[0x1cf] = piVar2[0x1cf] + -1;
  M<UInt32>(M<int>(self + 0x8c) + 0x5c8) = 0x20000;
  if (M<int>(self + 0x98) != 0) {
    iVar3 = M<int>(self + 0x8c);
    iVar4 = M<int>(iVar3 + 0x60);
    if (iVar4 == 0) {
      if (M<int>(iVar3 + 0x68) == 0) goto LAB_0000e548;
    }
    else {
      while( true ) {
        if (M<unsigned int>(iVar3 + 0x5c8) < M<unsigned int>(iVar4 + 0xb0)) {
          M<unsigned int>(iVar3 + 0x5c8) = M<unsigned int>(iVar4 + 0xb0);
        }
        piVar2 = (int *)GH_ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDesc(iVar4,M<UInt32>(self + 0x98));
        if (piVar2 != (int *)0x0) {
          VCALL(*piVar2, 0x18)(piVar2);
        }
        iVar4 = M<int>(iVar4 + 0x80);
        if (iVar4 == 0) break;
        iVar3 = M<int>(self + 0x8c);
      }
      iVar3 = M<int>(self + 0x8c);
    }
    iVar4 = M<int>(iVar3 + 0x68);
    if (iVar4 != 0) {
      while( true ) {
        if (M<unsigned int>(iVar3 + 0x5c8) < 0x80000) {
          M<UInt32>(iVar3 + 0x5c8) = 0x80000;
        }
        piVar2 = (int *)GH_ZN12IOUserClient26removeMappingForDescriptorEP18IOMemoryDesc(iVar4,M<UInt32>(self + 0x98));
        if (piVar2 != (int *)0x0) {
          VCALL(*piVar2, 0x18)(piVar2);
        }
        iVar4 = M<int>(iVar4 + 0x80);
        if (iVar4 == 0) break;
        iVar3 = M<int>(self + 0x8c);
      }
    }
  }
LAB_0000e548:
  if (M<int>(self + 0xb4) != 0) {
    this->freeAllContextBuffers();
  }
  if (M<int>(self + 0x98) != 0) {
    ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0x8c)))->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + 0x90)));
  }
  if (self == M<UInt8 *>(M<int>(self + 0x8c) + 0x78)) {
    M<UInt32>(M<int>(self + 0x8c) + 0x78) = 0;
  }
  if (M<UInt8 *>(self + 0xf8) != (UInt8 *)0x0) {
    ((IOATIR500Surface *)(M<UInt8 *>(self + 0xf8)))->remove_dvd_context((IOATIR500DVDContext *)(self));
    ((IOATIR500Surface *)(M<UInt8 *>(self + 0xf8)))->prune_buffers();
    M<UInt32>(self + 0xf8) = 0;
  }
  if (M<int>(self + 0x84) != 0) {
    pIVar5 = self;
    do {
      if (M<int>(pIVar5 + 0x104) != 0) {
        iVar3 = GH_OSDecrementAtomic(M<int>(M<int>(pIVar5 + 0x104) + 0x14) + 0x10);
        if (iVar3 == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + 0x84)))->delete_texture((VendorTextureBuffer *)(M<UInt8 *>(pIVar5 + 0x104)));
        }
        M<UInt32>(pIVar5 + 0x104) = 0;
      }
      pIVar5 = pIVar5 + 4;
    } while (pIVar5 != self + 0x48);
    VCALL(*M<int *>(self + 0x84), 0x18)(M<int *>(self + 0x84));
    M<UInt32>(self + 0x84) = 0;
  }
  IOUserClient::stop(real_param_1);   /* the shipped body tail-calls the base class (SUB_60000000 = its lazy-binding stub) */
  return;
}
