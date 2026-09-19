/*
 * ATIR500GLContext_compute_zb_bw_cntl_Port.cpp
 *
 * ATIR500GLContext::compute_zb_bw_cntl (real addr 0x26e40, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x26e40 */
UInt32 ATIR500GLContext::compute_zb_bw_cntl(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *pAVar1;
  UInt32 uVar2;
  
  pAVar1 = self + 0x5a0;
  if (M<SInt32>(self + 0x3bc) == 0) {
    pAVar1 = *(UInt8 **)
              ((UInt32)M<UInt16>(self + 0xae) * 4 + M<SInt32>(self + 0x290) + 0xb70);
  }
  uVar2 = 0;
  if ((pAVar1[0x34] != 0x0) &&
     ((2 < M<UInt16>(pAVar1 + 0x16) || (uVar2 = 4, 2 < (M<UInt32>(pAVar1 + 0x3c) >> 0x14 & 0xf))))
     ) {
    uVar2 = 0x1c;
  }
  if ((pAVar1[0x35] != 0x0) && ((param_1 & 1) != 0)) {
    uVar2 = uVar2 | 1;
  }
  return param_1 & 0xffffffe2 | uVar2;
}
