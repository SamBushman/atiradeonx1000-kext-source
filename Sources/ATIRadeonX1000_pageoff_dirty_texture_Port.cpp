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
void ATIRadeonX1000::pageoff_dirty_texture(VendorTextureBuffer *texture, SInt32 param_3, SInt32 param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  unsigned int uVar1;
  int iVar2;
  int *mapping;
  UInt8 *hwInfo;
  int iVar5;
  int face;
  
  if ((M<int>(textureBytes + 0x48) != 0) &&
     (mapping = (int *)VCALL(*M<int *>(textureBytes + 8), 0x14c)
                                (M<int *>(textureBytes + 8),GH_kernel_task,0,1,0,0),
     mapping != (int *)0x0)) {
    hwInfo = (UInt8 *)VCALL(*mapping, 0xd0)(mapping);
    if ((M<unsigned int>(hwInfo + 0x20) & 0x20000000) == 0) {
      if ((((M<unsigned int>(hwInfo + 0x20) & 0x40000000) == 0) ||
          (iVar5 = this->pageoff_dirty_texture_with_gpu((VendorTextureBuffer *)((UInt8 *)textureBytes),(ATITextureBufferHeader *)(hwInfo)),
          iVar5 == 0)) &&
         (iVar5 = this->prepare_texture_for_pageoff_with_cpu((VendorTextureBuffer *)((UInt8 *)textureBytes),(ATITextureBufferHeader *)(hwInfo)),
         iVar5 != 0)) {
        this->pageoff_dirty_texture_with_cpu((VendorTextureBuffer *)((UInt8 *)textureBytes),(ATITextureBufferHeader *)(hwInfo));
      }
    }
    else {
      this->pageoff_linear_buffer((VendorTextureBuffer *)((UInt8 *)textureBytes),(ATITextureBufferHeader *)(hwInfo));
    }
    iVar5 = M<int>(textureBytes + 0x14);
    if ((M<SInt16>(iVar5 + 0x36) == 0) && (uVar1 = (unsigned int)M<UInt8>(iVar5 + 0x34), uVar1 != 0)) {
      face = 0;
      if (uVar1 == 0) {
        uVar1 = 1;
      }
      while( true ) {
        iVar2 = face * 2;
        face = face + 1;
        iVar2 = iVar2 + iVar5;
        M<UInt16>(iVar2 + 0x1c) = M<UInt16>(iVar2 + 0x1c) | M<UInt16>(iVar2 + 0x28);
        uVar1 = uVar1 - 1;
        if (uVar1 == 0) break;
        iVar5 = M<int>(textureBytes + 0x14);
      }
    }
    VCALL(*mapping, 0x18)(mapping);
  }
  return;
}
