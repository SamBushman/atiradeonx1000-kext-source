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
bool IOATIR500Accelerator::foundFramebuffer(IOFramebuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 *pIVar1;
  UInt8 *pIVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  UInt32 uVar5;
  UInt8 *pIVar6;
  code *pcVar7;
  SInt32 iVar8;
  UInt32 uVar9;
  UInt32 local_138;
  UInt8 auStack_134 [288];
  
  uVar3 = M<UInt32>(self + 0xcc);
  local_138 = 0x100;
  if (uVar3 == 0) {
LAB_000005a0:
    M<UInt8 *>(self + uVar3 * 0x20 + 0xd4) = param_1;
    iVar8 = M<SInt32>(self + 0xcc);
    iVar4 = GH_ZN13IOFramebuffer26addFramebufferNotificationEPFiP8OSObjectP(param_1,(UInt32)&IOATIR500Accelerator::display_change_handler,self,iVar8);
    M<SInt32>(self + iVar8 * 0x20 + 0xd8) = iVar4;
    if (iVar4 != 0) {
      pcVar7 = M<code *>(M<SInt32>(param_1) + 0x160);
      uVar5 = VCALL(M<SInt32>(self), 0x188)(self,"IOCFPlugInTypes");
      (*pcVar7)(param_1,"IOCFPlugInTypes",uVar5);
      iVar4 = VCALL(M<SInt32>(self), 0x218)(self,auStack_134,&local_138,GH_gIOServicePlane);
      if (iVar4 != 0) {
        VCALL(M<SInt32>(param_1), 0x164)(param_1,"IOAccelTypes",auStack_134);
        VCALL(M<SInt32>(param_1), 0x16c)
                  (param_1,"IOAccelIndex",0,M<UInt32>(self + 0xcc),0x20);
        VCALL(M<SInt32>(param_1), 0x16c)(param_1,"IOAccelRevision",0,2,0x20);
        ACCEL(self)->getVRAMDescriptor(M<UInt32>(self + 0xcc));
        M<SInt32>(self + 0xcc) = M<SInt32>(self + 0xcc) + 1;
        return 1;
      }
    }
    uVar5 = 0;
  }
  else {
    pIVar2 = M<UInt8 *>(self + 0xd4);
    uVar9 = uVar3;
    pIVar6 = self;
    while (param_1 != pIVar2) {
      uVar9 = uVar9 - 1;
      if (uVar9 == 0) {
        if (1 < uVar3) {
          return 0;
        }
        goto LAB_000005a0;
      }
      pIVar1 = pIVar6 + 0xf4;
      pIVar6 = pIVar6 + 0x20;
      pIVar2 = M<UInt8 *>(pIVar1);
    }
    uVar5 = 1;
  }
  return uVar5;
}

