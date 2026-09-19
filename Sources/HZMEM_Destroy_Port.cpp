/*
 * HZMEM_Destroy_Port.cpp
 *
 * HZMEM_Destroy (real addr 0x45280, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFreePageable(...) asm("_IOFreePageable");
extern "C" UInt32 GH_bzero(...) asm("_bzero");


/* real addr 0x45280 */
UInt32 HZMEM_Destroy(_HZDATA *real_param_1) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  unsigned int uVar1;
  UInt32 uVar2;
  UInt32 *puVar3;
  unsigned int uVar4;
  UInt8 *p_Var5;
  
  uVar2 = 1;
  if (param_1 != (UInt8 *)0x0) {
    uVar1 = M<unsigned int>(param_1 + 0xc);
    if (uVar1 != 0) {
      uVar4 = 0;
      p_Var5 = param_1;
      do {
        puVar3 = M<UInt32 *>(p_Var5 + 0x10);
        if (puVar3 != (UInt32 *)0x0) {
          if (puVar3[3] != 0) {
            GH_IOFreePageable(puVar3[3],*puVar3);
            puVar3 = M<UInt32 *>(p_Var5 + 0x10);
          }
          GH_IOFreePageable(puVar3,0x1014);
          uVar1 = M<unsigned int>(param_1 + 0xc);
        }
        uVar4 = uVar4 + 1;
        p_Var5 = p_Var5 + 4;
      } while (uVar4 < uVar1);
    }
    GH_bzero(param_1,0x1c);
    uVar2 = 0;
  }
  return uVar2;
}
