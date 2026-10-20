/* NOTE 2026-09-19: 2 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Accelerator_Members.cpp
 *
 * RESOLVED (ledger pass): mid-size IOATIR500Accelerator members that had no body in the rebuild, transcribed
 * mechanically from the shipped kext's decompile (Tools/port_fn.py -> Tools/ghidra2cpp.py, Headers/GhidraCompat.h; the
 * pseudo-C is the transcription, see ATIR500Surface_BuildSwap.cpp for the conventions). Real addrs in the comments.
 *   display_change_handler (0x370)  foundFramebuffer (0x550)  findFramebuffers (0x770)  serializePerformanceStats (0x9f0)
 *   freeAllCommandBuffers (0x1fd0)  freeAllDataBuffers (0x3410)  free_gart_wirings (0x4a90)
 *   mapVendorTransferBuffer (0x4f20)  unmapVendorTransferBuffer (0x4fe0)  teardownAGP (0x5090)  removeFromGART (0x5270)
 *   disp_mode_did_change (0x5710)  teardown3D (0x5890)  disp_mode_will_change (0x6ad0)
 * `_ASICSupportsAGP` labels in the decompile are zero-immediate data references; the real target of each site (page_shift,
 * page_size, gIODTPlane, an OSMetaClass ...) was read from the relocation table and substituted (Headers/GhidraExterns.h).
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/GhidraExterns.h"

#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

#define ACCEL(x) ((IOATIR500Accelerator *)(x))
extern "C" void *GH_IOATIR500Accelerator_metaClass asm("__ZN20IOATIR500Accelerator9metaClassE");
static inline void GH_FreeTexvert(void *accelerator, void *texture) { IOATIR500Shared::free_texvert(reinterpret_cast<IOATIR500Accelerator *>(accelerator), reinterpret_cast<IOTextureBuffer *>(texture)); }

extern "C" UInt32 GH_IOFreeContiguous(...) asm("_IOFreeContiguous");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_IOGetTime(...) asm("_IOGetTime");
extern "C" UInt32 GH_IOLockWakeup(...) asm("_IOLockWakeup");
extern "C" UInt32 GH_IOPanic(...) asm("_IOPanic");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");
extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_ZN12OSDictionary12withCapacityEj(...) asm("__ZN12OSDictionary12withCapacityEj");
extern "C" UInt32 GH_ZN13IOFramebuffer26addFramebufferNotificationEPFiP8OSObjectP(...) asm("__ZN13IOFramebuffer26addFramebufferNotificationEPFiP8OSObjectPvPS_lS2_ES1_S2_");
extern "C" UInt32 GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(...) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");
extern "C" UInt32 GH_ZN8OSSymbol11withCStringEPKc(...) asm("__ZN8OSSymbol11withCStringEPKc");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");

/* real addr 0x370 */
/* (re-ported mechanically: see IOATIR500Accelerator_display_change_handler_Port.cpp) */


/* real addr 0x550 */
bool IOATIR500Accelerator::foundFramebuffer(IOFramebuffer *framebuffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *framebufferBytes = reinterpret_cast<UInt8 *>(framebuffer);

  UInt8 *nextSlotFramebufferPtr;
  UInt8 *knownFramebuffer;
  UInt32 knownCount;
  UInt8 *slotCursor;
  code *setProperty;
  SInt32 index;
  UInt32 slotsLeft;
  UInt32 pathLength;
  UInt8 path [288];
  SInt32 notification;
  SInt32 pathOk;
  UInt32 cfPlugInTypes;
  UInt32 result;
  
  knownCount = M<UInt32>(self + kIOATIR500Accelerator_displayCount);
  pathLength = 0x100;
  if (knownCount == 0) {
LAB_000005a0:
    M<UInt8 *>(self + knownCount * 0x20 + 0xd4) = framebufferBytes;
    index = M<SInt32>(self + kIOATIR500Accelerator_displayCount);
    notification = GH_ZN13IOFramebuffer26addFramebufferNotificationEPFiP8OSObjectP(framebufferBytes,(UInt32)&IOATIR500Accelerator::display_change_handler,self,index);
    M<SInt32>(self + index * 0x20 + 0xd8) = notification;
    if (notification != 0) {
      setProperty = M<code *>(M<SInt32>(framebufferBytes) + 0x160);
      cfPlugInTypes = VCALL(M<SInt32>(self), 0x188)(self,"IOCFPlugInTypes");
      (*setProperty)(framebufferBytes,"IOCFPlugInTypes",cfPlugInTypes);
      pathOk = VCALL(M<SInt32>(self), 0x218)(self,path,&pathLength,GH_gIOServicePlane);
      if (pathOk != 0) {
        VCALL(M<SInt32>(framebufferBytes), 0x164)(framebufferBytes,"IOAccelTypes",path);
        VCALL(M<SInt32>(framebufferBytes), 0x16c)
                  (framebufferBytes,"IOAccelIndex",0,M<UInt32>(self + kIOATIR500Accelerator_displayCount),0x20);
        VCALL(M<SInt32>(framebufferBytes), 0x16c)(framebufferBytes,"IOAccelRevision",0,2,0x20);
        ACCEL(self)->getVRAMDescriptor(M<UInt32>(self + kIOATIR500Accelerator_displayCount));
        M<SInt32>(self + kIOATIR500Accelerator_displayCount) = M<SInt32>(self + kIOATIR500Accelerator_displayCount) + 1;
        return 1;
      }
    }
    result = 0;
  }
  else {
    knownFramebuffer = M<UInt8 *>(self + kIOATIR500Accelerator_framebuffer0);
    slotsLeft = knownCount;
    slotCursor = self;
    while (framebufferBytes != knownFramebuffer) {
      slotsLeft = slotsLeft - 1;
      if (slotsLeft == 0) {
        if (1 < knownCount) {
          return 0;
        }
        goto LAB_000005a0;
      }
      nextSlotFramebufferPtr = slotCursor + 0xf4;
      slotCursor = slotCursor + 0x20;
      knownFramebuffer = M<UInt8 *>(nextSlotFramebufferPtr);
    }
    result = 1;
  }
  return result;
}

