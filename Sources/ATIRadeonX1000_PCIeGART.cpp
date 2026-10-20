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

  UInt32 endPage;
  SInt32 secondTable;
  SInt32 pageTable;
  SInt32 pagesCleared;
  SInt32 entryOffset;
  SInt32 pagesLeft;
  UInt32 *secondEntry;
  UInt32 emptyEntry;
  UInt32 entryPage;
  UInt32 descriptorLength;
  SInt32 mmioBase;
  SInt32 secondTableEnd;
  UInt32 flushValue;
  
  if (descriptorBytes != (UInt8 *)0x0) {
    entryPage = gartOffset >> (GH_page_shift & 0x3f);
    descriptorLength = VCALL(M<SInt32>(descriptorBytes), 0x128)(descriptorBytes);
    endPage = entryPage + (descriptorLength >> (GH_page_shift & 0x3f));
    pagesLeft = endPage - entryPage;
    M<SInt32>(self + kIOATIR500Accelerator_gartUsedBytes) = M<SInt32>(self + kIOATIR500Accelerator_gartUsedBytes) - (pagesLeft << (GH_page_shift & 0x3f));
    if (entryPage < endPage) {
      secondTable = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
      entryOffset = entryPage * 4;
      pageTable = M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable);
      emptyEntry = M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry);
      pagesCleared = 0;
      secondEntry = (UInt32 *)(secondTable + entryOffset);
      do {
        if (secondTable != 0) {
          *secondEntry = emptyEntry << 0x18 | (emptyEntry & 0xff00) << 8 | emptyEntry >> 8 & 0xff00 | emptyEntry >> 0x18;
        }
        M<UInt32>(entryOffset + pageTable) =
             emptyEntry << 0x18 | (emptyEntry & 0xff00) << 8 | emptyEntry >> 8 & 0xff00 | emptyEntry >> 0x18;
        pagesCleared = pagesCleared + 1;
        entryOffset = entryOffset + 4;
        secondEntry = secondEntry + 1;
        pagesLeft = pagesLeft + -1;
      } while (pagesLeft != 0);
      entryPage = entryPage + pagesCleared;
    }
    else {
      secondTable = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
    }
    enforceInOrderExecutionIO();
    if (secondTable != 0) {
      mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
      M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
           loadWordByteReversed(&M<UInt8>(mmioBase + 0x130));
      flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
      M<UInt32>(mmioBase + 0x130) =
           flushValue << 0x18 | (flushValue & 0xff00) << 8 | (flushValue & 0xff0000) >> 8 |
           (flushValue | 0x8000000) >> 0x18;
      flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
      M<UInt32>(mmioBase + 0x130) =
           flushValue << 0x18 | (flushValue & 0xff00) << 8 | flushValue >> 8 & 0xff00 | flushValue >> 0x18;
      secondTableEnd = entryPage * 4 + secondTable;
      M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
           loadWordByteReversed(&M<UInt8>(secondTableEnd + -4));
    }
    entryPage = gartOffset >> (GH_page_shift & 0x3f);
    VCALL(M<SInt32>(self), 0x59c)(self,entryPage,endPage - entryPage);
    VCALL(M<SInt32>(descriptorBytes), 0x148)(descriptorBytes,3);
  }
  return;
}

