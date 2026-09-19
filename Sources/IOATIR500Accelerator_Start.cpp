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
bool IOATIR500Accelerator::start(IOService *param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt8 *pIVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  SInt32 *piVar5;
  UInt32 uVar6;
  UInt8 *this_00;
  UInt32 *puVar7;
  UInt8 *pIVar8;
  UInt8 *pIVar9;
  UInt8 *pIVar10;
  SInt32 iVar11;
  UInt32 uVar12;
  SInt32 iVar13;
  SInt32 local_38 [2];
  UInt8 auStack_30 [8];   /* sysctl result buffer; the shipped code reads its last byte (a big-endian 64-bit value) */
  
  iVar3 = IOAccelerator::start(param_1);
  if (iVar3 == 0) {
    return 0;
  }
  M<UInt32>(self + 0x21c) = 0;
  M<UInt32>(self + 0x54) = 0;
  M<UInt32>(self + 200) = 0;
  M<UInt32>(self + 0x74) = 0;
  M<UInt32>(self + 0x840) = 0;
  M<UInt32>(self + 0x83c) = 0;
  M<UInt32>(self + 0x834) = 0;
  M<UInt32>(self + 0x838) = 0;
  M<UInt32>(self + 0x7c) = 0;
  M<UInt32>(self + 0x98) = 0;
  M<UInt32>(self + 0x9c) = 0;
  self[0x80] = 0x0;
  self[0x81] = 0x0;
  self[0x83] = 0x0;
  self[0x82] = 0x0;
  M<UInt32>(self + 0xac) = 0;
  M<UInt32>(self + 0xb0) = 0;
  M<UInt32>(self + 0xa0) = 0;
  M<UInt32>(self + 0xa4) = 0;
  M<UInt32>(self + 0x844) = 0;
  M<UInt32>(self + 0x848) = 1;
  M<UInt16>(self + 0xaa) = 0x1000;
  M<UInt32>(self + 0x50) = 1;
  self[0x85] = 0x1;
  M<UInt16>(self + 0xa8) = 0x1000;
  local_38[0] = 8;
  iVar3 = GH_sysctlbyname("hw.cachelinesize",auStack_30,local_38,0,0);
  if (iVar3 == 0) {
    self[0x84] = auStack_30[7];
  }
  else {
    self[0x84] = 0x20;
  }
  M<UInt32>(self + 0xcc) = 0;
  M<UInt32>(self + 0xd0) = 0;
  iVar3 = 0;
  pIVar10 = self + 0x150;
  pIVar2 = self;
  pIVar8 = self;
  pIVar9 = self;
  do {
    M<UInt32>(pIVar8 + 0xd4) = 0;
    M<UInt32>(pIVar8 + 0xd8) = 0;
    bVar1 = iVar3 != 1;
    iVar3 = iVar3 + 1;
    M<UInt32>(pIVar8 + 0xdc) = 0;
    M<UInt32>(pIVar8 + 0xe0) = 0;
    M<UInt32>(pIVar8 + 0xe4) = 0;
    M<UInt32>(pIVar8 + 0xe8) = 0;
    M<UInt32>(pIVar8 + 0xec) = 0;
    M<UInt32>(pIVar8 + 0xf0) = 0;
    M<UInt16>(pIVar2 + 0x140) = 0;
    M<UInt16>(pIVar2 + 0x142) = 0;
    M<UInt16>(pIVar2 + 0x144) = 0;
    M<UInt16>(pIVar2 + 0x148) = 0;
    M<UInt16>(pIVar2 + 0x14a) = 0;
    M<UInt16>(pIVar2 + 0x14c) = 1;
    M<UInt16>(pIVar2 + 0x14e) = 1;
    pIVar2[0x160] = 0x0;
    pIVar2[0x161] = 0x0;
    pIVar2[0x162] = 0x0;
    pIVar2[0x163] = 0xff;
    pIVar2[0x164] = 0x0;
    pIVar2[0x165] = 0x0;
    pIVar2[0x167] = 0x6;
    pIVar2[0x168] = 0x0;
    M<UInt32>(pIVar2 + 300) = 0;
    M<UInt32>(pIVar2 + 0x130) = 0;
    M<UInt32>(pIVar2 + 0x134) = 0;
    M<UInt32>(pIVar2 + 0x138) = 0;
    M<UInt32>(pIVar2 + 0x13c) = 0;
    M<UInt32>(pIVar2 + 0x150) = 0;
    M<UInt32>(pIVar2 + 0x154) = 0xffffffff;
    M<UInt32>(pIVar2 + 0x158) = 0;
    M<UInt32>(pIVar2 + 0x15c) = 0;
    pIVar8 = pIVar8 + 0x20;
    M<UInt32>(pIVar10 + 0x18) = M<UInt32>(pIVar10 + 0x18) & 0xff0007ff | 0x111000;
    M<UInt32>(pIVar2 + 0x16c) = 0;
    pIVar10 = pIVar10 + 0x78;
    M<UInt32>(pIVar2 + 0x170) = 0;
    M<UInt32>(pIVar9 + 0x114) = 1;
    pIVar2 = pIVar2 + 0x78;
    pIVar9 = pIVar9 + 4;
  } while (bVar1);
  M<UInt32>(self + 0x5c) = 0;
  M<UInt32>(self + 0x60) = 0;
  M<UInt32>(self + 100) = 0;
  M<UInt32>(self + 0x68) = 0;
  M<UInt32>(self + 0x6c) = 0;
  M<UInt32>(self + 0x70) = 0;
  M<UInt32>(self + 0x78) = 0;
  GH_memset(self + 0x6fc,0,0x130);
  M<UInt16>(self + 0x230) = 1;
  M<UInt32>(self + 0x23c) = 0;
  iVar3 = 0;
  M<UInt32>(self + 0x224) = 0;
  M<UInt32>(self + 0x228) = 0;
  M<UInt32>(self + 0x22c) = 0;
  M<UInt16>(self + 0x232) = 0;
  M<UInt32>(self + 0x234) = 0;
  M<UInt32>(self + 0x238) = 0;
  iVar11 = 0x240;
  pIVar2 = self;
  do {
    M<UInt16>(pIVar2 + 0x400) = 0;
    M<UInt16>(pIVar2 + 0x402) = 0;
    pIVar8 = self + iVar11;
    iVar13 = 0x10;
    do {
      M<UInt32>(pIVar8) = 0;
      M<UInt32>(pIVar8 + 4) = 0;
      M<UInt32>(pIVar8 + 8) = 0;
      M<UInt16>(pIVar8 + 0xe) = 0;
      M<UInt16>(pIVar8 + 0xc) = 1;
      M<UInt32>(pIVar8 + 0x10) = 0;
      M<UInt32>(pIVar8 + 0x14) = 0;
      M<UInt32>(pIVar8 + 0x18) = 0;
      pIVar8 = pIVar8 + 0x1c;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    bVar1 = iVar3 != 1;
    iVar11 = iVar11 + 0x1c4;
    pIVar2 = pIVar2 + 0x1c4;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  pIVar2 = self + 0x5dc;
  pIVar8 = self + 0x63c;
  M<UInt32>(self + 0x5d4) = 0;
  M<UInt32>(self + 0x5cc) = 0;
  M<UInt32>(self + 0x5d0) = 0;
  M<UInt32>(self + 0x5dc) = 0;
  M<UInt8 *>(self + 0x614) = pIVar2;
  M<UInt8 *>(self + 0x600) = pIVar2;
  M<UInt8 *>(self + 0x604) = pIVar2;
  M<UInt8 *>(self + 0x610) = pIVar2;
  M<UInt32>(self + 0x5e0) = 0;
  M<UInt32>(self + 0x5e4) = 0;
  M<UInt16>(self + 0x5ea) = 0;
  M<UInt32>(self + 0x5ec) = 0;
  M<UInt32>(self + 0x5f0) = 0;
  M<UInt32>(self + 0x5f4) = 0;
  M<UInt32>(self + 0x5f8) = 0;
  M<UInt16>(self + 0x5fe) = 0;
  M<UInt32>(self + 0x608) = 0;
  M<UInt32>(self + 0x60c) = 0;
  M<UInt32>(self + 0x618) = 0;
  M<UInt32>(self + 0x61c) = 0;
  M<UInt32>(self + 0x620) = 0;
  M<UInt32>(self + 0x624) = 0;
  M<UInt32>(self + 0x628) = 0;
  M<UInt32>(self + 0x62c) = 0;
  M<UInt32>(self + 0x630) = 0;
  M<UInt32>(self + 0x634) = 0;
  M<UInt32>(self + 0x63c) = 0;
  M<UInt32>(self + 0x640) = 0;
  M<UInt32>(self + 0x644) = 0;
  M<UInt16>(self + 0x64a) = 0;
  M<UInt32>(self + 0x5c8) = 0x20000;
  M<UInt16>(self + 0x5e8) = 4;
  M<UInt32>(self + 0x5d8) = 0x10000;
  M<UInt32>(self + 0x64c) = 0;
  M<UInt8 *>(self + 0x674) = pIVar8;
  M<UInt32>(self + 0x650) = 0;
  M<UInt32>(self + 0x654) = 0;
  M<UInt32>(self + 0x658) = 0;
  M<UInt16>(self + 0x65e) = 0;
  M<UInt8 *>(self + 0x660) = pIVar8;
  M<UInt8 *>(self + 0x664) = pIVar8;
  M<UInt32>(self + 0x668) = 0;
  M<UInt32>(self + 0x66c) = 0;
  M<UInt8 *>(self + 0x670) = pIVar8;
  M<UInt16>(self + 0x648) = 4;
  M<UInt32>(self + 0x678) = 0;
  M<UInt32>(self + 0x67c) = 0;
  M<UInt32>(self + 0x680) = 0;
  M<UInt32>(self + 0x684) = 0;
  M<UInt32>(self + 0x688) = 0;
  M<UInt32>(self + 0x68c) = 0;
  M<UInt32>(self + 0x690) = 0;
  M<UInt32>(self + 0x694) = 0;
  M<UInt32>(self + 0x220) = 0;
  iVar3 = GH_ZN10IOWorkLoop8workLoopEv();
  M<SInt32>(self + 0xb4) = iVar3;
  if (iVar3 == 0) goto LAB_00002f98;
  iVar3 = GH_ZN22IOInterruptEventSource20interruptEventSourceEP8OSObjectP(self,garbage_collector,0,0);
  M<SInt32>(self + 0xbc) = iVar3;
  if (iVar3 != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe4)(M<SInt32 *>(self + 0xb4),iVar3);
    VCALL(*M<SInt32 *>(self + 0xbc), 0xec)(M<SInt32 *>(self + 0xbc));
  }
  iVar3 = GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(self,garbage_collector_timer);
  M<SInt32>(self + 0xb8) = iVar3;
  if (iVar3 != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe4)(M<SInt32 *>(self + 0xb4),iVar3);
    VCALL(*M<SInt32 *>(self + 0xb8), 0xec)(M<SInt32 *>(self + 0xb8));
  }
  pIVar2 = self + 0x69c;
  M<UInt16>(self + 0x6a8) = 4;
  M<UInt32>(self + 0x69c) = 0;
  M<UInt32>(self + 0x6a0) = 0;
  M<UInt32>(self + 0x6a4) = 0;
  M<UInt8 *>(self + 0x6d4) = pIVar2;
  M<UInt16>(self + 0x6aa) = 0;
  M<UInt32>(self + 0x6ac) = 0;
  M<UInt32>(self + 0x6b0) = 0;
  M<UInt32>(self + 0x6b4) = 0;
  M<UInt32>(self + 0x6b8) = 0;
  M<UInt16>(self + 0x6be) = 0;
  M<UInt8 *>(self + 0x6c0) = pIVar2;
  M<UInt8 *>(self + 0x6c4) = pIVar2;
  M<UInt32>(self + 0x6c8) = 0;
  M<UInt32>(self + 0x6cc) = 0;
  M<UInt8 *>(self + 0x6d0) = pIVar2;
  M<UInt32>(self + 0x6d8) = 0;
  M<UInt32>(self + 0x6dc) = 0;
  M<UInt32>(self + 0x6e0) = 0;
  M<UInt32>(self + 0x6e4) = 0;
  M<UInt32>(self + 0x6e8) = 0;
  M<UInt32>(self + 0x6ec) = 0;
  M<UInt32>(self + 0x6f0) = 0;
  M<UInt32>(self + 0x6f4) = 0;
  iVar3 = GH_ZN22IOInterruptEventSource20interruptEventSourceEP8OSObjectP(self,gart_collector,0,0);
  M<SInt32>(self + 0xc4) = iVar3;
  if (iVar3 != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe4)(M<SInt32 *>(self + 0xb4),iVar3);
    VCALL(*M<SInt32 *>(self + 0xc4), 0xec)(M<SInt32 *>(self + 0xc4));
  }
  iVar3 = GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(self,gart_collector_timer);
  M<SInt32>(self + 0xc0) = iVar3;
  if (iVar3 != 0) {
    VCALL(*M<SInt32 *>(self + 0xb4), 0xe4)(M<SInt32 *>(self + 0xb4),iVar3);
    VCALL(*M<SInt32 *>(self + 0xc0), 0xec)(M<SInt32 *>(self + 0xc0));
  }
  M<UInt32>(self + 0x94) = 0;
  M<UInt32>(self + 0x90) = 1;
  M<UInt32>(self + 0x8c) = 0xfa;
  uVar4 = VCALL(M<SInt32>(self), 0x188)(self,"GARTReclaimInterval");
  uVar12 = GH_OSNumber_metaClass;
  piVar5 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar4,GH_OSNumber_metaClass);
  if (piVar5 != (SInt32 *)0x0) {
    uVar4 = VCALL(*piVar5, 0xe8)(piVar5);
    M<UInt32>(self + 0x8c) = uVar4;
  }
  uVar4 = VCALL(M<SInt32>(self), 0x188)(self,"GARTReclaimTimeout");
  piVar5 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar4,uVar12);
  if (piVar5 != (SInt32 *)0x0) {
    uVar6 = VCALL(*piVar5, 0xe8)(piVar5);
    M<UInt32>(self + 0x90) = uVar6 / 1000;
    M<UInt32>(self + 0x94) = (uVar6 - uVar6 / 1000) * 1000;
  }
  uVar4 = VCALL(M<SInt32>(self), 0x188)(self,"GARTCacheSize");
  piVar5 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar4,uVar12);
  if (piVar5 != (SInt32 *)0x0) {
    uVar4 = VCALL(*piVar5, 0xe8)(piVar5);
    M<UInt32>(self + 0xa4) = uVar4;
  }
  iVar3 = GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(param_1,GH_IOPCIDevice_metaClass);
  M<SInt32>(self + 0x74) = iVar3;
  if (iVar3 == 0) goto LAB_00002f98;
  iVar3 = GH_IOLockAlloc();
  M<SInt32>(self + 0x840) = iVar3;
  if (iVar3 == 0) goto LAB_00002f98;
  M<UInt32>(self + 0x82c) = 0;
  iVar3 = VCALL(M<SInt32>(self), 0x580)(self,param_1);
  if (iVar3 == 0) goto LAB_00002f98;
  piVar5 = (SInt32 *)GH_ZN12OSSerializer9forTargetEPvPFbS0_S0_P11OSSerializeES0_(self,(void *)&IOATIR500Accelerator::serializePerformanceStats,0);
  if (piVar5 != (SInt32 *)0x0) {
    VCALL(M<SInt32>(self), 0x160)(self,"PerformanceStatistics",piVar5);
    VCALL(*piVar5, 0x18)(piVar5);
  }
  VCALL(*M<SInt32 *>(self + 0x74), 0x55c)(M<SInt32 *>(self + 0x74),1);
  VCALL(*M<SInt32 *>(self + 0x74), 0x564)(M<SInt32 *>(self + 0x74),1);
  this_00 = (UInt8 *)new ATIR500Memory();   /* real: OSObject::operator new(0x14) + the ATIR500Memory constructor */
  M<UInt8 *>(self + 0x7c) = this_00;
  if (this_00 == (UInt8 *)0x0) goto LAB_00002f98;
  iVar3 = VCALL(M<SInt32>(this_00), 0x48)(this_00);
  if (iVar3 == 0) {
    VCALL(*M<SInt32 *>(self + 0x7c), 0x18)(M<SInt32 *>(self + 0x7c));
    M<UInt32>(self + 0x7c) = 0;
    goto LAB_00002f98;
  }
  iVar3 = ((IOATIR500Accelerator *)(self))->allocCommandBuffer((VendorCommandBuffer *)(self + 0x224), 0x1000);
  if (iVar3 == 0) goto LAB_00002f98;
  if (((M<UInt32>(self + 0x98) & 1) != 0) &&
     (VCALL(*M<SInt32 *>(self + 0x22c), 0x144)(M<SInt32 *>(self + 0x22c),3),
     M<UInt32>(self + 0x830) >> 2 != 0)) {
    uVar12 = 0;
    do {
      iVar3 = uVar12 << (GH_page_shift & 0x3f);
      uVar12 = uVar12 + 1;
      VCALL(M<SInt32>(self), 0x588)(self,M<UInt32>(self + 0x22c),iVar3,0);
    } while (uVar12 < M<UInt32>(self + 0x830) >> 2);
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
  uVar4 = VCALL(*M<SInt32 *>(self + 0x74), 0x188)(M<SInt32 *>(self + 0x74),"IOAGPCommandValue")
  ;
  piVar5 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar4,GH_OSData_metaClass);
  if ((piVar5 != (SInt32 *)0x0) &&
     (puVar7 = (UInt32 *)VCALL(*piVar5, 0x100)(piVar5), (*puVar7 & 0x10) != 0)) {
    M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) | 0x20;
  }
  if (iVar3 != 0) {
    return iVar3;
  }
