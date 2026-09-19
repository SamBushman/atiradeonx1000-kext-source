/*
 * IOATIR500Accelerator_allocMoreCommandBuffers_Port.cpp
 *
 * IOATIR500Accelerator::allocMoreCommandBuffers (real addr 0x24a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x24a0 */
bool IOATIR500Accelerator::allocMoreCommandBuffers(UInt32 param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt16 uVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt32 uVar6;
  UInt32 uVar7;
  UInt8 *pVVar8;
  UInt8 *pIVar9;
  
  iVar5 = param_1 * 0x1c4;
  uVar1 = M<UInt16>(self + iVar5 + 0x402);
  uVar6 = (UInt32)uVar1;
  if (uVar6 == 0x10) {
LAB_00002580:
    uVar3 = 0;
  }
  else {
    uVar4 = 1;
    if (uVar6 != 0) {
      uVar4 = uVar6 << 1;
    }
    if (uVar6 < uVar4) {
      pVVar8 = (UInt8 *)(self + uVar6 * 0x1c + iVar5 + 0x240);
      uVar7 = uVar6;
      do {
        iVar2 = this->allocCommandBuffer((VendorCommandBuffer *)(pVVar8),param_2);
        if (iVar2 == 0) {
          iVar2 = uVar7 - 1;
          if ((SInt32)uVar6 <= iVar2) {
            pIVar9 = self + iVar2 * 0x1c + iVar5 + 0x240;
            do {
              iVar2 = iVar2 + -1;
              this->freeCommandBuffer((VendorCommandBuffer *)((UInt8 *)pIVar9));
              pIVar9 = (UInt8 *)(pIVar9 + -0x1c);
            } while ((SInt32)uVar6 <= iVar2);
          }
          goto LAB_00002580;
        }
        uVar7 = uVar7 + 1;
        pVVar8 = pVVar8 + 0x1c;
      } while (uVar4 != uVar7);
    }
    uVar3 = 1;
    M<SInt16>(self + iVar5 + 0x402) = (SInt16)uVar4;
    M<UInt16>(self + iVar5 + 0x400) = uVar1;
  }
  return uVar3;
}