/* real addr 0x770 */
bool IOATIR500Accelerator::findFramebuffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *iterator;
  SInt32 *framebufferClassName;
  UInt8 *framebuffer;
  SInt32 child;
  UInt8 classNameNull;
  UInt32 nextEntry;
  UInt32 framebufferObject;
  SInt32 *entryService;
  SInt32 *entry;
  SInt32 *childIterator;
  
  iterator = (SInt32 *)VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x1bc)
                            (M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),GH_gIODTPlane);
  framebufferClassName = (SInt32 *)GH_ZN8OSSymbol11withCStringEPKc("IOFramebuffer");
  classNameNull = (framebufferClassName == (SInt32 *)0x0) << 1;
  if ((iterator != (SInt32 *)0x0) && (framebufferClassName != (SInt32 *)0x0)) {
    while( true ) {
      nextEntry = VCALL(*iterator, 0xd8)(iterator);
      entryService = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(nextEntry,GH_IOService_metaClass);
      if (entryService == (SInt32 *)0x0) break;
      framebufferObject = VCALL(*entryService, 0x444)(entryService,framebufferClassName);
      framebuffer = (UInt8 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(framebufferObject,GH_IOFramebuffer_metaClass);
      if (framebuffer != (UInt8 *)0x0) {
        ((IOATIR500Accelerator *)(self))->foundFramebuffer((IOFramebuffer *)framebuffer);
      }
    }
    VCALL(*iterator, 0x18)(iterator);
  }
  iterator = (SInt32 *)VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x3c0)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice));
  if (iterator != (SInt32 *)0x0) {
    while (entry = (SInt32 *)VCALL(*iterator, 0xd8)(iterator), entry != (SInt32 *)0x0) {
      framebuffer = (UInt8 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(entry,GH_IOFramebuffer_metaClass);
      if (framebuffer == (UInt8 *)0x0) {
        childIterator = (SInt32 *)VCALL(*entry, 0x3c0)(entry);
        while (child = VCALL(*childIterator, 0xd8)(childIterator), child != 0) {
          framebuffer = (UInt8 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(child,GH_IOFramebuffer_metaClass);
          if (framebuffer != (UInt8 *)0x0) {
            ((IOATIR500Accelerator *)(self))->foundFramebuffer((IOFramebuffer *)framebuffer);
          }
        }
        VCALL(*childIterator, 0x18)(childIterator);
      }
      else {
        ((IOATIR500Accelerator *)(self))->foundFramebuffer((IOFramebuffer *)framebuffer);
      }
    }
    VCALL(*iterator, 0x18)(iterator);
  }
  if (!(bool)(classNameNull >> 1 & 1)) {
    VCALL(*framebufferClassName, 0x18)(framebufferClassName);
  }
  return 1;
}

/* real addr 0x9f0 */
bool IOATIR500Accelerator::serializePerformanceStats(void *target, void *ref, OSSerialize *serializer) {

  SInt32 *accelerator;
  SInt32 *statsDictionary;
  UInt32 result;
  
  result = 0;
  accelerator = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(target,GH_IOATIR500Accelerator_metaClass);
  if (accelerator != (SInt32 *)0x0) {
    statsDictionary = (SInt32 *)GH_ZN12OSDictionary12withCapacityEj(1);
    if (statsDictionary != (SInt32 *)0x0) {
      VCALL(*accelerator, 0x568)(accelerator,statsDictionary);
      result = VCALL(*statsDictionary, 0x1c)(statsDictionary,serializer);
      VCALL(*statsDictionary, 0x18)(statsDictionary);
    }
  }
  return result;
}

/* real addr 0x1fd0 */
void IOATIR500Accelerator::freeAllCommandBuffers(UInt32 recordIndex) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 recordOffset;
  SInt32 bufferIndex;
  UInt8 *commandBuffer;
  
  recordOffset = recordIndex * 0x1c4;
  if (M<SInt16>(self + recordOffset + 0x402) != 0) {
    bufferIndex = 0;
    commandBuffer = self + recordOffset + 0x240;
    do {
      bufferIndex = bufferIndex + 1;
      ((IOATIR500Accelerator *)(self))->freeCommandBuffer((VendorCommandBuffer *)commandBuffer);
      commandBuffer = (UInt8 *)(commandBuffer + 0x1c);
    } while (bufferIndex < (SInt32)(UInt32)M<UInt16>(self + recordOffset + 0x402));
  }
  M<UInt16>(self + recordOffset + 0x402) = 0;
  M<UInt16>(self + recordOffset + 0x400) = 0;
  return;
}