/* real addr 0x770 */
bool IOATIR500Accelerator::findFramebuffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *piVar1;
  SInt32 *piVar2;
  UInt32 uVar3;
  UInt8 *pIVar4;
  SInt32 iVar5;
  SInt32 *piVar6;
  UInt8 bVar7;
  
  piVar1 = (SInt32 *)VCALL(*M<SInt32 *>(self + 0x74), 0x1bc)
                            (M<SInt32 *>(self + 0x74),GH_gIODTPlane);
  piVar2 = (SInt32 *)GH_ZN8OSSymbol11withCStringEPKc("IOFramebuffer");
  bVar7 = (piVar2 == (SInt32 *)0x0) << 1;
  if ((piVar1 != (SInt32 *)0x0) && (piVar2 != (SInt32 *)0x0)) {
    while( true ) {
      uVar3 = VCALL(*piVar1, 0xd8)(piVar1);
      piVar6 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar3,GH_IOService_metaClass);
      if (piVar6 == (SInt32 *)0x0) break;
      uVar3 = VCALL(*piVar6, 0x444)(piVar6,piVar2);
      pIVar4 = (UInt8 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(uVar3,GH_IOFramebuffer_metaClass);
      if (pIVar4 != (UInt8 *)0x0) {
        ((IOATIR500Accelerator *)(self))->foundFramebuffer((IOFramebuffer *)pIVar4);
      }
    }
    VCALL(*piVar1, 0x18)(piVar1);
  }
  piVar1 = (SInt32 *)VCALL(*M<SInt32 *>(self + 0x74), 0x3c0)(M<SInt32 *>(self + 0x74));
  if (piVar1 != (SInt32 *)0x0) {
    while (piVar6 = (SInt32 *)VCALL(*piVar1, 0xd8)(piVar1), piVar6 != (SInt32 *)0x0) {
      pIVar4 = (UInt8 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(piVar6,GH_IOFramebuffer_metaClass);
      if (pIVar4 == (UInt8 *)0x0) {
        piVar6 = (SInt32 *)VCALL(*piVar6, 0x3c0)(piVar6);
        while (iVar5 = VCALL(*piVar6, 0xd8)(piVar6), iVar5 != 0) {
          pIVar4 = (UInt8 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(iVar5,GH_IOFramebuffer_metaClass);
          if (pIVar4 != (UInt8 *)0x0) {
            ((IOATIR500Accelerator *)(self))->foundFramebuffer((IOFramebuffer *)pIVar4);
          }
        }
        VCALL(*piVar6, 0x18)(piVar6);
      }
      else {
        ((IOATIR500Accelerator *)(self))->foundFramebuffer((IOFramebuffer *)pIVar4);
      }
    }
    VCALL(*piVar1, 0x18)(piVar1);
  }
  if (!(bool)(bVar7 >> 1 & 1)) {
    VCALL(*piVar2, 0x18)(piVar2);
  }
  return 1;
}

/* real addr 0x9f0 */
bool IOATIR500Accelerator::serializePerformanceStats(void *param_1, void *param_2, OSSerialize *param_3) {

  SInt32 *piVar1;
  SInt32 *piVar2;
  UInt32 uVar3;
  
  uVar3 = 0;
  piVar1 = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(param_1,GH_IOATIR500Accelerator_metaClass);
  if (piVar1 != (SInt32 *)0x0) {
    piVar2 = (SInt32 *)GH_ZN12OSDictionary12withCapacityEj(1);
    if (piVar2 != (SInt32 *)0x0) {
      VCALL(*piVar1, 0x568)(piVar1,piVar2);
      uVar3 = VCALL(*piVar2, 0x1c)(piVar2,param_3);
      VCALL(*piVar2, 0x18)(piVar2);
    }
  }
  return uVar3;
}

/* real addr 0x1fd0 */
void IOATIR500Accelerator::freeAllCommandBuffers(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  SInt32 iVar2;
  UInt8 *pIVar3;
  
  iVar1 = param_1 * 0x1c4;
  if (M<SInt16>(self + iVar1 + 0x402) != 0) {
    iVar2 = 0;
    pIVar3 = self + iVar1 + 0x240;
    do {
      iVar2 = iVar2 + 1;
      ((IOATIR500Accelerator *)(self))->freeCommandBuffer((VendorCommandBuffer *)pIVar3);
      pIVar3 = (UInt8 *)(pIVar3 + 0x1c);
    } while (iVar2 < (SInt32)(UInt32)M<UInt16>(self + iVar1 + 0x402));
  }
  M<UInt16>(self + iVar1 + 0x402) = 0;
  M<UInt16>(self + iVar1 + 0x400) = 0;
  return;
}

/* real addr 0x3410 */
void IOATIR500Accelerator::freeAllDataBuffers() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *pVVar1;
  UInt8 *pVVar2;
  
  pVVar1 = M<UInt8 *>(self + 0x5cc);
  while (pVVar1 != (UInt8 *)0x0) {
    pVVar2 = M<UInt8 *>(pVVar1 + 0x3c);
    ((IOATIR500Accelerator *)(self))->freeOneDataBuffer((VendorTextureBuffer *)pVVar1);
    pVVar1 = pVVar2;
  }
  M<UInt32>(self + 0x5d0) = 0;
  M<UInt32>(self + 0x5d4) = 0;
  M<UInt32>(self + 0x5cc) = 0;
  return;
}

/* real addr 0x4a90 */
/* (re-ported mechanically: see IOATIR500Accelerator_free_gart_wirings_Port.cpp) */


