/*
 * ATIRadeonX1000_HZMEM.cpp
 *
 * RESOLVED (ledger pass): the HiZ memory-manager setup/teardown functions that had no body in the rebuild (real addrs
 * in parentheses): HZMEM_InitMemResource (0x44d90), HZMEM_InitAllocationTable (0x45160), HZMEM_Init (0x45200),
 * HZMEM_Destroy (0x45280). (HZMEM_Alloc / HZMEM_Free / HZMEM_GetBlockOffset are in their own files.)
 *
 * _HZDATA layout (raw offsets): +0 mode, +4 / +8 / +0xc tuning words (4, 4, 3 = the number of resource tables),
 * +0x10 / +0x14 / +0x18 pointers to the three resource tables. Each table is a 0x1014-byte record {+0 entry count,
 * +4 size, +8 limit, +0xc bitmap (pageable memory), +0x10 next-free, +0x14.. index slots}.
 *
 * Transcribed mechanically from the decompile (Tools/ghidra2cpp.py, Headers/GhidraCompat.h). The Ghidra-labelled
 * `IOATIR500Surface::decrement_refcounts` in InitMemResource is a mislabelled constant: the immediate is 0x14000
 * (the address of that method), the entry count used when mode is neither 1 nor 2.
 */

#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraCompat.h"

extern "C" void *IOMallocPageable(unsigned long size, unsigned long alignment);
extern "C" void IOFreePageable(void *address, unsigned long size);
extern "C" void bzero(void *address, unsigned long size);

namespace {
inline UInt32 HZ_alloc(UInt32 size, UInt32 alignment) { return reinterpret_cast<UInt32>(IOMallocPageable(size, alignment)); }
template <class T> inline void HZ_free(T address, UInt32 size) { IOFreePageable((void *)(address), size); }
template <class T> inline void HZ_zero(T address, UInt32 size) { bzero((void *)(address), size); }
} // namespace

UInt32 HZMEM_InitMemResource(_HZDATA *hz, UInt32 param_2, UInt32 param_3, UInt32 param_4) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(hz);

  UInt32 uVar1;
  UInt32 *puVar2;
  UInt32 *puVar3;
  SInt32 iVar4;
  UInt32 pcVar5;
  UInt32 uVar6;
  UInt8 bVar7;
  
  bVar7 = (param_2 == 1) << 1;
  M<UInt32>(param_1 + 0xc) = 3;
  M<UInt32>(param_1 + 8) = 4;
  M<UInt32>(param_1 + 4) = 4;
  if ((param_2 == 1) || (pcVar5 = 0x14000, param_2 == 2)) {
    pcVar5 = 0x10000;
  }
  puVar2 = (UInt32 *)HZ_alloc(0x1014,0x20);
  M<UInt32 *>(param_1 + 0x10) = puVar2;
  M<UInt32>(param_1 + 0x18) = 0;
  M<UInt32>(param_1 + 0x14) = 0;
  if (puVar2 != (UInt32 *)0x0) {
    *puVar2 = (UInt32)pcVar5 >> 4;
    M<UInt32>(M<SInt32>(param_1 + 0x10) + 4) = param_3 * param_4 * 0x10;
    if ((bool)(bVar7 >> 1 & 1)) {
      uVar1 = 0x1fff0;
    }
    else {
      uVar1 = 0x7fff0;
    }
    M<UInt32>(M<SInt32>(param_1 + 0x10) + 8) = uVar1;
    M<UInt32>(M<SInt32>(param_1 + 0x10) + 0x10) = 0;
    iVar4 = M<SInt32>(param_1 + 0x10);
    uVar1 = HZ_alloc((UInt32)pcVar5 >> 4,0x20);
    M<UInt32>(iVar4 + 0xc) = uVar1;
    if (M<SInt32>(M<SInt32>(param_1 + 0x10) + 0xc) != 0) {
      if ((((bool)(bVar7 >> 1 & 1)) || (param_2 == 2)) || (uVar6 = 0xa000, param_2 == 3)) {
        uVar6 = 0xf000;
      }
      puVar2 = (UInt32 *)HZ_alloc(0x1014,0x20);
      M<UInt32 *>(param_1 + 0x14) = puVar2;
      if (puVar2 == (UInt32 *)0x0) {
        HZ_free((M<UInt32 *>(param_1 + 0x10))[3],*M<UInt32 *>(param_1 + 0x10));
        M<UInt32>(M<SInt32>(param_1 + 0x10) + 0xc) = 0;
        HZ_free(M<UInt32>(param_1 + 0x10),0x1014);
        M<UInt32>(param_1 + 0x10) = 0;
        return 1;
      }
      *puVar2 = uVar6 >> 2;
      M<UInt32>(M<SInt32>(param_1 + 0x14) + 4) = param_3 * param_4 * 4;
      if ((bool)(bVar7 >> 1 & 1)) {
        uVar1 = 0x1fffc;
      }
      else {
        uVar1 = 0x3fffc;
      }
      M<UInt32>(M<SInt32>(param_1 + 0x14) + 8) = uVar1;
      M<UInt32>(M<SInt32>(param_1 + 0x14) + 0x10) = 0;
      iVar4 = M<SInt32>(param_1 + 0x14);
      uVar1 = HZ_alloc(uVar6 >> 2,0x20);
      M<UInt32>(iVar4 + 0xc) = uVar1;
      if (M<SInt32>(M<SInt32>(param_1 + 0x14) + 0xc) == 0) {
        HZ_free((M<UInt32 *>(param_1 + 0x10))[3],*M<UInt32 *>(param_1 + 0x10));
        M<UInt32>(M<SInt32>(param_1 + 0x10) + 0xc) = 0;
        HZ_free(M<UInt32>(param_1 + 0x10),0x1014);
        M<UInt32>(param_1 + 0x10) = 0;
        HZ_free(M<UInt32>(param_1 + 0x14),0x1014);
        M<UInt32>(param_1 + 0x14) = 0;
        return 1;
      }
      puVar3 = (UInt32 *)HZ_alloc(0x1014,0x20);
      M<UInt32 *>(param_1 + 0x18) = puVar3;
      if (puVar3 == (UInt32 *)0x0) {
        HZ_free((M<UInt32 *>(param_1 + 0x10))[3],*M<UInt32 *>(param_1 + 0x10));
        M<UInt32>(M<SInt32>(param_1 + 0x10) + 0xc) = 0;
        HZ_free(M<UInt32>(param_1 + 0x10),0x1014);
        M<UInt32>(param_1 + 0x10) = 0;
        HZ_free((M<UInt32 *>(param_1 + 0x14))[3],*M<UInt32 *>(param_1 + 0x14));
        M<UInt32>(M<SInt32>(param_1 + 0x14) + 0xc) = 0;
        HZ_free(M<UInt32>(param_1 + 0x14),0x1014);
        M<UInt32>(param_1 + 0x14) = 0;
        return 1;
      }
      *puVar3 = 0x1400;
      M<UInt32>(M<SInt32>(param_1 + 0x18) + 4) = param_3 << 4;
      if ((bool)(bVar7 >> 1 & 1)) {
        uVar1 = 0x3fff0;
      }
      else {
        uVar1 = 0x7fff0;
      }
      M<UInt32>(M<SInt32>(param_1 + 0x18) + 8) = uVar1;
      M<UInt32>(M<SInt32>(param_1 + 0x18) + 0x10) = 0;
      iVar4 = M<SInt32>(param_1 + 0x18);
      uVar1 = HZ_alloc(0x1400,0x20);
      M<UInt32>(iVar4 + 0xc) = uVar1;
      if (M<SInt32>(M<SInt32>(param_1 + 0x18) + 0xc) != 0) {
        return 0;
      }
      HZ_free((M<UInt32 *>(param_1 + 0x10))[3],*M<UInt32 *>(param_1 + 0x10));
      M<UInt32>(M<SInt32>(param_1 + 0x10) + 0xc) = 0;
      HZ_free(M<UInt32>(param_1 + 0x10),0x1014);
      M<UInt32>(param_1 + 0x10) = 0;
      HZ_free((M<UInt32 *>(param_1 + 0x14))[3],*M<UInt32 *>(param_1 + 0x14));
      M<UInt32>(M<SInt32>(param_1 + 0x14) + 0xc) = 0;
      HZ_free(M<UInt32>(param_1 + 0x14),0x1014);
      M<UInt32>(param_1 + 0x14) = 0;
      HZ_free(M<UInt32>(param_1 + 0x18),0x1014);
      M<UInt32>(param_1 + 0x18) = 0;
      return 1;
    }
  }
  return 1;
}

