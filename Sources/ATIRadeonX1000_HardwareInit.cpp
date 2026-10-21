/*
 * ATIRadeonX1000_HardwareInit.cpp
 *
 * RESOLVED (ledger pass): R520 pipe setup, display mode/VRAM setup, PM4 (promo4) microcode load/start/stop, R500 internal space, initialize_hardware.
 * Mechanically ported from the Ghidra decompile of the shipped kext (Tools/port_fn.py); real addresses in the markers.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 gl_assert_wait_timeout_event;
extern "C" UInt32 global_dummy_read_back_a_register;
extern "C" UInt32 GH_IODelay(...) asm("_IODelay");
extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOLog(...) asm("_IOLog");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");
extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_absolutetime_to_nanoseconds(...) asm("_absolutetime_to_nanoseconds");
extern "C" UInt32 GH_assert_wait_timeout(...) asm("_assert_wait_timeout");
extern "C" UInt32 GH_clock_get_uptime(...) asm("_clock_get_uptime");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");

extern "C" UInt32 aPM4_Microcode_R520[513];

/* real addr 0x1bd20 */
void ATIRadeonX1000::setupR520Pipes() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 zPipeConfig;
  SInt32 mmioBase;
  UInt32 pipeCountCode;
  UInt32 savedStrobeWord;
  UInt32 pipeMask;
  UInt32 tilePipeBits;
  
  enforceInOrderExecutionIO();
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  do {
    do {
    } while ((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0);
  } while (((((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0)) ||
           ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0)) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0));
  storeWordByteReversed(&M<UInt8>(mmioBase + 0x402c), loadWordByteReversed(&M<UInt8>(mmioBase + 0x402c)) | 0x40000);
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0);
  } while ((((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0)) ||
          (((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0 || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0))));
  pipeCountCode = loadWordByteReversed(&M<UInt8>(mmioBase + 0x402c)) >> 0xc & 3;
  pipeMask = (1 << pipeCountCode + 1) - 1;
  storeWordByteReversed(&M<UInt8>(mmioBase + 0x42c8), pipeMask);
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0);
  } while ((((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0)) ||
          (((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0 || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0))));
  if (pipeCountCode == 1) {
    tilePipeBits = 6;
    M<UInt32>(self + kIOATIR500Accelerator_numPipes) = 2;
  }
  else if (pipeCountCode == 0) {
LAB_0001bea0:
    tilePipeBits = 0;
    M<UInt32>(self + kIOATIR500Accelerator_numPipes) = 1;
  }
  else if (pipeCountCode == 2) {
    tilePipeBits = 0xc;
    M<UInt32>(self + kIOATIR500Accelerator_numPipes) = 3;
  }
  else {
    if (pipeCountCode != 3) goto LAB_0001bea0;
    tilePipeBits = 0xe;
    M<UInt32>(self + kIOATIR500Accelerator_numPipes) = 4;
  }
  M<UInt32>(self + kIOATIR500Accelerator_gbTileConfig) = tilePipeBits | 0xc00011;
  M<UInt32>(mmioBase + 0x4018) = (tilePipeBits | 0xc00011) << 0x18 | 0xc000;
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0);
  } while (((((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0)) ||
           ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0)) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0));
  storeWordByteReversed(&M<UInt8>(mmioBase + 0x170c), loadWordByteReversed(&M<UInt8>(mmioBase + 0x170c)) | 0x80000000);
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0);
  } while ((((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0)) ||
          (((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0 || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0))));
  M<UInt32>(mmioBase + 0x429c) = 0x40000;
  enforceInOrderExecutionIO();
  GH_IOSleep(1);
  enforceInOrderExecutionIO();
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  do {
    do {
    } while ((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0);
  } while ((((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0)) ||
          (((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0 || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0))));
  M<UInt32>(self + kIOATIR500Accelerator_numZPipes) = 1;
  if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x200000) == 0) {
    return;
  }
  /* #147/#155/#156-class bug (fixed 2026-10-08, same pattern as ATIRadeonX1000_Start.cpp's chip-ID/
   * chip-rev read): self+0x860[8..0xb] is a write-strobe/read-back MMIO register - write a modified
   * value to +8 to trigger a hardware latch, READ the latched data (here, +0xf) while still strobed,
   * THEN restore the original +8 value (confirmed via stock's own disassembly,
   * ATIRadeonX1000::setupR520Pipes ~0x1bff4-0x1c014, lwbrx/stwbrx byte-reversed access). This read
   * was happening after the restore instead of between the strobe and the restore - moved to the
   * correct position, matching stock's real instruction order. This function was previously
   * unreachable on a hot-swapped instance (blocked by #147's original chip-ID bug), so this bug was
   * never exercised until #147/#156's real fix let setupR520Pipes() run for the first time. */
  savedStrobeWord = loadWordByteReversed(&M<UInt8>(mmioBase + 8));
  storeWordByteReversed(&M<UInt8>(mmioBase + 8), savedStrobeWord & 0xffffff40 | 0x34);
  zPipeConfig = (loadWordByteReversed(&M<UInt8>(mmioBase + 0xc)) ^ 0x30000000) >> 0x1c & 3;
  storeWordByteReversed(&M<UInt8>(mmioBase + 8), savedStrobeWord);
  if (zPipeConfig != 0) {
    if (zPipeConfig < 3) {
      M<UInt32>(self + kIOATIR500Accelerator_numZPipes) = 1;
      goto LAB_0001c040;
    }
    if (zPipeConfig == 3) {
      if (M<UInt32>(self + kIOATIR500Accelerator_chipRev) < 4) {
        zPipeConfig = 1;
        M<UInt32>(self + kIOATIR500Accelerator_numZPipes) = 1;
      }
      else {
        zPipeConfig = 3;
        M<UInt32>(self + kIOATIR500Accelerator_numZPipes) = 2;
      }
      goto LAB_0001c040;
    }
  }
  M<UInt32>(self + kIOATIR500Accelerator_numZPipes) = 1;
  zPipeConfig = 1;
LAB_0001c040:
  M<UInt32>(mmioBase + 0x4124) = zPipeConfig << 0x18;
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0);
  } while (((((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0)) ||
           ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0)) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0));
  M<UInt32>(mmioBase + 0x4be8) = zPipeConfig << 0x18;
  enforceInOrderExecutionIO();
  return;
}

