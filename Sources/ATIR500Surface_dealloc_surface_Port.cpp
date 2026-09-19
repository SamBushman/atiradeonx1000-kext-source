/*
 * ATIR500Surface_dealloc_surface_Port.cpp
 *
 * ATIR500Surface::dealloc_surface (real addr 0x3df70, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3df70 */
UInt32 ATIR500Surface::dealloc_surface(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt8 *pVVar6;
  SInt32 iVar7;
  SInt32 *piVar8;
  
  if (2 < param_1 - 6) goto LAB_0003e150;
  iVar5 = param_1 * 0x78;
  if ((M<SInt32>(self + iVar5 + 0xb0) != 0) && (piVar8 = M<SInt32 *>(self + 0xd50), piVar8[0x2e5] != 0)
     ) {
    uVar1 = M<UInt16>(self + 0xcae) + 1 & 3;
    M<SInt16>(self + 0xcae) = (SInt16)uVar1;
    pVVar6 = (UInt8 *)(self + uVar1 * 0x1c + 0xc3c);
    if (M<SInt32>(self + uVar1 * 0x1c + 0xc44) == 0) {
      iVar2 = ((IOATIR500Surface *)((UInt8 *)self))->allocAllSlaveSwapBuffers(0,M<UInt32>(self + 0xcb0));
      if (iVar2 != 0) goto LAB_0003e028;
      pVVar6 = (UInt8 *)0x0;
    }
    else {
      iVar7 = piVar8[0x1e2];
      iVar2 = VCALL(*piVar8, 0x54c)(piVar8,M<UInt32>(self + uVar1 * 0x1c + 0xc4c));
      piVar8[0x1e2] = iVar7 + iVar2;
LAB_0003e028:
      if (M<SInt32>(self + uVar1 * 0x1c + 0xc40) == 0) {
        ((IOATIR500Surface *)(self))->map_transfer_to_GART((VendorTransferBuffer *)(pVVar6));
      }
    }
    self[iVar5 + 0xdc] = 0x0;
    if (pVVar6 != (UInt8 *)0x0) {
      uVar3 = this->decompress_and_flush_depth_buffer((ATIR500SurfaceBuffer *)((UInt8 *)(self + iVar5 + 0xa8)),0,
                         (UInt32 *)(M<SInt32>(pVVar6 + 0x14) + 0x20));
      if ((uVar3 & 1) != 0) {
        iVar2 = uVar3 * 4;
        uVar3 = uVar3 + 1;
        M<UInt32>(iVar2 + M<SInt32>(pVVar6 + 0x14) + 0x20) = 0x80000000;
      }
      M<UInt32>(M<SInt32>(self + 0xc34) + 0x1c) = M<UInt32>(M<SInt32>(self + 0xc34) + 0x1c) | 1;
      M<UInt32>(M<SInt32>(self + 0xd50) + 0x710) =
           uVar3 * 4 + M<SInt32>(M<SInt32>(self + 0xd50) + 0x710);
      uVar4 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 0xd50)))->submit_buffer((UInt32 *)(M<SInt32>(pVVar6 + 0x14) + 0x20),M<SInt32>(pVVar6 + 4) + 0x20,uVar3);
      M<UInt32>(pVVar6 + 0x10) = uVar4;
    }
  }
  uVar3 = M<UInt32>(self + iVar5 + 0xd0);
  if ((uVar3 & 0x3ff) != 0x3ff) {
    HZMEM_Free((_HZDATA *)((UInt8 *)(M<SInt32>(self + 0xd50) + 0x870)),uVar3,0);
    self[iVar5 + 0xdc] = 0x0;
    uVar3 = M<UInt32>(self + iVar5 + 0xd0) & 0xfffffc00 | 0x3ff;
    M<UInt32>(self + iVar5 + 0xd0) = uVar3;
  }
  if ((uVar3 & 0xffc00) != 0xffc00) {
    HZMEM_Free((_HZDATA *)((UInt8 *)(M<SInt32>(self + 0xd50) + 0x870)),uVar3,1);
    self[iVar5 + 0xdd] = 0x0;
    M<UInt32>(self + iVar5 + 0xd0) = M<UInt32>(self + iVar5 + 0xd0) & 0xfff003ff | 0xffc00;
  }
LAB_0003e150:
  if ((param_1 == 9) && ((M<UInt32>(self + 0x508) & 0x3ff00000) != 0x3ff00000)) {
    HZMEM_Free((_HZDATA *)((UInt8 *)(M<SInt32>(self + 0xd50) + 0x870)),M<UInt32>(self + 0x508),2);
    self[0x516] = 0x0;
    M<UInt32>(self + 0x508) = M<UInt32>(self + 0x508) & 0xc00fffff | 0x3ff00000;
  }
  IOATIR500Surface::dealloc_surface(param_1);
  return 1;
}
