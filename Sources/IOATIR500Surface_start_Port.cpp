/*
 * IOATIR500Surface_start_Port.cpp
 *
 * IOATIR500Surface::start (real addr 0x119f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern const VendorExternalMethod kSurfaceMethods[19] asm("__ZZN16IOATIR500Surface5startEP9IOServiceE11methodDescs");   /* ATIR500Surface_ExternalMethods.cpp */

extern "C" UInt32 GH_IOLockAlloc(...) asm("_IOLockAlloc");
extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");

/* a swap-buffer entry as IOATIR500Surface::start leaves it: every field zero except the 16-bit state at +0x0c, which is 2 */
static inline void ClearSwapBufferEntry(SwapBufferEntry *e) {
    e->unknown_0x00 = 0;
    e->gartOffset = 0;
    e->memory = 0;
    e->lockCount = 0;
    e->usageKind = 2;
    e->stamp = 0;
    e->header = 0;
    e->rectWordIndex = 0;
}

/* real addr 0x119f0 */
bool IOATIR500Surface::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

  bool success;
  SInt32 panelNo;
  UInt32 lock;
  UInt8 *accelerator;
  UInt8 *formatSlot;
  UInt8 *surfaceBuffer;
  UInt8 *tilingCursor;
  UInt32 panelIndex;
  SInt32 entryIndex;
  PanelRecord *panel;
  SInt32 superStartOk;
  SInt32 submitStamp;
  SInt32 buffersLeft;
  SInt32 haveVram;
  SInt32 regionMemory;
  SInt32 acceleratorBytes;
  SInt32 swapBufferOk;
  SInt32 firstSurface;
  SInt32 lastSurface;
  UInt8 *bufferRecord;
  UInt8 *regionSlot;
  
  superStartOk = IOUserClient::start(provider);
  if (superStartOk == 0) {
    return false;
  }
  M<UInt8 *>(self + kIOATIR500Surface_accelerator) = providerBytes;
  M<UInt32>(self + kIOATIR500Surface_vramInitSucceeded) = 0;
  submitStamp = M<SInt32>(providerBytes + 0x50);
  M<UInt32>(self + kIOATIR500Surface_requestedId) = 0xffffffe0;
  M<UInt32>(self + kIOATIR500Surface_submittedStamp) = 0;
  M<UInt32>(self + kIOATIR500Surface_flushedStamp) = 0;
  M<SInt32>(self + kIOATIR500Surface_stamp) = submitStamp + -0x3fffffff;
  lock = GH_IOLockAlloc();
  M<UInt32>(self + kIOATIR500Surface_backingLength) = 0;
  M<UInt32>(self + kIOATIR500Surface_glContextList) = 0;
  M<UInt32>(self + kIOATIR500Surface_lock) = lock;
  M<UInt32>(self + kIOATIR500Surface_context2DList) = 0;
  M<UInt32>(self + kIOATIR500Surface_boundDVDContext) = 0;
  M<UInt32>(self + kIOATIR500Surface_flipContext) = 0;
  M<UInt32>(self + kIOATIR500Surface_modeBits) = 0;
  M<UInt32>(self + kIOATIR500Surface_shapeBits) = 0;
  M<UInt16>(self + kIOATIR500Surface_width) = 0;
  M<UInt16>(self + kIOATIR500Surface_height) = 0;
  M<UInt16>(self + kIOATIR500Surface_committedWidth) = 0;
  M<UInt16>(self + kIOATIR500Surface_committedHeight) = 0;
  M<UInt32>(self + kIOATIR500Surface_contextReqBits) = 0x20000000;
  M<UInt32>(self + kIOATIR500Surface_reqBits) = 0x20000000;
  self[0xc09] = 0x0;
  self[0xbf7] = 0x0;
  buffersLeft = 0x17;
  surfaceBuffer = self + kIOATIR500Surface_buffers;
  tilingCursor = self + kIOATIR500Surface_buffer0HzBlockField;
  bufferRecord = self;
  formatSlot = self;
  do {
    M<UInt16>(bufferRecord + 0xbc) = 0;
    M<UInt16>(bufferRecord + 0xbe) = 0;
    M<UInt16>(bufferRecord + 0xc0) = 0;
    M<UInt16>(bufferRecord + 0xc4) = 0;
    M<UInt16>(bufferRecord + 0xc6) = 0;
    M<UInt16>(bufferRecord + 200) = 1;
    M<UInt16>(bufferRecord + 0xca) = 1;
    bufferRecord[0xdc] = 0x0;
    bufferRecord[0xdd] = 0x0;
    bufferRecord[0xde] = 0x0;
    bufferRecord[0xdf] = 0xff;
    bufferRecord[0xe0] = 0x0;
    bufferRecord[0xe1] = 0x0;
    bufferRecord[0xe3] = 0x6;
    bufferRecord[0xe4] = 0x0;
    M<UInt32>(bufferRecord + 0xa8) = 0;
    M<UInt32>(bufferRecord + 0xac) = 0;
    M<UInt32>(bufferRecord + 0xb0) = 0;
    M<UInt32>(bufferRecord + 0xb4) = 0;
    M<UInt32>(bufferRecord + 0xb8) = 0;
    M<UInt32>(bufferRecord + 0xcc) = 0;
    M<UInt32>(bufferRecord + 0xd0) = 0xffffffff;
    M<UInt32>(bufferRecord + 0xd4) = 0;
    M<UInt32>(bufferRecord + 0xd8) = 0;
    M<UInt32>(tilingCursor + 0x14) = M<UInt32>(tilingCursor + 0x14) & 0xff0007ff | 0x111000;
    M<UInt32>(bufferRecord + 0xe8) = 0;
    tilingCursor = tilingCursor + 0x78;
    M<UInt32>(bufferRecord + 0xec) = 0;
    M<UInt8 *>(formatSlot + 0xb70) = surfaceBuffer;
    bufferRecord = bufferRecord + 0x78;
    surfaceBuffer = surfaceBuffer + 0x78;
    formatSlot = formatSlot + 4;
    buffersLeft = buffersLeft + -1;
  } while (buffersLeft != 0);
  panel = PANEL_RECORD(self, 0);
  for (panelNo = 0; panelNo < 2; panelNo++, panel++) {
    M<UInt32>(self + panelNo * 8 + 0xd60) = 0;                 /* the per-id region record pointer and size */
    M<UInt32>(self + panelNo * 8 + 0xd64) = 0;
    panel->active = 0x0;
    panel->swapMode = 0x0;
    panel->slotIndex = 0;
    panel->swapBufferSize = 0;
    ClearSwapBufferEntry(&panel->entries[0]);
    for (entryIndex = 1; entryIndex < 5; entryIndex++) {
      ClearSwapBufferEntry(&panel->entries[entryIndex]);
    }
  }
  self[0xbd1] = 0x0;
  M<UInt16>(self + kIOATIR500Surface_memoryLockCount) = 0;
  self[0xc08] = 0x0;
  self[0xbec] = 0x0;
  self[0xbd0] = 0x0;
  self[0xbf4] = 0x1;
  self[0xbed] = 0x0;
  self[0xbf0] = 0x0;
  self[0xbf1] = 0x0;
  self[0xbf2] = 0x0;
  self[0xbf3] = 0x0;
  self[0xbef] = 0x0;
  M<UInt32>(self + kIOATIR500Surface_volatileState) = 0;
  M<UInt32>(self + kIOATIR500Surface_backingStoreList) = 0;
  M<UInt32>(self + kIOATIR500Surface_accessDescriptor) = 0;
  M<UInt32>(self + kIOATIR500Surface_userMap) = 0;
  M<UInt32>(self + kIOATIR500Surface_userMapAddress) = 0;
  M<UInt32>(self + kIOATIR500Surface_kernelMap) = 0;
  M<UInt32>(self + kIOATIR500Surface_kernelMapAddress) = 0;
  M<UInt32>(self + kIOATIR500Surface_orphanedBacking) = 0;
  M<UInt32>(self + kIOATIR500Surface_lockDataFlags) = 0;
  accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
  M<UInt32>(self + kIOATIR500Surface_stateBits) = 0x307fffff;
  M<UInt32>(self + kIOATIR500Surface_panel) = 0xffff;
  if (M<SInt32>(accelerator + kIOATIR500Accelerator_displayCount) == 0) {
getVramDescriptors:
    haveVram = ((IOATIR500Accelerator *)(accelerator))->getVRAMDescriptors();
    if (haveVram != 0) {
      accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
      success = true;
      goto registerSurface;
    }
    accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
  }
  else {
    panelIndex = 0;
    regionSlot = self;
    do {
      regionMemory = GH_IOMallocAligned(0xc,0x20);
      M<SInt32>(regionSlot + 0xd60) = regionMemory;
      if (regionMemory == 0) {
failCleanup:
        accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
        break;
      }
      acceleratorBytes = M<SInt32>(self + kIOATIR500Surface_accelerator);
      if (acceleratorBytes != 0) {
        M<SInt32>(acceleratorBytes + 0x804) = M<SInt32>(acceleratorBytes + 0x804) + 0xc;
      }
      M<UInt32>(regionSlot + 0xd64) = 0xc;
      *M<UInt32 *>(regionSlot + 0xd60) = 0;
      M<UInt16>(M<SInt32>(regionSlot + 0xd60) + 4) = 0;
      M<UInt16>(M<SInt32>(regionSlot + 0xd60) + 6) = 0;
      M<UInt16>(M<SInt32>(regionSlot + 0xd60) + 8) = 0;
      M<UInt16>(M<SInt32>(regionSlot + 0xd60) + 10) = 0;
      swapBufferOk = this->allocMasterSwapBuffer(panelIndex,0x9000);
      if (swapBufferOk == 0) goto failCleanup;
      accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
      panelIndex = panelIndex + 1;
      regionSlot = regionSlot + 8;
    } while (panelIndex < M<UInt32>(accelerator + kIOATIR500Accelerator_displayCount));
    if (M<UInt32>(accelerator + kIOATIR500Accelerator_displayCount) == panelIndex) goto getVramDescriptors;
  }
  success = false;