/* real addr 0x4f20 */
bool IOATIR500Accelerator::mapVendorTransferBuffer(VendorTransferBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  M<UInt32>(param_1) = 1;
  switch(M<UInt16>(param_1 + 0xc)) {
  case 0:
    M<SInt32>(self + 0x814) = M<SInt32>(self + 0x814) + 1;
    break;
  case 1:
    M<SInt32>(self + 0x818) = M<SInt32>(self + 0x818) + 1;
    break;
  case 2:
    M<SInt32>(self + 0x81c) = M<SInt32>(self + 0x81c) + 1;
    break;
  case 3:
    M<SInt32>(self + 0x820) = M<SInt32>(self + 0x820) + 1;
    break;
  case 4:
    M<SInt32>(self + 0x824) = M<SInt32>(self + 0x824) + 1;
    break;
  default:
    M<SInt32>(self + 0x828) = M<SInt32>(self + 0x828) + 1;
  }
  return 1;
}

/* real addr 0x4fe0 */
void IOATIR500Accelerator::unmapVendorTransferBuffer(VendorTransferBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  M<UInt32>(param_1) = 0;
  switch(M<UInt16>(param_1 + 0xc)) {
  case 0:
    M<SInt32>(self + 0x814) = M<SInt32>(self + 0x814) + -1;
    return;
  case 1:
    M<SInt32>(self + 0x818) = M<SInt32>(self + 0x818) + -1;
    return;
  case 2:
    M<SInt32>(self + 0x81c) = M<SInt32>(self + 0x81c) + -1;
    return;
  case 3:
    M<SInt32>(self + 0x820) = M<SInt32>(self + 0x820) + -1;
    return;
  case 4:
    M<SInt32>(self + 0x824) = M<SInt32>(self + 0x824) + -1;
    return;
  default:
    M<SInt32>(self + 0x828) = M<SInt32>(self + 0x828) + -1;
    return;
  }
}

/* real addr 0x5090 */
void IOATIR500Accelerator::teardownAGP(IOService *real_provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  
  if (M<SInt32>(self + 0x83c) != 0) {
    GH_IOFreeContiguous(M<SInt32>(self + 0x83c),GH_page_size * 2 + M<SInt32>(self + 0x830));
    M<UInt32>(self + 0x848) = 1;
    M<UInt32>(self + 0x844) = 0;
    iVar1 = GH_page_size;
    M<UInt32>(self + 0x83c) = 0;
    M<SInt32>(self + 0x7fc) = M<SInt32>(self + 0x7fc) - (iVar1 * 2 + M<SInt32>(self + 0x830));
  }
  if ((M<SInt32 *>(self + 0x74) != (SInt32 *)0x0) && ((M<UInt32>(self + 0x98) & 2) != 0)) {
    VCALL(*M<SInt32 *>(self + 0x74), 0x5e0)(M<SInt32 *>(self + 0x74));
    M<UInt32>(self + 0x98) = M<UInt32>(self + 0x98) & 0xfffffffd;
  }
  return;
}

