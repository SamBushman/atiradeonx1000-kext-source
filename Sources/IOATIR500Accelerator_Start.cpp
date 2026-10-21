/*
 * IOATIR500Accelerator_Start.cpp
 *
 * RESOLVED (ledger pass): IOATIR500Accelerator::start (real addr 0x2650, vtable +0x348) and configureAGP (0x5b80, +0x580).
 * start initialises every accelerator field, creates the workloop with the two software-only event sources
 * (garbage collector and GART collector, each with a timer), reads the GART reclaim tunables (GARTReclaimInterval /
 * GARTReclaimTimeout / GARTCacheSize), casts the provider to IOPCIDevice, allocates the command lock, runs
 * configureAGP, publishes "PerformanceStatistics", creates the ATIR500Memory pool, allocates the scratch command buffer,
 * maps the AGP aperture page by page when AGP is in use, and (for IOKit builds newer than 6) rescans framebuffers.
 * Transcribed mechanically from the decompile (Tools/port_fn.py); the base-class call is IOAccelerator::start.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/GhidraExterns.h"

#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"

inline void *operator new(size_t, void *where) { return where; }   /* placement new (the same inline definition as ATIRadeonX1000_Start.cpp) */

extern "C" UInt32 GH_IOLockAlloc(...) asm("_IOLockAlloc");
extern "C" UInt32 GH_ZN10IOWorkLoop8workLoopEv(...) asm("__ZN10IOWorkLoop8workLoopEv");
extern "C" UInt32 GH_ZN12OSSerializer9forTargetEPvPFbS0_S0_P11OSSerializeES0_(...) asm("__ZN12OSSerializer9forTargetEPvPFbS0_S0_P11OSSerializeES0_");
extern "C" UInt32 GH_ZN15IORegistryEntry15getRegistryRootEv(...) asm("__ZN15IORegistryEntry15getRegistryRootEv");
extern "C" UInt32 GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(...) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");
extern "C" UInt32 GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(...) asm("__ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_E");
extern "C" UInt32 GH_ZN22IOInterruptEventSource20interruptEventSourceEP8OSObjectP(...) asm("__ZN22IOInterruptEventSource20interruptEventSourceEP8OSObjectPFvS1_PS_iEP9IOServicei");
extern "C" UInt32 GH_ZN8OSObjectnwEm(...) asm("__ZN8OSObjectnwEm");
extern "C" UInt32 GH_memset(...) asm("_memset");
extern "C" UInt32 GH_sscanf(...) asm("_sscanf");
extern "C" UInt32 GH_sysctlbyname(...) asm("_sysctlbyname");

