/*
 * ATIRadeonX1000_submit_idct_buffer_consumed_Port.cpp
 *
 * ATIRadeonX1000::submit_idct_buffer_consumed (real addr 0x1eb30, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1eb30 */
UInt32 ATIRadeonX1000::submit_idct_buffer_consumed(UInt32*param_1, UInt32 param_2, sATIDVDIDCTInfo *real_param_3) {
    static UInt32 u32Dummy;   /* real function-local static: submit_idct_buffer_consumed(unsigned long*, unsigned long, sATIDVDIDCTInfo*)::u32Dummy */
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_3 = reinterpret_cast<UInt8 *>(real_param_3);

  SInt32 iVar1;
  UInt32 uVar2;
  UInt32 uVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  SInt32 iVar6;
  UInt32 uVar7;
  SInt32 iVar8;
  
  iVar8 = M<SInt32>(self + 0x930);
  if ((M<UInt32>(self + 0x98) & 0x80) == 0) {
    ppcSync();
    instructionSynchronize();
  }
  else {
    uVar3 = (UInt32)(UInt8)self[0x84];
    iVar5 = 0;
    iVar1 = (M<SInt32>(param_3 + 0x10) * 4 + ((UInt32)param_1 & uVar3 - 1)) - uVar3;
    if (0 < iVar1) {
      do {
        dataCacheBlockStore((-uVar3 & (UInt32)param_1) + iVar5);
        iVar5 = iVar5 + uVar3;
      } while (iVar5 < iVar1);
    }
    ppcSync();
    instructionSynchronize();
    dataCacheBlockFlush((-uVar3 & (UInt32)param_1) + iVar5);
    ppcSync();
    instructionSynchronize();
    instructionSynchronize();
  }
  if (M<SInt32>(self + 0x8a0) != 0) {
    this->submit_empty_buffer();
  }
  iVar1 = M<SInt32>(self + 0x8a4);
  if (M<SInt32>(self + 0x8bc) != 0) {
    iVar5 = M<SInt32>(self + 0x930);
    iVar6 = 0;
    while ((((UInt32)CONCAT11(((UInt8 *)(M<SInt32>(self + 0x928) + M<SInt32>(self + 0x92c)))[1],
                            M<UInt8>(M<SInt32>(self + 0x928) + M<SInt32>(self + 0x92c))) -
            iVar5) - 1 & 0x7ff) < 0x20) {
      iVar6 = iVar6 + 1;
      if (iVar6 == 0xf4241) goto LAB_0001ef58;
      do {
        u32Dummy =
             u32Dummy +
             1;
      } while ((u32Dummy
               & 0xf) != 0);
    }
    if (iVar6 != 0xf4241) {
      iVar6 = M<SInt32>(self + 0x91c);
      M<UInt32>(iVar6 + iVar5 * 4) = 0x80001fe0;
      uVar3 = iVar5 + 1U & 0x7ff;
      uVar7 = uVar3 + 1;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar3 * 4) = M<UInt32>(param_3 + 0x2c);
      uVar7 = uVar7 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar7 * 4) = 0x80001fe4;
      uVar3 = uVar7 + 1 & 0x7ff;
      uVar7 = uVar3 + 1;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar3 * 4) = M<UInt32>(param_3 + 0x30);
      uVar7 = uVar7 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar7 * 4) = 0x80001fec;
      uVar3 = uVar7 + 1 & 0x7ff;
      uVar7 = uVar3 + 1;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar3 * 4) = M<UInt32>(param_3 + 0x1c);
      uVar7 = uVar7 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar7 * 4) = 0x80001ff0;
      uVar3 = uVar7 + 1 & 0x7ff;
      uVar7 = uVar3 + 1;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar3 * 4) = M<UInt32>(param_3 + 0x20);
      uVar7 = uVar7 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar7 * 4) = 0x80001f8c;
      uVar3 = uVar7 + 1 & 0x7ff;
      uVar7 = uVar3 + 1;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar3 * 4) = M<UInt32>(param_3 + 0x10);
      uVar7 = uVar7 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar7 * 4) = 0x80001ffc;
      uVar3 = uVar7 + 1 & 0x7ff;
      uVar7 = uVar3 + 1;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar3 * 4) = M<UInt32>(param_3 + 0x24);
      uVar7 = uVar7 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar7 * 4) = 0x80001ff8;
      uVar3 = uVar7 + 1 & 0x7ff;
      uVar7 = uVar3 + 1;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar3 * 4) = M<UInt32>(param_3 + 0x28);
      uVar7 = uVar7 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar7 * 4) = param_2 + iVar1 >> 1 & 0x7ffffff0;
      uVar3 = uVar7 + 1 & 0x7ff;
      uVar7 = uVar3 + 1;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar3 * 4) = M<UInt32>(param_3 + 0x14);
      uVar7 = uVar7 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar7 * 4) = 0x80001fa8;
      iVar1 = M<SInt32>(self + 0x854);
      uVar3 = uVar7 + 1 & 0x7ff;
      uVar7 = uVar3 + 1;
      M<UInt32>(self + 0x930) = uVar7;
      M<SInt32>(iVar6 + uVar3 * 4) = iVar1;
      uVar7 = uVar7 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar7 * 4) = 0x80001fac;
      uVar3 = uVar7 + 1 & 0x7ff;
      uVar7 = uVar3 + 1;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar3 * 4) = M<UInt32>(param_3 + 0x18);
      uVar7 = uVar7 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar7;
      M<UInt32>(iVar6 + uVar7 * 4) = 0x80001fb4;
      uVar3 = uVar7 + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar3;
      M<UInt32>(iVar6 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar3;
      M<UInt32>(iVar6 + uVar3 * 4) = 0x80001fb4;
      uVar3 = uVar3 + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar3;
      M<UInt32>(iVar6 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar3;
      M<UInt32>(iVar6 + uVar3 * 4) = 0x80001fb4;
      uVar3 = uVar3 + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar3;
      M<UInt32>(iVar6 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar3;
      M<UInt32>(iVar6 + uVar3 * 4) = 0x80001fb4;
      uVar3 = uVar3 + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar3;
      M<UInt32>(iVar6 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar3;
      M<UInt32>(iVar6 + uVar3 * 4) = 0x80001fb4;
      uVar3 = uVar3 + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar3;
      M<UInt32>(iVar6 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar3;
      M<UInt32>(iVar6 + uVar3 * 4) = 0x80001fb4;
      uVar3 = uVar3 + 1 & 0x7ff;
      M<UInt32>(self + 0x930) = uVar3;
      M<UInt32>(iVar6 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      M<UInt32>(self + 0x930) = uVar3 & 0x7ff;
      if ((M<UInt32>(self + 0x98) & 0x80) == 0) {
        ppcSync();
        instructionSynchronize();
      }
      else {
        uVar4 = (UInt32)(UInt8)self[0x84];
        iVar5 = 0;
        uVar7 = iVar8 * 4 + iVar6;
        uVar2 = -uVar4 & uVar7;
        iVar8 = ((uVar7 & uVar4 - 1) + 0x80) - uVar4;
        if (0 < iVar8) {
          do {
            dataCacheBlockStore(uVar2 + iVar5);
            iVar5 = iVar5 + uVar4;
          } while (iVar5 < iVar8);
        }
        ppcSync();
        instructionSynchronize();
        dataCacheBlockFlush(uVar2 + iVar5);
        ppcSync();
        instructionSynchronize();
        instructionSynchronize();
      }
      M<UInt32>(M<SInt32>(self + 0x860) + 0x1fa0) = uVar3 * 0x1000000 | (uVar3 & 0x700) << 8;
      enforceInOrderExecutionIO();
      M<SInt32>(self + 0x854) = iVar1 + 1;
      return iVar1;
    }
LAB_0001ef58:
    this->DumpASICHangState();
  }
  return *(SInt32 *)(self + 0x854) + -1;
}
