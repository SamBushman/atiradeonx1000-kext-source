/*
 * ATIR500Memory_init_pool_Port.cpp
 *
 * ATIR500Memory::init_pool (real addr 0x18e00, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");


/* real addr 0x18e00 */
bool ATIR500Memory::init_pool(UInt32 poolSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 *spareLink;
  UInt32 result;
  SInt32 nodesLeft;
  SInt32 initOk;
  SInt32 chunk;
  UInt32 *newChunk;
  UInt32 *spareNode;
  
  initOk = VCALL(M<SInt32>(self), 0x48)(self);
  if (initOk == 0) {
initFailed:
    result = 0;
  }
  else {
    chunk = M<SInt32>(self + kATIR500Memory_chunkList);
    M<UInt32>(self + kATIR500Memory_spareNodeStack) = 0;
    M<UInt32>(self + 8) = 0;
    if (chunk == 0) {
      newChunk = (UInt32 *)GH_IOMallocAligned(0x204,0x20);
      M<UInt32 *>(self + kATIR500Memory_chunkList) = newChunk;
      if (newChunk != (UInt32 *)0x0) {
        *newChunk = 0;
      }
      chunk = M<SInt32>(self + kATIR500Memory_chunkList);
      if (chunk == 0) goto initFailed;
    }
    spareNode = (UInt32 *)(chunk + 0x44);
    M<SInt32>(self + 8) = chunk + 4;
    M<UInt32>(chunk + 0xc) = 0;
    M<UInt32>(chunk + 8) = 0;
    M<UInt32>(chunk + 0x1c) = 0;
    M<SInt32>(chunk + 0x18) = chunk + 4;
    M<UInt32>(chunk + 0x2c) = 0;
    M<SInt32>(chunk + 0x28) = chunk + 0x14;
    M<UInt32>(chunk + 0x3c) = poolSize;
    M<SInt32>(chunk + 0x38) = chunk + 0x24;
    M<SInt32>(chunk + 4) = chunk + 0x14;
    M<SInt32>(chunk + 0x14) = chunk + 0x24;
    M<SInt32>(chunk + 0x24) = chunk + 0x34;
    M<UInt32>(chunk + 0x34) = 0;
    M<UInt32>(chunk + 0x10) = 0x80000000;
    M<UInt32>(chunk + 0x20) = 0;
    M<UInt32>(chunk + 0x30) = 0x80000000;
    M<UInt32>(chunk + 0x40) = 0;
    M<UInt32 *>(self + kATIR500Memory_spareNodeStack) = spareNode;
    M<UInt32>(chunk + 0x48) = 0;
    M<UInt32>(chunk + 0x4c) = 0;
    M<UInt32>(chunk + 0x50) = 0;
    if ((UInt32 *)(chunk + 500) != spareNode) {
      spareLink = (UInt32 *)(chunk + 0x5c);
      nodesLeft = 0x1b;
      do {
        *spareLink = 0;
        spareLink[1] = 0;
        spareLink[-1] = 0;
        *spareNode = (UInt32)(spareNode + 4);
        spareLink = spareLink + 4;
        nodesLeft = nodesLeft + -1;
        spareNode = spareNode + 4;
      } while (nodesLeft != 0);
    }
    result = 1;
    M<UInt32>(chunk + 500) = 0;
  }
  return result;
}
