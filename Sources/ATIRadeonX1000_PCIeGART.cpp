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
void ATIRadeonX1000::removeFromPCIeGART(IOMemoryDescriptor *descriptor, UInt32 gartOffset) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *descriptorBytes = reinterpret_cast<UInt8 *>(descriptor);

  UInt32 uVar1;
  SInt32 iVar2;
  SInt32 pageTable;
  SInt32 pagesCleared;
  SInt32 entryOffset;
  SInt32 iVar6;
  UInt32 *secondEntry;
  UInt32 uVar8;
  UInt32 uVar9;
  
  if (descriptorBytes != (UInt8 *)0x0) {
    uVar9 = gartOffset >> (GH_page_shift & 0x3f);
    uVar1 = VCALL(M<SInt32>(descriptorBytes), 0x128)(descriptorBytes);
    uVar1 = uVar9 + (uVar1 >> (GH_page_shift & 0x3f));
    iVar6 = uVar1 - uVar9;
    M<SInt32>(self + kIOATIR500Accelerator_gartUsedBytes) = M<SInt32>(self + kIOATIR500Accelerator_gartUsedBytes) - (iVar6 << (GH_page_shift & 0x3f));
    if (uVar9 < uVar1) {
      iVar2 = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
      entryOffset = uVar9 * 4;
      pageTable = M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable);
      uVar8 = M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry);
      pagesCleared = 0;
      secondEntry = (UInt32 *)(iVar2 + entryOffset);
      do {
        if (iVar2 != 0) {
          *secondEntry = uVar8 << 0x18 | (uVar8 & 0xff00) << 8 | uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
        }
        M<UInt32>(entryOffset + pageTable) =
             uVar8 << 0x18 | (uVar8 & 0xff00) << 8 | uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
        pagesCleared = pagesCleared + 1;
        entryOffset = entryOffset + 4;
        secondEntry = secondEntry + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      uVar9 = uVar9 + pagesCleared;
    }
    else {
      iVar2 = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
    }
    enforceInOrderExecutionIO();
    if (iVar2 != 0) {
      iVar6 = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
      M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
           loadWordByteReversed(&M<UInt8>(iVar6 + 0x130));
      uVar8 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
      M<UInt32>(iVar6 + 0x130) =
           uVar8 << 0x18 | (uVar8 & 0xff00) << 8 | (uVar8 & 0xff0000) >> 8 |
           (uVar8 | 0x8000000) >> 0x18;
      uVar8 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
      M<UInt32>(iVar6 + 0x130) =
           uVar8 << 0x18 | (uVar8 & 0xff00) << 8 | uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
      iVar2 = uVar9 * 4 + iVar2;
      M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
           loadWordByteReversed(&M<UInt8>(iVar2 + -4));
    }
    uVar9 = gartOffset >> (GH_page_shift & 0x3f);
    VCALL(M<SInt32>(self), 0x59c)(self,uVar9,uVar1 - uVar9);
    VCALL(M<SInt32>(descriptorBytes), 0x148)(descriptorBytes,3);
  }
  return;
}

/* real addr 0x1b6d0 */
bool ATIRadeonX1000::reserveInGART(UInt32 gartOffset) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 *entry;
  
  iVar2 = BASE_reserveInGART(gartOffset);
  if (iVar2 != 0) {
    iVar2 = (gartOffset >> (GH_page_shift & 0x3f)) * 4;
    entry = (UInt32 *)(iVar2 + M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable));
    if ((loadWordByteReversed(entry)) != M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry))
    {
      BASE_clearInGART(gartOffset >> (GH_page_shift & 0x3f));
      GH_IOSleep(10);
      return 0;
    }
    uVar1 = M<UInt32>(self + kIOATIR500Accelerator_gartReservedEntry);
    *entry = uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
    if (M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) != 0) {
      entry = (UInt32 *)(iVar2 + M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress));
      *entry = uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
      enforceInOrderExecutionIO();
      iVar2 = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
      M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
           loadWordByteReversed(&M<UInt8>(iVar2 + 0x130));
      uVar1 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
      M<UInt32>(iVar2 + 0x130) =
           uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8 |
           (uVar1 | 0x8000000) >> 0x18;
      uVar1 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
      M<UInt32>(iVar2 + 0x130) =
           uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
      M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
           loadWordByteReversed(entry);
      return 1;
    }
  }
  return 1;
}

