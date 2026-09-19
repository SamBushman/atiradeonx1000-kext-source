/*
 * IOATIR5002DContext_freeToAllocGART_Port.cpp
 *
 * IOATIR5002DContext::freeToAllocGART (real addr 0xbbc0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0xbbc0 */
bool IOATIR5002DContext::freeToAllocGART(VendorTransferBuffer *real_param_1, bool param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  bool bVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  UInt8 *pVVar4;
  UInt8 *pIVar5;
  
  iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0x94)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + 0xb4)),
                     (VendorTransferBuffer *)(param_1),M<UInt32>(self + 0xc4),param_2);
  if ((iVar2 == 0) &&
     (iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0x94)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + 0x98)),(VendorTransferBuffer *)(param_1),M<UInt32>(self + 0xa8),
                         param_2), iVar2 == 0)) {
    iVar2 = 0;
    pVVar4 = (UInt8 *)(self + 0xcc);
    pIVar5 = self;
    while (iVar3 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0x94)))->freeTransferToAllocGART((VendorTransferBuffer *)(pVVar4),(VendorTransferBuffer *)(param_1),
                              M<UInt32>(pIVar5 + 0xdc),param_2), iVar3 == 0) {
      bVar1 = iVar2 == 1;
      pVVar4 = pVVar4 + 0x18;
      pIVar5 = pIVar5 + 0x18;
      iVar2 = iVar2 + 1;
      if (bVar1) {
        return 0;
      }
    }
  }
  return 1;
}
