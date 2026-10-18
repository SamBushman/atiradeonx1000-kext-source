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
  UInt8 *pIVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  SInt32 *piVar5;
  UInt32 uVar6;
  UInt8 *memoryManager;
  UInt32 *agpCommandValue;
  UInt8 *pIVar8;
  UInt8 *buffersPerPanelCursor;
  UInt8 *pIVar10;
  SInt32 blockOffset;
  UInt32 uVar12;
  SInt32 entriesLeft;
  SInt32 local_38 [2];
  SInt32 panel;
  UInt8 *bufferRecord;
  UInt8 *panelBlock;
  UInt8 *panelCounters;
  UInt8 *blockEntry;
  UInt8 auStack_30 [8];   /* sysctl result buffer; the shipped code reads its last byte (a big-endian 64-bit value) */
  
  iVar3 = IOAccelerator::start(provider);
  if (iVar3 == 0) {
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
  M<UInt32>(self + kIOATIR500Accelerator_memoryPool) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramSize) = 0;
  self[0x80] = 0x0;
  self[0x81] = 0x0;
  self[0x83] = 0x0;
  self[0x82] = 0x0;
  M<UInt32>(self + kIOATIR500Accelerator_registerDeviceMemory) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0xb0) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartUsedBytes) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartCacheBytes) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartReservedEntry) = 1;
  M<UInt16>(self + kIOATIR500Accelerator_unknown_0xaa) = 0x1000;
  M<UInt32>(self + kIOATIR500Accelerator_submitStamp) = 1;
  self[0x85] = 0x1;
  M<UInt16>(self + kIOATIR500Accelerator_unknown_0xa8) = 0x1000;
  local_38[0] = 8;
  iVar3 = GH_sysctlbyname("hw.cachelinesize",auStack_30,local_38,0,0);
  if (iVar3 == 0) {
    self[0x84] = auStack_30[7];
  }
  else {
    self[0x84] = 0x20;
  }
  M<UInt32>(self + kIOATIR500Accelerator_framebufferCount) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_activePanelMask) = 0;
  panel = 0;
  pIVar10 = self + kIOATIR500Accelerator_unknown_0x150;
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
    M<UInt32>(pIVar10 + 0x18) = M<UInt32>(pIVar10 + 0x18) & 0xff0007ff | 0x111000;
    M<UInt32>(bufferRecord + 0x16c) = 0;
    pIVar10 = pIVar10 + 0x78;
    M<UInt32>(bufferRecord + 0x170) = 0;
    M<UInt32>(buffersPerPanelCursor + 0x114) = 1;
    bufferRecord = bufferRecord + 0x78;
    buffersPerPanelCursor = buffersPerPanelCursor + 4;
  } while (notLastIteration);
  M<UInt32>(self + kIOATIR500Accelerator_liveSurfaceListHead) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_liveGLContextListHead) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_live2DContextListHead) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_liveDVDContextListHead) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x6c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x70) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_currentContext) = 0;
  GH_memset(self + kIOATIR500Accelerator_commandBytesPerSample,0,0x130);
  M<UInt16>(self + kIOATIR500Accelerator_scratchCommandBuffer_0x0c) = 1;
  M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBufferSize) = 0;
  panel = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBuffer) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBufferGartOffset) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBufferMemory) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_scratchCommandBuffer_0x0e) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBuffer_0x10) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBufferHeader) = 0;
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
  pIVar2 = self + kIOATIR500Accelerator_vramBufferList;
  pIVar8 = self + kIOATIR500Accelerator_orphanTextureList;
  M<UInt32>(self + kIOATIR500Accelerator_dataBufferCacheCount) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_dataBufferCacheHead) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_dataBufferCacheTail) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramBufferList) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_transferNext) = pIVar2;
  M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_prev) = pIVar2;
  M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_next) = pIVar2;
  M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_transferPrev) = pIVar2;
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
  M<UInt32>(self + kIOATIR500Accelerator_commandBufferSize) = 0x20000;
  M<UInt16>(self + kIOATIR500Accelerator_vramBufferList_kind) = 4;
  M<UInt32>(self + kIOATIR500Accelerator_dataBufferSizeThreshold) = 0x10000;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x10) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_transferNext) = pIVar8;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x14) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x18) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x1c) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_orphanTextureList_0x22) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_prev) = pIVar8;
  M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_next) = pIVar8;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x2c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_orphanTextureList_0x30) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_orphanTextureList_transferPrev) = pIVar8;
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
  iVar3 = GH_ZN10IOWorkLoop8workLoopEv();
  M<SInt32>(self + kIOATIR500Accelerator_workLoop) = iVar3;
  if (iVar3 == 0) goto LAB_00002f98;
  iVar3 = GH_ZN22IOInterruptEventSource20interruptEventSourceEP8OSObjectP(self,garbage_collector,0,0);
  M<SInt32>(self + kIOATIR500Accelerator_garbageCollectorSource) = iVar3;
  if (iVar3 != 0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_workLoop), 0xe4)(M<SInt32 *>(self + kIOATIR500Accelerator_workLoop),iVar3);
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorSource), 0xec)(M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorSource));
  }
  iVar3 = GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(self,garbage_collector_timer);
  M<SInt32>(self + kIOATIR500Accelerator_garbageCollectorTimer) = iVar3;
  if (iVar3 != 0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_workLoop), 0xe4)(M<SInt32 *>(self + kIOATIR500Accelerator_workLoop),iVar3);
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorTimer), 0xec)(M<SInt32 *>(self + kIOATIR500Accelerator_garbageCollectorTimer));
  }
  pIVar2 = self + kIOATIR500Accelerator_gartWiredTransferList;
  M<UInt16>(self + kIOATIR500Accelerator_gartWiredTransferList_kind) = 4;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x04) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x08) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_gartWiredTransferList_transferNext) = pIVar2;
  M<UInt16>(self + kIOATIR500Accelerator_gartWiredTransferList_0x0e) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x10) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x14) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x18) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x1c) = 0;
  M<UInt16>(self + kIOATIR500Accelerator_gartWiredTransferList_0x22) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_gartWiredTransferList_prev) = pIVar2;
  M<UInt8 *>(self + kIOATIR500Accelerator_gartWiredTransferList_next) = pIVar2;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x2c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x30) = 0;
  M<UInt8 *>(self + kIOATIR500Accelerator_gartWiredTransferList_transferPrev) = pIVar2;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x3c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x40) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x44) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x48) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x4c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x50) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x54) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartWiredTransferList_0x58) = 0;
  iVar3 = GH_ZN22IOInterruptEventSource20interruptEventSourceEP8OSObjectP(self,gart_collector,0,0);
  M<SInt32>(self + kIOATIR500Accelerator_gartCollectorSource) = iVar3;
  if (iVar3 != 0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_workLoop), 0xe4)(M<SInt32 *>(self + kIOATIR500Accelerator_workLoop),iVar3);
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_gartCollectorSource), 0xec)(M<SInt32 *>(self + kIOATIR500Accelerator_gartCollectorSource));
  }
  iVar3 = GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(self,gart_collector_timer);
  M<SInt32>(self + kIOATIR500Accelerator_gartCollectorTimer) = iVar3;
  if (iVar3 != 0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_workLoop), 0xe4)(M<SInt32 *>(self + kIOATIR500Accelerator_workLoop),iVar3);
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_gartCollectorTimer), 0xec)(M<SInt32 *>(self + kIOATIR500Accelerator_gartCollectorTimer));
  }
  M<UInt32>(self + kIOATIR500Accelerator_gartReclaimTimeoutNsec) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartReclaimTimeoutSec) = 1;
  M<UInt32>(self + kIOATIR500Accelerator_gartReclaimInterval) = 0xfa;
  uVar4 = VCALL(M<SInt32>(self), 0x188)(self,"GARTReclaimInterval");
  uVar12 = GH_OSNumber_metaClass;
  piVar5 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar4,GH_OSNumber_metaClass);
  if (piVar5 != (SInt32 *)0x0) {
    uVar4 = VCALL(*piVar5, 0xe8)(piVar5);
    M<UInt32>(self + kIOATIR500Accelerator_gartReclaimInterval) = uVar4;
  }
  uVar4 = VCALL(M<SInt32>(self), 0x188)(self,"GARTReclaimTimeout");
  piVar5 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar4,uVar12);
  if (piVar5 != (SInt32 *)0x0) {
    uVar6 = VCALL(*piVar5, 0xe8)(piVar5);
    M<UInt32>(self + kIOATIR500Accelerator_gartReclaimTimeoutSec) = uVar6 / 1000;
    M<UInt32>(self + kIOATIR500Accelerator_gartReclaimTimeoutNsec) = (uVar6 - uVar6 / 1000) * 1000;
  }
  uVar4 = VCALL(M<SInt32>(self), 0x188)(self,"GARTCacheSize");
  piVar5 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar4,uVar12);
  if (piVar5 != (SInt32 *)0x0) {
    uVar4 = VCALL(*piVar5, 0xe8)(piVar5);
    M<UInt32>(self + kIOATIR500Accelerator_gartCacheBytes) = uVar4;
  }
  iVar3 = GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(provider,GH_IOPCIDevice_metaClass);
  M<SInt32>(self + kIOATIR500Accelerator_pciDevice) = iVar3;
  if (iVar3 == 0) goto LAB_00002f98;
  iVar3 = GH_IOLockAlloc();
  M<SInt32>(self + kIOATIR500Accelerator_commandLock) = iVar3;
  if (iVar3 == 0) goto LAB_00002f98;
  M<UInt32>(self + kIOATIR500Accelerator_commandBufferMemoryOptions) = 0;
  iVar3 = VCALL(M<SInt32>(self), 0x580)(self,provider);
  if (iVar3 == 0) goto LAB_00002f98;
  piVar5 = (SInt32 *)GH_ZN12OSSerializer9forTargetEPvPFbS0_S0_P11OSSerializeES0_(self,(void *)&IOATIR500Accelerator::serializePerformanceStats,0);
  if (piVar5 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(self), 0x160)(self,"PerformanceStatistics",piVar5);
    VCALL(*piVar5, 0x18)(piVar5);
  }
  VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x55c)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),1);
  VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x564)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),1);
  memoryManager = (UInt8 *)new ATIR500Memory();   /* real: OSObject::operator new(0x14) + the ATIR500Memory constructor */
  M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool) = memoryManager;
  if (memoryManager == (UInt8 *)0x0) goto LAB_00002f98;
  iVar3 = VCALL(M<SInt32>(memoryManager), 0x48)(memoryManager);
  if (iVar3 == 0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_memoryPool), 0x18)(M<SInt32 *>(self + kIOATIR500Accelerator_memoryPool));
    M<UInt32>(self + kIOATIR500Accelerator_memoryPool) = 0;
    goto LAB_00002f98;
  }
  iVar3 = ((IOATIR500Accelerator *)(self))->allocCommandBuffer((VendorCommandBuffer *)(self + kIOATIR500Accelerator_scratchCommandBuffer), 0x1000);
  if (iVar3 == 0) goto LAB_00002f98;
  if (((M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) & 1) != 0) &&
     (VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_scratchCommandBufferMemory), 0x144)(M<SInt32 *>(self + kIOATIR500Accelerator_scratchCommandBufferMemory),3),
     M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2 != 0)) {
    uVar12 = 0;
    do {
      iVar3 = uVar12 << (GH_page_shift & 0x3f);
      uVar12 = uVar12 + 1;
      VCALL(M<SInt32>(self), 0x588)(self,M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBufferMemory),iVar3,0);
    } while (uVar12 < M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2);
  }
  VCALL(M<SInt32>(self), 0x16c)(self,"IOAccelRevision",0,2,0x20);
  piVar5 = (SInt32 *)GH_ZN15IORegistryEntry15getRegistryRootEv();
  if (piVar5 == (SInt32 *)0x0) {
LAB_00002f28:
    iVar3 = 1;
  }
  else {
    uVar4 = VCALL(*piVar5, 0x188)(piVar5,"IOKitBuildVersion");
    piVar5 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar4,GH_OSString_metaClass);
    if (piVar5 == (SInt32 *)0x0) goto LAB_00002f28;
    uVar4 = VCALL(*piVar5, 0xe8)(piVar5);
    iVar3 = GH_sscanf(uVar4,"IOKit Component Version %d.%d:",local_38,auStack_30);
    if ((iVar3 != 2) || (6 < local_38[0])) goto LAB_00002f28;
    iVar3 = ((IOATIR500Accelerator *)(self))->findFramebuffers();
  }
  uVar4 = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x188)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),"IOAGPCommandValue")
  ;
  piVar5 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar4,GH_OSData_metaClass);
  if ((piVar5 != (SInt32 *)0x0) &&
     (agpCommandValue = (UInt32 *)VCALL(*piVar5, 0x100)(piVar5), (*agpCommandValue & 0x10) != 0)) {
    M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) = M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) | 0x20;
  }
  if (iVar3 != 0) {
    return iVar3;
  }