/* real addr 0x3410 */
void IOATIR500Accelerator::freeAllDataBuffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *dataBuffer;
  UInt8 *nextBuffer;
  
  dataBuffer = M<UInt8 *>(self + kIOATIR500Accelerator_dataBufferCacheHead);
  while (dataBuffer != (UInt8 *)0x0) {
    nextBuffer = M<UInt8 *>(dataBuffer + 0x3c);
    ((IOATIR500Accelerator *)(self))->freeOneDataBuffer((VendorTextureBuffer *)dataBuffer);
    dataBuffer = nextBuffer;
  }
  M<UInt32>(self + kIOATIR500Accelerator_dataBufferCacheTail) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_dataBufferCacheCount) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_dataBufferCacheHead) = 0;
  return;
}

/* real addr 0x4a90 */
/* (re-ported mechanically: see IOATIR500Accelerator_free_gart_wirings_Port.cpp) */


/* real addr 0x4f20 */
bool IOATIR500Accelerator::mapVendorTransferBuffer(VendorTransferBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  M<UInt32>(bufferBytes) = 1;
  switch(M<UInt16>(bufferBytes + 0xc)) {
  case 0:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind0) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind0) + 1;
    break;
  case 1:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind1) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind1) + 1;
    break;
  case 2:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind2) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind2) + 1;
    break;
  case 3:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind3) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind3) + 1;
    break;
  case 4:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind4) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind4) + 1;
    break;
  default:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountOther) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountOther) + 1;
  }
  return 1;
}

/* real addr 0x4fe0 */
void IOATIR500Accelerator::unmapVendorTransferBuffer(VendorTransferBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  M<UInt32>(bufferBytes) = 0;
  switch(M<UInt16>(bufferBytes + 0xc)) {
  case 0:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind0) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind0) + -1;
    return;
  case 1:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind1) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind1) + -1;
    return;
  case 2:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind2) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind2) + -1;
    return;
  case 3:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind3) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind3) + -1;
    return;
  case 4:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind4) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountKind4) + -1;
    return;
  default:
    M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountOther) = M<SInt32>(self + kIOATIR500Accelerator_mappedTransferCountOther) + -1;
    return;
  }
}

/* real addr 0x5090 */
void IOATIR500Accelerator::teardownAGP(IOService *real_provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *selfBytes = reinterpret_cast<UInt8 *>(this);

  SInt32 pageSize;

  if (M<SInt32>(self + kIOATIR500Accelerator_gartTable) != 0) {
    GH_IOFreeContiguous(M<SInt32>(self + kIOATIR500Accelerator_gartTable),GH_page_size * 2 + M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB));
    M<UInt32>(self + kIOATIR500Accelerator_gartReservedEntry) = 1;
    M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry) = 0;
    pageSize = GH_page_size;
    M<UInt32>(self + kIOATIR500Accelerator_gartTable) = 0;
    M<SInt32>(self + kIOATIR500Accelerator_gartTableAllocatedBytes) = M<SInt32>(self + kIOATIR500Accelerator_gartTableAllocatedBytes) - (pageSize * 2 + M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB));
  }
  if ((M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice) != (SInt32 *)0x0) && ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 2) != 0)) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x5e0)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice));
    M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0xfffffffd;
  }
  return;
}

