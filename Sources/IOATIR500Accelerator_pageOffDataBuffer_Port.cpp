/*
 * IOATIR500Accelerator_pageOffDataBuffer_Port.cpp
 *
 * IOATIR500Accelerator::pageOffDataBuffer (real addr 0x3140, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3140 */
void IOATIR500Accelerator::pageOffDataBuffer(VendorTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  SInt32 *piVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  
  iVar1 = this->allocDataBufferBacking((VendorTextureBuffer *)(param_1));
  if (iVar1 == 0) {
    VCALL(M<SInt32>(self), 0x524)(self,param_1);
    iVar3 = M<SInt32>(param_1 + 0x24);
    M<UInt32>(iVar3 + 0x28) = M<UInt32>(param_1 + 0x28);
    iVar1 = M<SInt32>(param_1 + 0x28);
    M<UInt8 *>(param_1 + 0x28) = param_1;
    M<SInt32>(iVar1 + 0x24) = iVar3;
    M<UInt8 *>(param_1 + 0x24) = param_1;
  }
  else {
    piVar2 = M<SInt32 *>(param_1 + 0x10);
    if (piVar2 != (SInt32 *)0x0) {
      VCALL(*piVar2, 0xf0)(piVar2,0,0x400,0);
    }
    piVar2 = (SInt32 *)VCALL(*M<SInt32 *>(param_1 + 8), 0x14c)
                              (M<SInt32 *>(param_1 + 8),GH_kernel_task,0,0x401,0,0);
    if (piVar2 != (SInt32 *)0x0) {
      iVar1 = VCALL(*piVar2, 0xd0)(piVar2);
      if (M<UInt32>(param_1 + 0x50) >> 2 != 0) {
        uVar4 = 0;
        iVar3 = 0;
        do {
          uVar4 = uVar4 + 1;
          M<UInt32>(iVar3 + iVar1) =
               M<UInt32>(M<SInt32>(self + 0xe4) + iVar3 + M<SInt32>(param_1 + 0x48));
          iVar3 = iVar3 + 4;
        } while (uVar4 < M<UInt32>(param_1 + 0x50) >> 2);
      }
      VCALL(*piVar2, 0x18)(piVar2);
    }
    piVar2 = M<SInt32 *>(param_1 + 0x10);
    if (piVar2 != (SInt32 *)0x0) {
      VCALL(*piVar2, 0xf0)(piVar2,M<UInt32>(param_1 + 8),0x400,0);
    }
  }
  return;
}
