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

  UInt8 bVar1;
  UInt32 uVar2;
  SInt32 mmioBase;
  UInt32 pipeCountCode;
  UInt32 savedStrobeWord;
  
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
  uVar2 = (1 << pipeCountCode + 1) - 1;
  M<UInt32>(mmioBase + 0x42c8) =
       uVar2 * 0x1000000 | (uVar2 & 0xff00) << 8 | uVar2 >> 8 & 0xff00 | uVar2 >> 0x18;
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0);
  } while ((((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0)) ||
          (((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0 || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0))));
  if (pipeCountCode == 1) {
    uVar2 = 6;
    M<UInt32>(self + kIOATIR500Accelerator_numPipes) = 2;
  }
  else if (pipeCountCode == 0) {
LAB_0001bea0:
    uVar2 = 0;
    M<UInt32>(self + kIOATIR500Accelerator_numPipes) = 1;
  }
  else if (pipeCountCode == 2) {
    uVar2 = 0xc;
    M<UInt32>(self + kIOATIR500Accelerator_numPipes) = 3;
  }
  else {
    if (pipeCountCode != 3) goto LAB_0001bea0;
    uVar2 = 0xe;
    M<UInt32>(self + kIOATIR500Accelerator_numPipes) = 4;
  }
  M<UInt32>(self + kIOATIR500Accelerator_gbTileConfig) = uVar2 | 0xc00011;
  M<UInt32>(mmioBase + 0x4018) = (uVar2 | 0xc00011) << 0x18 | 0xc000;
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
  if ((M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) & 0x200000) == 0) {
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
  uVar2 = (loadWordByteReversed(&M<UInt8>(mmioBase + 0xc)) ^ 0x30000000) >> 0x1c & 3;
  storeWordByteReversed(&M<UInt8>(mmioBase + 8), savedStrobeWord);
  if (uVar2 != 0) {
    if (uVar2 < 3) {
      M<UInt32>(self + kIOATIR500Accelerator_numZPipes) = 1;
      goto LAB_0001c040;
    }
    if (uVar2 == 3) {
      if (M<UInt32>(self + kIOATIR500Accelerator_chipRev) < 4) {
        uVar2 = 1;
        M<UInt32>(self + kIOATIR500Accelerator_numZPipes) = 1;
      }
      else {
        uVar2 = 3;
        M<UInt32>(self + kIOATIR500Accelerator_numZPipes) = 2;
      }
      goto LAB_0001c040;
    }
  }
  M<UInt32>(self + kIOATIR500Accelerator_numZPipes) = 1;
  uVar2 = 1;
LAB_0001c040:
  M<UInt32>(mmioBase + 0x4124) = uVar2 << 0x18;
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  do {
    do {
    } while ((SInt32)(loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40))) < 0);
  } while (((((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x10000) == 0) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x60000) != 0)) ||
           ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1720)) & 0x20000) == 0)) || ((loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40)) & 0x380000) != 0));
  M<UInt32>(mmioBase + 0x4be8) = uVar2 << 0x18;
  enforceInOrderExecutionIO();
  return;
}

