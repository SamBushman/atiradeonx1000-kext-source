/*
 * ATIRadeonX1000_pageoff_dirty_texture_Port.cpp
 *
 * ATIRadeonX1000::pageoff_dirty_texture (real addr 0x21c60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x21c60 */
void ATIRadeonX1000::pageoff_dirty_texture(VendorTextureBuffer *real_param_2, SInt32 param_3, SInt32 param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);

  unsigned int uVar1;
  int iVar2;
  int *piVar3;
  UInt8 *pAVar4;
  int iVar5;
  int iVar6;
  
  if ((M<int>(param_2 + 0x48) != 0) &&
     (piVar3 = (int *)VCALL(*M<int *>(param_2 + 8), 0x14c)
                                (M<int *>(param_2 + 8),GH_kernel_task,0,1,0,0),
     piVar3 != (int *)0x0)) {
    pAVar4 = (UInt8 *)VCALL(*piVar3, 0xd0)(piVar3);
    if ((M<unsigned int>(pAVar4 + 0x20) & 0x20000000) == 0) {
      if ((((M<unsigned int>(pAVar4 + 0x20) & 0x40000000) == 0) ||
          (iVar5 = this->pageoff_dirty_texture_with_gpu((VendorTextureBuffer *)((UInt8 *)param_2),(ATITextureBufferHeader *)(pAVar4)),
          iVar5 == 0)) &&
         (iVar5 = this->prepare_texture_for_pageoff_with_cpu((VendorTextureBuffer *)((UInt8 *)param_2),(ATITextureBufferHeader *)(pAVar4)),
         iVar5 != 0)) {
        this->pageoff_dirty_texture_with_cpu((VendorTextureBuffer *)((UInt8 *)param_2),(ATITextureBufferHeader *)(pAVar4));
      }
    }
    else {
      this->pageoff_linear_buffer((VendorTextureBuffer *)((UInt8 *)param_2),(ATITextureBufferHeader *)(pAVar4));
    }
    iVar5 = M<int>(param_2 + 0x14);
    if ((M<SInt16>(iVar5 + 0x36) == 0) && (uVar1 = (unsigned int)M<UInt8>(iVar5 + 0x34), uVar1 != 0)) {
      iVar6 = 0;
      if (uVar1 == 0) {
        uVar1 = 1;
      }
      while( true ) {
        iVar2 = iVar6 * 2;
        iVar6 = iVar6 + 1;
        iVar2 = iVar2 + iVar5;
        M<UInt16>(iVar2 + 0x1c) = M<UInt16>(iVar2 + 0x1c) | M<UInt16>(iVar2 + 0x28);
        uVar1 = uVar1 - 1;
        if (uVar1 == 0) break;
        iVar5 = M<int>(param_2 + 0x14);
      }
    }
    VCALL(*piVar3, 0x18)(piVar3);
  }
  return;
}
