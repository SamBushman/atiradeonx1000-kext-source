/*
 * IOATIR500Accelerator_display_change_handler_Port.cpp
 *
 * IOATIR500Accelerator::display_change_handler (real addr 0x370, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");
extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");


extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");

/* real addr 0x370 */
IOReturn IOATIR500Accelerator::display_change_handler(OSObject *real_param_1, void *param_2, IOFramebuffer *real_param_3, SInt32 param_4, void *param_5) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);
    UInt8 *param_3 = reinterpret_cast<UInt8 *>(real_param_3);

  int iVar1;
  
  ((IOATIR500Accelerator *)param_1)->getVRAMDescriptor((UInt32)param_2);   /* stub 0x534 -> local 0x290; r3/r4 are the untouched arguments */
  switch(param_4) {
  default:
    goto LAB_00000500;
  case 1:
    goto switchD_000003b0_caseD_1;
  case 3:
    if (param_5 != (void *)0x0) {
      VCALL(M<int>(param_1), 0x5bc)(param_1);
      return 0;
    }
switchD_000003b0_caseD_1:
    iVar1 = GH_OSIncrementAtomic(param_1 + 200);
    if (iVar1 == 0) {
      iVar1 = VCALL(M<int>(param_1), 0x5b4)(param_1,param_4);
joined_r0x000004a0:
      if (iVar1 == 0) {
LAB_00000500:
        return 0xe00002bc;
      }
    }
    return 0;
  case 4:
    if (param_5 != (void *)0x0) {
      VCALL(M<int>(param_1), 0x5c0)(param_1);
      return 0;
    }
  case 2:
    iVar1 = GH_OSDecrementAtomic(param_1 + 200);
    if (iVar1 != 1) {
      return 0;
    }
    iVar1 = VCALL(M<int>(param_1), 0x5b8)(param_1);
    goto joined_r0x000004a0;
  case 9:
    VCALL(M<int>(param_1), 0x5c4)(param_1);
    return 0;
  case 10:
    VCALL(M<int>(param_1), 0x5c8)(param_1);
    return 0;
  }
}
