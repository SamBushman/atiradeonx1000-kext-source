/*
 * HZMEM_GetBlockCount_Port.cpp
 *
 * HZMEM_GetBlockCount (real addr 0x45810, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x45810 */
UInt32 HZMEM_GetBlockCount(_HZDATA *hizData, UInt32 surfaceHzField, UInt32 blockKind) {
    UInt8 *hizDataBytes = reinterpret_cast<UInt8 *>(hizData);

  UInt32 blockIndex;
  SInt32 block;
  
  if ((hizDataBytes != (UInt8 *)0x0) && (M<SInt32>(hizDataBytes + blockKind * 4 + 0x10) != 0)) {
    if (blockKind == 1) {
      blockIndex = surfaceHzField >> 10 & 0x3ff;
    }
    else {
      blockIndex = surfaceHzField & 0x3ff;
      if (blockKind != 0) {
        if (blockKind != 2) {
          return 1;
        }
        blockIndex = surfaceHzField >> 0x14 & 0x3ff;
      }
    }
    if (blockIndex != 0x3ff) {
      block = blockIndex * 0x10 + M<SInt32>(hizDataBytes + blockKind * 4 + 0x10);
      if (block != -0x14) {
        return *(UInt32 *)(block + 0x1c);
      }
      return 0xfffffffe;
    }
  }
  return 1;
}
