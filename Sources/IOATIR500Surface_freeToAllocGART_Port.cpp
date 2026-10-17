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

  bool bVar1;
  UInt8 *this_00;
  SInt32 iVar2;
  UInt8 *pVVar3;
  UInt32 uVar4;
  UInt32 uVar5;
  SInt32 iVar6;
  UInt8 *pIVar8;
  
  uVar4 = 0;
  this_00 = M<UInt8 *>(self + 0xd50);
  if (M<SInt32>(this_00 + 0xcc) != 0) {
    do {
      if (M<SInt32>(this_00 + uVar4 * 4 + 0x114) != 0) {
        PanelRecord *rec = PANEL_RECORD(self, uVar4);
        uVar5 = 0;
        do {
          SwapBufferEntry *master = &rec->entries[uVar5];
          iVar2 = ((IOATIR500Accelerator *)(this_00))->freeTransferToAllocGART((VendorTransferBuffer *)(master),(VendorTransferBuffer *)(neededBytes),
                             master->stamp,aggressive);
          if (iVar2 != 0) {
            return 1;
          }
          iVar2 = 0;
          /* the four submit slots entries[uVar5 + 1 .. uVar5 + 4]; with more than one buffer per panel this walks past the record (stock behaviour, kept) */
          SwapBufferEntry *slot = &rec->entries[uVar5 + 1];
          do {
            iVar6 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0xd50)))->freeTransferToAllocGART((VendorTransferBuffer *)(slot),(VendorTransferBuffer *)(neededBytes),
                               slot->stamp,aggressive);
            if (iVar6 != 0) {
              return 1;
            }
            bVar1 = iVar2 != 3;
            slot = slot + 1;
            iVar2 = iVar2 + 1;
          } while (bVar1);
          this_00 = M<UInt8 *>(self + 0xd50);
          uVar5 = uVar5 + 1;
        } while (uVar5 < M<UInt32>(this_00 + uVar4 * 4 + 0x114));
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < M<UInt32>(this_00 + 0xcc));
  }
  pIVar8 = self;
  while ((pVVar3 = M<UInt8 *>(pIVar8 + 0xcc), pVVar3 == (UInt8 *)0x0
         || (iVar2 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 0xd50)))->freeTransferToAllocGART((VendorTransferBuffer *)(pVVar3),(VendorTransferBuffer *)(neededBytes),
                                M<UInt32>(M<SInt32>(pVVar3 + 0x14) + 8),aggressive), iVar2 == 0))) {
    pIVar8 = pIVar8 + 0x78;
    if (self + 0xac8 == pIVar8) {
      return 0;
    }
  }
  return 1;
}
