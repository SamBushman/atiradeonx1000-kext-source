/*
 * ATIRadeonX1000_freeToAllocTextureCPUVisibleVRAM_Port.cpp
 *
 * ATIRadeonX1000::freeToAllocTextureCPUVisibleVRAM (real addr 0x1e320, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1e320 */
UInt32 ATIRadeonX1000::freeToAllocTextureCPUVisibleVRAM(VendorTextureBuffer *texture, UInt32 size) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  UInt16 *puVar1;
  UInt16 *puVar2;
  UInt32 faceCount;
  SInt32 iVar4;
  UInt32 uVar5;
  SInt32 iVar6;
  UInt8 *candidate;
  UInt32 uVar8;
  
  VCALL(M<SInt32>(self), 0x558)(self,M<SInt32>(self + kIOATIR500Accelerator_submitStamp) + -1);
  candidate = M<UInt8 *>(self + kIOATIR500Accelerator_vramBufferList_next);
  do {
    while( true ) {
      if (self + kIOATIR500Accelerator_vramBufferList == candidate) {
        return 0;
      }
      if (M<UInt32>(candidate + 0x48) < M<UInt32>(self + kIOATIR500Accelerator_usableVramSize)) break;
LAB_0001e480:
      candidate = M<UInt8 *>(candidate + 0x28);
    }
    iVar4 = M<SInt32>(candidate + 0x14);
    if (iVar4 == 0) {
LAB_0001e3c8:
      VCALL(M<SInt32>(self), 0x524)(self,candidate);
      M<UInt8>(M<SInt32>(candidate + 0x14) + 0x14) = 1;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x28) = 0;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x2a) = 0;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x2c) = 0;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x2e) = 0;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x30) = 0;
      M<UInt16>(M<SInt32>(candidate + 0x14) + 0x32) = 0;
      iVar6 = M<SInt32>(candidate + 0x24);
      M<UInt32>(iVar6 + 0x28) = M<UInt32>(candidate + 0x28);
      iVar4 = M<SInt32>(candidate + 0x28);
      M<UInt8 *>(candidate + 0x28) = candidate;
      M<SInt32>(iVar4 + 0x24) = iVar6;
      M<UInt8 *>(candidate + 0x24) = candidate;
      M<SInt32>(self + kIOATIR500Accelerator_vramScanEvictedCount) = M<SInt32>(self + kIOATIR500Accelerator_vramScanEvictedCount) + 1;
      iVar4 = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->alloc((GLKMemoryElement *)((UInt8 *)(textureBytes + 0x40)),
                         size,0x1000,0,M<UInt32>(self + kIOATIR500Accelerator_usableVramSize));
      if (iVar4 != 0) {
        return 1;
      }
      goto LAB_0001e480;
    }
    faceCount = (UInt32)M<UInt8>(iVar4 + 0x34);
    uVar5 = 0;
    if (faceCount == 0) {
LAB_0001e3c0:
      if (uVar5 == faceCount) goto LAB_0001e3c8;
    }
    else if ((M<UInt16>(iVar4 + 0x28) & ~M<UInt16>(iVar4 + 0x1c)) == 0) {
      uVar5 = 0;
      uVar8 = faceCount;
      if (faceCount == 0) {
        uVar8 = 1;
      }
      do {
        uVar5 = uVar5 + 1;
        uVar8 = uVar8 - 1;
        if (uVar8 == 0) goto LAB_0001e3c0;
        puVar1 = (UInt16 *)(iVar4 + 0x2a);
        puVar2 = (UInt16 *)(iVar4 + 0x1e);
        iVar4 = iVar4 + 2;
      } while ((*puVar1 & ~*puVar2) == 0);
    }
  } while( true );
}