/* real addr 0x1b6d0 */
bool ATIRadeonX1000::reserveInGART(UInt32 gartOffset) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 reservedEntry;
  SInt32 entryOffset;
  UInt32 *entry;
  SInt32 baseResult;
  SInt32 mmioBase;
  UInt32 flushValue;
  
  baseResult = BASE_reserveInGART(gartOffset);
  if (baseResult != 0) {
    entryOffset = (gartOffset >> (GH_page_shift & 0x3f)) * 4;
    entry = (UInt32 *)(entryOffset + M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable));
    if ((loadWordByteReversed(entry)) != M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry))
    {
      BASE_clearInGART(gartOffset >> (GH_page_shift & 0x3f));
      GH_IOSleep(10);
      return 0;
    }
    reservedEntry = M<UInt32>(self + kIOATIR500Accelerator_gartReservedEntry);
    *entry = reservedEntry << 0x18 | (reservedEntry & 0xff00) << 8 | reservedEntry >> 8 & 0xff00 | reservedEntry >> 0x18;
    if (M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) != 0) {
      entry = (UInt32 *)(entryOffset + M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress));
      *entry = reservedEntry << 0x18 | (reservedEntry & 0xff00) << 8 | reservedEntry >> 8 & 0xff00 | reservedEntry >> 0x18;
      enforceInOrderExecutionIO();
      mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
      M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
           loadWordByteReversed(&M<UInt8>(mmioBase + 0x130));
      flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
      M<UInt32>(mmioBase + 0x130) =
           flushValue << 0x18 | (flushValue & 0xff00) << 8 | (flushValue & 0xff0000) >> 8 |
           (flushValue | 0x8000000) >> 0x18;
      flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
      M<UInt32>(mmioBase + 0x130) =
           flushValue << 0x18 | (flushValue & 0xff00) << 8 | flushValue >> 8 & 0xff00 | flushValue >> 0x18;
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
  UInt32 emptyEntry;
  SInt32 entryOffset;
  UInt32 flushValue;
  SInt32 mmioBase;
  
  BASE_clearInGART(gartOffset);
  emptyEntry = M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry);
  entryOffset = (gartOffset >> (GH_page_shift & 0x3f)) * 4;
  M<UInt32>(entryOffset + M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable)) =
       emptyEntry << 0x18 | (emptyEntry & 0xff00) << 8 | emptyEntry >> 8 & 0xff00 | emptyEntry >> 0x18;
  if (M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) != 0) {
    secondEntry = (UInt32 *)(entryOffset + M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress));
    *secondEntry = emptyEntry << 0x18 | (emptyEntry & 0xff00) << 8 | emptyEntry >> 8 & 0xff00 | emptyEntry >> 0x18;
    enforceInOrderExecutionIO();
    mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
         loadWordByteReversed(&M<UInt8>(mmioBase + 0x130));
    flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
    M<UInt32>(mmioBase + 0x130) =
         flushValue << 0x18 | (flushValue & 0xff00) << 8 | (flushValue & 0xff0000) >> 8 |
         (flushValue | 0x8000000) >> 0x18;
    flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
    M<UInt32>(mmioBase + 0x130) =
         flushValue << 0x18 | (flushValue & 0xff00) << 8 | flushValue >> 8 & 0xff00 | flushValue >> 0x18;
    M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
         loadWordByteReversed(secondEntry);
  }
  return;
}

