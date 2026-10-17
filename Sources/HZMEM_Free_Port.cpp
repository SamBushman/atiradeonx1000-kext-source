/*
 * HZMEM_Free_Port.cpp
 *
 * HZMEM_Free (real addr 0x45680, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x45680 */
UInt32 HZMEM_Free(_HZDATA *hizData, UInt32 surfaceHzField, UInt32 blockKind) {
    UInt8 *hizDataBytes = reinterpret_cast<UInt8 *>(hizData);

  UInt32 blockIndex;
  SInt32 unitsLeft;
  UInt8 *bitmapCursor;
  UInt32 startUnit;
  UInt32 uVar5;
  UInt32 *pool;
  
  if (hizDataBytes != (UInt8 *)0x0) {
    pool = M<UInt32 *>(hizDataBytes + blockKind * 4 + 0x10);
    if (pool != (UInt32 *)0x0) {
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
      if ((blockIndex != 0x3ff) && (pool + blockIndex * 4 + 5 != (UInt32 *)0x0)) {
        uVar5 = pool[1];
        if (uVar5 == 0) {
          startUnit = 0;
          uVar5 = 0;
        }
        else {
          startUnit = pool[blockIndex * 4 + 6] / uVar5;
          uVar5 = startUnit + pool[blockIndex * 4 + 7] / uVar5;
          if (*pool < uVar5) {
            return 1;
          }
        }
        if (pool[3] != 0) {
          if (startUnit < uVar5) {
            unitsLeft = uVar5 - startUnit;
            bitmapCursor = (UInt8 *)(startUnit + pool[3]);
            do {
              *bitmapCursor = 0;
              bitmapCursor = bitmapCursor + 1;
              unitsLeft = unitsLeft + -1;
            } while (unitsLeft != 0);
          }
          pool[blockIndex * 4 + 5] = 0;
          M<SInt32>(M<SInt32>(hizDataBytes + blockKind * 4 + 0x10) + 0x10) =
               M<SInt32>(M<SInt32>(hizDataBytes + blockKind * 4 + 0x10) + 0x10) + -1;
          return 0;
        }
      }
    }
  }
  return 1;
}
