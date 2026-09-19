/*
 * IOATIR500GLContext_map_transfer_to_GART_Port.cpp
 *
 * IOATIR500GLContext::map_transfer_to_GART (real addr 0x79d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x79d0 */
void IOATIR500GLContext::map_transfer_to_GART(VendorTransferBuffer *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  SInt32 iVar1;
  
  iVar1 = VCALL(*M<SInt32 *>(self + 200), 0x5a8)(M<SInt32 *>(self + 200));
  if (iVar1 == 0) {
    ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeToAllocGART((IOATIR5002DContext *)((UInt8 *)0x0),
               (IOATIR500DVDContext *)((UInt8 *)0x0),(IOATIR500GLContext *)(self),(IOATIR500Surface *)(M<UInt8 *>(self + 0x290)),
               (IOATIR500Shared *)(M<UInt8 *>(self + 0x88)),(VendorTransferBuffer *)(param_1));
  }
  return;
}