/* real addr 0x1d830 */
SInt32 ATIRadeonX1000::startupPCIeGART() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 tableWidth;
  UInt32 result;
  UInt32 gartSize;
  UInt32 *primaryEntry;
  UInt32 *secondTable;
  UInt32 *secondEntry;
  SInt32 registers;
  UInt32 emptyEntry;
  UInt32 tableGpuBase;
  UInt32 tableGpuEnd;
  UInt32 vramSize;
  UInt32 entriesLeft;
  UInt32 flushValue;
  SInt32 capabilityOffset;
  SInt32 mmioBase;
  SInt32 entriesFilled;
  SInt32 widthTriesLeft;
  
  result = 0;
  if (((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0xf00000) != 0) && (result = 1, M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) == 0)) {
    capabilityOffset = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x568)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),0x10,0);
    if (capabilityOffset == 0) {
      GH_kprintf(
                  "ATI_PCIe:startupPCIeGART() (findPCICapability(kIOPCIPCIExpressCapability) failed, IGNORING...)\n"
                  );
      GH_IOSleep(10);
    }
    gartSize = M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB);
    if (gartSize != 0) {
      mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
      vramSize = loadWordByteReversed(&M<UInt8>(mmioBase + 0xf8));
      if (0x8000000 < vramSize) {
        vramSize = 0x8000000;
      }
      M<UInt32>(self + kIOATIR500Accelerator_gartReserveSize) = gartSize + 0x10000;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableVramOffset) = vramSize - gartSize;
      M<UInt32>(self + kIOATIR500Accelerator_gartReserveOffset) = vramSize - (gartSize + 0x10000);
      if (M<SInt32>(self + kIOATIR500Accelerator_vramApertureBase) != 0) {
        M<UInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) = (vramSize - gartSize) + M<SInt32>(self + kIOATIR500Accelerator_vramApertureBase);
      }
      if (M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable) == 0) {
        primaryEntry = (UInt32 *)GH_IOMallocAligned(gartSize,GH_page_size);
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
          gartSize = M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB);
          entriesLeft = gartSize >> 2;
          if (entriesLeft != 0) {
            emptyEntry = M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry);
            do {
              *primaryEntry = emptyEntry << 0x18 | (emptyEntry & 0xff00) << 8 | emptyEntry >> 8 & 0xff00 | emptyEntry >> 0x18;
              primaryEntry = primaryEntry + 1;
              entriesLeft = entriesLeft - 1;
            } while (entriesLeft != 0);
          }
        }
        else {
          gartSize = M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB);
          entriesFilled = 0;
          entriesLeft = gartSize >> 2;
          if (entriesLeft != 0) {
            emptyEntry = M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry);
            entriesFilled = 0;
            secondEntry = secondTable;
            do {
              *secondEntry = emptyEntry << 0x18 | (emptyEntry & 0xff00) << 8 | emptyEntry >> 8 & 0xff00 | emptyEntry >> 0x18;
              *primaryEntry = emptyEntry << 0x18 | (emptyEntry & 0xff00) << 8 | emptyEntry >> 8 & 0xff00 | emptyEntry >> 0x18;
              entriesFilled = entriesFilled + 1;
              secondEntry = secondEntry + 1;
              primaryEntry = primaryEntry + 1;
              entriesLeft = entriesLeft - 1;
            } while (entriesLeft != 0);
            entriesFilled = entriesFilled * 4;
          }
          registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
          M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
               loadWordByteReversed(&M<UInt8>(registers + 0x130));
          flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
          M<UInt32>(registers + 0x130) =
               flushValue << 0x18 | (flushValue & 0xff00) << 8 | (flushValue & 0xff0000) >> 8 |
               (flushValue | 0x8000000) >> 0x18;
          flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
          M<UInt32>(registers + 0x130) =
               flushValue << 0x18 | (flushValue & 0xff00) << 8 | flushValue >> 8 & 0xff00 | flushValue >> 0x18;
          M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
               loadWordByteReversed(&M<UInt8>((SInt32)secondTable + entriesFilled + -4));
        }
      }
      else {
      }
      widthTriesLeft = 0xc;
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
      tableWidth = 0x800;
      M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferTilingDegreeBits) = M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferTilingDegreeBits) & 0xff0007ff | 0x111000;
      do {
        if (gartSize == (gartSize / tableWidth) * tableWidth) {
          M<SInt16>(self + kIOATIR500Accelerator_gartTableBufferActiveWidth) = (SInt16)tableWidth;
          M<UInt32>(self + kIOATIR500Accelerator_gartTableElementBAlignMask) = 0;
          M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferSize) = gartSize;
          M<SInt16>(self + kIOATIR500Accelerator_gartTableBufferWidth) = (SInt16)tableWidth;
          M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferBytesPerPixel) = 4;
          M<SInt16>(self + kIOATIR500Accelerator_gartTableBufferPitch) = (SInt16)(tableWidth << 2);
          M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferGpuBaseAddress) = M<UInt32>(self + kIOATIR500Accelerator_gartTableVramOffset);
          self[0xbfc] = 0x0;
          self[0xbfd] = 0x0;
          M<UInt32>(self + kIOATIR500Accelerator_gartTableElementB) = 0;
          M<UInt32>(self + kIOATIR500Accelerator_gartTableElementBPrev) = 0;
          M<UInt32>(self + kIOATIR500Accelerator_gartTableElementBOffset) = 0;
          self[0xbfb] = 0xff;
          self[0xbff] = 0x6;
          self[0xbfe] = 0xb;
          M<SInt16>(self + kIOATIR500Accelerator_gartTableBufferActiveHeight) = (SInt16)(gartSize / (tableWidth << 2));
          if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80) == 0) {
            M<UInt32>(self + kIOATIR500Accelerator_gartEntryBase) = 0;
          }
          else {
            M<UInt32>(self + kIOATIR500Accelerator_gartEntryBase) = 1;
          }
          self[0x990] = ((char)self[0x990] + -1);
          mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
          M<UInt32>(mmioBase + 0xb5c) =
               (UInt32)(M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferPitch) >> 3) << 0x18 |
               (M<UInt16>(self + kIOATIR500Accelerator_gartTableBufferPitch) >> 3 & 0xff00) << 8 |
               (((UInt8)self[0xbfc] & 7) << 0x10 | ((UInt8)self[0xbfd] & 3) << 0x14 |
               ((UInt8)self[0xbfd] & 3) << 0x16) >> 8;
          enforceInOrderExecutionIO();
          tableGpuBase = M<UInt32>(self + kIOATIR500Accelerator_gartTableBufferGpuBaseAddress);
          M<UInt32>(mmioBase + 0xb54) =
               tableGpuBase << 0x18 | (tableGpuBase & 0xff00) << 8 | tableGpuBase >> 8 & 0xff00 | tableGpuBase >> 0x18;
          enforceInOrderExecutionIO();
          tableGpuEnd = (tableGpuBase + M<SInt32>(self + kIOATIR500Accelerator_gartTableBufferSize)) - 1;
          M<UInt32>(mmioBase + 0xb58) =
               tableGpuEnd * 0x1000000 | (tableGpuEnd & 0xff00) << 8 | tableGpuEnd >> 8 & 0xff00 | tableGpuEnd >> 0x18;
          enforceInOrderExecutionIO();
          return 1;
        }
        tableWidth = tableWidth >> 1;
        widthTriesLeft = widthTriesLeft + -1;
      } while (widthTriesLeft != 0);
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
    ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->dealloc((GLKMemoryElement *)(self + kIOATIR500Accelerator_gartTableBuffer));
  }
  M<UInt32>(self + kIOATIR500Accelerator_gartTableVramOffset) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartReserveOffset) = 0;
  return;
}

