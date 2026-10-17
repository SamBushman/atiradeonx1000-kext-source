/*
 * IOATIR500Surface_connect_buffer_backing_store_Port.cpp
 *
 * IOATIR500Surface::connect_buffer_backing_store (real addr 0x12800, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(...) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");


/* real addr 0x12800 */
bool IOATIR500Surface::connect_buffer_backing_store(ATIR500SurfaceBuffer *buffer, unsigned int userAddress, UInt32 pitch) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  UInt8 *memory;
  UInt32 length;
  UInt32 pageOffset;
  
  pageOffset = GH_page_size - 1U & userAddress;
  length = -GH_page_size & (GH_page_size + M<UInt16>(bufferBytes + 0x1e) * pitch + pageOffset) - 1
  ;
  if (M<UInt32>(self + 0xd4c) != 0) {
    length = M<UInt32>(self + 0xd4c);
  }
  memory = (UInt8 *)
           GH_ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task(userAddress & -GH_page_size,length,0x10003,M<UInt32>(self + 0x78));
  if (memory != (UInt8 *)0x0) {
    VCALL(M<SInt32>(memory), 0xdc)(memory,2,0);
    this->attach_buffer_backing_store((ATIR500SurfaceBuffer *)(bufferBytes),(IOMemoryDescriptor *)(memory),pageOffset,pitch);
    M<UInt8>(M<SInt32>(bufferBytes + 0x24) + 0x59) = 1;
  }
  return memory != (UInt8 *)0x0;
}