/* real addr 0x1c120 */
bool ATIRadeonX1000::set_display_mode_and_vram() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 graphDepth;
  UInt8 graphFormat;
  UInt32 alignedHeight2;
  UInt32 display1Base;
  UInt32 usableSize;
  UInt32 memorySize;
  UInt32 scanout1Size;
  UInt8 storageFormat1;
  UInt8 storageFormat2;
  UInt16 bytesPerPixel16;
  UInt32 bytesPerPixel2;
  SInt32 registers;
  SInt32 queryResult;
  SInt32 pixelResult;
  SInt32 modeResult;
  SInt32 reserved;
  SInt32 poolReady;
  UInt32 reg16c4Bits;
  UInt32 halfVramMask;
  UInt32 display2Width;
  UInt32 mcRegionSize;
  UInt32 scanout2Size;
  UInt32 display2Base;
  UInt32 pixelFormat;
  UInt32 vramSize;
  UInt32 bytesPerPixel;
  UInt32 pitch;
  UInt8 crtc2Enable;
  UInt32 display1BaseKiB;
  UInt8 pixelFormatByte2;
  UInt32 alignedHeight1;
  UInt32 pixelFormat2;
  UInt32 scanout1PadSize;
  UInt32 pitchRegBits;
  UInt32 scanout2PadSize;
  UInt32 display1Width;
  UInt32 pitchAlignMask;
  UInt32 pitch2;
  UInt32 display2BaseKiB;
  /* One 0xa8-byte stack object (r1+0x58..): Ghidra named its slots separately. getCurrentDisplayMode fills f8/f4 and getPixelInformation fills
   `pix` AND the two words after it (L.activeWidth / L.activeHeight), so they must be one object: as separate scalars the compiler saw L.activeWidth/L.activeHeight
   as never written and deleted the branches that read them (4 of the 10 ATIR500Memory::reserve calls, #85). */
  struct { UInt32 f8; UInt32 f4; UInt8 pix[156]; UInt32 activeWidth; UInt32 activeHeight; UInt32 reserved[3]; } L;
  /* `reserved` is the tail of IOPixelInformation (sizeof 0xb0 = pix + activeWidth/activeHeight + reserved[3]): getPixelInformation fills all of it, and
   without these 12 bytes it overran L into whatever the compiler placed next (spill slots) - harmless by luck in the 2c54898 layout, a zeroed
   GLKMemoryElement* (NULL deref in ATIR500Memory::reserve) once a rename changed the slot order (hot-swap panic 2026-10-17). */
  
  self[0x168] = 0x0;
  M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferField22) = 1;
  self[0x167] = 0x6;
  M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferField20) = 1;
  self[0x160] = 0x0;
  self[0x163] = 0xff;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferMipOffset1) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1Buffer) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferElementPrev) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferGpuBaseAddress) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferAlignMask) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferSize) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferWidth) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferBytesPerPixel) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferPitch) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferActiveWidth) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferActiveHeight) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferBackingStoreHandle) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferHzBlockField) = 0xffffffff;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferHzBlockExtra) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferHzBlockCountField) = 0;
  self[0x161] = 0x0;
  self[0x162] = 0x0;
  self[0x164] = 0x0;
  self[0x165] = 0x0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferMipOffset0) = 0;
  registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferTilingDegreeBits) = M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferTilingDegreeBits) & 0xff0007ff | 0x111000;
  memorySize = loadWordByteReversed(&M<UInt8>(registers + 0xf8));
  M<UInt32>(self + kIOATIR500Accelerator_vramSize) = memorySize;
  if (memorySize == 0) {
    M<UInt32>(self + kIOATIR500Accelerator_vramSize) = 0x800000;
  }
  vramSize = M<UInt32>(self + kIOATIR500Accelerator_vramSize);
  if (vramSize < 0x8000001) {
    M<UInt32>(self + kIOATIR500Accelerator_usableVramSize) = vramSize;
  }
  else {
    M<UInt32>(self + kIOATIR500Accelerator_usableVramSize) = 0x8000000;
  }
  usableSize = M<UInt32>(self + kIOATIR500Accelerator_usableVramSize);
  M<UInt32>(self + kIOATIR500Accelerator_displayConfigBits) = 0;
  halfVramMask = (usableSize >> 1) - 1;
  if (vramSize == usableSize) {
    poolReady = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->init_pool(usableSize);
    if (poolReady == 0) {
      return 0;
    }
    ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->init_pool(M<UInt32>(self + kIOATIR500Accelerator_vramSize));
  }
  else {
    poolReady = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->init_pool(vramSize, usableSize, 0);
    if (poolReady == 0) {
      return 0;
    }
    ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->init_pool(M<UInt32>(self + kIOATIR500Accelerator_vramSize),M<UInt32>(self + kIOATIR500Accelerator_usableVramSize),0)
    ;
  }
  if (M<UInt32>(self + kIOATIR500Accelerator_gartReserveOffset) != 0) {
    reserved = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_gartTableBuffer),
                        M<UInt32>(self + kIOATIR500Accelerator_gartReserveOffset),M<UInt32>(self + kIOATIR500Accelerator_gartReserveSize));
    if (reserved == 0) {
      return 0;
    }
    ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_gartTableElementB),
               M<UInt32>(self + kIOATIR500Accelerator_gartReserveOffset),M<UInt32>(self + kIOATIR500Accelerator_gartReserveSize));
  }
  registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  if ((loadWordByteReversed(&M<UInt8>(registers + 0x6110))) !=
      M<UInt32>(self + kIOATIR500Accelerator_display1SurfaceAddressSeen)) {
    M<UInt32>(self + kIOATIR500Accelerator_display1SurfaceAddress) =
         loadWordByteReversed(&M<UInt8>(registers + 0x6110));
    M<UInt32>(self + kIOATIR500Accelerator_display1SurfaceAddressB) =
         loadWordByteReversed(&M<UInt8>(registers + 0x6120));
  }
  display1Base = M<UInt32>(self + kIOATIR500Accelerator_display1SurfaceAddress);
  display1Width = M<UInt32>(self + kIOATIR500Accelerator_display1SurfaceAddressB);
  modeResult = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer0), 0x5f0)
                     (M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer0),&L.f4,&L.f8);
  if (modeResult != 0) {
    GH_IOLog("ERROR: VendorAccelerator::set_display_mode_and_vram() call to fFramebuffers[0].framebuffer->getCurrentDisplayMode() result:%lX\n"
                 ,modeResult);
    GH_IOSleep(10);
  }
  pixelResult = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer0), 0x5ec)
                     (M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer0),L.f4,L.f8,0,L.pix);
  if (pixelResult != 0) {
    GH_IOLog("ERROR: VendorAccelerator::set_display_mode_and_vram() call to fFramebuffers[0].framebuffer->getPixelInformation() result:%lX\n"
                 ,pixelResult);
    GH_IOSleep(10);
  }
  if (L.activeWidth != 0) {
    display1Width = L.activeWidth;
  }
  registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  reg16c4Bits = loadWordByteReversed(&M<UInt8>(registers + 0x16c4)) & 0xfffffff0;
  if ((loadWordByteReversed(&M<UInt8>(registers + 0x6080)) & 1) == 0) {
    scanout1Size = 0;
    pitch = 0;
    pitchAlignMask = 0;
  }
  else {
    graphDepth = loadWordByteReversed(&M<UInt8>(registers + 0x6104)) & 3;
    graphFormat = loadWordByteReversed(&M<UInt8>(registers + 0x6104)) >> 8 & 7;
    if (graphDepth == 1) {
      pixelFormat = 4;
      if (((graphFormat != 1) && (pixelFormat = 3, graphFormat != 0)) && (pixelFormat = 0xf, graphFormat != 2))
      goto LAB_0001c414;
    }
    else {
      if (graphDepth == 0) {
        pixelFormat = 9;
joined_r0x0001c43c:
        if (graphFormat == 0) goto LAB_0001c418;
      }
      else if (graphDepth == 2) {
        pixelFormat = 6;
        if ((graphFormat == 0) || (pixelFormat = 5, graphFormat == 1)) goto LAB_0001c418;
      }
      else if (graphDepth == 3) {
        pixelFormat = 10;
        goto joined_r0x0001c43c;
      }
LAB_0001c414:
      pixelFormat = 0xff;
    }
LAB_0001c418:
    M<UInt32>(self + kIOATIR500Accelerator_display1Enabled) = loadWordByteReversed(&M<UInt8>(registers + 0x6088)) & 1;
    if (pixelFormat == 6) {
      reg16c4Bits = reg16c4Bits | 6;
      M<UInt32>(registers + 0x15d4) = 0x2000000;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x15d0) = 0x2000000;
      enforceInOrderExecutionIO();
      storageFormat1 = 0xb;
      bytesPerPixel = 4;
      bytesPerPixel16 = 4;
    }
    else {
      if (pixelFormat < 7) {
        if (pixelFormat - 3 < 2) {
          reg16c4Bits = reg16c4Bits | 3;
          M<UInt32>(registers + 0x15d4) = 0x1000000;
          enforceInOrderExecutionIO();
          M<UInt32>(registers + 0x15d0) = 0x1000000;
          enforceInOrderExecutionIO();
          storageFormat1 = 0x7;
          bytesPerPixel = 2;
          bytesPerPixel16 = 2;
          goto LAB_0001c54c;
        }
      }
      else if (pixelFormat == 9) {
        reg16c4Bits = reg16c4Bits | 2;
        M<UInt32>(registers + 0x15d4) = 0;
        enforceInOrderExecutionIO();
        M<UInt32>(registers + 0x15d0) = 0;
        enforceInOrderExecutionIO();
      }
      storageFormat1 = 0x1;
      bytesPerPixel = 1;
      bytesPerPixel16 = 1;
    }
