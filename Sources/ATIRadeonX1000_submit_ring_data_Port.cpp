/*
 * ATIRadeonX1000_submit_ring_data_Port.cpp
 *
 * ATIRadeonX1000::submit_ring_data (real addr 0x1f030, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1f030 */
void ATIRadeonX1000::submit_ring_data() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 uVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  SInt32 iVar4;
  UInt32 uVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  UInt32 uVar8;
  
  uVar2 = M<UInt32>(self + 0x914);
  uVar1 = M<UInt32>(self + 0x918);
  if (uVar2 != uVar1) {
    if ((uVar2 & 7) != 0) {
      iVar6 = M<SInt32>(self + 0x900);
      do {
        uVar3 = uVar2 + 1;
        M<UInt32>(iVar6 + uVar2 * 4) = 0x80000000;
        uVar2 = uVar3 & 0x7ff;
      } while ((uVar3 & 7) != 0);
      M<UInt32>(self + 0x914) = uVar2;
    }
    if ((M<UInt32>(self + 0x98) & 0x80) == 0) {
      ppcSync();
      instructionSynchronize();
    }
    else if (uVar1 < uVar2) {
      uVar5 = (UInt32)(UInt8)self[0x84];
      uVar3 = uVar1 * 4 + M<SInt32>(self + 0x900);
      uVar7 = -uVar5 & uVar3;
      iVar6 = 0;
      iVar4 = ((uVar2 - uVar1) * 4 + (uVar3 & uVar5 - 1)) - uVar5;
      if (0 < iVar4) {
        do {
          dataCacheBlockStore(uVar7 + iVar6);
          iVar6 = iVar6 + uVar5;
        } while (iVar6 < iVar4);
      }
      ppcSync();
      instructionSynchronize();
      dataCacheBlockFlush(uVar7 + iVar6);
      ppcSync();
      instructionSynchronize();
      instructionSynchronize();
    }
    else {
      uVar7 = (UInt32)(UInt8)self[0x84];
      uVar5 = M<UInt32>(self + 0x900);
      uVar3 = uVar5 + uVar1 * 4;
      uVar8 = -uVar7 & uVar3;
      iVar6 = 0;
      iVar4 = ((0x800 - uVar1) * 4 + (uVar3 & uVar7 - 1)) - uVar7;
      if (0 < iVar4) {
        do {
          dataCacheBlockStore(uVar8 + iVar6);
          iVar6 = iVar6 + uVar7;
        } while (iVar6 < iVar4);
      }
      ppcSync();
      instructionSynchronize();
      dataCacheBlockFlush(uVar8 + iVar6);
      ppcSync();
      instructionSynchronize();
      instructionSynchronize();
      uVar1 = -uVar7 & uVar5;
      iVar6 = 0;
      iVar4 = (uVar2 * 4 + (uVar7 - 1 & uVar5)) - uVar7;
      if (0 < iVar4) {
        do {
          dataCacheBlockStore(uVar1 + iVar6);
          iVar6 = iVar6 + uVar7;
        } while (iVar6 < iVar4);
      }
      ppcSync();
      instructionSynchronize();
      dataCacheBlockFlush(uVar1 + iVar6);
      ppcSync();
      instructionSynchronize();
      instructionSynchronize();
    }
    M<UInt32>(M<SInt32>(self + 0x860) + 0x714) = uVar2 << 0x18 | (uVar2 & 0x700) << 8;
    enforceInOrderExecutionIO();
    M<UInt32>(self + 0x918) = uVar2;
    return;
  }
  return;
}
