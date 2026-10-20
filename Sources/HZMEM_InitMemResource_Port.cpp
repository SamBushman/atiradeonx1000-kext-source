/*
 * HZMEM_InitMemResource_Port.cpp
 *
 * HZMEM_InitMemResource (real addr 0x44d90, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFreePageable(...) asm("_IOFreePageable");
extern "C" UInt32 GH_IOMallocPageable(...) asm("_IOMallocPageable");


/* real addr 0x44d90 */
UInt32 HZMEM_InitMemResource(_HZDATA *hizData, UInt32 hzMode, UInt32 numPipes, UInt32 numZPipes) {
    UInt8 *hizDataBytes = reinterpret_cast<UInt8 *>(hizData);

  UInt32 *kind2Pool;
  code *kind0MapBytes;
  unsigned int kind1MapBytes;
  UInt8 modeIsOne;
  unsigned int *kind0Pool;
  unsigned int *kind1Pool;
  int currentPool;
  UInt32 mapLimit;
  UInt32 mapMemory;
  
  modeIsOne = (hzMode == 1) << 1;
  M<UInt32>(hizDataBytes + 0xc) = 3;
  M<UInt32>(hizDataBytes + 8) = 4;
  M<UInt32>(hizDataBytes + 4) = 4;
  if ((hzMode == 1) || (kind0MapBytes = (code *)0x14000, hzMode == 2)) {
    kind0MapBytes = (code *)0x10000;
  }
  kind0Pool = (unsigned int *)GH_IOMallocPageable(0x1014,0x20);
  M<unsigned int *>(hizDataBytes + 0x10) = kind0Pool;
  M<UInt32>(hizDataBytes + 0x18) = 0;
  M<UInt32>(hizDataBytes + 0x14) = 0;
  if (kind0Pool != (unsigned int *)0x0) {
    *kind0Pool = (unsigned int)kind0MapBytes >> 4;
    M<UInt32>(M<int>(hizDataBytes + 0x10) + 4) = numPipes * numZPipes * 0x10;
    if ((bool)(modeIsOne >> 1 & 1)) {
      mapLimit = 0x1fff0;
    }
    else {
      mapLimit = 0x7fff0;
    }
    M<UInt32>(M<int>(hizDataBytes + 0x10) + 8) = mapLimit;
    M<UInt32>(M<int>(hizDataBytes + 0x10) + 0x10) = 0;
    currentPool = M<int>(hizDataBytes + 0x10);
    mapMemory = GH_IOMallocPageable((unsigned int)kind0MapBytes >> 4,0x20);
    M<UInt32>(currentPool + 0xc) = mapMemory;
    if (M<int>(M<int>(hizDataBytes + 0x10) + 0xc) != 0) {
      if ((((bool)(modeIsOne >> 1 & 1)) || (hzMode == 2)) || (kind1MapBytes = 0xa000, hzMode == 3)) {
        kind1MapBytes = 0xf000;
      }
      kind1Pool = (unsigned int *)GH_IOMallocPageable(0x1014,0x20);
      M<unsigned int *>(hizDataBytes + 0x14) = kind1Pool;
      if (kind1Pool == (unsigned int *)0x0) {
        GH_IOFreePageable((M<UInt32 *>(hizDataBytes + 0x10))[3],*M<UInt32 *>(hizDataBytes + 0x10));
        M<UInt32>(M<int>(hizDataBytes + 0x10) + 0xc) = 0;
        GH_IOFreePageable(M<UInt32>(hizDataBytes + 0x10),0x1014);
        M<UInt32>(hizDataBytes + 0x10) = 0;
        return 1;
      }
      *kind1Pool = kind1MapBytes >> 2;
      M<UInt32>(M<int>(hizDataBytes + 0x14) + 4) = numPipes * numZPipes * 4;
      if ((bool)(modeIsOne >> 1 & 1)) {
        mapLimit = 0x1fffc;
      }
      else {
        mapLimit = 0x3fffc;
      }
      M<UInt32>(M<int>(hizDataBytes + 0x14) + 8) = mapLimit;
      M<UInt32>(M<int>(hizDataBytes + 0x14) + 0x10) = 0;
      currentPool = M<int>(hizDataBytes + 0x14);
      mapMemory = GH_IOMallocPageable(kind1MapBytes >> 2,0x20);
      M<UInt32>(currentPool + 0xc) = mapMemory;
      if (M<int>(M<int>(hizDataBytes + 0x14) + 0xc) == 0) {
        GH_IOFreePageable((M<UInt32 *>(hizDataBytes + 0x10))[3],*M<UInt32 *>(hizDataBytes + 0x10));
        M<UInt32>(M<int>(hizDataBytes + 0x10) + 0xc) = 0;
        GH_IOFreePageable(M<UInt32>(hizDataBytes + 0x10),0x1014);
        M<UInt32>(hizDataBytes + 0x10) = 0;
        GH_IOFreePageable(M<UInt32>(hizDataBytes + 0x14),0x1014);
        M<UInt32>(hizDataBytes + 0x14) = 0;
        return 1;
      }
      kind2Pool = (UInt32 *)GH_IOMallocPageable(0x1014,0x20);
      M<UInt32 *>(hizDataBytes + 0x18) = kind2Pool;
      if (kind2Pool == (UInt32 *)0x0) {
        GH_IOFreePageable((M<UInt32 *>(hizDataBytes + 0x10))[3],*M<UInt32 *>(hizDataBytes + 0x10));
        M<UInt32>(M<int>(hizDataBytes + 0x10) + 0xc) = 0;
        GH_IOFreePageable(M<UInt32>(hizDataBytes + 0x10),0x1014);
        M<UInt32>(hizDataBytes + 0x10) = 0;
        GH_IOFreePageable((M<UInt32 *>(hizDataBytes + 0x14))[3],*M<UInt32 *>(hizDataBytes + 0x14));
        M<UInt32>(M<int>(hizDataBytes + 0x14) + 0xc) = 0;
        GH_IOFreePageable(M<UInt32>(hizDataBytes + 0x14),0x1014);
        M<UInt32>(hizDataBytes + 0x14) = 0;
        return 1;
      }
      *kind2Pool = 0x1400;
      M<UInt32>(M<int>(hizDataBytes + 0x18) + 4) = numPipes << 4;
      if ((bool)(modeIsOne >> 1 & 1)) {
        mapLimit = 0x3fff0;
      }
      else {
        mapLimit = 0x7fff0;
      }
      M<UInt32>(M<int>(hizDataBytes + 0x18) + 8) = mapLimit;
      M<UInt32>(M<int>(hizDataBytes + 0x18) + 0x10) = 0;
      currentPool = M<int>(hizDataBytes + 0x18);
      mapMemory = GH_IOMallocPageable(0x1400,0x20);
      M<UInt32>(currentPool + 0xc) = mapMemory;
      if (M<int>(M<int>(hizDataBytes + 0x18) + 0xc) != 0) {
        return 0;
      }
      GH_IOFreePageable((M<UInt32 *>(hizDataBytes + 0x10))[3],*M<UInt32 *>(hizDataBytes + 0x10));
      M<UInt32>(M<int>(hizDataBytes + 0x10) + 0xc) = 0;
      GH_IOFreePageable(M<UInt32>(hizDataBytes + 0x10),0x1014);
      M<UInt32>(hizDataBytes + 0x10) = 0;
      GH_IOFreePageable((M<UInt32 *>(hizDataBytes + 0x14))[3],*M<UInt32 *>(hizDataBytes + 0x14));
      M<UInt32>(M<int>(hizDataBytes + 0x14) + 0xc) = 0;
      GH_IOFreePageable(M<UInt32>(hizDataBytes + 0x14),0x1014);
      M<UInt32>(hizDataBytes + 0x14) = 0;
      GH_IOFreePageable(M<UInt32>(hizDataBytes + 0x18),0x1014);
      M<UInt32>(hizDataBytes + 0x18) = 0;
      return 1;
    }
  }
  return 1;
}
