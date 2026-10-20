/*
 * IOATIR500Shared_alloc_client_shared_Port.cpp
 *
 * IOATIR500Shared::alloc_client_shared (real addr 0x16d50, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFree(...) asm("_IOFree");
extern "C" UInt32 GH_IOMalloc(...) asm("_IOMalloc");
extern "C" UInt32 GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(...) asm("__ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj");


/* real addr 0x16d50 */
bool IOATIR500Shared::alloc_client_shared(UInt32 index, sIOClientShared**outKernelPtr, unsigned int*outUserAddr) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 *lastChunk;
  UInt32 *chunk;
  SInt32 *bufferMemory;
  SInt32 *clientMap;
  UInt32 clientAddress;
  UInt32 kernelAddress;
  SInt32 kernelMap;
  SInt32 acceleratorBytes;
  
  lastChunk = (UInt32 *)0x0;
  chunk = M<UInt32 *>(self + kIOATIR500Shared_chunkList);
  while (chunk != (UInt32 *)0x0) {
LAB_00016f00:
    lastChunk = chunk;
    if (index < (UInt32)lastChunk[6]) {
      *outKernelPtr = (sIOClientShared *)(index * 0x40 + lastChunk[4]);
      *outUserAddr = index * 0x40 + lastChunk[5];
      *(UInt32 *)(UInt8 *)*outKernelPtr = 0;
      M<UInt32>((UInt8 *)*outKernelPtr + 4) = 0;
      M<UInt32>((UInt8 *)*outKernelPtr + 8) = 0;
      M<UInt32>((UInt8 *)*outKernelPtr + 0xc) = 0;
      M<UInt32>((UInt8 *)*outKernelPtr + 0x10) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x1c) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x1e) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x20) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x22) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x24) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x26) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x28) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x2a) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x2c) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x2e) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x30) = 0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x32) = 0;
      ((UInt8 *)*outKernelPtr)[0x14] = 0x1;
      ((UInt8 *)*outKernelPtr)[0x15] = 0x0;
      ((UInt8 *)*outKernelPtr)[0x16] = 0x0;
      ((UInt8 *)*outKernelPtr)[0x34] = 0x0;
      ((UInt8 *)*outKernelPtr)[0x35] = 0x0;
      ((UInt8 *)*outKernelPtr)[0x17] = 0x0;
      M<UInt16>((UInt8 *)*outKernelPtr + 0x36) = 0;
      return 1;
    }
    index = index - lastChunk[6];
    chunk = (UInt32 *)*lastChunk;
  }
  chunk = (UInt32 *)GH_IOMalloc(0x1c);
  if (chunk == (UInt32 *)0x0) {
    return 0;
  }
  bufferMemory = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj(M<UInt32>(self + 8),0x10022,0x2000,GH_page_size);
  chunk[1] = (UInt32)(bufferMemory);
  if (bufferMemory == (SInt32 *)0x0) goto LAB_00016e80;
  clientMap = (SInt32 *)VCALL(*bufferMemory, 0x14c)(bufferMemory,M<UInt32>(self + 8),0,1,0,0);
  chunk[2] = (UInt32)(clientMap);
  if (clientMap != (SInt32 *)0x0) {
    clientAddress = VCALL(*clientMap, 0xd0)(clientMap);
    chunk[5] = clientAddress;
    kernelMap = VCALL(*(SInt32 *)chunk[1], 0x14c)((SInt32 *)chunk[1],GH_kernel_task,0,1,0,0);
    chunk[3] = kernelMap;
    if (kernelMap != 0) {
      acceleratorBytes = M<SInt32>(self + kIOATIR500Shared_accelerator);
      if (acceleratorBytes != 0) {
        M<SInt32>(acceleratorBytes + kIOATIR500Accelerator_vendorTextureBufferBytes) = M<SInt32>(acceleratorBytes + kIOATIR500Accelerator_vendorTextureBufferBytes) + 0x1c;
      }
      kernelAddress = VCALL(*(SInt32 *)chunk[3], 0xd0)(chunk[3]);
      *chunk = 0;
      chunk[4] = kernelAddress;
      chunk[6] = 0x80;
      if (lastChunk == (UInt32 *)0x0) {
        M<UInt32 *>(self + kIOATIR500Shared_chunkList) = chunk;
      }
      else {
        *lastChunk = (UInt32)(chunk);
      }
      goto LAB_00016f00;
    }
    VCALL(*(SInt32 *)chunk[2], 0x18)(chunk[2]);
  }
  VCALL(*(SInt32 *)chunk[1], 0x18)(chunk[1]);
LAB_00016e80:
  GH_IOFree(chunk,0x1c);
  return 0;
}
