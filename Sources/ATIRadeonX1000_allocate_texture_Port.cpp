/*
 * ATIRadeonX1000_allocate_texture_Port.cpp
 *
 * ATIRadeonX1000::allocate_texture (real addr 0x1a800, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1a800 */
IOReturn ATIRadeonX1000::allocate_texture(VendorTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 VVar1;
  int *piVar2;
  int iVar3;
  UInt8 *this_00;
  UInt32 uVar4;
  UInt32 uVar5;
  UInt32 uVar6;
  unsigned int uVar7;
  
  VVar1 = param_1[0x20];
  if ((VVar1 == 0x3) || (VVar1 == 0x7)) {
    uVar6 = M<UInt32>(param_1 + 0x50);
LAB_0001a84c:
    uVar5 = M<UInt32>(self + 0x84c);
    if (uVar5 == M<UInt32>(self + 0x9c)) {
LAB_0001a8f0:
      if (M<int>(self + 0xd0) == 0) {
        iVar3 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->alloc((GLKMemoryElement *)(param_1 + 0x40),
                           uVar6,0x1000,0x10000,uVar5 - 0x10000);
      }
      else {
        this_00 = M<UInt8 *>(self + 0x7c);
LAB_0001a980:
        iVar3 = ((ATIR500Memory *)(this_00))->alloc((GLKMemoryElement *)(param_1 + 0x40),uVar6,0x1000,0,uVar5);
      }
      if (iVar3 == 0) goto LAB_0001a994;
    }
    else {
      piVar2 = (int *)VCALL(*M<int *>(param_1 + 8), 0x14c)
                                (M<int *>(param_1 + 8),GH_kernel_task,0,1,0,0);
      if (piVar2 == (int *)0x0) {
        uVar5 = M<UInt32>(self + 0x84c);
        goto LAB_0001a8f0;
      }
      iVar3 = VCALL(*piVar2, 0xd0)(piVar2);
      uVar7 = M<unsigned int>(iVar3 + 0x20);
      VCALL(*piVar2, 0x18)(piVar2);
      uVar5 = M<UInt32>(self + 0x84c);
      if (((uVar7 ^ 0x40000000) >> 0x1e & 1) != 0) goto LAB_0001a8f0;
      iVar3 = ((ATIR500Memory *)(M<UInt8 *>(self + 0x7c)))->alloc((GLKMemoryElement *)(param_1 + 0x40),uVar6
                         ,0x1000,uVar5,M<int>(self + 0x9c) - uVar5);
      if (iVar3 == 0) {
        uVar5 = M<UInt32>(self + 0x84c);
        this_00 = M<UInt8 *>(self + 0x7c);
        goto LAB_0001a980;
      }
    }
    uVar4 = 1;
  }
  else {
    if (VVar1 != 0x8) {
      uVar6 = 0;
      goto LAB_0001a84c;
    }
LAB_0001a994:
    uVar4 = 0;
  }
  return uVar4;
}