/* real addr 0x2650 */
bool IOATIR500Accelerator::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool notLastIteration;
  UInt32 timeoutMs;
  UInt8 *memoryManager;
  UInt32 *agpCommandValue;
  UInt8 *orphanListHead;
  UInt8 *buffersPerPanelCursor;
  UInt8 *scanoutBuffer;
  SInt32 blockOffset;
  SInt32 entriesLeft;
  SInt32 panel;
  UInt8 *bufferRecord;
  UInt8 *panelBlock;
  UInt8 *panelCounters;
  UInt8 *blockEntry;
  SInt32 superStartOk;
  SInt32 sysctlStatus;
  SInt32 workLoop;
  SInt32 garbageCollectorSource;
  SInt32 garbageCollectorTimer;
  SInt32 gartCollectorSource;
  SInt32 gartCollectorTimer;
  SInt32 pciDevice;
  SInt32 commandLock;
  SInt32 agpConfigured;
  SInt32 poolInitialized;
  SInt32 scratchAllocated;
  SInt32 gartByteOffset;
  SInt32 framebuffersOk;
  SInt32 scanCount;
  UInt32 property;
  UInt32 numberValue;
  UInt32 buildVersion;
  SInt32 *number;
  SInt32 *serializer;
  SInt32 *registryRoot;
  SInt32 *buildVersionString;
  SInt32 *agpData;
  UInt32 numberClass;
  UInt32 scratchPage;
  SInt32 sysctlLength [2];
  SInt32 kextMajorVersion [2];
  UInt8 *gartWiredListHead;
  UInt8 *vramListHead;
  UInt8 cacheLineBuffer [8];
  UInt8 kextMinorVersion [8];
  
  superStartOk = IOAccelerator::start(provider);
  if (superStartOk == 0) {
    return 0;
  }
  M<UInt32>(self + kIOATIR500Accelerator_volatileSurfaceCount) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_lastReadStamp) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_displayChangeDepth) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_pciDevice) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_commandLock) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartTable) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartTablePhysical) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_agpApertureBase) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramPool) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramSize) = 0;
  self[0x80] = 0x0;
  self[0x81] = 0x0;
  self[0x83] = 0x0;
  self[0x82] = 0x0;
  M<UInt32>(self + kIOATIR500Accelerator_pciBar0Config) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0xb0) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartUsedBytes) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartCacheBytes) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartReservedEntry) = 1;
  M<UInt16>(self + kIOATIR500Accelerator_maxSurfaceHeight) = 0x1000;
  M<UInt32>(self + kIOATIR500Accelerator_submitStamp) = 1;
  self[0x85] = 0x1;
  M<UInt16>(self + kIOATIR500Accelerator_maxSurfaceWidth) = 0x1000;
  sysctlLength[0] = 8;
  sysctlStatus = GH_sysctlbyname("hw.cachelinesize",cacheLineBuffer,sysctlLength,0,0);
  if (sysctlStatus == 0) {
    self[0x84] = cacheLineBuffer[7];
  }
  else {
    self[0x84] = 0x20;
  }
  M<UInt32>(self + kIOATIR500Accelerator_displayCount) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_displayConfigBits) = 0;
  panel = 0;
  scanoutBuffer = self + kIOATIR500Accelerator_scanout1BufferBackingStoreHandle;
  bufferRecord = self;
  panelCounters = self;
  buffersPerPanelCursor = self;
  do {
    M<UInt32>(panelCounters + 0xd4) = 0;
    M<UInt32>(panelCounters + 0xd8) = 0;
    notLastIteration = panel != 1;
    panel = panel + 1;
    M<UInt32>(panelCounters + 0xdc) = 0;
    M<UInt32>(panelCounters + 0xe0) = 0;
    M<UInt32>(panelCounters + 0xe4) = 0;
    M<UInt32>(panelCounters + 0xe8) = 0;
    M<UInt32>(panelCounters + 0xec) = 0;
    M<UInt32>(panelCounters + 0xf0) = 0;
    M<UInt16>(bufferRecord + 0x140) = 0;
    M<UInt16>(bufferRecord + 0x142) = 0;
    M<UInt16>(bufferRecord + 0x144) = 0;
    M<UInt16>(bufferRecord + 0x148) = 0;
    M<UInt16>(bufferRecord + 0x14a) = 0;
    M<UInt16>(bufferRecord + 0x14c) = 1;
    M<UInt16>(bufferRecord + 0x14e) = 1;
    bufferRecord[0x160] = 0x0;
    bufferRecord[0x161] = 0x0;
    bufferRecord[0x162] = 0x0;
    bufferRecord[0x163] = 0xff;
    bufferRecord[0x164] = 0x0;
    bufferRecord[0x165] = 0x0;
    bufferRecord[0x167] = 0x6;
    bufferRecord[0x168] = 0x0;
    M<UInt32>(bufferRecord + 300) = 0;
    M<UInt32>(bufferRecord + 0x130) = 0;
    M<UInt32>(bufferRecord + 0x134) = 0;
    M<UInt32>(bufferRecord + 0x138) = 0;
    M<UInt32>(bufferRecord + 0x13c) = 0;
    M<UInt32>(bufferRecord + 0x150) = 0;
    M<UInt32>(bufferRecord + 0x154) = 0xffffffff;
    M<UInt32>(bufferRecord + 0x158) = 0;
    M<UInt32>(bufferRecord + 0x15c) = 0;
    panelCounters = panelCounters + 0x20;
    M<UInt32>(scanoutBuffer + 0x18) = M<UInt32>(scanoutBuffer + 0x18) & 0xff0007ff | 0x111000;
    M<UInt32>(bufferRecord + 0x16c) = 0;
    scanoutBuffer = scanoutBuffer + 0x78;
    M<UInt32>(bufferRecord + 0x170) = 0;
    M<UInt32>(buffersPerPanelCursor + 0x114) = 1;
    bufferRecord = bufferRecord + 0x78;
    buffersPerPanelCursor = buffersPerPanelCursor + 4;
  } while (notLastIteration);
  M<UInt32>(self + kIOATIR500Accelerator_liveSurfaceListHead) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_liveGLContextListHead) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_live2DContextListHead) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_liveDVDContextListHead) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_globalShared) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_globalTextureCounter) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x78) = 0;
  GH_memset(self + kIOATIR500Accelerator_commandBytesPerSample,0,0x130);
  M<UInt16>(self + kIOATIR500Accelerator_scratchCommandBuffer_0x0c) = 1;
  M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBufferSize) = 0;
  panel = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBuffer) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scratchBufferGartOffset) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scratchBufferDescriptor) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_scratchCommandBuffer_0x0e) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBuffer_0x10) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scratchHeader) = 0;
  blockOffset = 0x240;
  panelBlock = self;
  do {
    M<UInt16>(panelBlock + 0x400) = 0;
    M<UInt16>(panelBlock + 0x402) = 0;
    blockEntry = self + blockOffset;
    entriesLeft = 0x10;
    do {
      M<UInt32>(blockEntry) = 0;
      M<UInt32>(blockEntry + 4) = 0;
      M<UInt32>(blockEntry + 8) = 0;
      M<UInt16>(blockEntry + 0xe) = 0;
      M<UInt16>(blockEntry + 0xc) = 1;
      M<UInt32>(blockEntry + 0x10) = 0;
      M<UInt32>(blockEntry + 0x14) = 0;
      M<UInt32>(blockEntry + 0x18) = 0;
      blockEntry = blockEntry + 0x1c;
      entriesLeft = entriesLeft + -1;
    } while (entriesLeft != 0);
    notLastIteration = panel != 1;
    blockOffset = blockOffset + 0x1c4;
    panelBlock = panelBlock + 0x1c4;
    panel = panel + 1;
  } while (notLastIteration);
  vramListHead = self + kIOATIR500Accelerator_textureVramListSentinel;
  orphanListHead = self + kIOATIR500Accelerator_orphanTextureList;
  M<UInt32>(self + kIOATIR500Accelerator_dataBufferCacheCount) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_dataBufferCacheHead) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_dataBufferCacheTail) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_textureVramListSentinel) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_transferNext) = vramListHead;
  M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_prev) = vramListHead;
  M<UInt8 *>(self + kIOATIR500Accelerator_textureVramListFirst) = vramListHead;
  M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_transferPrev) = vramListHead;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x04) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x08) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_vramBufferList_0x0e) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x10) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x14) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x18) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x1c) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_vramBufferList_0x22) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x2c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x30) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x3c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x40) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x44) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x48) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x4c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x50) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x54) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList_0x58) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x04) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x08) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_orphanTextureList_0x0e) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_cachedBufferSizeThreshold) = 0x20000;
  M<UInt16>(self + kIOATIR500Accelerator_vramBufferList_kind) = 4;
  M<UInt32>(self + kIOATIR500Accelerator_dataBufferSizeThreshold) = 0x10000;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x10) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_transferNext) = orphanListHead;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x14) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x18) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x1c) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_orphanTextureList_0x22) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_prev) = orphanListHead;
  M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_next) = orphanListHead;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x2c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x30) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_transferPrev) = orphanListHead;
  M<UInt16>(self + kIOATIR500Accelerator_orphanTextureList_kind) = 4;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x3c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x40) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x44) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x48) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x4c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x50) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x54) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x58) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x220) = 0;
  workLoop = GH_ZN10IOWorkLoop8workLoopEv();
  M<SInt32>(self + kIOATIR500Accelerator_workLoop) = workLoop;
  if (workLoop == 0) goto LAB_00002f98;
  garbageCollectorSource = GH_ZN22IOInterruptEventSource20interruptEventSourceEP8OSObjectP(self,garbage_collector,0,0);
  M<SInt32>(self + kIOATIR500Accelerator_garbageCollectorSource) = garbageCollectorSource;
  if (garbageCollectorSource != 0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_workLoop), 0xe4)(M<SInt32 *>(self + kIOATIR500Accelerator_workLoop),garbageCollectorSource);
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorSource), 0xec)(M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorSource));
  }
  garbageCollectorTimer = GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(self,garbage_collector_timer);
  M<SInt32>(self + kIOATIR500Accelerator_garbageCollectorTimer) = garbageCollectorTimer;
  if (garbageCollectorTimer != 0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_workLoop), 0xe4)(M<SInt32 *>(self + kIOATIR500Accelerator_workLoop),garbageCollectorTimer);
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorTimer), 0xec)(M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorTimer));
  }
  gartWiredListHead = self + kIOATIR500Accelerator_gartWiredTransferList;
  M<UInt16>(self + kIOATIR500Accelerator_gartWiredTransferList_kind) = 4;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x04) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x08) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_gartWiredTransferList_transferNext) = gartWiredListHead;
  M<UInt16>(self + kIOATIR500Accelerator_gartWiredTransferList_0x0e) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x10) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x14) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x18) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x1c) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_gartWiredTransferList_0x22) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_gartWiredTransferList_prev) = gartWiredListHead;
  M<UInt8 *>(self + kIOATIR500Accelerator_gartWiredTransferList_next) = gartWiredListHead;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x2c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x30) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_gartWiredTransferList_transferPrev) = gartWiredListHead;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x3c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x40) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x44) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x48) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x4c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x50) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x54) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x58) = 0;
  gartCollectorSource = GH_ZN22IOInterruptEventSource20interruptEventSourceEP8OSObjectP(self,gart_collector,0,0);
  M<SInt32>(self + kIOATIR500Accelerator_gartCollectorSource) = gartCollectorSource;
  if (gartCollectorSource != 0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_workLoop), 0xe4)(M<SInt32 *>(self + kIOATIR500Accelerator_workLoop),gartCollectorSource);
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_gartCollectorSource), 0xec)(M<SInt32 *>(self + kIOATIR500Accelerator_gartCollectorSource));
  }
  gartCollectorTimer = GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(self,gart_collector_timer);
  M<SInt32>(self + kIOATIR500Accelerator_gartCollectorTimer) = gartCollectorTimer;
  if (gartCollectorTimer != 0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_workLoop), 0xe4)(M<SInt32 *>(self + kIOATIR500Accelerator_workLoop),gartCollectorTimer);
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_gartCollectorTimer), 0xec)(M<SInt32 *>(self + kIOATIR500Accelerator_gartCollectorTimer));
  }
  M<UInt32>(self + kIOATIR500Accelerator_gartReclaimTimeoutNsec) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartReclaimTimeoutSec) = 1;
  M<UInt32>(self + kIOATIR500Accelerator_gartReclaimInterval) = 0xfa;
  property = VCALL(M<SInt32>(self), 0x188)(self,"GARTReclaimInterval");
  numberClass = GH_OSNumber_metaClass;
  number = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(property,GH_OSNumber_metaClass);
  if (number != (SInt32 *)0x0) {
    numberValue = VCALL(*number, 0xe8)(number);
    M<UInt32>(self + kIOATIR500Accelerator_gartReclaimInterval) = numberValue;
  }
  property = VCALL(M<SInt32>(self), 0x188)(self,"GARTReclaimTimeout");
  number = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(property,numberClass);
  if (number != (SInt32 *)0x0) {
    timeoutMs = VCALL(*number, 0xe8)(number);
    M<UInt32>(self + kIOATIR500Accelerator_gartReclaimTimeoutSec) = timeoutMs / 1000;
    M<UInt32>(self + kIOATIR500Accelerator_gartReclaimTimeoutNsec) = (timeoutMs - timeoutMs / 1000) * 1000;
  }
  property = VCALL(M<SInt32>(self), 0x188)(self,"GARTCacheSize");
  number = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(property,numberClass);
  if (number != (SInt32 *)0x0) {
    numberValue = VCALL(*number, 0xe8)(number);
    M<UInt32>(self + kIOATIR500Accelerator_gartCacheBytes) = numberValue;
  }
  pciDevice = GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(provider,GH_IOPCIDevice_metaClass);
  M<SInt32>(self + kIOATIR500Accelerator_pciDevice) = pciDevice;
  if (pciDevice == 0) goto LAB_00002f98;
  commandLock = GH_IOLockAlloc();
  M<SInt32>(self + kIOATIR500Accelerator_commandLock) = commandLock;
  if (commandLock == 0) goto LAB_00002f98;
  M<UInt32>(self + kIOATIR500Accelerator_commandBufferMemoryOptions) = 0;
  agpConfigured = VCALL(M<SInt32>(self), 0x580)(self,provider);
  if (agpConfigured == 0) goto LAB_00002f98;
  serializer = (SInt32 *)GH_ZN12OSSerializer9forTargetEPvPFbS0_S0_P11OSSerializeES0_(self,(void *)&IOATIR500Accelerator::serializePerformanceStats,0);
  if (serializer != (SInt32 *)0x0) {
    VCALL(M<SInt32>(self), 0x160)(self,"PerformanceStatistics",serializer);
    VCALL(*serializer, 0x18)(serializer);
  }
  VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x55c)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),1);
  VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x564)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),1);
  { void *mem = OSObject::operator new(0x14);   /* real: OSObject::operator new(0x14) + the ATIR500Memory constructor; the null check must be explicit: `new T()` compiled to an unconditional constructor call (the #187 bug class; found by the IOATIR500Accelerator::start hand world) */
    memoryManager = (UInt8 *)(mem ? ::new (mem) ATIR500Memory() : 0); }
  M<UInt8 *>(self + kIOATIR500Accelerator_vramPool) = memoryManager;
  if (memoryManager == (UInt8 *)0x0) goto LAB_00002f98;
  poolInitialized = VCALL(M<SInt32>(memoryManager), 0x48)(memoryManager);
  if (poolInitialized == 0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_vramPool), 0x18)(M<SInt32 *>(self + kIOATIR500Accelerator_vramPool));
    M<UInt32>(self + kIOATIR500Accelerator_vramPool) = 0;
    goto LAB_00002f98;
  }
  scratchAllocated = ((IOATIR500Accelerator *)(self))->allocCommandBuffer((VendorCommandBuffer *)(self + kIOATIR500Accelerator_scratchCommandBuffer), 0x1000);
  if (scratchAllocated == 0) goto LAB_00002f98;
  if (((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 1) != 0) &&
     (VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_scratchBufferDescriptor), 0x144)(M<SInt32 *>(self + kIOATIR500Accelerator_scratchBufferDescriptor),3),
     M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2 != 0)) {
    scratchPage = 0;
    do {
      gartByteOffset = scratchPage << (GH_page_shift & 0x3f);
      scratchPage = scratchPage + 1;
      VCALL(M<SInt32>(self), 0x588)(self,M<UInt32>(self + kIOATIR500Accelerator_scratchBufferDescriptor),gartByteOffset,0);
    } while (scratchPage < M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2);
  }
  VCALL(M<SInt32>(self), 0x16c)(self,"IOAccelRevision",0,2,0x20);
  registryRoot = (SInt32 *)GH_ZN15IORegistryEntry15getRegistryRootEv();
  if (registryRoot == (SInt32 *)0x0) {
LAB_00002f28:
    framebuffersOk = 1;
  }
  else {
    property = VCALL(*registryRoot, 0x188)(registryRoot,"IOKitBuildVersion");
    buildVersionString = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(property,GH_OSString_metaClass);
    if (buildVersionString == (SInt32 *)0x0) goto LAB_00002f28;
    buildVersion = VCALL(*buildVersionString, 0xe8)(buildVersionString);
    scanCount = GH_sscanf(buildVersion,"IOKit Component Version %d.%d:",kextMajorVersion,kextMinorVersion);
    if ((scanCount != 2) || (6 < kextMajorVersion[0])) goto LAB_00002f28;
    framebuffersOk = ((IOATIR500Accelerator *)(self))->findFramebuffers();
  }
  property = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x188)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),"IOAGPCommandValue")
  ;
  agpData = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(property,GH_OSData_metaClass);
  if ((agpData != (SInt32 *)0x0) &&
     (agpCommandValue = (UInt32 *)VCALL(*agpData, 0x100)(agpData), (*agpCommandValue & 0x10) != 0)) {
    M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) | 0x20;
  }
  if (framebuffersOk != 0) {
    return framebuffersOk;
  }
