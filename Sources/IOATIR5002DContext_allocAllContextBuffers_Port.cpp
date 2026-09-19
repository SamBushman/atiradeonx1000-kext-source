/*
 * IOATIR5002DContext_allocAllContextBuffers_Port.cpp
 *
 * IOATIR5002DContext::allocAllContextBuffers (real addr 0xbee0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(...) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj");


/* real addr 0xbee0 */
bool IOATIR5002DContext::allocAllContextBuffers(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 *piVar2;
  VendorContextBufferHeader *pVVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt8 *pIVar7;
  
  piVar2 = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(0x10023,param_1,GH_page_size);
  uVar4 = 0;
  M<SInt32 *>(self + 0xbc) = piVar2;
  if (piVar2 != (SInt32 *)0x0) {
    iVar6 = 0;
    pVVar3 = (VendorContextBufferHeader *)VCALL(*piVar2, 0x1cc)(piVar2);
    M<VendorContextBufferHeader *>(self + 200) = pVVar3;
    this->init_context_buffer_header((VendorContextBufferHeader *)(pVVar3),param_1);
    pIVar7 = self;
    do {
      piVar2 = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(M<UInt32>(M<SInt32>(self + 0x94) + 0x82c) | 0x10023,param_1,
                                   GH_page_size);
      M<SInt32 *>(pIVar7 + 0xd4) = piVar2;
      if (piVar2 == (SInt32 *)0x0) {
        if (-1 < iVar6 + -1) {
          iVar5 = 0;
          pIVar7 = self + (iVar6 + -1) * 0x18 + 0xd4;
          do {
            iVar5 = iVar5 + 1;
            VCALL(*M<SInt32 *>(pIVar7), 0x18)(M<SInt32 *>(pIVar7));
            M<UInt32>(pIVar7 + -8) = 0;
            M<UInt32>(pIVar7 + -4) = 0;
            M<UInt32>(pIVar7) = 0;
            M<UInt16>(pIVar7 + 6) = 0;
            M<UInt16>(pIVar7 + 4) = 0;
            M<UInt32>(pIVar7 + 8) = 0;
            M<UInt32>(pIVar7 + 0xc) = 0;
            pIVar7 = pIVar7 + -0x18;
          } while (iVar5 != iVar6);
        }
        VCALL(*M<SInt32 *>(self + 0xbc), 0x18)(M<SInt32 *>(self + 0xbc));
        M<UInt32>(self + 200) = 0;
        M<UInt32>(self + 0xb4) = 0;
        M<UInt32>(self + 0xb8) = 0;
        M<UInt32>(self + 0xbc) = 0;
        M<UInt16>(self + 0xc2) = 0;
        M<UInt16>(self + 0xc0) = 0;
        M<UInt32>(self + 0xc4) = 0;
        return 0;
      }
      pVVar3 = (VendorContextBufferHeader *)VCALL(*piVar2, 0x1cc)(piVar2);
      M<VendorContextBufferHeader *>(pIVar7 + 0xe0) = pVVar3;
      pIVar7 = pIVar7 + 0x18;
      this->init_context_buffer_header((VendorContextBufferHeader *)(pVVar3),param_1);
      bVar1 = iVar6 != 1;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    uVar4 = 1;
  }
  return uVar4;
}