/* real addr 0x5270 */
/* (re-ported mechanically: see IOATIR500Accelerator_removeFromGART_Port.cpp) */


/* real addr 0x5710 */
bool IOATIR500Accelerator::disp_mode_did_change() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 panelSurface;
  UInt8 *panelRecord;
  UInt32 panelCount;
  UInt32 panelIndex;
  UInt32 panel;
  UInt8 *displayRecord;
  UInt8 *surface;
  UInt8 *perPanelCursor;
  
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x78) = 0;
  self[0x81] = 0x0;
  surface = M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead);
  if (surface == (UInt8 *)0x0) {
    panelCount = M<UInt32>(self + kIOATIR500Accelerator_displayCount);
  }
  else {
    do {
      ((IOATIR500Surface *)(surface))->reset_access();
      panelCount = M<UInt32>(self + kIOATIR500Accelerator_displayCount);
      if (panelCount != 0) {
        panelIndex = 0;
        panelRecord = surface;
        do {
          if ((1 << (panelIndex & 0x3f) & M<UInt32>(self + kIOATIR500Accelerator_displayConfigBits)) == 0) {
            panelRecord[0xcac] = 0x0;
            panelCount = M<UInt32>(self + kIOATIR500Accelerator_displayCount);
          }
          panelIndex = panelIndex + 1;
          panelRecord = panelRecord + 0x94;
        } while (panelIndex < panelCount);
      }
      surface = M<UInt8 *>(surface + 0x9c);
    } while (surface != M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead));
  }
  if (panelCount != 0) {
    panel = 0;
    displayRecord = self;
    perPanelCursor = self;
    do {
      M<UInt32>(perPanelCursor + 0x114) = 1;
      if (M<UInt32>(perPanelCursor + 0x124) != 0) {
        ((IOATIR500Accelerator *)(self))->setup_stereo(panel, M<UInt32>(perPanelCursor + 0x124));
        M<UInt32>(perPanelCursor + 0x124) = 0;
      }
      panelSurface = M<UInt32>(displayRecord + 0xe8);
      if (panelSurface != 0) {
        /* real: alloc_surfaces(surface->0xc18, false) - the decompile shows only the low byte and drops the retry argument */
        ((IOATIR500Surface *)(panelSurface))->alloc_surfaces(M<UInt32>(panelSurface + 0xc18), false);
        VCALL(*M<SInt32 *>(displayRecord + 0xe8), 0x5a4)(M<SInt32 *>(displayRecord + 0xe8));
      }
      panel = panel + 1;
      perPanelCursor = perPanelCursor + 4;
      displayRecord = displayRecord + 0x20;
    } while (panel < M<UInt32>(self + kIOATIR500Accelerator_displayCount));
  }
  GH_IOLockWakeup(M<UInt32>(self + kIOATIR500Accelerator_commandLock),self,0);
  return 1;
}

/* real addr 0x5890 */
void IOATIR500Accelerator::teardown3D() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 panelCount;
  UInt32 panel;
  UInt8 *perPanelCursor;
  
  ((IOATIR500Accelerator *)(self))->freeAllCommandBuffers(0);
  ((IOATIR500Accelerator *)(self))->freeAllDataBuffers();
  panelCount = M<UInt32>(self + kIOATIR500Accelerator_displayCount);
  if (panelCount != 0) {
    panel = 0;
    perPanelCursor = self;
    do {
      M<UInt32>(perPanelCursor + 0x114) = 1;
      if (M<SInt32>(perPanelCursor + 0x11c) != 0) {
        ((IOATIR500Accelerator *)(self))->setup_stereo(panel, 0);
        panelCount = M<UInt32>(self + kIOATIR500Accelerator_displayCount);
      }
      panel = panel + 1;
      perPanelCursor = perPanelCursor + 4;
    } while (panel < panelCount);
  }
  return;
}