/* real addr 0x1c120 */
bool ATIRadeonX1000::set_display_mode_and_vram() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 bVar1;
  UInt8 bVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  UInt32 usableSize;
  UInt32 memorySize;
  UInt32 uVar5;
  UInt8 AVar6;
  UInt8 AVar7;
  UInt16 uVar9;
  UInt32 uVar8;
  SInt32 registers;
  SInt32 queryResult;
  SInt32 pixelResult;
  SInt32 modeResult;
  SInt32 reserved;
  SInt32 poolReady;
  UInt32 uVar11;
  UInt32 uVar12;
  UInt32 uVar13;
  UInt32 uVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  UInt32 pixelFormat;
  UInt32 vramSize;
  UInt32 bytesPerPixel;
  UInt32 pitch;
  /* One 0xa8-byte stack object (r1+0x58..): Ghidra named its slots separately. getCurrentDisplayMode fills f8/f4 and getPixelInformation fills
   `pix` AND the two words after it (L.f54 / L.f50), so they must be one object: as separate scalars the compiler saw L.f54/L.f50
   as never written and deleted the branches that read them (4 of the 10 ATIR500Memory::reserve calls, #85). */
  struct { UInt32 f8; UInt32 f4; UInt8 pix[156]; UInt32 f54; UInt32 f50; UInt32 reserved[3]; } L;
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
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x150) = 0;
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
  M<UInt32>(self + kIOATIR500Accelerator_activePanelMask) = 0;
  uVar12 = (usableSize >> 1) - 1;
  if (vramSize == usableSize) {
    poolReady = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->init_pool(usableSize);
    if (poolReady == 0) {
      return 0;
    }
    ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->init_pool(M<UInt32>(self + kIOATIR500Accelerator_vramSize));
  }
  else {
    poolReady = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->init_pool(vramSize, usableSize, 0);
    if (poolReady == 0) {
      return 0;
    }
    ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->init_pool(M<UInt32>(self + kIOATIR500Accelerator_vramSize),M<UInt32>(self + kIOATIR500Accelerator_usableVramSize),0)
    ;
  }
  if (M<UInt32>(self + kIOATIR500Accelerator_gartReserveOffset) != 0) {
    reserved = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_gartTableBuffer),
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
  uVar4 = M<UInt32>(self + kIOATIR500Accelerator_display1SurfaceAddress);
  uVar14 = M<UInt32>(self + kIOATIR500Accelerator_display1SurfaceAddressB);
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
  if (L.f54 != 0) {
    uVar14 = L.f54;
  }
  registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  uVar11 = loadWordByteReversed(&M<UInt8>(registers + 0x16c4)) & 0xfffffff0;
  if ((loadWordByteReversed(&M<UInt8>(registers + 0x6080)) & 1) == 0) {
    uVar5 = 0;
    pitch = 0;
    uVar14 = 0;
  }
  else {
    bVar1 = loadWordByteReversed(&M<UInt8>(registers + 0x6104)) & 3;
    bVar2 = loadWordByteReversed(&M<UInt8>(registers + 0x6104)) >> 8 & 7;
    if (bVar1 == 1) {
      pixelFormat = 4;
      if (((bVar2 != 1) && (pixelFormat = 3, bVar2 != 0)) && (pixelFormat = 0xf, bVar2 != 2))
      goto LAB_0001c414;
    }
    else {
      if (bVar1 == 0) {
        pixelFormat = 9;
joined_r0x0001c43c:
        if (bVar2 == 0) goto LAB_0001c418;
      }
      else if (bVar1 == 2) {
        pixelFormat = 6;
        if ((bVar2 == 0) || (pixelFormat = 5, bVar2 == 1)) goto LAB_0001c418;
      }
      else if (bVar1 == 3) {
        pixelFormat = 10;
        goto joined_r0x0001c43c;
      }
LAB_0001c414:
      pixelFormat = 0xff;
    }
LAB_0001c418:
    M<UInt32>(self + kIOATIR500Accelerator_display1Enabled) = loadWordByteReversed(&M<UInt8>(registers + 0x6088)) & 1;
    if (pixelFormat == 6) {
      uVar11 = uVar11 | 6;
      M<UInt32>(registers + 0x15d4) = 0x2000000;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x15d0) = 0x2000000;
      enforceInOrderExecutionIO();
      AVar6 = 0xb;
      bytesPerPixel = 4;
      uVar9 = 4;
    }
    else {
      if (pixelFormat < 7) {
        if (pixelFormat - 3 < 2) {
          uVar11 = uVar11 | 3;
          M<UInt32>(registers + 0x15d4) = 0x1000000;
          enforceInOrderExecutionIO();
          M<UInt32>(registers + 0x15d0) = 0x1000000;
          enforceInOrderExecutionIO();
          AVar6 = 0x7;
          bytesPerPixel = 2;
          uVar9 = 2;
          goto LAB_0001c54c;
        }
      }
      else if (pixelFormat == 9) {
        uVar11 = uVar11 | 2;
        M<UInt32>(registers + 0x15d4) = 0;
        enforceInOrderExecutionIO();
        M<UInt32>(registers + 0x15d0) = 0;
        enforceInOrderExecutionIO();
      }
      AVar6 = 0x1;
      bytesPerPixel = 1;
      uVar9 = 1;
    }
