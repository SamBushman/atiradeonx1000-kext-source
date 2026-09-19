/*
 * IOATIR500Surface_connect_buffer_backing_store_Port.cpp
 *
 * IOATIR500Surface::connect_buffer_backing_store (real addr 0x12800, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(...) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");


/* real addr 0x12800 */
bool IOATIR500Surface::connect_buffer_backing_store(ATIR500SurfaceBuffer *real_param_1, unsigned int param_2, UInt32 param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt8 *pIVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  
  uVar3 = GH_page_size - 1U & param_2;
  uVar2 = -GH_page_size & (GH_page_size + M<UInt16>(param_1 + 0x1e) * param_3 + uVar3) - 1
  ;
  if (M<UInt32>(self + 0xd4c) != 0) {
    uVar2 = M<UInt32>(self + 0xd4c);
  }
  pIVar1 = (UInt8 *)
           GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(param_2 & -GH_page_size,uVar2,0x10003,M<UInt32>(self + 0x78));
  if (pIVar1 != (UInt8 *)0x0) {
    VCALL(M<SInt32>(pIVar1), 0xdc)(pIVar1,2,0);
    this->attach_buffer_backing_store((ATIR500SurfaceBuffer *)(param_1),(IOMemoryDescriptor *)(pIVar1),uVar3,param_3);
    M<UInt8>(M<SInt32>(param_1 + 0x24) + 0x59) = 1;
  }
  return pIVar1 != (UInt8 *)0x0;
}
