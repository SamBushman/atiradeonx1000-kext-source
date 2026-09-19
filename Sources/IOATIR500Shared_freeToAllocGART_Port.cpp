/*
 * IOATIR500Shared_freeToAllocGART_Port.cpp
 *
 * IOATIR500Shared::freeToAllocGART (real addr 0x17060, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x17060 */
bool IOATIR500Shared::freeToAllocGART(VendorTransferBuffer *real_param_1, bool param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 VVar1;
  int iVar2;
  UInt8 *pVVar3;
  
  pVVar3 = M<UInt8 *>(self + 0x24);
  do {
    if (pVVar3 == (UInt8 *)0x0) {
      return 0;
    }
    VVar1 = pVVar3[0x20];
    if (VVar1 == 0x4) {
      M<UInt8>(M<int>(pVVar3 + 0x14) + 0x14) = 1;
      iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0xc)))->freeTransferToAllocGART((VendorTransferBuffer *)(pVVar3),(VendorTransferBuffer *)(param_1),
                         M<UInt32>(M<int>(pVVar3 + 0x14) + 8),param_2);
joined_r0x000170d8:
      if (iVar2 != 0) {
        return 1;
      }
    }
    else if ((VVar1 == 0x7) || (VVar1 == 0x3)) {
      iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0xc)))->freeTransferToAllocGART((VendorTransferBuffer *)(pVVar3),(VendorTransferBuffer *)(param_1),
                         M<UInt32>(M<int>(pVVar3 + 0x14) + 0xc),param_2);
      goto joined_r0x000170d8;
    }
    pVVar3 = M<UInt8 *>(pVVar3 + 0x3c);
  } while( true );
}
