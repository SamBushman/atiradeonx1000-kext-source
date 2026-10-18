/*
 * ATIRadeonX1000_Start.cpp
 *
 * RESOLVED (ledger pass): ATIRadeonX1000::start (real addr 0x1f750, 3692 bytes): calls IOATIR500Accelerator::start, resets the hardware state,
 * reads the wide-blit properties, sets up the register aperture / PCIe GART / GART pages, HZMEM, the SWDS timer, the FED info,
 * the AccelCaps property and the GPU-sensor timer.
 * Mechanically ported from the Ghidra decompile of the shipped kext (Tools/port_fn.py); the resolved data references
 * (metaClass / page_shift / page_size / plane symbols) come from the kext relocation table.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 GH_IOFreeAligned(...) asm("_IOFreeAligned");
extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");
extern "C" UInt32 GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(...) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");
extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEPvm11IODirection(...) asm("__ZN18IOMemoryDescriptor11withAddressEPvm11IODirection");
extern "C" UInt32 GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(...) asm("__ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_E");
extern "C" UInt32 GH_ZN8OSObjectnwEm(...) asm("__ZN8OSObjectnwEm");
extern "C" UInt32 GH_ZN8OSSymbol17withCStringNoCopyEPKc(...) asm("__ZN8OSSymbol17withCStringNoCopyEPKc");
extern "C" UInt32 GH_ZN9IOServiceC1Ev(...) asm("__ZN9IOServiceC1Ev");
extern "C" UInt32 GH_memcpy(...) asm("_memcpy");
extern "C" UInt32 GH_memset(...) asm("_memset");

struct _HZDATA;
UInt32 HZMEM_Init(_HZDATA *hz, UInt32 param_2, UInt32 param_3, UInt32 param_4);
UInt32 HZMEM_Destroy(_HZDATA *hz);

/* real addr 0x1f750 */
bool ATIRadeonX1000::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt32 savedStrobeWord;
  UInt32 chipWord;
  UInt8 *chipID;
  UInt8 *pAVar4;
  SInt32 iVar5;
  SInt32 swdsTimer;
  SInt32 hzmemResult;
  SInt32 flushLength;
  SInt32 pageIndex;
  SInt32 mapped;
  SInt32 gartStartResult;
  SInt32 registers;
  SInt32 poolReady;
  SInt32 index;
  SInt32 baseStarted;
  UInt32 uVar6;
  UInt32 flag;
  UInt32 property;
  SInt32 *piVar7;
  SInt32 *period;
  SInt32 *booleanObject;
  UInt8 *memoryPool;
  UInt32 uVar8;
  SInt32 iVar9;
  SInt32 *piVar10;
  UInt32 uVar11;
  UInt32 cacheFlushStart;
  UInt32 uVar13;
  code *pcVar14;
  SInt32 *piVar15;
  SInt32 iVar16;
  SInt32 gartOffset;
  UInt8 *local_34 [6];
  SInt32 *sensorArray;
  SInt32 bufferMemory;
  SInt32 bufferDescriptor;
  SInt32 mapResult;
  SInt32 commandBufferAllocated;
  SInt32 hardwareReady;
  SInt32 attached;
  SInt32 gpuSensorTimer;
  SInt32 addResult;
  
  gartOffset = 0;
  baseStarted = IOATIR500Accelerator::start(provider);
  if (baseStarted == 0) {
    return 0;
  }
  M<UInt32>(self + kIOATIR500Accelerator_lastRetiredStamp) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_lastConsumedIDCTStamp) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_ringPointerBase) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_ringWritePointerOffset) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_numPipes) = 1;
  M<UInt32>(self + kIOATIR500Accelerator_retiredStampCounter) = 1;
  M<UInt32>(self + kIOATIR500Accelerator_idctSubmitBaseCounter) = 1;
  M<UInt32>(self + kIOATIR500Accelerator_ringIndex) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_mainRingMemory) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_idctPointerBase) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_idctPointerOffset) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_idctRingMemory) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_registerMap) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_mmioBase) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_stampPageMemory) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x8fc) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramSizeProgrammed) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_vramPreparedMask) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_idctEngineActive) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanoutOverlapsVram) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_display1Enabled) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_display2Enabled) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_transferMappedFlag) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0x88c) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_xdctEngineRunning) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartReserveSize) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartTableVramOffset) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_gartTableCpuAddress) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_chipID) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_chipRev) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_unknown_0xc58) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_pcieGartTable) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout2PadElement) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout2PadElementPrev) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout2PadElementOffset) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout2PadElementAlignMask) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1PadElement) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1PadElementPrev) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1PadElementOffset) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_scanout1PadElementAlignMask) = 0;
  ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->init_pool(0);
  M<UInt32>(self + kIOATIR500Accelerator_vramPoolB) = 0;
  index = 0;
  pAVar4 = self;
  do {
    bVar1 = index != 1;
    M<UInt32>(pAVar4 + 0x940) = 0;
    M<UInt32>(pAVar4 + 0x944) = 0;
    M<UInt32>(pAVar4 + 0x948) = 0;
    M<UInt32>(pAVar4 + 0x94c) = 0;
    M<UInt32>(pAVar4 + 0x950) = 0;
    M<UInt32>(pAVar4 + 0x954) = 0;
    M<UInt32>(pAVar4 + 0x958) = 0;
    M<UInt32>(pAVar4 + 0x95c) = 0;
    index = index + 1;
    pAVar4 = pAVar4 + 0x20;
  } while (bVar1);
  M<UInt32>(self + kIOATIR500Accelerator_tearingWideBlit) = 0;
  M<UInt32>(self + kIOATIR500Accelerator_wideBlitSupport) = 0;
  property = VCALL(M<SInt32>(self), 0x188)(self,"ATIEnableWideBlitSupport");
  uVar11 = GH_OSBoolean_metaClass;
  booleanObject = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(property,GH_OSBoolean_metaClass);
  if (booleanObject != (SInt32 *)0x0) {
    flag = VCALL(*booleanObject, 0xd8)(booleanObject);
    M<UInt32>(self + kIOATIR500Accelerator_wideBlitSupport) = flag;
  }
  property = VCALL(M<SInt32>(self), 0x188)(self,"ATIUseTearingWideBlit");
  booleanObject = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(property,uVar11);
  if (booleanObject != (SInt32 *)0x0) {
    flag = VCALL(*booleanObject, 0xd8)(booleanObject);
    M<UInt32>(self + kIOATIR500Accelerator_tearingWideBlit) = flag;
  }
  if (M<SInt32>(self + kIOATIR500Accelerator_wideBlitSupport) == 0) {
    M<UInt32>(self + kIOATIR500Accelerator_tearingWideBlit) = 0;
    M<UInt16>(self + kIOATIR500Accelerator_maxSurfaceWidth) = 0x1000;
  }
  else {
    M<UInt16>(self + kIOATIR500Accelerator_maxSurfaceHeight) = 0x1000;
    M<UInt16>(self + kIOATIR500Accelerator_maxSurfaceWidth) = 0x1000;
  }
  /* #85: the decompile's `operator new(0x14); if (p) ATIR500Memory::ATIR500Memory(p)` pair is exactly what `new ATIR500Memory()` compiles to; the
   * mechanical port wrote both, which allocated twice and leaked the first object on every start(). */
  memoryPool = (UInt8 *)new ATIR500Memory();
  M<UInt8 *>(self + kIOATIR500Accelerator_vramPoolB) = memoryPool;
  if (memoryPool != (UInt8 *)0x0) {
    poolReady = ((ATIR500Memory *)(memoryPool))->init_pool(0);
    if (poolReady == 0) {
      VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_vramPoolB), 0x18)(M<SInt32 *>(self + kIOATIR500Accelerator_vramPoolB));
      M<UInt32>(self + kIOATIR500Accelerator_vramPoolB) = 0;
    }
    else {
      iVar5 = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x578)(M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),0x18);
      M<SInt32>(self + kIOATIR500Accelerator_pciBar0Config) = iVar5;
      if (iVar5 != 0) {
        piVar7 = (SInt32 *)VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x57c)
                                  (M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),0x18,0);
        M<SInt32 *>(self + kIOATIR500Accelerator_registerMap) = piVar7;
        if (piVar7 != (SInt32 *)0x0) {
          registers = VCALL(*piVar7, 0xd0)(piVar7);
          M<SInt32>(self + kIOATIR500Accelerator_mmioBase) = registers;
          if (registers != 0) {
            /* #147/#155/#156 root cause (corrected 2026-10-08 - the prior version of this comment,
             * and #147's own fix, both blamed "MMIO timing fragility"/hardware drift; that was
             * wrong, and was itself an instance of the same bias the project's standing methodology
             * exists to rule out - blaming something other than this port's own code. Stock,
             * hot-swapped the identical way as the rebuilt kext (not boot/reset-adjacent at all),
             * reliably reads the correct chip-ID AND chip-rev here every time - proving the register
             * itself was never the problem.
             *
             * The real bug: self+0x860[8..0xb] is a write-strobe/read-back hardware register. Real
             * sequence (confirmed via stock's own disassembly, ATIRadeonX1000::start ~0x1fa48-0x1fa7c,
             * using lwbrx/stwbrx - byte-reversed load/store, since this MMIO block is little-endian):
             * (1) read the original word at +8, (2) write a MODIFIED value to +8 (forces bit 0x34,
             * masks 0xff40) to trigger the hardware latch, (3) READ the now-latched chip-ID/chip-rev
             * word back from +0xc while still in the strobed state, (4) THEN restore the original
             * value to +8. This port had BOTH reads (chip-ID originally via CONCAT11(registers+0xd,
             * registers+0xc), chip-rev via registers+0xf) happening AFTER step 4's restore instead of between
             * steps 2 and 4 - reading the register back in its already-restored, un-strobed state.
             * That's why chip-ID drifted to garbage (#147) and chip-rev came back 0 instead of 0xc
             * (#156) on a hot-swapped instance - not hardware timing, a dropped read-ordering step in
             * the mechanical port. #147's PCI-config-space fix (vtable+0x53c = IOPCIDevice::
             * configRead16) got a correct VALUE for chip-ID but was a workaround for this same bug,
             * not the real fix - reverted here in favor of the original MMIO mechanism, now correctly
             * positioned between the strobe write and the restore write, matching stock exactly.
             * Live-verified (2026-10-08): self+0xc50=0x7240, self+0xc54=0xc, ioreg AccelCaps=3 -
             * identical outcome to #147's fix, via the real mechanism instead of a substitute. */
            savedStrobeWord = loadWordByteReversed(&M<UInt8>(registers + 8));
            storeWordByteReversed(&M<UInt8>(registers + 8), savedStrobeWord & 0xffffff40 | 0x34);
            chipWord = loadWordByteReversed(&M<UInt8>(registers + 0xc));
            storeWordByteReversed(&M<UInt8>(registers + 8), savedStrobeWord);
            M<UInt32>(self + kIOATIR500Accelerator_chipRev) = chipWord >> 24 & 0xf;
            chipID = (UInt8 *)(chipWord & 0xffff);
            M<UInt8 *>(self + kIOATIR500Accelerator_chipID) = chipID;
            if (chipID == (UInt8 *)0x7157) goto LAB_0001fafc;
            if (chipID < (UInt8 *)0x7158) {
              if (chipID < (UInt8 *)0x7147) {
                if ((chipID < (UInt8 *)0x7144) && (chipID != (UInt8 *)0x7140)) {
                  if (chipID < (UInt8 *)0x7141) {
                    if (chipID + -0x7100 < (UInt8 *)0x10) {
                      uVar13 = 0;
                      M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) | 0x110000;
                      this->setupR520Pipes();
                      goto LAB_0001fc04;
                    }
                  }
                  else if (chipID == (UInt8 *)0x7142) goto LAB_0001fafc;
                  goto LAB_0001fbc8;
                }
              }
              else if (chipID != (UInt8 *)0x714e) {
                if (chipID < (UInt8 *)0x714f) {
                  if (chipID + -29000 < (UInt8 *)0x3) goto LAB_0001fafc;
                }
                else if ((chipID == (UInt8 *)0x7150) ||
                        (((UInt8 *)0x714f < chipID && (chipID + -0x7152 < (UInt8 *)0x2))))
                goto LAB_0001fafc;
                goto LAB_0001fbc8;
              }
LAB_0001fafc:
              uVar13 = 2;
              M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) | 0x410000;
              this->setupR520Pipes();
            }
            else {
              if (chipID != (UInt8 *)0x71d2) {
                if ((UInt8 *)0x71d2 < chipID) {
                  if (chipID < (UInt8 *)0x7250) {
                    if ((UInt8 *)0x723f < chipID) {
LAB_0001fbec:
                      uVar13 = 3;
                      M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) | 0x810000;
                      this->setupR520Pipes();
                      goto LAB_0001fc04;
                    }
                    if (chipID == (UInt8 *)0x71de) goto LAB_0001fbd0;
                  }
                  else if ((chipID == (UInt8 *)0x7260) ||
                          (((UInt8 *)0x725f < chipID && (chipID + -0x7263 < (UInt8 *)0xd))))
                  goto LAB_0001fbec;
LAB_0001fbc8:
                  uVar13 = 0;
                  goto LAB_0001fc04;
                }
                if (chipID != (UInt8 *)0x71c2) {
                  if (chipID < (UInt8 *)0x71c3) {
                    if (chipID == (UInt8 *)0x715e) goto LAB_0001fafc;
                    if (chipID != (UInt8 *)0x71c0) goto LAB_0001fbc8;
                  }
                  else if ((chipID < (UInt8 *)0x71c4) ||
                          (((UInt8 *)0x71c6 < chipID && (chipID != (UInt8 *)0x71ce))))
                  goto LAB_0001fbc8;
                }
              }
