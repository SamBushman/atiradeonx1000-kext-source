/*
 * ATIRadeonX1000_submit_buffer_Port.cpp
 *
 * ATIRadeonX1000::submit_buffer (real addr 0x20980, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLog(...) asm("_IOLog");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");


/* real addr 0x20980 */
UInt32 ATIRadeonX1000::submit_buffer(UInt32*param_1, UInt32 param_2, UInt32 param_3) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt32 uVar6;
  SInt32 iVar7;
  SInt32 iVar8;
  
  for (; (param_3 & 7) != 0; param_3 = param_3 + 1) {
    param_1[param_3] = 0x80000000;
  }
  iVar3 = M<SInt32>(self + 0x90c);
  iVar5 = M<SInt32>(self + 0x910);
  uVar4 = M<UInt32>(self + 0x914);
  iVar7 = 0;
  if ((SInt32)(((CONCAT11(((UInt8 *)(iVar3 + iVar5))[1],M<UInt8>(iVar3 + iVar5)) - uVar4) -
             1 & 0x7ff) - 7) < 5) {
    do {
      iVar7 = iVar7 + 1;
      GH_IOSleep(1);
      iVar3 = M<SInt32>(self + 0x90c);
      iVar5 = M<SInt32>(self + 0x910);
      uVar4 = M<UInt32>(self + 0x914);
      iVar1 = ((CONCAT11(((UInt8 *)(iVar3 + iVar5))[1],M<UInt8>(iVar3 + iVar5)) - uVar4)
               - 1 & 0x7ff) - 7;
      if (4 < iVar1) goto LAB_00020a3c;
    } while (iVar7 != 1000);
  }
  else {
LAB_00020a3c:
    M<UInt32>(self + 0x6fc) = param_3 * 4 + M<SInt32>(self + 0x6fc);
    if ((M<UInt32>(self + 0x98) & 0x80) == 0) {
      ppcSync();
      instructionSynchronize();
    }
    else {
      uVar6 = (UInt32)(UInt8)self[0x84];
      iVar7 = 0;
      iVar1 = (param_3 * 4 + ((UInt32)param_1 & uVar6 - 1)) - uVar6;
      if (0 < iVar1) {
        iVar7 = 0;
        do {
          dataCacheBlockStore((-uVar6 & (UInt32)param_1) + iVar7);
          iVar7 = iVar7 + uVar6;
        } while (iVar7 < iVar1);
      }
      ppcSync();
      instructionSynchronize();
      dataCacheBlockFlush((-uVar6 & (UInt32)param_1) + iVar7);
      ppcSync();
      instructionSynchronize();
      instructionSynchronize();
    }
    if (M<SInt32>(self + 0x8a0) != 0) {
      this->submit_empty_buffer();
      iVar3 = M<SInt32>(self + 0x90c);
      iVar5 = M<SInt32>(self + 0x910);
      uVar4 = M<UInt32>(self + 0x914);
    }
    iVar7 = M<SInt32>(self + 0x8a4);
    iVar8 = 0;
    if (4 < (SInt32)(((CONCAT11(((UInt8 *)(iVar3 + iVar5))[1],M<UInt8>(iVar3 + iVar5)) -
                   uVar4) - 1 & 0x7ff) - 7)) {
LAB_00020b4c:
      if (M<SInt32>(self + 0x8d0) == 0) {
        iVar3 = M<SInt32>(self + 0x900);
        M<UInt32>(iVar3 + uVar4 * 4) = 0x57f;
        uVar2 = M<UInt32>(self + 0x50);
        uVar6 = uVar4 + 1 & 0x7ff;
        uVar4 = uVar6 + 1;
        M<UInt32>(self + 0x914) = uVar4;
        M<UInt32>(iVar3 + uVar6 * 4) = uVar2;
        uVar4 = uVar4 & 0x7ff;
        M<UInt32>(self + 0x914) = uVar4;
      }
      else {
        iVar3 = M<SInt32>(self + 0x900);
        uVar2 = M<UInt32>(self + 0x50);
      }
      M<UInt32>(iVar3 + uVar4 * 4) = 0x101ce;
      uVar4 = uVar4 + 1 & 0x7ff;
      M<UInt32>(self + 0x914) = uVar4;
      M<UInt32>(iVar3 + uVar4 * 4) = param_2 + iVar7 & 0xfffffffc;
      uVar4 = uVar4 + 1 & 0x7ff;
      M<UInt32>(self + 0x914) = uVar4;
      M<UInt32>(iVar3 + uVar4 * 4) = param_3 & 0x7fffff;
      uVar4 = uVar4 + 1 & 0x7ff;
      M<UInt32>(self + 0x914) = uVar4;
      M<UInt32>(iVar3 + uVar4 * 4) = 0x578;
      uVar4 = uVar4 + 1 & 0x7ff;
      uVar6 = uVar4 + 1;
      M<UInt32>(self + 0x914) = uVar6;
      M<UInt32>(iVar3 + uVar4 * 4) = uVar2;
      M<UInt32>(self + 0x914) = uVar6 & 0x7ff;
      this->submit_ring_data();
      if (M<SInt32>(self + 0x8d0) != 0) {
        M<UInt32>(M<SInt32>(self + 0x8d0) + 0x20) = M<UInt32>(self + 0x50);
      }
      iVar3 = M<SInt32>(self + 0x50);
      M<SInt32>(self + 0x50) = iVar3 + 1;
      return iVar3;
    }
    do {
      iVar8 = iVar8 + 1;
      GH_IOSleep(1);
      uVar4 = M<UInt32>(self + 0x914);
      iVar1 = ((CONCAT11(((UInt8 *)(M<SInt32>(self + 0x90c) + M<SInt32>(self + 0x910)))[1],
                         M<UInt8>(M<SInt32>(self + 0x90c) + M<SInt32>(self + 0x910))) - uVar4)
               - 1 & 0x7ff) - 7;
      if (4 < iVar1) goto LAB_00020b4c;
    } while (iVar8 != 1000);
  }
  iVar3 = M<SInt32>(self + 0x860);
  GH_IOLog("ATIRadeon::wait_for_rb_space: Overflowed block waiting for FIFO space.   Have %lu, need %lu. RBBM_STATUS 0x%08x\n"
               ,iVar1,5,(UInt32)M<UInt8>(iVar3 + 0xe43) << 0x18 |
                        (UInt32)M<UInt8>(iVar3 + 0xe42) << 0x10 | (UInt32)M<UInt8>(iVar3 + 0xe41) << 8
                        | (UInt32)M<UInt8>(iVar3 + 0xe40));
  this->DumpASICHangState();
  return *(SInt32 *)(self + 0x50) + -1;
}
