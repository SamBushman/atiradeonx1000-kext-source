/*
 * IOATIR500Surface_flush_surface_Port.cpp
 *
 * IOATIR500Surface::flush_surface (real addr 0x10fa0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x10fa0 */
void IOATIR500Surface::flush_surface(UInt32 panelMask, UInt32 swapArg) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 panelIndex;
  PanelRecord *panel;
  SInt32 stampReached;
  SInt32 accelerator;
  
  if ((self[0xbed] == 0x0) ||
     (stampReached = VCALL(*M<SInt32 *>(self + kIOATIR500Surface_accelerator), 0x554)
                        (M<SInt32 *>(self + kIOATIR500Surface_accelerator),M<UInt32>(self + kIOATIR500Surface_submittedStamp)), stampReached != 0)) {
    if ((M<UInt32>(self + kIOATIR500Surface_stateBits) & M<UInt32>(self + kIOATIR500Surface_reqBits) & 0x10000000) != 0) {
      VCALL(M<SInt32>(self), 0x5c0)(self);
      M<UInt32>(self + kIOATIR500Surface_stateBits) = M<UInt32>(self + kIOATIR500Surface_stateBits) & 0xefffffff;
    }
    accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
    M<UInt32>(self + kIOATIR500Surface_flushedStamp) = M<UInt32>(self + kIOATIR500Surface_submittedStamp);
    if (M<SInt32>(accelerator + kIOATIR500Accelerator_displayCount) != 0) {
      panelIndex = 0;
      panel = PANEL_RECORD(self, 0);
      do {
        if (((1 << (panelIndex & 0x3f) & panelMask) != 0) && (panel->active != 0x0)) {
          VCALL(M<SInt32>(self), 0x5d4)(self,panelIndex,swapArg);
          M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x74c) = M<SInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x74c) + 1;
          accelerator = M<SInt32>(self + kIOATIR500Surface_accelerator);
        }
        panelIndex = panelIndex + 1;
        panel = panel + 1;
      } while (panelIndex < M<UInt32>(accelerator + kIOATIR500Accelerator_displayCount));
    }
    M<UInt32>(accelerator + kIOATIR500Accelerator_unknown_0x78) = 0;
  }
  return;
}
