/*
 * ATIR5002DContext_alloc_and_load_image_Port.cpp
 *
 * ATIR5002DContext::alloc_and_load_image (real addr 0x31b70, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOGetTime(...) asm("_IOGetTime");


/* real addr 0x31b70 */
void ATIR5002DContext::alloc_and_load_image(VendorTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  int iVar1;
  
  if (param_1[0x20] == 0x3) {
    if ((M<int>(param_1 + 4) != 0) ||
       (((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)param_1)),
       M<int>(param_1 + 4) != 0)) {
      GH_IOGetTime(param_1 + 0x2c);
      iVar1 = M<int>(param_1 + 0x34);
      M<UInt32>(iVar1 + 0x38) = M<UInt32>(param_1 + 0x38);
      M<int>(M<int>(param_1 + 0x38) + 0x34) = iVar1;
      M<UInt32>(param_1 + 0x34) = M<UInt32>(M<int>(self + 0x94) + 0x6d0);
      M<int>(param_1 + 0x38) = M<int>(self + 0x94) + 0x69c;
      M<UInt8 *>(M<int>(self + 0x94) + 0x6d0) = param_1;
      M<UInt8 *>(M<int>(param_1 + 0x34) + 0x38) = param_1;
    }
    if (((M<int>(param_1 + 0x48) == 0) &&
        (iVar1 = VCALL(*M<int *>(self + 0x94), 0x528)(M<int *>(self + 0x94),param_1),
        iVar1 == 0)) &&
       (iVar1 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0x94)))->freeToAllocTextureVRAM((IOATIR500Surface *)(M<UInt8 *>(self + 0x100)),
                           (VendorTextureBuffer **)((UInt8 **)(self + 0x114)),1,(VendorTextureBuffer *)(param_1)), iVar1 == 0)) {
      return;
    }
  }
  else {
    if (param_1[0x20] != 0x4) {
      return;
    }
    if ((M<int>(param_1 + 4) != 0) ||
       (((IOATIR5002DContext *)((UInt8 *)self))->map_transfer_to_GART((VendorTransferBuffer *)((UInt8 *)param_1)),
       M<int>(param_1 + 4) != 0)) {
      GH_IOGetTime(param_1 + 0x2c);
      iVar1 = M<int>(param_1 + 0x34);
      M<UInt32>(iVar1 + 0x38) = M<UInt32>(param_1 + 0x38);
      M<int>(M<int>(param_1 + 0x38) + 0x34) = iVar1;
      M<UInt32>(param_1 + 0x34) = M<UInt32>(M<int>(self + 0x94) + 0x6d0);
      M<int>(param_1 + 0x38) = M<int>(self + 0x94) + 0x69c;
      M<UInt8 *>(M<int>(self + 0x94) + 0x6d0) = param_1;
      M<UInt8 *>(M<int>(param_1 + 0x34) + 0x38) = param_1;
    }
  }
  M<UInt8>(M<int>(param_1 + 0x14) + 0x14) = 0;
  return;
}
