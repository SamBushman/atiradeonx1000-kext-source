/*
 * IOATIR500Surface_invalidate_contexts_Port.cpp
 *
 * IOATIR500Surface::invalidate_contexts (real addr 0x12050, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x12050 */
void IOATIR500Surface::invalidate_contexts() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *context;
  
  M<UInt32>(M<SInt32>(self + kIOATIR500Surface_accelerator) + 0x78) = 0;
  for (context = M<SInt32 *>(self + kIOATIR500Surface_context2DList); context != (SInt32 *)0x0; context = (SInt32 *)context[0x21]) {
    VCALL(*context, 0x5a4)(context);
  }
  for (context = M<SInt32 *>(self + kIOATIR500Surface_glContextList); context != (SInt32 *)0x0; context = (SInt32 *)context[0x21]) {
    VCALL(*context, 0x5a4)(context);
  }
  if (M<SInt32 *>(self + kIOATIR500Surface_boundDVDContext) != (SInt32 *)0x0) {
    VCALL(*M<SInt32 *>(self + kIOATIR500Surface_boundDVDContext), 0x5a4)(M<SInt32 *>(self + kIOATIR500Surface_boundDVDContext));
  }
  return;
}
