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

  SInt32 iVar1;
  UInt32 bitmapWord;
  UInt32 bitIndex;
  SInt32 iVar4;
  UInt32 *bitmapCursor;
  UInt32 bit;
  UInt32 wordIndex;
  UInt32 handle;
  
  wordIndex = M<UInt32>(self + kIOATIR500Shared_handleHint) >> 5;
  do {
    if (wordIndex < M<UInt32>(self + kIOATIR500Shared_handleCapacity) >> 5) {
      iVar4 = wordIndex * 4;
      bitmapWord = M<UInt32>(M<SInt32>(self + kIOATIR500Shared_handleBitmap) + iVar4);
      if (bitmapWord != 0xffffffff) {
LAB_00016c4c:
        bitIndex = 0;
        iVar1 = 0x20;
        break;
      }
      iVar1 = (M<UInt32>(self + kIOATIR500Shared_handleCapacity) >> 5) - wordIndex;
      bitmapCursor = (UInt32 *)(M<SInt32>(self + kIOATIR500Shared_handleBitmap) + iVar4);
      while( true ) {
        iVar4 = iVar4 + 4;
        wordIndex = wordIndex + 1;
        iVar1 = iVar1 + -1;
        if (iVar1 == 0) break;
        bitmapCursor = bitmapCursor + 1;
        bitmapWord = *bitmapCursor;
        if (bitmapWord != 0xffffffff) goto LAB_00016c4c;
      }
    }
    iVar4 = this->alloc_handles();
    if (iVar4 == 0) {
      return 0;
    }
  } while( true );
  while( true ) {
    bit = bitIndex;
    if ((bitmapWord >> (bitIndex & 0x3f) & 1) == 0) goto LAB_00016c7c;
    bitIndex = bitIndex + 1;
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) break;
  }
  bit = 0x20;
LAB_00016c7c:
  handle = wordIndex * 0x20 + bitIndex;
  M<UInt32>(self + kIOATIR500Shared_handleHint) = handle + 1;
  M<void *>(handle * 4 + M<SInt32>(self + kIOATIR500Shared_handleTable)) = record;
  M<UInt32>(iVar4 + M<SInt32>(self + kIOATIR500Shared_handleBitmap)) =
       1 << (bit & 0x3f) | M<UInt32>(iVar4 + M<SInt32>(self + kIOATIR500Shared_handleBitmap));
  *outHandle = handle;
  return 1;
}
