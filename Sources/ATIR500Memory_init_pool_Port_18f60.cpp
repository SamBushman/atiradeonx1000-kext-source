/*
 * ATIR500Memory_init_pool_Port_18f60.cpp
 *
 * ATIR500Memory::init_pool (real addr 0x18f60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x18f60 */
bool ATIR500Memory::init_pool(UInt32 poolSize, UInt32 reservedOffset, UInt32 reservedSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 *newChunk;
  UInt32 result;
  SInt32 *chunkEnd;
  SInt32 *spareNode;
  SInt32 *nextSpare;
  SInt32 initOk;
  SInt32 chunk;
  SInt32 *poolNode;
  SInt32 *spareLink;
  
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
    poolNode = (SInt32 *)(chunk + 0x24);
    M<SInt32>(self + 8) = chunk + 4;
    chunkEnd = (SInt32 *)(chunk + 500);
    M<UInt32>(chunk + 0xc) = 0;
    M<UInt32>(chunk + 8) = 0;
    M<UInt32>(chunk + 0x10) = 0x80000000;
    M<SInt32>(chunk + 0x18) = chunk + 4;
    M<SInt32>(chunk + 4) = chunk + 0x14;
    M<UInt32>(chunk + 0x1c) = 0;
    M<UInt32>(chunk + 0x20) = 0;
    M<SInt32 *>(chunk + 0x14) = poolNode;
    if (reservedOffset != 0) {
      poolNode = (SInt32 *)(chunk + 0x34);
      M<SInt32>(chunk + 0x28) = chunk + 0x14;
      M<UInt32>(chunk + 0x2c) = 0;
      M<UInt32>(chunk + 0x30) = 0x80000000;
      M<SInt32 *>(chunk + 0x24) = poolNode;
    }
    spareNode = poolNode + 0xc;
    poolNode[2] = reservedOffset;
    poolNode[1] = (SInt32)(poolNode + -4);
    poolNode[3] = 0;
    poolNode[8] = 0;
    poolNode[5] = (SInt32)poolNode;
    *poolNode = (SInt32)(poolNode + 4);
    poolNode[9] = (SInt32)(poolNode + 4);
    poolNode[4] = (SInt32)(poolNode + 8);
    poolNode[6] = reservedOffset + reservedSize;
    poolNode[7] = -0x80000000;
    poolNode[10] = poolSize;
    poolNode[0xb] = 0;
    M<SInt32 *>(self + kATIR500Memory_spareNodeStack) = spareNode;
    poolNode[0xd] = 0;
    poolNode[0xe] = 0;
    poolNode[0xf] = 0;
    if (chunkEnd != spareNode) {
      spareLink = poolNode + 0x12;
      do {
        nextSpare = spareNode + 4;
        *spareLink = 0;
        spareLink[1] = 0;
        spareLink[-1] = 0;
        *spareNode = (SInt32)nextSpare;
        spareLink = spareLink + 4;
        spareNode = nextSpare;
      } while (chunkEnd != nextSpare);
    }
    result = 1;
    *chunkEnd = 0;
  }
  return result;
}
