/*
 * ATIR500GLContext_setCompatibleSurfaceMode_Port.cpp
 *
 * ATIR500GLContext::setCompatibleSurfaceMode (real addr 0x270a0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x270a0 */
bool ATIR500GLContext::setCompatibleSurfaceMode(SInt32*modeBits, eIOGLContextModeBits mode, SInt32 flags) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 baseResult;
  UInt32 mergedBits;
  UInt32 currentBits;
  UInt32 bitsToMerge;
  UInt32 *modeBitsWords = reinterpret_cast<UInt32 *>(modeBits);
  UInt32 modeValue = (UInt32)mode;
  UInt32 flagsValue = (UInt32)flags;
  
  baseResult = IOATIR500GLContext::setCompatibleSurfaceMode(modeBits, mode, flags);
  if (baseResult == 0) {
    currentBits = *modeBitsWords;
    mergedBits = currentBits & 0xffff7fc0;
    if ((flagsValue & 0x40) == 0) {
      mergedBits = modeValue & 0x30000 | currentBits & 0xfffc7fc0;
    }
    else {
      bitsToMerge = modeValue & 0x30000;
      if ((currentBits & 0x30000) != bitsToMerge) {
        if (((currentBits & 0x30000) != 0) && (bitsToMerge != 0)) {
          return 0;
        }
        mergedBits = mergedBits | bitsToMerge;
      }
    }
    if ((flagsValue & 0x200) == 0) {
      mergedBits = modeValue & 0x7c0000 | mergedBits & 0xff83ffff;
    }
    else {
      bitsToMerge = modeValue & 0x700000;
      if ((mergedBits & 0x700000) != bitsToMerge) {
        if (((mergedBits & 0x700000) != 0) && (bitsToMerge != 0)) {
          return 0;
        }
        mergedBits = mergedBits | bitsToMerge;
      }
      bitsToMerge = modeValue & 0xc0000;
      if ((mergedBits & 0xc0000) != bitsToMerge) {
        if (((mergedBits & 0xc0000) != 0) && (bitsToMerge != 0)) {
          return 0;
        }
        mergedBits = mergedBits | bitsToMerge;
      }
    }
    if ((mergedBits & 0xfffcffff) == (modeValue & 0xfffcc03f)) {
      *modeBitsWords = mergedBits | currentBits & 0x803f | modeValue & 0x30000;
      return 1;
    }
  }
  return 1;
}
