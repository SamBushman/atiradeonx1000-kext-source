/*
 * IOATIR500Surface_allocMasterSwapBuffer_Port.cpp
 *
 * IOATIR500Surface::allocMasterSwapBuffer (real addr 0x118e0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(...) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj");


/* real addr 0x118e0 */
bool IOATIR500Surface::allocMasterSwapBuffer(UInt32 panel, UInt32 swapBufferSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    PanelRecord *rec = PANEL_RECORD(self, panel);

  SInt32 *memoryDescriptor;
  VendorSwapBufferHeader *swapHeader;
  SInt32 accelerator;
  UInt32 count;
  SwapBufferEntry *entry;
  
  rec->swapBufferSize = 0;
  accelerator = M<SInt32>(self + 0xd50);
  if (M<SInt32>(panel * 4 + accelerator + 0x114) != 0) {
    count = 0;
    entry = rec->entries;
    do {
      memoryDescriptor = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(M<UInt32>(accelerator + 0x82c) | 0x10023,swapBufferSize,GH_page_size);
      entry->memory = memoryDescriptor;
      if (memoryDescriptor == (SInt32 *)0x0) {
        return 0;
      }
      count = count + 1;
      swapHeader = (VendorSwapBufferHeader *)VCALL(*memoryDescriptor, 0x1cc)(memoryDescriptor);
      entry->header = swapHeader;
      entry = entry + 1;
      this->init_swap_buffer_header((VendorSwapBufferHeader *)(swapHeader),swapBufferSize);
      accelerator = M<SInt32>(self + 0xd50);
    } while (count < M<UInt32>(panel * 4 + accelerator + 0x114));
  }
  rec->swapBufferSize = swapBufferSize;
  return 1;
}