/* real addr 0x1dcd0 */
void ATIRadeonX1000::pageOnPCIeGART() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 secondTable;
  SInt32 registers;
  UInt32 entryIndex;
  SInt32 copiedBytes;
  SInt32 lastEntryEnd;
  UInt32 flushValue;
  
  secondTable = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
  if (secondTable != 0) {
    copiedBytes = 0;
    entryIndex = 0;
    if (M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2 != 0) {
      while( true ) {
        M<UInt32>(secondTable + entryIndex * 4) = M<UInt32>(M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable) + entryIndex * 4);
        enforceInOrderExecutionIO();
        entryIndex = entryIndex + 1;
        if (M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2 <= entryIndex) break;
        secondTable = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
      }
      secondTable = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
      copiedBytes = entryIndex * 4;
    }
    enforceInOrderExecutionIO();
    registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
         loadWordByteReversed(&M<UInt8>(registers + 0x130));
    flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
    M<UInt32>(registers + 0x130) =
         flushValue << 0x18 | (flushValue & 0xff00) << 8 | (flushValue & 0xff0000) >> 8 |
         (flushValue | 0x8000000) >> 0x18;
    flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
    M<UInt32>(registers + 0x130) =
         flushValue << 0x18 | (flushValue & 0xff00) << 8 | flushValue >> 8 & 0xff00 | flushValue >> 0x18;
    lastEntryEnd = copiedBytes + secondTable;
    M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
         loadWordByteReversed(&M<UInt8>(lastEntryEnd + -4));
    return;
  }
  return;
}

