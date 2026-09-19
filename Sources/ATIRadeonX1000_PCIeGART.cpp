/*
 * ATIRadeonX1000_PCIeGART.cpp
 *
 * RESOLVED (ledger pass): the PCIe GART management members of ATIRadeonX1000 (real addrs in parentheses):
 *   removeFromPCIeGART (0x1b540)  reserveInGART (0x1b6d0)  clearInGART (0x1b7f0)  startupPCIeGART (0x1d830)
 *   shutdownPCIeGART (0x1dc10)  pageOnPCIeGART (0x1dcd0)  addToPCIeGART (0x1dd80)
 * The GART page table (this+0xc4c, plus a second copy at +0xbb8 = 3000 when the aperture sits in video memory) holds
 * little-endian entries written through byte-swapped stores; after each edit the code kicks the CP's GART flush register
 * (aperture+0x130, bit 27) and reads the last written entry back (this+0xc5c) to post the write. reserveInGART /
 * clearInGART first call the IOATIR500Accelerator versions (BASE_*; the shipped code reaches them through
 * the IOATIR500Accelerator vtable slot). Transcribed mechanically from the decompile (Tools/port_fn.py,
 * Headers/GhidraCompat.h; conventions as in ATIR500Surface_BuildSwap.cpp). addToPCIeGART's decompile names `this`
 * param_1, so its real parameters are param_2 .. param_5.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraExterns.h"

#define BASE_reserveInGART(x) IOATIR500Accelerator::reserveInGART(x)
#define BASE_clearInGART(x) IOATIR500Accelerator::clearInGART(x)
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_kprintf(...) asm("_kprintf");

/* real addr 0x1b540 */
void ATIRadeonX1000::removeFromPCIeGART(IOMemoryDescriptor *real_param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  SInt32 iVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt32 *puVar7;
  UInt32 uVar8;
  UInt32 uVar9;
  
  if (param_1 != (UInt8 *)0x0) {
    uVar9 = param_2 >> (GH_page_shift & 0x3f);
    uVar1 = VCALL(M<SInt32>(param_1), 0x128)(param_1);
    uVar1 = uVar9 + (uVar1 >> (GH_page_shift & 0x3f));
    iVar6 = uVar1 - uVar9;
    M<SInt32>(self + 0xa0) = M<SInt32>(self + 0xa0) - (iVar6 << (GH_page_shift & 0x3f));
    if (uVar9 < uVar1) {
      iVar2 = M<SInt32>(self + 3000);
      iVar5 = uVar9 * 4;
      iVar3 = M<SInt32>(self + 0xc4c);
      uVar8 = M<UInt32>(self + 0x844);
      iVar4 = 0;
      puVar7 = (UInt32 *)(iVar2 + iVar5);
      do {
        if (iVar2 != 0) {
          *puVar7 = uVar8 << 0x18 | (uVar8 & 0xff00) << 8 | uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
        }
        M<UInt32>(iVar5 + iVar3) =
             uVar8 << 0x18 | (uVar8 & 0xff00) << 8 | uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 4;
        puVar7 = puVar7 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      uVar9 = uVar9 + iVar4;
    }
    else {
      iVar2 = M<SInt32>(self + 3000);
    }
    enforceInOrderExecutionIO();
    if (iVar2 != 0) {
      iVar6 = M<SInt32>(self + 0x860);
      M<UInt32>(self + 0xc5c) =
           (UInt32)M<UInt8>(iVar6 + 0x133) << 0x18 | (UInt32)M<UInt8>(iVar6 + 0x132) << 0x10 |
           (UInt32)M<UInt8>(iVar6 + 0x131) << 8 | (UInt32)M<UInt8>(iVar6 + 0x130);
      uVar8 = M<UInt32>(self + 0xc5c);
      M<UInt32>(iVar6 + 0x130) =
           uVar8 << 0x18 | (uVar8 & 0xff00) << 8 | (uVar8 & 0xff0000) >> 8 |
           (uVar8 | 0x8000000) >> 0x18;
      uVar8 = M<UInt32>(self + 0xc5c);
      M<UInt32>(iVar6 + 0x130) =
           uVar8 << 0x18 | (uVar8 & 0xff00) << 8 | uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
      iVar2 = uVar9 * 4 + iVar2;
      M<UInt32>(self + 0xc5c) =
           (UInt32)M<UInt8>(iVar2 + -1) << 0x18 | (UInt32)M<UInt8>(iVar2 + -2) << 0x10 |
           (UInt32)M<UInt8>(iVar2 + -3) << 8 | (UInt32)M<UInt8>(iVar2 + -4);
    }
    uVar9 = param_2 >> (GH_page_shift & 0x3f);
    VCALL(M<SInt32>(self), 0x59c)(self,uVar9,uVar1 - uVar9);
    VCALL(M<SInt32>(param_1), 0x148)(param_1,3);
  }
  return;
}

/* real addr 0x1b6d0 */
bool ATIRadeonX1000::reserveInGART(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 *puVar3;
  
  iVar2 = BASE_reserveInGART(param_1);
  if (iVar2 != 0) {
    iVar2 = (param_1 >> (GH_page_shift & 0x3f)) * 4;
    puVar3 = (UInt32 *)(iVar2 + M<SInt32>(self + 0xc4c));
    if (((UInt32)(UInt8)*puVar3 << 0x18 | (UInt32)M<UInt8>((SInt32)puVar3 + 2) << 0x10 |
         (UInt32)M<UInt8>((SInt32)puVar3 + 1) << 8 | (UInt32)M<UInt8>(puVar3)) != M<UInt32>(self + 0x844))
    {
      BASE_clearInGART(param_1 >> (GH_page_shift & 0x3f));
      GH_IOSleep(10);
      return 0;
    }
    uVar1 = M<UInt32>(self + 0x848);
    *puVar3 = uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
    if (M<SInt32>(self + 3000) != 0) {
      puVar3 = (UInt32 *)(iVar2 + M<SInt32>(self + 3000));
      *puVar3 = uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
      enforceInOrderExecutionIO();
      iVar2 = M<SInt32>(self + 0x860);
      M<UInt32>(self + 0xc5c) =
           (UInt32)M<UInt8>(iVar2 + 0x133) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x132) << 0x10 |
           (UInt32)M<UInt8>(iVar2 + 0x131) << 8 | (UInt32)M<UInt8>(iVar2 + 0x130);
      uVar1 = M<UInt32>(self + 0xc5c);
      M<UInt32>(iVar2 + 0x130) =
           uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8 |
           (uVar1 | 0x8000000) >> 0x18;
      uVar1 = M<UInt32>(self + 0xc5c);
      M<UInt32>(iVar2 + 0x130) =
           uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
      M<UInt32>(self + 0xc5c) =
           (UInt32)(UInt8)*puVar3 << 0x18 | (UInt32)M<UInt8>((SInt32)puVar3 + 2) << 0x10 |
           (UInt32)M<UInt8>((SInt32)puVar3 + 1) << 8 | (UInt32)M<UInt8>(puVar3);
      return 1;
    }
  }
  return 1;
}