LAB_0001c54c:
    M<UInt32>(registers + 0x16c4) =
         uVar11 << 0x18 | (uVar11 & 0xff00) << 8 | uVar11 >> 8 & 0xff00 | uVar11 >> 0x18;
    enforceInOrderExecutionIO();
    pitch = uVar14 * bytesPerPixel + 0xff & 0xffffff00;
    if (bytesPerPixel != 0) {
      uVar14 = pitch / bytesPerPixel;
    }
    uVar8 = L.f50;
    if ((L.f50 & 0xf) != 0) {
      uVar8 = (L.f50 & 0xfffffff0) + 0x10;
    }
    uVar5 = uVar8 * pitch;
    M<UInt16>(self + kIOATIR500Accelerator_scanout1BufferBytesPerPixel) = uVar9;
    M<SInt16>(self + kIOATIR500Accelerator_scanout1BufferWidth) = (SInt16)uVar14;
    M<SInt16>(self + kIOATIR500Accelerator_scanout1BufferActiveWidth) = (SInt16)L.f54;
    M<SInt16>(self + kIOATIR500Accelerator_scanout1BufferActiveHeight) = (SInt16)L.f50;
    self[0x163] = 0xff;
    M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferGpuBaseAddress) = uVar4;
    M<SInt16>(self + kIOATIR500Accelerator_scanout1BufferPitch) = (SInt16)pitch;
    M<UInt32>(self + kIOATIR500Accelerator_scanout1BufferSize) = uVar5;
    if ((loadWordByteReversed(&M<UInt8>(registers + 0x6104)) & 0x100000) == 0) {
      self[0x164] = (loadWordByteReversed(&M<UInt8>(registers + 0x6104)) >> 0x15 & 1);
    }
    else {
      self[0x164] = 0x3;
    }
    self[0x167] = SUB41m(pixelFormat,0);
    self[0x166] = AVar6;
    M<UInt32>(self + kIOATIR500Accelerator_activePanelMask) = 1;
    uVar14 = 0xff;
    self[0x165] = ('\x01' - (char)((SInt32)-(bytesPerPixel ^ 2) >> 0x1f));
  }
  if (((M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) & 0x10000) == 0) || (M<UInt32>(self + kIOATIR500Accelerator_framebufferCount) < 2)) {
    uVar16 = 0;
    uVar14 = 0x200000;
    goto LAB_0001c9b0;
  }
  bVar1 = loadWordByteReversed(&M<UInt8>(registers + 0x6880)) & 1;
  M<UInt32>(self + kIOATIR500Accelerator_scanoutOverlapsVram) = 0;
  if ((loadWordByteReversed(&M<UInt8>(registers + 0x6910))) !=
      M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddressSeen)) {
    M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddress) =
         loadWordByteReversed(&M<UInt8>(registers + 0x6910));
    M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddressB) =
         loadWordByteReversed(&M<UInt8>(registers + 0x6920));
  }
  uVar16 = M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddress);
  uVar13 = M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddressB);
  if (((((bVar1 & 1) == 0) || (M<UInt32>(self + kIOATIR500Accelerator_vramSize) <= uVar16)) ||
      (queryResult = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer2), 0x5f0)
                          (M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer2),&L.f8,&L.f4), queryResult != 0)) ||
     (queryResult = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer2), 0x5ec)
                         (M<SInt32 *>(self + kIOATIR500Accelerator_framebuffer2),L.f8,L.f4,0,L.pix), queryResult != 0)) {
    uVar16 = 0;
    uVar14 = 0x200000;
    M<UInt32>(self + kIOATIR500Accelerator_scanout2BufferSize) = 0;
    M<UInt32>(self + kIOATIR500Accelerator_scanout2BufferGpuBaseAddress) = 0;
    goto LAB_0001c9b0;
  }
  if (L.f54 != 0) {
    uVar13 = L.f54;
  }
  registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  bVar1 = loadWordByteReversed(&M<UInt8>(registers + 0x6904)) & 3;
  bVar2 = loadWordByteReversed(&M<UInt8>(registers + 0x6904)) >> 8 & 7;
  if (bVar1 == 1) {
    if (bVar2 == 1) {
      uVar8 = 4;
      AVar6 = 0x4;
    }
    else if (bVar2 == 0) {
      uVar8 = 3;
      AVar6 = 0x3;
    }
    else {
      if (bVar2 != 2) goto LAB_0001c710;
      uVar8 = 0xf;
      AVar6 = 0xf;
    }
  }
  else if (bVar1 == 0) {
    if (bVar2 == 0) {
      uVar8 = 9;
      AVar6 = 0x9;
    }
    else {
LAB_0001c710:
      uVar8 = 0xff;
      AVar6 = 0xff;
    }
  }
  else if (bVar1 == 2) {
    if (bVar2 == 0) {
      uVar8 = 6;
      AVar6 = 0x6;
    }
    else {
      if (bVar2 != 1) goto LAB_0001c710;
      uVar8 = 5;
      AVar6 = 0x5;
    }
  }
  else {
    if ((bVar1 != 3) || (bVar2 != 0)) goto LAB_0001c710;
    uVar8 = 10;
    AVar6 = 0xa;
  }
  M<UInt32>(self + kIOATIR500Accelerator_display2Enabled) = loadWordByteReversed(&M<UInt8>(registers + 0x6888)) & 1;
  if (uVar8 < 3) {
LAB_0001c7d0:
    AVar7 = 0x1;
    uVar8 = 1;
    uVar9 = 1;
  }
  else if (uVar8 < 5) {
    AVar7 = 0x7;
    uVar8 = 2;
    uVar9 = 2;
  }
  else {
    if (uVar8 != 6) goto LAB_0001c7d0;
    AVar7 = 0xb;
    uVar8 = 4;
    uVar9 = 4;
  }
  uVar14 = uVar14 + uVar13 * uVar8 & ~uVar14;
  if (uVar8 != 0) {
    uVar13 = uVar14 / uVar8;
  }
  uVar3 = L.f50;
  if ((L.f50 & 0xf) != 0) {
    uVar3 = (L.f50 & 0xfffffff0) + 0x10;
  }
  uVar15 = uVar3 * uVar14;
  M<SInt16>(self + kIOATIR500Accelerator_scanout2BufferPitch) = (SInt16)uVar14;
  M<UInt16>(self + kIOATIR500Accelerator_scanout2BufferBytesPerPixel) = uVar9;
  M<SInt16>(self + kIOATIR500Accelerator_scanout2BufferWidth) = (SInt16)uVar13;
  M<SInt16>(self + kIOATIR500Accelerator_scanout2BufferActiveWidth) = (SInt16)L.f54;
  M<SInt16>(self + kIOATIR500Accelerator_scanout2BufferActiveHeight) = (SInt16)L.f50;
  self[0x1db] = 0xff;
  M<UInt32>(self + kIOATIR500Accelerator_scanout2BufferGpuBaseAddress) = uVar16;
  M<UInt32>(self + kIOATIR500Accelerator_scanout2BufferSize) = uVar15;
  if ((loadWordByteReversed(&M<UInt8>(registers + 0x6904)) & 0x100000) == 0) {
    self[0x1dc] = (loadWordByteReversed(&M<UInt8>(registers + 0x6904)) >> 0x15 & 1);
  }
  else {
    self[0x1dc] = 0x3;
  }
  self[0x1df] = AVar6;
  self[0x1de] = AVar7;
  M<UInt32>(self + kIOATIR500Accelerator_activePanelMask) = M<UInt32>(self + kIOATIR500Accelerator_activePanelMask) | 2;
  self[0x1dd] = ('\x01' - (char)((SInt32)-(uVar8 ^ 2) >> 0x1f));
  if ((uVar16 < uVar4) || (uVar5 + uVar4 <= uVar16)) {
    if ((uVar16 <= uVar4) && (uVar4 < uVar16 + uVar15)) {
      if (uVar16 + uVar15 < uVar5 + uVar4) {
        uVar15 = (uVar5 + uVar4) - uVar16;
      }
      uVar5 = 0;
      M<UInt32>(self + kIOATIR500Accelerator_scanoutOverlapsVram) = 1;
    }
    if (uVar15 != 0) {
      reserved = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout2Buffer),uVar16
                          ,uVar15);
      if (reserved == 0) {
        return 0;
      }
      ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout2ElementB),uVar16,uVar15)
      ;
      uVar13 = uVar12 & uVar16;
      if (uVar13 != 0) {
        reserved = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout2PadElement),
                            uVar16 - uVar13,uVar13);
        if (reserved == 0) {
          return 0;
        }
        uVar14 = 0xa00000;
        ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout2PadElementB),
                   uVar16 - uVar13,uVar13);
        goto LAB_0001c9b0;
      }
    }
    uVar14 = 0xa00000;
  }
  else {
    if (uVar5 + uVar4 < uVar16 + uVar15) {
      uVar5 = (uVar16 + uVar15) - uVar4;
    }
    uVar14 = 0xa00000;
    M<UInt32>(self + kIOATIR500Accelerator_scanoutOverlapsVram) = 1;
  }
