/*
 * ATIRadeonX1000_deallocate_texture_Port.cpp
 *
 * ATIRadeonX1000::deallocate_texture (real addr 0x1a620, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1a620 */
void ATIRadeonX1000::deallocate_texture(VendorTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt16 *puVar1;
  UInt16 *puVar2;
  UInt8 VVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  
  VVar3 = param_1[0x20];
  if ((VVar3 == 0x3) || (VVar3 == 0x7)) {
    iVar6 = M<SInt32>(param_1 + 0x14);
    uVar5 = (UInt32)M<UInt8>(iVar6 + 0x34);
    if (uVar5 != 0) {
      if ((M<UInt16>(iVar6 + 0x28) & ~M<UInt16>(iVar6 + 0x1c)) == 0) {
        uVar7 = 0;
        uVar8 = uVar5;
        if (uVar5 == 0) {
          uVar8 = 1;
        }
        do {
          uVar7 = uVar7 + 1;
          uVar8 = uVar8 - 1;
          if (uVar8 == 0) {
            if (uVar5 == uVar7) goto LAB_0001a700;
            break;
          }
          puVar1 = (UInt16 *)(iVar6 + 0x2a);
          puVar2 = (UInt16 *)(iVar6 + 0x1e);
          iVar6 = iVar6 + 2;
        } while ((*puVar1 & ~*puVar2) == 0);
      }
      VCALL(M<SInt32>(self), 0x52c)(self,param_1,0xffffffff,0xffffffff);
    }
  }
  else if (VVar3 == 0x8) {
    if (param_1[0x54] == 0x0) {
      if (M<SInt32 *>(param_1 + 0x10) != (SInt32 *)0x0) {
        VCALL(*M<SInt32 *>(param_1 + 0x10), 0x18)(M<SInt32 *>(param_1 + 0x10));
        M<UInt32>(param_1 + 0x10) = 0;
      }
    }
    else {
      ((IOATIR500Accelerator *)(self))->pageOffDataBuffer((VendorTextureBuffer *)(param_1));
    }
  }
LAB_0001a700:
  uVar4 = M<UInt32>(param_1 + 0x6c);
  if (uVar4 != 0xffffffff) {
    if ((uVar4 & 0x3ff) != 0x3ff) {
      HZMEM_Free((_HZDATA *)((UInt8 *)(self + 0x870)),uVar4,0);
      uVar4 = M<UInt32>(param_1 + 0x6c);
    }
    if ((uVar4 & 0xffc00) != 0xffc00) {
      HZMEM_Free((_HZDATA *)((UInt8 *)(self + 0x870)),uVar4,1);
    }
    M<UInt16>(param_1 + 0x72) = 0;
    M<UInt16>(param_1 + 0x7a) = 0;
    M<UInt32>(param_1 + 0x6c) = 0xffffffff;
    M<UInt16>(param_1 + 0x70) = 0;
    M<UInt32>(param_1 + 0x74) = 0;
    M<UInt16>(param_1 + 0x78) = 0;
  }
  ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->dealloc((GLKMemoryElement *)((UInt8 *)(param_1 + 0x40)));
  return;
}
