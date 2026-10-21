/*
 * ATIRadeonX1000_allocate_texture_Port.cpp
 *
 * ATIRadeonX1000::allocate_texture (real addr 0x1a800, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x1a800 */
IOReturn ATIRadeonX1000::allocate_texture(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  UInt8 type;
  int *mapping;
  int allocResult;
  UInt8 *memory;
  UInt32 result;
  UInt32 cpuVisibleSize;
  UInt32 size;
  unsigned int flags;
  int hwInfo;
  
  type = textureBytes[0x20];
  if ((type == 0x3) || (type == 0x7)) {
    size = M<UInt32>(textureBytes + 0x50);
allocateInVram:
    cpuVisibleSize = M<UInt32>(self + kIOATIR500Accelerator_usableVramSize);
    if (cpuVisibleSize == M<UInt32>(self + kIOATIR500Accelerator_vramSize)) {
allocateFromPool:
      if (M<int>(self + kIOATIR500Accelerator_displayConfigBits) == 0) {
        allocResult = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->alloc((GLKMemoryElement *)(textureBytes + 0x40),
                           size,0x1000,0x10000,cpuVisibleSize - 0x10000);
      }
      else {
        memory = M<UInt8 *>(self + kIOATIR500Accelerator_vramPool);
poolAlloc:
        allocResult = ((ATIR500Memory *)(memory))->alloc((GLKMemoryElement *)(textureBytes + 0x40),size,0x1000,0,cpuVisibleSize);
      }
      if (allocResult == 0) goto allocFailed;
    }
    else {
      mapping = (int *)VCALL(*M<int *>(textureBytes + 8), 0x14c)
                                (M<int *>(textureBytes + 8),GH_kernel_task,0,1,0,0);
      if (mapping == (int *)0x0) {
        cpuVisibleSize = M<UInt32>(self + kIOATIR500Accelerator_usableVramSize);
        goto allocateFromPool;
      }
      hwInfo = VCALL(*mapping, 0xd0)(mapping);
      flags = M<unsigned int>(hwInfo + 0x20);
      VCALL(*mapping, 0x18)(mapping);
      cpuVisibleSize = M<UInt32>(self + kIOATIR500Accelerator_usableVramSize);
      if (((flags ^ 0x40000000) >> 0x1e & 1) != 0) goto allocateFromPool;
      allocResult = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_vramPool)))->alloc((GLKMemoryElement *)(textureBytes + 0x40),size
                         ,0x1000,cpuVisibleSize,M<int>(self + kIOATIR500Accelerator_vramSize) - cpuVisibleSize);
      if (allocResult == 0) {
        cpuVisibleSize = M<UInt32>(self + kIOATIR500Accelerator_usableVramSize);
        memory = M<UInt8 *>(self + kIOATIR500Accelerator_vramPool);
        goto poolAlloc;
      }
    }
    result = 1;
  }
  else {
    if (type != 0x8) {
      size = 0;
      goto allocateInVram;
    }
allocFailed:
    result = 0;
  }
  return result;
}