registerSurface:
  M<UInt8 **>(self + kIOATIR500Surface_methodTable) = (UInt8 **)kSurfaceMethods; /* IOATIR500Surface::start(IOService*)::methodDescs */
  firstSurface = M<SInt32>(accelerator + kIOATIR500Accelerator_liveSurfaceListHead);
  if (firstSurface == 0) {
    M<UInt8 *>(self + kIOATIR500Surface_surfaceListNext) = self;
    M<UInt8 *>(self + kIOATIR500Surface_surfaceListPrev) = self;
  }
  else {
    lastSurface = M<SInt32>(firstSurface + 0xa0);
    M<SInt32>(self + kIOATIR500Surface_surfaceListNext) = firstSurface;
    M<SInt32>(self + kIOATIR500Surface_surfaceListPrev) = lastSurface;
    M<UInt8 *>(lastSurface + 0x9c) = self;
    M<UInt8 *>(firstSurface + 0xa0) = self;
  }
  M<UInt8 *>(accelerator + kIOATIR500Accelerator_liveSurfaceListHead) = self;
  M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x730) = M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x730) + 1;
  if (success) {
    M<UInt32>(self + kIOATIR500Surface_vramInitSucceeded) = 1;
  }
  else {
    IOATIR500Surface::stop(provider);
  }
  return success;
}
