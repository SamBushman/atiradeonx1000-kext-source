/*
 * ATIR500Surface_alloc_surface_buffer_Port.cpp
 *
 * ATIR500Surface::alloc_surface_buffer (real addr 0x3e230, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3e230 */
UInt32 ATIR500Surface::alloc_surface_buffer(ATIR500SurfaceBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt16 uVar1;
  int iVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  unsigned int uVar6;
  int iVar7;
  unsigned int uVar8;
  
  uVar6 = M<unsigned int>(param_1 + 0x3c);
  uVar8 = uVar6 >> 0xb & 1;
  if (((M<unsigned int>(self + 0xbe8) & 0x700000) == 0) ||
     ((uVar8 == 0 && (param_1 != (UInt8 *)(self + 0x4e0))))) {
    iVar7 = M<int>(self + 0xd50);
    if (M<UInt16>(iVar7 + 0xa8) < M<UInt16>(param_1 + 0x1c)) {
      return 0;
    }
    if (M<UInt16>(iVar7 + 0xaa) < M<UInt16>(param_1 + 0x1e)) {
      return 0;
    }
  }
  else {
    if (((uVar6 & 0xf00000) != 0) &&
       (0x1000 < (unsigned int)M<UInt16>(param_1 + 0x1c) / (uVar6 >> 0x14 & 0xf))) {
      return 0;
    }
    if (0x1000 < M<UInt16>(param_1 + 0x1e)) {
      return 0;
    }
    iVar7 = M<int>(self + 0xd50);
  }
  if (M<int>(self + 0x90) == 0) {
LAB_0003e330:
    if (M<int>(iVar7 + 0xd0) == 0) {
      iVar7 = ((ATIR500Memory *)(M<UInt8 *>(iVar7 + 0x7c)))->alloc((GLKMemoryElement *)((UInt8 *)param_1),
                         M<UInt32>(param_1 + 0x10),0x1000,0x10000,M<int>(iVar7 + 0x84c) - 0x10000);
    }
    else {
      iVar7 = ((ATIR500Memory *)(M<UInt8 *>(iVar7 + 0x7c)))->alloc((GLKMemoryElement *)((UInt8 *)param_1),
                         M<UInt32>(param_1 + 0x10),0x1000,0,M<UInt32>(iVar7 + 0x84c));
    }
    if (iVar7 == 0) {
      return 0;
    }
  }
  else {
    uVar5 = M<UInt32>(iVar7 + 0x84c);
    if ((M<unsigned int>(iVar7 + 0x9c) <= uVar5) ||
       ((1 < (UInt8)((char)param_1[0x3a] - 0x2dU) && (param_1[0x3a] != 0xb))))
    goto LAB_0003e330;
    iVar7 = ((ATIR500Memory *)(M<UInt8 *>(iVar7 + 0x7c)))->alloc((GLKMemoryElement *)((UInt8 *)param_1),
                       M<UInt32>(param_1 + 0x10),0x1000,uVar5,M<unsigned int>(iVar7 + 0x9c) - uVar5);
    if (iVar7 == 0) {
      iVar7 = M<int>(self + 0xd50);
      goto LAB_0003e330;
    }
  }
  if (uVar8 == 0) {
    if (param_1 != (UInt8 *)(self + 0x4e0)) {
      return 1;
    }
    uVar6 = 0;
    iVar7 = M<int>(M<int>(self + 0xd50) + 0xb98);
    if ((M<unsigned int>(param_1 + 0x3c) & 0xf00000) != 0) {
      uVar6 = (unsigned int)M<UInt16>(param_1 + 0x14) / (M<unsigned int>(param_1 + 0x3c) >> 0x14 & 0xf);
    }
    uVar8 = 0x20 / M<UInt16>(param_1 + 0x16);
    if (0x20 / M<UInt16>(param_1 + 0x16) <= uVar6) {
      uVar8 = uVar6;
    }
    iVar2 = 0x20;
    if (iVar7 != 4) {
      iVar2 = iVar7 << 4;
      uVar5 = 0;
      if (iVar2 == 0) goto LAB_0003e544;
    }
    uVar5 = iVar2 * ((int)(iVar2 + uVar8 + -1) / iVar2);
LAB_0003e544:
    uVar1 = M<UInt16>(param_1 + 0x1e);
    uVar6 = (unsigned int)uVar1;
    if ((uVar1 & 0x1f) != 0) {
      uVar6 = (uVar1 & 0xffffffe0) + 0x20;
    }
    uVar3 = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<int>(self + 0xd50) + 0x870)),M<UInt32>(param_1 + 0x28),2,
                        uVar5,uVar6);
    M<UInt32>(param_1 + 0x28) = uVar3;
    return 1;
  }
  uVar6 = 0;
  iVar7 = M<int>(M<int>(self + 0xd50) + 0xb98);
  if ((M<unsigned int>(param_1 + 0x3c) & 0xf00000) != 0) {
    uVar6 = (unsigned int)M<UInt16>(param_1 + 0x14) / (M<unsigned int>(param_1 + 0x3c) >> 0x14 & 0xf);
  }
  uVar8 = 0x20 / M<UInt16>(param_1 + 0x16);
  if (0x20 / M<UInt16>(param_1 + 0x16) <= uVar6) {
    uVar8 = uVar6;
  }
  iVar2 = 0x20;
  if (iVar7 == 4) {
LAB_0003e3e8:
    uVar5 = iVar2 * ((int)(iVar2 + uVar8 + -1) / iVar2);
  }
  else {
    iVar2 = iVar7 << 4;
    uVar5 = 0;
    if (iVar2 != 0) goto LAB_0003e3e8;
  }
  uVar1 = M<UInt16>(param_1 + 0x1e);
  uVar6 = (unsigned int)uVar1;
  if ((uVar1 & 0x1f) != 0) {
    uVar6 = (uVar1 & 0xffffffe0) + 0x20;
  }
  uVar5 = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<int>(self + 0xd50) + 0x870)),M<UInt32>(param_1 + 0x28),0,uVar5
                      ,uVar6);
  M<UInt32>(param_1 + 0x28) = uVar5;
  if (M<UInt16>(param_1 + 0x16) == 2) {
    uVar6 = M<unsigned int>(param_1 + 0x3c);
    if (1 < (uVar6 >> 0x14 & 0xf)) {
      return 1;
    }
  }
  else {
    uVar6 = M<unsigned int>(param_1 + 0x3c);
  }
  uVar8 = 0;
  iVar7 = M<int>(M<int>(self + 0xd50) + 0xb98);
  if ((uVar6 & 0xf00000) != 0) {
    uVar8 = (unsigned int)M<UInt16>(param_1 + 0x14) / (uVar6 >> 0x14 & 0xf);
  }
  uVar6 = 0x20 / M<UInt16>(param_1 + 0x16);
  if (uVar6 <= uVar8) {
    uVar6 = uVar8;
  }
  iVar2 = 0x20;
  if (iVar7 != 4) {
    iVar2 = iVar7 << 4;
    uVar4 = 0;
    if (iVar2 == 0) goto LAB_0003e4a4;
  }
  uVar4 = iVar2 * ((int)(iVar2 + uVar6 + -1) / iVar2);
LAB_0003e4a4:
  uVar1 = M<UInt16>(param_1 + 0x1e);
  uVar6 = (unsigned int)uVar1;
  if ((uVar1 & 0x1f) != 0) {
    uVar6 = (uVar1 & 0xffffffe0) + 0x20;
  }
  uVar3 = HZMEM_Alloc((_HZDATA *)((UInt8 *)(M<int>(self + 0xd50) + 0x870)),uVar5,1,uVar4,uVar6);
  M<UInt32>(param_1 + 0x28) = uVar3;
  return 1;
}
