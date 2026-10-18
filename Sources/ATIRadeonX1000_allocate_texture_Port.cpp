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
  int iVar3;
  UInt8 *memory;
  UInt32 result;
  UInt32 cpuVisibleSize;
  UInt32 size;
  unsigned int flags;
  
  type = textureBytes[0x20];
  if ((type == 0x3) || (type == 0x7)) {
    size = M<UInt32>(textureBytes + 0x50);
LAB_0001a84c:
    cpuVisibleSize = M<UInt32>(self + 0x84c);
    if (cpuVisibleSize == M<UInt32>(self + kIOATIR500Accelerator_vramSize)) {
LAB_0001a8f0:
      if (M<int>(self + kIOATIR500Accelerator_activePanelMask) == 0) {
        iVar3 = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->alloc((GLKMemoryElement *)(textureBytes + 0x40),
                           size,0x1000,0x10000,cpuVisibleSize - 0x10000);
      }
      else {
        memory = M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool);
LAB_0001a980:
        iVar3 = ((ATIR500Memory *)(memory))->alloc((GLKMemoryElement *)(textureBytes + 0x40),size,0x1000,0,cpuVisibleSize);
      }
      if (iVar3 == 0) goto LAB_0001a994;
    }
    else {
      mapping = (int *)VCALL(*M<int *>(textureBytes + 8), 0x14c)
                                (M<int *>(textureBytes + 8),GH_kernel_task,0,1,0,0);
      if (mapping == (int *)0x0) {
        cpuVisibleSize = M<UInt32>(self + 0x84c);
        goto LAB_0001a8f0;
      }
      iVar3 = VCALL(*mapping, 0xd0)(mapping);
      flags = M<unsigned int>(iVar3 + 0x20);
      VCALL(*mapping, 0x18)(mapping);
      cpuVisibleSize = M<UInt32>(self + 0x84c);
      if (((flags ^ 0x40000000) >> 0x1e & 1) != 0) goto LAB_0001a8f0;
      iVar3 = ((ATIR500Memory *)(M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool)))->alloc((GLKMemoryElement *)(textureBytes + 0x40),size
                         ,0x1000,cpuVisibleSize,M<int>(self + kIOATIR500Accelerator_vramSize) - cpuVisibleSize);
      if (iVar3 == 0) {
        cpuVisibleSize = M<UInt32>(self + 0x84c);
        memory = M<UInt8 *>(self + kIOATIR500Accelerator_memoryPool);
        goto LAB_0001a980;
      }
    }
    result = 1;
  }
  else {
    if (type != 0x8) {
      size = 0;
      goto LAB_0001a84c;
    }
LAB_0001a994:
    result = 0;
  }
  return result;
}