LAB_0001c54c:
    storeWordByteReversed(&M<UInt8>(registers + 0x16c4), reg16c4Bits);
    enforceInOrderExecutionIO();
    pitch = display1Width * bytesPerPixel + 0xff & 0xffffff00;
    if (bytesPerPixel != 0) {
      display1Width = pitch / bytesPerPixel;
    }
    alignedHeight1 = L.activeHeight;
    if ((L.activeHeight & 0xf) != 0) {
      alignedHeight1 = (L.activeHeight & 0xfffffff0) + 0x10;
    }
    scanout1Size = alignedHeight1 * pitch;
    M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferBytesPerPixel) = bytesPerPixel16;
    storeHalf(&M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferWidth), display1Width);
    storeHalf(&M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferActiveWidth), (SInt16)L.activeWidth);
    storeHalf(&M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferActiveHeight), (SInt16)L.activeHeight);
    self[0x163] = 0xff;
    M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferGpuBaseAddress) = display1Base;
    storeHalf(&M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferPitch), pitch);
    M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferSize) = scanout1Size;
    if ((loadWordByteReversed(&M<UInt8>(registers + 0x6104)) & 0x100000) == 0) {
      self[0x164] = (loadWordByteReversed(&M<UInt8>(registers + 0x6104)) >> 0x15 & 1);
    }
    else {
      self[0x164] = 0x3;
    }
    self[0x167] = SUB41m(pixelFormat,0);
    self[0x166] = storageFormat1;
    M<UInt32>(self + kIOATIR500Accelerator_displayConfigBits) = 1;
    pitchAlignMask = 0xff;
    self[0x165] = ('\x01' - (char)((SInt32)-(bytesPerPixel ^ 2) >> 0x1f));
  }
  if (((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x10000) == 0) || (M<UInt32>(self + kIOATIR500Accelerator_displayCount) < 2)) {
    display2Base = 0;
    mcRegionSize = 0x200000;
    goto LAB_0001c9b0;
  }
  crtc2Enable = loadWordByteReversed(&M<UInt8>(registers + 0x6880)) & 1;
  M<UInt32>(self + kIOATIR500Accelerator_scanoutOverlapsVram) = 0;
  if ((loadWordByteReversed(&M<UInt8>(registers + 0x6910))) !=
      M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddressSeen)) {
    M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddress) =
         loadWordByteReversed(&M<UInt8>(registers + 0x6910));
    M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddressB) =
         loadWordByteReversed(&M<UInt8>(registers + 0x6920));
  }
  display2Base = M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddress);
  display2Width = M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddressB);
  if (((((crtc2Enable & 1) == 0) || (M<UInt32>(self + kIOATIR500Accelerator_vramSize) <= display2Base)) ||
      (queryResult = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer1), 0x5f0)
                          (M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer1),&L.f8,&L.f4), queryResult != 0)) ||
     (queryResult = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer1), 0x5ec)
                         (M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer1),L.f8,L.f4,0,L.pix), queryResult != 0)) {
    display2Base = 0;
    mcRegionSize = 0x200000;
    M<UInt32>(self + kIOATIR500Accelerator_scanout2BufferSize) = 0;
    M<UInt32>(self + kIOATIR500Accelerator_scanout2BufferGpuBaseAddress) = 0;
    goto LAB_0001c9b0;
  }
  if (L.activeWidth != 0) {
    display2Width = L.activeWidth;
  }
  registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  graphDepth = loadWordByteReversed(&M<UInt8>(registers + 0x6904)) & 3;
  graphFormat = loadWordByteReversed(&M<UInt8>(registers + 0x6904)) >> 8 & 7;
  if (graphDepth == 1) {
    if (graphFormat == 1) {
      pixelFormat2 = 4;
      pixelFormatByte2 = 0x4;
    }
    else if (graphFormat == 0) {
      pixelFormat2 = 3;
      pixelFormatByte2 = 0x3;
    }
    else {
      if (graphFormat != 2) goto LAB_0001c710;
      pixelFormat2 = 0xf;
      pixelFormatByte2 = 0xf;
    }
  }
  else if (graphDepth == 0) {
    if (graphFormat == 0) {
      pixelFormat2 = 9;
      pixelFormatByte2 = 0x9;
    }
    else {
LAB_0001c710:
      pixelFormat2 = 0xff;
      pixelFormatByte2 = 0xff;
    }
  }
  else if (graphDepth == 2) {
    if (graphFormat == 0) {
      pixelFormat2 = 6;
      pixelFormatByte2 = 0x6;
    }
    else {
      if (graphFormat != 1) goto LAB_0001c710;
      pixelFormat2 = 5;
      pixelFormatByte2 = 0x5;
    }
  }
  else {
    if ((graphDepth != 3) || (graphFormat != 0)) goto LAB_0001c710;
    pixelFormat2 = 10;
    pixelFormatByte2 = 0xa;
  }
  M<UInt32>(self + kIOATIR500Accelerator_display2Enabled) = loadWordByteReversed(&M<UInt8>(registers + 0x6888)) & 1;
  if (pixelFormat2 < 3) {
LAB_0001c7d0:
    storageFormat2 = 0x1;
    bytesPerPixel2 = 1;
    bytesPerPixel16 = 1;
  }
  else if (pixelFormat2 < 5) {
    storageFormat2 = 0x7;
    bytesPerPixel2 = 2;
    bytesPerPixel16 = 2;
  }
  else {
    if (pixelFormat2 != 6) goto LAB_0001c7d0;
    storageFormat2 = 0xb;
    bytesPerPixel2 = 4;
    bytesPerPixel16 = 4;
  }
  pitch2 = pitchAlignMask + display2Width * bytesPerPixel2 & ~pitchAlignMask;
  if (bytesPerPixel2 != 0) {
    display2Width = pitch2 / bytesPerPixel2;
  }
  alignedHeight2 = L.activeHeight;
  if ((L.activeHeight & 0xf) != 0) {
    alignedHeight2 = (L.activeHeight & 0xfffffff0) + 0x10;
  }
  scanout2Size = alignedHeight2 * pitch2;
  storeHalf(&M<UInt16>(self + kIOATIR500Accelerator_scanout2BufferPitch), pitch2);
  M<UInt16>(self + kIOATIR500Accelerator_scanout2BufferBytesPerPixel) = bytesPerPixel16;
  storeHalf(&M<UInt16>(self + kIOATIR500Accelerator_scanout2BufferWidth), display2Width);
  storeHalf(&M<UInt16>(self + kIOATIR500Accelerator_scanout2BufferActiveWidth), (SInt16)L.activeWidth);
  storeHalf(&M<UInt16>(self + kIOATIR500Accelerator_scanout2BufferActiveHeight), (SInt16)L.activeHeight);
  self[0x1db] = 0xff;
  M<UInt32>(self + kIOATIR500Accelerator_scanout2BufferGpuBaseAddress) = display2Base;
  M<UInt32>(self + kIOATIR500Accelerator_scanout2BufferSize) = scanout2Size;
  if ((loadWordByteReversed(&M<UInt8>(registers + 0x6904)) & 0x100000) == 0) {
    self[0x1dc] = (loadWordByteReversed(&M<UInt8>(registers + 0x6904)) >> 0x15 & 1);
  }
  else {
    self[0x1dc] = 0x3;
  }
  self[0x1df] = pixelFormatByte2;
  self[0x1de] = storageFormat2;
  M<UInt32>(self + kIOATIR500Accelerator_displayConfigBits) = M<UInt32>(self + kIOATIR500Accelerator_displayConfigBits) | 2;
  self[0x1dd] = ('\x01' - (char)((SInt32)-(bytesPerPixel2 ^ 2) >> 0x1f));
  if ((display2Base < display1Base) || (scanout1Size + display1Base <= display2Base)) {
    if ((display2Base <= display1Base) && (display1Base < display2Base + scanout2Size)) {
      if (display2Base + scanout2Size < scanout1Size + display1Base) {
        scanout2Size = (scanout1Size + display1Base) - display2Base;
      }
      scanout1Size = 0;
      M<UInt32>(self + kIOATIR500Accelerator_scanoutOverlapsVram) = 1;
    }
    if (scanout2Size != 0) {
      reserved = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout2Buffer),display2Base
                          ,scanout2Size);
      if (reserved == 0) {
        return 0;
      }
      ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout2ElementB),display2Base,scanout2Size)
      ;
      scanout2PadSize = halfVramMask & display2Base;
      if (scanout2PadSize != 0) {
        reserved = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout2PadElement),
                            display2Base - scanout2PadSize,scanout2PadSize);
        if (reserved == 0) {
          return 0;
        }
        mcRegionSize = 0xa00000;
        ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout2PadElementB),
                   display2Base - scanout2PadSize,scanout2PadSize);
        goto LAB_0001c9b0;
      }
    }
    mcRegionSize = 0xa00000;
  }
  else {
    if (scanout1Size + display1Base < display2Base + scanout2Size) {
      scanout1Size = (display2Base + scanout2Size) - display1Base;
    }
    mcRegionSize = 0xa00000;
    M<UInt32>(self + kIOATIR500Accelerator_scanoutOverlapsVram) = 1;
  }
