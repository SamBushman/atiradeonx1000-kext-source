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
extern "C" void track_regs_written_by_pm4(tracked_register_set *state, UInt32*rangeStart, UInt32*rangeEnd) {
    UInt8 *stateBytes = reinterpret_cast<UInt8 *>(state);

  UInt32 *secondValue;
  UInt32 countMinusOne;
  UInt32 reg;
  UInt32 value;
  SInt32 written;
  UInt32 header;
  UInt32 packetType;
  
  while (rangeStart < rangeEnd) {
    header = *rangeStart;
    packetType = header >> 0x1e;
    if (packetType == 1) {
      store_reg(state,header & 0x7ff,rangeStart[1]);
      secondValue = rangeStart + 2;
      rangeStart = rangeStart + 3;
      store_reg(state,header >> 0xb & 0x7ff,*secondValue);
    }
    else if (packetType == 0) {
      countMinusOne = header >> 0x10 & 0x3fff;
      rangeStart = rangeStart + 1;
      reg = header & 0x1fff;
      if ((header & 0x8000) == 0) {
        if (countMinusOne != 0xffffffff) {
          written = 0;
          do {
            value = *rangeStart;
            written = written + 1;
            rangeStart = rangeStart + 1;
            store_reg(state,reg,value);
            reg = reg + 1;
          } while (countMinusOne + 1 != written);
        }
      }
      else if (countMinusOne != 0xffffffff) {
        written = 0;
        do {
          value = *rangeStart;
          written = written + 1;
          rangeStart = rangeStart + 1;
          store_reg(state,reg,value);
        } while (countMinusOne + 1 != written);
      }
    }
    else if (packetType == 2) {
      rangeStart = rangeStart + 1;
    }
    else if (packetType == 3) {
      rangeStart = (UInt32 *)((SInt32)rangeStart + (header >> 0xe & 0xfffc) + 8);
    }
  }
  return;
}