/* real addr 0x1b7f0 */
void ATIRadeonX1000::clearInGART(UInt32 gartOffset) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 *secondEntry;
  UInt32 uVar2;
  SInt32 iVar3;
  
  BASE_clearInGART(gartOffset);
  uVar2 = M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry);
  iVar3 = (gartOffset >> (GH_page_shift & 0x3f)) * 4;
  M<UInt32>(iVar3 + M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable)) =
       uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
  if (M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) != 0) {
    secondEntry = (UInt32 *)(iVar3 + M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress));
    *secondEntry = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
    enforceInOrderExecutionIO();
    iVar3 = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
         loadWordByteReversed(&M<UInt8>(iVar3 + 0x130));
    uVar2 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
    M<UInt32>(iVar3 + 0x130) =
         uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | (uVar2 & 0xff0000) >> 8 |
         (uVar2 | 0x8000000) >> 0x18;
    uVar2 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
    M<UInt32>(iVar3 + 0x130) =
         uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
    M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
         loadWordByteReversed(secondEntry);
  }
  return;
}

/* real addr 0x1d830 */
SInt32 ATIRadeonX1000::startupPCIeGART() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  UInt32 result;
  SInt32 iVar3;
  UInt32 uVar4;
  UInt32 *primaryEntry;
  UInt32 *secondTable;
  UInt32 *secondEntry;
  SInt32 registers;
  UInt32 emptyEntry;
  
  result = 0;
  if (((M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) & 0xf00000) != 0) && (result = 1, M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) == 0)) {
    iVar3 = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x568)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),0x10,0);
    if (iVar3 == 0) {
      GH_kprintf(
                  "ATI_PCIe:startupPCIeGART() (findPCICapability(kIOPCIPCIExpressCapability) failed, IGNORING...)\n"
                  );
      GH_IOSleep(10);
    }
    uVar4 = M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB);
    if (uVar4 != 0) {
      iVar3 = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
      uVar1 = loadWordByteReversed(&M<UInt8>(iVar3 + 0xf8));
      if (0x8000000 < uVar1) {
        uVar1 = 0x8000000;
      }
      M<UInt32>(self + kIOATIR500Accelerator_gartReserveSize) = uVar4 + 0x10000;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableVramOffset) = uVar1 - uVar4;
      M<UInt32>(self + kIOATIR500Accelerator_gartReserveOffset) = uVar1 - (uVar4 + 0x10000);
      if (M<SInt32>(self + kIOATIR500Accelerator_vramMappedAddress) != 0) {
        M<UInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) = (uVar1 - uVar4) + M<SInt32>(self + kIOATIR500Accelerator_vramMappedAddress);
      }
      if (M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable) == 0) {
        primaryEntry = (UInt32 *)GH_IOMallocAligned(uVar4,GH_page_size);
        M<UInt32 *>(self + kIOATIR500Accelerator_pcieGartTable) = primaryEntry;
        if (primaryEntry == (UInt32 *)0x0) {
          M<UInt32>(self + kIOATIR500Accelerator_gartTableVramOffset) = 0;
          M<UInt32>(self + kIOATIR500Accelerator_gartReserveSize) = 0;
          M<UInt32>(self + kIOATIR500Accelerator_gartReserveOffset) = 0;
          M<UInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) = 0;
          return 0xffffffff;
        }
        secondTable = M<UInt32 *>(self + kIOATIR500Accelerator_gartTableCpuAddress);
        if (secondTable == (UInt32 *)0x0) {
          uVar4 = M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB);
          uVar1 = uVar4 >> 2;
          if (uVar1 != 0) {
            emptyEntry = M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry);
            do {
              *primaryEntry = emptyEntry << 0x18 | (emptyEntry & 0xff00) << 8 | emptyEntry >> 8 & 0xff00 | emptyEntry >> 0x18;
              primaryEntry = primaryEntry + 1;
              uVar1 = uVar1 - 1;
            } while (uVar1 != 0);
          }
        }
        else {
          uVar4 = M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB);
          iVar3 = 0;
          uVar1 = uVar4 >> 2;
          if (uVar1 != 0) {
            emptyEntry = M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry);
            iVar3 = 0;
            secondEntry = secondTable;
            do {
              *secondEntry = emptyEntry << 0x18 | (emptyEntry & 0xff00) << 8 | emptyEntry >> 8 & 0xff00 | emptyEntry >> 0x18;
              *primaryEntry = emptyEntry << 0x18 | (emptyEntry & 0xff00) << 8 | emptyEntry >> 8 & 0xff00 | emptyEntry >> 0x18;
              iVar3 = iVar3 + 1;
              secondEntry = secondEntry + 1;
              primaryEntry = primaryEntry + 1;
              uVar1 = uVar1 - 1;
            } while (uVar1 != 0);
            iVar3 = iVar3 * 4;
          }
          registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
          M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
               loadWordByteReversed(&M<UInt8>(registers + 0x130));
          uVar1 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
          M<UInt32>(registers + 0x130) =
               uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8 |
               (uVar1 | 0x8000000) >> 0x18;
          uVar1 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
          M<UInt32>(registers + 0x130) =
               uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
          M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
               loadWordByteReversed(&M<UInt8>((SInt32)secondTable + iVar3 + -4));
        }
      }
      else {
      }
      iVar3 = 0xc;
      self[0xc00] = 0x0;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferMipOffset1) = 0;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBuffer) = 0;
      self[0xbff] = 0x6;
      M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferField22) = 1;
      self[0xbfb] = 0xff;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferElementPrev) = 0;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferGpuBaseAddress) = 0;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferAlignMask) = 0;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferSize) = 0;
      M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferWidth) = 0;
      M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferBytesPerPixel) = 0;
      M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferPitch) = 0;
      M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferActiveWidth) = 0;
      M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferActiveHeight) = 0;
      M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferField20) = 1;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferBackingStoreHandle) = 0;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferHzBlockField) = 0xffffffff;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferHzBlockExtra) = 0;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferHzBlockCountField) = 0;
      self[0xbf8] = 0x0;
      self[0xbf9] = 0x0;
      self[0xbfa] = 0x0;
      self[0xbfc] = 0x0;
      self[0xbfd] = 0x0;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferMipOffset0) = 0;
      uVar1 = 0x800;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferTilingDegreeBits) = M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferTilingDegreeBits) & 0xff0007ff | 0x111000;
      do {
        if (uVar4 == (uVar4 / uVar1) * uVar1) {
          M<SInt16>(self + kIOATIR500Accelerator_gartTableBufferActiveWidth) = (SInt16)uVar1;
          M<UInt32>(self + kIOATIR500Accelerator_gartTableElementBAlignMask) = 0;
          M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferSize) = uVar4;
          M<SInt16>(self + kIOATIR500Accelerator_gartTableBufferWidth) = (SInt16)uVar1;
          M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferBytesPerPixel) = 4;
          M<SInt16>(self + kIOATIR500Accelerator_gartTableBufferPitch) = (SInt16)(uVar1 << 2);
          M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferGpuBaseAddress) = M<UInt32>(self + kIOATIR500Accelerator_gartTableVramOffset);
          self[0xbfc] = 0x0;
          self[0xbfd] = 0x0;
          M<UInt32>(self + kIOATIR500Accelerator_gartTableElementB) = 0;
          M<UInt32>(self + kIOATIR500Accelerator_gartTableElementBPrev) = 0;
          M<UInt32>(self + kIOATIR500Accelerator_gartTableElementBOffset) = 0;
          self[0xbfb] = 0xff;
          self[0xbff] = 0x6;
          self[0xbfe] = 0xb;
          M<SInt16>(self + kIOATIR500Accelerator_gartTableBufferActiveHeight) = (SInt16)(uVar4 / (uVar1 << 2));
          if ((M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) & 0x80) == 0) {
            M<UInt32>(self + kIOATIR500Accelerator_gartEntryBase) = 0;
          }
          else {
            M<UInt32>(self + kIOATIR500Accelerator_gartEntryBase) = 1;
          }
          self[0x990] = ((char)self[0x990] + -1);
          iVar3 = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
          M<UInt32>(iVar3 + 0xb5c) =
               (UInt32)(M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferPitch) >> 3) << 0x18 |
               (M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferPitch) >> 3 & 0xff00) << 8 |
               (((UInt8)self[0xbfc] & 7) << 0x10 | ((UInt8)self[0xbfd] & 3) << 0x14 |
               ((UInt8)self[0xbfd] & 3) << 0x16) >> 8;
          enforceInOrderExecutionIO();
          uVar4 = M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferGpuBaseAddress);
          M<UInt32>(iVar3 + 0xb54) =
               uVar4 << 0x18 | (uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 | uVar4 >> 0x18;
          enforceInOrderExecutionIO();
          uVar4 = (uVar4 + M<SInt32>(self + kIOATIR500Accelerator_gartTableBufferSize)) - 1;
          M<UInt32>(iVar3 + 0xb58) =
               uVar4 * 0x1000000 | (uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 | uVar4 >> 0x18;
          enforceInOrderExecutionIO();
          return 1;
        }
        uVar1 = uVar1 >> 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    result = 0xffffffff;
  }
  return result;
}

