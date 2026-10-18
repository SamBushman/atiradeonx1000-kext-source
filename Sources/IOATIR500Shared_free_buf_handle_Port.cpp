/*
 * IOATIR500Shared_free_buf_handle_Port.cpp
 *
 * IOATIR500Shared::free_buf_handle (real addr 0x16cf0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x16cf0 */
void IOATIR500Shared::free_buf_handle(void*record, UInt32 handle) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 bitmapOffset;
  
  if (M<UInt32>(self + kIOATIR500Shared_handleCapacity) <= handle) {
    return;
  }
  if (M<void *>(M<SInt32>(self + kIOATIR500Shared_handleTable) + handle * 4) != record) {
    return;
  }
  if (handle < M<UInt32>(self + kIOATIR500Shared_handleHint)) {
    M<UInt32>(self + kIOATIR500Shared_handleHint) = handle;
  }
  bitmapOffset = handle >> 3 & 0x1ffffffc;
  M<UInt32>(handle * 4 + M<SInt32>(self + kIOATIR500Shared_handleTable)) = 0;
  M<UInt32>(bitmapOffset + M<SInt32>(self + kIOATIR500Shared_handleBitmap)) =
       (-2 << (handle & 0x1f) | 0xfffffffeU >> 0x20 - (handle & 0x1f)) &
       M<UInt32>(bitmapOffset + M<SInt32>(self + kIOATIR500Shared_handleBitmap));
  return;
}