/* real addr 0x5270 */
void IOATIR500Accelerator::removeFromGART(IOMemoryDescriptor *real_param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  
  uVar4 = param_2 >> (GH_page_shift & 0x3f);
  if (param_1 != (UInt8 *)0x0) {
    uVar1 = VCALL(M<SInt32>(param_1), 0x128)(param_1);
    uVar1 = uVar4 + (uVar1 >> (GH_page_shift & 0x3f));
    iVar3 = uVar1 - uVar4;
    M<SInt32>(self + 0x718) = (iVar3 << (GH_page_shift & 0x3f)) + M<SInt32>(self + 0x718);
    M<SInt32>(self + 0xa0) = M<SInt32>(self + 0xa0) - (iVar3 << (GH_page_shift & 0x3f));
    if (uVar4 < uVar1) {
      iVar2 = uVar4 << 2;
      do {
        M<UInt32>(M<SInt32>(self + 0x83c) + iVar2) = M<UInt32>(self + 0x844);
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    if (((M<UInt32>(self + 0x98) & 2) != 0) &&
       (uVar4 = param_2 >> (GH_page_shift & 0x3f), uVar4 < uVar1)) {
      do {
        iVar3 = uVar4 << (GH_page_shift & 0x3f);
        uVar4 = uVar4 + 1;
        VCALL(M<SInt32>(self), 0x588)(self,M<UInt32>(self + 0x22c),iVar3,0);
      } while (uVar4 != uVar1);
    }
    uVar4 = param_2 >> (GH_page_shift & 0x3f);
    VCALL(M<SInt32>(self), 0x59c)(self,uVar4,uVar1 - uVar4);
    VCALL(M<SInt32>(param_1), 0x148)(param_1,3);
  }
  return;
}

/* real addr 0x5710 */
bool IOATIR500Accelerator::disp_mode_did_change() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  UInt8 *pIVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  UInt8 *pIVar6;
  UInt8 *this_00;
  UInt8 *pIVar7;
  
  M<UInt32>(self + 0x78) = 0;
  self[0x81] = 0x0;
  this_00 = M<UInt8 *>(self + 0x5c);
  if (this_00 == (UInt8 *)0x0) {
    uVar3 = M<UInt32>(self + 0xcc);
  }
  else {
    do {
      ((IOATIR500Surface *)(this_00))->reset_access();
      uVar3 = M<UInt32>(self + 0xcc);
      if (uVar3 != 0) {
        uVar4 = 0;
        pIVar2 = this_00;
        do {
          if ((1 << (uVar4 & 0x3f) & M<UInt32>(self + 0xd0)) == 0) {
            pIVar2[0xcac] = 0x0;
            uVar3 = M<UInt32>(self + 0xcc);
          }
          uVar4 = uVar4 + 1;
          pIVar2 = pIVar2 + 0x94;
        } while (uVar4 < uVar3);
      }
      this_00 = M<UInt8 *>(this_00 + 0x9c);
    } while (this_00 != M<UInt8 *>(self + 0x5c));
  }
  if (uVar3 != 0) {
    uVar5 = 0;
    pIVar6 = self;
    pIVar7 = self;
    do {
      M<UInt32>(pIVar7 + 0x114) = 1;
      if (M<UInt32>(pIVar7 + 0x124) != 0) {
        ((IOATIR500Accelerator *)(self))->setup_stereo(uVar5, M<UInt32>(pIVar7 + 0x124));
        M<UInt32>(pIVar7 + 0x124) = 0;
      }
      uVar1 = M<UInt32>(pIVar6 + 0xe8);
      if (uVar1 != 0) {
        /* real: alloc_surfaces(surface->0xc18, false) - the decompile shows only the low byte and drops the retry argument */
        ((IOATIR500Surface *)(uVar1))->alloc_surfaces(M<UInt32>(uVar1 + 0xc18), false);
        VCALL(*M<SInt32 *>(pIVar6 + 0xe8), 0x5a4)(M<SInt32 *>(pIVar6 + 0xe8));
      }
      uVar5 = uVar5 + 1;
      pIVar7 = pIVar7 + 4;
      pIVar6 = pIVar6 + 0x20;
    } while (uVar5 < M<UInt32>(self + 0xcc));
  }
  GH_IOLockWakeup(M<UInt32>(self + 0x840),self,0);
  return 1;
}

/* real addr 0x5890 */
void IOATIR500Accelerator::teardown3D() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  UInt32 uVar2;
  UInt8 *pIVar3;
  
  ((IOATIR500Accelerator *)(self))->freeAllCommandBuffers(0);
  ((IOATIR500Accelerator *)(self))->freeAllDataBuffers();
  uVar1 = M<UInt32>(self + 0xcc);
  if (uVar1 != 0) {
    uVar2 = 0;
    pIVar3 = self;
    do {
      M<UInt32>(pIVar3 + 0x114) = 1;
      if (M<SInt32>(pIVar3 + 0x11c) != 0) {
        ((IOATIR500Accelerator *)(self))->setup_stereo(uVar2, 0);
        uVar1 = M<UInt32>(self + 0xcc);
      }
      uVar2 = uVar2 + 1;
      pIVar3 = pIVar3 + 4;
    } while (uVar2 < uVar1);
  }
  return;
}

