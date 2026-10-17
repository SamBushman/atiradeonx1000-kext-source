/*
 * IOATIR500Surface_freeAllSwapBuffers_Port.cpp
 *
 * IOATIR500Surface::freeAllSwapBuffers (real addr 0x10860, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x10860 */
void IOATIR500Surface::freeAllSwapBuffers(UInt32 panel) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    PanelRecord *rec = PANEL_RECORD(self, panel);

  SInt32 iVar2;
  SInt32 waitTotal;
  UInt32 bufferIndex;
  SInt32 *accelerator;
  
  accelerator = M<SInt32 *>(self + 0xd50);
  if (accelerator[panel + 0x45] != 0) {
    bufferIndex = 0;
    do {
      waitTotal = accelerator[0x1e2];
      /* the stamp of the submit slot (rec->slotIndex + bufferIndex), numbered from entries[1] */
      iVar2 = rec->slotIndex + bufferIndex;
      bufferIndex = bufferIndex + 1;
      iVar2 = VCALL(*accelerator, 0x54c)
                        (accelerator,rec->entries[iVar2 + 1].stamp);
      accelerator[0x1e2] = waitTotal + iVar2;
      accelerator = M<SInt32 *>(self + 0xd50);
    } while (bufferIndex < (UInt32)accelerator[panel + 0x45]);
    if (accelerator[panel + 0x45] != 0) {
      bufferIndex = 0;
      do {
        /* the four submit slots entries[bufferIndex + 1 .. bufferIndex + 4]. With more than one buffer per panel this walks past the record into the next one (stock behaviour, kept) */
        SwapBufferEntry *slot = &rec->entries[bufferIndex + 1];
        for (SInt32 iVar4 = 0; iVar4 != 4; iVar4 = iVar4 + 1, slot = slot + 1) {
          if (slot->gartOffset != 0) {
            VCALL(*M<SInt32 *>(self + 0xd50), 0x5ac)(M<SInt32 *>(self + 0xd50),slot);
          }
          if (slot->memory != (void *)0x0) {
            VCALL(*(SInt32 *)slot->memory, 0x18)((SInt32 *)slot->memory);
          }
          slot->unknown_0x00 = 0;
          slot->gartOffset = 0;
          slot->memory = (void *)0x0;
          slot->unknown_0x0e = 0;
          slot->unknown_0x0c = 2;
          slot->stamp = 0;
          slot->header = (VendorSwapBufferHeader *)0x0;
          slot->rectWordIndex = 0;
        }
        SwapBufferEntry *master = &rec->entries[bufferIndex];
        if (master->memory != (void *)0x0) {
          VCALL(*(SInt32 *)master->memory, 0x18)((SInt32 *)master->memory);
        }
        master->unknown_0x0c = 2;
        master->unknown_0x0e = 0;
        bufferIndex = bufferIndex + 1;
        master->rectWordIndex = 0;
        master->unknown_0x00 = 0;
        master->gartOffset = 0;
        master->memory = (void *)0x0;
        master->stamp = 0;
        master->header = (VendorSwapBufferHeader *)0x0;
      } while (bufferIndex < M<UInt32>(panel * 4 + M<SInt32>(self + 0xd50) + 0x114));
    }
  }
  rec->swapBufferSize = 0;
  return;
}

