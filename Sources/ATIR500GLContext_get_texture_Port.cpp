/*
 * ATIR500GLContext_get_texture_Port.cpp
 *
 * ATIR500GLContext::get_texture (real addr 0x2b5f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x2b5f0 */
void ATIR500GLContext::get_texture(UInt32*param_1, VendorTextureBuffer *real_param_2, UInt32*param_3, UInt32*param_4, UInt32*param_5, register_tracking_state *real_param_6) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_2 = reinterpret_cast<UInt8 *>(real_param_2);
    UInt8 *param_6 = reinterpret_cast<UInt8 *>(real_param_6);

  UInt32 uVar1;
  SInt32 *piVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  char in_RESERVE;
  UInt8 in_cr0;
  
  iVar3 = M<SInt32>(param_2 + 0x14);
  if (M<char>(iVar3 + 0x14) != '\0') {
    if (*param_4 != 0) {
      uVar1 = param_1[-1] >> 2;
      if (4 < uVar1) {
        uVar5 = 0x80000000;
        if (uVar1 != 5) {
          uVar5 = (uVar1 - 6) * 0x10000 | 0xc0001000;
        }
        param_1[-uVar1] = uVar5;
      }
      param_1[-4] = 0x1393;
      param_1[-3] = 0;
      param_1[-2] = 0x5c8;
      param_1[-1] = 0x20000;
      M<UInt32>(M<SInt32>(self + 200) + 0x704) =
           *param_4 * 4 + M<SInt32>(M<SInt32>(self + 200) + 0x704);
      M<UInt32>(M<SInt32>(self + 200) + 0xb94) = 1;
      uVar4 = ((ATIRadeonX1000 *)(M<UInt8 *>(self + 200)))->submit_buffer((UInt32 *)((*param_3 & 0xfffffffc) + M<SInt32>(self + 0xe0) + 0x20),
                         *param_3 + M<SInt32>(self + 0xd0) + 0x20,*param_4);
      M<UInt32>(self + 0xdc) = uVar4;
      *param_3 = *param_4 * 4 + *param_3;
      *param_4 = 0;
      *param_5 = 0;
    }
    this->alloc_and_load_texture((VendorTextureBuffer *)(param_2));
    if (M<SInt32>(M<SInt32>(self + 200) + 0xb90) != 0) {
      M<UInt32 *>(param_6 + 0x140) = param_1;
      this->restore_state_destroyed_by_pageoff((register_tracking_state *)(param_6));
    }
    if (M<SInt32>(self + 0xd0) == 0) {
      ((IOATIR500GLContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)));
      iVar3 = M<SInt32>(param_2 + 0x14);
    }
    else {
      iVar3 = M<SInt32>(param_2 + 0x14);
    }
  }
  piVar2 = (SInt32 *)(iVar3 + 0x10);
  atomicAddReturningOld((SInt32 *)piVar2, -0xffff);
  if (M<SInt32>(param_2 + 0x48) != 0) {
    iVar3 = M<SInt32>(param_2 + 0x24);
    M<UInt32>(iVar3 + 0x28) = M<UInt32>(param_2 + 0x28);
    M<SInt32>(M<SInt32>(param_2 + 0x28) + 0x24) = iVar3;
    M<UInt32>(param_2 + 0x24) = M<UInt32>(M<SInt32>(self + 200) + 0x600);
    M<SInt32>(param_2 + 0x28) = M<SInt32>(self + 200) + 0x5dc;
    M<UInt8 *>(M<SInt32>(self + 200) + 0x600) = param_2;
    M<UInt8 *>(M<SInt32>(param_2 + 0x24) + 0x28) = param_2;
  }
  return;
}
