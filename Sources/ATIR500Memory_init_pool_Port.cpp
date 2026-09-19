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
bool ATIR500Memory::init_pool(UInt32 param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 *puVar1;
  SInt32 iVar2;
  UInt32 *puVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  
  iVar2 = VCALL(M<SInt32>(self), 0x48)(self);
  if (iVar2 == 0) {
LAB_00018f2c:
    uVar4 = 0;
  }
  else {
    iVar2 = M<SInt32>(self + 0x10);
    M<UInt32>(self + 0xc) = 0;
    M<UInt32>(self + 8) = 0;
    if (iVar2 == 0) {
      puVar3 = (UInt32 *)GH_IOMallocAligned(0x204,0x20);
      M<UInt32 *>(self + 0x10) = puVar3;
      if (puVar3 != (UInt32 *)0x0) {
        *puVar3 = 0;
      }
      iVar2 = M<SInt32>(self + 0x10);
      if (iVar2 == 0) goto LAB_00018f2c;
    }
    puVar3 = (UInt32 *)(iVar2 + 0x44);
    M<SInt32>(self + 8) = iVar2 + 4;
    M<UInt32>(iVar2 + 0xc) = 0;
    M<UInt32>(iVar2 + 8) = 0;
    M<UInt32>(iVar2 + 0x1c) = 0;
    M<SInt32>(iVar2 + 0x18) = iVar2 + 4;
    M<UInt32>(iVar2 + 0x2c) = 0;
    M<SInt32>(iVar2 + 0x28) = iVar2 + 0x14;
    M<UInt32>(iVar2 + 0x3c) = param_1;
    M<SInt32>(iVar2 + 0x38) = iVar2 + 0x24;
    M<SInt32>(iVar2 + 4) = iVar2 + 0x14;
    M<SInt32>(iVar2 + 0x14) = iVar2 + 0x24;
    M<SInt32>(iVar2 + 0x24) = iVar2 + 0x34;
    M<UInt32>(iVar2 + 0x34) = 0;
    M<UInt32>(iVar2 + 0x10) = 0x80000000;
    M<UInt32>(iVar2 + 0x20) = 0;
    M<UInt32>(iVar2 + 0x30) = 0x80000000;
    M<UInt32>(iVar2 + 0x40) = 0;
    M<UInt32 *>(self + 0xc) = puVar3;
    M<UInt32>(iVar2 + 0x48) = 0;
    M<UInt32>(iVar2 + 0x4c) = 0;
    M<UInt32>(iVar2 + 0x50) = 0;
    if ((UInt32 *)(iVar2 + 500) != puVar3) {
      puVar1 = (UInt32 *)(iVar2 + 0x5c);
      iVar5 = 0x1b;
      do {
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[-1] = 0;
        *puVar3 = (UInt32)(puVar3 + 4);
        puVar1 = puVar1 + 4;
        iVar5 = iVar5 + -1;
        puVar3 = puVar3 + 4;
      } while (iVar5 != 0);
    }
    uVar4 = 1;
    M<UInt32>(iVar2 + 500) = 0;
  }
  return uVar4;
}