LAB_0001c9b0:
  if (uVar5 != 0) {
    reserved = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout1Buffer),uVar4,
                        uVar5);
    if (reserved == 0) {
      return 0;
    }
    ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout1ElementB),uVar4,uVar5);
    uVar12 = uVar12 & uVar4;
    if (uVar12 != 0) {
      reserved = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout1PadElement),
                          uVar4 - uVar12,uVar12);
      if (reserved == 0) {
        return 0;
      }
      ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB)))->reserve((GLKMemoryElement *)(self + kIOATIR500Accelerator_scanout1PadElementB),uVar4 - uVar12
                 ,uVar12);
    }
  }
  registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  M<UInt32>(registers + 0xb00) = uVar14 >> 8 | 0x1000000;
  uVar12 = (pitch & 0x3f00) << 0x10;
  uVar4 = uVar4 >> 10;
  M<UInt32>(registers + 0x16e0) =
       uVar4 << 0x18 | (uVar4 & 0xff00) << 8 | (uVar4 & 0x3f0000) >> 8 |
       (uVar12 | 0x40000000) >> 0x18;
  enforceInOrderExecutionIO();
  if (uVar16 != 0) {
    uVar16 = uVar16 >> 10;
    M<UInt32>(registers + 0x16f8) =
         uVar16 << 0x18 | (uVar16 & 0xff00) << 8 | (uVar16 & 0x3f0000) >> 8 |
         (uVar12 | 0x40000000) >> 0x18;
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
  UInt8 bVar3;
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
    M<UInt32>(mmioBase + 0x7dc) =
         microcodeWord << 0x18 | (microcodeWord & 0xff00) << 8 | microcodeWord >> 8 & 0xff00 | microcodeWord >> 0x18;
    enforceInOrderExecutionIO();
    microcodeWord = microcodeCursor[-1];
    M<UInt32>(mmioBase + 0x7e0) =
         microcodeWord << 0x18 | (microcodeWord & 0xff00) << 8 | microcodeWord >> 8 & 0xff00 | microcodeWord >> 0x18;
    enforceInOrderExecutionIO();
    microcodeCursor = microcodeCursor + 2;
    pairsLeft = pairsLeft + -1;
  } while (pairsLeft != 0);
  return;
}