/* real addr 0x1dc10 */
void ATIRadeonX1000::shutdownPCIeGART() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 registers;
  UInt32 savedValue;
  
  registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  M<UInt32>(registers + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  savedValue = M<UInt32>(self + kIOATIR500Accelerator_pcieIndirectRegValue);
  M<UInt32>(registers + 0x34) =
       savedValue << 0x18 | (savedValue & 0xff00 | 0x100) << 8 | (savedValue & 0xff0000) >> 8 | savedValue >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(registers + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  M<UInt32>(registers + 0x34) =
       savedValue << 0x18 | (savedValue & 0xff00) << 8 | savedValue >> 8 & 0xff00 | savedValue >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(registers + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  M<UInt32>(registers + 0x34) =
       (savedValue & 0xfffffffe) << 0x18 | (savedValue & 0xff00) << 8 | savedValue >> 8 & 0xff00 | savedValue >> 0x18;
  enforceInOrderExecutionIO();
  if ((M<SInt32>(self + kIOATIR500Accelerator_gartTableBufferElementPrev) != 0) && (M<SInt32>(self + kIOATIR500Accelerator_gartTableBuffer) != 0)) {
    ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->dealloc((GLKMemoryElement *)(self + kIOATIR500Accelerator_gartTableBuffer));
  }
  M<UInt32>(self + kIOATIR500Accelerator_gartTableVramOffset) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartReserveOffset) = 0;
  return;
}

/* real addr 0x1dcd0 */
void ATIRadeonX1000::pageOnPCIeGART() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  SInt32 secondTable;
  SInt32 registers;
  UInt32 uVar4;
  
  secondTable = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
  if (secondTable != 0) {
    iVar1 = 0;
    uVar4 = 0;
    if (M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2 != 0) {
      while( true ) {
        M<UInt32>(secondTable + uVar4 * 4) = M<UInt32>(M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable) + uVar4 * 4);
        enforceInOrderExecutionIO();
        uVar4 = uVar4 + 1;
        if (M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2 <= uVar4) break;
        secondTable = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
      }
      secondTable = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
      iVar1 = uVar4 * 4;
    }
    enforceInOrderExecutionIO();
    registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
         loadWordByteReversed(&M<UInt8>(registers + 0x130));
    uVar4 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
    M<UInt32>(registers + 0x130) =
         uVar4 << 0x18 | (uVar4 & 0xff00) << 8 | (uVar4 & 0xff0000) >> 8 |
         (uVar4 | 0x8000000) >> 0x18;
    uVar4 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
    M<UInt32>(registers + 0x130) =
         uVar4 << 0x18 | (uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 | uVar4 >> 0x18;
    iVar1 = iVar1 + secondTable;
    M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
         loadWordByteReversed(&M<UInt8>(iVar1 + -4));
    return;
  }
  return;
}