LAB_00002f98:
  IOATIR500Accelerator::stop(provider);
  return 0;
}

extern "C" UInt32 GH_IOMallocContiguous(...) asm("_IOMallocContiguous");

/* real addr 0x5b80 */
bool IOATIR500Accelerator::configureAGP(IOService *real_provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);

  SInt32 byteOffset;
  SInt32 iVar2;
  UInt32 uVar3;
  SInt32 *agpFlagsNumber;
  UInt32 uVar5;
  UInt32 totalPages;
  UInt8 bVar7;
  UInt32 sysctlLength;
  UInt32 gartBytes;
  UInt32 local_mem[2];   /* hw.memsize as a big-endian 64-bit value: [0] high, [1] low (local_mem[0] / local_mem[1] in the decompile) */
  
  iVar2 = GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(M<UInt32>(self + kIOATIR500Accelerator_pciDevice),GH_IOAGPDevice_metaClass);
  if (((iVar2 != 0) &&
      (iVar2 = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x188)
                         (M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),"IOAGPFlags"), iVar2 != 0)) &&
     (iVar2 = VCALL(M<SInt32>(self), 0x5e4)(self), iVar2 != 0)) {
    M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) = M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) | 1;
    uVar3 = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x188)
                      (M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),"IOAGPFlags");
    agpFlagsNumber = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar3,GH_OSNumber_metaClass);
    if (agpFlagsNumber == (SInt32 *)0x0) {
      M<UInt32>(self + kIOATIR500Accelerator_commandBufferMemoryOptions) = 0x400;
    }
    else {
      uVar5 = VCALL(*agpFlagsNumber, 0xe8)(agpFlagsNumber);
      if ((uVar5 & 2) == 0) {
        M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) = M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) | 4;
      }
      if ((uVar5 & 4) == 0) {
        M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) = M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) | 8;
      }
      if ((uVar5 & 0x20) != 0) {
        M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) = M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) | 0x10;
      }
    }
  }
  iVar2 = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x188)
                    (M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),"IOPCIExpressLinkStatus");
  if (iVar2 != 0) {
    M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) = M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) | 0x40;
  }
  sysctlLength = 8;
  iVar2 = GH_sysctlbyname("hw.memsize",local_mem,&sysctlLength,0,0);
  if (iVar2 != 0) {
    local_mem[0] = 0;
    local_mem[1] = 0x20000000;
  }
  uVar5 = local_mem[1] >> 0xc;
  totalPages = local_mem[0] << 0x14 | uVar5;
  M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = totalPages;
  if ((M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) & 1) == 0) {
    if (totalPages < 0x8000) {
      M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = 0x8000;
    }
    else if (totalPages < 0x20001) {
      if ((uVar5 & 0xffff) != 0) {
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
      if ((uVar5 & 0xffff) != 0) {
        M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = totalPages + 0xffff & 0xffff0000;
      }
    }
    else {
      M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = 0x20000;
    }
    gartBytes = M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB) << 10;
    iVar2 = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x5dc)
                      (M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),0,self + kIOATIR500Accelerator_agpApertureBase,&gartBytes);
    if (iVar2 != 0) {
      return 0;
    }
    M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) = gartBytes >> 10;
    if (0x18000 < (gartBytes >> 10) - 0x8000) {
      return 0;
    }
    M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) = M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) | 2;
    /* real: the "IOAGPFlags" property cast to OSNumber; its unsigned64BitValue() (vtable +0xec, a 64-bit return whose
     * low word is in r4) bit 0 becomes the byte at this+0x85 */
    uVar3 = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x188)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),"IOAGPFlags");
    agpFlagsNumber = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar3,GH_OSNumber_metaClass);
    if (agpFlagsNumber != (SInt32 *)0x0) {
      typedef unsigned long long (*Value64Fn)(void *);
      unsigned long long agpValue = (*reinterpret_cast<Value64Fn *>(*reinterpret_cast<UInt8 **>(agpFlagsNumber) + 0xec))(agpFlagsNumber);
      self[0x85] = (UInt8)(agpValue & 1);
    }
  }
  uVar3 = GH_IOMallocContiguous(GH_page_size * 2 + M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB),GH_page_size,
                       self + kIOATIR500Accelerator_gartTablePhysical);
  M<UInt32>(self + kIOATIR500Accelerator_gartTable) = uVar3;
  uVar5 = VCALL(M<SInt32>(self), 0x5b0)
                    (self,M<SInt32>(self + kIOATIR500Accelerator_gartTablePhysical) + M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB));
  M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry) =
       uVar5 << 0x18 | (uVar5 & 0xff00) << 8 | uVar5 >> 8 & 0xff00 | uVar5 >> 0x18;
  uVar5 = VCALL(M<SInt32>(self), 0x5b0)
                    (self,M<SInt32>(self + kIOATIR500Accelerator_gartTablePhysical) + M<SInt32>(self + kIOATIR500Accelerator_gartSizeKB) +
                             GH_page_size);
  M<UInt32>(self + kIOATIR500Accelerator_gartReservedEntry) =
       uVar5 << 0x18 | (uVar5 & 0xff00) << 8 | uVar5 >> 8 & 0xff00 | uVar5 >> 0x18;
  iVar2 = M<SInt32>(self + kIOATIR500Accelerator_gartTable);
  if (iVar2 == 0) {
    return 0;
  }
  M<UInt32>(self + kIOATIR500Accelerator_gartTableAllocatedBytes) =
       ((GH_page_size + M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB)) - 1 & ~GH_page_size) +
       M<SInt32>(self + kIOATIR500Accelerator_gartTableAllocatedBytes);
  if (M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2 != 0) {
    uVar5 = 0;
    while( true ) {
      byteOffset = uVar5 * 4;
      uVar5 = uVar5 + 1;
      M<UInt32>(byteOffset + iVar2) = M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry);
      if (M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB) >> 2 <= uVar5) break;
      iVar2 = M<SInt32>(self + kIOATIR500Accelerator_gartTable);
    }
  }
  return 1;
}
