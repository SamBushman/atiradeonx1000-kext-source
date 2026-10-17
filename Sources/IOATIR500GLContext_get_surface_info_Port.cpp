/*
 * IOATIR500GLContext_get_surface_info_Port.cpp
 *
 * IOATIR500GLContext::get_surface_info (real addr 0x8bb0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0x8bb0 */
IOReturn IOATIR500GLContext::get_surface_info(UInt32 surfaceID, SInt32*outFlags, SInt32*outW, SInt32*outH) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  UInt32 modeBits;
  SInt32 surface;
  UInt32 result;
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  if (surfaceID != 0) {
    surface = (SInt32)((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->find_surface_for_id(surfaceID);
    if (surface != 0) {
      modeBits = M<UInt32>(surface + 0xbe8);
      *outFlags = modeBits;
      if ((M<UInt32>(surface + 0xc18) & 8) == 0) {
        if ((M<UInt32>(surface + 0xc18) & 4) != 0) {
          *outFlags = modeBits | 0x100;
        }
      }
      else {
        *outFlags = modeBits | 0x200;
      }
      if (M<SInt32>(surface + 0xbd8) == M<SInt32>(surface + 0xbd4)) {
        result = 0;
        *outW = (UInt32)M<UInt16>(M<SInt32>(surface + 0xb70) + 0x1c);
        *outH = (UInt32)M<UInt16>(M<SInt32>(surface + 0xb70) + 0x1e);
      }
      else {
        result = 0;
        *outW = (SInt32)M<SInt16>(surface + 0xbd8);
        *outH = (SInt32)M<SInt16>(surface + 0xbda);
      }
      goto LAB_00008cb0;
    }
  }
  result = 0xe00002c2;
  *outFlags = 0;
  *outW = 0;
  *outH = 0;
LAB_00008cb0:
  GH_IOLockUnlock(M<UInt32>(M<SInt32>(self + 200) + 0x840));
  return result;
}
