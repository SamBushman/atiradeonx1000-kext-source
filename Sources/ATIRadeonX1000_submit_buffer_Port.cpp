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
UInt32 ATIRadeonX1000::submit_buffer(UInt32*bufferStart, UInt32 gartOffset, UInt32 dwordCount) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt32 stamp;
  SInt32 iVar3;
  UInt32 writeIndex;
  SInt32 rptrOffset;
  UInt32 uVar6;
  SInt32 iVar7;
  SInt32 spinCount;
  
  for (; (dwordCount & 7) != 0; dwordCount = dwordCount + 1) {
    bufferStart[dwordCount] = 0x80000000;
  }
  iVar3 = M<SInt32>(self + 0x90c);
  rptrOffset = M<SInt32>(self + 0x910);
  writeIndex = M<UInt32>(self + 0x914);
  iVar7 = 0;
  if ((SInt32)((((loadWordByteReversed((UInt8 *)(iVar3 + rptrOffset)) & 0xffff) - writeIndex) -
             1 & 0x7ff) - 7) < 5) {
    do {
      iVar7 = iVar7 + 1;
      GH_IOSleep(1);
      iVar3 = M<SInt32>(self + 0x90c);
      rptrOffset = M<SInt32>(self + 0x910);
      writeIndex = M<UInt32>(self + 0x914);
      iVar1 = (((loadWordByteReversed((UInt8 *)(iVar3 + rptrOffset)) & 0xffff) - writeIndex)
               - 1 & 0x7ff) - 7;
      if (4 < iVar1) goto LAB_00020a3c;
    } while (iVar7 != 1000);
  }
  else {
LAB_00020a3c:
    M<UInt32>(self + kIOATIR500Accelerator_commandBytesPerSample) = dwordCount * 4 + M<SInt32>(self + kIOATIR500Accelerator_commandBytesPerSample);
    if ((M<UInt32>(self + kIOATIR500Accelerator_capabilityFlags) & 0x80) == 0) {
      ppcSync();
      instructionSynchronize();
    }
    else {
      uVar6 = (UInt32)(UInt8)self[0x84];
      iVar7 = 0;
      iVar1 = (dwordCount * 4 + ((UInt32)bufferStart & uVar6 - 1)) - uVar6;
      if (0 < iVar1) {
        iVar7 = 0;
        do {
          dataCacheBlockStore((-uVar6 & (UInt32)bufferStart) + iVar7);
          iVar7 = iVar7 + uVar6;
        } while (iVar7 < iVar1);
      }
      ppcSync();
      instructionSynchronize();
      dataCacheBlockFlush((-uVar6 & (UInt32)bufferStart) + iVar7);
      ppcSync();
      instructionSynchronize();
      instructionSynchronize();
    }
    if (M<SInt32>(self + 0x8a0) != 0) {
      this->submit_empty_buffer();
      iVar3 = M<SInt32>(self + 0x90c);
      rptrOffset = M<SInt32>(self + 0x910);
      writeIndex = M<UInt32>(self + 0x914);
    }
    iVar7 = M<SInt32>(self + 0x8a4);
    spinCount = 0;
    if (4 < (SInt32)((((loadWordByteReversed((UInt8 *)(iVar3 + rptrOffset)) & 0xffff) -
                   writeIndex) - 1 & 0x7ff) - 7)) {
LAB_00020b4c:
      if (M<SInt32>(self + 0x8d0) == 0) {
        iVar3 = M<SInt32>(self + 0x900);
        M<UInt32>(iVar3 + writeIndex * 4) = 0x57f;
        stamp = M<UInt32>(self + kIOATIR500Accelerator_submitStamp);
        uVar6 = writeIndex + 1 & 0x7ff;
        writeIndex = uVar6 + 1;
        M<UInt32>(self + 0x914) = writeIndex;
        M<UInt32>(iVar3 + uVar6 * 4) = stamp;
        writeIndex = writeIndex & 0x7ff;
        M<UInt32>(self + 0x914) = writeIndex;
      }
      else {
        iVar3 = M<SInt32>(self + 0x900);
        stamp = M<UInt32>(self + kIOATIR500Accelerator_submitStamp);
      }
      M<UInt32>(iVar3 + writeIndex * 4) = 0x101ce;
      writeIndex = writeIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x914) = writeIndex;
      M<UInt32>(iVar3 + writeIndex * 4) = gartOffset + iVar7 & 0xfffffffc;
      writeIndex = writeIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x914) = writeIndex;
      M<UInt32>(iVar3 + writeIndex * 4) = dwordCount & 0x7fffff;
      writeIndex = writeIndex + 1 & 0x7ff;
      M<UInt32>(self + 0x914) = writeIndex;
      M<UInt32>(iVar3 + writeIndex * 4) = 0x578;
      writeIndex = writeIndex + 1 & 0x7ff;
      uVar6 = writeIndex + 1;
      M<UInt32>(self + 0x914) = uVar6;
      M<UInt32>(iVar3 + writeIndex * 4) = stamp;
      M<UInt32>(self + 0x914) = uVar6 & 0x7ff;
      this->submit_ring_data();
      if (M<SInt32>(self + 0x8d0) != 0) {
        M<UInt32>(M<SInt32>(self + 0x8d0) + 0x20) = M<UInt32>(self + kIOATIR500Accelerator_submitStamp);
      }
      iVar3 = M<SInt32>(self + kIOATIR500Accelerator_submitStamp);
      M<SInt32>(self + kIOATIR500Accelerator_submitStamp) = iVar3 + 1;
      return iVar3;
    }
    do {
      spinCount = spinCount + 1;
      GH_IOSleep(1);
      writeIndex = M<UInt32>(self + 0x914);
      iVar1 = (((loadWordByteReversed((UInt8 *)(M<SInt32>(self + 0x90c) + M<SInt32>(self + 0x910))) & 0xffff) - writeIndex)
               - 1 & 0x7ff) - 7;
      if (4 < iVar1) goto LAB_00020b4c;
    } while (spinCount != 1000);
  }
  iVar3 = M<SInt32>(self + 0x860);
  GH_IOLog("ATIRadeon::wait_for_rb_space: Overflowed block waiting for FIFO space.   Have %lu, need %lu. RBBM_STATUS 0x%08x\n"
               ,iVar1,5,loadWordByteReversed(&M<UInt8>(iVar3 + 0xe40)));
  this->DumpASICHangState();
  return *(SInt32 *)(self + kIOATIR500Accelerator_submitStamp) + -1;
}