LAB_00002f98:
  IOATIR500Accelerator::stop(param_1);
  return 0;
}

extern "C" UInt32 GH_IOMallocContiguous(...) asm("_IOMallocContiguous");

/* real addr 0x5b80 */
bool IOATIR500Accelerator::configureAGP(IOService *real_provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  SInt32 *piVar4;
  UInt32 uVar5;
  UInt32 uVar6;
  UInt8 bVar7;
  UInt32 local_28;
  UInt32 local_24;
  UInt32 local_mem[2];   /* hw.memsize as a big-endian 64-bit value: [0] high, [1] low (local_mem[0] / local_mem[1] in the decompile) */
  
  iVar2 = GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(M<UInt32>(self + 0x74),GH_IOAGPDevice_metaClass);
  if (((iVar2 != 0) &&
      (iVar2 = VCALL(*M<SInt32 *>(self + 0x74), 0x188)
                         (M<SInt32 *>(self + 0x74),"IOAGPFlags"), iVar2 != 0)) &&
     (iVar2 = VCALL(M<SInt32>(self), 0x5e4)(self), iVar2 != 0)) {
    M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) | 1;
    uVar3 = VCALL(*M<SInt32 *>(self + 0x74), 0x188)
                      (M<SInt32 *>(self + 0x74),"IOAGPFlags");
    piVar4 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar3,GH_OSNumber_metaClass);
    if (piVar4 == (SInt32 *)0x0) {
      M<UInt32>(self + 0x82c) = 0x400;
    }
    else {
      uVar5 = VCALL(*piVar4, 0xe8)(piVar4);
      if ((uVar5 & 2) == 0) {
        M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) | 4;
      }
      if ((uVar5 & 4) == 0) {
        M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) | 8;
      }
      if ((uVar5 & 0x20) != 0) {
        M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) | 0x10;
      }
    }
  }
  iVar2 = VCALL(*M<SInt32 *>(self + 0x74), 0x188)
                    (M<SInt32 *>(self + 0x74),"IOPCIExpressLinkStatus");
  if (iVar2 != 0) {
    M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) | 0x40;
  }
  local_28 = 8;
  iVar2 = GH_sysctlbyname("hw.memsize",local_mem,&local_28,0,0);
  if (iVar2 != 0) {
    local_mem[0] = 0;
    local_mem[1] = 0x20000000;
  }
  uVar5 = local_mem[1] >> 0xc;
  uVar6 = local_mem[0] << 0x14 | uVar5;
  M<UInt32>(self + 0x830) = uVar6;
  if ((M<UInt32>(self + 0x98) & 1) == 0) {
    if (uVar6 < 0x8000) {
      M<UInt32>(self + 0x830) = 0x8000;
    }
    else if (uVar6 < 0x20001) {
      if ((uVar5 & 0xffff) != 0) {
        M<UInt32>(self + 0x830) = uVar6 + 0xffff & 0xffff0000;
      }
    }
    else {
      M<UInt32>(self + 0x830) = 0x20000;
    }
  }
  else {
    if (uVar6 < 0x8000) {
      M<UInt32>(self + 0x830) = 0x8000;
    }
    else if (uVar6 < 0x20001) {
      if ((uVar5 & 0xffff) != 0) {
        M<UInt32>(self + 0x830) = uVar6 + 0xffff & 0xffff0000;
      }
    }
    else {
      M<UInt32>(self + 0x830) = 0x20000;
    }
    local_24 = M<SInt32>(self + 0x830) << 10;
    iVar2 = VCALL(*M<SInt32 *>(self + 0x74), 0x5dc)
                      (M<SInt32 *>(self + 0x74),0,self + 0x838,&local_24);
    if (iVar2 != 0) {
      return 0;
    }
    M<UInt32>(self + 0x830) = local_24 >> 10;
    if (0x18000 < (local_24 >> 10) - 0x8000) {
      return 0;
    }
    M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) | 2;
    /* real: the "IOAGPFlags" property cast to OSNumber; its unsigned64BitValue() (vtable +0xec, a 64-bit return whose
     * low word is in r4) bit 0 becomes the byte at this+0x85 */
    uVar3 = VCALL(*M<SInt32 *>(self + 0x74), 0x188)(M<SInt32 *>(self + 0x74),"IOAGPFlags");
    piVar4 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar3,GH_OSNumber_metaClass);
    if (piVar4 != (SInt32 *)0x0) {
      typedef unsigned long long (*Value64Fn)(void *);
      unsigned long long agpValue = (*reinterpret_cast<Value64Fn *>(*reinterpret_cast<UInt8 **>(piVar4) + 0xec))(piVar4);
      self[0x85] = (UInt8)(agpValue & 1);
    }
  }
  uVar3 = GH_IOMallocContiguous(GH_page_size * 2 + M<SInt32>(self + 0x830),GH_page_size,
                       self + 0x834);
  M<UInt32>(self + 0x83c) = uVar3;
  uVar5 = VCALL(M<SInt32>(self), 0x5b0)
                    (self,M<SInt32>(self + 0x834) + M<SInt32>(self + 0x830));
  M<UInt32>(self + 0x844) =
       uVar5 << 0x18 | (uVar5 & 0xff00) << 8 | uVar5 >> 8 & 0xff00 | uVar5 >> 0x18;
  uVar5 = VCALL(M<SInt32>(self), 0x5b0)
                    (self,M<SInt32>(self + 0x834) + M<SInt32>(self + 0x830) +
                             GH_page_size);
  M<UInt32>(self + 0x848) =
       uVar5 << 0x18 | (uVar5 & 0xff00) << 8 | uVar5 >> 8 & 0xff00 | uVar5 >> 0x18;
  iVar2 = M<SInt32>(self + 0x83c);
  if (iVar2 == 0) {
    return 0;
  }
  M<UInt32>(self + 0x7fc) =
       ((GH_page_size + M<UInt32>(self + 0x830)) - 1 & ~GH_page_size) +
       M<SInt32>(self + 0x7fc);
  if (M<UInt32>(self + 0x830) >> 2 != 0) {
    uVar5 = 0;
    while( true ) {
      iVar1 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      M<UInt32>(iVar1 + iVar2) = M<UInt32>(self + 0x844);
      if (M<UInt32>(self + 0x830) >> 2 <= uVar5) break;
      iVar2 = M<SInt32>(self + 0x83c);
    }
  }
  return 1;
}