/* real addr 0x1cd90 */
bool ATIRadeonX1000::start_promo4_engine(UInt32 mode) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt8 bVar2;
  UInt8 bVar3;
  UInt32 uVar4;
  UInt32 ringWritePointer;
  UInt32 uVar6;
  UInt32 uVar7;
  UInt32 rbbmStatus;
  UInt8 *displayRecord;
  UInt32 ringReadPointer;
  SInt32 mmioBase;
  SInt32 iVar11;
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
    if ((M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) & 0x80000) == 0) {
      uVar7 = M<SInt32>(self + kIOATIR500Accelerator_vramSizeProgrammed) + M<SInt32>(self + kIOATIR500Accelerator_scratchCommandBufferGartOffset) + (ringPointerBase - M<SInt32>(self + kIOATIR500Accelerator_scratchCommandBufferHeader));
      M<UInt32>(mmioBase + 0x70c) =
           (uVar7 & 0xfffffffc) << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 |
           uVar7 >> 0x18;
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
      if ((M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) & 0x80000) == 0) {
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
        bVar1 = displayIndex != 1;
        displayRecord = displayRecord + 0x20;
        displayIndex = displayIndex + 1;
      } while (bVar1);
      return 1;
    }
  }
  return 0;
}

/* real addr 0x1cf70 */
void ATIRadeonX1000::setup_R500_internal_space() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  SInt32 mmioBase;
  SInt32 iVar6;
  UInt32 uVar7;
  UInt32 chipFlags;
  UInt32 uVar8;
  UInt32 uVar9;
  UInt32 uVar10;
  UInt32 uVar11;
  
  enforceInOrderExecutionIO();
  ppcSync();
  instructionSynchronize();
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  M<UInt32>(mmioBase + 0x740) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x744) = 0;
  enforceInOrderExecutionIO();
  chipFlags = M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags);
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x8fc) = 0;
  if ((chipFlags & 0x400000) == 0) {
    M<UInt32>(mmioBase + 0x70) = 0x4007f00;
    enforceInOrderExecutionIO();
  }
  else {
    M<UInt32>(mmioBase + 0x70) = 0x1007f00;
    enforceInOrderExecutionIO();
  }
  uVar4 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x74)) & 0xffff;
  if (uVar4 != 0) {
    uVar8 = loadWordByteReversed(&M<UInt8>(mmioBase + 0xf8));
    if (uVar8 == 0) {
      uVar8 = 0x8000000;
    }
    uVar11 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x130));
    uVar9 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x108));
    uVar10 = uVar11 & 0xff7fffff;
    if ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x104))) ==
        uVar9 + (loadWordByteReversed(&M<UInt8>(mmioBase + 0x100)))) {
      uVar9 = uVar9 << 1;
      uVar10 = uVar11 | 0x800000;
    }
    if (uVar9 < uVar8) {
      M<UInt32>(mmioBase + 0xf8) =
           uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 | uVar9 >> 0x18;
      enforceInOrderExecutionIO();
      M<UInt32>(self + kIOATIR500Accelerator_vramSizeProgrammed) =
           loadWordByteReversed(&M<UInt8>(mmioBase + 0xf8));
      uVar8 = uVar9;
    }
    M<UInt32>(mmioBase + 0x130) =
         uVar10 << 0x18 | (uVar10 & 0xff00) << 8 | uVar10 >> 8 & 0xff00 | uVar10 >> 0x18;
    enforceInOrderExecutionIO();
    bVar1 = (chipFlags & 0x400000) == 0;
    uVar2 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x6110));
    uVar3 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x6910));
    uVar2 = uVar2 + uVar4 * -0x10000;
    uVar11 = uVar3 + uVar4 * -0x10000;
    if (bVar1) {
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
    storeWordByteReversed(&M<UInt8>(mmioBase + 0x6110), uVar2);
    enforceInOrderExecutionIO();
    storeWordByteReversed(&M<UInt8>(mmioBase + 0x6910), uVar11);
    enforceInOrderExecutionIO();
    if (bVar1) {
      M<UInt32>(mmioBase + 0x70) = 0x400ff00;
      enforceInOrderExecutionIO();
    }
    else {
      M<UInt32>(mmioBase + 0x70) = 0x100ff00;
      enforceInOrderExecutionIO();
    }
    M<UInt32>(mmioBase + 0x74) = (uVar8 - 1 & 0xffff0000) >> 8 & 0xff00 | uVar8 - 1 >> 0x18;
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
  iVar6 = M<SInt32>(self + kIOATIR500Accelerator_stampPageGartOffset);
  uVar8 = (loadWordByteReversed(&M<UInt8>(mmioBase + 0x74)) & 0xffff0000) + 0x10000;
  M<UInt32>(self + kIOATIR500Accelerator_vramSizeProgrammed) = uVar8;
  uVar4 = uVar8 + iVar6;
  M<UInt32>(mmioBase + 0x30) = 0x13000000;
  enforceInOrderExecutionIO();
  uVar7 = M<UInt32>(self + kIOATIR500Accelerator_gartTableVramOffset);
  M<UInt32>(mmioBase + 0x34) =
       uVar7 << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x17000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x16000000;
  enforceInOrderExecutionIO();
  uVar7 = uVar8 + M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB) * 0x400;
  M<UInt32>(mmioBase + 0x34) = (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x15000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x14000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x12000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x30) = 0x11000000;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x34) = uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
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
  uVar8 = uVar8 + M<SInt32>(self + kIOATIR500Accelerator_mainRingGartOffset);
  M<UInt32>(mmioBase + 0x700) =
       M<SInt32>(self + kIOATIR500Accelerator_mainRingGartOffset) << 0x18 | (uVar8 & 0xff00) << 8 | uVar8 >> 8 & 0xff00 | uVar8 >> 0x18;
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
  M<UInt32>(mmioBase + 0x774) =
       iVar6 << 0x18 | (uVar4 & 0xff00) << 8 | uVar4 >> 8 & 0xff00 | uVar4 >> 0x18;
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

  UInt8 bVar1;
  UInt8 bVar2;
  UInt8 bVar3;
  UInt8 bVar4;
  UInt32 result;
  UInt32 uVar6;
  UInt32 nextWriteIndex;
  SInt32 iVar7;
  SInt32 writeIndex;
  SInt32 registers;
  SInt32 modeSet;
  SInt32 engineStarted;
  SInt32 ring;
  UInt32 uVar9;
  
  if ((M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) & 0xf00000) != 0) {
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
      uVar6 = M<SInt32>(self + kIOATIR500Accelerator_submitStamp) - 1;
      M<UInt32>(registers + 0x15e0) =
           uVar6 * 0x1000000 | (uVar6 & 0xff00) << 8 | uVar6 >> 8 & 0xff00 | uVar6 >> 0x18;
      enforceInOrderExecutionIO();
      uVar6 = M<UInt32>(self + kIOATIR500Accelerator_retiredStampCounter);
      M<UInt32>(registers + 0x15e4) =
           uVar6 << 0x18 | (uVar6 & 0xff00) << 8 | uVar6 >> 8 & 0xff00 | uVar6 >> 0x18;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x16e8) = 0xff1fff1f;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x16cc) = 0xffffffff;
      enforceInOrderExecutionIO();
      M<UInt32>(registers + 0x2284) = 0;
      enforceInOrderExecutionIO();
      uVar6 = M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags);
      if ((uVar6 & 0x200000) == 0) {
        if ((uVar6 & 0x400000) == 0) {
          M<UInt32>(registers + 0x2080) = 0x56083000;
          enforceInOrderExecutionIO();
          if ((uVar6 & 0x800000) != 0) {
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
        uVar9 = loadWordByteReversed(&M<UInt8>(registers + 0x1724));
        writeIndex = M<SInt32>(self + kIOATIR500Accelerator_ringIndex);
        ring = M<SInt32>(self + kIOATIR500Accelerator_mainRingMemory);
        M<UInt32>(ring + writeIndex * 4) = 0x5c9;
        nextWriteIndex = writeIndex + 1U & 0x7ff;
        M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = nextWriteIndex;
        M<UInt32>(ring + nextWriteIndex * 4) =
             uVar9 | 3;
        M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = nextWriteIndex + 1 & 0x7ff;
        this->submit_ring_data();
        result = 1;
      }
    }
  }
  return result;
}