/* real addr 0x6ad0 */
bool IOATIR500Accelerator::disp_mode_will_change(SInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  UInt8 *pIVar4;
  UInt8 *this_00;
  UInt32 uVar5;
  UInt8 *pIVar6;
  ATIR500SurfaceBuffer *pAVar7;
  UInt8 *pIVar8;
  UInt8 *pIVar9;
  
  if (self[0x80] != 0x0) {
    VCALL(M<SInt32>(self), 0x54c)(self,M<SInt32>(self + 0x50) + -1);
    if (M<SInt32>(self + 0xcc) != 0) {
      uVar5 = 0;
      pIVar6 = self;
      pIVar8 = self;
      do {
        if (M<SInt32 *>(pIVar6 + 0xe8) != (SInt32 *)0x0) {
          VCALL(*M<SInt32 *>(pIVar6 + 0xe8), 0x5a8)(M<SInt32 *>(pIVar6 + 0xe8));
        }
        if (M<SInt32>(pIVar8 + 0x11c) != 0) {
          M<SInt32>(pIVar8 + 0x124) = M<SInt32>(pIVar8 + 0x11c);
          ((IOATIR500Accelerator *)(self))->setup_stereo(uVar5, 0);
        }
        uVar5 = uVar5 + 1;
        pIVar6 = pIVar6 + 0x20;
        pIVar8 = pIVar8 + 4;
      } while (uVar5 < M<UInt32>(self + 0xcc));
    }
    pIVar6 = M<UInt8 *>(self + 0x604);
    while (pIVar6 != self + 0x5dc) {
      if (M<SInt32>(pIVar6 + 0x48) != 0) {
        VCALL(M<SInt32>(self), 0x524)(self,pIVar6);
        M<UInt8>(M<SInt32>(pIVar6 + 0x14) + 0x14) = 1;
        M<UInt16>(M<SInt32>(pIVar6 + 0x14) + 0x28) = 0;
        M<UInt16>(M<SInt32>(pIVar6 + 0x14) + 0x2a) = 0;
        M<UInt16>(M<SInt32>(pIVar6 + 0x14) + 0x2c) = 0;
        M<UInt16>(M<SInt32>(pIVar6 + 0x14) + 0x2e) = 0;
        M<UInt16>(M<SInt32>(pIVar6 + 0x14) + 0x30) = 0;
        M<UInt16>(M<SInt32>(pIVar6 + 0x14) + 0x32) = 0;
      }
      iVar3 = M<SInt32>(pIVar6 + 0x24);
      M<UInt32>(iVar3 + 0x28) = M<UInt32>(pIVar6 + 0x28);
      iVar2 = M<SInt32>(pIVar6 + 0x28);
      M<UInt8 *>(pIVar6 + 0x28) = pIVar6;
      M<SInt32>(iVar2 + 0x24) = iVar3;
      M<UInt8 *>(pIVar6 + 0x24) = pIVar6;
      pIVar6 = M<UInt8 *>(self + 0x604);
    }
    pIVar4 = M<UInt8 *>(self + 0x664);
    while (pIVar4 != (UInt8 *)(self + 0x63c)) {
      iVar3 = M<SInt32>(pIVar4 + 0x24);
      M<UInt32>(iVar3 + 0x28) = M<UInt32>(pIVar4 + 0x28);
      iVar2 = M<SInt32>(pIVar4 + 0x28);
      M<UInt8 *>(pIVar4 + 0x28) = pIVar4;
      M<SInt32>(iVar2 + 0x24) = iVar3;
      M<UInt8 *>(pIVar4 + 0x24) = pIVar4;
      GH_FreeTexvert(self,pIVar4);
      pIVar4 = M<UInt8 *>(self + 0x664);
    }
    this_00 = M<UInt8 *>(self + 0x5c);
    if (this_00 != (UInt8 *)0x0) {
      do {
        iVar2 = 0;
        pAVar7 = (ATIR500SurfaceBuffer *)(this_00 + 0xa8);
        pIVar9 = this_00;
        do {
          if (M<SInt32>(pIVar9 + 0xb0) != 0) {
            ((IOATIR500Surface *)(this_00))->move_buffer_to_backing_store(pAVar7);
          }
          bVar1 = iVar2 != 0x16;
          pAVar7 = pAVar7 + 0x78;
          pIVar9 = pIVar9 + 0x78;
          iVar2 = iVar2 + 1;
        } while (bVar1);
        this_00 = M<UInt8 *>(this_00 + 0x9c);
      } while (this_00 != M<UInt8 *>(self + 0x5c));
    }
    VCALL(M<SInt32>(self), 0x54c)(self,M<SInt32>(self + 0x50) + -1);
    self[0x81] = (param_1 == 3);
    if (self[0x88] != 0x0) {
      VCALL(*M<SInt32 *>(self + 0xc0), 0x158)(M<SInt32 *>(self + 0xc0));
    }
    self[0x89] = 0x0;
    self[0x88] = 0x0;
  }
  return 1;
}
