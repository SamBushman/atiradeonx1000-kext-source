/*
 * ATIR500Memory_dealloc_Port.cpp
 *
 * ATIR500Memory::dealloc (real addr 0x197d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x197d0 */
UInt32 ATIR500Memory::dealloc(GLKMemoryElement *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 *puVar1;
  SInt32 iVar2;
  SInt32 *piVar3;
  SInt32 *piVar4;
  SInt32 iVar5;
  
  iVar5 = M<SInt32>(param_1 + 8);
  if ((M<SInt32>(self + 0xc) == 0) && (iVar2 = this->add_to_stack(), iVar2 == 0)) {
    return 0;
  }
  piVar3 = M<SInt32 *>(param_1 + 4);
  piVar4 = M<SInt32 *>(param_1);
  M<UInt32>(param_1 + 0xc) = 0;
  M<UInt32>(param_1 + 4) = 0;
  M<UInt32>(param_1) = 0;
  M<UInt32>(param_1 + 8) = 0;
  if ((piVar3[3] & piVar4[3]) < 0) {
    *piVar3 = *piVar4;
    M<SInt32 *>(*piVar4 + 4) = piVar3;
    iVar5 = M<SInt32>(self + 0xc);
    piVar4[3] = 0;
    piVar4[1] = 0;
    piVar4[2] = 0;
    *piVar4 = iVar5;
    M<SInt32 *>(self + 0xc) = piVar4;
  }
  else if (piVar3[3] < 0) {
    piVar4[1] = (SInt32)piVar3;
    *piVar3 = (SInt32)piVar4;
  }
  else if (piVar4[3] < 0) {
    piVar4[2] = iVar5;
    piVar4[1] = (SInt32)piVar3;
    *piVar3 = (SInt32)piVar4;
  }
  else {
    puVar1 = M<UInt32 *>(self + 0xc);
    M<UInt32>(self + 0xc) = *puVar1;
    *piVar3 = (SInt32)puVar1;
    piVar4[1] = (SInt32)puVar1;
    puVar1[3] = 0x80000000;
    puVar1[2] = iVar5;
    *puVar1 = (UInt32)(piVar4);
    puVar1[1] = (UInt32)(piVar3);
  }
  return 1;
}