LAB_0001c9b0:
  if (scanout1Size != 0) {
    reserved = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout1Buffer),display1Base,
                        scanout1Size);
    if (reserved == 0) {
      return 0;
    }
    ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout1ElementB),display1Base,scanout1Size);
    scanout1PadSize = halfVramMask & display1Base;
    if (scanout1PadSize != 0) {
      reserved = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout1PadElement),
                          display1Base - scanout1PadSize,scanout1PadSize);
      if (reserved == 0) {
        return 0;
      }
      ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout1PadElementB),display1Base - scanout1PadSize
                 ,scanout1PadSize);
    }
  }
  registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  M<UInt32>(registers + 0xb00) = mcRegionSize >> 8 | 0x1000000;
  pitchRegBits = (pitch & 0x3f00) << 0x10;
  display1BaseKiB = display1Base >> 10;
  storeWordByteReversed(&M<UInt8>(registers + 0x16e0), (display1BaseKiB & 0xff) | (display1BaseKiB & 0xff00) | (display1BaseKiB & 0x3f0000) | ((pitchRegBits | 0x40000000) & 0xff000000));
  enforceInOrderExecutionIO();
  if (display2Base != 0) {
    display2BaseKiB = display2Base >> 10;
    storeWordByteReversed(&M<UInt8>(registers + 0x16f8), (display2BaseKiB & 0xff) | (display2BaseKiB & 0xff00) | (display2BaseKiB & 0x3f0000) | ((pitchRegBits | 0x40000000) & 0xff000000));
    enforceInOrderExecutionIO();
    return 1;
  }
  return 1;
}