LAB_00002f98:
  IOATIR500Accelerator::stop(provider);
  return 0;
}

extern "C" UInt32 GH_IOMallocContiguous(...) asm("_IOMallocContiguous");

/* real addr 0x5b80 */
bool IOATIR500Accelerator::configureAGP(IOService *real_provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *selfBytes = reinterpret_cast<UInt8 *>(this);

  SInt32 byteOffset;
  SInt32 *agpFlagsNumber;
  UInt32 totalPages;
  UInt32 sysctlLength;
  UInt32 gartBytes;
  SInt32 agpDevice;
  SInt32 agpFlagsProperty;
  SInt32 asicSupportsAGP;
  SInt32 linkStatusProperty;
  SInt32 sysctlStatus;
  SInt32 createStatus;
  SInt32 gartTable;
  UInt32 agpFlagsObject;
  UInt32 gartTableMemory;
  UInt32 agpFlags;
  UInt32 memsizeLowPages;
  UInt32 gartEntry;
  UInt32 entryIndex;
  UInt32 local_mem[2];   /* hw.memsize as a big-endian 64-bit value: [0] high, [1] low (local_mem[0] / local_mem[1] in the decompile) */
  
  agpDevice = GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(M<UInt32>(self + kIOATIR500Accelerator_pciDevice),GH_IOAGPDevice_metaClass);
  if (((agpDevice != 0) &&
      (agpFlagsProperty = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x188)
                         (M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),"IOAGPFlags"), agpFlagsProperty != 0)) &&
     (asicSupportsAGP = VCALL(M<SInt32>(self), 0x5e4)(self), asicSupportsAGP != 0)) {
    M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) | 1;
    agpFlagsObject = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x188)
                      (M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),"IOAGPFlags");
    agpFlagsNumber = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(agpFlagsObject,GH_OSNumber_metaClass);
    if (agpFlagsNumber == (SInt32 *)0x0) {
      M<UInt32>(self + kIOATIR500Accelerator_commandBufferMemoryOptions) = 0x400;
    }
    else {
      agpFlags = VCALL(*agpFlagsNumber, 0xe8)(agpFlagsNumber);
      if ((agpFlags & 2) == 0) {
        M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) | 4;
      }
      if ((agpFlags & 4) == 0) {
        M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) | 8;
      }
      if ((agpFlags & 0x20) != 0) {
        M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) | 0x10;
      }
    }
  }
  linkStatusProperty = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x188)
                    (M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),"IOPCIExpressLinkStatus");
  if (linkStatusProperty != 0) {
    M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) | 0x40;
  }
  sysctlLength = 8;
  sysctlStatus = GH_sysctlbyname("hw.memsize",local_mem,&sysctlLength,0,0);
  if (sysctlStatus != 0) {
    local_mem[0] = 0;
    local_mem[1] = 0x20000000;
  }
  memsizeLowPages = local_mem[1] >> 0xc;
  totalPages = local_mem[0] << 0x14 | memsizeLowPages;
  M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = totalPages;
  if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 1) == 0) {
    if (totalPages < 0x8000) {
      M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = 0x8000;
    }
    else if (totalPages < 0x20001) {
      if ((memsizeLowPages & 0xffff) != 0) {
        M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = totalPages + 0xffff & 0xffff0000;
      }
    }
    else {
      M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = 0x20000;
    }
  }
  else {
    if (totalPages < 0x8000) {
      M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = 0x8000;
    }
    else if (totalPages < 0x20001) {
      if ((memsizeLowPages & 0xffff) != 0) {
        M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = totalPages + 0xffff & 0xffff0000;
      }
    }
    else {
      M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = 0x20000;
    }
    gartBytes = M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB) << 10;
    createStatus = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x5dc)
                      (M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),0,self + kIOATIR500Accelerator_agpApertureBase,&gartBytes);
    if (createStatus != 0) {
      return 0;
    }
    M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = gartBytes >> 10;
    if (0x18000 < (gartBytes >> 10) - 0x8000) {
      return 0;
    }
    M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) | 2;
    /* real: the "IOAGPFlags" property cast to OSNumber; its unsigned64BitValue() (vtable +0xec, a 64-bit return whose
     * low word is in r4) bit 0 becomes the byte at this+0x85 */
    agpFlagsObject = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x188)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),"IOAGPFlags");
    agpFlagsNumber = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(agpFlagsObject,GH_OSNumber_metaClass);
    if (agpFlagsNumber != (SInt32 *)0x0) {
      typedef unsigned long long (*Value64Fn)(void *);
      unsigned long long agpValue = (*reinterpret_cast<Value64Fn *>(*reinterpret_cast<UInt8 **>(agpFlagsNumber) + 0xec))(agpFlagsNumber);
      self[0x85] = (UInt8)(agpValue & 1);
    }
  }
  gartTableMemory = GH_IOMallocContiguous(GH_page_size * 2 + M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB),GH_page_size,
                       self + kIOATIR500Accelerator_gartTablePhysical);
  M<UInt32>(self + kIOATIR500Accelerator_gartTable) = gartTableMemory;
  gartEntry = VCALL(M<SInt32>(self), 0x5b0)
                    (self,M<SInt32>(self + kIOATIR500Accelerator_gartTablePhysical) + M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB));
  storeWordByteReversed(&M<UInt8>(self + kIOATIR500Accelerator_gartEmptyEntry), gartEntry);
  gartEntry = VCALL(M<SInt32>(self), 0x5b0)
                    (self,M<SInt32>(self + kIOATIR500Accelerator_gartTablePhysical) + M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB) +
                             GH_page_size);
  storeWordByteReversed(&M<UInt8>(self + kIOATIR500Accelerator_gartReservedEntry), gartEntry);
  gartTable = M<SInt32>(self + kIOATIR500Accelerator_gartTable);
  if (gartTable == 0) {
    return 0;
  }
  M<UInt32>(self + kIOATIR500Accelerator_gartTableAllocatedBytes) =
       ((GH_page_size + M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB)) - 1 & ~GH_page_size) +
       M<SInt32>(self + kIOATIR500Accelerator_gartTableAllocatedBytes);
  if (M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2 != 0) {
    entryIndex = 0;
    while( true ) {
      byteOffset = entryIndex * 4;
      entryIndex = entryIndex + 1;
      M<UInt32>(byteOffset + gartTable) = M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry);
      if (M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2 <= entryIndex) break;
      gartTable = M<SInt32>(self + kIOATIR500Accelerator_gartTable);
    }
  }
  return 1;
}
