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
UInt32 IOATIR500Surface::convert_surface_bits(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  SInt32 iVar2;
  UInt32 uVar3;
  
  uVar1 = 0;
  if (param_1 == 0) {
    return uVar1;
  }
  uVar3 = 1;
  do {
    if ((uVar3 & param_1) == 0) goto LAB_00012454;
    if (uVar3 == 0x10) {
      iVar2 = 6;
LAB_00012420:
      uVar1 = uVar1 | 1 << ((M<SInt32>(self + iVar2 * 4 + 0xb70) - (SInt32)(self + 0xa8)) / 0x78 & 0x3fU
                           );
    }
    else {
      if (0x10 < uVar3) {
        if (uVar3 == 0x400) {
          iVar2 = 7;
        }
        else if (uVar3 < 0x401) {
          if (uVar3 == 0x80) {
            iVar2 = 2;
          }
          else {
            if (uVar3 != 0x100) goto LAB_00012454;
            iVar2 = 3;
          }
        }
        else if (uVar3 == 0x800) {
          iVar2 = 8;
        }
        else {
          if (uVar3 != 0x10000) goto LAB_00012454;
          iVar2 = 9;
        }
        goto LAB_00012420;
      }
      if (uVar3 == 2) {
        iVar2 = 0;
        goto LAB_00012420;
      }
      if (2 < uVar3) {
        if (uVar3 == 4) {
          iVar2 = 4;
        }
        else {
          if (uVar3 != 8) goto LAB_00012454;
          iVar2 = 5;
        }
        goto LAB_00012420;
      }
      if (uVar3 == 1) {
        iVar2 = 1;
        goto LAB_00012420;
      }
    }
LAB_00012454:
    uVar3 = uVar3 << 1;
    if (param_1 < uVar3) {
      return uVar1;
    }
  } while( true );
}