UInt32 HZMEM_InitAllocationTable(_HZDATA *hz) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(hz);

  UInt8 *p_Var1;
  UInt32 uVar2;
  UInt8 *p_Var3;
  
  if (M<SInt32>(param_1 + 0xc) != 0) {
    uVar2 = 0;
    p_Var3 = param_1;
    do {
      uVar2 = uVar2 + 1;
      HZ_zero((M<UInt32 *>(p_Var3 + 0x10))[3],*M<UInt32 *>(p_Var3 + 0x10));
      p_Var1 = p_Var3 + 0x10;
      p_Var3 = p_Var3 + 4;
      HZ_zero(M<SInt32>(p_Var1) + 0x14,0x1000);
    } while (uVar2 < M<UInt32>(param_1 + 0xc));
  }
  return 0;
}

UInt32 HZMEM_Init(_HZDATA *hz, UInt32 param_2, UInt32 param_3, UInt32 param_4) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(hz);

  SInt32 iVar1;
  UInt32 uVar2;
  
  if (param_1 != (UInt8 *)0x0) {
    M<UInt32>(param_1) = param_2;
    iVar1 = HZMEM_InitMemResource(hz,param_2,param_3,param_4);
    if (iVar1 == 0) {
      uVar2 = HZMEM_InitAllocationTable(hz);
      return uVar2;
    }
  }
  return 1;
}

UInt32 HZMEM_Destroy(_HZDATA *hz) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(hz);

  UInt32 uVar1;
  UInt32 uVar2;
  UInt32 *puVar3;
  UInt32 uVar4;
  UInt8 *p_Var5;
  
  uVar2 = 1;
  if (param_1 != (UInt8 *)0x0) {
    uVar1 = M<UInt32>(param_1 + 0xc);
    if (uVar1 != 0) {
      uVar4 = 0;
      p_Var5 = param_1;
      do {
        puVar3 = M<UInt32 *>(p_Var5 + 0x10);
        if (puVar3 != (UInt32 *)0x0) {
          if (puVar3[3] != 0) {
            HZ_free(puVar3[3],*puVar3);
            puVar3 = M<UInt32 *>(p_Var5 + 0x10);
          }
          HZ_free(puVar3,0x1014);
          uVar1 = M<UInt32>(param_1 + 0xc);
        }
        uVar4 = uVar4 + 1;
        p_Var5 = p_Var5 + 4;
      } while (uVar4 < uVar1);
    }
    HZ_zero(param_1,0x1c);
    uVar2 = 0;
  }
  return uVar2;
}
