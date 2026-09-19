/*
 * ATIRadeonX1000_prepare_texture_for_pageoff_with_cpu_Port.cpp
 *
 * ATIRadeonX1000::prepare_texture_for_pageoff_with_cpu (real addr 0x20d30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_memcpy(...) asm("_memcpy");


/* real addr 0x20d30 */
UInt32 ATIRadeonX1000::prepare_texture_for_pageoff_with_cpu(VendorTextureBuffer *real_param_1, ATITextureBufferHeader *real_param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);

  UInt8 bVar1;
  bool bVar2;
  UInt8 bVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  SInt32 iVar8;
  UInt8 *pAVar9;
  UInt8 *pAVar10;
  UInt32 uVar11;
  UInt32 uVar12;
  SInt32 iVar13;
  UInt32 uVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  UInt32 uVar17;
  UInt8 *pAVar18;
  UInt32 uVar19;
  SInt32 iVar20;
  UInt32 uVar21;
  UInt32 uVar22;
  UInt32 uVar23;
  UInt8 aGStack_68[28];
  
  uVar19 = M<UInt32>(param_1 + 0x48);
  if (uVar19 < M<UInt32>(self + 0x84c)) {
    return 1;
  }
  if ((param_1[0x20] != 0x3) && (param_1[0x20] != 0x7)) {
    return 0;
  }
  uVar22 = M<UInt32>(param_1 + 0x50);
  GH_memcpy(aGStack_68,(UInt8 *)(param_1 + 0x40),0x10);
  iVar6 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->alloc((GLKMemoryElement *)((UInt8 *)(param_1 + 0x40)),uVar22,
                     0x1000,0,M<UInt32>(self + 0x84c));
  if ((iVar6 == 0) && (iVar6 = this->freeToAllocTextureCPUVisibleVRAM((VendorTextureBuffer *)(param_1),uVar22), iVar6 == 0)) {
    return 0;
  }
  iVar20 = M<SInt32>(param_1 + 0x48);
  pAVar18 = param_2 + M<SInt32>(param_2 + 4) * 4 + 0xa00;
  M<UInt32>(pAVar18 + 0x2c) = M<UInt32>(self + 0xb74);
  iVar6 = M<SInt32>(param_1 + 0x14);
  uVar12 = (UInt32)M<UInt8>(iVar6 + 0x15);
  uVar14 = (UInt32)M<UInt8>(iVar6 + 0x17);
  bVar1 = M<UInt8>(iVar6 + 0x34);
  bVar3 = M<UInt8>(iVar6 + 0x15) >> 3;
  uVar16 = (uVar14 + M<UInt8>(iVar6 + 0x35)) - 1;
  iVar6 = -(bVar3 & 3);
  if ((bVar3 & 2) == 0) {
    if (-1 < iVar6) {
      bVar2 = false;
      goto LAB_00020e40;
    }
    uVar11 = (UInt32)(UInt8)param_2[0x1a];
    bVar2 = uVar11 == 0;
LAB_00020e48:
    if (uVar11 < 4) {
      if (bVar2) {
        iVar13 = 2;
        iVar6 = 3;
      }
      else {
        iVar13 = 1;
        iVar6 = 4;
      }
      goto LAB_00020e80;
    }
  }
  else {
    bVar2 = true;
LAB_00020e40:
    if (iVar6 < 0) {
      uVar11 = (UInt32)(UInt8)param_2[0x1a];
      goto LAB_00020e48;
    }
    uVar11 = (UInt32)(UInt8)param_2[0x1a];
  }
  iVar13 = 0;
  iVar6 = 5;
LAB_00020e80:
  uVar15 = 0;
  uVar17 = 1 << (iVar6 - uVar11 & 0x3f);
  if (bVar1 != 0) {
    while( true ) {
      uVar11 = M<UInt32>(param_2 + 0xc) >> (uVar11 & 0x3f);
      if (uVar14 <= uVar16) {
        pAVar9 = param_2 + uVar14 * 0x20 + uVar15 * 0x1a0 + 0x40;
        uVar23 = uVar14;
        do {
          pAVar10 = pAVar18 + (UInt32)M<UInt16>(pAVar9 + 0x18) * 4;
          if ((uVar12 & 4) != 0) {
            uVar4 = (SInt32)(UInt32)M<UInt16>(param_2 + 0x16) >> (uVar23 & 0x3f);
            uVar5 = 1 << iVar13;
            if (1 << iVar13 < (SInt32)uVar4) {
              uVar5 = uVar4;
            }
            if ((uVar11 < uVar17 << 3) || (iVar6 = 1, uVar5 < (UInt32)(1 << iVar13 + 3))) {
              iVar6 = 0;
            }
            uVar12 = iVar6 << 2 | uVar12 & 0xfffffffb;
          }
          iVar6 = M<SInt32>(pAVar9 + 8);
          M<UInt32>(pAVar10) = 0x138a;
          uVar5 = uVar11 >> 1;
          if (M<SInt16>(pAVar9 + 2) != 0) {
            uVar4 = uVar12 >> 2 & 1;
            uVar21 = uVar12 >> 3 & 3;
            iVar8 = 0;
            do {
              iVar8 = iVar8 + 1;
              M<SInt32>(pAVar10 + 4) = iVar6 + iVar20;
              M<UInt32>(pAVar10 + 0x24) =
                   uVar11 - 1 & 0x3fff | M<UInt32>(pAVar10 + 0x24) & 0xffffc000;
              M<UInt32>(pAVar10 + 0xc) =
                   (uVar5 & 0x1fff) << 1 |
                   uVar21 << 0x11 | uVar4 << 0x10 | M<UInt32>(pAVar10 + 0xc) & 0xffe0c001;
              M<UInt32>(pAVar10 + 0x14) = iVar6 + uVar19 & 0xffffffe0 | uVar21 << 3 | uVar4 << 2;
              pAVar10 = pAVar10 + 0x74;
              iVar6 = iVar6 + M<SInt32>(pAVar9 + 0x10);
            } while (iVar8 < (SInt32)(UInt32)M<UInt16>(pAVar9 + 2));
          }
          uVar11 = uVar17;
          if (uVar17 < uVar5) {
            uVar11 = uVar5;
          }
          uVar23 = uVar23 + 1;
          pAVar9 = pAVar9 + 0x20;
        } while (uVar23 <= uVar16);
      }
      uVar15 = uVar15 + 1;
      if (bVar1 <= uVar15) break;
      uVar11 = (UInt32)(UInt8)param_2[0x1a];
    }
  }
  uVar22 = M<UInt32>(param_2 + 8);
  M<UInt32>(self + 0xb90) = 1;
  if ((uVar22 & 1) != 0) {
    iVar6 = uVar22 * 4;
    uVar22 = uVar22 + 1;
    M<UInt32>(pAVar18 + iVar6) = 0x80000000;
  }
  M<UInt32>(self + 0x704) = uVar22 * 4 + M<SInt32>(self + 0x704);
  iVar6 = M<SInt32>(param_1 + 0x14);
  uVar7 = this->submit_buffer((UInt32 *)pAVar18,
                        M<SInt32>(param_2 + 4) * 4 + M<SInt32>(param_1 + 4) + 0xa00,uVar22);
  M<UInt32>(iVar6 + 0xc) = uVar7;
  VCALL(M<SInt32>(self), 0x54c)(self,M<UInt32>(M<SInt32>(param_1 + 0x14) + 0xc));
  ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)(aGStack_68));
  return 1;
}
