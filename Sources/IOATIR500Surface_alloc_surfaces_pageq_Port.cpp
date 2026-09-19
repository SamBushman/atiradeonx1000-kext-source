/*
 * IOATIR500Surface_alloc_surfaces_pageq_Port.cpp
 *
 * IOATIR500Surface::alloc_surfaces_pageq (real addr 0x12110, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12110 */
UInt32 IOATIR500Surface::alloc_surfaces_pageq(UInt32 param_2, UInt32 param_3, bool param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);

  int *piVar1;
  bool bVar2;
  unsigned int uVar3;
  bool bVar4;
  UInt32 uVar5;
  UInt32 in_register_00000014;
  int iVar6;
  unsigned int uVar7;
  unsigned int uVar8;
  int iVar9;
  unsigned int uVar10;
  UInt32 uVar11;
  
  this->invalidate_contexts();
  uVar8 = param_2 & M<unsigned int>(self + 0xbf8);
  if (uVar8 == 0) {
LAB_000122dc:
    uVar5 = 0;
  }
  else {
    uVar10 = 0;
    uVar7 = 1;
    do {
      uVar3 = 1 << (uVar10 & 0x3f);
      if ((uVar8 & uVar3) != 0) {
        uVar3 = VCALL(M<int>(self), 0x5f4)
                          (self,uVar10,(((UInt32)param_3) & uVar3) == 0);
        uVar7 = uVar7 & uVar3;
      }
      uVar10 = uVar10 + 1;
      if ((uVar8 >> (uVar10 & 0x3f) == 0) || (uVar10 == 0x17)) {
        if (uVar7 != 0) goto LAB_000122dc;
        break;
      }
    } while (uVar7 != 0);
    iVar6 = M<int>(M<int>(self + 0xd50) + 0x5c);
    iVar9 = iVar6;
    if (iVar6 != 0) {
      do {
        if (M<int>(iVar9 + 0xbd0) != 0) {
          if (iVar9 != 0) {
            return 1;
          }
          break;
        }
        piVar1 = (int *)(iVar9 + 0x9c);
        iVar9 = *piVar1;
      } while (iVar6 != *piVar1);
    }
    bVar4 = false;
    iVar9 = 0;
    uVar11 = (UInt32)self;
    do {
      if (M<int>(uVar11 + 0xb0) != 0) {
        this->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)((UInt8 *)(iVar9 * 0x78 + self + 0xa8)));
        bVar4 = true;
      }
      bVar2 = iVar9 != 0x16;
      uVar11 = uVar11 + 0x78;
      iVar9 = iVar9 + 1;
    } while (bVar2);
    if (bVar4) {
      uVar8 = param_2 & M<unsigned int>(self + 0xbf8);
      if (uVar8 == 0) goto LAB_000122dc;
      uVar10 = 0;
      uVar7 = 1;
      do {
        uVar3 = 1 << (uVar10 & 0x3f);
        if ((uVar8 & uVar3) != 0) {
          uVar3 = VCALL(M<int>(self), 0x5f4)
                            (self,uVar10,(uVar3 & ((UInt32)param_3)) == 0);
          uVar7 = uVar7 & uVar3;
        }
        uVar10 = uVar10 + 1;
        if ((uVar8 >> (uVar10 & 0x3f) == 0) || (uVar10 == 0x17)) {
          if (uVar7 != 0) goto LAB_000122dc;
          break;
        }
      } while (uVar7 != 0);
    }
    uVar5 = 2;
  }
  return uVar5;
}