/* real addr 0x1dd80 */
IOReturn ATIRadeonX1000::addToPCIeGART(IOMemoryDescriptor *descriptor, UInt32 *outOffset, UInt32 minOffset, UInt32 maxOffset) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *descriptorBytes = reinterpret_cast<UInt8 *>(descriptor);
    UInt8 *outOffsetBytes = reinterpret_cast<UInt8 *>(outOffset);

  UInt32 gartEntries;
  UInt32 entry;
  UInt32 pageCount;
  SInt32 pageIndex;
  SInt32 pageTable;
  UInt32 entryBits;
  UInt8 *entryScan;
  SInt32 entryOffset;
  SInt32 secondTable;
  UInt32 segmentLength [6];
  UInt32 pageSize;
  UInt32 flushValue;
  UInt32 pageShift;
  UInt32 segmentAddress;
  UInt32 freeRun;
  SInt32 prepareResult;
  SInt32 segmentOffset;
  SInt32 secondTableBase;
  SInt32 secondTableEnd;
  SInt32 mmioBase;

  segmentLength[0] = 0;
  if ((descriptorBytes != 0) && (outOffsetBytes != 0)) {
    pageCount = VCALL(M<UInt32>(descriptorBytes), 0x128)(descriptorBytes);
    pageShift = GH_page_shift;
    gartEntries = M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB);
    M<UInt32>(outOffsetBytes) = 0;
    gartEntries = gartEntries >> 2;
    pageCount = pageCount >> (pageShift & 0x3f);
    if (gartEntries == 0) {
      if (pageCount == 0) {
        pageIndex = 0;
        pageCount = 0;
LAB_0001de4c:
        prepareResult = VCALL(M<UInt32>(descriptorBytes), 0x144)(descriptorBytes,3);
        if (prepareResult == 0) {
          segmentOffset = 0;
          M<SInt32>(outOffsetBytes) = pageIndex << (GH_page_shift & 0x3f);
          /* #167: the per-entry step is _page_size (stock 0x1de94 HA16/LO16 _page_size), NOT _page_shift
           * - the Ghidra dump labeled both zero-immediate data relocs alike; with the shift (12) as the
           * step each segment page wrote ~341 GART entries and ran off the end of the table. */
          while (segmentAddress = VCALL(M<UInt32>(descriptorBytes), 0x13c)(descriptorBytes,segmentOffset,segmentLength),
                pageSize = GH_page_size, segmentAddress != 0) {
            segmentOffset = segmentOffset + segmentLength[0];
            if (GH_page_size <= segmentLength[0]) {
              secondTable = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
              pageTable = M<SInt32>(self + kIOATIR500Accelerator_pcieGartTable);
              entryOffset = pageIndex << 2;
              entryBits = M<UInt32>(self + kIOATIR500Accelerator_gartEntryBase);
              do {
                if (secondTable != 0) {
                  entry = segmentAddress >> 8 | entryBits;
                  M<UInt32>(entryOffset + secondTable) =
                       (entry | 0xc) << 0x18 | (entry & 0xff00) << 8 | (entry & 0xff0000) >> 8 |
                       entryBits >> 0x18;
                }
                entry = segmentAddress >> 8 | entryBits;
                M<UInt32>(entryOffset + pageTable) =
                     (entry | 0xc) << 0x18 | (entry & 0xff00) << 8 | (entry & 0xff0000) >> 8 |
                     entryBits >> 0x18;
                segmentLength[0] = segmentLength[0] - pageSize;
                segmentAddress = segmentAddress + pageSize;
                pageIndex = pageIndex + 1;
                entryOffset = entryOffset + 4;
              } while (pageSize <= segmentLength[0]);
            }
          }
          enforceInOrderExecutionIO();
          secondTableBase = M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress);
          if (secondTableBase != 0) {
            mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
            M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
                 loadWordByteReversed(&M<UInt8>(mmioBase + 0x130));
            flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
            M<UInt32>(mmioBase + 0x130) =
                 flushValue << 0x18 | (flushValue & 0xff00) << 8 | (flushValue & 0xff0000) >> 8 |
                 (flushValue | 0x8000000) >> 0x18;
            flushValue = M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch);
            M<UInt32>(mmioBase + 0x130) =
                 flushValue << 0x18 | (flushValue & 0xff00) << 8 | flushValue >> 8 & 0xff00 | flushValue >> 0x18;
            secondTableEnd = pageIndex * 4 + secondTableBase;
            M<UInt32>(self + kIOATIR500Accelerator_gartFlushScratch) =
                 loadWordByteReversed(&M<UInt8>(secondTableEnd + -4));
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
      freeRun = 0;
      pageIndex = 0;
      do {
        freeRun = freeRun + 1;
        if ((loadWordByteReversed(entryScan)) != M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry)) {
          freeRun = 0;
        }
        pageIndex = pageIndex + 1;
        if (freeRun == pageCount) {
          pageIndex = pageIndex - pageCount;
          goto LAB_0001de4c;
        }
        entryScan = entryScan + 4;
        gartEntries = gartEntries - 1;
      } while (gartEntries != 0);
    }
  }
  return 0;
}
