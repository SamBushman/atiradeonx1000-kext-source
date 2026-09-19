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
bool ATIRadeonX1000::start(IOService *param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt8 bVar2;
  UInt8 *puVar3;
  UInt8 *pAVar4;
  SInt32 iVar5;
  UInt32 uVar6;
  SInt32 *piVar7;
  UInt8 *this_00;
  UInt32 uVar8;
  SInt32 iVar9;
  SInt32 *piVar10;
  UInt32 uVar11;
  UInt32 uVar12;
  UInt32 uVar13;
  code *pcVar14;
  SInt32 *piVar15;
  SInt32 iVar16;
  SInt32 local_38;
  UInt8 *local_34 [6];
  
  local_38 = 0;
  iVar5 = IOATIR500Accelerator::start(param_1);
  if (iVar5 == 0) {
    return 0;
  }
  M<UInt32>(self + 0x858) = 0;
  M<UInt32>(self + 0x85c) = 0;
  M<UInt32>(self + 0x90c) = 0;
  M<UInt32>(self + 0x910) = 0;
  M<UInt32>(self + 0xb98) = 1;
  M<UInt32>(self + 0x850) = 1;
  M<UInt32>(self + 0x854) = 1;
  M<UInt32>(self + 0x914) = 0;
  M<UInt32>(self + 0x900) = 0;
  M<UInt32>(self + 0x928) = 0;
  M<UInt32>(self + 0x92c) = 0;
  M<UInt32>(self + 0x930) = 0;
  M<UInt32>(self + 0x91c) = 0;
  M<UInt32>(self + 0x934) = 0;
  M<UInt32>(self + 0x860) = 0;
  M<UInt32>(self + 0x8d0) = 0;
  M<UInt32>(self + 0x8fc) = 0;
  M<UInt32>(self + 0x8a4) = 0;
  M<UInt32>(self + 0x890) = 0;
  M<UInt32>(self + 0x938) = 0;
  M<UInt32>(self + 0x894) = 0;
  M<UInt32>(self + 0x898) = 0;
  M<UInt32>(self + 0x89c) = 0;
  M<UInt32>(self + 0x8a0) = 0;
  M<UInt32>(self + 0x88c) = 0;
  M<UInt32>(self + 0x8bc) = 0;
  M<UInt32>(self + 0xbac) = 0;
  M<UInt32>(self + 0xbb0) = 0;
  M<UInt32>(self + 3000) = 0;
  M<UInt32>(self + 0xc50) = 0;
  M<UInt32>(self + 0xc54) = 0;
  M<UInt32>(self + 0xc58) = 0;
  M<UInt32>(self + 0xc4c) = 0;
  M<UInt32>(self + 0x8dc) = 0;
  M<UInt32>(self + 0x8e0) = 0;
  M<UInt32>(self + 0x8e4) = 0;
  M<UInt32>(self + 0x8e8) = 0;
  M<UInt32>(self + 0x8ec) = 0;
  M<UInt32>(self + 0x8f0) = 0;
  M<UInt32>(self + 0x8f4) = 0;
  M<UInt32>(self + 0x8f8) = 0;
  ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->init_pool(0);
  M<UInt32>(self + 0x93c) = 0;
  iVar5 = 0;
  pAVar4 = self;
  do {
    bVar1 = iVar5 != 1;
    M<UInt32>(pAVar4 + 0x940) = 0;
    M<UInt32>(pAVar4 + 0x944) = 0;
    M<UInt32>(pAVar4 + 0x948) = 0;
    M<UInt32>(pAVar4 + 0x94c) = 0;
    M<UInt32>(pAVar4 + 0x950) = 0;
    M<UInt32>(pAVar4 + 0x954) = 0;
    M<UInt32>(pAVar4 + 0x958) = 0;
    M<UInt32>(pAVar4 + 0x95c) = 0;
    iVar5 = iVar5 + 1;
    pAVar4 = pAVar4 + 0x20;
  } while (bVar1);
  M<UInt32>(self + 0x8c4) = 0;
  M<UInt32>(self + 0x8c0) = 0;
  uVar6 = VCALL(M<SInt32>(self), 0x188)(self,"ATIEnableWideBlitSupport");
  uVar11 = GH_OSBoolean_metaClass;
  piVar7 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar6,GH_OSBoolean_metaClass);
  if (piVar7 != (SInt32 *)0x0) {
    uVar6 = VCALL(*piVar7, 0xd8)(piVar7);
    M<UInt32>(self + 0x8c0) = uVar6;
  }
  uVar6 = VCALL(M<SInt32>(self), 0x188)(self,"ATIUseTearingWideBlit");
  piVar7 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar6,uVar11);
  if (piVar7 != (SInt32 *)0x0) {
    uVar6 = VCALL(*piVar7, 0xd8)(piVar7);
    M<UInt32>(self + 0x8c4) = uVar6;
  }
  if (M<SInt32>(self + 0x8c0) == 0) {
    M<UInt32>(self + 0x8c4) = 0;
    M<UInt16>(self + 0xa8) = 0x1000;
  }
  else {
    M<UInt16>(self + 0xaa) = 0x1000;
    M<UInt16>(self + 0xa8) = 0x1000;
  }
  this_00 = (UInt8 *)GH_ZN8OSObjectnwEm(0x14);
  if (this_00 != (UInt8 *)0x0) {
    this_00 = (UInt8 *)new ATIR500Memory();
  }
  M<UInt8 *>(self + 0x93c) = this_00;
  if (this_00 != (UInt8 *)0x0) {
    iVar5 = ((ATIR500Memory *)(this_00))->init_pool(0);
    if (iVar5 == 0) {
      VCALL(*M<SInt32 *>(self + 0x93c), 0x18)(M<SInt32 *>(self + 0x93c));
      M<UInt32>(self + 0x93c) = 0;
    }
    else {
      iVar5 = VCALL(*M<SInt32 *>(self + 0x74), 0x578)(M<SInt32 *>(self + 0x74),0x18);
      M<SInt32>(self + 0xac) = iVar5;
      if (iVar5 != 0) {
        piVar7 = (SInt32 *)VCALL(*M<SInt32 *>(self + 0x74), 0x57c)
                                  (M<SInt32 *>(self + 0x74),0x18,0);
        M<SInt32 *>(self + 0x934) = piVar7;
        if (piVar7 != (SInt32 *)0x0) {
          iVar5 = VCALL(*piVar7, 0xd0)(piVar7);
          M<SInt32>(self + 0x860) = iVar5;
          if (iVar5 != 0) {
            bVar2 = M<UInt8>(iVar5 + 8);
            M<UInt32>(iVar5 + 8) =
                 (bVar2 & 0xffffff40 | 0x34) << 0x18 | (UInt32)M<UInt8>(iVar5 + 9) << 0x10 |
                 (UInt32)M<UInt8>(iVar5 + 10) << 8 | (UInt32)M<UInt8>(iVar5 + 0xb);
            M<UInt32>(iVar5 + 8) =
                 (UInt32)bVar2 << 0x18 | (UInt32)M<UInt8>(iVar5 + 9) << 0x10 |
                 (UInt32)M<UInt8>(iVar5 + 10) << 8 | (UInt32)M<UInt8>(iVar5 + 0xb);
            puVar3 = (UInt8 *)
                     (UInt32)CONCAT11(M<UInt8>(iVar5 + 0xd),M<UInt8>(iVar5 + 0xc));
            M<UInt32>(self + 0xc54) = M<UInt8>(iVar5 + 0xf) & 0xf;
            M<UInt8 *>(self + 0xc50) = puVar3;
            if (puVar3 == (UInt8 *)0x7157) goto LAB_0001fafc;
            if (puVar3 < (UInt8 *)0x7158) {
              if (puVar3 < (UInt8 *)0x7147) {
                if ((puVar3 < (UInt8 *)0x7144) && (puVar3 != (UInt8 *)0x7140)) {
                  if (puVar3 < (UInt8 *)0x7141) {
                    if (puVar3 + -0x7100 < (UInt8 *)0x10) {
                      uVar13 = 0;
                      M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) | 0x110000;
                      this->setupR520Pipes();
                      goto LAB_0001fc04;
                    }
                  }
                  else if (puVar3 == (UInt8 *)0x7142) goto LAB_0001fafc;
                  goto LAB_0001fbc8;
                }
              }
              else if (puVar3 != (UInt8 *)0x714e) {
                if (puVar3 < (UInt8 *)0x714f) {
                  if (puVar3 + -29000 < (UInt8 *)0x3) goto LAB_0001fafc;
                }
                else if ((puVar3 == (UInt8 *)0x7150) ||
                        (((UInt8 *)0x714f < puVar3 && (puVar3 + -0x7152 < (UInt8 *)0x2))))
                goto LAB_0001fafc;
                goto LAB_0001fbc8;
              }
LAB_0001fafc:
              uVar13 = 2;
              M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) | 0x410000;
              this->setupR520Pipes();
            }
            else {
              if (puVar3 != (UInt8 *)0x71d2) {
                if ((UInt8 *)0x71d2 < puVar3) {
                  if (puVar3 < (UInt8 *)0x7250) {
                    if ((UInt8 *)0x723f < puVar3) {
LAB_0001fbec:
                      uVar13 = 3;
                      M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) | 0x810000;
                      this->setupR520Pipes();
                      goto LAB_0001fc04;
                    }
                    if (puVar3 == (UInt8 *)0x71de) goto LAB_0001fbd0;
                  }
                  else if ((puVar3 == (UInt8 *)0x7260) ||
                          (((UInt8 *)0x725f < puVar3 && (puVar3 + -0x7263 < (UInt8 *)0xd))))
                  goto LAB_0001fbec;
LAB_0001fbc8:
                  uVar13 = 0;
                  goto LAB_0001fc04;
                }
                if (puVar3 != (UInt8 *)0x71c2) {
                  if (puVar3 < (UInt8 *)0x71c3) {
                    if (puVar3 == (UInt8 *)0x715e) goto LAB_0001fafc;
                    if (puVar3 != (UInt8 *)0x71c0) goto LAB_0001fbc8;
                  }
                  else if ((puVar3 < (UInt8 *)0x71c4) ||
                          (((UInt8 *)0x71c6 < puVar3 && (puVar3 != (UInt8 *)0x71ce))))
                  goto LAB_0001fbc8;
                }
              }
LAB_0001fbd0:
              uVar13 = 1;
              M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) | 0x210000;
              this->setupR520Pipes();
            }
LAB_0001fc04:
            self[0x990] = 0x6;
            iVar5 = this->startupPCIeGART();
            if (iVar5 != -1) {
              self[0x8cd] = 0x0;
              self[0x8cc] = 0x0;
              M<UInt32>(self + 0x86c) = 0x15e0;
              M<UInt32>(self + 0x8c8) = 0;
              M<UInt32>(self + 0x864) = M<UInt32>(self + 0x860);
              M<UInt32>(self + 0x868) = 0x15e4;
              iVar5 = VCALL(M<SInt32>(self), 0x590)
                                (self,M<UInt32>(self + 0x22c),self + 0x228,0,0x1000);
              if (iVar5 != 0) {
                if (M<SInt32>(self + 0x8c8) == 0) {
                  if ((self[0x8cc] != 0x0) && (1 < (UInt8)self[0x8cc])) {
                    iVar5 = 1;
                    do {
                      local_38 = iVar5 << (GH_page_shift & 0x3f);
                      iVar9 = VCALL(M<SInt32>(self), 0x590)
                                        (self,M<UInt32>(self + 0x22c),&local_38,local_38,
                                         local_38 + 0x1000);
                      if (iVar9 == 0) {
                        if (iVar5 < (SInt32)(UInt32)(UInt8)self[0x8cc]) {
                          if (-1 < iVar5 + -1) {
                            iVar9 = 0;
                            do {
                              iVar16 = (iVar5 + -1) - iVar9;
                              iVar9 = iVar9 + 1;
                              VCALL(M<SInt32>(self), 0x5a4)
                                        (self,M<UInt32>(self + 0x22c),
                                         iVar16 << (GH_page_shift & 0x3f));
                            } while (iVar5 != iVar9);
                          }
                          goto LAB_0001f9a0;
                        }
                        break;
                      }
                      iVar5 = iVar5 + 1;
                    } while (iVar5 < (SInt32)(UInt32)(UInt8)self[0x8cc]);
                  }
                }
                else {
                  VCALL(M<SInt32>(self), 0x594)(self,1 << (GH_page_shift & 0x3f));
                  if (1 < (UInt8)self[0x8cc]) {
                    iVar5 = 2;
                    do {
                      local_38 = iVar5 << (GH_page_shift & 0x3f);
                      iVar9 = VCALL(M<SInt32>(self), 0x590)
                                        (self,M<UInt32>(self + 0x22c),&local_38,local_38,
                                         local_38 + 0x1000);
                      if (iVar9 == 0) {
                        if (iVar5 < (SInt32)((UInt32)(UInt8)self[0x8cc] << 1)) goto LAB_0001fd88;
                        break;
                      }
                      iVar9 = iVar5 + 1;
                      iVar5 = iVar5 + 2;
                      VCALL(M<SInt32>(self), 0x594)(self,iVar9 << (GH_page_shift & 0x3f));
                    } while (iVar5 < (SInt32)((UInt32)(UInt8)self[0x8cc] << 1));
                  }
                }
                M<UInt32>(self + 0x938) = 1;
                if ((M<UInt32>(self + 0x98) & 0x80) != 0) {
                  uVar11 = (UInt32)(UInt8)self[0x84];
                  iVar9 = 0;
                  uVar12 = -uVar11 & M<SInt32>(self + 0x238) + 0x20U;
                  iVar5 = ((M<SInt32>(self + 0x238) + 0x20U & uVar11 - 1) + 0x20) - uVar11;
                  if (0 < iVar5) {
                    iVar9 = 0;
                    do {
                      dataCacheBlockStore(uVar12 + iVar9);
                      iVar9 = iVar9 + uVar11;
                    } while (iVar9 < iVar5);
                  }
                  ppcSync();
                  instructionSynchronize();
                  dataCacheBlockFlush(uVar12 + iVar9);
                  ppcSync();
                  instructionSynchronize();
                  instructionSynchronize();
                }
                if ((M<UInt32>(self + 0x98) & 0x80000) == 0) {
                  M<UInt32>(self + 0x910) = 0;
                  M<UInt32>(self + 0x90c) = M<UInt32>(self + 0x238);
                }
                else {
                  M<UInt32>(self + 0x910) = 0x710;
                  M<UInt32>(self + 0x90c) = M<UInt32>(self + 0x860);
                }
                M<UInt32>(self + 0xba0) = 0x2000;
                iVar5 = GH_IOMallocAligned(0x2000,GH_page_size);
                M<SInt32>(self + 0x900) = iVar5;
                if (iVar5 != 0) {
                  iVar5 = GH_ZN18IOMemoryDescriptor11withAddressEPvm11IODirection(iVar5,M<UInt32>(self + 0xba0),3);
                  M<SInt32>(self + 0x908) = iVar5;
                  if (iVar5 != 0) {
                    iVar5 = VCALL(M<SInt32>(self), 0x5a0)(self,iVar5,self + 0x904);
                    if (iVar5 != 0) {
                      iVar9 = M<SInt32>(self + 0x900);
                      iVar5 = 0;
                      iVar16 = 0x800;
                      do {
                        M<UInt32>(iVar9 + iVar5 * 4) = 0x80000000;
                        iVar5 = iVar5 + 1;
                        iVar16 = iVar16 + -1;
                      } while (iVar16 != 0);
                      if ((M<UInt32>(self + 0x98) & 0x80000) == 0) {
                        M<UInt32>(self + 0x92c) = 0;
                        M<SInt32>(self + 0x928) = M<SInt32>(self + 0x238) + 4;
                      }
                      else {
                        M<UInt32>(self + 0x92c) = 0x1f9c;
                        M<UInt32>(self + 0x928) = M<UInt32>(self + 0x860);
                      }
                      iVar5 = GH_IOMallocAligned(0x2000,GH_page_size);
                      M<SInt32>(self + 0x91c) = iVar5;
                      if (iVar5 != 0) {
                        iVar5 = GH_ZN18IOMemoryDescriptor11withAddressEPvm11IODirection(iVar5,0x2000,3);
                        M<SInt32>(self + 0x924) = iVar5;
                        if (iVar5 != 0) {
                          iVar5 = VCALL(M<SInt32>(self), 0x5a0)(self,iVar5,self + 0x920);
                          if (iVar5 != 0) {
                            iVar9 = M<SInt32>(self + 0x91c);
                            iVar5 = 0;
                            iVar16 = 0x800;
                            do {
                              M<UInt32>(iVar9 + iVar5 * 4) = 0x80000000;
                              iVar5 = iVar5 + 1;
                              iVar16 = iVar16 + -1;
                            } while (iVar16 != 0);
                            M<UInt32>(self + 0xb74) = 0x11;
                            if ((M<UInt32>(self + 0x98) & 0x80000) == 0) {
                              iVar5 = GH_IOMallocAligned(GH_page_size,GH_page_size);
                              M<SInt32>(self + 0x8d0) = iVar5;
                              if (iVar5 != 0) {
                                iVar5 = GH_ZN18IOMemoryDescriptor11withAddressEPvm11IODirection(iVar5,GH_page_size,3);
                                M<SInt32>(self + 0x8d8) = iVar5;
                                if (iVar5 == 0) {
                                  GH_IOFreeAligned(M<UInt32>(self + 0x8d0),GH_page_size);
                                  M<UInt32>(self + 0x8d0) = 0;
                                }
                                else {
                                  iVar5 = VCALL(M<SInt32>(self), 0x5a0)
                                                    (self,iVar5,self + 0x8d4);
                                  if (iVar5 == 0) {
                                    VCALL(*M<SInt32 *>(self + 0x8d8), 0x18)(M<SInt32 *>(self + 0x8d8));
                                    GH_IOFreeAligned(M<UInt32>(self + 0x8d0),GH_page_size);
                                    M<UInt32>(self + 0x8d0) = 0;
                                  }
                                  else {
                                    M<UInt32>(self + 0x86c) = 0;
                                    M<UInt32>(self + 0x868) = 4;
                                    M<UInt32>(self + 0x864) = M<UInt32>(self + 0x8d0);
                                  }
                                }
                              }
                            }
                            VCALL(M<SInt32>(self), 0x164)
                                      (self,"IOGLBundleName","ATIRadeonX1000GLDriver");
                            M<UInt32>(self + 0x980) = 0x7b8;
                            M<UInt32>(self + 0x984) = 0x3ff;
                            M<UInt32>(self + 0x988) = 0;
                            iVar5 = HZMEM_Init((_HZDATA *)(self + 0x870),uVar13,
                                               M<UInt32>(self + 0xb98),M<UInt32>(self + 0xb9c));
                            if (iVar5 == 0) {
                              GH_memset(self + 0xb2c,0,0x40);
                              self[0x9b0] = 0x0;
                              M<UInt32>(self + 0xb6c) = 0;
                              M<UInt32>(self + 0xb70) = 0;
                              M<UInt32>(self + 0xacc) = 0;
                              M<UInt32>(self + 0x9b4) = 10;
                              M<UInt32>(self + 0xad0) = 0;
                              M<UInt32>(self + 0xaac) = 0;
                              M<UInt32>(self + 0xab0) = 0;
                              M<UInt32>(self + 0xab4) = 0;
                              M<UInt32>(self + 0xab8) = 0;
                              M<UInt32>(self + 0xabc) = 0;
                              M<UInt32>(self + 0xac0) = 0;
                              M<UInt32>(self + 0xac4) = 0;
                              M<UInt32>(self + 0xac8) = 0;
                              GH_memset(self + 0x9bc,0,0xf0);
                              GH_memset(self + 0xafc,0,0x30);
                              iVar5 = GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(self,SWDSFunc);
                              M<SInt32>(self + 0x9b8) = iVar5;
                              if (iVar5 != 0) {
                                VCALL(*M<SInt32 *>(self + 0xb4), 0xe4)
                                          (M<SInt32 *>(self + 0xb4),iVar5);
                                M<UInt32>(self + 0xaf8) = 0;
                                M<UInt32>(self + 0xadc) = 0;
                                M<UInt32>(self + 0xae0) = 0;
                                M<UInt32>(self + 0xae4) = 0;
                                M<UInt16>(self + 0xaec) = 1;
                                M<UInt32>(self + 0xae8) = 0;
                                M<UInt16>(self + 0xaee) = 0;
                                M<UInt32>(self + 0xaf0) = 0;
                                M<UInt32>(self + 0xaf4) = 0;
                                iVar5 = IOATIR500Accelerator::allocCommandBuffer((VendorCommandBuffer *)(self + 0xae0),0x1000);
                                if ((iVar5 != 0) &&
                                   (iVar5 = VCALL(M<SInt32>(self), 0x5a0)
                                                      (self,M<UInt32>(self + 0xae8),
                                                       self + 0xae4), iVar5 != 0)) {
                                  M<UInt32>(self + 0xb58) = 7;
                                  M<UInt32>(self + 0xb54) = 7;
                                  local_34[0] = self + 0xb2c;
                                  VCALL(*M<SInt32 *>(self + 0x74), 0x170)
                                            (M<SInt32 *>(self + 0x74),"ATIFEDSInfo",local_34,4);
                                  if ((M<SInt32>(self + 0xcc) == 0) ||
                                     ((M<SInt32>(self + 0xe4) == 0 ||
                                      (iVar5 = this->initialize_hardware(), iVar5 != 0)))) {
                                    pcVar14 = M<code *>(M<SInt32>(self) + 0x16c);
                                    uVar6 = VCALL(M<SInt32>(self), 0x5d0)(self);
                                    (*pcVar14)(self,"AccelCaps",0,uVar6,0x20);
                                    VCALL(M<SInt32>(self), 0x340)(self,0);
                                    M<UInt32>(self + 0x9a4) = 0;
                                    uVar6 = VCALL(M<SInt32>(self), 0x188)
                                                      (self,"sensor-properties");
                                    piVar7 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar6,GH_OSArray_metaClass);
                                    if (piVar7 != (SInt32 *)0x0) {
                                      piVar15 = (SInt32 *)0x0;
                                      iVar5 = 0;
                                      while( true ) {
                                        uVar6 = VCALL(*piVar7, 0x138)(piVar7,iVar5);
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
                                        iVar5 = iVar5 + 1;
                                      }
                                      if ((piVar15 != (SInt32 *)0x0) &&
                                         (iVar5 = VCALL(*piVar15, 0x1d8)
                                                            (piVar15,self,GH_gIOServicePlane),
                                         iVar5 != 0)) {
                                        M<SInt32 *>(self + 0x9a4) = piVar15;
                                        VCALL(*piVar15, 0x340)(piVar15,0);
                                      }
                                    }
                                    if (M<SInt32>(self + 0x9a4) != 0) {
                                      M<UInt32>(self + 0x994) = 0;
                                      M<UInt32>(self + 0x998) = 0;
                                      iVar5 = GH_ZN18IOTimerEventSource16timerEventSourceEP8OSObjectPFvS1_PS_(self,GPUSensorFunc);
                                      M<SInt32>(self + 0x9a8) = iVar5;
                                      if (iVar5 != 0) {
                                        iVar5 = VCALL(*M<SInt32 *>(self + 0xb4), 0xe4)
                                                          (M<SInt32 *>(self + 0xb4),iVar5);
                                        if (iVar5 == 0) {
                                          piVar7 = (SInt32 *)this->getPeriodValue("polling-period");
                                          if (piVar7 != (SInt32 *)0x0) {
                                            M<UInt32>(self + 0x994) =
                                                 *piVar7 * 1000 + (UInt32)piVar7[1] / 1000000;
                                          }
                                          piVar7 = (SInt32 *)this->getPeriodValue("sample-period");
                                          if (piVar7 != (SInt32 *)0x0) {
                                            M<UInt32>(self + 0x998) =
                                                 *piVar7 * 1000 + (UInt32)piVar7[1] / 1000000;
                                          }
                                          this->enable_GPUSensor();
                                        }
                                        else {
                                          VCALL(*M<SInt32 *>(self + 0x9a8), 0x18)(M<SInt32 *>(self + 0x9a8));
                                          M<UInt32>(self + 0x9a8) = 0;
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
                          VCALL(*M<SInt32 *>(self + 0x924), 0x18)(M<SInt32 *>(self + 0x924));
                        }
                        GH_IOFreeAligned(M<UInt32>(self + 0x91c),0x2000);
                        M<UInt32>(self + 0x91c) = 0;
                      }
                      goto LAB_0001f9a0;
                    }
                    VCALL(*M<SInt32 *>(self + 0x908), 0x18)(M<SInt32 *>(self + 0x908));
                  }
                  GH_IOFreeAligned(M<UInt32>(self + 0x900),M<UInt32>(self + 0xba0));
                  M<UInt32>(self + 0x900) = 0;
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
  VCALL(M<SInt32>(self), 0x34c)(self,param_1);
LAB_0001f9c0:
  uVar8 = GH_ZN8OSSymbol17withCStringNoCopyEPKc("getSensorValue");
  M<UInt32>(self + 0x9ac) = uVar8;
  return uVar6;
LAB_0001fd88:
  while (iVar9 = iVar5 + -2, -1 < iVar9) {
    VCALL(M<SInt32>(self), 0x598)(self,iVar5 + -1 << (GH_page_shift & 0x3f));
    VCALL(M<SInt32>(self), 0x5a4)
              (self,M<UInt32>(self + 0x22c),iVar9 << (GH_page_shift & 0x3f));
    iVar5 = iVar9;
  }
  goto LAB_0001f9a0;
}

