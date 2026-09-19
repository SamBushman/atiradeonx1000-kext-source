/*
 * ATIRadeonX1000_pageoff_linear_buffer_Port.cpp
 *
 * ATIRadeonX1000::pageoff_linear_buffer (real addr 0x217a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x217a0 */
UInt32 ATIRadeonX1000::pageoff_linear_buffer(VendorTextureBuffer *real_param_1, ATITextureBufferHeader *real_param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);

  SInt16 sVar3;
  int iVar1;
  int iVar2;
  int iVar4;
  int iVar5;
  UInt32 uVar6;
  UInt8 *pAVar7;
  UInt32 uVar8;
  int iVar9;
  int iVar10;
  UInt8 VVar11;
  unsigned int uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  UInt8 *pVVar16;
  int iVar17;
  int iVar18;
  
  if (param_1[0x20] == 0x3) {
    VVar11 = 0x3;
    if (M<int>(param_1 + 4) == 0) {
      iVar4 = VCALL(M<int>(self), 0x5a8)(self);
      if ((iVar4 == 0) &&
         (iVar4 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                             (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                             (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                             (VendorTransferBuffer *)((UInt8 *)param_1)), iVar4 == 0)) {
        VCALL(M<int>(self), 0x54c)(self,M<int>(self + 0x50) + -1);
        iVar4 = VCALL(M<int>(self), 0x5a8)(self,param_1);
        if ((iVar4 == 0) &&
           (iVar4 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                               (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                               (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                               (VendorTransferBuffer *)((UInt8 *)param_1)), iVar4 == 0)) {
          return 0;
        }
      }
      VVar11 = param_1[0x20];
    }
  }
  else {
    if (param_1[0x20] != 0x7) {
      return 0;
    }
    pVVar16 = M<UInt8 *>(param_1 + 0x58);
    if (((M<int>(pVVar16 + 4) == 0) &&
        (iVar4 = VCALL(M<int>(self), 0x5a8)(self,pVVar16), iVar4 == 0)) &&
       (iVar4 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                           (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                           (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),(VendorTransferBuffer *)(pVVar16)), iVar4 == 0)) {
      VCALL(M<int>(self), 0x54c)(self,M<int>(self + 0x50) + -1);
      iVar4 = VCALL(M<int>(self), 0x5a8)(self,pVVar16);
      if ((iVar4 == 0) &&
         (iVar4 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                             (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                             (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),(VendorTransferBuffer *)(pVVar16)), iVar4 == 0)) {
        return 0;
      }
    }
    iVar4 = M<int>(param_1 + 4);
    sVar3 = M<SInt16>(pVVar16 + 0xe) + 1;
    M<SInt16>(pVVar16 + 0xe) = sVar3;
    if (iVar4 == 0) {
      iVar4 = VCALL(M<int>(self), 0x5a8)(self,param_1);
      if ((iVar4 == 0) &&
         (iVar4 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                             (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                             (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                             (VendorTransferBuffer *)((UInt8 *)param_1)), iVar4 == 0)) {
        VCALL(M<int>(self), 0x54c)(self,M<int>(self + 0x50) + -1);
        iVar4 = VCALL(M<int>(self), 0x5a8)(self,param_1);
        if ((iVar4 == 0) &&
           (iVar4 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                               (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                               (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                               (VendorTransferBuffer *)((UInt8 *)param_1)), iVar4 == 0)) {
          M<SInt16>(pVVar16 + 0xe) = M<SInt16>(pVVar16 + 0xe) + -1;
          return 0;
        }
      }
      sVar3 = M<SInt16>(pVVar16 + 0xe);
    }
    VVar11 = param_1[0x20];
    M<SInt16>(pVVar16 + 0xe) = sVar3 + -1;
  }
  if (VVar11 == 0x7) {
    iVar4 = M<int>(param_1 + 0x50);
    iVar17 = M<int>(M<int>(param_1 + 0x58) + 4);
  }
  else {
    iVar17 = M<int>(param_1 + 4);
    iVar4 = M<int>(param_1 + 0x50);
  }
  iVar14 = M<int>(self + 0x758);
  iVar5 = VCALL(M<int>(self), 0x54c)(self,M<UInt32>(M<int>(param_1 + 0x14) + 0xc));
  iVar1 = M<int>(self + 0x8a4);
  pAVar7 = param_2 + 0xa00;
  M<int>(self + 0x758) = iVar14 + iVar5;
  uVar12 = (unsigned int)M<UInt16>(param_2 + 0x40);
  iVar5 = M<int>(param_2 + 0x44);
  iVar14 = M<int>(param_2 + 0x48);
  iVar9 = uVar12 + 4;
  iVar10 = uVar12 + 7;
  M<UInt32>(pAVar7 + uVar12 * 4) = 0x80000000;
  iVar18 = M<int>(param_1 + 0x48);
  M<int>(pAVar7 + iVar9 * 4) = iVar14 + iVar18;
  M<int>(pAVar7 + iVar10 * 4) = iVar17 + iVar1 + iVar5;
  if (1 < M<UInt16>(param_2 + 0x42)) {
    iVar2 = M<UInt16>(param_2 + 0x42) - 1;
    iVar13 = M<int>(param_2 + 0x50);
    iVar15 = M<int>(param_2 + 0x4c);
    do {
      uVar12 = uVar12 + 0x12;
      iVar9 = iVar9 + 0x12;
      iVar10 = iVar10 + 0x12;
      iVar5 = iVar5 + iVar15;
      iVar14 = iVar14 + iVar13;
      M<UInt32>(pAVar7 + uVar12 * 4) = 0x80000000;
      M<int>(pAVar7 + iVar9 * 4) = iVar14 + iVar18;
      M<int>(pAVar7 + iVar10 * 4) = iVar17 + iVar1 + iVar5;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar17 = M<int>(param_1 + 0x14);
  M<UInt16>(iVar17 + 0x1c) = M<UInt16>(iVar17 + 0x1c) | M<UInt16>(iVar17 + 0x28);
  uVar8 = M<UInt32>(param_2);
  if ((uVar8 & 1) != 0) {
    iVar17 = uVar8 * 4;
    uVar8 = uVar8 + 1;
    M<UInt32>(pAVar7 + iVar17) = 0x80000000;
  }
  M<UInt32>(self + 0x704) = uVar8 * 4 + M<int>(self + 0x704);
  M<int>(self + 0x720) = iVar4 + M<int>(self + 0x720);
  iVar4 = M<int>(param_1 + 0x14);
  uVar6 = this->submit_buffer((UInt32 *)pAVar7,M<int>(param_1 + 4) + 0xa00,uVar8);
  M<UInt32>(iVar4 + 0xc) = uVar6;
  if (param_1[0x20] == 0x7) {
    M<UInt32>(M<int>(M<int>(param_1 + 0x58) + 0x14) + 8) =
         M<UInt32>(M<int>(param_1 + 0x14) + 0xc);
  }
  uVar6 = M<UInt32>(M<int>(param_1 + 0x14) + 0xc);
  M<unsigned int>(param_2 + 0x20) = M<unsigned int>(param_2 + 0x20) | 0x10000000;
  M<UInt32>(param_2 + 0x1c) = uVar6;
  return 1;
}
