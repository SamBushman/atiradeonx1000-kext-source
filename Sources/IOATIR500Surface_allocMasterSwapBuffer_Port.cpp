/*
 * IOATIR500Surface_allocMasterSwapBuffer_Port.cpp
 *
 * IOATIR500Surface::allocMasterSwapBuffer (real addr 0x118e0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x118e0 */
bool IOATIR500Surface::allocMasterSwapBuffer(UInt32 param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *piVar1;
  VendorSwapBufferHeader *pVVar2;
  SInt32 iVar3;
  SInt32 iVar4;
  UInt32 uVar5;
  UInt8 *pIVar6;
  
  iVar4 = param_1 * 0x94;
  M<UInt32>(self + iVar4 + 0xcb0) = 0;
  iVar3 = M<SInt32>(self + 0xd50);
  if (M<SInt32>(param_1 * 4 + iVar3 + 0x114) != 0) {
    uVar5 = 0;
    pIVar6 = self + iVar4 + 0xc28;
    do {
      piVar1 = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(M<UInt32>(iVar3 + 0x82c) | 0x10023,param_2,GH_page_size);
      M<SInt32 *>(pIVar6) = piVar1;
      if (piVar1 == (SInt32 *)0x0) {
        return 0;
      }
      uVar5 = uVar5 + 1;
      pVVar2 = (VendorSwapBufferHeader *)VCALL(*piVar1, 0x1cc)(piVar1);
      M<VendorSwapBufferHeader *>(pIVar6 + 0xc) = pVVar2;
      pIVar6 = pIVar6 + 0x1c;
      this->init_swap_buffer_header((VendorSwapBufferHeader *)(pVVar2),param_2);
      iVar3 = M<SInt32>(self + 0xd50);
    } while (uVar5 < M<UInt32>(param_1 * 4 + iVar3 + 0x114));
  }
  M<UInt32>(self + iVar4 + 0xcb0) = param_2;
  return 1;
}
