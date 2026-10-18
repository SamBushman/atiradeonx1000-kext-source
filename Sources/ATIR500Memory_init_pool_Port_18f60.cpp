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

  SInt32 iVar1;
  UInt32 *newChunk;
  UInt32 result;
  SInt32 *chunkEnd;
  SInt32 *piVar5;
  SInt32 *piVar7;
  SInt32 *piVar6;
  
  iVar1 = VCALL(M<SInt32>(self), 0x48)(self);
  if (iVar1 == 0) {
LAB_000190f0:
    result = 0;
  }
  else {
    iVar1 = M<SInt32>(self + kATIR500Memory_chunkList);
    M<UInt32>(self + kATIR500Memory_spareNodeStack) = 0;
    M<UInt32>(self + 8) = 0;
    if (iVar1 == 0) {
      newChunk = (UInt32 *)GH_IOMallocAligned(0x204,0x20);
      M<UInt32 *>(self + kATIR500Memory_chunkList) = newChunk;
      if (newChunk != (UInt32 *)0x0) {
        *newChunk = 0;
      }
      iVar1 = M<SInt32>(self + kATIR500Memory_chunkList);
      if (iVar1 == 0) goto LAB_000190f0;
    }
    piVar7 = (SInt32 *)(iVar1 + 0x24);
    M<SInt32>(self + 8) = iVar1 + 4;
    chunkEnd = (SInt32 *)(iVar1 + 500);
    M<UInt32>(iVar1 + 0xc) = 0;
    M<UInt32>(iVar1 + 8) = 0;
    M<UInt32>(iVar1 + 0x10) = 0x80000000;
    M<SInt32>(iVar1 + 0x18) = iVar1 + 4;
    M<SInt32>(iVar1 + 4) = iVar1 + 0x14;
    M<UInt32>(iVar1 + 0x1c) = 0;
    M<UInt32>(iVar1 + 0x20) = 0;
    M<SInt32 *>(iVar1 + 0x14) = piVar7;
    if (reservedOffset != 0) {
      piVar7 = (SInt32 *)(iVar1 + 0x34);
      M<SInt32>(iVar1 + 0x28) = iVar1 + 0x14;
      M<UInt32>(iVar1 + 0x2c) = 0;
      M<UInt32>(iVar1 + 0x30) = 0x80000000;
      M<SInt32 *>(iVar1 + 0x24) = piVar7;
    }
    piVar5 = piVar7 + 0xc;
    piVar7[2] = reservedOffset;
    piVar7[1] = (SInt32)(piVar7 + -4);
    piVar7[3] = 0;
    piVar7[8] = 0;
    piVar7[5] = (SInt32)piVar7;
    *piVar7 = (SInt32)(piVar7 + 4);
    piVar7[9] = (SInt32)(piVar7 + 4);
    piVar7[4] = (SInt32)(piVar7 + 8);
    piVar7[6] = reservedOffset + reservedSize;
    piVar7[7] = -0x80000000;
    piVar7[10] = poolSize;
    piVar7[0xb] = 0;
    M<SInt32 *>(self + kATIR500Memory_spareNodeStack) = piVar5;
    piVar7[0xd] = 0;
    piVar7[0xe] = 0;
    piVar7[0xf] = 0;
    if (chunkEnd != piVar5) {
      piVar7 = piVar7 + 0x12;
      do {
        piVar6 = piVar5 + 4;
        *piVar7 = 0;
        piVar7[1] = 0;
        piVar7[-1] = 0;
        *piVar5 = (SInt32)piVar6;
        piVar7 = piVar7 + 4;
        piVar5 = piVar6;
      } while (chunkEnd != piVar6);
    }
    result = 1;
    *chunkEnd = 0;
  }
  return result;
}