LAB_0001fbd0:
              uVar13 = 1;
              M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) = M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) | 0x210000;
              this->setupR520Pipes();
            }
LAB_0001fc04:
            self[0x990] = 0x6;
            gartStartResult = this->startupPCIeGART();
            if (gartStartResult != -1) {
              self[0x8cd] = 0x0;
              self[0x8cc] = 0x0;
              M<UInt32>(self + kIOATIR500Accelerator_checkedStampOffset) = 0x15e0;
              M<UInt32>(self + kIOATIR500Accelerator_unknown_0x8c8) = 0;
              M<UInt32>(self + kIOATIR500Accelerator_stampPageBase) = M<UInt32>(self + kIOATIR500Accelerator_mmioBase);
              M<UInt32>(self + kIOATIR500Accelerator_retiredStampOffset) = 0x15e4;
              mapped = VCALL(M<SInt32>(self), 0x590)
                                (self,M<UInt32>(self + kIOATIR500Accelerator_scratchBufferDescriptor),self + kIOATIR500Accelerator_scratchBufferGartOffset,0,0x1000);
              if (mapped != 0) {
                if (M<SInt32>(self + kIOATIR500Accelerator_unknown_0x8c8) == 0) {
                  if ((self[0x8cc] != 0x0) && (1 < (UInt8)self[0x8cc])) {
                    pageIndex = 1;
                    do {
                      gartOffset = pageIndex << (GH_page_shift & 0x3f);
                      iVar9 = VCALL(M<SInt32>(self), 0x590)
                                        (self,M<UInt32>(self + kIOATIR500Accelerator_scratchBufferDescriptor),&gartOffset,gartOffset,
                                         gartOffset + 0x1000);
                      if (iVar9 == 0) {
                        if (pageIndex < (SInt32)(UInt32)(UInt8)self[0x8cc]) {
                          if (-1 < pageIndex + -1) {
                            iVar9 = 0;
                            do {
                              iVar16 = (pageIndex + -1) - iVar9;
                              iVar9 = iVar9 + 1;
                              VCALL(M<SInt32>(self), 0x5a4)
                                        (self,M<UInt32>(self + kIOATIR500Accelerator_scratchBufferDescriptor),
                                         iVar16 << (GH_page_shift & 0x3f));
                            } while (pageIndex != iVar9);
                          }
                          goto LAB_0001f9a0;
                        }
                        break;
                      }
                      pageIndex = pageIndex + 1;
                    } while (pageIndex < (SInt32)(UInt32)(UInt8)self[0x8cc]);
                  }
                }
                else {
                  VCALL(M<SInt32>(self), 0x594)(self,1 << (GH_page_shift & 0x3f));
                  if (1 < (UInt8)self[0x8cc]) {
                    pageIndex = 2;
                    do {
                      gartOffset = pageIndex << (GH_page_shift & 0x3f);
                      iVar9 = VCALL(M<SInt32>(self), 0x590)
                                        (self,M<UInt32>(self + kIOATIR500Accelerator_scratchBufferDescriptor),&gartOffset,gartOffset,
                                         gartOffset + 0x1000);
                      if (iVar9 == 0) {
                        if (pageIndex < (SInt32)((UInt32)(UInt8)self[0x8cc] << 1)) goto LAB_0001fd88;
                        break;
                      }
                      iVar9 = pageIndex + 1;
                      pageIndex = pageIndex + 2;
                      VCALL(M<SInt32>(self), 0x594)(self,iVar9 << (GH_page_shift & 0x3f));
                    } while (pageIndex < (SInt32)((UInt32)(UInt8)self[0x8cc] << 1));
                  }
                }
                M<UInt32>(self + kIOATIR500Accelerator_idctEngineActive) = 1;
                if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80) != 0) {
                  uVar11 = (UInt32)(UInt8)self[0x84];
                  iVar9 = 0;
                  cacheFlushStart = -uVar11 & M<SInt32>(self + kIOATIR500Accelerator_scratchHeader) + 0x20U;
                  flushLength = ((M<SInt32>(self + kIOATIR500Accelerator_scratchHeader) + 0x20U & uVar11 - 1) + 0x20) - uVar11;
                  if (0 < flushLength) {
                    iVar9 = 0;
                    do {
                      dataCacheBlockStore(cacheFlushStart + iVar9);
                      iVar9 = iVar9 + uVar11;
                    } while (iVar9 < flushLength);
                  }
                  ppcSync();
                  instructionSynchronize();
                  dataCacheBlockFlush(cacheFlushStart + iVar9);
                  ppcSync();
                  instructionSynchronize();
                  instructionSynchronize();
                }
                if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80000) == 0) {
                  M<UInt32>(self + kIOATIR500Accelerator_ringWritePointerOffset) = 0;
                  M<UInt32>(self + kIOATIR500Accelerator_ringPointerBase) = M<UInt32>(self + kIOATIR500Accelerator_scratchHeader);
                }
                else {
                  M<UInt32>(self + kIOATIR500Accelerator_ringWritePointerOffset) = 0x710;
                  M<UInt32>(self + kIOATIR500Accelerator_ringPointerBase) = M<UInt32>(self + kIOATIR500Accelerator_mmioBase);
                }
                M<UInt32>(self + kIOATIR500Accelerator_mainRingSize) = 0x2000;
                bufferMemory = GH_IOMallocAligned(0x2000,GH_page_size);
                M<SInt32>(self + kIOATIR500Accelerator_mainRingMemory) = bufferMemory;
                if (bufferMemory != 0) {
                  bufferDescriptor = GH_ZN18IOMemoryDescriptor11withAddressEPvm11IODirection(bufferMemory,M<UInt32>(self + kIOATIR500Accelerator_mainRingSize),3);
                  M<SInt32>(self + kIOATIR500Accelerator_mainRingDescriptor) = bufferDescriptor;
                  if (bufferDescriptor != 0) {
                    mapResult = VCALL(M<SInt32>(self), 0x5a0)(self,bufferDescriptor,self + kIOATIR500Accelerator_mainRingGartOffset);
                    if (mapResult != 0) {
                      iVar9 = M<SInt32>(self + kIOATIR500Accelerator_mainRingMemory);
                      index = 0;
                      iVar16 = 0x800;
                      do {
                        M<UInt32>(iVar9 + index * 4) = 0x80000000;
                        index = index + 1;
                        iVar16 = iVar16 + -1;
                      } while (iVar16 != 0);
                      if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80000) == 0) {
                        M<UInt32>(self + kIOATIR500Accelerator_idctPointerOffset) = 0;
                        M<SInt32>(self + kIOATIR500Accelerator_idctPointerBase) = M<SInt32>(self + kIOATIR500Accelerator_scratchHeader) + 4;
                      }
                      else {
                        M<UInt32>(self + kIOATIR500Accelerator_idctPointerOffset) = 0x1f9c;
                        M<UInt32>(self + kIOATIR500Accelerator_idctPointerBase) = M<UInt32>(self + kIOATIR500Accelerator_mmioBase);
                      }
                      bufferMemory = GH_IOMallocAligned(0x2000,GH_page_size);
                      M<SInt32>(self + kIOATIR500Accelerator_idctRingMemory) = bufferMemory;
                      if (bufferMemory != 0) {
                        bufferDescriptor = GH_ZN18IOMemoryDescriptor11withAddressEPvm11IODirection(bufferMemory,0x2000,3);
                        M<SInt32>(self + kIOATIR500Accelerator_idctRingDescriptor) = bufferDescriptor;
                        if (bufferDescriptor != 0) {
                          mapResult = VCALL(M<SInt32>(self), 0x5a0)(self,bufferDescriptor,self + kIOATIR500Accelerator_idctRingGartOffset);
                          if (mapResult != 0) {
                            iVar9 = M<SInt32>(self + kIOATIR500Accelerator_idctRingMemory);
                            index = 0;
                            iVar16 = 0x800;
                            do {
                              M<UInt32>(iVar9 + index * 4) = 0x80000000;
                              index = index + 1;
                              iVar16 = iVar16 + -1;
                            } while (iVar16 != 0);
                            M<UInt32>(self + kIOATIR500Accelerator_gbTileConfig) = 0x11;
                            if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x80000) == 0) {
                              bufferMemory = GH_IOMallocAligned(GH_page_size,GH_page_size);
                              M<SInt32>(self + kIOATIR500Accelerator_stampPageMemory) = bufferMemory;
                              if (bufferMemory != 0) {
                                bufferDescriptor = GH_ZN18IOMemoryDescriptor11withAddressEPvm11IODirection(bufferMemory,GH_page_size,3);
                                M<SInt32>(self + kIOATIR500Accelerator_clientMemoryDescriptorType0) = bufferDescriptor;
                                if (bufferDescriptor == 0) {
                                  GH_IOFreeAligned(M<UInt32>(self + kIOATIR500Accelerator_stampPageMemory),GH_page_size);
                                  M<UInt32>(self + kIOATIR500Accelerator_stampPageMemory) = 0;
                                }
                                else {
                                  mapResult = VCALL(M<SInt32>(self), 0x5a0)
                                                    (self,bufferDescriptor,self + kIOATIR500Accelerator_stampPageGartOffset);
                                  if (mapResult == 0) {
                                    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_clientMemoryDescriptorType0), 0x18)(M<SInt32 *>(self + kIOATIR500Accelerator_clientMemoryDescriptorType0));
                                    GH_IOFreeAligned(M<UInt32>(self + kIOATIR500Accelerator_stampPageMemory),GH_page_size);
                                    M<UInt32>(self + kIOATIR500Accelerator_stampPageMemory) = 0;
                                  }
                                  else {
                                    M<UInt32>(self + kIOATIR500Accelerator_checkedStampOffset) = 0;
                                    M<UInt32>(self + kIOATIR500Accelerator_retiredStampOffset) = 4;
                                    M<UInt32>(self + kIOATIR500Accelerator_stampPageBase) = M<UInt32>(self + kIOATIR500Accelerator_stampPageMemory);
                                  }
                                }
                              }
                            }
                            VCALL(M<SInt32>(self), 0x164)
                                      (self,"IOGLBundleName","ATIRadeonX1000GLDriver");
                            M<UInt32>(self + kIOATIR500Accelerator_unknown_0x980) = 0x7b8;
                            M<UInt32>(self + kIOATIR500Accelerator_unknown_0x984) = 0x3ff;
                            M<UInt32>(self + kIOATIR500Accelerator_unknown_0x988) = 0;
                            hzmemResult = HZMEM_Init((_HZDATA *)(self + kIOATIR500Accelerator_hzmem),uVar13,
                                               M<UInt32>(self + kIOATIR500Accelerator_numPipes),M<UInt32>(self + kIOATIR500Accelerator_numZPipes));
                            if (hzmemResult == 0) {
                              GH_memset(self + kIOATIR500Accelerator_swdsState_0xb2c,0,0x40);
                              self[0x9b0] = 0x0;
                              M<UInt32>(self + kIOATIR500Accelerator_display1SurfaceAddressSeen) = 0;
                              M<UInt32>(self + kIOATIR500Accelerator_display2SurfaceAddressSeen) = 0;
                              M<UInt32>(self + kIOATIR500Accelerator_unknown_0xacc) = 0;
                              M<UInt32>(self + kIOATIR500Accelerator_swdsPeriodMs) = 10;
                              M<UInt32>(self + kIOATIR500Accelerator_unknown_0xad0) = 0;
                              M<UInt32>(self + kIOATIR500Accelerator_unknown_0xaac) = 0;
                              M<UInt32>(self + kIOATIR500Accelerator_unknown_0xab0) = 0;
                              M<UInt32>(self + kIOATIR500Accelerator_unknown_0xab4) = 0;
                              M<UInt32>(self + kIOATIR500Accelerator_unknown_0xab8) = 0;
                              M<UInt32>(self + kIOATIR500Accelerator_swdsScratchElement) = 0;
                              M<UInt32>(self + kIOATIR500Accelerator_unknown_0xac0) = 0;
                              M<UInt32>(self + kIOATIR500Accelerator_unknown_0xac4) = 0;
                              M<UInt32>(self + kIOATIR500Accelerator_unknown_0xac8) = 0;
                              GH_memset(self + kIOATIR500Accelerator_swdsBuffer0,0,0xf0);
                              GH_memset(self + kIOATIR500Accelerator_swdsEntry1,0,0x30);
                              swdsTimer = GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(self,SWDSFunc);
                              M<SInt32>(self + kIOATIR500Accelerator_swdsTimer) = swdsTimer;
                              if (swdsTimer != 0) {
                                VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_workLoop), 0xe4)
                                          (M<SInt32 *>(self + kIOATIR500Accelerator_workLoop),swdsTimer);
                                M<UInt32>(self + kIOATIR500Accelerator_swdsEntry0RectWordIndex) = 0;
                                M<UInt32>(self + kIOATIR500Accelerator_swdsEntryIndex) = 0;
                                M<UInt32>(self + kIOATIR500Accelerator_swdsEntry0) = 0;
                                M<UInt32>(self + kIOATIR500Accelerator_swdsEntry0GartOffset) = 0;
                                M<UInt16>(self + kIOATIR500Accelerator_swdsEntry0Field0c) = 1;
                                M<UInt32>(self + kIOATIR500Accelerator_swdsEntry0Memory) = 0;
                                M<UInt16>(self + kIOATIR500Accelerator_swdsEntry0Field0e) = 0;
                                M<UInt32>(self + kIOATIR500Accelerator_swdsEntry0Stamp) = 0;
                                M<UInt32>(self + kIOATIR500Accelerator_swdsEntry0Header) = 0;
                                commandBufferAllocated = IOATIR500Accelerator::allocCommandBuffer((VendorCommandBuffer *)(self + kIOATIR500Accelerator_swdsEntry0),0x1000);
                                if ((commandBufferAllocated != 0) &&
                                   (mapResult = VCALL(M<SInt32>(self), 0x5a0)
                                                      (self,M<UInt32>(self + kIOATIR500Accelerator_swdsEntry0Memory),
                                                       self + kIOATIR500Accelerator_swdsEntry0GartOffset), mapResult != 0)) {
                                  M<UInt32>(self + kIOATIR500Accelerator_unknown_0xb58) = 7;
                                  M<UInt32>(self + kIOATIR500Accelerator_unknown_0xb54) = 7;
                                  local_34[0] = self + kIOATIR500Accelerator_swdsState_0xb2c;
                                  VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice), 0x170)
                                            (M<SInt32 *>(self + kIOATIR500Accelerator_pciDevice),"ATIFEDSInfo",local_34,4);
                                  if ((M<SInt32>(self + kIOATIR500Accelerator_displayCount) == 0) ||
                                     ((M<SInt32>(self + kIOATIR500Accelerator_vramApertureBase) == 0 ||
                                      (hardwareReady = this->initialize_hardware(), hardwareReady != 0)))) {
                                    pcVar14 = M<code *>(M<SInt32>(self) + 0x16c);
                                    uVar6 = VCALL(M<SInt32>(self), 0x5d0)(self);
                                    (*pcVar14)(self,"AccelCaps",0,uVar6,0x20);
                                    VCALL(M<SInt32>(self), 0x340)(self,0);
                                    M<UInt32>(self + kIOATIR500Accelerator_gpuSensorProvider) = 0;
                                    uVar6 = VCALL(M<SInt32>(self), 0x188)
                                                      (self,"sensor-properties");
                                    sensorArray = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar6,GH_OSArray_metaClass);
                                    if (sensorArray != (SInt32 *)0x0) {
                                      piVar15 = (SInt32 *)0x0;
                                      index = 0;
                                      while( true ) {
                                        uVar6 = VCALL(*sensorArray, 0x138)(sensorArray,index);
                                        iVar9 = GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar6,GH_OSDictionary_metaClass);
                                        if (iVar9 == 0) break;
                                        piVar10 = (SInt32 *)GH_ZN8OSObjectnwEm(0x50);
                                        piVar15 = piVar10;
                                        if (piVar10 != (SInt32 *)0x0) {
                                          GH_ZN9IOServiceC1Ev(piVar10);
                                          iVar9 = VCALL(*piVar10, 0x150)(piVar10,iVar9);
                                          if (iVar9 == 0) {
                                            piVar15 = (SInt32 *)0x0;
                                            VCALL(*piVar10, 0x4c)(piVar10);
                                          }
                                        }
                                        index = index + 1;
                                      }
                                      if ((piVar15 != (SInt32 *)0x0) &&
                                         (attached = VCALL(*piVar15, 0x1d8)
                                                            (piVar15,self,GH_gIOServicePlane),
                                         attached != 0)) {
                                        M<SInt32 *>(self + kIOATIR500Accelerator_gpuSensorProvider) = piVar15;
                                        VCALL(*piVar15, 0x340)(piVar15,0);
                                      }
                                    }
                                    if (M<SInt32>(self + kIOATIR500Accelerator_gpuSensorProvider) != 0) {
                                      M<UInt32>(self + kIOATIR500Accelerator_swdsPeriodMsA) = 0;
                                      M<UInt32>(self + kIOATIR500Accelerator_gpuSensorPeriodMs) = 0;
                                      gpuSensorTimer = GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(self,GPUSensorFunc);
                                      M<SInt32>(self + kIOATIR500Accelerator_gpuSensorTimer) = gpuSensorTimer;
                                      if (gpuSensorTimer != 0) {
                                        addResult = VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_workLoop), 0xe4)
                                                          (M<SInt32 *>(self + kIOATIR500Accelerator_workLoop),gpuSensorTimer);
                                        if (addResult == 0) {
                                          period = (SInt32 *)this->getPeriodValue("polling-period");
                                          if (period != (SInt32 *)0x0) {
                                            M<UInt32>(self + kIOATIR500Accelerator_swdsPeriodMsA) =
                                                 *period * 1000 + (UInt32)period[1] / 1000000;
                                          }
                                          period = (SInt32 *)this->getPeriodValue("sample-period");
                                          if (period != (SInt32 *)0x0) {
                                            M<UInt32>(self + kIOATIR500Accelerator_gpuSensorPeriodMs) =
                                                 *period * 1000 + (UInt32)period[1] / 1000000;
                                          }
                                          this->enable_GPUSensor();
                                        }
                                        else {
                                          VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_gpuSensorTimer), 0x18)(M<SInt32 *>(self + kIOATIR500Accelerator_gpuSensorTimer));
                                          M<UInt32>(self + kIOATIR500Accelerator_gpuSensorTimer) = 0;
                                        }
                                      }
                                    }
                                    uVar6 = 1;
                                    goto LAB_0001f9c0;
                                  }
                                }
                              }
                            }
                            goto LAB_0001f9a0;
                          }
                          VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_idctRingDescriptor), 0x18)(M<SInt32 *>(self + kIOATIR500Accelerator_idctRingDescriptor));
                        }
                        GH_IOFreeAligned(M<UInt32>(self + kIOATIR500Accelerator_idctRingMemory),0x2000);
                        M<UInt32>(self + kIOATIR500Accelerator_idctRingMemory) = 0;
                      }
                      goto LAB_0001f9a0;
                    }
                    VCALL(*M<SInt32 *>(self + kIOATIR500Accelerator_mainRingDescriptor), 0x18)(M<SInt32 *>(self + kIOATIR500Accelerator_mainRingDescriptor));
                  }
                  GH_IOFreeAligned(M<UInt32>(self + kIOATIR500Accelerator_mainRingMemory),M<UInt32>(self + kIOATIR500Accelerator_mainRingSize));
                  M<UInt32>(self + kIOATIR500Accelerator_mainRingMemory) = 0;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_0001f9a0:
  uVar6 = 0;
  VCALL(M<SInt32>(self), 0x34c)(self,provider);
LAB_0001f9c0:
  uVar8 = GH_ZN8OSSymbol17withCStringNoCopyEPKc("getSensorValue");
  M<UInt32>(self + kIOATIR500Accelerator_gpuSensorFunction) = uVar8;
  return uVar6;
LAB_0001fd88:
  while (iVar9 = pageIndex + -2, -1 < iVar9) {
    VCALL(M<SInt32>(self), 0x598)(self,pageIndex + -1 << (GH_page_shift & 0x3f));
    VCALL(M<SInt32>(self), 0x5a4)
              (self,M<UInt32>(self + kIOATIR500Accelerator_scratchBufferDescriptor),iVar9 << (GH_page_shift & 0x3f));
    pageIndex = iVar9;
  }
  goto LAB_0001f9a0;
}