/* real addr 0x1cb00 */
bool ATIRadeonX1000::stop_promo4_engine() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool stillCounting;
  UInt32 ringControl;
  SInt32 mmioBase;
  SInt32 timeoutCount;
  
  self[0x80] = 0x0;
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  if (mmioBase != 0) {
    enforceInOrderExecutionIO();
    timeoutCount = 1000;
    while ((((((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0 ||
              ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0)) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0)) ||
            (((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0 || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0)))) &&
           (stillCounting = timeoutCount != 0, timeoutCount = timeoutCount + -1, stillCounting))) {
      GH_IODelay(100);
      mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    }
    M<UInt32>(mmioBase + 0x770) = 0;
    enforceInOrderExecutionIO();
    storeWordByteReversed(&M<UInt8>(mmioBase + 0x704), loadWordByteReversed(&M<UInt8>(mmioBase + 0x704)) | 0x8000000);
    enforceInOrderExecutionIO();
    M<UInt32>(mmioBase + 0x744) = 0;
    enforceInOrderExecutionIO();
    (void)loadWordByteReversed(&M<UInt8>(mmioBase + 0x744));       /* read-back of the register just written (the shipped code does it) */
    ringControl = loadWordByteReversed(&M<UInt8>(mmioBase + 0x704));
    storeWordByteReversed(&M<UInt8>(mmioBase + 0x704), ringControl | 0x80000000);
    enforceInOrderExecutionIO();
    M<UInt32>(mmioBase + 0x71c) = 0;
    enforceInOrderExecutionIO();
    M<UInt32>(mmioBase + 0x714) = 0;
    enforceInOrderExecutionIO();
    storeWordByteReversed(&M<UInt8>(mmioBase + 0x704), ringControl & 0x7fffffff);
    enforceInOrderExecutionIO();
    enforceInOrderExecutionIO();
    timeoutCount = 1000;
    while (((((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0 ||
             ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0)) ||
            (((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0 ||
             (((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0 || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0))))))
           && (stillCounting = timeoutCount != 0, timeoutCount = timeoutCount + -1, stillCounting))) {
      GH_IODelay(100);
      mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    }
    enforceInOrderExecutionIO();
    timeoutCount = 1000;
    while ((((((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0 ||
              ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0)) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0)) ||
            (((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0 || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0)))) &&
           (stillCounting = timeoutCount != 0, timeoutCount = timeoutCount + -1, stillCounting))) {
      GH_IODelay(100);
      mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    }
  }
  return 1;
}