/* real addr 0x1b7f0 */
void ATIRadeonX1000::clearInGART(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 *puVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  
  BASE_clearInGART(param_1);
  uVar2 = M<UInt32>(self + 0x844);
  iVar3 = (param_1 >> (GH_page_shift & 0x3f)) * 4;
  M<UInt32>(iVar3 + M<SInt32>(self + 0xc4c)) =
       uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
  if (M<SInt32>(self + 3000) != 0) {
    puVar1 = (UInt32 *)(iVar3 + M<SInt32>(self + 3000));
    *puVar1 = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
    enforceInOrderExecutionIO();
    iVar3 = M<SInt32>(self + 0x860);
    M<UInt32>(self + 0xc5c) =
         (UInt32)M<UInt8>(iVar3 + 0x133) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0x132) << 0x10 |
         (UInt32)M<UInt8>(iVar3 + 0x131) << 8 | (UInt32)M<UInt8>(iVar3 + 0x130);
    uVar2 = M<UInt32>(self + 0xc5c);
    M<UInt32>(iVar3 + 0x130) =
         uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | (uVar2 & 0xff0000) >> 8 |
         (uVar2 | 0x8000000) >> 0x18;
    uVar2 = M<UInt32>(self + 0xc5c);
    M<UInt32>(iVar3 + 0x130) =
         uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
    M<UInt32>(self + 0xc5c) =
         (UInt32)(UInt8)*puVar1 << 0x18 | (UInt32)M<UInt8>((SInt32)puVar1 + 2) << 0x10 |
         (UInt32)M<UInt8>((SInt32)puVar1 + 1) << 8 | (UInt32)M<UInt8>(puVar1);
  }
  return;
}