/* real addr 0x1dd80 */
IOReturn ATIRadeonX1000::addToPCIeGART(IOMemoryDescriptor *descriptor, UInt32 *outOffset, UInt32 minOffset, UInt32 maxOffset) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);
    UInt8 *descriptorBytes = reinterpret_cast<UInt8 *>(descriptor);
    UInt8 *outOffsetBytes = reinterpret_cast<UInt8 *>(outOffset);

  UInt32 uVar1;
  UInt32 entry;
  UInt32 pageCount;
  SInt32 iVar4;
  SInt32 pageIndex;
  SInt32 pageTable;
  UInt32 entryBits;
  UInt8 *entryScan;
  SInt32 iVar9;
  UInt32 uVar10;
  SInt32 secondTable;
  UInt32 segmentLength [6];

  segmentLength[0] = 0;
  if ((descriptorBytes != 0) && (outOffsetBytes != 0)) {
    pageCount = VCALL(M<UInt32>(descriptorBytes), 0x128)(descriptorBytes);
    uVar10 = GH_page_shift;
    uVar1 = M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB);
    M<UInt32>(outOffsetBytes) = 0;
    uVar1 = uVar1 >> 2;
    pageCount = pageCount >> (uVar10 & 0x3f);
    if (uVar1 == 0) {
      if (pageCount == 0) {
        pageIndex = 0;
        pageCount = 0;
LAB_0001de4c:
        iVar4 = VCALL(M<UInt32>(descriptorBytes), 0x144)(descriptorBytes,3);
        if (iVar4 == 0) {
          iVar4 = 0;
          M<SInt32>(outOffsetBytes) = pageIndex << (GH_page_shift & 0x3f);
          /* #167: the per-entry step is _page_size (stock 0x1de94 HA16/LO16 _page_size), NOT _page_shift
           * - the Ghidra dump labeled both zero-immediate data relocs alike; with the shift (12) as the
           * step each segment page wrote ~341 GART entries and ran off the end of the table. */
          while (uVar10 = VCALL(M<UInt32>(descriptorBytes), 0x13c)(descriptorBytes,iVar4,segmentLength),
                uVar1 = GH_page_size, uVar10 != 0) {
            iVar4 = iVar4 + segmentLength[0];
            if (GH_page_size <= segmentLength[0]) {
              secondTable = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
              pageTable = M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable);
              iVar9 = pageIndex << 2;
              entryBits = M<UInt32>(self + kIOATIR500Accelerator_gartEntryBase);
              do {
                if (secondTable != 0) {
                  entry = uVar10 >> 8 | entryBits;
                  M<UInt32>(iVar9 + secondTable) =
                       (entry | 0xc) << 0x18 | (entry & 0xff00) << 8 | (entry & 0xff0000) >> 8 |
                       entryBits >> 0x18;
                }
                entry = uVar10 >> 8 | entryBits;
                M<UInt32>(iVar9 + pageTable) =
                     (entry | 0xc) << 0x18 | (entry & 0xff00) << 8 | (entry & 0xff0000) >> 8 |
                     entryBits >> 0x18;
                segmentLength[0] = segmentLength[0] - uVar1;
                uVar10 = uVar10 + uVar1;
                pageIndex = pageIndex + 1;
                iVar9 = iVar9 + 4;
              } while (uVar1 <= segmentLength[0]);
            }
          }
          enforceInOrderExecutionIO();
          iVar4 = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
          if (iVar4 != 0) {
            iVar9 = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
            M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
                 loadWordByteReversed(&M<UInt8>(iVar9 + 0x130));
            uVar1 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
            M<UInt32>(iVar9 + 0x130) =
                 uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (uVar1 & 0xff0000) >> 8 |
                 (uVar1 | 0x8000000) >> 0x18;
            uVar1 = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
            M<UInt32>(iVar9 + 0x130) =
                 uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
            iVar4 = pageIndex * 4 + iVar4;
            M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
                 loadWordByteReversed(&M<UInt8>(iVar4 + -4));
          }
          VCALL(M<SInt32>(self), 0x59c)(self,pageIndex - pageCount,pageCount);
          M<UInt32>(self + kIOATIR500Accelerator_gartUsedBytes) =
               (pageCount << (GH_page_shift & 0x3f)) + M<SInt32>(self + kIOATIR500Accelerator_gartUsedBytes);
          return 1;
        }
      }
    }
    else {
      entryScan = M<UInt8 *>(self + kIOATIR500Accelerator_pcieGartTable);
      uVar10 = 0;
      pageIndex = 0;
      do {
        uVar10 = uVar10 + 1;
        if ((loadWordByteReversed(entryScan)) != M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry)) {
          uVar10 = 0;
        }
        pageIndex = pageIndex + 1;
        if (uVar10 == pageCount) {
          pageIndex = pageIndex - pageCount;
          goto LAB_0001de4c;
        }
        entryScan = entryScan + 4;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
    }
  }
  return 0;
}