/* real addr 0x1cd30 */
void ATIRadeonX1000::load_promo4_micro_code() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 microcodeWord;
  UInt32 *microcodeCursor;
  SInt32 mmioBase;
  SInt32 pairsLeft;
  
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  M<UInt32>(mmioBase + 0x7d4) = 0;
  enforceInOrderExecutionIO();
  pairsLeft = 0x100;
  microcodeCursor = aPM4_Microcode_R520 + 1;
  do {
    microcodeWord = *microcodeCursor;
    storeWordByteReversed(&M<UInt8>(mmioBase + 0x7dc), microcodeWord);
    enforceInOrderExecutionIO();
    microcodeWord = microcodeCursor[-1];
    storeWordByteReversed(&M<UInt8>(mmioBase + 0x7e0), microcodeWord);
    enforceInOrderExecutionIO();
    microcodeCursor = microcodeCursor + 2;
    pairsLeft = pairsLeft + -1;
  } while (pairsLeft != 0);
  return;
}

/* real addr 0x1cd90 */
bool ATIRadeonX1000::start_promo4_engine(UInt32 mode) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool notLastDisplay;
  UInt32 ringWritePointer;
  UInt32 rptrWritebackAddress;
  UInt32 rbbmStatus;
  UInt8 *displayRecord;
  UInt32 ringReadPointer;
  SInt32 mmioBase;
  SInt32 displayIndex;
  SInt32 spinCount;
  SInt32 ringPointerBase;
  SInt32 registers;
  UInt32 ringControl;
  
  enforceInOrderExecutionIO();
  registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  ringControl = loadWordByteReversed(&M<UInt8>(registers + 0x704)) & 0x77f0c0ff | 0xa000a;
  storeWordByteReversed(&M<UInt8>(registers + 0x704), ringControl);
  enforceInOrderExecutionIO();
  load_promo4_micro_code();
  if (mode == 4) {
    mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    M<UInt32>(mmioBase + 0x718) = 0x23000000;
    enforceInOrderExecutionIO();
    ringReadPointer = loadWordByteReversed(&M<UInt8>(mmioBase + 0x710));
    ringWritePointer = ringReadPointer & 0x7ff;
    M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = ringReadPointer;
    storeWordByteReversed(&M<UInt8>(mmioBase + 0x714), ringWritePointer);
    enforceInOrderExecutionIO();
    M<UInt32>(self + kIOATIR500Accelerator_mainRingCursor) = ringReadPointer;
    ringPointerBase = M<SInt32>(self + kIOATIR500Accelerator_ringPointerBase);
    storeWordByteReversed(&M<UInt8>(ringPointerBase + M<SInt32>(self + kIOATIR500Accelerator_ringWritePointerOffset)), ringWritePointer);
    enforceInOrderExecutionIO();
    if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80000) == 0) {
      rptrWritebackAddress = M<SInt32>(self + kIOATIR500Accelerator_vramSizeProgrammed) + M<SInt32>(self + kIOATIR500Accelerator_scratchBufferGartOffset) + (ringPointerBase - M<SInt32>(self + kIOATIR500Accelerator_scratchHeader));
      storeWordByteReversed(&M<UInt8>(mmioBase + 0x70c), ((rptrWritebackAddress & 0xfffffffc) & 0xff) | (rptrWritebackAddress & 0xff00) | (rptrWritebackAddress & 0xff0000) | (rptrWritebackAddress & 0xff000000));
      enforceInOrderExecutionIO();
    }
    M<UInt32>(mmioBase + 0x740) = 0x40;
    enforceInOrderExecutionIO();
    spinCount = 0;
    while( true ) {
      rbbmStatus = loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40));
      spinCount = spinCount + 1;
      GH_IOSleep(1);
      if ((rbbmStatus & 0x10200) == 0) break;
      if (spinCount == 0xf4241) {
        return 0;
      }
      mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    }
    if (spinCount != 0xf4241) {
      if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80000) == 0) {
        ringControl = ringControl & 0xf7ffffff;
      }
      storeWordByteReversed(&M<UInt8>(M<SInt32>(self + kIOATIR500Accelerator_mmioBase) + 0x704), ringControl);
      enforceInOrderExecutionIO();
      displayIndex = 0;
      displayRecord = self;
      do {
        if (M<SInt32>(displayRecord + 0xe4) != 0) {
          self[0x80] = 0x1;
          return 1;
        }
        notLastDisplay = displayIndex != 1;
        displayRecord = displayRecord + 0x20;
        displayIndex = displayIndex + 1;
      } while (notLastDisplay);
      return 1;
    }
  }
  return 0;
}

