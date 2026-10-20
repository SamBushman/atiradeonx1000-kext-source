/*
 * IOATIR5002DContext_clientMemoryForType_Port.cpp
 *
 * IOATIR5002DContext::clientMemoryForType (real addr 0xd6f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockSleep(...) asm("_IOLockSleep");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* label addresses in the shipped code: retryOrGiveUp 0xd8b8, checkSurface 0xd930, checkPanelIndex 0xd93c, afterAllocation 0xd950, recordStampOnly 0xdc70, advanceRing 0xdd38,
 * returnCommandBuffer 0xde0c */
/* real addr 0xd6f0 */
IOReturn IOATIR5002DContext::clientMemoryForType(UInt32 type, UInt32*options, IOMemoryDescriptor**memory) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt16 uVar1;
  UInt16 savedInFlight;
  unsigned int surfaceMask;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *surfaceForPanel;
  int *ringSlot;
  int iVar6;
  int iVar7;
  unsigned int allocatedMask;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  UInt32 savedStamp;
  UInt32 bufferFlags;
  unsigned int retries;
  unsigned int panel;
  UInt8 *surface;
  int iVar16;
  UInt8 *accel;
  int *surfaceWords;
  int *accelWords;
  int accelAddr;
  int allocResult;
  int panelOffset;
  int waited;
  int swapRequest;
  int flushSurface;
  int stampComplete;
  int allocatedMore;
  int waitedCount;
  int newType;
  int newStamp;
  int submitStamp;
  int surfaceStamp;
  int boundSurfaceAddr;
  int listHead;
  int savedWaitCount;
  int savedBusyCount;
  int newDescriptor;
  int oldStamp;
  int headNext;
  int oldGartOffset;
  int newGartOffset;
  int newSize;
  int oldBuffer;
  int oldDescriptor;
  int oldHeader;
  int oldSize;
  UInt16 oldType;
  int finalAllocResult;
  /* one 16-byte stack object filled by the +0x5ac/+0x5b4/+0x560 callees (Ghidra named its words descriptor and local_30; #85) */
  int descriptor[4];
  
  if (type == 1) {
    GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x840));
    VCALL(*M<int *>(self + kIOATIR5002DContext_contextBufferDescriptor), 0x14)(M<int *>(self + kIOATIR5002DContext_contextBufferDescriptor));
    *options = 0;
    *memory = M<IOMemoryDescriptor *>(self + kIOATIR5002DContext_contextBufferDescriptor);
    this->init_context_buffer_header((VendorContextBufferHeader *)(M<VendorContextBufferHeader *>(self + kIOATIR5002DContext_contextBufferHeader)),0x1000);
    GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x840));
    return 0;
  }
  retries = 0;
  if (type != 0) {
    if (type != 2) {
      return 0xe00002c2;
    }
    if (M<int *>(M<int>(self + kIOATIR5002DContext_accelerator) + 0xac) == (int *)0x0) {
      return 0xe00002be;
    }
    VCALL(*M<int *>(M<int>(self + kIOATIR5002DContext_accelerator) + 0xac), 0x14)(M<int *>(M<int>(self + kIOATIR5002DContext_accelerator) + 0xac));
    *options = 0;
    *memory = M<IOMemoryDescriptor *>(M<int>(self + kIOATIR5002DContext_accelerator) + 0xac);
    return 0;
  }
  do {
    while( true ) {
      GH_IOLockLock(M<UInt32>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x840));
      surface = M<UInt8 *>(self + kIOATIR5002DContext_boundSurface);
      if ((surface == (UInt8 *)0x0) || (M<unsigned int>(surface + 0xa4) < 0x100)) {
        accelAddr = M<int>(self + kIOATIR5002DContext_accelerator);
      }
      else {
        accelAddr = M<int>(self + kIOATIR5002DContext_accelerator);
        if (M<char>(accelAddr + kIOATIR500Accelerator_active) == '\0') {
          do {
            GH_IOLockSleep(M<UInt32>(accelAddr + kIOATIR500Accelerator_commandLock),accelAddr,0);
          } while (M<char>(accelAddr + kIOATIR500Accelerator_active) == '\0');
          accelAddr = M<int>(self + kIOATIR5002DContext_accelerator);
          surface = M<UInt8 *>(self + kIOATIR5002DContext_boundSurface);
        }
      }
      if (M<char>(accelAddr + kIOATIR500Accelerator_active) == '\0') {
        retries = 0x3e9;
        bufferFlags = 0;
        goto checkSurface;
      }
      if (surface == (UInt8 *)0x0) {
        surface = (UInt8 *)0x0;
        bufferFlags = 0;
        goto checkPanelIndex;
      }
      if (surface[0xbf6] == 0x0) break;
      VCALL(M<int>(surface), 0x14)(surface);
      GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x840));
      ((IOATIR500Surface *)(surface))->sleep_blocked();
      VCALL(M<int>(surface), 0x18)(surface);
    }
    bufferFlags = M<UInt32>(surface + 0xbfc);
    if ((M<unsigned int>(surface + 0xbec) & 0xffffff) != 0) {
      bufferFlags = bufferFlags | 2;
    }
    if ((surface[0xbd0] == 0x0) || (retries == 999)) {
      allocatedMask = M<unsigned int>(surface + 0xbf8);
      if (((M<unsigned int>(self + kIOATIR5002DContext_surfaceFlagsBitmask) | M<unsigned int>(surface + 0xc1c)) & allocatedMask) == 0) goto afterAllocation;
      if ((allocatedMask & 0x20000000) != 0) {
        retries = 0x3e9;
        goto afterAllocation;
      }
      surfaceMask = (M<unsigned int>(self + kIOATIR5002DContext_surfaceFlagsBitmask) | M<unsigned int>(surface + 0xc1c)) & 0x7fffff;
      if ((allocatedMask & surfaceMask) != 0) {
        allocResult = ((IOATIR500Surface *)((UInt32)surface))->alloc_surfaces(surfaceMask, false);
        if (allocResult != 0) {
          if (allocResult != 2) goto retryOrGiveUp;
          surface = M<UInt8 *>(self + kIOATIR5002DContext_boundSurface);
          retries = 0x3e9;
          goto checkSurface;
        }
        surface = M<UInt8 *>(self + kIOATIR5002DContext_boundSurface);
        if ((M<unsigned int>(surface + 0xbf8) & M<unsigned int>(surface + 0xc1c) & 0x10000000) == 0)
        goto afterAllocation;
      }
      VCALL(M<int>(surface), 0x5c0)(surface);
      M<unsigned int>(M<int>(self + kIOATIR5002DContext_boundSurface) + 0xbf8) =
           M<unsigned int>(M<int>(self + kIOATIR5002DContext_boundSurface) + 0xbf8) & 0xefffffff;
      surface = M<UInt8 *>(self + kIOATIR5002DContext_boundSurface);
      goto checkSurface;
    }
