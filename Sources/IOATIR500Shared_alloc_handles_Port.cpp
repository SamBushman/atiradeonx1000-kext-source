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
  SInt32 iVar2;
  UInt32 uVar3;
  SInt32 newCapacity;
  SInt32 iVar5;
  SInt32 totalBytes;
  UInt32 oldCapacity;
  SInt32 oldTable;
  
  oldCapacity = M<UInt32>(self + 0x14);
  if (oldCapacity == 0) {
    newCapacity = 0x400;
    bitmapBytes = 0x80;
    iVar5 = 0x1000;
  }
  else {
    newCapacity = oldCapacity << 1;
    iVar5 = oldCapacity << 3;
    bitmapBytes = (oldCapacity & 0x7fffffff) >> 2;
  }
  totalBytes = iVar5 + bitmapBytes;
  oldTable = M<SInt32>(self + 0x10);
  uVar3 = M<UInt32>(self + 0x18);
  iVar2 = GH_IOMalloc(totalBytes);
  M<SInt32>(self + 0x10) = iVar2;
  if (iVar2 == 0) {
    uVar3 = 0;
    M<SInt32>(self + 0x10) = oldTable;
  }
  else {
    iVar2 = M<SInt32>(self + 0xc);
    if (iVar2 != 0) {
      M<SInt32>(iVar2 + 0x808) = totalBytes + M<SInt32>(iVar2 + 0x808);
    }
    M<SInt32>(self + 0x14) = newCapacity;
    M<SInt32>(self + 0x18) = iVar5 + M<SInt32>(self + 0x10);
    GH_memset(M<SInt32>(self + 0x10),0,totalBytes);
    if (oldTable != 0) {
      iVar5 = oldCapacity * 4 + (oldCapacity >> 3);
      GH_memcpy(M<UInt32>(self + 0x10),oldTable,oldCapacity * 4);
      GH_memcpy(M<UInt32>(self + 0x18),uVar3,oldCapacity >> 3);
      GH_IOFree(oldTable,iVar5);
      newCapacity = M<SInt32>(self + 0xc);
      if (newCapacity != 0) {
        M<SInt32>(newCapacity + 0x808) = M<SInt32>(newCapacity + 0x808) - iVar5;
        return 1;
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}