/* real addr 0x1d830 */
SInt32 ATIRadeonX1000::startupPCIeGART() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  UInt32 *puVar5;
  UInt32 *puVar6;
  UInt32 *puVar7;
  SInt32 iVar8;
  UInt32 uVar9;
  
  uVar2 = 0;
  if (((M<UInt32>(self + 0x98) & 0xf00000) != 0) && (uVar2 = 1, M<SInt32>(self + 3000) == 0)) {
    iVar3 = VCALL(*M<SInt32 *>(self + 0x74), 0x568)(M<SInt32 *>(self + 0x74),0x10,0);
    if (iVar3 == 0) {
      GH_kprintf(
                  "ATI_PCIe:startupPCIeGART() (findPCICapability(kIOPCIPCIExpressCapability) failed, IGNORING...)\n"
                  );
      GH_IOSleep(10);
    }
    uVar4 = M<UInt32>(self + 0x830);
    if (uVar4 != 0) {
      iVar3 = M<SInt32>(self + 0x860);
      uVar1 = (UInt32)M<UInt8>(iVar3 + 0xfb) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0xfa) << 0x10 |
              (UInt32)M<UInt8>(iVar3 + 0xf9) << 8 | (UInt32)M<UInt8>(iVar3 + 0xf8);
      if (0x8000000 < uVar1) {
        uVar1 = 0x8000000;
      }
      M<UInt32>(self + 0xbac) = uVar4 + 0x10000;
      M<UInt32>(self + 0xbb0) = uVar1 - uVar4;
      M<UInt32>(self + 0xbb4) = uVar1 - (uVar4 + 0x10000);
      if (M<SInt32>(self + 0xe4) != 0) {
        M<UInt32>(self + 3000) = (uVar1 - uVar4) + M<SInt32>(self + 0xe4);
      }
      if (M<SInt32>(self + 0xc4c) == 0) {
        puVar5 = (UInt32 *)GH_IOMallocAligned(uVar4,GH_page_size);
        M<UInt32 *>(self + 0xc4c) = puVar5;
        if (puVar5 == (UInt32 *)0x0) {
          M<UInt32>(self + 0xbb0) = 0;
          M<UInt32>(self + 0xbac) = 0;
          M<UInt32>(self + 0xbb4) = 0;
          M<UInt32>(self + 3000) = 0;
          return 0xffffffff;
        }
        puVar6 = M<UInt32 *>(self + 3000);
        if (puVar6 == (UInt32 *)0x0) {
          uVar4 = M<UInt32>(self + 0x830);
          uVar1 = uVar4 >> 2;
          if (uVar1 != 0) {
            uVar9 = M<UInt32>(self + 0x844);
            do {
              *puVar5 = uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 | uVar9 >> 0x18;
              puVar5 = puVar5 + 1;
              uVar1 = uVar1 - 1;
            } while (uVar1 != 0);
          }
        }
        else {
          uVar4 = M<UInt32>(self + 0x830);
          iVar3 = 0;
          uVar1 = uVar4 >> 2;
          if (uVar1 != 0) {
            uVar9 = M<UInt32>(self + 0x844);
            iVar3 = 0;
            puVar7 = puVar6;
            do {
              *puVar7 = uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 | uVar9 >> 0x18;
              *puVar5 = uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 | uVar9 >> 0x18;
              iVar3 = iVar3 + 1;
              puVar7 = puVar7 + 1;
              puVar5 = puVar5 + 1;
              uVar1 = uVar1 - 1;
            } while (uVar1 != 0);
            iVar3 = iVar3 * 4;
          }
          iVar8 = M<SInt32>(self + 0x860);
          M<UInt32>(self + 0xc5c) =
               (UInt32)M<UInt8>(iVar8 + 0x133) << 0x18 | (UInt32)M<UInt8>(iVar8 + 0x132) << 0x10 |
               (UInt32)M<UInt8>(iVar8 + 0x131) << 8 | (UInt32)M<UInt8>(iVar8 + 0x130);
          uVar1 = M<UInt32>(self + 0xc5c);
          M<UInt32>(iVar8 + 0x130) =
               uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8 |
               (uVar1 | 0x8000000) >> 0x18;
          uVar1 = M<UInt32>(self + 0xc5c);
          M<UInt32>(iVar8 + 0x130) =
               uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
          M<UInt32>(self + 0xc5c) =
               (UInt32)M<UInt8>((SInt32)puVar6 + iVar3 + -1) << 0x18 |
               (UInt32)M<UInt8>((SInt32)puVar6 + iVar3 + -2) << 0x10 |
               (UInt32)M<UInt8>((SInt32)puVar6 + iVar3 + -3) << 8 |
               (UInt32)M<UInt8>((SInt32)puVar6 + iVar3 + -4);
        }
      }
      iVar3 = 0xc;
      self[0xc00] = 0x0;
      M<UInt32>(self + 0xc08) = 0;
      M<UInt32>(self + 0xbc4) = 0;
      self[0xbff] = 0x6;
      M<UInt16>(self + 0xbe6) = 1;
      self[0xbfb] = 0xff;
      M<UInt32>(self + 0xbc8) = 0;
      M<UInt32>(self + 0xbcc) = 0;
      M<UInt32>(self + 0xbd0) = 0;
      M<UInt32>(self + 0xbd4) = 0;
      M<UInt16>(self + 0xbd8) = 0;
      M<UInt16>(self + 0xbda) = 0;
      M<UInt16>(self + 0xbdc) = 0;
      M<UInt16>(self + 0xbe0) = 0;
      M<UInt16>(self + 0xbe2) = 0;
      M<UInt16>(self + 0xbe4) = 1;
      M<UInt32>(self + 0xbe8) = 0;
      M<UInt32>(self + 0xbec) = 0xffffffff;
      M<UInt32>(self + 0xbf0) = 0;
      M<UInt32>(self + 0xbf4) = 0;
      self[0xbf8] = 0x0;
      self[0xbf9] = 0x0;
      self[0xbfa] = 0x0;
      self[0xbfc] = 0x0;
      self[0xbfd] = 0x0;
      M<UInt32>(self + 0xc04) = 0;
      uVar1 = 0x800;
      M<UInt32>(self + 0xc00) = M<UInt32>(self + 0xc00) & 0xff0007ff | 0x111000;
      do {
        if (uVar4 == (uVar4 / uVar1) * uVar1) {
          M<SInt16>(self + 0xbe0) = (SInt16)uVar1;
          M<UInt32>(self + 0xc48) = 0;
          M<UInt32>(self + 0xbd4) = uVar4;
          M<SInt16>(self + 0xbd8) = (SInt16)uVar1;
          M<UInt16>(self + 0xbda) = 4;
          M<SInt16>(self + 0xbdc) = (SInt16)(uVar1 << 2);
          M<UInt32>(self + 0xbcc) = M<UInt32>(self + 0xbb0);
          self[0xbfc] = 0x0;
          self[0xbfd] = 0x0;
          M<UInt32>(self + 0xc3c) = 0;
          M<UInt32>(self + 0xc40) = 0;
          M<UInt32>(self + 0xc44) = 0;
          self[0xbfb] = 0xff;
          self[0xbff] = 0x6;
          self[0xbfe] = 0xb;
          M<SInt16>(self + 0xbe2) = (SInt16)(uVar4 / (uVar1 << 2));
          if ((M<UInt32>(self + 0x98) & 0x80) == 0) {
            M<UInt32>(self + 0xbc0) = 0;
          }
          else {
            M<UInt32>(self + 0xbc0) = 1;
          }
          self[0x990] = ((char)self[0x990] + -1);
          iVar3 = M<SInt32>(self + 0x860);
          M<UInt32>(iVar3 + 0xb5c) =
               (UInt32)(M<UInt16>(self + 0xbdc) >> 3) << 0x18 |
               (M<UInt16>(self + 0xbdc) >> 3 & 0xff00) << 8 |
               (((UInt8)self[0xbfc] & 7) << 0x10 | ((UInt8)self[0xbfd] & 3) << 0x14 |
               ((UInt8)self[0xbfd] & 3) << 0x16) >> 8;
          enforceInOrderExecutionIO();
          uVar4 = M<UInt32>(self + 0xbcc);
          M<UInt32>(iVar3 + 0xb54) =
               uVar4 << 0x18 | (uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 | uVar4 >> 0x18;
          enforceInOrderExecutionIO();
          uVar4 = (uVar4 + M<SInt32>(self + 0xbd4)) - 1;
          M<UInt32>(iVar3 + 0xb58) =
               uVar4 * 0x1000000 | (uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 | uVar4 >> 0x18;
          enforceInOrderExecutionIO();
          return 1;
        }
        uVar1 = uVar1 >> 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* real addr 0x1dc10 */
void ATIRadeonX1000::shutdownPCIeGART() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 uVar2;
  
  iVar1 = M<SInt32>(self + 0x860);
  M<UInt32>(iVar1 + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  uVar2 = M<UInt32>(self + 0xbbc);
  M<UInt32>(iVar1 + 0x34) =
       uVar2 << 0x18 | (uVar2 & 0xff00 | 0x100) << 8 | (uVar2 & 0xff0000) >> 8 | uVar2 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar1 + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar1 + 0x34) =
       uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar1 + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  M<UInt32>(iVar1 + 0x34) =
       (uVar2 & 0xfffffffe) << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
  enforceInOrderExecutionIO();
  if ((M<SInt32>(self + 0xbc8) != 0) && (M<SInt32>(self + 0xbc4) != 0)) {
    ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)(self + 0xbc4));
  }
  M<UInt32>(self + 0xbb0) = 0;
  M<UInt32>(self + 0xbb4) = 0;
  return;
}

/* real addr 0x1dcd0 */
void ATIRadeonX1000::pageOnPCIeGART() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  
  iVar2 = M<SInt32>(self + 3000);
  if (iVar2 != 0) {
    iVar1 = 0;
    uVar4 = 0;
    if (M<UInt32>(self + 0x830) >> 2 != 0) {
      while( true ) {
        M<UInt32>(iVar2 + uVar4 * 4) = M<UInt32>(M<SInt32>(self + 0xc4c) + uVar4 * 4);
        enforceInOrderExecutionIO();
        uVar4 = uVar4 + 1;
        if (M<UInt32>(self + 0x830) >> 2 <= uVar4) break;
        iVar2 = M<SInt32>(self + 3000);
      }
      iVar2 = M<SInt32>(self + 3000);
      iVar1 = uVar4 * 4;
    }
    enforceInOrderExecutionIO();
    iVar3 = M<SInt32>(self + 0x860);
    M<UInt32>(self + 0xc5c) =
         (UInt32)M<UInt8>(iVar3 + 0x133) << 0x18 | (UInt32)M<UInt8>(iVar3 + 0x132) << 0x10 |
         (UInt32)M<UInt8>(iVar3 + 0x131) << 8 | (UInt32)M<UInt8>(iVar3 + 0x130);
    uVar4 = M<UInt32>(self + 0xc5c);
    M<UInt32>(iVar3 + 0x130) =
         uVar4 << 0x18 | (uVar4 & 0xff00) << 8 | (uVar4 & 0xff0000) >> 8 |
         (uVar4 | 0x8000000) >> 0x18;
    uVar4 = M<UInt32>(self + 0xc5c);
    M<UInt32>(iVar3 + 0x130) =
         uVar4 << 0x18 | (uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 | uVar4 >> 0x18;
    iVar1 = iVar1 + iVar2;
    M<UInt32>(self + 0xc5c) =
         (UInt32)M<UInt8>(iVar1 + -1) << 0x18 | (UInt32)M<UInt8>(iVar1 + -2) << 0x10 |
         (UInt32)M<UInt8>(iVar1 + -3) << 8 | (UInt32)M<UInt8>(iVar1 + -4);
    return;
  }
  return;
}

/* real addr 0x1dd80 */
IOReturn ATIRadeonX1000::addToPCIeGART(IOMemoryDescriptor *real_param_2, UInt32 *real_param_3, UInt32 param_4, UInt32 param_5) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);
    UInt8 *param_3 = reinterpret_cast<UInt8 *>(real_param_3);

  UInt32 uVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  UInt8 *pbVar8;
  SInt32 iVar9;
  UInt32 uVar10;
  SInt32 iVar11;
  UInt32 local_38 [6];
  
  local_38[0] = 0;
  if ((param_2 != 0) && (param_3 != 0)) {
    uVar3 = VCALL(*param_2, 0x128)(param_2);
    uVar10 = GH_page_shift;
    uVar1 = M<UInt32>(self + 0x830);
    M<UInt32>(param_3) = 0;
    uVar1 = uVar1 >> 2;
    uVar3 = uVar3 >> (uVar10 & 0x3f);
    if (uVar1 == 0) {
      if (uVar3 == 0) {
        iVar5 = 0;
        uVar3 = 0;
LAB_0001de4c:
        iVar4 = VCALL(*param_2, 0x144)(param_2,3);
        if (iVar4 == 0) {
          iVar4 = 0;
          M<SInt32>(param_3) = iVar5 << (GH_page_shift & 0x3f);
          while (uVar10 = VCALL(*param_2, 0x13c)(param_2,iVar4,local_38),
                uVar1 = GH_page_shift, uVar10 != 0) {
            iVar4 = iVar4 + local_38[0];
            if (GH_page_size <= local_38[0]) {
              iVar11 = M<SInt32>(self + 3000);
              iVar6 = M<SInt32>(self + 0xc4c);
              iVar9 = iVar5 << 2;
              uVar7 = M<UInt32>(self + 0xbc0);
              do {
                if (iVar11 != 0) {
                  uVar2 = uVar10 >> 8 | uVar7;
                  M<UInt32>(iVar9 + iVar11) =
                       (uVar2 | 0xc) << 0x18 | (uVar2 & 0xff00) << 8 | (uVar2 & 0xff0000) >> 8 |
                       uVar7 >> 0x18;
                }
                uVar2 = uVar10 >> 8 | uVar7;
                M<UInt32>(iVar9 + iVar6) =
                     (uVar2 | 0xc) << 0x18 | (uVar2 & 0xff00) << 8 | (uVar2 & 0xff0000) >> 8 |
                     uVar7 >> 0x18;
                local_38[0] = local_38[0] - uVar1;
                uVar10 = uVar10 + uVar1;
                iVar5 = iVar5 + 1;
                iVar9 = iVar9 + 4;
              } while (uVar1 <= local_38[0]);
            }
          }
          enforceInOrderExecutionIO();
          iVar4 = M<SInt32>(self + 3000);
          if (iVar4 != 0) {
            iVar9 = M<SInt32>(self + 0x860);
            M<UInt32>(self + 0xc5c) =
                 (UInt32)M<UInt8>(iVar9 + 0x133) << 0x18 | (UInt32)M<UInt8>(iVar9 + 0x132) << 0x10 |
                 (UInt32)M<UInt8>(iVar9 + 0x131) << 8 | (UInt32)M<UInt8>(iVar9 + 0x130);
            uVar1 = M<UInt32>(self + 0xc5c);
            M<UInt32>(iVar9 + 0x130) =
                 uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8 |
                 (uVar1 | 0x8000000) >> 0x18;
            uVar1 = M<UInt32>(self + 0xc5c);
            M<UInt32>(iVar9 + 0x130) =
                 uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
            iVar4 = iVar5 * 4 + iVar4;
            M<UInt32>(self + 0xc5c) =
                 (UInt32)M<UInt8>(iVar4 + -1) << 0x18 | (UInt32)M<UInt8>(iVar4 + -2) << 0x10 |
                 (UInt32)M<UInt8>(iVar4 + -3) << 8 | (UInt32)M<UInt8>(iVar4 + -4);
          }
          VCALL(M<SInt32>(self), 0x59c)(self,iVar5 - uVar3,uVar3);
          M<UInt32>(self + 0xa0) =
               (uVar3 << (GH_page_shift & 0x3f)) + M<SInt32>(self + 0xa0);
          return 1;
        }
      }
    }
    else {
      pbVar8 = M<UInt8 *>(self + 0xc4c);
      uVar10 = 0;
      iVar5 = 0;
      do {
        uVar10 = uVar10 + 1;
        if (((UInt32)pbVar8[3] << 0x18 | (UInt32)pbVar8[2] << 0x10 | (UInt32)pbVar8[1] << 8 |
            (UInt32)*pbVar8) != M<UInt32>(self + 0x844)) {
          uVar10 = 0;
        }
        iVar5 = iVar5 + 1;
        if (uVar10 == uVar3) {
          iVar5 = iVar5 - uVar3;
          goto LAB_0001de4c;
        }
        pbVar8 = pbVar8 + 4;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
    }
  }
  return 0;
}