retryOrGiveUp:
    if (retries == 1000) break;
    retries = retries + 1;
    GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x840));
    GH_thread_block(0);
    GH_IOSleep(1);
  } while( true );
  surface = M<UInt8 *>(self + kIOATIR5002DContext_boundSurface);
checkSurface:
  if (surface == (UInt8 *)0x0) {
checkPanelIndex:
    if (M<int>(self + kIOATIR5002DContext_panelIndex) == 0xffff) goto returnCommandBuffer;
  }
afterAllocation:
  if (999 < retries) {
    if ((1000 < retries) ||
       (finalAllocResult = ((IOATIR500Surface *)((UInt32)surface))->alloc_surfaces((M<UInt32>(self + kIOATIR5002DContext_surfaceFlagsBitmask) | M<UInt32>(surface + 0xc1c)) & 0x7fffff, true), finalAllocResult != 0))
    goto returnCommandBuffer;
    surfaceWords = M<int *>(self + kIOATIR5002DContext_boundSurface);
    if ((surfaceWords[0x2fe] & surfaceWords[0x307] & 0x10000000U) != 0) {
      VCALL(*surfaceWords, 0x5c0)(surfaceWords);
      M<unsigned int>(M<int>(self + kIOATIR5002DContext_boundSurface) + 0xbf8) =
           M<unsigned int>(M<int>(self + kIOATIR5002DContext_boundSurface) + 0xbf8) & 0xefffffff;
    }
  }
  if (self != M<UInt8 *>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x78)) {
    VCALL(M<int>(self), 0x5a8)(self);
    M<int>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x744) = M<int>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x744) + 1;
    M<UInt8 *>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x78) = self;
  }
  surfaceWords = M<int *>(self + kIOATIR5002DContext_boundSurface);
  if (surfaceWords != (int *)0x0) {
    VCALL(*surfaceWords, 0x5b8)(surfaceWords,M<UInt32>(self + kIOATIR5002DContext_surfaceFlagsBitmask));
  }
  if (M<int>(self + kIOATIR5002DContext_commandBufferGartOffset) == 0) {
    this->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + kIOATIR5002DContext_commandBuffer)));
  }
  swapRequest = VCALL(M<int>(self), 0x5ac)(self,descriptor);
  if (M<int>(self + kIOATIR5002DContext_lastBoundTexture) != 0) {
    M<UInt32>(M<int>(M<int>(self + kIOATIR5002DContext_lastBoundTexture) + 0x14) + 8) =
         M<UInt32>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x50);
  }
  if (descriptor[2] == 0) {
    submitStamp = M<int>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x50) + -1;
  }
  else {
    M<int>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x700) = descriptor[2] * 4 + M<int>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x700)
    ;
    submitStamp = VCALL(*M<int *>(self + kIOATIR5002DContext_accelerator), 0x560)(M<int *>(self + kIOATIR5002DContext_accelerator),descriptor);
  }
  surfaceWords = M<int *>(self + kIOATIR5002DContext_boundSurface);
  M<int>(self + kIOATIR5002DContext_lastSubmitStamp) = submitStamp;
  M<int>(self + kIOATIR5002DContext_commandBufferStamp) = submitStamp;
  if (surfaceWords == (int *)0x0) {
recordStampOnly:
    M<UInt32>(M<int>(self + kIOATIR5002DContext_panelIndex) * 0x20 + M<int>(self + kIOATIR5002DContext_accelerator) + 0xec) =
         M<UInt32>(self + kIOATIR5002DContext_lastSubmitStamp);
  }
  else {
    VCALL(*surfaceWords, 0x5bc)(surfaceWords,M<UInt32>(self + kIOATIR5002DContext_surfaceFlagsBitmask));
    surfaceWords = M<int *>(self + kIOATIR5002DContext_boundSurface);
    if (surfaceWords == (int *)0x0) goto recordStampOnly;
    surfaceStamp = VCALL(*surfaceWords, 0x5b4)
                      (surfaceWords,M<UInt32>(self + kIOATIR5002DContext_lastSubmitStamp),M<UInt32>(self + kIOATIR5002DContext_surfaceFlagsBitmask));
    surfaceWords[0x1f] = surfaceStamp;
    if (self[0x92] != 0x0) {
      M<UInt32>(M<int>(M<int>(M<int>(self + kIOATIR5002DContext_boundSurface) + 0xb70) + 0x24) + 0x54) =
           M<UInt32>(M<int>(self + kIOATIR5002DContext_boundSurface) + 0x7c);
    }
    boundSurfaceAddr = M<int>(self + kIOATIR5002DContext_boundSurface);
    if (boundSurfaceAddr != M<int>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x5c)) {
      M<UInt32>(M<int>(boundSurfaceAddr + kIOATIR500Surface_surfaceListNext) + 0xa0) = M<UInt32>(boundSurfaceAddr + kIOATIR500Surface_surfaceListPrev);
      M<UInt32>(M<int>(M<int>(self + kIOATIR5002DContext_boundSurface) + 0xa0) + 0x9c) =
           M<UInt32>(M<int>(self + kIOATIR5002DContext_boundSurface) + 0x9c);
      listHead = M<int>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x5c);
      M<int>(M<int>(self + kIOATIR5002DContext_boundSurface) + 0x9c) = listHead;
      headNext = M<int>(listHead + 0xa0);
      M<int>(M<int>(self + kIOATIR5002DContext_boundSurface) + 0xa0) = headNext;
      M<UInt32>(listHead + 0xa0) = M<UInt32>(self + kIOATIR5002DContext_boundSurface);
      M<UInt32>(headNext + 0x9c) = M<UInt32>(self + kIOATIR5002DContext_boundSurface);
      M<UInt32>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x5c) = M<UInt32>(self + kIOATIR5002DContext_boundSurface);
    }
    if ((swapRequest != 0) && ((bufferFlags & 2) == 0)) {
      flushSurface = M<int>(self + kIOATIR5002DContext_boundSurface);
      savedStamp = M<UInt32>(flushSurface + kIOATIR500Surface_flushedStamp);
      M<UInt32>(flushSurface + kIOATIR500Surface_flushedStamp) = M<UInt32>(flushSurface + kIOATIR500Surface_submittedStamp);
      accelWords = M<int *>(self + kIOATIR5002DContext_accelerator);
      if (accelWords[0x33] != 0) {
        panel = 0;
        panelOffset = 0;
        do {
          surfaceForPanel = M<int *>(self + kIOATIR5002DContext_boundSurface);
          if (M<char>((int)surfaceForPanel + panelOffset + 0xcac) != '\0') {
            VCALL(*surfaceForPanel, 0x5d4)(surfaceForPanel,panel,0);
            M<int>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x74c) = M<int>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x74c) + 1;
            accelWords = M<int *>(self + kIOATIR5002DContext_accelerator);
          }
          panel = panel + 1;
          panelOffset = panelOffset + 0x94;
        } while (panel < (unsigned int)accelWords[0x33]);
      }
      savedWaitCount = accelWords[0x1e5];
      waited = VCALL(*accelWords, 0x558)(accelWords,savedStamp);
      accelWords[0x1e5] = savedWaitCount + waited;
    }
  }
  accelWords = M<int *>(self + kIOATIR5002DContext_accelerator);
  ringSlot = accelWords + (unsigned int)M<UInt16>(accelWords + 0x171) * 7 + 0x101;
  stampComplete = VCALL(*accelWords, 0x554)(accelWords,ringSlot[4]);
  if (stampComplete == 0) {
    accel = M<UInt8 *>(self + kIOATIR5002DContext_accelerator);
    if (M<UInt16>(accel + kIOATIR500Accelerator_commandBufferRing1Count) < 8) {
      allocatedMore = ((IOATIR500Accelerator *)(accel))->allocMoreCommandBuffers(1, 0x1000);
      if (allocatedMore != 0) {
        accelAddr = M<int>(self + kIOATIR5002DContext_accelerator);
        ringSlot = (int *)(accelAddr + (unsigned int)M<UInt16>(accelAddr + kIOATIR500Accelerator_commandBufferRing1Head) * 0x1c + 0x404);
        goto advanceRing;
      }
      accel = M<UInt8 *>(self + kIOATIR5002DContext_accelerator);
    }
    savedBusyCount = M<int>(accel + kIOATIR500Accelerator_freeCommandBuffer2DWaitTime);
    waitedCount = VCALL(M<int>(accel), 0x54c)(accel,ringSlot[4]);
    M<int>(accel + kIOATIR500Accelerator_freeCommandBuffer2DWaitTime) = savedBusyCount + waitedCount;
    accelAddr = M<int>(self + kIOATIR5002DContext_accelerator);
  }
  else {
    accelAddr = M<int>(self + kIOATIR5002DContext_accelerator);
  }
