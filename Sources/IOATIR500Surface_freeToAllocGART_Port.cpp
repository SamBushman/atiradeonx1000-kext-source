/*
 * IOATIR500Surface_freeToAllocGART_Port.cpp
 *
 * IOATIR500Surface::freeToAllocGART (real addr 0x10c60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x10c60 */
bool IOATIR500Surface::freeToAllocGART(VendorTransferBuffer *needed, bool aggressive) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  bool notLastSlot;
  UInt8 *accelerator;
  UInt8 *backingStore;
  UInt32 panelIndex;
  UInt32 bufferIndex;
  SInt32 slotFreed;
  UInt8 *cursor;
  SInt32 freed;
  SInt32 slotNo;
  
  panelIndex = 0;
  accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
  if (M<SInt32>(accelerator + kIOATIR500Accelerator_displayCount) != 0) {
    do {
      if (M<SInt32>(accelerator + panelIndex * 4 + 0x114) != 0) {
        PanelRecord *rec = PANEL_RECORD(self, panelIndex);
        bufferIndex = 0;
        do {
          SwapBufferEntry *master = &rec->entries[bufferIndex];
          freed = ((IOATIR500Accelerator *)(accelerator))->freeTransferToAllocGART((VendorTransferBuffer *)(master),(VendorTransferBuffer *)(neededBytes),
                             master->stamp,aggressive);
          if (freed != 0) {
            return 1;
          }
          slotNo = 0;
          /* the four submit slots entries[bufferIndex + 1 .. bufferIndex + 4]; with more than one buffer per panel this walks past the record (stock behaviour, kept) */
          SwapBufferEntry *slot = &rec->entries[bufferIndex + 1];
          do {
            slotFreed = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500Surface_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)(slot),(VendorTransferBuffer *)(neededBytes),
                               slot->stamp,aggressive);
            if (slotFreed != 0) {
              return 1;
            }
            notLastSlot = slotNo != 3;
            slot = slot + 1;
            slotNo = slotNo + 1;
          } while (notLastSlot);
          accelerator = M<UInt8 *>(self + kIOATIR500Surface_accelerator);
          bufferIndex = bufferIndex + 1;
        } while (bufferIndex < M<UInt32>(accelerator + panelIndex * 4 + 0x114));
      }
      panelIndex = panelIndex + 1;
    } while (panelIndex < M<UInt32>(accelerator + kIOATIR500Accelerator_displayCount));
  }
  cursor = self;
  while ((backingStore = M<UInt8 *>(cursor + 0xcc), backingStore == (UInt8 *)0x0
         || (freed = ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500Surface_accelerator)))->freeTransferToAllocGART((VendorTransferBuffer *)(backingStore),(VendorTransferBuffer *)(neededBytes),
                                M<UInt32>(M<SInt32>(backingStore + 0x14) + 8),aggressive), freed == 0))) {
    cursor = cursor + 0x78;
    if (self + 0xac8 == cursor) {
      return 0;
    }
  }
  return 1;
}
