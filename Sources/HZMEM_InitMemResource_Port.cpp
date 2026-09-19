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
UInt32 HZMEM_InitMemResource(_HZDATA *real_param_1, UInt32 param_2, UInt32 param_3, UInt32 param_4) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  unsigned int *puVar2;
  UInt32 *puVar3;
  int iVar4;
  code *pcVar5;
  unsigned int uVar6;
  UInt8 bVar7;
  
  bVar7 = (param_2 == 1) << 1;
  M<UInt32>(param_1 + 0xc) = 3;
  M<UInt32>(param_1 + 8) = 4;
  M<UInt32>(param_1 + 4) = 4;
  if ((param_2 == 1) || (pcVar5 = (code *)0x14000, param_2 == 2)) {
    pcVar5 = (code *)0x10000;
  }
  puVar2 = (unsigned int *)GH_IOMallocPageable(0x1014,0x20);
  M<unsigned int *>(param_1 + 0x10) = puVar2;
  M<UInt32>(param_1 + 0x18) = 0;
  M<UInt32>(param_1 + 0x14) = 0;
  if (puVar2 != (unsigned int *)0x0) {
    *puVar2 = (unsigned int)pcVar5 >> 4;
    M<UInt32>(M<int>(param_1 + 0x10) + 4) = param_3 * param_4 * 0x10;
    if ((bool)(bVar7 >> 1 & 1)) {
      uVar1 = 0x1fff0;
    }
    else {
      uVar1 = 0x7fff0;
    }
    M<UInt32>(M<int>(param_1 + 0x10) + 8) = uVar1;
    M<UInt32>(M<int>(param_1 + 0x10) + 0x10) = 0;
    iVar4 = M<int>(param_1 + 0x10);
    uVar1 = GH_IOMallocPageable((unsigned int)pcVar5 >> 4,0x20);
    M<UInt32>(iVar4 + 0xc) = uVar1;
    if (M<int>(M<int>(param_1 + 0x10) + 0xc) != 0) {
      if ((((bool)(bVar7 >> 1 & 1)) || (param_2 == 2)) || (uVar6 = 0xa000, param_2 == 3)) {
        uVar6 = 0xf000;
      }
      puVar2 = (unsigned int *)GH_IOMallocPageable(0x1014,0x20);
      M<unsigned int *>(param_1 + 0x14) = puVar2;
      if (puVar2 == (unsigned int *)0x0) {
        GH_IOFreePageable((M<UInt32 *>(param_1 + 0x10))[3],*M<UInt32 *>(param_1 + 0x10));
        M<UInt32>(M<int>(param_1 + 0x10) + 0xc) = 0;
        GH_IOFreePageable(M<UInt32>(param_1 + 0x10),0x1014);
        M<UInt32>(param_1 + 0x10) = 0;
        return 1;
      }
      *puVar2 = uVar6 >> 2;
      M<UInt32>(M<int>(param_1 + 0x14) + 4) = param_3 * param_4 * 4;
      if ((bool)(bVar7 >> 1 & 1)) {
        uVar1 = 0x1fffc;
      }
      else {
        uVar1 = 0x3fffc;
      }
      M<UInt32>(M<int>(param_1 + 0x14) + 8) = uVar1;
      M<UInt32>(M<int>(param_1 + 0x14) + 0x10) = 0;
      iVar4 = M<int>(param_1 + 0x14);
      uVar1 = GH_IOMallocPageable(uVar6 >> 2,0x20);
      M<UInt32>(iVar4 + 0xc) = uVar1;
      if (M<int>(M<int>(param_1 + 0x14) + 0xc) == 0) {
        GH_IOFreePageable((M<UInt32 *>(param_1 + 0x10))[3],*M<UInt32 *>(param_1 + 0x10));
        M<UInt32>(M<int>(param_1 + 0x10) + 0xc) = 0;
        GH_IOFreePageable(M<UInt32>(param_1 + 0x10),0x1014);
        M<UInt32>(param_1 + 0x10) = 0;
        GH_IOFreePageable(M<UInt32>(param_1 + 0x14),0x1014);
        M<UInt32>(param_1 + 0x14) = 0;
        return 1;
      }
      puVar3 = (UInt32 *)GH_IOMallocPageable(0x1014,0x20);
      M<UInt32 *>(param_1 + 0x18) = puVar3;
      if (puVar3 == (UInt32 *)0x0) {
        GH_IOFreePageable((M<UInt32 *>(param_1 + 0x10))[3],*M<UInt32 *>(param_1 + 0x10));
        M<UInt32>(M<int>(param_1 + 0x10) + 0xc) = 0;
        GH_IOFreePageable(M<UInt32>(param_1 + 0x10),0x1014);
        M<UInt32>(param_1 + 0x10) = 0;
        GH_IOFreePageable((M<UInt32 *>(param_1 + 0x14))[3],*M<UInt32 *>(param_1 + 0x14));
        M<UInt32>(M<int>(param_1 + 0x14) + 0xc) = 0;
        GH_IOFreePageable(M<UInt32>(param_1 + 0x14),0x1014);
        M<UInt32>(param_1 + 0x14) = 0;
        return 1;
      }
      *puVar3 = 0x1400;
      M<UInt32>(M<int>(param_1 + 0x18) + 4) = param_3 << 4;
      if ((bool)(bVar7 >> 1 & 1)) {
        uVar1 = 0x3fff0;
      }
      else {
        uVar1 = 0x7fff0;
      }
      M<UInt32>(M<int>(param_1 + 0x18) + 8) = uVar1;
      M<UInt32>(M<int>(param_1 + 0x18) + 0x10) = 0;
      iVar4 = M<int>(param_1 + 0x18);
      uVar1 = GH_IOMallocPageable(0x1400,0x20);
      M<UInt32>(iVar4 + 0xc) = uVar1;
      if (M<int>(M<int>(param_1 + 0x18) + 0xc) != 0) {
        return 0;
      }
      GH_IOFreePageable((M<UInt32 *>(param_1 + 0x10))[3],*M<UInt32 *>(param_1 + 0x10));
      M<UInt32>(M<int>(param_1 + 0x10) + 0xc) = 0;
      GH_IOFreePageable(M<UInt32>(param_1 + 0x10),0x1014);
      M<UInt32>(param_1 + 0x10) = 0;
      GH_IOFreePageable((M<UInt32 *>(param_1 + 0x14))[3],*M<UInt32 *>(param_1 + 0x14));
      M<UInt32>(M<int>(param_1 + 0x14) + 0xc) = 0;
      GH_IOFreePageable(M<UInt32>(param_1 + 0x14),0x1014);
      M<UInt32>(param_1 + 0x14) = 0;
      GH_IOFreePageable(M<UInt32>(param_1 + 0x18),0x1014);
      M<UInt32>(param_1 + 0x18) = 0;
      return 1;
    }
  }
  return 1;
}
