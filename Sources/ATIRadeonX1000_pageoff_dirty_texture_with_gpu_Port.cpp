/*
 * ATIRadeonX1000_pageoff_dirty_texture_with_gpu_Port.cpp
 *
 * ATIRadeonX1000::pageoff_dirty_texture_with_gpu (real addr 0x210f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x210f0 */
UInt32 ATIRadeonX1000::pageoff_dirty_texture_with_gpu(VendorTextureBuffer *real_param_1, ATITextureBufferHeader *real_param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);

  UInt8 bVar1;
  UInt8 AVar2;
  bool bVar3;
  UInt8 bVar4;
  unsigned int uVar5;
  unsigned int uVar6;
  unsigned int uVar7;
  SInt16 sVar10;
  int iVar8;
  unsigned int uVar9;
  int iVar11;
  UInt32 uVar12;
  UInt32 uVar13;
  UInt8 *pAVar14;
  int iVar15;
  UInt8 *pAVar16;
  UInt8 VVar17;
  unsigned int uVar18;
  unsigned int uVar19;
  int iVar20;
  unsigned int uVar21;
  unsigned int uVar22;
  unsigned int uVar23;
  int iVar24;
  UInt8 *pAVar25;
  unsigned int uVar26;
  unsigned int uVar27;
  int iVar28;
  UInt8 *pVVar29;
  int iVar30;
  int local_68;
  
  iVar15 = M<int>(param_1 + 0x14);
  iVar24 = M<int>(param_1 + 0x48);
  uVar6 = (unsigned int)M<UInt8>(iVar15 + 0x17);
  bVar1 = M<UInt8>(iVar15 + 0x34);
  uVar7 = (uVar6 + M<UInt8>(iVar15 + 0x35)) - 1;
  if (param_1[0x20] == 0x3) {
    VVar17 = 0x3;
    if (M<int>(param_1 + 4) == 0) {
      iVar15 = VCALL(M<int>(self), 0x5a8)(self);
      if ((iVar15 == 0) &&
         (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                              (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                              (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                              (VendorTransferBuffer *)((UInt8 *)param_1)), iVar15 == 0)) {
        VCALL(M<int>(self), 0x54c)(self,M<int>(self + 0x50) + -1);
        iVar15 = VCALL(M<int>(self), 0x5a8)(self,param_1);
        if ((iVar15 == 0) &&
           (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                                (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                                (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                                (VendorTransferBuffer *)((UInt8 *)param_1)), iVar15 == 0)) {
          return 0;
        }
      }
      iVar15 = M<int>(param_1 + 0x14);
      VVar17 = param_1[0x20];
    }
  }
  else {
    if (param_1[0x20] != 0x7) {
      return 0;
    }
    pVVar29 = M<UInt8 *>(param_1 + 0x58);
    if (((M<int>(pVVar29 + 4) == 0) &&
        (iVar15 = VCALL(M<int>(self), 0x5a8)(self,pVVar29), iVar15 == 0)) &&
       (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                            (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                            (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),(VendorTransferBuffer *)(pVVar29)), iVar15 == 0)) {
      VCALL(M<int>(self), 0x54c)(self,M<int>(self + 0x50) + -1);
      iVar15 = VCALL(M<int>(self), 0x5a8)(self,pVVar29);
      if ((iVar15 == 0) &&
         (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                              (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                              (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),(VendorTransferBuffer *)(pVVar29)), iVar15 == 0))
      {
        return 0;
      }
    }
    iVar15 = M<int>(param_1 + 4);
    sVar10 = M<SInt16>(pVVar29 + 0xe) + 1;
    M<SInt16>(pVVar29 + 0xe) = sVar10;
    if (iVar15 == 0) {
      iVar15 = VCALL(M<int>(self), 0x5a8)(self,param_1);
      if ((iVar15 == 0) &&
         (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                              (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                              (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                              (VendorTransferBuffer *)((UInt8 *)param_1)), iVar15 == 0)) {
        VCALL(M<int>(self), 0x54c)(self,M<int>(self + 0x50) + -1);
        iVar15 = VCALL(M<int>(self), 0x5a8)(self,param_1);
        if ((iVar15 == 0) &&
           (iVar15 = ((IOATIR500Accelerator *)((UInt8 *)self))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
                                (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)((UInt8 *)0x0),
                                (IOATIR500Surface *)((UInt8 *)0x0),(IOATIR500Shared *)((UInt8 *)0x0),
                                (VendorTransferBuffer *)((UInt8 *)param_1)), iVar15 == 0)) {
          M<SInt16>(pVVar29 + 0xe) = M<SInt16>(pVVar29 + 0xe) + -1;
          return 0;
        }
      }
      sVar10 = M<SInt16>(pVVar29 + 0xe);
    }
    iVar15 = M<int>(param_1 + 0x14);
    VVar17 = param_1[0x20];
    M<SInt16>(pVVar29 + 0xe) = sVar10 + -1;
  }
  if (VVar17 == 0x7) {
    local_68 = M<int>(param_1 + 0x50);
    iVar30 = M<int>(M<int>(param_1 + 0x58) + 4);
  }
  else {
    local_68 = M<int>(param_1 + 0x50);
    iVar30 = M<int>(param_1 + 4);
  }
  iVar28 = M<int>(self + 0x758);
  iVar15 = VCALL(M<int>(self), 0x54c)(self,M<UInt32>(iVar15 + 0xc));
  iVar8 = M<int>(self + 0x8a4);
  M<int>(self + 0x758) = iVar28 + iVar15;
  pAVar25 = param_2 + M<int>(param_2 + 4) * 4 + 0xa00;
  M<UInt32>(pAVar25 + 0x2c) = M<UInt32>(self + 0xb74);
  iVar28 = M<int>(param_1 + 0x14);
  bVar4 = M<UInt8>(iVar28 + 0x15) >> 3;
  iVar15 = -(bVar4 & 3);
  if ((bVar4 & 2) == 0) {
    if (-1 < iVar15) {
      bVar3 = false;
      goto LAB_000214a0;
    }
    uVar18 = (unsigned int)(UInt8)param_2[0x1a];
    bVar3 = uVar18 == 0;
LAB_000214a8:
    if (uVar18 < 4) {
      if (bVar3) {
        iVar20 = 2;
        iVar15 = 3;
      }
      else {
        iVar20 = 1;
        iVar15 = 4;
      }
      goto LAB_000214e0;
    }
  }
  else {
    bVar3 = true;
LAB_000214a0:
    if (iVar15 < 0) {
      uVar18 = (unsigned int)(UInt8)param_2[0x1a];
      goto LAB_000214a8;
    }
    uVar18 = (unsigned int)(UInt8)param_2[0x1a];
  }
  iVar20 = 0;
  iVar15 = 5;
LAB_000214e0:
  uVar21 = 0;
  uVar23 = 1 << (iVar15 - uVar18 & 0x3f);
  uVar22 = 0x20 >> (uVar18 & 0x3f);
  if (bVar1 != 0) {
    while( true ) {
      uVar26 = (unsigned int)M<UInt8>(iVar28 + 0x15);
      uVar19 = M<unsigned int>(param_2 + 0x10) >> (uVar18 & 0x3f);
      uVar18 = M<unsigned int>(param_2 + 0xc) >> (uVar18 & 0x3f);
      if (uVar6 <= uVar7) {
        pAVar14 = param_2 + uVar6 * 0x20 + uVar21 * 0x1a0 + 0x40;
        uVar27 = uVar6;
        do {
          pAVar16 = pAVar25 + (unsigned int)M<UInt16>(pAVar14 + 0x18) * 4;
          if ((uVar26 & 4) != 0) {
            uVar5 = (int)(unsigned int)M<UInt16>(param_2 + 0x16) >> (uVar27 & 0x3f);
            uVar9 = 1 << iVar20;
            if (1 << iVar20 < (int)uVar5) {
              uVar9 = uVar5;
            }
            if ((uVar18 < uVar23 << 3) || (iVar15 = 1, uVar9 < (unsigned int)(1 << iVar20 + 3))) {
              iVar15 = 0;
            }
            uVar26 = iVar15 << 2 | uVar26 & 0xfffffffb;
          }
          iVar15 = M<int>(pAVar14 + 4);
          iVar28 = M<int>(pAVar14 + 8);
          uVar9 = uVar19 >> 1;
          M<UInt32>(pAVar16) = 0x138a;
          if (M<SInt16>(pAVar14 + 2) != 0) {
            iVar11 = 0;
            do {
              uVar19 = M<unsigned int>(pAVar16 + 0xc);
              iVar11 = iVar11 + 1;
              M<int>(pAVar16 + 4) = iVar15 + iVar30 + iVar8;
              M<unsigned int>(pAVar16 + 0xc) = uVar19 & 0xfff8ffff;
              AVar2 = param_2[0x1b];
              M<unsigned int>(pAVar16 + 0x24) =
                   uVar18 - 1 & 0x3fff | M<unsigned int>(pAVar16 + 0x24) & 0xffffc000;
              M<unsigned int>(pAVar16 + 0x14) =
                   iVar28 + iVar24 & 0xffffffe0U | (uVar26 >> 3 & 3) << 3 | (uVar26 >> 2 & 1) << 2;
              M<unsigned int>(pAVar16 + 0xc) =
                   (uVar9 & 0x1fff) << 1 | ((UInt8)AVar2 & 3) << 0x13 | uVar19 & 0xffe0c001;
              pAVar16 = pAVar16 + 0x74;
              iVar15 = iVar15 + M<int>(pAVar14 + 0xc);
              iVar28 = iVar28 + M<int>(pAVar14 + 0x10);
            } while (iVar11 < (int)(unsigned int)M<UInt16>(pAVar14 + 2));
          }
          uVar19 = uVar22;
          if (uVar22 < uVar9) {
            uVar19 = uVar9;
          }
          uVar9 = uVar18 >> 1;
          uVar18 = uVar23;
          if (uVar23 < uVar9) {
            uVar18 = uVar9;
          }
          uVar27 = uVar27 + 1;
          pAVar14 = pAVar14 + 0x20;
        } while (uVar27 <= uVar7);
      }
      uVar21 = uVar21 + 1;
      if (bVar1 <= uVar21) break;
      iVar28 = M<int>(param_1 + 0x14);
      uVar18 = (unsigned int)(UInt8)param_2[0x1a];
    }
  }
  uVar13 = M<UInt32>(param_2 + 8);
  M<UInt32>(self + 0xb90) = 1;
  M<UInt32>(self + 0x78) = 0;
  if ((uVar13 & 1) != 0) {
    iVar15 = uVar13 * 4;
    uVar13 = uVar13 + 1;
    M<UInt32>(pAVar25 + iVar15) = 0x80000000;
  }
  M<UInt32>(self + 0x704) = uVar13 * 4 + M<int>(self + 0x704);
  M<int>(self + 0x720) = local_68 + M<int>(self + 0x720);
  iVar15 = M<int>(param_1 + 0x14);
  uVar12 = this->submit_buffer((UInt32 *)pAVar25,
                         M<int>(param_2 + 4) * 4 + M<int>(param_1 + 4) + 0xa00,uVar13);
  M<UInt32>(iVar15 + 0xc) = uVar12;
  if (param_1[0x20] == 0x7) {
    M<UInt32>(M<int>(M<int>(param_1 + 0x58) + 0x14) + 8) =
         M<UInt32>(M<int>(param_1 + 0x14) + 0xc);
  }
  uVar12 = M<UInt32>(M<int>(param_1 + 0x14) + 0xc);
  M<unsigned int>(param_2 + 0x20) = M<unsigned int>(param_2 + 0x20) | 0x10000000;
  M<UInt32>(param_2 + 0x1c) = uVar12;
  return 1;
}