/* real addr 0x6ad0 */
bool IOATIR500Accelerator::disp_mode_will_change(SInt32 mode) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool notLastBuffer;
  SInt32 prevNode;
  UInt8 *texvert;
  UInt8 *surface;
  UInt32 panel;
  UInt8 *textureNode;
  UInt8 *displayRecord;
  SInt32 bufferIndex;
  SInt32 nextNode;
  UInt8 *surfaceBuffer;   /* #176: byte pointer - a typed ATIR500SurfaceBuffer* scaled the +0x78 slot stride by sizeof(ATIR500SurfaceBuffer)=0x80 */
  UInt8 *perPanelCursor;
  UInt8 *bufferSlot;
  
  if (self[0x80] != 0x0) {
    VCALL(M<SInt32>(self), 0x54c)(self,M<SInt32>(self + kIOATIR500Accelerator_submitStamp) + -1);
    if (M<SInt32>(self + kIOATIR500Accelerator_displayCount) != 0) {
      panel = 0;
      displayRecord = self;
      perPanelCursor = self;
      do {
        if (M<SInt32 *>(displayRecord + 0xe8) != (SInt32 *)0x0) {
          VCALL(*M<SInt32 *>(displayRecord + 0xe8), 0x5a8)(M<SInt32 *>(displayRecord + 0xe8));
        }
        if (M<SInt32>(perPanelCursor + 0x11c) != 0) {
          M<SInt32>(perPanelCursor + 0x124) = M<SInt32>(perPanelCursor + 0x11c);
          ((IOATIR500Accelerator *)(self))->setup_stereo(panel, 0);
        }
        panel = panel + 1;
        displayRecord = displayRecord + 0x20;
        perPanelCursor = perPanelCursor + 4;
      } while (panel < M<UInt32>(self + kIOATIR500Accelerator_displayCount));
    }
    textureNode = M<UInt8 *>(self + kIOATIR500Accelerator_textureVramListFirst);
    while (textureNode != self + kIOATIR500Accelerator_textureVramListSentinel) {
      if (M<SInt32>(textureNode + 0x48) != 0) {
        VCALL(M<SInt32>(self), 0x524)(self,textureNode);
        M<UInt8>(M<SInt32>(textureNode + 0x14) + 0x14) = 1;
        M<UInt16>(M<SInt32>(textureNode + 0x14) + 0x28) = 0;
        M<UInt16>(M<SInt32>(textureNode + 0x14) + 0x2a) = 0;
        M<UInt16>(M<SInt32>(textureNode + 0x14) + 0x2c) = 0;
        M<UInt16>(M<SInt32>(textureNode + 0x14) + 0x2e) = 0;
        M<UInt16>(M<SInt32>(textureNode + 0x14) + 0x30) = 0;
        M<UInt16>(M<SInt32>(textureNode + 0x14) + 0x32) = 0;
      }
      prevNode = M<SInt32>(textureNode + 0x24);
      M<UInt32>(prevNode + 0x28) = M<UInt32>(textureNode + 0x28);
      nextNode = M<SInt32>(textureNode + 0x28);
      M<UInt8 *>(textureNode + 0x28) = textureNode;
      M<SInt32>(nextNode + 0x24) = prevNode;
      M<UInt8 *>(textureNode + 0x24) = textureNode;
      textureNode = M<UInt8 *>(self + kIOATIR500Accelerator_textureVramListFirst);
    }
    texvert = M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_next);
    while (texvert != (UInt8 *)(self + kIOATIR500Accelerator_orphanTextureList)) {
      prevNode = M<SInt32>(texvert + 0x24);
      M<UInt32>(prevNode + 0x28) = M<UInt32>(texvert + 0x28);
      nextNode = M<SInt32>(texvert + 0x28);
      M<UInt8 *>(texvert + 0x28) = texvert;
      M<SInt32>(nextNode + 0x24) = prevNode;
      M<UInt8 *>(texvert + 0x24) = texvert;
      GH_FreeTexvert(self,texvert);
      texvert = M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_next);
    }
    surface = M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead);
    if (surface != (UInt8 *)0x0) {
      do {
        bufferIndex = 0;
        surfaceBuffer = surface + 0xa8;
        bufferSlot = surface;
        do {
          if (M<SInt32>(bufferSlot + 0xb0) != 0) {
            ((IOATIR500Surface *)(surface))->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
          }
          notLastBuffer = bufferIndex != 0x16;
          surfaceBuffer = surfaceBuffer + 0x78;
          bufferSlot = bufferSlot + 0x78;
          bufferIndex = bufferIndex + 1;
        } while (notLastBuffer);
        surface = M<UInt8 *>(surface + 0x9c);
      } while (surface != M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead));
    }
    VCALL(M<SInt32>(self), 0x54c)(self,M<SInt32>(self + kIOATIR500Accelerator_submitStamp) + -1);
    self[0x81] = (mode == 3);
    if (self[0x88] != 0x0) {
      VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_gartCollectorTimer), 0x158)(M<SInt32 *>(self + kIOATIR500Accelerator_gartCollectorTimer));
    }
    self[0x89] = 0x0;
    self[0x88] = 0x0;
  }
  return 1;
}
