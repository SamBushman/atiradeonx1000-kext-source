/*
 * ATIR500Memory_add_to_stack_Port.cpp
 *
 * ATIR500Memory::add_to_stack (real addr 0x191b0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");


/* real addr 0x191b0 */
bool ATIR500Memory::add_to_stack() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  UInt32 *puVar2;
  UInt32 *puVar3;
  UInt32 *puVar4;
  SInt32 iVar5;
  
  puVar2 = (UInt32 *)GH_IOMallocAligned(0x204,0x20);
  uVar1 = 0;
  if (puVar2 != (UInt32 *)0x0) {
    puVar4 = puVar2 + 1;
    *puVar2 = M<UInt32>(self + 0x10);
    M<UInt32 *>(self + 0xc) = puVar4;
    M<UInt32 *>(self + 0x10) = puVar2;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    if (puVar4 != puVar2 + 0x7d) {
      puVar3 = puVar2 + 7;
      iVar5 = 0x1f;
      do {
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[-1] = 0;
        *puVar4 = (UInt32)(puVar4 + 4);
        puVar3 = puVar3 + 4;
        iVar5 = iVar5 + -1;
        puVar4 = puVar4 + 4;
      } while (iVar5 != 0);
    }
    uVar1 = 1;
    puVar2[0x7d] = 0;
  }
  return uVar1;
}
