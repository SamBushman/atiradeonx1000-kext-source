/*
 * track_regs_written_by_pm4_Port.cpp
 *
 * track_regs_written_by_pm4 (real addr 0x1b180, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



struct tracked_register_set;   /* opaque, see ATIRadeonX1000_StoreReg.cpp */
extern "C" void store_reg(tracked_register_set *state, UInt32 regIndex, UInt32 value) asm("__Z9store_regP20tracked_register_setmm");   /* real addr 0x1abe0, local symbol */
extern "C" void track_regs_written_by_pm4(tracked_register_set *state, UInt32 *rangeStart, UInt32 *rangeEnd) asm("__Z25track_regs_written_by_pm4P20tracked_register_setPmS1_");

/* real addr 0x1b180 */
extern "C" void track_regs_written_by_pm4(tracked_register_set *real_param_1, UInt32*param_2, UInt32*param_3) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 *puVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt32 uVar6;
  
  while (param_2 < param_3) {
    uVar6 = *param_2;
    uVar3 = uVar6 >> 0x1e;
    if (uVar3 == 1) {
      store_reg(real_param_1,uVar6 & 0x7ff,param_2[1]);
      puVar1 = param_2 + 2;
      param_2 = param_2 + 3;
      store_reg(real_param_1,uVar6 >> 0xb & 0x7ff,*puVar1);
    }
    else if (uVar3 == 0) {
      uVar2 = uVar6 >> 0x10 & 0x3fff;
      param_2 = param_2 + 1;
      uVar3 = uVar6 & 0x1fff;
      if ((uVar6 & 0x8000) == 0) {
        if (uVar2 != 0xffffffff) {
          iVar5 = 0;
          do {
            uVar4 = *param_2;
            iVar5 = iVar5 + 1;
            param_2 = param_2 + 1;
            store_reg(real_param_1,uVar3,uVar4);
            uVar3 = uVar3 + 1;
          } while (uVar2 + 1 != iVar5);
        }
      }
      else if (uVar2 != 0xffffffff) {
        iVar5 = 0;
        do {
          uVar4 = *param_2;
          iVar5 = iVar5 + 1;
          param_2 = param_2 + 1;
          store_reg(real_param_1,uVar3,uVar4);
        } while (uVar2 + 1 != iVar5);
      }
    }
    else if (uVar3 == 2) {
      param_2 = param_2 + 1;
    }
    else if (uVar3 == 3) {
      param_2 = (UInt32 *)((SInt32)param_2 + (uVar6 >> 0xe & 0xfffc) + 8);
    }
  }
  return;
}
