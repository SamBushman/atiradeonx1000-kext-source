/*
 * IOATIR500Accelerator_removeFromGART_Port.cpp
 *
 * IOATIR500Accelerator::removeFromGART (real addr 0x5270, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x5270 */
void IOATIR500Accelerator::removeFromGART(IOMemoryDescriptor*descriptor, UInt32 gartOffset) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  unsigned int endEntry;
  int tableOffset;
  int iVar3;
  unsigned int entry;
  
  entry = gartOffset >> (GH_page_shift & 0x3f);
  if (descriptor != 0) {
    endEntry = VCALL(M<int>(descriptor), 0x128)(descriptor);
    endEntry = entry + (endEntry >> (GH_page_shift & 0x3f));
    iVar3 = endEntry - entry;
    M<int>(self + kIOATIR500Accelerator_gartMapOutBytesPerSample) = (iVar3 << (GH_page_shift & 0x3f)) + M<int>(self + kIOATIR500Accelerator_gartMapOutBytesPerSample);
    M<int>(self + kIOATIR500Accelerator_gartUsedBytes) = M<int>(self + kIOATIR500Accelerator_gartUsedBytes) - (iVar3 << (GH_page_shift & 0x3f));
    if (entry < endEntry) {
      tableOffset = entry << 2;
      do {
        M<UInt32>(M<int>(self + kIOATIR500Accelerator_gartTable) + tableOffset) = M<UInt32>(self + kIOATIR500Accelerator_gartEmptyEntry);
        tableOffset = tableOffset + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    if (((M<unsigned int>(self + kIOATIR500Accelerator_hwCapabilityBits) & 2) != 0) &&
       (entry = gartOffset >> (GH_page_shift & 0x3f), entry < endEntry)) {
      do {
        iVar3 = entry << (GH_page_shift & 0x3f);
        entry = entry + 1;
        VCALL(M<int>(self), 0x588)(self,M<UInt32>(self + kIOATIR500Accelerator_scratchBufferDescriptor),iVar3,0);
      } while (entry != endEntry);
    }
    entry = gartOffset >> (GH_page_shift & 0x3f);
    VCALL(M<int>(self), 0x59c)(self,entry,endEntry - entry);
    VCALL(M<int>(descriptor), 0x148)(descriptor,3);
  }
  return;
}
