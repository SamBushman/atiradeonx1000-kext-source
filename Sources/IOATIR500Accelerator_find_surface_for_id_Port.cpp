/*
 * IOATIR500Accelerator_find_surface_for_id_Port.cpp
 *
 * IOATIR500Accelerator::find_surface_for_id (real addr 0x59e0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x59e0 */
void *IOATIR500Accelerator::find_surface_for_id(UInt32 surfaceID) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *nextLink;
  SInt32 head;
  SInt32 surface;
  
  head = M<SInt32>(self + 0x5c);
  surface = head;
  if (head != 0) {
    do {
      if (M<UInt32>(surface + 0xa4) == surfaceID) {
        return (void *)(surface);
      }
      nextLink = (SInt32 *)(surface + 0x9c);
      surface = *nextLink;
    } while (head != *nextLink);
  }
  return 0;
}
