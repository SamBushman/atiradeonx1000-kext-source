/*
 * IOATIR500Shared_alloc_buf_handle_Port.cpp
 *
 * IOATIR500Shared::alloc_buf_handle (real addr 0x16bb0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x16bb0 */
bool IOATIR500Shared::alloc_buf_handle(void*record, UInt32*outHandle) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 bitmapWord;
  UInt32 bitIndex;
  SInt32 wordByteOffset;
  UInt32 *bitmapCursor;
  UInt32 bit;
  UInt32 wordIndex;
  UInt32 handle;
  SInt32 bitsLeft;
  SInt32 wordsLeft;
  
  wordIndex = M<UInt32>(self + kIOATIR500Shared_handleHint) >> 5;
  do {
    if (wordIndex < M<UInt32>(self + kIOATIR500Shared_handleCapacity) >> 5) {
      wordByteOffset = wordIndex * 4;
      bitmapWord = M<UInt32>(M<SInt32>(self + kIOATIR500Shared_handleBitmap) + wordByteOffset);
      if (bitmapWord != 0xffffffff) {
scanBitmapWord:
        bitIndex = 0;
        bitsLeft = 0x20;
        break;
      }
      wordsLeft = (M<UInt32>(self + kIOATIR500Shared_handleCapacity) >> 5) - wordIndex;
      bitmapCursor = (UInt32 *)(M<SInt32>(self + kIOATIR500Shared_handleBitmap) + wordByteOffset);
      while( true ) {
        wordByteOffset = wordByteOffset + 4;
        wordIndex = wordIndex + 1;
        wordsLeft = wordsLeft + -1;
        if (wordsLeft == 0) break;
        bitmapCursor = bitmapCursor + 1;
        bitmapWord = *bitmapCursor;
        if (bitmapWord != 0xffffffff) goto scanBitmapWord;
      }
    }
    wordByteOffset = this->alloc_handles();
    if (wordByteOffset == 0) {
      return 0;
    }
  } while( true );
  while( true ) {
    bit = bitIndex;
    if ((bitmapWord >> (bitIndex & 0x3f) & 1) == 0) goto claimHandle;
    bitIndex = bitIndex + 1;
    bitsLeft = bitsLeft + -1;
    if (bitsLeft == 0) break;
  }
  bit = 0x20;
claimHandle:
  handle = wordIndex * 0x20 + bitIndex;
  M<UInt32>(self + kIOATIR500Shared_handleHint) = handle + 1;
  M<void *>(handle * 4 + M<SInt32>(self + kIOATIR500Shared_handleTable)) = record;
  M<UInt32>(wordByteOffset + M<SInt32>(self + kIOATIR500Shared_handleBitmap)) =
       1 << (bit & 0x3f) | M<UInt32>(wordByteOffset + M<SInt32>(self + kIOATIR500Shared_handleBitmap));
  *outHandle = handle;
  return 1;
}