/* real addr 0x1cf70 */
void ATIRadeonX1000::setup_R500_internal_space() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool mcIndexIsR520;
  UInt32 display1Address;
  UInt32 display2Address;
  UInt32 fbStart16;
  SInt32 mmioBase;
  SInt32 stampPageGartOffset;
  UInt32 gartTableOffset;
  UInt32 chipFlags;
  UInt32 fbEnd;
  UInt32 mcSizeReg108;
  UInt32 newReg130;
  UInt32 reg130Value;
  UInt32 stampPageAddress;
  UInt32 mainRingAddress;
  UInt32 vramLimit;
  UInt32 display2AddressRebased;
  UInt32 gartEnd;
  
  enforceInOrderExecutionIO();
  ppcSync();
  instructionSynchronize();
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  M<UInt32>(mmioBase + 0x740) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x744) = 0;
  enforceInOrderExecutionIO();
  chipFlags = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits);
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x8fc) = 0;
  if ((chipFlags & 0x400000) == 0) {
    M<UInt32>(mmioBase + 0x70) = 0x4007f00;
    enforceInOrderExecutionIO();
  }
  else {
    M<UInt32>(mmioBase + 0x70) = 0x1007f00;
    enforceInOrderExecutionIO();
  }
  fbStart16 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x74)) & 0xffff;
  if (fbStart16 != 0) {
    vramLimit = loadWordByteReversed(&M<UInt8>(mmioBase + 0xf8));
    if (vramLimit == 0) {
      vramLimit = 0x8000000;
    }
    reg130Value = loadWordByteReversed(&M<UInt8>(mmioBase + 0x130));
    mcSizeReg108 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x108));
    newReg130 = reg130Value & 0xff7fffff;
    if ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x104))) ==
        mcSizeReg108 + (loadWordByteReversed(&M<UInt8>(mmioBase + 0x100)))) {
      mcSizeReg108 = mcSizeReg108 << 1;
      newReg130 = reg130Value | 0x800000;
    }
    if (mcSizeReg108 < vramLimit) {
      storeWordByteReversed(&M<UInt8>(mmioBase + 0xf8), mcSizeReg108);
      enforceInOrderExecutionIO();
      M<UInt32>(self + kIOATIR500Accelerator_vramSizeProgrammed) =
           loadWordByteReversed(&M<UInt8>(mmioBase + 0xf8));
      vramLimit = mcSizeReg108;
    }
    storeWordByteReversed(&M<UInt8>(mmioBase + 0x130), newReg130);
    enforceInOrderExecutionIO();
    mcIndexIsR520 = (chipFlags & 0x400000) == 0;
    display1Address = loadWordByteReversed(&M<UInt8>(mmioBase + 0x6110));
    display2Address = loadWordByteReversed(&M<UInt8>(mmioBase + 0x6910));
    display1Address = display1Address + fbStart16 * -0x10000;
    display2AddressRebased = display2Address + fbStart16 * -0x10000;
    if (mcIndexIsR520) {
      M<UInt32>(mmioBase + 0x70) = 0x400ff00;
      enforceInOrderExecutionIO();
    }
    else {
      M<UInt32>(mmioBase + 0x70) = 0x100ff00;
      enforceInOrderExecutionIO();
    }
    M<UInt32>(mmioBase + 0x74) = 0xffff;
    enforceInOrderExecutionIO();
    M<UInt32>(mmioBase + 0x134) = 0;
    enforceInOrderExecutionIO();
    storeWordByteReversed(&M<UInt8>(mmioBase + 0x6110), display1Address);
    enforceInOrderExecutionIO();
    storeWordByteReversed(&M<UInt8>(mmioBase + 0x6910), display2AddressRebased);
    enforceInOrderExecutionIO();
    if (mcIndexIsR520) {
      M<UInt32>(mmioBase + 0x70) = 0x400ff00;
      enforceInOrderExecutionIO();
    }
    else {
      M<UInt32>(mmioBase + 0x70) = 0x100ff00;
      enforceInOrderExecutionIO();
    }
    M<UInt32>(mmioBase + 0x74) = (vramLimit - 1 & 0xffff0000) >> 8 & 0xff00 | vramLimit - 1 >> 0x18;
    enforceInOrderExecutionIO();
  }
  if ((chipFlags & 0x400000) == 0) {
    M<UInt32>(mmioBase + 0x70) = 0x4007f00;
    enforceInOrderExecutionIO();
  }
  else {
    M<UInt32>(mmioBase + 0x70) = 0x1007f00;
    enforceInOrderExecutionIO();
  }
  stampPageGartOffset = M<SInt32>(self + kIOATIR500Accelerator_stampPageGartOffset);
  fbEnd = (loadWordByteReversed(&M<UInt8>(mmioBase + 0x74)) & 0xffff0000) + 0x10000;
  M<UInt32>(self + kIOATIR500Accelerator_vramSizeProgrammed) = fbEnd;
  stampPageAddress = fbEnd + stampPageGartOffset;
  M<UInt32>(mmioBase + 0x30) = 0x13000000;
  enforceInOrderExecutionIO();
  gartTableOffset = M<UInt32>(self + kIOATIR500Accelerator_gartTableVramOffset);
  storeWordByteReversed(&M<UInt8>(mmioBase + 0x34), gartTableOffset);
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x17000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x16000000;
  enforceInOrderExecutionIO();
  gartEnd = fbEnd + M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB) * 0x400;
  M<UInt32>(mmioBase + 0x34) = (gartEnd & 0xff00) << 8 | gartEnd >> 8 & 0xff00 | gartEnd >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x15000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x14000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = fbEnd >> 8 & 0xff00 | fbEnd >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x12000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x11000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = fbEnd >> 8 & 0xff00 | fbEnd >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(self + kIOATIR500Accelerator_pcieIndirectRegValue) = 0x47;
  M<UInt32>(mmioBase + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = 0x10000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = 0x47000000;
  enforceInOrderExecutionIO();
  mainRingAddress = fbEnd + M<SInt32>(self + kIOATIR500Accelerator_mainRingGartOffset);
  storeWordByteReversed(&M<UInt8>(mmioBase + 0x700), ((M<SInt32>(self + kIOATIR500Accelerator_mainRingGartOffset)) & 0xff) | (mainRingAddress & 0xff00) | (mainRingAddress & 0xff0000) | (mainRingAddress & 0xff000000));
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x15e0) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x15e4) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x15e8) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x15ec) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x15f0) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x15f4) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x15f8) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x15fc) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x1fa8) = 0;
  enforceInOrderExecutionIO();
  storeWordByteReversed(&M<UInt8>(mmioBase + 0x774), (stampPageGartOffset & 0xff) | (stampPageAddress & 0xff00) | (stampPageAddress & 0xff0000) | (stampPageAddress & 0xff000000));
  enforceInOrderExecutionIO();
  if (M<SInt32>(self + kIOATIR500Accelerator_stampPageMemory) != 0) {
    M<UInt32>(mmioBase + 0x770) = 0xff000000;
    enforceInOrderExecutionIO();
    return;
  }
  M<UInt32>(mmioBase + 0x770) = 0;
  enforceInOrderExecutionIO();
  return;
}

