/*
 * IOATIR500Shared_freeToAllocGART_Port.cpp
 *
 * IOATIR500Shared::freeToAllocGART (real addr 0x17060, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x17060 */
bool IOATIR500Shared::freeToAllocGART(VendorTransferBuffer *needed, bool aggressive) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  UInt8 bufferType;
  int freed;
  UInt8 *texture;
  
  texture = M<UInt8 *>(self + kIOATIR500Shared_textureListHead);
  do {
    if (texture == (UInt8 *)0x0) {
      return 0;
    }
    bufferType = texture[0x20];
    if (bufferType == 0x4) {
      M<UInt8>(M<int>(texture + 0x14) + 0x14) = 1;
      freed = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500Shared_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)(texture),(VendorTransferBuffer *)(neededBytes),
                         M<UInt32>(M<int>(texture + 0x14) + 8),aggressive);
joined_r0x000170d8:
      if (freed != 0) {
        return 1;
      }
    }
    else if ((bufferType == 0x7) || (bufferType == 0x3)) {
      freed = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500Shared_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)(texture),(VendorTransferBuffer *)(neededBytes),
                         M<UInt32>(M<int>(texture + 0x14) + 0xc),aggressive);
      goto joined_r0x000170d8;
    }
    texture = M<UInt8 *>(texture + 0x3c);
  } while( true );
}
