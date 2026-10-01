/*
 * IOATIR500Accelerator_removeFromGART_Port.cpp
 *
 * IOATIR500Accelerator::removeFromGART (real addr 0x5270, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x5270 */
void IOATIR500Accelerator::removeFromGART(IOMemoryDescriptor*param_1, UInt32 param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  unsigned int uVar1;
  int iVar2;
  int iVar3;
  unsigned int uVar4;
  
  uVar4 = param_2 >> (GH_page_shift & 0x3f);
  if (param_1 != 0) {
    uVar1 = VCALL(M<int>(param_1), 0x128)(param_1);
    uVar1 = uVar4 + (uVar1 >> (GH_page_shift & 0x3f));
    iVar3 = uVar1 - uVar4;
    M<int>(self + 0x718) = (iVar3 << (GH_page_shift & 0x3f)) + M<int>(self + 0x718);
    M<int>(self + 0xa0) = M<int>(self + 0xa0) - (iVar3 << (GH_page_shift & 0x3f));
    if (uVar4 < uVar1) {
      iVar2 = uVar4 << 2;
      do {
        M<UInt32>(M<int>(self + 0x83c) + iVar2) = M<UInt32>(self + 0x844);
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    if (((M<unsigned int>(self + 0x98) & 2) != 0) &&
       (uVar4 = param_2 >> (GH_page_shift & 0x3f), uVar4 < uVar1)) {
      do {
        iVar3 = uVar4 << (GH_page_shift & 0x3f);
        uVar4 = uVar4 + 1;
        VCALL(M<int>(self), 0x588)(self,M<UInt32>(self + 0x22c),iVar3,0);
      } while (uVar4 != uVar1);
    }
    uVar4 = param_2 >> (GH_page_shift & 0x3f);
    VCALL(M<int>(self), 0x59c)(self,uVar4,uVar1 - uVar4);
    VCALL(M<int>(param_1), 0x148)(param_1,3);
  }
  return;
}