/* real addr 0x1f3c0 */
bool ATIRadeonX1000::initialize_hardware() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 result;
  UInt32 submitStampValue;
  UInt32 nextWriteIndex;
  SInt32 writeIndex;
  SInt32 registers;
  SInt32 modeSet;
  SInt32 engineStarted;
  SInt32 ring;
  UInt32 reg1724Value;
  UInt32 retiredStampValue;
  UInt32 hwCaps;
  
  if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0xf00000) != 0) {
    setupR520Pipes();
  }
  setup_R500_internal_space();
  this->initialize_GUI();
  engineStarted = start_promo4_engine(4);
  result = 0;
  if (engineStarted != 0) {
    modeSet = set_display_mode_and_vram();
    if (modeSet == 0) {
      GH_IOLog("set_display_mode_and_vram failed\n");
      result = 0;
    }
    else {
      registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
      submitStampValue = M<SInt32>(self + kIOATIR500Accelerator_submitStamp) - 1;
      storeWordByteReversed(&M<UInt8>(registers + 0x15e0), submitStampValue);
      enforceInOrderExecutionIO();
      retiredStampValue = M<UInt32>(self + kIOATIR500Accelerator_retiredStampCounter);
      storeWordByteReversed(&M<UInt8>(registers + 0x15e4), retiredStampValue);
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x16e8) = 0xff1fff1f;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x16cc) = 0xffffffff;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x2284) = 0;
      enforceInOrderExecutionIO();
      hwCaps = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits);
      if ((hwCaps & 0x200000) == 0) {
        if ((hwCaps & 0x400000) == 0) {
          M<UInt32>(registers + 0x2080) = 0x56083000;
          enforceInOrderExecutionIO();
          if ((hwCaps & 0x800000) != 0) {
            M<UInt32>(registers + 0x4614) = 0x1040000;
            enforceInOrderExecutionIO();
          }
        }
        else {
          M<UInt32>(registers + 0x2080) = 0x56023000;
          enforceInOrderExecutionIO();
          M<UInt32>(registers + 0x47c8) = 0;
          enforceInOrderExecutionIO();
        }
      }
      else {
        M<UInt32>(registers + 0x2080) = 0x56053000;
        enforceInOrderExecutionIO();
        M<UInt32>(registers + 0x4bec) = 0x1000000;
        enforceInOrderExecutionIO();
        M<UInt32>(registers + 0x4398) = 0;
        enforceInOrderExecutionIO();
        M<UInt32>(registers + 0x47c8) = 0;
        enforceInOrderExecutionIO();
        M<UInt32>(registers + 0x4614) = 0x1040000;
        enforceInOrderExecutionIO();
      }
      M<UInt32>(registers + 0x43b0) = 0;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x43b4) = 0xffffff03;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x43b8) = 0;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x43bc) = 0xffffff03;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x43c0) = 0;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x43c4) = 0xffffff03;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x43c8) = 0;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x43cc) = 0xffffff03;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x43d0) = 0xffff0000;
      enforceInOrderExecutionIO();
      if (self[0x85] != 0x0) {
        this->submit_empty_buffer();
        registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
      }
      M<UInt32>(self + kIOATIR500Accelerator_savedD1Reg6104) =
           loadWordByteReversed(&M<UInt8>(registers + 0x6104));
      M<UInt32>(self + kIOATIR500Accelerator_savedD2Reg6904) =
           loadWordByteReversed(&M<UInt8>(registers + 0x6904));
      M<UInt32>(self + kIOATIR500Accelerator_savedD1Reg6148) =
           loadWordByteReversed(&M<UInt8>(registers + 0x6148));
      M<UInt32>(self + kIOATIR500Accelerator_savedD2Reg6948) =
           loadWordByteReversed(&M<UInt8>(registers + 0x6948));
      M<UInt32>(self + kIOATIR500Accelerator_savedD1Reg60c4) =
           loadWordByteReversed(&M<UInt8>(registers + 0x60c4));
      M<UInt32>(self + kIOATIR500Accelerator_savedD2Reg68c4) =
           loadWordByteReversed(&M<UInt8>(registers + 0x68c4));
      result = 1;
      if (M<SInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) != 0) {
        enforceInOrderExecutionIO();
        reg1724Value = loadWordByteReversed(&M<UInt8>(registers + 0x1724));
        writeIndex = M<SInt32>(self + kIOATIR500Accelerator_ringIndex);
        ring = M<SInt32>(self + kIOATIR500Accelerator_mainRingMemory);
        M<UInt32>(ring + writeIndex * 4) = 0x5c9;
        nextWriteIndex = writeIndex + 1U & 0x7ff;
        M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = nextWriteIndex;
        M<UInt32>(ring + nextWriteIndex * 4) =
             reg1724Value | 3;
        M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = nextWriteIndex + 1 & 0x7ff;
        this->submit_ring_data();
        result = 1;
      }
    }
  }
  return result;
}

