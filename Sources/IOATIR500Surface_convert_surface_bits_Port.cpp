/*
 * IOATIR500Surface_convert_surface_bits_Port.cpp
 *
 * IOATIR500Surface::convert_surface_bits (real addr 0x12320, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12320 */
UInt32 IOATIR500Surface::convert_surface_bits(UInt32 selectorBits) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 result;
  SInt32 formatSlot;
  UInt32 selectorBit;
  
  result = 0;
  if (selectorBits == 0) {
    return result;
  }
  selectorBit = 1;
  do {
    if ((selectorBit & selectorBits) == 0) goto LAB_00012454;
    if (selectorBit == 0x10) {
      formatSlot = 6;
LAB_00012420:
      result = result | 1 << ((M<SInt32>(self + formatSlot * 4 + 0xb70) - (SInt32)(self + kIOATIR500Surface_buffers)) / 0x78 & 0x3fU
                           );
    }
    else {
      if (0x10 < selectorBit) {
        if (selectorBit == 0x400) {
          formatSlot = 7;
        }
        else if (selectorBit < 0x401) {
          if (selectorBit == 0x80) {
            formatSlot = 2;
          }
          else {
            if (selectorBit != 0x100) goto LAB_00012454;
            formatSlot = 3;
          }
        }
        else if (selectorBit == 0x800) {
          formatSlot = 8;
        }
        else {
          if (selectorBit != 0x10000) goto LAB_00012454;
          formatSlot = 9;
        }
        goto LAB_00012420;
      }
      if (selectorBit == 2) {
        formatSlot = 0;
        goto LAB_00012420;
      }
      if (2 < selectorBit) {
        if (selectorBit == 4) {
          formatSlot = 4;
        }
        else {
          if (selectorBit != 8) goto LAB_00012454;
          formatSlot = 5;
        }
        goto LAB_00012420;
      }
      if (selectorBit == 1) {
        formatSlot = 1;
        goto LAB_00012420;
      }
    }
LAB_00012454:
    selectorBit = selectorBit << 1;
    if (selectorBits < selectorBit) {
      return result;
    }
  } while( true );
}