advanceRing:
  M<UInt16>(accelAddr + kIOATIR500Accelerator_commandBufferRing1Head) = M<SInt16>(accelAddr + kIOATIR500Accelerator_commandBufferRing1Head) + 1U & M<SInt16>(accelAddr + kIOATIR500Accelerator_commandBufferRing1Count) - 1U;
  oldType = M<UInt16>(self + kIOATIR5002DContext_commandBufferType);
  savedInFlight = M<UInt16>(self + kIOATIR5002DContext_commandBufferInFlight);      /* read before the 32-bit store to commandBufferType below overwrites both halves */
  newType = ringSlot[3];
  newGartOffset = ringSlot[1];
  newDescriptor = ringSlot[2];
  oldDescriptor = M<int>(self + kIOATIR5002DContext_commandBufferDescriptor);
  oldGartOffset = M<int>(self + kIOATIR5002DContext_commandBufferGartOffset);
  oldBuffer = M<int>(self + kIOATIR5002DContext_commandBuffer);
  oldSize = M<int>(self + kIOATIR5002DContext_commandBufferSize);
  M<int>(self + kIOATIR5002DContext_commandBuffer) = *ringSlot;
  M<int>(self + kIOATIR5002DContext_commandBufferType) = newType;
  M<int>(self + kIOATIR5002DContext_commandBufferDescriptor) = newDescriptor;
  M<int>(self + kIOATIR5002DContext_commandBufferGartOffset) = newGartOffset;
  oldHeader = M<int>(self + kIOATIR5002DContext_commandBufferHeader);
  oldStamp = M<int>(self + kIOATIR5002DContext_commandBufferStamp);
  newStamp = ringSlot[4];
  newSize = ringSlot[6];
  M<int>(self + kIOATIR5002DContext_commandBufferHeader) = ringSlot[5];
  M<int>(self + kIOATIR5002DContext_commandBufferStamp) = newStamp;
  M<int>(self + kIOATIR5002DContext_commandBufferSize) = newSize;
  M<UInt16>((int)ringSlot + 0xe) = savedInFlight;
  M<UInt16>(ringSlot + 3) = oldType;
  *ringSlot = oldBuffer;
  ringSlot[6] = oldSize;
  ringSlot[5] = oldHeader;
  ringSlot[4] = oldStamp;
  ringSlot[2] = oldDescriptor;
  ringSlot[1] = oldGartOffset;
  accelAddr = M<int>(self + kIOATIR5002DContext_accelerator);
  if (M<char>(accelAddr + 0x88) == '\0') {
    VCALL(*M<int *>(accelAddr + kIOATIR500Accelerator_gartCollectorTimer), 300)
              (M<int *>(accelAddr + kIOATIR500Accelerator_gartCollectorTimer),M<UInt32>(accelAddr + kIOATIR500Accelerator_gartReclaimInterval));
    M<UInt8>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x88) = 1;
  }
  else {
    M<UInt8>(accelAddr + 0x89) = 1;
  }
returnCommandBuffer:
  VCALL(*M<int *>(self + kIOATIR5002DContext_commandBufferDescriptor), 0x14)(M<int *>(self + kIOATIR5002DContext_commandBufferDescriptor));
  *options = 0;
  *memory = M<IOMemoryDescriptor *>(self + kIOATIR5002DContext_commandBufferDescriptor);
  this->init_command_buffer_header((VendorCommandBufferHeader *)(M<VendorCommandBufferHeader *>(self + kIOATIR5002DContext_commandBufferHeader)),M<UInt32>(self + kIOATIR5002DContext_commandBufferSize),bufferFlags);
  GH_IOLockUnlock(M<UInt32>(M<int>(self + kIOATIR5002DContext_accelerator) + 0x840));
  return 0;
}
