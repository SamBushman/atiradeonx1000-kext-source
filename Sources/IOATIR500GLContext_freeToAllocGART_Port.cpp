/*
 * IOATIR500GLContext_freeToAllocGART_Port.cpp
 *
 * IOATIR500GLContext::freeToAllocGART (real addr 0x7a50, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x7a50 */
bool IOATIR500GLContext::freeToAllocGART(VendorTransferBuffer *real_param_1, bool param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  bool bVar1;
  SInt32 iVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  UInt8 *pIVar5;
  UInt8 *pVVar6;
  
  iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + 0xf4)),
                     (VendorTransferBuffer *)(param_1),M<UInt32>(self + 0x104),param_2);
  if ((iVar2 == 0) &&
     (iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeTransferToAllocGART((VendorTransferBuffer *)((UInt8 *)(self + 0xcc)),(VendorTransferBuffer *)(param_1),M<UInt32>(self + 0xdc),
                         param_2), iVar2 == 0)) {
    iVar2 = 0;
    pVVar6 = (UInt8 *)(self + 0x10c);
    pIVar5 = self;
    do {
      iVar3 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeTransferToAllocGART((VendorTransferBuffer *)(pVVar6),(VendorTransferBuffer *)(param_1),
                         M<UInt32>(pIVar5 + 0x11c),param_2);
      if (iVar3 != 0) goto LAB_00007b30;
      bVar1 = iVar2 != 0xf;
      pVVar6 = pVVar6 + 0x18;
      pIVar5 = pIVar5 + 0x18;
      iVar2 = iVar2 + 1;
    } while (bVar1);
    for (pVVar6 = M<UInt8 *>(self + 0xe8); pVVar6 != (UInt8 *)0x0;
        pVVar6 = M<UInt8 *>(pVVar6 + 0x3c)) {
      iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->freeTransferToAllocGART((VendorTransferBuffer *)(pVVar6),(VendorTransferBuffer *)(param_1),
                         M<UInt32>(pVVar6 + 0x5c),param_2);
      if (iVar2 != 0) goto LAB_00007b30;
    }
    uVar4 = 0;
  }
  else {
LAB_00007b30:
    uVar4 = 1;
  }
  return uVar4;
}
