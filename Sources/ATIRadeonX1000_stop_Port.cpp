/*
 * ATIRadeonX1000_stop_Port.cpp
 *
 * ATIRadeonX1000::stop (real addr 0x26250, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFreeAligned(...) asm("_IOFreeAligned");

UInt32 HZMEM_Destroy(_HZDATA *hz);

/* real addr 0x26250 */
void ATIRadeonX1000::stop(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

  /* #153 (2026-10-08): stop()-path panic on unload - "IORegistryEntry::_RESERVEDIORegistryEntry10
   * called" via self+0x74's vtable+0x17c (the ATIFEDSInfo removeProperty call). Confirmed the
   * stock kext's own compiled code uses this exact same offset (0x17c) at the exact same relative
   * position - the offset itself is right, so the object pointer at self+0x74 is the suspect
   * (same defect class as the kOSBooleanTrue bug: a bad pointer landing on a real-but-wrong
   * vtable, not a bad offset). self+0x74 is read-only in every one of our own ported functions
   * (never assigned by our own code) and works fine during start() (the same field, same calls),
   * so logging its raw value and first vtable word right here to see if it's already garbage by
   * the time stop() runs, before touching it. */
  {
    void *field_0x74 = *(void **)(self + kIOATIR500Accelerator_pciDevice);
    UInt32 field_0x74_vtable = field_0x74 ? *(UInt32 *)field_0x74 : 0;
  }

  bool bVar1;
  int iVar2;
  unsigned int uVar3;
  int iVar4;
  UInt8 *memoryElement;
  UInt8 *displayRecord;
  int iVar7;
  
  if (M<int>(self + kIOATIR500Accelerator_gpuSensorTimer) != 0) {
    /* #155 FIX: real IOWorkLoop::removeEventSource(IOEventSource*) at vtable+0xe8 takes TWO args
     * (this, toRemove) - confirmed against the real XNU IOWorkLoop.cpp source (_maintRequest's
     * mRemoveEvent case) and against stock's own disassembly, which keeps the event-source pointer
     * live in r4 from an earlier load, not reloaded immediately before the bctrl. The mechanical
     * Ghidra port dropped this second argument (GhidraVFn is a bare variadic function pointer, so
     * the compiler only sets up registers for args actually written here) - the real callee read
     * whatever happened to be in r4, a valid-looking but wrong pointer, matching this issue's
     * "valid pointer, zeroed vtable" crash signature exactly. */
    VCALL(*M<int *>(self + kIOATIR500Accelerator_workLoop), 0xe8)(M<int *>(self + kIOATIR500Accelerator_workLoop), M<int *>(self + kIOATIR500Accelerator_gpuSensorTimer));
    VCALL(*M<int *>(self + kIOATIR500Accelerator_gpuSensorTimer), 0x18)(M<int *>(self + kIOATIR500Accelerator_gpuSensorTimer));
    M<UInt32>(self + kIOATIR500Accelerator_gpuSensorTimer) = 0;
  }
  if (M<int>(self + kIOATIR500Accelerator_swdsTimer) != 0) {
    VCALL(*M<int *>(self + kIOATIR500Accelerator_workLoop), 0xe8)(M<int *>(self + kIOATIR500Accelerator_workLoop), M<int *>(self + kIOATIR500Accelerator_swdsTimer));
    VCALL(*M<int *>(self + kIOATIR500Accelerator_swdsTimer), 0x18)(M<int *>(self + kIOATIR500Accelerator_swdsTimer));
    M<UInt32>(self + kIOATIR500Accelerator_swdsTimer) = 0;
  }
  iVar4 = 0;
  memoryElement = (UInt8 *)(self + kIOATIR500Accelerator_swdsBuffer0);
  VCALL(*M<int *>(self + kIOATIR500Accelerator_pciDevice), 0x17c)(M<int *>(self + kIOATIR500Accelerator_pciDevice),"ATIFEDSInfo");
  displayRecord = self;
  do {
    if ((M<int>(displayRecord + 0x9c0) != 0) && (M<int>(displayRecord + 0x9bc) != 0)) {
      ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->dealloc((GLKMemoryElement *)(memoryElement));
    }
    bVar1 = iVar4 != 1;
    memoryElement = memoryElement + 0x78;
    displayRecord = displayRecord + 0x78;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  if (M<int>(self + kIOATIR500Accelerator_swdsEntry0Memory) != 0) {
    ((IOATIR500Accelerator *)((UInt8 *)self))->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + kIOATIR500Accelerator_swdsEntry0)));
  }
  if ((M<int>(self + kIOATIR500Accelerator_scanout2PadElementPrev) != 0) && (M<int>(self + kIOATIR500Accelerator_scanout2PadElement) != 0)) {
    ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->dealloc((GLKMemoryElement *)((UInt8 *)(self + kIOATIR500Accelerator_scanout2PadElement)));
  }
  if ((M<int>(self + kIOATIR500Accelerator_scanout1PadElementPrev) != 0) && (M<int>(self + kIOATIR500Accelerator_scanout1PadElement) != 0)) {
    ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->dealloc((GLKMemoryElement *)((UInt8 *)(self + kIOATIR500Accelerator_scanout1PadElement)));
  }
  iVar4 = 0;
  memoryElement = (UInt8 *)(self + kIOATIR500Accelerator_scanout1Buffer);
  displayRecord = self;
  do {
    if ((M<int>(displayRecord + 0x130) != 0) && (M<int>(displayRecord + 300) != 0)) {
      ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->dealloc((GLKMemoryElement *)(memoryElement));
    }
    bVar1 = iVar4 != 1;
    memoryElement = memoryElement + 0x78;
    displayRecord = displayRecord + 0x78;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  VCALL(M<int>(self), 0x54c)(self,M<int>(self + kIOATIR500Accelerator_submitStamp) + -1);
  if (M<int>(self + kIOATIR500Accelerator_xdctEngineRunning) != 0) {
    this->stop_xdct_engine();
  }
  this->stop_promo4_engine();
  if (M<int>(self + kIOATIR500Accelerator_swdsPanel0Flag) != 0) {
    uVar3 = M<unsigned int>(self + kIOATIR500Accelerator_display1SurfaceAddress);
    iVar4 = M<int>(self + kIOATIR500Accelerator_mmioBase);
    M<unsigned int>(iVar4 + 0x6110) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    uVar3 = M<unsigned int>(self + kIOATIR500Accelerator_display1SurfaceAddressB);
    M<UInt32>(self + kIOATIR500Accelerator_display1SurfaceAddress) = 0;
    M<unsigned int>(iVar4 + 0x6120) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(self + kIOATIR500Accelerator_swdsPanel0Flag) = 0;
    M<UInt32>(self + kIOATIR500Accelerator_display1SurfaceAddressB) = 0;
  }
  if (M<int>(self + kIOATIR500Accelerator_swdsPanel1Flag) != 0) {
    uVar3 = M<unsigned int>(self + kIOATIR500Accelerator_display2SurfaceAddress);
    iVar4 = M<int>(self + kIOATIR500Accelerator_mmioBase);
    M<unsigned int>(iVar4 + 0x6910) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    uVar3 = M<unsigned int>(self + kIOATIR500Accelerator_display2SurfaceAddressB);
    M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddress) = 0;
    M<unsigned int>(iVar4 + 0x6920) =
         uVar3 << 0x18 | (uVar3 & 0xff00) << 8 | uVar3 >> 8 & 0xff00 | uVar3 >> 0x18;
    enforceInOrderExecutionIO();
    M<UInt32>(self + kIOATIR500Accelerator_swdsPanel1Flag) = 0;
    M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddressB) = 0;
  }
  HZMEM_Destroy((_HZDATA *)((UInt8 *)(self + kIOATIR500Accelerator_hzmem)));
  if (M<int>(self + kIOATIR500Accelerator_stampPageMemory) != 0) {
    M<UInt32>(self + kIOATIR500Accelerator_retiredStampOffset) = 0x15e4;
    M<UInt32>(self + kIOATIR500Accelerator_checkedStampOffset) = 0x15e0;
    M<int>(self + kIOATIR500Accelerator_stampPageBase) = M<int>(self + kIOATIR500Accelerator_mmioBase);
    M<UInt32>(M<int>(self + kIOATIR500Accelerator_mmioBase) + 0x770) = 0;
    enforceInOrderExecutionIO();
    VCALL(M<int>(self), 0x5a4)
              (self,M<UInt32>(self + kIOATIR500Accelerator_clientMemoryDescriptorType0),M<UInt32>(self + kIOATIR500Accelerator_stampPageGartOffset));
    VCALL(*M<int *>(self + kIOATIR500Accelerator_clientMemoryDescriptorType0), 0x18)(M<int *>(self + kIOATIR500Accelerator_clientMemoryDescriptorType0));
    GH_IOFreeAligned(M<UInt32>(self + kIOATIR500Accelerator_stampPageMemory),GH_page_size);
    M<UInt32>(self + kIOATIR500Accelerator_stampPageMemory) = 0;
  }
  if (M<int>(self + kIOATIR500Accelerator_mainRingMemory) != 0) {
    if (M<int>(self + kIOATIR500Accelerator_mainRingSize) != 0) {
      uVar3 = 0;
      do {
        VCALL(M<int>(self), 0x598)(self,uVar3 + M<int>(self + kIOATIR500Accelerator_mainRingGartOffset) + 0x1000000);
        uVar3 = uVar3 + GH_page_size;
      } while (uVar3 < M<unsigned int>(self + kIOATIR500Accelerator_mainRingSize));
    }
    VCALL(M<int>(self), 0x5a4)
              (self,M<UInt32>(self + kIOATIR500Accelerator_mainRingDescriptor),M<UInt32>(self + kIOATIR500Accelerator_mainRingGartOffset));
    GH_IOFreeAligned(M<UInt32>(self + kIOATIR500Accelerator_mainRingMemory),M<UInt32>(self + kIOATIR500Accelerator_mainRingSize));
    M<UInt32>(self + kIOATIR500Accelerator_mainRingMemory) = 0;
  }
  if (M<int>(self + kIOATIR500Accelerator_idctRingMemory) != 0) {
    iVar4 = 0;
    do {
      VCALL(M<int>(self), 0x598)(self,iVar4 + M<int>(self + kIOATIR500Accelerator_idctRingGartOffset) + 0x1000000);
      iVar4 = iVar4 + GH_page_size;
    } while (iVar4 < 0x2000);
    VCALL(M<int>(self), 0x5a4)
              (self,M<UInt32>(self + kIOATIR500Accelerator_idctRingDescriptor),M<UInt32>(self + kIOATIR500Accelerator_idctRingGartOffset));
    GH_IOFreeAligned(M<UInt32>(self + kIOATIR500Accelerator_idctRingMemory),0x2000);
    M<UInt32>(self + kIOATIR500Accelerator_idctRingMemory) = 0;
  }
  if (M<int>(self + kIOATIR500Accelerator_idctEngineActive) != 0) {
    if (M<int>(self + kIOATIR500Accelerator_unknown_0x8c8) == 0) {
      if (((UInt8)self[0x8cc] != 0) && (iVar4 = (UInt8)self[0x8cc] - 1, 0 < iVar4)) {
        iVar7 = 0;
        do {
          iVar2 = iVar4 - iVar7;
          iVar7 = iVar7 + 1;
          VCALL(M<int>(self), 0x5a4)
                    (self,M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBufferMemory),iVar2 << (GH_page_shift & 0x3f));
        } while (iVar4 != iVar7);
      }
    }
    else {
      iVar4 = (unsigned int)(UInt8)self[0x8cc] * 2;
      while (iVar7 = iVar4 + -2, 0 < iVar7) {
        VCALL(M<int>(self), 0x598)(self,iVar4 + -1 << (GH_page_shift & 0x3f));
        VCALL(M<int>(self), 0x5a4)
                  (self,M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBufferMemory),iVar7 << (GH_page_shift & 0x3f));
        iVar4 = iVar7;
      }
      VCALL(M<int>(self), 0x598)(self,1 << (GH_page_shift & 0x3f));
    }
    VCALL(M<int>(self), 0x5a4)
              (self,M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBufferMemory),M<UInt32>(self + kIOATIR500Accelerator_scratchCommandBufferGartOffset));
  }
  if (M<int *>(self + kIOATIR500Accelerator_gpuSensorFunction) != (int *)0x0) {
    VCALL(*M<int *>(self + kIOATIR500Accelerator_gpuSensorFunction), 0x18)(M<int *>(self + kIOATIR500Accelerator_gpuSensorFunction));
    M<UInt32>(self + kIOATIR500Accelerator_gpuSensorFunction) = 0;
  }
  this->shutdownPCIeGART();
  M<UInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) = 0;
  if (M<int>(self + kIOATIR500Accelerator_pcieGartTable) != 0) {
    GH_IOFreeAligned(M<int>(self + kIOATIR500Accelerator_pcieGartTable),M<UInt32>(self + kIOATIR500Accelerator_gartSizeKB));
    M<UInt32>(self + kIOATIR500Accelerator_pcieGartTable) = 0;
  }
  if (M<int *>(self + kIOATIR500Accelerator_registerMap) != (int *)0x0) {
    VCALL(*M<int *>(self + kIOATIR500Accelerator_registerMap), 0x18)(M<int *>(self + kIOATIR500Accelerator_registerMap));
    M<UInt32>(self + kIOATIR500Accelerator_registerMap) = 0;
    M<UInt32>(self + kIOATIR500Accelerator_mmioBase) = 0;
  }
  if (M<int>(self + kIOATIR500Accelerator_scratchTransferMemory) != 0) {
    VCALL(M<int>(self), 0x5ac)(self,self + kIOATIR500Accelerator_scratchTransfer);
    M<UInt32>(self + kIOATIR500Accelerator_scratchTransferDescriptor) = 0;
    GH_IOFreeAligned(M<UInt32>(self + kIOATIR500Accelerator_scratchTransferMemory),0x2000);
    M<UInt32>(self + kIOATIR500Accelerator_scratchTransferMemory) = 0;
  }
  if (M<int>(self + kIOATIR500Accelerator_registerDeviceMemory) != 0) {
    M<UInt32>(self + kIOATIR500Accelerator_registerDeviceMemory) = 0;
  }
  if (M<int *>(self + kIOATIR500Accelerator_vramPoolB) != (int *)0x0) {
    VCALL(*M<int *>(self + kIOATIR500Accelerator_vramPoolB), 0x18)(M<int *>(self + kIOATIR500Accelerator_vramPoolB));
    M<UInt32>(self + kIOATIR500Accelerator_vramPoolB) = 0;
  }
  /* #155 ROOT CAUSE FIX (2026-10-11): the mechanical port wrote this base-class chain-up as a
   * pointer-cast-and-arrow call. Under -fapple-kext (required for this build; it disables
   * devirtualization so kexts stay binary-patchable), `((Base*)obj)->virtualMethod()` ALWAYS
   * compiles to a real vtable dispatch, regardless of the cast - verified directly in this
   * build's own disassembly (reads self's live vtable pointer, adds the literal slot offset
   * 0x34c, matching stop()'s documented vtable slot, then calls through it). Since `self` is a
   * live ATIRadeonX1000 instance and ATIRadeonX1000 overrides that exact same slot, this called
   * ATIRadeonX1000::stop() itself - recursively, deterministically, every single time - instead
   * of reaching IOATIR500Accelerator::stop()'s base implementation. Confirmed via stock's own
   * disassembly that the real compiled driver uses a direct, fixed-address long-call here, not a
   * vtable read - meaning stock's real source used non-virtual scope-resolution call syntax,
   * which the mechanical Ghidra port didn't reproduce. Fixed by using the same explicit
   * Base::method() syntax already used correctly elsewhere in this file family (e.g.
   * ATIRadeonX1000::start()'s own `IOAccelerator::start(providerBytes)` chain call) - this is defined
   * by the C++ standard to bypass virtual dispatch entirely, independent of -fapple-kext. */
  this->IOATIR500Accelerator::stop((IOService *)(providerBytes));
  return;
}
