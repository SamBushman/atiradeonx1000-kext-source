/*
 * ATIR500Surface_invalidate_Port.cpp
 *
 * ATIR500Surface::invalidate (real addr 0x3acb0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3acb0 */
void ATIR500Surface::invalidate() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt8 *batchHeader;
  UInt32 uVar2;
  PanelRecord *panel;
  
  if (M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xcc) == 0) {
    return;
  }
  uVar2 = 0;
  panel = PANEL_RECORD(self, 0);
  do {
    batchHeader = reinterpret_cast<UInt8 *>(panel->entries[0].header);     /* the panel's pending swap-write batch */
    uVar2 = uVar2 + 1;
    panel = panel + 1;
    M<UInt32>(batchHeader + 0x1c) = M<UInt32>(batchHeader + 0x1c) | 1;
  } while (uVar2 < M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0xcc));
  return;
}
