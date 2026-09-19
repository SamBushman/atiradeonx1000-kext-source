/*
 * IOATIR500Surface_delete_buffer_backing_Port.cpp
 *
 * IOATIR500Surface::delete_buffer_backing (real addr 0x12c30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12c30 */
void IOATIR500Surface::delete_buffer_backing(IOTextureBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  SInt32 iVar2;
  
  if (M<SInt32>(param_1 + 4) != 0) {
    iVar1 = VCALL(*M<SInt32 *>(self + 0xd50), 0x554)
                      (M<SInt32 *>(self + 0xd50),M<UInt32>(M<SInt32>(param_1 + 0x14) + 8));
    if (iVar1 == 0) {
      ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0xd50)))->addOrphanTexture((IOTextureBuffer *)(param_1));
      if (param_1[0x20] != 0x0) {
        return;
      }
      iVar1 = M<SInt32>(param_1 + 0x24);
      M<UInt32>(iVar1 + 0x28) = M<UInt32>(param_1 + 0x28);
      iVar2 = M<SInt32>(param_1 + 0x28);
      M<UInt8 *>(param_1 + 0x28) = param_1;
      M<SInt32>(iVar2 + 0x24) = iVar1;
      M<UInt8 *>(param_1 + 0x24) = param_1;
      return;
    }
    if (M<SInt32>(param_1 + 4) != 0) {
      VCALL(*M<SInt32 *>(self + 0xd50), 0x5ac)(M<SInt32 *>(self + 0xd50),param_1);
    }
  }
  VCALL(*M<SInt32 *>(param_1 + 8), 0x18)(M<SInt32 *>(param_1 + 8));
  VCALL(*M<SInt32 *>(self + 0xd50), 0x574)(M<SInt32 *>(self + 0xd50),param_1,0xc0);
  return;
}
