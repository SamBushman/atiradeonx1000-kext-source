/*
 * IOATIR500Shared_alloc_handles_Port.cpp
 *
 * IOATIR500Shared::alloc_handles (real addr 0x16910, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFree(...) asm("_IOFree");
extern "C" UInt32 GH_IOMalloc(...) asm("_IOMalloc");
extern "C" UInt32 GH_memcpy(...) asm("_memcpy");
extern "C" UInt32 GH_memset(...) asm("_memset");


/* real addr 0x16910 */
bool IOATIR500Shared::alloc_handles() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 bitmapBytes;
  SInt32 newCapacity;
  SInt32 totalBytes;
  UInt32 oldCapacity;
  SInt32 oldTable;
  UInt32 oldBitmap;
  UInt32 result;
  SInt32 newTable;
  SInt32 acceleratorBytes;
  SInt32 tableBytes;
  SInt32 oldTotalBytes;
  SInt32 accelerator;
  
  oldCapacity = M<UInt32>(self + kIOATIR500Shared_handleCapacity);
  if (oldCapacity == 0) {
    newCapacity = 0x400;
    bitmapBytes = 0x80;
    tableBytes = 0x1000;
  }
  else {
    newCapacity = oldCapacity << 1;
    tableBytes = oldCapacity << 3;
    bitmapBytes = (oldCapacity & 0x7fffffff) >> 2;
  }
  totalBytes = tableBytes + bitmapBytes;
  oldTable = M<SInt32>(self + kIOATIR500Shared_handleTable);
  oldBitmap = M<UInt32>(self + kIOATIR500Shared_handleBitmap);
  newTable = GH_IOMalloc(totalBytes);
  M<SInt32>(self + kIOATIR500Shared_handleTable) = newTable;
  if (newTable == 0) {
    result = 0;
    M<SInt32>(self + kIOATIR500Shared_handleTable) = oldTable;
  }
  else {
    acceleratorBytes = M<SInt32>(self + kIOATIR500Shared_accelerator);
    if (acceleratorBytes != 0) {
      M<SInt32>(acceleratorBytes + kIOATIR500Accelerator_vendorTextureBufferBytes) = totalBytes + M<SInt32>(acceleratorBytes + kIOATIR500Accelerator_vendorTextureBufferBytes);
    }
    M<SInt32>(self + kIOATIR500Shared_handleCapacity) = newCapacity;
    M<SInt32>(self + kIOATIR500Shared_handleBitmap) = tableBytes + M<SInt32>(self + kIOATIR500Shared_handleTable);
    GH_memset(M<SInt32>(self + kIOATIR500Shared_handleTable),0,totalBytes);
    if (oldTable != 0) {
      oldTotalBytes = oldCapacity * 4 + (oldCapacity >> 3);
      GH_memcpy(M<UInt32>(self + kIOATIR500Shared_handleTable),oldTable,oldCapacity * 4);
      GH_memcpy(M<UInt32>(self + kIOATIR500Shared_handleBitmap),oldBitmap,oldCapacity >> 3);
      GH_IOFree(oldTable,oldTotalBytes);
      accelerator = M<SInt32>(self + kIOATIR500Shared_accelerator);
      if (accelerator != 0) {
        M<SInt32>(accelerator + kIOATIR500Accelerator_vendorTextureBufferBytes) = M<SInt32>(accelerator + kIOATIR500Accelerator_vendorTextureBufferBytes) - oldTotalBytes;
        return 1;
      }
    }
    result = 1;
  }
  return result;
}
