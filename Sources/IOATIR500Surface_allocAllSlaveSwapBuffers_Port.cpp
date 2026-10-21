/*
 * IOATIR500Surface_allocAllSlaveSwapBuffers_Port.cpp
 *
 * IOATIR500Surface::allocAllSlaveSwapBuffers (real addr 0x11e50, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x11e50 */
UInt32 IOATIR500Surface::allocAllSlaveSwapBuffers(UInt32 panel, UInt32 swapBufferSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    PanelRecord *rec = PANEL_RECORD(self, panel);

  bool isLastSlot;
  SInt32 counterOffset;
  VendorSwapBufferHeader *swapHeader;
  SInt32 accelerator;
  UInt32 bufferIndex;
  SInt32 *memoryDescriptor;
  UInt32 slotNumber;
  SwapBufferEntry *slot;
  SwapBufferEntry *victim;
  
  /* The four submit slots are entries[1..4]; slot number slotNumber (0..3) allocates one descriptor per buffer of the panel, into entries[slotNumber + 1 + bufferIndex]
     (with more than one buffer per panel that runs past the record into the next one - stock behaviour, kept). */
  memoryDescriptor = (SInt32 *)0x0;
  slotNumber = 0;
  counterOffset = panel * 4;
  accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
  do {
    if (M<SInt32>(counterOffset + accelerator + 0x114) == 0) {
      if (memoryDescriptor == (SInt32 *)0x0) {
unwindSlots:
        /* Failure unwind: release the slots allocated so far, walking backwards from entries[slotNumber]. The shipped code has no exit condition here
           (issue #32: it keeps walking down through memory until it faults); the loop is kept exactly that way. */
        victim = &rec->entries[slotNumber];
        do {
          if (M<SInt32>(counterOffset + accelerator + 0x114) != 0) {
            SwapBufferEntry *v = victim;
            slotNumber = 0;
            do {
              if (v->memory != (void *)0x0) {
                VCALL(*(SInt32 *)v->memory, 0x18)((SInt32 *)v->memory);
              }
              v->lockCount = 0;
              v->usageKind = 2;
              slotNumber = slotNumber + 1;
              v->unknown_0x00 = 0;
              v->gartOffset = 0;
              v->memory = (void *)0x0;
              v->stamp = 0;
              v->header = (VendorSwapBufferHeader *)0x0;
              v->rectWordIndex = 0;
              v = v + 1;
              accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
            } while (slotNumber < M<UInt32>(counterOffset + accelerator + 0x114));
          }
          victim = victim - 1;
        } while( true );
      }
    }
    else {
      bufferIndex = 0;
      slot = &rec->entries[slotNumber + 1];
      do {
        memoryDescriptor = (SInt32 *)GH_ZN24IOBufferMemoryDescriptor11withOptionsEmjj(M<UInt32>(accelerator + kIOATIR500Accelerator_commandBufferMemoryOptions) | 0x10023,swapBufferSize,GH_page_size);
        slot->memory = memoryDescriptor;
        if (memoryDescriptor == (SInt32 *)0x0) {
          if (3 < slotNumber) {
            return 1;
          }
          accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
          goto unwindSlots;
        }
        bufferIndex = bufferIndex + 1;
        swapHeader = (VendorSwapBufferHeader *)VCALL(*memoryDescriptor, 0x1cc)(memoryDescriptor);
        slot->header = swapHeader;
        slot = slot + 1;
        this->init_swap_buffer_header((VendorSwapBufferHeader *)(swapHeader),swapBufferSize);
        accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
      } while (bufferIndex < M<UInt32>(counterOffset + accelerator + 0x114));
    }
    isLastSlot = slotNumber == 3;
    slotNumber = slotNumber + 1;
    if (isLastSlot) {
      return 1;
    }
  } while( true );
}

